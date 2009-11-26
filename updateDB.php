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
 *  updateDB.php
 *  
 *  Created on Nov 22, 2009, 5:21:39 PM
 */

require 'includes' . DIRECTORY_SEPARATOR . 'constant.inc';
require INCLUDES_DIR . DS . 'defaultvars.inc';

$sql = $systemquery->getDescribe('registry');
$systemquery->connect();
$getit = $systemquery->conn->Execute($sql);
$systemquery->close();
if($getit->_numOfRows > 0){
    for($i=0; $i<$getit->_numOfRows; $i++){
        if($getit->fields['Field'] == 'path_alls'){
            $is_there = 0; break;
        }
        $getit->MoveNext();
    }
} unset($getit);
if(!isset($is_there)){
    $sql = $systemquery->alterTableColumn(
        'registry',
        array(
            'path_alls'
        ),
        'add',
        'text'
    );
} else {
    $sql = $systemquery->alterTableColumn(
        'registry',
        array(
            'path_alls',
            'path_alls'
        ),
        'change',
        'text'
    );
}
$systemquery->connect();
$systemquery->conn->Execute($sql);
$systemquery->close();
header('Location:/');