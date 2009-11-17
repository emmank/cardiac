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
 *  node.inc
 *
 *  Created on Sep 6, 2009, 11:03:48 AM
 */

//Produce node items

function get_content($path){
    global $configs, $user;
    if(count($user) < 1){
        if($configs->user_required == TRUE){
            if($path['main'] != 'login'){
                redirect_to('/login');
            }
        } else {
            if($path['main'] == 'user' ||
            $path['main'] == 'admin' ||
                (isset($path['menu']) && (
                    $path['menu'] == 'add' ||
                    $path['menu'] == 'edit' ||
                    $path['menu'] == 'drop')
                )
            ){
                redirect_to('/login');
            }
        }
    } else {
        if($path['main'] == 'login'){
            redirect_to('/');
        } else {
//            $menus = __get_menu_lists();
            $checkmenus = __get_active_menus();
            $getallow_path = array();
//            echo '<pre>'; print_r($checkmenus); echo '</pre>';
            foreach($checkmenus as $key => $value){
                $getallow_path[] = $menus[$value]['path'];
            }
            if(isset($path['vars'])){
//                echo 'disini';
                $vars = explode('/', $path['vars']);
                $vars = $vars[0];
                $gettruepath = $path['main'] . ($path['menu'] != '' ? '/' . $path['menu'] . ($vars != '' ? '/' . $vars : '') : '');
            } else {
                $gettruepath = implode('/', $path);
            }
            if(!preg_match('/^\//', $gettruepath)){
                $gettruepath = '/' . preg_replace('/\/$/', '', $gettruepath);
            }
            if(!in_array($gettruepath, $getallow_path)){
                redirect_to('/');
            }
//            echo '<pre>'; print_r($gettruepath); echo '</pre>'; exit();
        }
    }
}

function __get_modul_exec($exec_menus){
    global $systemquery;
    $execfunc = array();
    foreach($exec_menus as $value){
        $sql = $systemquery->getSelect(
            array('module', 'exec'),
            array('menus'),
            array(
                array('&&', "id=" . $value)
            )
        );
        $systemquery->connect();
        $query = $systemquery->conn->Execute($sql); unset($sql);
        $systemquery->close();
        $execfunc[] = (!is_null($query->fields['module']) ? $query->fields['module'] . '_' : '') . $query->fields['exec'];
        unset($query);
    }
//    echo '<pre>'; print_r($execfunc); echo '</pre>';
    return $execfunc;
}

function exec_module_function($func){
    global $systemquery, $configs;
    $modules = get_active_modules();
    $output = array();
    foreach($func as $key=>$value){
        if(!is_null($value)){
            $get_module = explode('_', $value);
            $get_module = trim($get_module[0]);
            $value = ereg_replace($get_module . '_', '', $value);
            if(in_array($get_module, $modules)){
                require MODULES_DIR . DS . $get_module . DS . $get_module . '.module';
                ${$get_module . '_config'}->time = $configs->time;
                ${$get_module . '_config'}->timelog_idle = $configs->timelog_idle;
                ${$get_module . '_config'}->fcache = $configs->fcache;
                ${$get_module . '_config'}->flog = $configs->flog;

                $funcdb = $get_module == 'user' || $get_module == 'auth' || $get_module == 'group' ? 'dbuser' : 'db' . $get_module;

                ${$get_module . '_query'}->dbname = ${$get_module . '_config'}->{$funcdb}['name'];
                ${$get_module . '_query'}->dbprefix = ${$get_module . '_config'}->{$funcdb}['prefix'];
                ${$get_module . '_query'}->dbsuffix = ${$get_module . '_config'}->{$funcdb}['suffix'];
                ${$get_module . '_query'}->tbprefix = ${$get_module . '_config'}->{$funcdb}['tbprefix'];
                ${$get_module . '_query'}->tbsuffix = ${$get_module . '_config'}->{$funcdb}['tbsuffix'];
                ${$get_module . '_query'}->hostname = ${$get_module . '_config'}->{$funcdb}['host'];
                ${$get_module . '_query'}->username = ${$get_module . '_config'}->{$funcdb}['user'];
                ${$get_module . '_query'}->passwd = ${$get_module . '_config'}->{$funcdb}['passwd'];
                ${$get_module . '_query'}->conn = &ADONewConnection(${$get_module . '_config'}->rdbms);

                ${$get_module . '_exec'}->config = ${$get_module . '_config'};
                ${$get_module . '_exec'}->sysquery = $systemquery;
                ${$get_module . '_exec'}->query = ${$get_module . '_query'};

                if(preg_match('/form$/', $value)){
                    $output['form'][] = ${$get_module . '_exec'}->$value();
                } else {
                    if($get_module == 'core'){
                        $output[] = $value();
                    } else {
                        $output[] = ${$get_module . '_exec'}->$value();
                    }
                }
            } unset($get_module);
        }
    } unset($modules);
    return $output;
}

function show_node_menus(){
    global $systemquery;
    $result = array();
    $menu_lists = __get_menu_lists();
    $systemquery->connect();
    $sql = $systemquery->getSelect(
        array(),
        array('navigations'),
        array(
            array('&&', "parent=" . $menu_lists['node']['id'])
        ),
        'weight'
    );
    $query = $systemquery->conn->Execute($sql); unset($sql);
    $systemquery->close();
    for($i=0; $i<$query->_numOfRows; $i++){
        $result[] = $menu_lists[$query->fields['menus']];
    }
    return $result;
}

function show_user_menus(){
    global $systemquery;
    $result = array();
    $menu_lists = __get_menu_lists();
    $systemquery->connect();
    $sql = $systemquery->getSelect(
        array(),
        array('navigations'),
        array(
            array('&&', "parent=" . $menu_lists['user']['id'])
        ),
        'weight'
    );
    $query = $systemquery->conn->Execute($sql); unset($sql);
    $systemquery->close();
    for($i=0; $i<$query->_numOfRows; $i++){
        $result[] = $menu_lists[$query->fields['menus']];
    }
    return $result;
}

function show_admin_menus(){
    global $systemquery;
    $result = array();
    $menu_lists = __get_menu_lists();
    $systemquery->connect();
    $sql = $systemquery->getSelect(
        array(),
        array('navigations'),
        array(
            array('&&', "parent=" . $menu_lists['admin']['id'])
        ),
        'weight'
    );
    $query = $systemquery->conn->Execute($sql); unset($sql);
    $systemquery->close();
    for($i=0; $i<$query->_numOfRows; $i++){
        $result[] = $menu_lists[$query->fields['menus']];
    }
   return $result;
}