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
 *  Created on Oct 1, 2009, 1:12:45 PM
 */

require_once MODULES_DIR . DS . 'vascular' . DS . 'config.inc';

class vascularModule extends mainModule
{
    var $title = 'vascular';
    var $description = 'Manajemen data digital pasien vascular';
    var $hidden_fields = array(
        'id', 'teens', 'inputer','updated', 'inputtime'
    );

    function menu(){
        $items['vascular_form'] = array(
            'title' => __t('form vascular'),
            'description' => __t('formulir vascular'),
            'path' => '/user/vascular/form',
            'exec' => 'form',
            'weight' => '0',
            'user_required' => 'vascular'
        );
        $items['vascular_form_submit'] = array(
            'title' => __t('form vascular'),
            'description' => __t('formulir vascular'),
            'path' => '/user/vascular/form_submit',
            'exec' => 'form_submit',
            'weight' => '0',
            'user_required' => 'vascular'
        );
        $items['vascular_get_lists'] = array(
            'title' => __t('list antrian vascular'),
            'description' => __t('formulir vascular'),
            'path' => '/user/vascular/today_vascular_lists',
            'exec' => '__get_today_lists',
            'weight' => '0',
            'user_required' => 'vascular'
        );
        $items['vascular_message'] = array(
            'title' => __t('vascularmessage'),
            'description' => __t('get vascularmessage'),
            'path' => '/user/vascular/message',
            'exec' => 'message',
            'weight' => 5,
            'user_required' => 'vascular'
        );
        $items['vascular_view'] = array(
            'title' => __t('Vascular Echo-doppler'),
            'description' => __t('explore vascular'),
            'path' => '/user/vascular/view',
            'exec' => 'view',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['vascular_detail'] = array(
            'title' => __t('detail vascular'),
            'description' => __t("detail vascular's patients"),
            'path' => '/user/vascular/detail_form',
            'exec' => 'detail_form',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['vascular_search'] = array(
            'title' => __t('search vascular'),
            'description' => __t("search vascular's patients"),
            'path' => '/user/vascular/search',
            'exec' => 'search',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['vascular_search_submit'] = array(
            'title' => __t('submitted search vascular'),
            'description' => __t("submitted search vascular's patients"),
            'path' => '/user/vascular/search_submit',
            'exec' => 'search_submit',
            'weight' => '0',
            'user_required' => 'users'
        );
        return $items;
    }

    function search_submit(){
        return $this->__get_search_submit();
    }

    function __get_search_submit(){
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
                        array('vascular'),
                        array(
                            array('&&', "patients=" . $vl)
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
                                $result['data'][$cnt]['links'] = '/user/vascular/detail_form/' . $getit->fields['id'];
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
        return $result;
    }

    function search(){
        return $this->__get_search();
    }

    function __get_search(){
        $result = array();
        $result['type'] = 'search';
        $result['title'] = __t('Cari data pasien vascular');
        $result['description'] = __t('Mencari data pasien vascular');
        $result['dataform']['character'] = array(
            '#type' => 'character'
        );
        $i = 0;
        foreach($this->config->abjad as $value){
            $result['dataform']['character']['data'][$i]['show'] = $value;
            $sql = $this->query->getSelect(
                array('vascular|id as vascular_id'),
                array('vascular', 'patients'),
                array(
                    array('&&', "vascular|patients=patients|id"),
                    array('&&', "patients|nama like '" . strtolower($value) . "%'")
                )
            );
            $this->query->connect();
            $getit = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            $result['dataform']['character']['data'][$i]['links'] = $getit->_numOfRows > 0 ? '/user/vascular/search/' . $value : NULL;
            unset($getit); $i++;
        } unset($i);
        $result['dataform']['form'] = array(
            '#type' => 'form',
            '#action' => '/user/vascular/search',
            '#id' => 'vascular_search',
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
        return $result;
    }

    function view(){
        $this->sync_scheme('vascular', $this->query);
        return $this->__get_view();
    }

    function __get_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('daftar beberapa pasien');
        $result['description'] = __t('daftar beberapa pasien terakhir yang telah diperiksa');
        $result['addmenu']['#add'] = array(
            'title' => __t('add'),
            'action' => '/user/vascular/form',
            'position' => 'top',
            'user_required' => 'users'
        );
        $result['addmenu']['#search'] = array(
            'title' => __t('search'),
            'action' => '/user/vascular/search',
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
            array('vascular'),
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
                $result['data'][$i]['goto'] = '/user/vascular/detail_form/' . $getit->fields['id'];
                $result['data'][$i]['inputtime'] = date('j-n-Y H:i:s', strtotime($getit->fields['inputtime']));
                $getit->MoveNext();
            }
        }
        return $result;
    }

    function detail_form(){
        return $this->__detail_form();
    }

    function __detail_form(){
        $this->formhabit = 'readonly';
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        $vcache = $this->__get_vascular_data((int)$dump[3]);
        $this->vardump = $this->__write_custom_cache($vcache);
        $this->vardump['readonly'] = $this->formhabit;
        $result = $this->form();
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

    function __get_vascular_data($id){
        $result = array();
        $sql = $this->query->getSelect(
            array(),
            array('vascular'),
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
                    $vascular_id = preg_replace('/^edit_/','',$dump[3]);
                    $vcache = $this->__get_vascular_data((int)$vascular_id);
                    $this->vardump = $vcache;
                    unset($vascular_id);
                } else {
                    $vcache['kunjungan'] = $dump[3]; unset($dump);
                }
            } else {
                redirect_to('/user/vascular/today_vascular_lists');
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
        $addmenuopts = array(
            '' => __t('-- medical record --'),
            'all' => __t('semua')
        );
        $dump_addmenus = $this->__get_bagian_lists();
        foreach($dump_addmenus as $key => $value){
            $sql = $this->query->getSelect(
                array('id'),
                array('kunjungan'),
                array(
                    array('&&', "patients=" . $vcache['patients']),
                    array('&&', "bagian=" . $value),
                    array('&&', "doneby is not null")
                )
            );
            $this->query->connect();
            $getit = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            if($getit->_numOfRows > 0){
                $addmenuopts[$key] = $value;
            } unset($getit);
        } unset($dump_addmenus);
        $form['vascular'] = array(
            '#type' => 'special',
            '#id' => 'vascular',
            '#title' => __t('vascular'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/user/vascular/form' . ($this->formhabit == 'readonly' ? '/edit_' . $vcache['id'] : '_submit'),
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE,
            '#formtpl' => MODULES_DIR . DS . 'vascular' . DS . 'vascular.tpl',
            '#addmenu' => array(
                'title' => __t('medical record'),
                'action' => '/user/patient/medical_record/' . $vcache['patients'],
                'position' => 'top',
                'class' => 'button',
                'methode' => 'choose',
                'options' => $addmenuopts,
                'filter' => 'bagian'
            )
        ); unset($addmenuopts);
        $form['vascular']['kunjungan'] = array(
            '#type' => 'hidden',
            '#value' => isset($vcache['kunjungan']) ? $vcache['kunjungan'] : ''
        );
        $thefields = $this->__get_data_fields('vascular', $this->query);
        foreach($thefields as $value){
            if(in_array($value, $this->hidden_fields)){
                if($value == 'id'){
                    $form['vascular'][$value] = array(
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
                    $form['vascular'][$value] = array(
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
                                $form['vascular']['umur'] = array(
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
                                    $form['vascular'][$ky] = array(
                                        '#type' => $ky == 'alamat' ? 'textarea' : 'info',
                                        '#value' => $vl,
                                        '#title' => __t($ky),
                                        '#tbpos' => $tbpos,
                                        '#readonly' => true
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
                        $form['vascular']['handleby'] = array(
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
                        $form['vascular']['kunjungan_ke'] = array(
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
                        $form['vascular']['pengirim'] = array(
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
                        $form['vascular']['denyut_jantung_max'] = array(
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
                        $form['vascular']['target_denyut_jantung_max'] = array(
                            '#type' => 'info',
                            '#value' => $getthis->fields['nadi_85'],
                            '#title' => __t('target_denyut_jantung_max'),
                            '#tbpos' => 14,
                            '#readonly' => true
                        ); unset($getthis);
                    }
                }
                if($value != 'no_registrasi' && $value != 'kunjungan' && $value != 'patients'){
                    $form['vascular'][$value] = array(
                        '#type' => $this->config->fields_form_type[$value],
                        '#value' => isset($vcache[$value]) ? $vcache[$value] : '',
                        '#size' => $this->config->fields_form_type[$value] != 'select' && $this->formtype_fields[$value] != 'date' ? 20 : 1,
                        '#title' => __t($value),
                        '#error' => isset($vcache['blank']) && in_array($value, $vcache['blank']) ? 1 : 0
                    );
                }
                if($this->formhabit == 'readonly'){
                    $form['vascular'][$value]['#extra'] = 'readonly="true"';
                }
            }
        }
        if(!isset($vcache['inputtime']) || $vcache['inputtime'] == '0000-00-00 00:00:00' || is_null($vcache['inputtime'] || trim($vcache['inputtime']) == '')){
            $vcache['inputtime'] = date('Y-m-d H:i:s', $this->config->time);
        }
        $form['vascular']['tanggal'] = array(
            '#type' => 'info',
            '#value' => date('j-n-Y', strtotime($vcache['inputtime'])),
            '#title' => __t('tanggal'),
            '#tbpos' => 8,
            '#readonly' => true
        );

        $form['vascular']['tab_items']['carotis'] = $this->__loadCarotis();
        $form['vascular']['tab_items']['superior'] = $this->__loadSuperior();
        $form['vascular']['tab_items']['inferior'] = $this->__loadInferior();
        $form['vascular']['tab_items']['vascabdomen'] = $this->__loadAbdomen();
//        $form['vascular']['tab_items']['recovery'] = $this->__loadFaseRecovery();
//        $form['vascular']['tab_items']['kesimpulan'] = $this->__loadKesimpulan();

        $form['vascular']['submit'] = array(
            '#type' => 'submit',
            '#value' => ($this->formhabit == 'readonly' ? __t('edit') : __t('submit'))
        );
        return $form;
    }

    function __loadCarotis($exec=NULL){
        $this->__include_module('carotis');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->carotis_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->carotis_exec->vascular_submit();
            }
        } else {
            return $this->carotis_exec->vascular_menu();
        }
    }

    function __loadSuperior($exec=NULL){
        $this->__include_module('superior');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->superior_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->superior_exec->vascular_submit();
            }
        } else {
            return $this->superior_exec->vascular_menu();
        }
    }

    function __loadInferior($exec=NULL){
        $this->__include_module('inferior');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->inferior_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->inferior_exec->vascular_submit();
            }
        } else {
            return $this->inferior_exec->vascular_menu();
        }
    }

    function __loadAbdomen($exec=NULL){
        $this->__include_module('vascabdomen');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->vascabdomen_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->vascabdomen_exec->vascular_submit();
            }
        } else {
            return $this->vascabdomen_exec->vascular_menu();
        }
    }

    function __loadFaseRecovery($exec=NULL){
        $this->__include_module('recovery');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->FaseRecovery_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->recovery_exec->vascular_submit();
            }
        } else {
            return $this->recovery_exec->vascular_menu();
        }
    }

    function __loadKesimpulan($exec=NULL){
        $this->__include_module('kesimpulan');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->kesimpulan_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->kesimpulan_exec->vascular_submit();
            }
        } else {
            return $this->kesimpulan_exec->vascular_menu();
            
        }
    }

