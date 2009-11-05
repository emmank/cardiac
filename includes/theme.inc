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
 *  page.inc
 *
 *  Created on Sep 6, 2009, 11:03:48 AM
 */

function get_theme(){
    global $configs, $user;
    $theme_lists = __get_theme_lists();
    if(isset($user['theme'])){
        if(!is_null($user['theme']) && $user['theme'] != '0'){
            if(!in_array($user['theme'], $theme_lists)){
                $theme = $configs->default_theme;
            } else {
                $theme = $user['theme'];
            }
        }
    } else {
        $theme = $configs->default_theme;
    } unset($theme_lists);
    return $theme;
}

function __get_theme_lists(){
    $lists = array();
    $getpath = __get_file_lists(THEMES_DIR);
    foreach($getpath as $key=>$value){
        if(__check_theme(THEMES_DIR, $value) === true){
            $lists[] = $value;
        }
    }
    return $lists;
}

function __check_theme($path, $name){
    if(is_dir($path . DS . $name)){
        $getlist = __get_file_lists($path . DS . $name);
        foreach($getlist as $key=>$value){
            if(preg_match('/.info$/', $value)){
                return true;
            }
        }
    }
    return false;
}

function __get_user_vars(){
    require_once MODULES_DIR . DS . 'auth' . DS . 'auth.module';
    $result = auth_user_vars();
    return $result;
}

function get_all_page_vars(){
    global $showpage, $content_items, $uservar;
    $rpath = __get_path();
    $showpage['path'] = $rpath;
    $path = implode('/', $rpath);
    $path = preg_replace('/\/$/','', $path);
    $uservar = __get_user_vars();
    $showpage['user'] = $uservar;
    $showpage['theme'] = __get_theme($uservar);
    $showpage['menu'] = __get_active_menu($uservar);
    require_once INCLUDES_DIR . DS . 'node.inc';
    get_content_items($path);
    if(isset($content_items['exec']) && !is_null($content_items['exec'])){
        $content_items['output'] = exec_module_function($content_items['exec']);
    }
    $showpage['content'] = $content_items;
    return $showpage;
}