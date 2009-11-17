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
    $sql = $systemquery->getSelect(
        array(),
        array('navigations'),
        array(
            array('&&', "parent is null")
        ),
        'weight, menus'
    );
    $systemquery->connect();
    $query = $systemquery->conn->Execute($sql); unset($sql);
    $systemquery->close();
    $cnt = 0;
    for($i=0; $i<$query->_numOfRows; $i++){
//        echo $query->fields['menus'] . '<br />';
        $result[$cnt] = $query->fields;
        $cnt++;
        $sql = $systemquery->getSelect(
            array(),
            array('navigations'),
            array(
                array('&&', "parent=" . $query->fields['id'])
            ),
            'weight, menus'
        );
        $systemquery->connect();
        $child = $systemquery->conn->Execute($sql); unset($sql);
        $systemquery->close();
        for($o=0; $o<$child->_numOfRows; $o++){
            $sql = $systemquery->getSelect(
                array('menus'),
                array('navigations'),
                array(
                    array('&&', "id=" . $query->fields['id'])
                )
            );
            $systemquery->connect();
            $getparent = $systemquery->conn->Execute($sql); unset($sql);
            $systemquery->close();
            $result[$cnt] = $child->fields;
            $result[$cnt]['parent'] = $getparent->fields['menus'];
            $cnt++;
            $child->MoveNext(); unset($getparent);
        } unset($child);
        $query->MoveNext();
    } unset($query);
//    echo '<pre>'; print_r($result); echo '</pre>';
    return $result;
}

function menu_organize(){
    global $configs, $systemquery;
    $result = array();
    $sql = $systemquery->getSelect(
        array(),
        array('registry'),
        array(
            array('&&', "id=" . $_COOKIE[$configs->cookiesession])
        )
    );
    $systemquery->connect();
    $getit = $systemquery->conn->Execute($sql); unset($sql);
    $systemquery->close();
    $primary_links = explode(',', $getit->fields['primary_links']);
    $secondary_links = explode(',', $getit->fields['secondary_links']);
    $navigations = explode(',', $getit->fields['navigations']);
        $i = 0;
        foreach ($primary_links as $key=>$value){
            $sql = $systemquery->getSelect(
                array(),
                array('menus'),
                array(
                    array('&&', "id=" . trim($value))
                )
            );
            $systemquery->connect();
            $get_menu_lists = $systemquery->conn->Execute($sql); unset($sql);
            $systemquery->close();
            $result['primary_links'][$i] = $get_menu_lists->fields;
            $result['primary_links'][$i]['name'] = trim($value);
            $i++; unset($get_menu_lists);
        }
        $i = 0;
        foreach ($secondary_links as $key=>$value){
            $sql = $systemquery->getSelect(
                array(),
                array('menus'),
                array(
                    array('&&', "id=" . trim($value))
                )
            );
            $systemquery->connect();
            $get_menu_lists = $systemquery->conn->Execute($sql); unset($sql);
            $systemquery->close();
            $result['secondary_links'][$i] = $get_menu_lists->fields;
            $result['secondary_links'][$i]['name'] = trim($value);
            $i++; unset($get_menu_lists);
        } $i = 0;
        foreach ($navigations as $key=>$value){
            $sql = $systemquery->getSelect(
                array(),
                array('menus'),
                array(
                    array('&&', "id=" . trim($value))
                )
            );
            $systemquery->connect();
            $get_menu_lists = $systemquery->conn->Execute($sql); unset($sql);
            $systemquery->close();
            $result['navigations'][$i] = $get_menu_lists->fields;
            $sql = $systemquery->getSelect(
                array('parent'),
                array('navigations'),
                array(
                    array('&&', "menus=" . trim($value))
                )
            );
            $systemquery->connect();
            $getparent = $systemquery->conn->Execute($sql); unset($sql);
            $systemquery->close();
            $sql = $systemquery->getSelect(
                array('menus'),
                array('navigations'),
                array(
                    array('&&', "id=" . $getparent->fields['parent'])
                )
            ); unset($getparent);
            $systemquery->connect();
            $getparent = $systemquery->conn->Execute($sql); unset($sql);
            $systemquery->close();
            $result['navigations'][$i]['parent'] = $getparent->fields['menus'];
            $result['navigations'][$i]['name'] = trim($value);
            $i++; unset($get_menu_lists, $getparent);
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
        if(is_null($query->fields['useradd'])){
            $useradd = array();
        } else {
            $useradd = explode(',', $query->fields['useradd']);
        }
//        echo '<pre>'; print_r($useradd); echo '</pre>';
        if(count($useradd) > 0 && in_array($user['id'], $useradd)){
            return TRUE;
        } else {
            return FALSE;
        }
    } else {
        return FALSE;
    }
}

