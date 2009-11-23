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
 *  vascularclass.php
 *  
 *  Created on Sep 14, 2009, 9:47:51 AM
 */

require_once MODULES_DIR . DS . 'vascular' . DS . 'config.inc';

class vascularModule extends mainModule
{
    var $title = 'vascular module';
    var $description = '';
    var $hidden_fields = array(
        'id', 'inputer', 'inputtime', 'updated'
    );
    var $interpreter = array(
        'cca' => array(
            'alias' => 'CCA-PSV (CM/SEC)'
        ),
        'ica' => array(
            'alias' => 'ICA (CM/SEC)',
            'micro' => array(
                'psv' => 'PSV',
                'edv' => 'EDV'
            )
        ),
        'psvratio' => array(
            'alias' => 'ICA/CCA (PSV RATIO)'
        ),
        'averteb' => array(
            'alias' => 'A. VERTEB',
            'micro' => array(
                'd' => 'D',
                'psv' => 'PSV'
            )
        )
    );
    var $intercols = array(
        'imc' => 'IMC',
        'plaqthr' => 'PLAQ/THR'
    );
    var $interpos = array('right','left');
    var $formtype_fields = array(
        'patients' => 'hidden',
        'no_registrasi' => 'info',
        'klinis' => 'text',
        'tgl_periksa' => 'info',
        'interpretasi' => 'textarea'
    );

    function menu(){
        $items['vascular_form'] = array(
            'title' => __t('vascular form'),
            'description' => __t('vascular check form'),
            'path' => '/user/vascular/form',
            'exec' => 'form',
            'weight' => 5,
            'user_required' => 3
        );
        $items['vascular_checkform'] = array(
            'title' => __t('vascular form'),
            'description' => __t('vascular check form'),
            'path' => '/user/vascular/checkform',
            'exec' => 'checkform',
            'weight' => 5,
            'user_required' => 3
        );
        $items['vascular_today_patient_lists'] = array(
            'title' => __t('vascular form'),
            'description' => __t('vascular check form'),
            'path' => '/user/vascular/today_patient_lists',
            'exec' => 'today_patient_lists',
            'weight' => 5,
            'user_required' => 3
        );
        $items['vascular_form_submit'] = array(
            'title' => __t('vascular form submit'),
            'description' => __t('execute vascular check form'),
            'path' => '/user/vascular/form_submit',
            'exec' => 'form_submit',
            'weight' => 5,
            'user_required' => 3
        );
        $items['vascular_message'] = array(
            'title' => __t('vascular message'),
            'description' => __t('get vascular message'),
            'path' => '/user/vascular/message',
            'exec' => 'message',
            'weight' => 5,
            'user_required' => 3
        );
        return $items;
    }

