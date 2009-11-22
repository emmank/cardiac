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
 *  setPatientsIndex.php
 *  
 *  Created on Nov 22, 2009, 5:21:39 PM
 */

require 'includes' . DIRECTORY_SEPARATOR . 'constant.inc';
require INCLUDES_DIR . DS . 'defaultvars.inc';

require MODULES_DIR . DS . 'patient' . DS . 'patient.module';
$patient_config->time = $configs->time;
$patient_config->timelog_idle = $configs->timelog_idle;
$patient_query->dbname = $patient_config->dbpatient['name'];
$patient_query->dbprefix = $patient_config->dbpatient['prefix'];
$patient_query->dbsuffix = $patient_config->dbpatient['suffix'];
$patient_query->tbprefix = $patient_config->dbpatient['tbprefix'];
$patient_query->tbsuffix = $patient_config->dbpatient['tbsuffix'];
$patient_query->hostname = $patient_config->dbpatient['host'];
$patient_query->username = $patient_config->dbpatient['user'];
$patient_query->passwd = $patient_config->dbpatient['passwd'];
$patient_query->conn = &ADONewConnection($patient_config->rdbms);

$sql = $patient_query->getDescribe('isearch_patients');
$patient_query->connect();
$getit = $patient_query->conn->Execute($sql); unset($sql);
$patient_query->close();
if($getit->_numOfRows < 1){
    $sql = $patient_query->createTable(
        'isearch_patients',
        array(
            'id' => 'int not null',
            'phrase' => 'text'
        ),
        'id'
    );
    $patient_query->connect();
    $patient_query->conn->Execute($sql); unset($sql);
    $patient_query->close();
} unset($getit);

$sql = $patient_query->setDelete(
    'isearch_patients'
);
$patient_query->connect();
$patient_query->conn->Execute($sql); unset($sql);
$patient_query->close();
$sql = $patient_query->getSelect(
    array(),
    array('patients'),
    NULL,
    'id'
);
$patient_query->connect();
$getit = $patient_query->conn->Execute($sql); unset($sql);
$patient_query->close();
if($getit->_numOfRows > 0){
    for($i=0; $i<$getit->_numOfRows; $i++){
        $thevalue = array();
        $thevalue['id'] = $getit->fields['id'];
        $thevalue['phrase'] = '';
        foreach($getit->fields as $value){
            if(isset($koma)){$thevalue['phrase'] .= ' ';}
            $thevalue['phrase'] .= $value; $koma = 0;
        } unset($koma);
        $sql = $patient_query->saveData(
            'isearch_patients',
            $thevalue
        ); unset($thevalue);
        $patient_query->connect();
        $patient_query->conn->Execute($sql); unset($sql);
        $patient_query->close();
        $getit->MoveNext();
    }
}

header('Location:/');