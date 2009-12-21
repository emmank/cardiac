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
    global $systemquery, $configs;
    $lang = __get_lang();
    $sql = $systemquery->getSelect(
        array('id'),
        array('dumptr'),
        array(
            array('&&', "id=" . $string)
        )
    );
    $systemquery->connect();
    $getit = $systemquery->conn->Execute($sql); unset($sql);
    $systemquery->close();
    $sql = $systemquery->getSelect(
        array($lang),
        array('translations'),
        array(
            array('&&', "strkey=" . trim(strtolower($string)))
        )
    );
    $systemquery->connect();
    $result = $systemquery->conn->Execute($sql); unset($sql);
    $systemquery->close();
    if($result->_numOfRows > 0 && trim($result->fields[$lang]) != ''){
        if($getit->_numOfRows > 0){
            $sql = $systemquery->setDelete(
                'dumptr',
                array(
                    array('&&', "id=" . $string)
                )
            );
            $systemquery->connect();
            $systemquery->conn->Execute($sql); unset($sql);
            $systemquery->close();
        } unset($getit);
        return $result->fields[$lang];
    } else {
        $string = trim(strtolower($string));
        if($getit->_numOfRows < 1 && $string != ''){
//            $sql = $systemquery->getSelect(
//                    array($lang),
//                    array('translate'),
//                    array(
//                        array('&&', $lang . "=" . $string)
//                    )
//            );
            $sql = $systemquery->saveData(
                'dumptr',
                array(
                    'id' => $string
                )
            );
            $systemquery->connect();
            $systemquery->conn->Execute($sql); unset($sql);
            $systemquery->close();
        } unset($getit);
        return ucwords(str_replace("_"," ",$string));
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
