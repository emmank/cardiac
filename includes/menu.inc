<?php
/*
 *  Copyright (c) 2009 Denic Wibowo<denicwibowo@gmail.com>.
 *  All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 *  Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 *  menu.inc
 *
 *  Created on Sep 6, 2009, 11:03:48 AM
 */

function __get_primary_links(){
    global $systemquery;
    $result = array();
    $systemquery->connect();
    $sql = $systemquery->getSelect(
        array(),
        array('primary_links'),
        NULL,
        'weight, menus'
    );
    $query = $systemquery->conn->Execute($sql); unset($sql);
    for($i=0; $i<$query->_numOfRows; $i++){
        $result[] = $query->fields;
        $query->MoveNext();
    } unset($query);
    $systemquery->close();
    return $result;
}

function __get_secondary_links(){
    global $systemquery;
    $result = array();
    $systemquery->connect();
    $sql = $systemquery->getSelect(
        array(),
        array('secondary_links'),
        NULL,
        'weight, menus'
    );
    $query = $systemquery->conn->Execute($sql); unset($sql);
    for($i=0; $i<$query->_numOfRows; $i++){
        $result[] = $query->fields;
        $query->MoveNext();
    } unset($query);
    $systemquery->close();
    return $result;
}

function __get_navigations(){
    global $systemquery;
    $result = array();
    $systemquery->connect();
    $sql = $systemquery->getSelect(
        array(),
        array('navigations'),
        array(
            array('&&', "parent is null")
        ),
        'weight, menus'
    );
    $query = $systemquery->conn->Execute($sql); unset($sql);
    for($i=0; $i<$query->_numOfRows; $i++){
        $result[] = $query->fields;
        $sql = $systemquery->getSelect(
            array(),
            array('navigations'),
            array(
                array('&&', "parent=" . $query->fields['id'])
            ),
            'weight, menus'
        );
        $child = $systemquery->conn->Execute($sql); unset($sql);
        for($o=0; $o<$child->_numOfRows; $o++){
            $result[] = $child->fields;
            $child->MoveNext();
        }
        $query->MoveNext();
    } unset($query);
    $systemquery->close();
    return $result;
}

function menu_organize(){
    global $configs;
    $result = array();
    $menu_lists = __get_menu_lists();
    $menu_actives = __get_active_menus();
    $primary_links = __get_primary_links();
    $secondary_links = __get_secondary_links();
    $navigations = __get_navigations();
        $i = 0;
        foreach ($primary_links as $key=>$value){
            if(in_array($value['menus'], $menu_actives)){
                foreach($menu_lists as $ky=>$vl){
                    if($ky == $value['menus']){
                        $result['primary_links'][$i] = $vl;
                        $result['primary_links'][$i]['name'] = $ky;
                        $i++;
                        break;
                    }
                }
            }
        }
        $i = 0;
        foreach ($secondary_links as $key=>$value){
            if(in_array($value['menus'], $menu_actives)){
                foreach($menu_lists as $ky=>$vl){
                    if($ky == $value['menus']){
                        $result['secondary_links'][$i] = $vl;
                        $result['secondary_links'][$i]['name'] = $ky;
                        $i++;
                        break;
                    }
                }
            }
        } $i = 0;
        foreach ($navigations as $key=>$value){
            if(in_array($value['menus'], $menu_actives)){
                foreach($menu_lists as $ky=>$vl){
                    if($ky == $value['menus']){
                        $result['navigations'][$i] = $vl;
                        $result['navigations'][$i]['parent'] = $value['parent'];
                        $result['navigations'][$i]['name'] = $ky;
                        $i++;
                        break;
                    }
                }
            }
        } unset($i, $menu_actives, $menu_lists, $primary_links, $secondary_links, $navigations);
    return $result;
}

function __get_group_permission($id){
    global $user, $systemquery;
//    echo $user['id'] . ' in ' . $id . '<br />';
    $systemquery->connect();
    $sql = $systemquery->getSelect(
        array('useradd'),
        array('groups'),
        array(
            array('&&', "name=" . $id)
        )
    );
    $query = $systemquery->conn->Execute($sql); unset($sql);
    $systemquery->close();
//    echo $query->fields['useradd'] . '<br />';
    if($query->_numOfRows > 0){
        $useradd = explode(',', $query->fields['useradd']);
//        echo '<pre>'; print_r($useradd); echo '</pre>';
        if(in_array($user['id'], $useradd)){
            return TRUE;
        } else {
            return FALSE;
        }
    } else {
        return FALSE;
    }
}

