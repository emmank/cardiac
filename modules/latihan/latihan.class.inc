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
 *  latihanclass.php
 *  
 *  Created on Oct 3, 2009, 4:35:17 PM
 */

require_once MODULES_DIR . DS . 'latihan' . DS . 'config.inc';

class latihanModule extends mainModule
{
    var $title = 'latihan';
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
        $this->sync_scheme('latihan', $this->query);
        $result = array();
        $result['#title'] = __t('Fase latihan');
        $result['#tpl'] = MODULES_DIR . DS . 'latihan' . DS . 'latihan.tpl';
        $datafields = $this->__get_data_fields('latihan', $this->query);
        if (count($this->config->free_val) > 0){
            $vcache = $this->config->free_val;
            $sql = $this->query->getSelect(
                array(),
                array('latihan'),
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
        foreach($this->config->urutanform as $key => $value){
            foreach($value as $ky => $vl){
                if(is_array($vl)){
                    foreach($vl as $yk => $lv){
                        if(is_array($lv)){
                            foreach($lv as $kk => $vv){
                                $result['datafields'][$key][$ky][$yk][$vv] = array(
                                    'title' => __t($vv),
                                    'type' => $this->config->typeoffields[$vv],
                                    'value' => isset($vcache[$vv]) ? $vcache[$vv] : ''
                                );
                                if(in_array($vv, $this->config->fieldsisarray)){
                                    $result['datafields'][$key][$ky][$yk][$vv]['theref'] = $this->__get_refs($vv);
                                } elseif($this->config->typeoffields[$vv] == 'datetime'){
                                    $result['datafields'][$key][$ky][$yk][$vv]['theref'] = $this->nama_bulan;
                                    $result['datafields'][$key][$ky][$yk][$vv]['timenow'] = $this->config->time;
                                } else {
                                    $result['datafields'][$key][$ky][$yk][$vv]['size'] = 6;
                                }
                                $result['datafields'][$key][$ky][$yk][$vv]['readonly'] = isset($this->config->free_val['readonly']) ? true : false;
                            }
                        } else {
                            $result['datafields'][$key][$ky][$lv] = array(
                                'title' => __t($lv),
                                'type' => $this->config->typeoffields[$lv],
                                'value' => isset($vcache[$lv]) ? $vcache[$lv] : ''
                            );
                            if(in_array($lv, $this->config->fieldsisarray)){
                                $result['datafields'][$key][$ky][$lv]['theref'] = $this->__get_refs($lv);
                            } elseif($this->config->typeoffields[$lv] == 'datetime'){
                                $result['datafields'][$key][$ky][$lv]['theref'] = $this->nama_bulan;
                                $result['datafields'][$key][$ky][$lv]['timenow'] = $this->config->time;
                            } else {
                                $result['datafields'][$key][$ky][$lv]['size'] = 6;
                            }
                            $result['datafields'][$key][$ky][$lv]['readonly'] = isset($this->config->free_val['readonly']) ? true : false;
                        }
                    }
                } else {
                    $result['datafields'][$key][$vl] = array(
                        'title' => __t($vl),
                        'type' => $this->config->typeoffields[$vl],
                        'value' => isset($vcache[$vl]) ? $vcache[$vl] : ''
                    );
                    if(in_array($vl, $this->config->fieldsisarray)){
                        $result['datafields'][$key][$vl]['theref'] = $this->__get_refs($vl);
                    } elseif($this->config->typeoffields[$vl] == 'datetime'){
                        $result['datafields'][$key][$vl]['theref'] = $this->nama_bulan;
                        $result['datafields'][$key][$vl]['timenow'] = $this->config->time;
                    } else {
                        $result['datafields'][$key][$vl]['size'] = 6;
                    }
                    $result['datafields'][$key][$vl]['readonly'] = isset($this->config->free_val['readonly']) ? true : false;
                }
            }
        }
//        foreach($datafields as $key => $value){
//            if($value == 'catched'){
//                if(!isset($vcache['catched']) || $vcache['catched'] == ''){
//                    $vcache['catched'] = date('Y-m-d H:i:s', $this->config->time);
//                }
//            }
//            $result['datafields'][$value] = array(
//                'title' => __t($value),
//                'type' => $this->config->typeoffields[$value],
//                'value' => isset($vcache[$value]) ? $vcache[$value] : ''
//            );
//
//
//        }
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function treadmill_submit(){
        $thefields = $this->__get_data_fields('latihan', $this->query);
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
                'latihan',
                $thevalue,
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
        } else {
            $sql = $this->query->saveData(
                'latihan',
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