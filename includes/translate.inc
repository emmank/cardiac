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
 *  translate.inc
 *
 *  Created on Sep 6, 2009, 11:03:48 AM
 */

//Get translation string

function __t($string){
    global $systemquery;
    $lang = __get_lang();
    $systemquery->connect();
    $sql = $systemquery->getSelect(
        array($lang),
        array('translations'),
        array(
            array('&&', "strkey=" . $string)
        )
    );
    $result = $systemquery->conn->Execute($sql); unset($sql);
    $systemquery->close();
    if($result->_numOfRows > 0 && $result->fields[$lang] != ''){
        return $result->fields[$lang];
    } else {
        return $string;
    }
}

function __get_lang(){
    global $configs, $user;
    if(count($user) > 0){
        $result = $user['bahasa'];
    } else {
        $result = $configs->default_lang;
    }
    return $result;
}
