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
 *  istirahatberdiriclass.php
 *  
 *  Created on Oct 3, 2009, 4:35:17 PM
 */

require_once MODULES_DIR . DS . 'istirahatberdiri' . DS . 'config.inc';

class istirahatberdiriModule extends mainModule
{
    var $title = 'istirahatberdiri module';
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

    function treadmill_menu(){
        $result = array();
//        echo "lagi disini";
        $result['#title'] = __t('Fase istirahat Berdiri');
        $result['#tpl'] = MODULES_DIR . DS . 'istirahatberdiri' . DS . 'istirahatberdiri.tpl';
        $datafield = $this->__get_data_fields('istirahatberdiri', $this->query);
        if (count($this->config->free_val) > 0){
            $vcache = $this->config->free_val;
            $sql = $this->query->getSelect(
                array(),
                array('istirahatberdiri'),
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
        foreach($datafield as $key => $value){
            if($value == 'catched'){
                if(!isset($vcache['catched']) || $vcache['catched'] == ''){
                    $vcache['catched'] = date('Y-m-d H:i:s', $this->config->time);
                }
            }
            $result['datafield'][$value] = array(
                'title' => __t($value),
                'type' => $this->config->typeoffields[$value],
                'value' => isset($vcache[$value]) ? $vcache[$value] : ''
            );
            if(in_array($value, $this->config->fieldsisarray)){
                $result['datafield'][$value]['theref'] = $this->__get_refs($value);
                $result['datafield'][$value]['blankopt'] = 1;
            } elseif($this->config->typeoffields[$value] == 'datetime'){
                $result['datafield'][$value]['theref'] = $this->nama_bulan;
                $result['datafield'][$value]['timenow'] = $this->config->time;
            } else {
                $result['datafield'][$value]['size'] = 6;
            }

            
            $result['datafield'][$value]['readonly'] = isset($this->config->free_val['readonly']) ? true : false;
        }
//        echo '<pre>'; print_r($result['datafield']); echo '</pre>';
        return $result;
    }

    function treadmill_submit(){
        $thefields = $this->__get_data_fields('istirahatberdiri', $this->query);
        foreach($this->config->free_val as $key => $value){
            if(in_array($key, $thefields)){
                if($key == 'catched'){
                    $value = $value[0] . '-' . $value[1] . '-' . $value[2] . ' ' . $value[3] . ':' . $value[4] . ':' . $value[5];
                } elseif($key == 'risk_factor' || $key == 'ilness_history'){
                    if(count($value) > 0){
                        $value = implode(',', $value);
                    }
                }
                $thevalue[$key] = $value;
            }
        } unset($thefields);
        if($_POST['id'] != ''){
            unset($thevalue['id']);
            $sql = $this->query->updateData(
                'istirahatberdiri',
                $thevalue,
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
        } else {
            $sql = $this->query->saveData(
                'istirahatberdiri',
                $thevalue
            );
        }
//        echo '<pre>'; print_r($thevalue); echo '</pre>';
        unset($thevalue);
        $this->query->connect();
        $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
    }

}