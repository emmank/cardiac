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
 *  treadmillclass.php
 *  
 *  Created on Oct 1, 2009, 1:12:45 PM
 */

require_once MODULES_DIR . DS . 'treadmill' . DS . 'config.inc';

class treadmillModule extends mainModule
{
    var $title = 'treadmill';
    var $description = 'Manajemen data digital pasien treadmill';
    var $hidden_fields = array(
        'id', 'teens', 'inputer','updated', 'inputtime'
    );

    function menu(){
        $items['treadmill_form'] = array(
            'title' => __t('form treadmill'),
            'description' => __t('formulir treadmill'),
            'path' => '/user/treadmill/form',
            'exec' => 'form',
            'weight' => '0',
            'user_required' => 'treadmill'
        );
        $items['treadmill_form_submit'] = array(
            'title' => __t('form treadmill'),
            'description' => __t('formulir treadmill'),
            'path' => '/user/treadmill/form_submit',
            'exec' => '_form_submit',
            'weight' => '0',
            'user_required' => 'treadmill'
        );
        $items['treadmill_get_lists'] = array(
            'title' => __t('list antrian treadmill'),
            'description' => __t('formulir treadmill'),
            'path' => '/user/treadmill/today_treadmill_lists',
            'exec' => '__get_today_lists',
            'weight' => '0',
            'user_required' => 'treadmill'
        );
        $items['treadmill_message'] = array(
            'title' => __t('treadmillmessage'),
            'description' => __t('get treadmillmessage'),
            'path' => '/user/treadmill/message',
            'exec' => 'message',
            'weight' => 5,
            'user_required' => 'treadmill'
        );
        $items['treadmill_view'] = array(
            'title' => __t('treadmill'),
            'description' => __t('explore treadmill'),
            'path' => '/user/treadmill/view',
            'exec' => 'view',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['treadmill_detail'] = array(
            'title' => __t('detail treadmill'),
            'description' => __t("detail treadmill's patients"),
            'path' => '/user/treadmill/detail_form',
            'exec' => '_detail_form',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['treadmill_search'] = array(
            'title' => __t('search treadmill'),
            'description' => __t("search treadmill's patients"),
            'path' => '/user/treadmill/search',
            'exec' => '_search',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['treadmill_search_submit'] = array(
            'title' => __t('submitted search treadmill'),
            'description' => __t("submitted search treadmill's patients"),
            'path' => '/user/treadmill/search_submit',
            'exec' => '_search_submit',
            'weight' => '0',
            'user_required' => 'users'
        );
        return $items;
    }

    function _search_submit(){
        return $this->__get_search_submit();
    }

    function __get_search_submit($teens=0){
        if(isset($_POST['data'])){
            $str = $_POST['data'];
            $dump = $this->__get_patients_search($str);
        } else {
            $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
            $str = '';
            if(trim($dump[3]) != ''){
                $str = trim($dump[3]);
                $dump = $this->__get_patients_search($str);
            } else {
                $dump = array();
            }
        }
        $result = array();
        $result['type'] = 'notelist';
        $result['title'] = __t('hasil pencarian');
        $result['description'] = __t('hasil pencarian') . ' <strong>"' . $str . '"</strong>';
        unset($str);
        if(count($dump) > 0){
            foreach($dump as $key => $value){
                foreach($value as $ky => $vl){
                    $sql = $this->query->getSelect(
                        array('id', 'inputtime'),
                        array('treadmill'),
                        array(
                            array('&&', "patients=" . $vl),
                            array('&&', "teens=" . ($teens == 0 ? 0 : $teens))
                        )
                    );
                    $this->query->connect();
                    $getit = $this->query->conn->Execute($sql); unset($sql);
                    $this->query->close();
                    if($getit->_numOfRows > 0){
                        if(!isset($cnt)){
                            $cnt = 0;
                            $result['data'] = array();
                        }
                        for($i=0; $i<$getit->_numOfRows; $i++){
                            if(!isset($dumpid)){$dumpid = array();}
                            if(!in_array($getit->fields['id'], $dumpid)){
                                if(count($dumpid) > 0){
                                    $cnt++;
                                }
                                $dumpid[] = $getit->fields['id'];
                                $result['data'][$cnt]['links'] = '/user/treadmill' . ($teens != 0 ? 'anak' : '') . '/detail_form/' . $getit->fields['id'];
                                $result['data'][$cnt]['caption'] = 'Data Tanggal ' . date('j-n-Y H:i:s', strtotime($getit->fields['inputtime']));
                            }
                            $sql = $this->query->getSelect(
                                array(),
                                array('patients'),
                                array(
                                    array('&&', "id=" . $vl)
                                )
                            );
                            $this->query->connect();
                            $getthis = $this->query->conn->Execute($sql); unset($sql);
                            $this->query->close();
                            if($getthis->_numOfRows > 0){
                                foreach($getthis->fields as $yk => $lv){
                                    if(eregi($key, $lv)){
                                        $result['data'][$cnt]['string'][$yk] = eregi_replace($key, '<strong>' . $key . '</strong>', $lv);
                                    }
                                }
                                if(!isset($result['data'][$cnt]['string']['nama'])){
                                    $result['data'][$cnt]['string']['nama'] = $getthis->fields['nama'];
                                }
                            } unset($getthis);
                            $getit->MoveNext();
                        }
                    } unset($getit);
                }
            }
        } unset($dump);
//        echo '<pre>'; print_r($result); echo '</pre>'; exit();
        return $result;
    }

    function _search(){
        return $this->__get_search();
    }

    function __get_search($teens=0){
        $result = array();
        $result['type'] = 'search';
        $result['title'] = __t('Cari data pasien treadmill');
        $result['description'] = __t('Mencari data pasien treadmill');
        $result['dataform']['character'] = array(
            '#type' => 'character'
        );
        $i = 0;
        foreach($this->config->abjad as $value){
            $result['dataform']['character']['data'][$i]['show'] = $value;
            $sql = $this->query->getSelect(
                array('treadmill|id as treadmill_id'),
                array('treadmill', 'patients'),
                array(
                    array('&&', "treadmill|patients=patients|id"),
                    array('&&', "patients|nama like '" . strtolower($value) . "%'"),
                    array('&&', "teens=" . ($teens == 0 ? 0 : $teens))
                )
            );
            $this->query->connect();
            $getit = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            $result['dataform']['character']['data'][$i]['links'] = $getit->_numOfRows > 0 ? '/user/treadmill' . ($teens == 0 ? '' : 'anak') . '/search/' . $value : NULL;
            unset($getit); $i++;
        } unset($i);
        $result['dataform']['form'] = array(
            '#type' => 'form',
            '#action' => '/user/treadmill' . ($teens == 0 ? '' : 'anak') . '/search',
            '#id' => 'treadmill_search',
            '#title' => __t('search'),
            'data' => array(
                '#type' => 'text',
                '#size' => 40
            ),
            'submit' => array(
                '#type' => 'submit',
                '#value' => __t('search')
            )
        );
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(isset($_POST['data']) || isset($dump[3])){
            $result['result'] = $this->__get_search_submit($teens);
        } unset($dump);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function view(){
        $this->sync_scheme('treadmill', $this->query);
        return $this->__get_view();
    }

    function __get_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('daftar beberapa pasien');
        $result['description'] = __t('daftar beberapa pasien terakhir yang telah diperiksa');
        $result['addmenu']['#add'] = array(
            'title' => __t('add'),
            'action' => '/user/treadmill/form',
            'position' => 'top',
            'user_required' => 'users'
        );
        $result['addmenu']['#search'] = array(
            'title' => __t('search'),
            'action' => '/user/treadmill/search',
            'position' => 'top',
            'user_required' => 'users'
        );
        $result['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => 'nama',
                'caption' => __t('nama'),
                'align' => 'left'
            ),
            array(
                'field' => 'tgl_lahir',
                'caption' => __t('usia'),
                'width' => '10%',
                'align' => 'right'
            ),
            array(
                'field' => 'inputtime',
                'caption' => __t('tgl periksa'),
                'width' => '25%',
                'align' => 'right'
            )
        );

        $sql = $this->query->getSelect(
            array(),
            array('treadmill'),
            NULL,
            'inputtime desc',
            '0,10'
        ); unset($where);
        $this->query->connect();
        $getit = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($getit->_numOfRows > 0){
            for($i=0; $i<$getit->_numOfRows; $i++){
                $sql = $this->query->getSelect(
                    array('id', 'nama', 'tgl_lahir', 'inputtime'),
                    array('patients'),
                    array(
                        array('&&', "id=" . $getit->fields['patients'])
                    )
                );
                $this->query->connect();
                $getthis = $this->query->conn->Execute($sql); unset($sql);
                $this->query->close();
                $result['data'][$i]['nama'] = $getthis->fields['nama'];
                $result['data'][$i]['tgl_lahir'] = number_format(round($this->agecount_in_month(strtotime($getthis->fields['tgl_lahir']))/12, 1), 1, ',','.') . ' th';
                $result['data'][$i]['goto'] = '/user/treadmill' . ($teens == 0 ? '' : 'anak') . '/detail_form/' . $getit->fields['id'];
                $result['data'][$i]['inputtime'] = date('j-n-Y H:i:s', strtotime($getit->fields['inputtime']));
                $getit->MoveNext();
            }
        }
        return $result;
    }

    function _detail_form(){
        return $this->__detail_form();
    }

    function __detail_form($teens=0){
        $this->formhabit = 'readonly';
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        $vcache = $this->__get_treadmill_data((int)$dump[3]);
        $this->vardump = $this->__write_custom_cache($vcache);
        $this->vardump['readonly'] = $this->formhabit;
        if($teens == 0){
            $result = $this->form();
        } else {
            $result = $this->anak_form();
        }
        return $result;
    }

    function __get_today_lists($teens=NULL){
        $result = array();
        $result = $this->today_patient_lists();
        if(count($result['data'])>0){
            foreach($result['data'] as $key => $value){
                if(!is_null($teens)){
                    if($value['age'] <= $this->config->teenlimit){
                        $result['data'][$key] = $value;
                    }
                } else {
                    if($value['age'] > $this->config->teenlimit){
                        $result['data'][$key] = $value;
                    }
                }
            }
        }
        return $result;
    }

    function __get_treadmill_data($id){
        $result = array();
        $sql = $this->query->getSelect(
            array(),
            array('treadmill'),
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

    function form(){
        return $this->__get_form();
    }

    function __get_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        } else {
            $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
            if(count($dump) > 3){
                if(preg_match('/^edit_/', $dump[3])){
                    $treadmill_id = preg_replace('/^edit_/','',$dump[3]);
                    $vcache = $this->__get_treadmill_data((int)$treadmill_id);
                    $this->vardump = $vcache;
                    unset($treadmill_id);
                } else {
                    $vcache['kunjungan'] = $dump[3]; unset($dump);
                }
            } else {
                redirect_to('/user/treadmill/today_treadmill_lists');
            } unset($dump);
        }
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('patients', 'inputer'),
            array('kunjungan'),
            array(
                array('&&', "id=" . $vcache['kunjungan'])
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        $pengirim = $query->fields['inputer'];
        if(!isset($vcache['patients'])){
            $vcache['patients'] = $query->fields['patients']; unset($query);
        }
        $form['treadmill'] = array(
            '#type' => 'special',
            '#id' => 'treadmill',
            '#title' => __t('treadmill'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/user/treadmill/form/' . ($this->formhabit == 'readonly' ? 'edit_' . $vcache['id'] : '/form_submit'),
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE,
            '#formtpl' => MODULES_DIR . DS . 'treadmill' . DS . 'treadmill.tpl',
        );
        $form['treadmill']['kunjungan'] = array(
            '#type' => 'hidden',
            '#value' => isset($vcache['kunjungan']) ? $vcache['kunjungan'] : ''
        );
        $thefields = $this->__get_data_fields('treadmill', $this->query);
        foreach($thefields as $value){
            if(in_array($value, $this->hidden_fields)){
                if($value == 'id'){
                    $form['treadmill'][$value] = array(
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
                    $form['treadmill'][$value] = array(
                        '#type' => 'hidden',
                        '#value' => $vcache['patients']
                    );
                    $query = $this->__get_patient_data(
                        $vcache['patients'],
                        array(
                            'strnum',
                            'nama',
                            'tgl_lahir',
                            'alamat',
                            'kota',
                            'propinsi',
                            'nomor',
                            'kelamin',
                            'gol_darah',
                            'tinggi',
                            'berat',
                            'tekanan_darah',
                            'indikasi'
                        )
                    );
                    if(count($query) > 0){
                        foreach($query as $ky => $vl){
                            if($ky == 'tgl_lahir'){
                                $vl = round(($this->agecount_in_month(strtotime($vl))/12),0);
                                $form['treadmill']['umur'] = array(
                                    '#type' => 'info',
                                    '#value' => $vl . ' tahun',
                                    '#title' => __t('umur'),
                                    '#tbpos' => 2
                                );
                                $usiapatient = floor($vl);
                            } else {
                                if($ky != 'kota' && $ky != 'propinsi'){
                                    if($ky == 'alamat'){
                                        $vl = $vl . ' ' . $query['kota'] . ' ' . $query['propinsi'];
                                        $tbpos = 3;
                                    } elseif($ky == 'strnum'){
                                        $ky = 'no_registrasi';
                                        $tbpos = 0;
                                    } elseif($ky == 'nama'){
                                        $tbpos = 1;
                                    } elseif($ky == 'kelamin'){
                                        $vl = $this->kelamin[$vl];
                                        $tbpos = 9;
                                    } elseif($ky == 'gol_darah'){
                                        $tbpos = 5;
                                    } elseif($ky == 'tinggi'){
                                        $tbpos = 10;
                                    } elseif ($ky == 'berat'){
                                        $tbpos = 11;
                                    } elseif ($ky == 'indikasi'){
                                        $tbpos = 4;
                                    } elseif ($ky == 'tekanan_darah'){
                                        $tbpos = 12;
                                    }
                                    $form['treadmill'][$ky] = array(
                                        '#type' => $ky == 'alamat' ? 'textarea' : 'info',
                                        '#value' => $vl,
                                        '#title' => __t($ky),
                                        '#tbpos' => $tbpos,
                                        '#readonly' => true
                                    );
                                    if($ky == 'alamat'){
                                        $form['treadmill'][$ky]['#extra'] = 'readonly="true"';
                                        $form['treadmill'][$ky]['#cols'] = '55';
                                        $form['treadmill'][$ky]['#rows'] = '3';
                                    } elseif($ky == 'no_registrasi'){
                                        $form['treadmill'][$ky]['#link'] = '/user/treadmill/today_patient_lists';
                                    }
                                    unset($tbpos);
                                }
                            }
                        }
                        $druser = $this->__get_user_info(1);
                        $sql = $this->query->getSelect(
                            array('nama'),
                            array('stafs'),
                            array(
                                array('&&', "id=" . $druser['id'])
                            )
                        ); unset($druser);
                        $this->query->connect();
                        $getstaf = $this->query->conn->Execute($sql); unset($sql);
                        $this->query->close();
                        $form['treadmill']['handleby'] = array(
                            '#type' => 'info',
                            '#value' => $getstaf->fields['nama'],
                            '#title' => __t('dr yg kerjakan'),
                            '#tbpos' => 13,
                            '#readonly' => true
                        ); unset($getstaf);
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
                        $form['treadmill']['kunjungan_ke'] = array(
                            '#type' => 'info',
                            '#value' => count($dumpfrek),
                            '#title' => __t('kunjungan_ke'),
                            '#tbpos' => 6,
                            '#readonly' => true
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
                        $form['treadmill']['pengirim'] = array(
                            '#type' => 'info',
                            '#value' => $getsender->fields['nama'],
                            '#title' => __t('pengirim'),
                            '#tbpos' => 5,
                            '#readonly' => true
                        );
                        unset($getsender);
                        $sql = $this->query->getSelect(
                            array(),
                            array('nadi_latihan'),
                            array(
                                array('&&', "umur=" . $usiapatient)
                            )
                        );
                        $this->query->connect();
                        $getthis = $this->query->conn->Execute($sql); unset($sql);
                        $this->query->close();
                        $form['treadmill']['denyut_jantung_max'] = array(
                            '#type' => 'info',
                            '#value' => $getthis->fields['nadi'],
                            '#title' => __t('denyut_jantung_max'),
                            '#tbpos' => 7,
                            '#readonly' => true
                        ); unset($getthis);
                        $sql = $this->query->getSelect(
                            array(),
                            array('thr'),
                            array(
                                array('&&', "umur=" . $usiapatient)
                            )
                        );
                        $this->query->connect();
                        $getthis = $this->query->conn->Execute($sql); unset($sql);
                        $this->query->close();
                        $form['treadmill']['target_denyut_jantung_max'] = array(
                            '#type' => 'info',
                            '#value' => $getthis->fields['nadi_85'],
                            '#title' => __t('target_denyut_jantung_max'),
                            '#tbpos' => 14,
                            '#readonly' => true
                        ); unset($getthis);
                    }
                }
                if($value != 'no_registrasi' && $value != 'kunjungan' && $value != 'patients'){
                    $form['treadmill'][$value] = array(
                        '#type' => $this->config->fields_form_type[$value],
                        '#value' => isset($vcache[$value]) ? $vcache[$value] : '',
                        '#size' => $this->config->fields_form_type[$value] != 'select' && $this->formtype_fields[$value] != 'date' ? 20 : 1,
                        '#title' => __t($value),
                        '#error' => isset($vcache['blank']) && in_array($value, $vcache['blank']) ? 1 : 0
                    );
                }
                if($this->formhabit == 'readonly'){
                    $form['treadmill'][$value]['#extra'] = 'readonly="true"';
                }
            }
        }
        if(!isset($vcache['inputtime']) || $vcache['inputtime'] == '0000-00-00 00:00:00' || is_null($vcache['inputtime'] || trim($vcache['inputtime']) == '')){
            $vcache['inputtime'] = date('Y-m-d H:i:s', $this->config->time);
        }
        $form['treadmill']['tanggal'] = array(
            '#type' => 'info',
            '#value' => date('j-n-Y', strtotime($vcache['inputtime'])),
            '#title' => __t('tanggal'),
            '#tbpos' => 8,
            '#readonly' => true
        );

        $form['treadmill']['tab_items']['istirahat'] = $this->__loadFaseIstirahat();
        $form['treadmill']['tab_items']['istirahatberdiri'] = $this->__loadFaseIstirahatBerdiri();
        $form['treadmill']['tab_items']['istirahathiperventilasi'] = $this->__loadFaseIstirahatHiperventilasi();
        $form['treadmill']['tab_items']['latihan'] = $this->__loadFaseLatihan();
        $form['treadmill']['tab_items']['recovery'] = $this->__loadFaseRecovery();
//        $form['treadmill']['tab_items']['kesimpulan'] = $this->__loadKesimpulan();

        $form['treadmill']['submit'] = array(
            '#type' => 'submit',
            '#value' => ($this->formhabit == 'readonly' ? __t('edit') : __t('submit'))
        );
        return $form;
    }

    function __loadFaseIstirahat($exec=NULL){
        $this->__include_module('istirahat');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->FaseIstirahat_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->istirahat_exec->treadmill_submit();
            }
        } else {
            return $this->istirahat_exec->treadmill_menu();
        }
    }

    function __loadFaseIstirahatBerdiri($exec=NULL){
        $this->__include_module('istirahatberdiri');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->FaseIstirahat_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->istirahatberdiri_exec->treadmill_submit();
            }
        } else {
            return $this->istirahatberdiri_exec->treadmill_menu();
        }
    }

    function __loadFaseIstirahatHiperventilasi($exec=NULL){
        $this->__include_module('istirahathiperventilasi');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->FaseIstirahat_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->istirahathiperventilasi_exec->treadmill_submit();
            }
        } else {
            return $this->istirahathiperventilasi_exec->treadmill_menu();
        }
    }