    function form_submit(){
        return $this->__get_form_submit();
    }

    function __get_form_submit(){
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
        $thefields = $this->__get_data_fields('vascular', $this->query);
        foreach($this->vardump as $key => $value){
            if(in_array($key, $thefields)){
                $thevalue[$key] = $value;
            }
        } unset($thefields);
        $user = $this->__get_user_info();
        if($_POST['id'] != ''){
            $thevalue['updated'] = $_COOKIE[$this->config->cookieid] . '|' . date('Y-m-d H:i:s', $this->config->time);
            $opr = 'update';
            $strid = array('id', $_POST['id']);
        } else {
            $thevalue['id'] = $this->__get_id_insert_value('vascular', 'id', $this->query);
            $thevalue['inputer'] = $user['userid'];
            $thevalue['inputtime'] = date('Y-m-d H:i:s', $this->config->time);
            $this->vardump['id'] = $thevalue['id'];
            $opr = 'insert';
            $strid = array('id', $thevalue['id']);
        }
        $this->__exec_db_ops(
            $this->query,
            'vascular',
            $opr,
            $strid,
            $thevalue
        );
        unset($thevalue, $opr, $strid);
        $this->__loadCarotis('submit');
        $this->__loadSuperior('submit');
        $this->__loadInferior('submit');
        $this->__loadAbdomen('submit');
//        $this->__loadFaseRecovery('submit');
//        $this->__loadKesimpulan('submit');
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
        redirect_to('/user/vascular/view');
    }

}