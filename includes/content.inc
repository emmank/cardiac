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
    global $configs, $systemquery;
    clearstatcache();
    if($path['main'] != 'node'){
        if(!isset($_COOKIE[$configs->cookiesession])){
            redirect_to('/'); exit();
        }
        $sql = $systemquery->getSelect(
            array('alls'),
            array('registry'),
            array(
                array('&&', "id=" . $_COOKIE[$configs->cookiesession])
            )
        );
        $systemquery->connect();
        $getit = $systemquery->conn->Execute($sql); unset($sql);
        $systemquery->close();
        if($getit->_numOfRows < 1){
            redirect_to('/'); exit();
        }
        $listmenus = explode(',', $getit->fields['alls']);
        $listpath = array();
        foreach($listmenus as $value){
            $sql = $systemquery->getSelect(
                array('path'),
                array('menus'),
                array(
                    array('&&', "id=" . trim($value))
                )
            );
            $systemquery->connect();
            $getthis = $systemquery->conn->Execute($sql); unset($sql);
            $systemquery->close();
            $listpath[] = $getthis->fields['path'];
        } unset($listmenus);
        $dump = $path;
        $vars = explode('/',$dump['vars']);
        $dump['vars'] = $vars[0]; unset($vars);
        $the_path = preg_replace('/\/$/', '', implode('/',$dump));
        $the_path = (!preg_match('/^\//',$the_path) ? '/' : '') . $the_path;
        unset($dump);
        if(!in_array($the_path, $listpath)){
            unset($the_path, $listpath);
            redirect_to('/'); exit();
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
//                    echo '<pre>'; print_r($value); echo '</pre>';
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