    function __get_vascular_data($id){
        $result = array();
        $this->query->connect();
        $this->query->getSelect(
            array(),
            array('vascular'),
            array(
                array('&&', "id=" . $id)
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            foreach($query->fields as $key => $value){
                $result[$key] = $value;
            }
        } unset($query);
        return $result;
    }

    function form($vascular_id=NULL){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        } elseif(isset($vascular_id) && !is_null($vascular_id)){
            $vcache = $this->__get_vascular_data($vascular_id);
        } else {
            $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
            if(count($dump) > 3){
                $vcache['idkunjungan'] = $dump[3]; unset($dump);
                $this->query->connect();
                $sql = $this->query->getSelect(
                    array('patients'),
                    array('kunjungan'),
                    array(
                        array('&&', "id=" . $vcache['idkunjungan'])
                    )
                );
                $query = $this->query->conn->Execute($sql); unset($sql);
                $this->query->close();
                $idpatients = $query->fields['patients']; unset($query);
                $vcache['patients'] = $idpatients;
                unset($idpatients);
            } else {
                redirect_to('/user/vascular/today_patient_lists');
            } unset($dump);
        }
        $form['vascular'] = array(
            '#type' => 'special',
            '#id' => 'vascular',
            '#title' => __t('hasil pemeriksaan angiologi<br />(C A R O T I S  &  A. VERTEBRALIS)'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/user/vascular/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE,
            '#formtpl' => MODULES_DIR . DS . 'vascular' . DS . 'vascular.tpl.php',
            '#interpreter' => $this->interpreter,
            '#intercols' => $this->intercols,
            '#interpos' => $this->interpos
        );
        $form['vascular']['idkunjungan'] = array(
            '#type' => 'hidden',
            '#value' => isset($vcache['idkunjungan']) ? $vcache['idkunjungan'] : ''
        );
        $thefields = $this->__get_data_fields('vascular', $this->query);
//        echo '<pre>'; print_r($thefields); echo '</pre>';
        foreach($thefields as $value){
            if(in_array($value, $this->hidden_fields)){
                if($value == 'id'){
                    $form['vascular'][$value] = array(
                        '#type' => 'hidden',
                        '#value' => isset($vcache['id']) ? $vcache['id'] : ''
                    );
                }
            } elseif(!preg_match('/^right_/', $value) && !preg_match('/^left_/', $value)) {
                if($value == 'tgl_periksa'){
                    if(!isset($vcache['tgl_periksa']) || $vcache['tgl_periksa'] == ''){
                        $vcache['tgl_periksa'] = date('Y-m-d', $this->config->time);
                    }
                } elseif($value == 'patients'){
                    $form['vascular'][$value] = array(
                        '#type' => 'hidden',
                        '#value' => $vcache['patients']
                    );
                    $query = $this->__get_patient_data($vcache['patients'], array('nama', 'tgl_lahir', 'alamat', 'kota', 'propinsi', 'nomor'));
                    if(count($query) > 0){
                        foreach($query as $ky => $vl){
                            if($ky == 'tgl_lahir'){
//                                $vl = $this->agecount_in_month(strtotime($vl));
                                $vl = round(($this->agecount_in_month(strtotime($vl))/12),0);
                                $form['vascular']['umur'] = array(
                                    '#type' => 'info',
                                    '#value' => $vl . ' tahun',
                                    '#title' => __t('umur'),
                                    '#tbpos' => 4
                                );
                            } else {
                                if($ky != 'kota' && $ky != 'propinsi'){
                                    if($ky == 'alamat'){
                                        $vl = $vl . ' ' . $query['kota'] . ' ' . $query['propinsi'];
                                        $tbpos = 3;
                                    } elseif($ky == 'nomor'){
                                        $ky = 'no_registrasi';
                                        $tbpos = 0;
                                    } elseif($ky == 'nama'){
                                        $tbpos = 2;
                                    }
                                    $form['vascular'][$ky] = array(
                                        '#type' => $ky == 'alamat' ? 'textarea' : 'info',
                                        '#value' => $vl,
                                        '#title' => __t($ky),
                                        '#tbpos' => $tbpos
                                    );
                                    if($ky == 'alamat'){
                                        $form['vascular'][$ky]['#extra'] = 'readonly="true"';
                                        $form['vascular'][$ky]['#cols'] = '55';
                                        $form['vascular'][$ky]['#rows'] = '3';
                                    } elseif($ky == 'no_registrasi'){
                                        $form['vascular'][$ky]['#link'] = '/user/vascular/today_patient_lists';
                                    }
                                    unset($tbpos);
                                }
                            }
                        }
                    }
                    $this->query->close();
                }
                if($value != 'no_registrasi'){
                    $form['vascular'][$value] = array(
                        '#type' => $this->formtype_fields[$value],
                        '#value' => isset($vcache[$value]) ? $vcache[$value] : '',
                        '#size' => $this->formtype_fields[$value] != 'select' && $this->formtype_fields[$value] != 'date' ? 20 : 1,
                        '#title' => __t($value),
                        '#error' => isset($vcache['blank']) && in_array($value, $vcache['blank']) ? 1 : 0
                    );
                }
                if($value == 'tgl_periksa'){
                    $dump = explode('-', $vcache['tgl_periksa']);
                    $form['vascular']['tgl_periksa']['#value'] = $dump[2] . ' ' . $this->nama_bulan[(int)$dump[1]] . ' ' . $dump[0];
                    $form['vascular']['tgl_periksa']['#tbpos'] = 1;
                } elseif($value == 'klinis'){
                    $form['vascular']['klinis']['#tbpos'] = 5;
                    $form['vascular']['klinis']['#size'] = 20;
                } elseif($value == 'interpretasi'){
                    $form['vascular']['interpretasi']['#cols'] = 85;
                    $form['vascular']['interpretasi']['#rows'] = 5;
                }
            }
        }
        foreach($this->interpreter as $key => $value){
            if(isset($value['micro'])){
                foreach($value['micro'] as $ky => $vv){
                    foreach($this->interpos as $vl){
                        foreach($this->intercols as $ke => $lv){
                            foreach($thefields as $val){
                                if(preg_match('/^right_/', $val) || preg_match('/^left_/', $val)){
                                    $dump = explode('_', $val);
                                    if(count($dump) > 3){
                                        if($dump[0] == $vl && $dump[1] == $key && $dump[2] == $ky && $dump[3] == $ke){
                                            $form['vascular']['data'][$val] = array(
                                                '#type' => 'text',
                                                '#value' => isset($vcache[$val]) ? $vcache[$val] : '',
                                                '#position' => $vl,
                                                '#column' => $ke,
                                                '#size' => 8,
                                                '#error' => isset($vcache['blank']) && in_array($val, $vcache['blank']) ? 1 : 0
                                            );
                                            break;
                                        }
                                    }
                                    unset($dump);
                                }
                            }
                        }
                    }
                }
            }
            foreach($this->interpos as $vl){
                foreach($this->intercols as $ke => $lv){
                    foreach($thefields as $val){
                        if(preg_match('/^right_/', $val) || preg_match('/^left_/', $val)){
                            $dump = explode('_', $val);
                            if($dump[0] == $vl && $dump[1] == $key && $dump[2] == $ke){
                                $form['vascular']['data'][$val] = array(
                                    '#type' => 'text',
                                    '#value' => isset($vcache[$val]) ? $vcache[$val] : '',
                                    '#position' => $vl,
                                    '#column' => $ke,
                                    '#size' => 8,
                                    '#error' => isset($vcache['blank']) && in_array($val, $vcache['blank']) ? 1 : 0
                                );
                                break;
                            }
                            unset($dump);
                        }
                    }
                }
            }
        }
        $form['vascular']['submit'] = array(
            '#type' => 'submit',
            '#value' => 'submit',
            '#extra' => ' class="button"'
        );
//        echo '<pre>'; print_r($form); echo '</pre>';
        return $form;
    }

    function form_submit(){
        $ignoredfields = array(
            'alamat', 'submit', 'blank', 'id', 'idkunjungan'
        );
        $dump = $this->__write_form_cache();
        foreach($dump as $key => $value){
            if(!in_array($key, $ignoredfields)){
                $thevalue[$key] = $value;
            }
        }
        if($dump['id'] == ''){
            $thevalue['id'] = $this->__get_id_insert_value('vascular', 'id', $this->query);
            $thevalue['tgl_periksa'] = date('Y-m-d', $this->config->time);
            $thevalue['inputer'] = $_COOKIE[$this->config->cookieid];
            $thevalue['inputtime'] = date('Y-m-d H:i:s', $this->config->time);
            $this->query->connect();
            $sql = $this->query->updateData(
                'kunjungan',
                array(
                    'doneby' => $_COOKIE[$this->config->cookieid]
                ),
                array(
                    array('&&', "id=" . $dump['idkunjungan'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        } else {
            $thevalue['updated'] = $_COOKIE[$this->config->cookieid] . '|' . date('Y-m-d H:i:s', $this->config->time);
        }
//        echo '<pre>'; print_r($thevalue); echo '</pre>';
        $this->query->connect();
        $sql = $this->query->saveData(
            'vascular', $thevalue
        );
        $this->query->conn->Execute($sql); unset($sql);
        $sql = $this->query->getSelect(
            array('nama'),
            array('patients'),
            array(
                array('&&', "id=" . $thevalue['patients'])
            )
        );
        $query = $this->query->conn->Eecute($sql); unset($sql);
        $this->query->close();
        unset($dump, $thevalue);
        $message = 'data pemeriksaan vascular pasien atas nama ' . $query->fields['nama'] . ' telah disimpan !';
        unset($query);
        redirect_to('/user/vascular/message/' . rawurlencode($message));
    }
}