    function __loadFaseLatihan($exec=NULL){
        $this->__include_module('latihan');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->FaseLatihan_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->latihan_exec->treadmill_submit();
            }
        } else {
            return $this->latihan_exec->treadmill_menu();
        }
    }

    function __loadFaseRecovery($exec=NULL){
        $this->__include_module('recovery');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->FaseRecovery_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->recovery_exec->treadmill_submit();
            }
        } else {
//            echo "disini";
            return $this->recovery_exec->treadmill_menu();
        }
    }

    function __loadKesimpulan($exec=NULL){
        $this->__include_module('kesimpulan');
//        echo "disini";
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->kesimpulan_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->kesimpulan_exec->treadmill_submit();
            }
        } else {
//            echo "disini";
            return $this->kesimpulan_exec->treadmill_menu();
            
        }
    }

    function _form_submit(){
        return $this->__get_form_submit();
    }

    function __get_form_submit($teens=0){
        $this->vardump = $this->__write_form_cache();
        $sql = $this->query->getSelect(
            array(),
            array('kunjungan'),
            array(
                array('&&', "id=" . $_POST['kunjungan'])
            )
        );
        $this->query->connect();
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        $thevalue = array(
            'patients' => $query->fields['patients'],
            'tgl' => date('Y-m-d', strtotime($query->fields['pukul']))
        );
        unset($query);
        $thefields = $this->__get_data_fields('treadmill', $this->query);
        foreach($this->vardump as $key => $value){
            if(in_array($key, $thefields)){
                $thevalue[$key] = $value;
            }
        } unset($thefields);
        if($teens != 0 && $teens != '0'){
            $thevalue['teens'] = 1;
        }
        $user = $this->__get_user_info();
        if($_POST['id'] != ''){
            $thevalue['updated'] = $_COOKIE[$this->config->cookieid] . '|' . date('Y-m-d H:i:s', $this->config->time);
            $sql = $this->query->updateData(
                'treadmill',
                $thevalue,
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
        } else {
            $thevalue['id'] = $this->__get_id_insert_value('treadmill', 'id', $this->query);
            $thevalue['inputer'] = $user['userid'];
            $thevalue['inputtime'] = date('Y-m-d H:i:s', $this->config->time);
            $sql = $this->query->saveData(
                'treadmill',
                $thevalue
            );
            $this->vardump['id'] = $thevalue['id'];
        }
        $this->query->connect();
        $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        unset($thevalue);
        $this->__loadFaseIstirahat('submit');
        $this->__loadFaseIstirahatBerdiri('submit');
        $this->__loadFaseLatihan('submit');
        $this->__loadFaseRecovery('submit');
        $this->__loadKesimpulan('submit');
        if(!isset($_POST['id']) || is_null($_POST['id']) || $_POST['id'] == ''){
            $sql = $this->query->updateData(
                'kunjungan',
                array(
                    'doneby' => $_COOKIE[$this->config->cookieid]
                ),
                array(
                    array('&&', "id=" . $_POST['kunjungan'])
                )
            );
            $this->query->connect();
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/user/treadmill' . ($teens == 0 ? '' : 'anak') . '/view');
    }

}