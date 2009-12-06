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
 *  recoveryclass.php
 *  
 *  Created on Oct 1, 2009, 1:12:45 PM
 */

require_once MODULES_DIR . DS . 'recovery' . DS . 'config.inc';

class recoveryModule extends mainModule
{
    var $title = 'recovery';
    var $description = '';
    var $hidden_fields = array(
        'id', 'id_pasien', 'inputer','updated', 'inputtime','tgl'
    );

    function menu(){
        $items['recovery_form'] = array(
            'title' => __t('form recovery'),
            'description' => __t('formulir recovery'),
            'path' => '/user/recovery/form',
            'exec' => 'form',
            'weight' => '0',
            'user_required' => 'recovery'
        );
        $items['recovery_form_submit'] = array(
            'title' => __t('form recovery'),
            'description' => __t('formulir recovery'),
            'path' => '/user/recovery/form_submit',
            'exec' => 'form_submit',
            'weight' => '0',
            'user_required' => 'recovery'
        );
        $items['recovery_get_lists'] = array(
            'title' => __t('form recovery'),
            'description' => __t('formulir recovery'),
            'path' => '/user/recovery/today_recovery_lists',
            'exec' => '__get_today_lists',
            'weight' => '0',
            'user_required' => 'recovery'
        );
        $items['recovery_message'] = array(
            'title' => __t('recovery message'),
            'description' => __t('get recovery message'),
            'path' => '/user/recovery/message',
            'exec' => 'message',
            'weight' => 5,
            'user_required' => 'recovery'
        );
        $items['recovery_message'] = array(
            'title' => __t('recovery message'),
            'description' => __t('get recovery message'),
            'path' => '/user/recovery/message',
            'exec' => 'message',
            'weight' => 5,
            'user_required' => 'recovery'
        );
        $items['recovery_view'] = array(
            'title' => __t('recovery'),
            'description' => __t('explore recovery'),
            'path' => '/user/recovery/view',
            'exec' => 'view',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['recovery_detail'] = array(
            'title' => __t('detail recovery'),
            'description' => __t("detail recovery's patients"),
            'path' => '/user/recovery/detail_form',
            'exec' => 'detail_form',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['recovery_search'] = array(
            'title' => __t('search recovery'),
            'description' => __t("search recovery's patients"),
            'path' => '/user/recovery/search',
            'exec' => 'search',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['recovery_search_submit'] = array(
            'title' => __t('submitted search recovery'),
            'description' => __t("submitted search recovery's patients"),
            'path' => '/user/recovery/search_submit',
            'exec' => 'search_submit',
            'weight' => '0',
            'user_required' => 'users'
        );
        return $items;
    }

    function treadmill_menu(){
        $this->sync_scheme('recovery', $this->query);
        $result = array();
        $result['#title'] = __t('FaseRecovery');
        $result['#tpl'] = MODULES_DIR . DS . 'recovery' . DS . 'recovery.tpl';
        $datafields = $this->__get_data_fields('recovery', $this->query);
        if (count($this->config->free_val) > 0){
            $vcache = $this->config->free_val;
            $sql = $this->query->getSelect(
                array(),
                array('recovery'),
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
        $result['recovery']['kunjungan'] = array(
            '#type' => 'hidden',
            '#value' => isset($vcache['kunjungan']) ? $vcache['kunjungan'] : ''
        );
        $thefields = $this->__get_data_fields('recovery', $this->query);
        foreach($thefields as $value){
            if(in_array($value, $this->hidden_fields)){
                if($value == 'id'){
                    $result['recovery'][$value] = array(
                        '#type' => 'hidden',
                        '#value' => isset($vcache['id']) ? $vcache['id'] : ''
                    );
                }
            } else {
                if($value == 'tgl'){
                    if(!isset($vcache['tgl']) || $vcache['tgl'] == ''){
                        $vcache['tgl'] = date('Y-m-d', $this->config->time);
                    }
                } elseif($value == 'patients'){
                    $result['recovery'][$value] = array(
                        '#type' => 'hidden',
                        '#value' => $vcache['patients']
                    );
                    $query = $this->__get_patient_data($vcache['patients'], array('nama', 'tgl_lahir', 'alamat', 'kota', 'propinsi', 'nomor', 'kelamin', 'gol_darah'));
                    if(count($query) > 0){
                        foreach($query as $ky => $vl){
                            if($ky == 'tgl_lahir'){
//                                $vl = $this->agecount_in_month(strtotime($vl));
//                                $vl = round(($this->agecount_in_month(strtotime($vl))/12),0);
//                                $result['recovery']['umur'] = array(
//                                    '#type' => 'info',
//                                    '#value' => $vl . ' tahun',
//                                    '#title' => __t('umur'),
//                                    '#tbpos' => 3
//                                );
                            } else {
                                if($ky != 'kota' && $ky != 'propinsi'){
                                    if($ky == 'alamat'){
                                        $vl = $vl . ' ' . $query['kota'] . ' ' . $query['propinsi'];
                                        $tbpos = 4;
                                    } elseif($ky == 'nomor'){
                                        $ky = 'no_registrasi';
                                        $tbpos = 0;
                                    } elseif($ky == 'nama'){
                                        $tbpos = 1;
                                    } elseif($ky == 'kelamin'){
                                        $vl = $this->kelamin[$vl];
                                        $tbpos = 2;
                                    } elseif($ky == 'gol_darah'){
                                        $tbpos = 5;
                                    }
                                    $result['recovery'][$ky] = array(
                                        '#type' => $ky == 'alamat' ? 'textarea' : 'info',
                                        '#value' => $vl,
                                        '#title' => __t($ky),
                                        '#tbpos' => $tbpos
                                    );
                                    if($ky == 'alamat'){
                                        $result['recovery'][$ky]['#extra'] = 'readonly="true"';
                                        $result['recovery'][$ky]['#cols'] = '55';
                                        $result['recovery'][$ky]['#rows'] = '3';
                                    } elseif($ky == 'no_registrasi'){
                                        $result['recovery'][$ky]['#link'] = '/user/recovery/today_patient_lists';
                                    }
                                    unset($tbpos);
                                }
                            }
                        }
                        $sql = $this->query->getSelect(
                            array('pukul'),
                            array('kunjungan'),
                            array(
                                array('&&', "patients=" . $vcache['patients'])
                            )
                        );
                        $this->query->connect();
                        $getfrek = $this->query->conn->Execute($sql); unset($sql);
                        $this->query->close();
                        $dumpfrek = array();
                        for($i=0; $i<$getfrek->_numOfRows; $i++){
                            $buffer = date('Y-m-d', strtotime($getfrek->fields['pukul']));
                            if(!in_array($buffer, $dumpfrek)){
                                $dumpfrek[] = $buffer;
                            }
                            unset($buffer);
                            $getfrek->MoveNext();
                        }
                        $result['recovery']['kunjungan_ke'] = array(
                            '#type' => 'info',
                            '#value' => count($dumpfrek),
                            '#title' => __t('kunjungan_ke'),
                            '#tbpos' => 6
                        );
                        unset($dumpfrek, $getfrek);
                        $sql = $this->query->getSelect(
                            array('nama'),
                            array('stafs'),
                            array(
                                array('&&', "id=" . $pengirim)
                            )
                        );
                        $this->query->connect();
                        $getsender = $this->query->conn->Execute($sql); unset($sql);
                        $this->query->close();
                        $result['recovery']['pengirim'] = array(
                            '#type' => 'info',
                            '#value' => $getsender->fields['nama'],
                            '#title' => __t('pengirim'),
                            '#tbpos' => 7
                        );
                        unset($getsender);
                    }
                }
                if($value != 'no_registrasi' && $value != 'kunjungan' && $value != 'patients'){
                    $result['recovery'][$value] = array(
                        '#type' => $this->config->fields_form_type[$value],
                        '#value' => isset($vcache[$value]) ? $vcache[$value] : '',
                        '#size' => $this->config->fields_form_type[$value] != 'select' && $this->config->fields_form_type[$value] != 'date' ? 20 : 1,
                        '#title' => __t($value),
                        '#error' => isset($vcache['blank']) && in_array($value, $vcache['blank']) ? 1 : 0
                    );
                    if(in_array($value, $this->config->fieldsisarray)){
                        $result['recovery'][$value]['#theref'] = $this->__get_refs($value);
                    }
                    if(in_array($value, $this->config->qrs_complex) || in_array($value, $this->config->segment_st) || $value == 'gelombang_t'){
                        $result['recovery'][$value]['#customized']['title'] = in_array($value, $this->config->qrs_complex) ? __t('qrs_complex') : ($value == 'gelombang_t' ? __t('gelombang_t') : __t('segment_st'));
                        $result['recovery'][$value]['#customized']['id'] = in_array($value, $this->config->qrs_complex) ? 'qrs_complex' : ($value == 'gelombang_t' ? 'gelombang_t' : 'segment_st');
                        if($this->config->fields_form_type[$value] == 'select2'){
                            $result['recovery'][$value]['#customized']['option'] =  array(
                                '1mm - 2mm' => '1mm - 2mm',
                                '> 2mm - 3mm' => '> 2mm - 3mm',
                                '> 3mm' => '> 3mm'
                            );
                        } elseif ($this->config->fields_form_type[$value] == 'select3') {
                            $result['recovery'][$value]['#customized']['option'] =  array(
                                'Q Patologi +' => 'Q Patologi +',
                                'Q Patologi -' => 'Q Patologi -'
                            );
                        } elseif ($value == 'gelombang_t') {
                            $result['recovery'][$value]['#customized']['option'] =  array(
                                'Normal' => 'Normal',
                                'Inverted' => 'Inverted'
                            );
                        }
                    }
                }
                if($this->formhabit == 'readonly'){
                    $result['recovery'][$value]['#readonly'] = TRUE;
                }
            }
        }

        $result['recovery']['submit'] = array(
            '#type' => 'submit',
            '#value' => ($this->formhabit == 'readonly' ? __t('edit') : __t('submit'))
        );
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function treadmill_submit(){
        $thefields = $this->__get_data_fields('recovery', $this->query);
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
                'recovery',
                $thevalue,
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
        } else {
            $sql = $this->query->saveData(
                'recovery',
                $thevalue
            );
        }
//        echo '<pre>'; print_r($thevalue); echo '</pre>';
        unset($thevalue);
        $this->query->connect();
        $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
    }

    function __get_recovery_data($id){
        $result = array();
        $sql = $this->query->getSelect(
            array(),
            array('recovery'),
            array(
                array('&&', "id=" . $id)
            )
        );
        $this->query->connect();
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            foreach($query->fields as $key => $value){
                $result[$key] = $value;
            }
        } unset($query);
        return $result;
    }

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
    
}