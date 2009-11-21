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
 *  bootstrap.inc
 *
 *  Created on Sep 6, 2009, 10:56:44 AM
 */

function rendering_page(){
    global $configs, $systemquery, $user, $forminput, $formtextarea, $formselect;
    __show_debug();
    unset_globals();
    $user = __get_user();
    __check_registry();
//    $modules = get_active_modules();
//    $menus = __get_menu_lists();
//    $mymenus = __get_active_menus();
    $path = get_path_array();
//    get_content($path);
    $exec_menus = get_exec_menus($path);
//    echo '<pre>'; print_r($path); echo '</pre>'; exit();
    $content['exec'] = __get_modul_exec($exec_menus);
    $content['output'] = exec_module_function($content['exec']);
    $theme = get_theme();
    $managed_menus = menu_organize();
    include_once INCLUDES_DIR . DS . 'renderme.inc';
    return;
}

function __show_debug(){
    global $configs;
    ini_set('display_errors', ($configs->debugshow !== false ? 1 : 0)); // Ensure errors get to the user.
    error_reporting(E_ALL & ~E_NOTICE);
}

function __check_registry(){
    global $user, $systemquery, $configs;
    if(isset($_COOKIE[$configs->cookiesession])){
        $sql = $systemquery->getSelect(
            array(),
            array('registry'),
            array(
                array('&&', "id=" . $_COOKIE[$configs->cookiesession])
            )
        );
        $systemquery->connect();
        $getregistry = $systemquery->conn->Execute($sql); unset($sql);
        $systemquery->close();
        if($getregistry->_numOfRows < 1){
            __write_registry();
        } unset($getregistry);
    }
}

/**
 * Unsets all disallowed global variables. See $allowed for what's allowed.
 */
function unset_globals() {
/*
  if (ini_get('register_globals')) {
    $allowed = array('_ENV' => 1, '_GET' => 1, '_POST' => 1, '_COOKIE' => 1, '_FILES' => 1, '_SERVER' => 1, '_REQUEST' => 1, 'GLOBALS' => 1);
    foreach ($GLOBALS as $key => $value) {
      if (!isset($allowed[$key])) {
        unset($GLOBALS[$key]);
      }
    }
  }
 *
 */
        if (!ini_get('register_globals')) {
            return;
        }

        // Might want to change this perhaps to a nicer error
        if (isset($_REQUEST['GLOBALS'])) {
            die('You may practice harder !!! dumb !');
        }

        // Variables that shouldn't be unset
        $noUnset = array('GLOBALS',  '_GET',
                         '_POST',    '_COOKIE',
                         '_REQUEST', '_SERVER',
                         '_ENV',     '_FILES');

        $input = array_merge($_GET,    $_POST,
                             $_COOKIE, $_SERVER,
                             $_ENV,    $_FILES,
                             isset($_SESSION) && is_array($_SESSION) ? $_SESSION : array());

        foreach ($input as $k => $v) {
            if (!in_array($k, $noUnset) && isset($GLOBALS[$k])) {
                unset($GLOBALS[$k]);
            }
        }
}

function __get_file_lists($path){
    if(is_dir($path)){
        $result = array(); clearstatcache(); $i = 0;
            if ($handle = opendir($path)){
                while (false !== ($file = readdir($handle))){
                    if ($file != "." && $file != ".."){
                        $result[$i] = $file; $i++;
                    }
                } closedir($handle);
            }
        return $result;
    } else {
        return NULL;
    }
}

function __remove_folder($dir){
    if(is_dir($dir)){
        $getlists = __get_file_lists($dir);
        foreach($getlists as $value){
            if(is_dir($value)){
                __remove_folder($value);
            } else {
                unlink($dir . DS . $value);
            }
        }
        rmdir($dir);
    }
}



function __get_user(){
    global $configs, $systemquery;
    $result = array();
    require MODULES_DIR . DS . 'auth' . DS . 'auth.module';
    $auth_config->time = $configs->time;
    $auth_config->timelog_idle = $configs->timelog_idle;
    $auth_config->fcache = $configs->fcache;
    $auth_config->flog = $configs->flog;

    $auth_query->dbname = $auth_config->dbuser['name'];
    $auth_query->dbprefix = $auth_config->dbuser['prefix'];
    $auth_query->dbsuffix = $auth_config->dbuser['suffix'];
    $auth_query->tbprefix = $auth_config->dbuser['tbprefix'];
    $auth_query->tbsuffix = $auth_config->dbuser['tbsuffix'];
    $auth_query->hostname = $auth_config->dbuser['host'];
    $auth_query->username = $auth_config->dbuser['user'];
    $auth_query->passwd = $auth_config->dbuser['passwd'];
    $auth_query->conn = &ADONewConnection($auth_config->rdbms);

    $auth_exec->config = $auth_config;
    $auth_exec->sysquery = $systemquery;
    $auth_exec->query = $auth_query;

    $result = $auth_exec->get_user_vars();
    return $result;
}

function __write_registry(){
    global $configs, $systemquery, $user;
//    echo '<pre>'; print_r($user); echo '</pre>';
    $menu_actives = __get_active_menus(1);
    $primary_links = __get_primary_links();
    $secondary_links = __get_secondary_links();
    $navigations = __get_navigations();
//    echo '<pre>'; print_r($menu_actives); echo '</pre>'; exit();
    $thevalue = array();
    foreach ($primary_links as $key=>$value){
        if(in_array($value['menus'], $menu_actives)){
            if(isset($koma)){$thevalue['primary_links'] .= ',';} else {$thevalue['primary_links'] = '';}
            $thevalue['primary_links'] .= $value['menus']; $koma = 0;
        }
    } unset($koma);
    foreach ($secondary_links as $key=>$value){
        if(in_array($value['menus'], $menu_actives)){
            if(isset($koma)){$thevalue['secondary_links'] .= ',';} else {$thevalue['secondary_links'] = '';}
            $thevalue['secondary_links'] .= $value['menus']; $koma = 0;
        }
    } unset($koma);
    foreach ($navigations as $key=>$value){
        if(in_array($value['menus'], $menu_actives)){
            if(isset($koma)){$thevalue['navigations'] .= ',';} else {$thevalue['navigations'] = '';}
            $thevalue['navigations'] .= $value['menus']; $koma = 0;
        }
    } unset($koma);
    foreach ($menu_actives as $key=>$value){
        if(isset($koma)){$thevalue['alls'] .= ',';} else {$thevalue['alls'] = '';}
        $thevalue['alls'] .= $value; $koma = 0;
    } unset($koma);

    $sql = $systemquery->getSelect(
        array('id'),
        array('registry'),
        array(
            array('&&', "id=" . $_COOKIE[$configs->cookiesession])
        )
    );
    $systemquery->connect();
    $checkit = $systemquery->conn->Execute($sql); unset($sql);
    $systemquery->close();
    if($checkit->_numOfRows > 0){
        $sql = $systemquery->setDelete(
            'registry',
            array(
                array('&&', "id=" . $_COOKIE[$configs->cookiesession])
            )
        );
    } unset($checkit);
    $thevalue['id'] = $_COOKIE[$configs->cookiesession];
//    echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();

    $sql = $systemquery->saveData(
        'registry',
        $thevalue
    ); unset($thevalue);
    $systemquery->connect();
    $systemquery->conn->Execute($sql); unset($sql);
    $systemquery->close();

    // writing all elements , but that just for temporary until menu module is existing !

    redirect_to('/');
}
