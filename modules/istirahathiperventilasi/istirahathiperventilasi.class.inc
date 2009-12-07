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
 *  istirahathiperventilasiclass.php
 *  
 *  Created on Oct 3, 2009, 4:35:17 PM
 */

require_once MODULES_DIR . DS . 'istirahathiperventilasi' . DS . 'config.inc';

class istirahathiperventilasiModule extends mainModule
{
    var $title = 'istirahat hiperventilasi';
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
        $this->sync_scheme('istirahathiperventilasi', $this->query);
        $result = array();
        $result['#title'] = __t('Istirahat Hiperventilasi');
        $result['#tpl'] = MODULES_DIR . DS . 'istirahathiperventilasi' . DS . 'istirahathiperventilasi.tpl';
        $datafields = $this->__get_data_fields('istirahathiperventilasi', $this->query);
        if (count($this->config->free_val) > 0){
            $vcache = $this->config->free_val;
            $sql = $this->query->getSelect(
                array(),
                array('istirahathiperventilasi'),
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
        rsort($datafields);
        foreach($datafields as $key => $value){
            if($value == 'catched'){
                if(!isset($vcache['catched']) || $vcache['catched'] == ''){
                    $vcache['catched'] = date('Y-m-d H:i:s', $this->config->time);
                }
            }
            $result['datafields'][$value] = array(
                '#title' => __t($value),
                '#type' => $this->config->fields_form_type[$value],
                '#value' => isset($vcache[$value]) ? $vcache[$value] : '',
                '#size' => $this->config->fields_form_type[$value] != 'select' && $this->config->fields_form_type[$value] != 'date' ? 20 : 1,
                '#error' => isset($vcache['blank']) && in_array($value, $vcache['blank']) ? 1 : 0
            );
            if(in_array($value, $this->config->fieldsisarray)){
                $result['datafields'][$value]['#theref'] = $this->__get_refs($value);
            } elseif($this->config->typeoffields[$value] == 'datetime'){
                $result['datafields'][$value]['#theref'] = $this->nama_bulan;
                $result['datafields'][$value]['#timenow'] = $this->config->time;
//            } else {
//                $result['datafields'][$value]['#size'] = 6;
            }
            if(in_array($value, $this->config->qrs_complex) || in_array($value, $this->config->segment_st) || $value == 'gelombang_t'){
                $result['datafields'][$value]['#customized']['title'] = in_array($value, $this->config->qrs_complex) ? __t('qrs_complex') : ($value == 'gelombang_t' ? __t('gelombang_t') : __t('segment_st'));
                $result['datafields'][$value]['#customized']['id'] = in_array($value, $this->config->qrs_complex) ? 'qrs_complex' : ($value == 'gelombang_t' ? 'gelombang_t' : 'segment_st');
                if($this->config->fields_form_type[$value] == 'select2'){
                    $result['datafields'][$value]['#customized']['option'] =  array(
                        '1mm - 2mm' => '1mm - 2mm',
                        '> 2mm - 3mm' => '> 2mm - 3mm',
                        '> 3mm' => '> 3mm'
                    );
                } elseif ($this->config->fields_form_type[$value] == 'select3') {
                    $result['datafields'][$value]['#customized']['option'] =  array(
                        'Q Patologi +' => 'Q Patologi +',
                        'Q Patologi -' => 'Q Patologi -'
                    );
                } elseif ($value == 'gelombang_t') {
                    $result['datafields'][$value]['#customized']['option'] =  array(
                        'Normal' => 'Normal',
                        'Inverted' => 'Inverted'
                    );
                }
            }
        }
        return $result;
    }

    function treadmill_submit(){
        $thefields = $this->__get_data_fields('istirahathiperventilasi', $this->query);
        foreach($this->config->free_val as $key => $value){
             if(preg_match('/^istirahathiperventilasi_/', $key)){
                $key = trim(preg_replace('/^istirahathiperventilasi_/', '', $key));
                if(in_array($key, $thefields)){
                    if($key == 'gelombang_t'){
                        if($value != 'Inverted'){
                            unset($value[1]);
                        }
                    }
                    if(count($value) > 0){
                        $value = implode('|', $value);
                    }
                    $thevalue[$key] = $value;
                }
            }
       } unset($thefields);
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
            'istirahathiperventilasi',
            $opr,
            $strid,
            $thevalue
        );
        unset($opr, $strid, $thevalue);
    }

}