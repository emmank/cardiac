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
 *  deskripsiclass.php
 *  
 *  Created on Oct 3, 2009, 4:35:17 PM
 */

require_once MODULES_DIR . DS . 'deskripsi' . DS . 'config.inc';

class deskripsiModule extends mainModule
{
    var $title = 'deskripsi module';
    var $description = '';



    function __get_refs($fields, $sort=NULL){
        $result = array();
        $sql = $this->query->getSelect(
            array(),
            array($this->config->reftable[$fields][0]),
            NULL,
            (!is_null($sort) ? $sort . ' asc' : 'id asc')
        );
        $this->query->connect();
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            $result[$query->fields['id']] = $query->fields[$this->config->reftable[$fields][1]];
            $query->MoveNext();
        }
        return $result;
    }

    function echocardiography_menu(){
        $this->sync_scheme('deskripsi', $this->query);
        $result = array();
        $result['#title'] = __t('Description');
        $result['#tpl'] = MODULES_DIR . DS . 'deskripsi' . DS . 'deskripsi.tpl';
        $datafields = $this->__get_data_fields('deskripsi', $this->query);
        if (count($this->config->free_val) > 0){
            $vcache = $this->config->free_val;
            $sql = $this->query->getSelect(
                array(),
                array('deskripsi'),
                array(
                    array('&&', "id=" . $vcache['id'])
                )
            ); unset($vcache);
            $this->query->connect();
            $getit = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            if($getit->_numOfRows > 0){
                foreach($getit->fields as $key => $value){
                    $vcache[$key] = $value;
                }
            }
        }
        foreach($datafields as $key => $value){
            if($value == 'catched'){
                if(!isset($vcache['catched']) || $vcache['catched'] == ''){
                    $vcache['catched'] = date('Y-m-d H:i:s', $this->config->time);
                }
            }
            $result['datafields'][$value] = array(
                'title' => __t($value),
                'type' => $this->config->fields_form_type_lv[$value],
                'value' => isset($vcache[$value]) ? $vcache[$value] : ''
            );
            if(in_array($value, $this->config->fieldsisarray)){
                $result['datafields'][$value]['theref'] = $this->__get_refs($value);
                $result['datafields'][$value]['blankopt'] = 1;
            } elseif($this->config->fields_form_type_lv[$value] == 'datetime'){
                $result['datafields'][$value]['theref'] = $this->nama_bulan;
                $result['datafields'][$value]['timenow'] = $this->config->time;
            } else {
                $result['datafields'][$value]['size'] = 6;
            }
            $result['datafields'][$value]['readonly'] = isset($this->config->free_val['readonly']) ? true : false;
        }
        return $result;
    }

    function echocardiography_submit(){
        $thefields = $this->__get_data_fields('deskripsi', $this->query);
        $patientsdata = array();
        foreach($this->config->free_val as $key => $value){
            if(in_array($key, $thefields)){
                if (is_array($value)){
                    ksort($value);
                    $thevalue[$key] = implode('|', $value);
                } else {
                    $thevalue[$key] = $value;
                }
//                echo '<pre>'; print_r($thevalue); echo '</pre>';
            }
        } unset($thefields, $patient_fields);
//        echo '<pre>'; print_r($thevalue); echo '</pre>';
        if($_POST['id'] != ''){
            unset($thevalue['id']);
            $opr = 'update';
            $strid = array('id', $_POST['id']);
        } else {
            $opr = 'insert';
            $strid = array('id', $thevalue['id']);
        }
        $this->__exec_db_ops(
            $this->query,
            'deskripsi',
            $opr,
            $strid,
            $thevalue
        );
//        unset($opr, $strid, $thevalue);
//        echo '<pre>'; print_r($patientdata); echo '</pre>';
//        $this->__exec_db_ops(
//            $this->query,
//            'patients',
//            'update',
//            array('id', $this->config->free_val['patients']),
//            $patientsdata
//        );
//        unset($patientsdata);
    }

}