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

function get_path_array(){
    $result = array();
    if(isset($_GET['q'])){
        $vars = explode('/', trim($_GET['q']));
        foreach($vars as $key => $value){
            if($key < 2){
                if($key == 0){
                    $result['main'] = trim($value);
                } elseif($key == 1){
                    $result['menu'] = trim($value);
                }
                unset($vars[$key]);
            }
        }
        $result['vars'] = implode('/', $vars);
    } else {
        $result = array(
            'main' => 'node'
        );
    }
    return $result;
}

function __extract_vars($vars){
    $result = explode('/', $vars);
    return $result;
}

function redirect_to($url_path){
    if(isset($url_path) && !is_null($url_path) && $url_path != ''){
        header("Location:" . $url_path);
    } else {
        header('Location:/');
    }
}

function __get_path_lists(){
}