function __get_active_menus(){
    global $user;
//    echo '<pre>'; print_r($user); echo '</pre>';
    $result = array();
    $lists = __get_menu_lists();
//    echo '<pre>'; print_r($lists); echo '</pre>';
    foreach($lists as $key=>$value){
        if($value['source'] == 'modules'){
            if($value['module'] == 'auth'){
                if($key == __get_active_login()){
                    $result[] = $key;
                }
            } else {
                if(!is_null($value['user_required']) && $value['user_required'] != '' && $value['user_required'] != '0' && $value['user_required'] != false){
                    if($value['user_required'] == 'admin'){
                        if($user['groups'] == 'admin'){
                            $result[] = $key;
                        }
                    } elseif($value['user_required'] == 'users'){
                        if(count($user) > 0){
                            $result[] = $key;
                        }
                    } elseif($value['user_required'] != 'admin' && $value['user_required'] != 'users'){
//                        echo $value['user_required'] . ' = ' . __get_group_permission($value['user_required']) . '<br>';
                        if($user['groups'] == 'admin' || $user['groups'] == $value['user_required']){
                            $result[] = $key;
                        } elseif(__get_group_permission($value['user_required']) !== FALSE){
                            $result[] = $key;
                        }
                    }
                } else {
                    $result[] = $key;
                }
            }
        } elseif($value['source'] == 'configs'){
            if(!is_null($value['user_required']) && $value['user_required'] != '' && $value['user_required'] != '0' && $value['user_required'] != false){
                if($user['groups'] == 'admin'){
                    $result[] = $key;
                } elseif($value['user_required'] == 'users'){
                    if(count($user) > 0){
                        $result[] = $key;
                    }
                } elseif($value['user_required'] != 'admin' && $value['user_required'] != 'users'){
                    if($user['groups'] == 'admin' || $user['groups'] == $value['user_required']){
                        $result[] = $key;
                    }
                }
            } else {
                $result[] = $key;
            }
        }
    }
//    echo '<pre>'; print_r($result); echo '</pre>';
    return $result;
}

function get_active_modules(){
    global $systemquery, $configs;
    $result = array();
    $cache_filename = FILES_DIR . DS . 'registry' . DS . $_COOKIE[$configs->cookiesession];
    clearstatcache();
    if(is_file($cache_filename)){
        require $cache_filename;
        $result = $modulelists;
    } else {
        $nothing = 0;
    } unset($cache_filename);
    if(isset($nothing)){
        unset($nothing);
        $systemquery->connect();
        $sql = $systemquery->getSelect(
            array(),
            array('modules'),
            NULL,
            'module'
        );
//        $systemquery->conn->debug=true;
        $query = $systemquery->conn->Execute($sql); unset($sql);
        for($i=0; $i<$query->_numOfRows; $i++){
            $result[] = $query->fields['module'];
            $query->MoveNext();
        } unset($query);
        $systemquery->connect();
    }
    return $result;
}

function __get_menu_sights(){
    global $configs;
    $result = array();
    foreach($configs->menu_sights as $key => $value){
        $result[$key] = $value;
    }
    return $result;
}

function __get_menu_lists(){
    global $systemquery, $configs;
    $modules = get_active_modules();
    $result = array();
    $cache_filename = FILES_DIR . DS . 'registry' . DS . $_COOKIE[$configs->cookiesession];
    clearstatcache();
    if(is_file($cache_filename)){
        require $cache_filename;
        $result = $menulists;
    } else {
        $nothing = 0;
    } unset($cache_filename);
    if(isset($nothing)){
        unset($nothing);
        foreach($modules as $value){
            require MODULES_DIR . DS . $value . DS . $value . '.module';
        }
        $menu_sight_lists = __get_menu_sights();
        $systemquery->connect();
        $sql = $systemquery->getSelect(
            array(),
            array('navigations'),
            array(
                array('&&', "parent is null")
            ),
            'weight'
        );
        $query = $systemquery->conn->Execute($sql); unset($sql);
        for($i=0; $i<$query->_numOfRows; $i++){
            $result[$query->fields['menus']] = $query->fields;
            foreach($menu_sight_lists[$query->fields['menus']] as $key => $value){
                $result[$query->fields['menus']][$key] = $value;
            }
            $result[$query->fields['menus']]['source'] = 'configs';
            $query->MoveNext();
        } unset($query);
        $systemquery->close();
        foreach($modules as $key=>$value){
//            echo $value . '<br />';
            require MODULES_DIR . DS . $value . DS . $value . '.module';
            $menu_lists = ${$value . '_exec'}->menu();
    //        if($value == 'group'){echo '<pre>'; print_r($menu_lists); echo '</pre>';}
            foreach($menu_lists as $ke=>$val){
                $result[$ke] = $val;
                $result[$ke]['module'] = $value;
                $result[$ke]['source'] = 'modules';
            } unset($menu_lists);
        }
        foreach($modules as $value){
            unset(${$value . '_module'}, ${$value . '_config'}, ${$value . '_query'});
        } unset($modules);
    }
    return $result;
}

function __get_active_login(){
    global $user;
    if(is_array($user)){
        if(count($user) > 0){
            return 'logout';
        } else {
            return 'login';
        }
    } else {
        return 'login';
    }
}

function get_exec_menus($path){
    global $systemquery;
    $result = array();
    $dump = $path;
//    if($dump['main'] == 'admin' || $dump['main'] == 'user'){
        $vars = explode('/',$dump['vars']);
        $dump['vars'] = $vars[0]; unset($vars);
//    }
    $the_path = preg_replace('/\/$/', '', implode('/',$dump));
    $the_path = (!preg_match('/^\//',$the_path) ? '/' : '') . $the_path;
    unset($dump);
    $menu_lists = __get_menu_lists();
    foreach($menu_lists as $key=>$value){
        if($value['path'] == $the_path){
            $result[] = $key;
        }
    }
//    echo '<pre>'; print_r($result); echo '</pre>'; exit();
    return $result;
}