function __get_active_menus($forced=NULL){
    global $user, $systemquery, $configs;
    $result = array();
    $lists = __get_menu_lists(!is_null($forced) ? $forced : NULL);
    if(count($user) < 1){
        if(isset($_COOKIE[$configs->cookieid])){
            $sql = $systemquery->getSelect(
                array(),
                array($configs->auth_use_table[0]),
                array(
                    array('&&', $configs->auth_use_table[4] . "=" . $_COOKIE[$configs->cookieid])
                )
            );
            $systemquery->connect();
            $getit = $systemquery->conn->Execute($sql); unset($sql);
            $systemquery->close();
            if($getit->_numOfRows > 0){
                $user = $getit->fields;
            } unset($getit);
        }
    }
//    echo '<pre>'; print_r($lists); echo '</pre>'; exit();
    foreach($lists as $key=>$value){
        $sql = $systemquery->getSelect(
            array(),
            array('menus'),
            array(
                array('&&', "id=" . $value)
            )
        );
        $systemquery->connect();
        $getelements = $systemquery->conn->Execute($sql); unset($sql);
        $systemquery->close();
        if($getelements->fields['source'] == 'modules'){
            if($getelements->fields['module'] == 'auth'){
                if($value == __get_active_login()){
                    $result[] = $value;
                }
            } else {
                if(!is_null($getelements->fields['user_required']) && $getelements->fields['user_required'] != '' && $getelements->fields['user_required'] != '0' && $getelements->fields['user_required'] != false){
                    if($getelements->fields['user_required'] == 'admin'){
                        if($user['groups'] == 'admin'){
                            $result[] = $value;
                        }
                    } elseif($getelements->fields['user_required'] == 'users'){
                        if(count($user) > 0){
                            $result[] = $value;
                        }
                    } elseif($getelements->fields['user_required'] != 'admin' && $getelements->fields['user_required'] != 'users'){
                        if($user['groups'] == 'admin' || $user['groups'] == $getelements->fields['user_required']){
                            $result[] = $value;
                        } elseif(__get_group_permission($getelements->fields['user_required']) !== FALSE){
//                            echo 'here' . "<br />";
                            $result[] = $value;
                        }
                    }
                } else {
                    $result[] = $value;
                }
            }
        } elseif($getelements->fields['source'] == 'configs'){
            if(!is_null($getelements->fields['user_required']) && $getelements->fields['user_required'] != '' && $getelements->fields['user_required'] != '0' && $getelements->fields['user_required'] != false){
                if($user['groups'] == 'admin'){
                    $result[] = $value;
                } elseif($getelements->fields['user_required'] == 'users'){
                    if(count($user) > 0){
                        $result[] = $value;
                    }
                } elseif($getelements->fields['user_required'] != 'admin' && $getelements->fields['user_required'] != 'users'){
                    if($user['groups'] == 'admin' || $user['groups'] == $getelements->fields['user_required']){
                        $result[] = $value;
                    }
                }
            } else {
                $result[] = $value;
            }
        } unset($getelements);
    }
//    echo '<pre>'; print_r($result); echo '</pre>'; exit();
    return $result;
}

function get_active_modules(){
    global $systemquery, $configs;
    $result = array();
    $sql = $systemquery->getSelect(
        array(),
        array('modules'),
        NULL,
        'module'
    );
    $systemquery->connect();
    $query = $systemquery->conn->Execute($sql); unset($sql);
    $systemquery->close();
    for($i=0; $i<$query->_numOfRows; $i++){
        $result[] = $query->fields['module'];
        $query->MoveNext();
    } unset($query);
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

function __get_menu_lists($forced = NULL){
    global $systemquery, $configs;
    $modules = get_active_modules();
    $result = array();
    $sql = $systemquery->getSelect(
        array(),
        array('registry'),
        array(
            array('&&', "id=" . $_COOKIE[$configs->cookiesession])
        )
    );
    $systemquery->connect();
    $registry = $systemquery->conn->Execute($sql); unset($sql);
    $systemquery->close();
    if($registry->_numOfRows > 0 && is_null($forced)){
        for($i=0; $i<$registry->_numOfRows; $i++){
            if(!is_null($registry->fields['alls']) && trim($registry->fields['alls']) != ''){
                $dumpr = explode(',', $registry->fields['alls']);
                foreach($dumpr as $value){
                    $result[] = $value;
                } unset($dumpr);
            }
            $registry->MoveNext();
        }
    } else {
        $sql = $systemquery->getSelect(
            array('id'),
            array('menus'),
            NULL,
            'parent, id'
        );
        $systemquery->connect();
        $menus = $systemquery->conn->Execute($sql); unset($sql);
        $systemquery->close();
        for($i=0; $i<$menus->_numOfRows; $i++){
            $result[] = $menus->fields['id'];
            $menus->MoveNext();
        } unset($menus);
    } unset($registry);
//    echo '<pre>'; print_r($result); echo '<pre>';
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
    $sql = $systemquery->getSelect(
        array('id'),
        array('menus'),
        array(
            array('&&', "path=" . $the_path)
        )
    );
    $systemquery->connect();
    $getmenus = $systemquery->conn->Execute($sql); unset($sql);
    $systemquery->close();
    for($i=0; $i<$getmenus->_numOfRows; $i++){
        $result[] = $getmenus->fields['id'];
        $getmenus->MoveNext();
    } unset($getmenus);
//    echo '<pre>'; print_r($result); echo '</pre>'; exit();
    return $result;
}