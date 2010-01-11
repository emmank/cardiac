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
 *  kateterisasiclass.php
 *  
 *  Created on Oct 1, 2009, 1:12:45 PM
 */

require_once MODULES_DIR . DS . 'kateterisasi' . DS . 'config.inc';

class kateterisasiModule extends mainModule
{
    var $title = 'kateterisasi module';
    var $description = '';
    var $hidden_fields = array(
        'id', 'id_pasien', 'inputer','updated', 'inputtime','tgl'
    );

    function menu(){
        $items['kateterisasi_form'] = array(
            'title' => __t('form kateterisasi'),
            'description' => __t('formulir kateterisasi'),
            'path' => '/user/kateterisasi/form',
            'exec' => 'form',
            'weight' => '0',
            'user_required' => 'kateterisasi'
        );
        $items['kateterisasi_form_submit'] = array(
            'title' => __t('form kateterisasi'),
            'description' => __t('formulir kateterisasi'),
            'path' => '/user/kateterisasi/form_submit',
            'exec' => 'form_submit',
            'weight' => '0',
            'user_required' => 'kateterisasi'
        );
        $items['kateterisasi_get_lists'] = array(
            'title' => __t('form kateterisasi'),
            'description' => __t('formulir kateterisasi'),
            'path' => '/user/kateterisasi/today_kateterisasi_lists',
            'exec' => '__get_today_lists',
            'weight' => '0',
            'user_required' => 'kateterisasi'
        );
        $items['kateterisasi_lists'] = array(
            'title' => __t('Kateterisasi'),
            'description' => __t('explore kateterisasi'),
            'path' => '/user/kateterisasi/lists',
            'exec' => 'lists',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['kateterisasi_message'] = array(
            'title' => __t('kateterisasi message'),
            'description' => __t('get kateterisasi message'),
            'path' => '/user/kateterisasi/message',
            'exec' => 'message',
            'weight' => 5,
            'user_required' => 'kateterisasi'
        );
        $items['kateterisasi_message'] = array(
            'title' => __t('kateterisasi message'),
            'description' => __t('get kateterisasi message'),
            'path' => '/user/kateterisasi/message',
            'exec' => 'message',
            'weight' => 5,
            'user_required' => 'kateterisasi'
        );
        $items['kateterisasi_view'] = array(
            'title' => __t('kateterisasi'),
            'description' => __t('explore kateterisasi'),
            'path' => '/user/kateterisasi/view',
            'exec' => 'view',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['kateterisasi_detail'] = array(
            'title' => __t('detail kateterisasi'),
            'description' => __t("detail kateterisasi's patients"),
            'path' => '/user/kateterisasi/detail_form',
            'exec' => 'detail_form',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['kateterisasi_search'] = array(
            'title' => __t('search kateterisasi'),
            'description' => __t("search kateterisasi's patients"),
            'path' => '/user/kateterisasi/search',
            'exec' => 'search',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['kateterisasi_search_submit'] = array(
            'title' => __t('submitted search kateterisasi'),
            'description' => __t("submitted search kateterisasi's patients"),
            'path' => '/user/kateterisasi/search_submit',
            'exec' => 'search_submit',
            'weight' => '0',
            'user_required' => 'users'
        );
        return $items;
    }

    function search_submit(){
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
                        array('kateterisasi'),
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
                                $result['data'][$cnt]['links'] = '/user/kateterisasi/detail_form/' . $getit->fields['id'];
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
        $result = array();
        $result['type'] = 'search';
        $result['title'] = __t('Cari data pasien kateterisasi');
        $result['description'] = __t('Mencari data pasien kateterisasi');
        $result['dataform']['character'] = array(
            '#type' => 'character'
        );
        $i = 0;
        foreach($this->config->abjad as $value){
            $result['dataform']['character']['data'][$i]['show'] = $value;
            $sql = $this->query->getSelect(
                array('kateterisasi|id as kateterisasi_id'),
                array('kateterisasi', 'patients'),
                array(
                    array('&&', "kateterisasi|patients=patients|id"),
                    array('&&', "patients|nama like '" . strtolower($value) . "%'")
                )
            );
            $this->query->connect();
            $getit = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            $result['dataform']['character']['data'][$i]['links'] = $getit->_numOfRows > 0 ? '/user/kateterisasi/search/' . $value : NULL;
            unset($getit); $i++;
        } unset($i);
        $result['dataform']['form'] = array(
            '#type' => 'form',
            '#action' => '/user/kateterisasi/search',
            '#id' => 'kateterisasi_search',
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
            $result['result'] = $this->search_submit();
        } unset($dump);
        return $result;
    }

    function __get_today_lists(){
        $result = array();
        $result = $this->today_patient_lists();
        if(count($result['data'])>0){
            foreach($result['data'] as $key => $value){
                $result['data'][$key] = $value;
            }
        }
        return $result;
    }

    function __get_kateterisasi_data($id){
        $result = array();
        $sql = $this->query->getSelect(
            array(),
            array('kateterisasi'),
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

    function detail_form(){
        $this->formhabit = 'readonly';
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        $vcache = $this->__get_kateterisasi_data((int)$dump[3]);
        $this->vardump = $this->__write_custom_cache($vcache);
        $this->vardump['readonly'] = $this->formhabit;
        $result = $this->form();
        return $result;
    }

    function form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        } else {
            $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
            if(count($dump) > 3){
                if(preg_match('/^back_/', $dump[3])){
//                    $kateterisasi_id = preg_replace('/^edit_/','',$dump[3]);
//                    $vcache = $this->__get_kateterisasi_data((int)$kateterisasi_id);
//                    $this->vardump = $vcache;
//                    unset($cardio_id);
                    redirect_to('/user/kateterisasi/view');
                } else {
                    $vcache['kunjungan'] = $dump[3]; unset($dump);
                }
            } else {
                redirect_to('/user/kateterisasi/today_kateterisasi_lists');
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
        $form['kateterisasi'] = array(
            '#type' => 'special',
            '#id' => 'kateterisasi',
            '#title' => __t('kateterisasi'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/user/kateterisasi/' . ($this->formhabit == 'readonly' ? 'form/edit_' . $vcache['id'] : 'form_submit'),
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE,
            '#formtpl' => MODULES_DIR . DS . 'kateterisasi' . DS . 'kateterisasi.tpl',
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
        $form['kateterisasi']['kunjungan'] = array(
            '#type' => 'hidden',
            '#value' => isset($vcache['kunjungan']) ? $vcache['kunjungan'] : ''
        );
        $thefields = $this->__get_data_fields('kateterisasi', $this->query);
        foreach($thefields as $value){
            if(in_array($value, $this->hidden_fields)){
                if($value == 'id'){
                    $form['kateterisasi'][$value] = array(
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
                    $form['kateterisasi'][$value] = array(
                        '#type' => 'hidden',
                        '#value' => $vcache['patients']
                    );
                    $query = $this->__get_patient_data($vcache['patients'], array('nama', 'tgl_lahir', 'alamat', 'kota', 'propinsi', 'nomor', 'kelamin', 'gol_darah','strnum'));
                    if(count($query) > 0){
                        foreach($query as $ky => $vl){
                            if($ky == 'tgl_lahir'){
//                                $vl = $this->agecount_in_month(strtotime($vl));
//                                $vl = round(($this->agecount_in_month(strtotime($vl))/12),0);
//                                $form['kateterisasi']['umur'] = array(
//                                    '#type' => 'info',
//                                    '#value' => $vl . ' tahun',
//                                    '#title' => __t('umur'),
//                                    '#tbpos' => 3
//                                );
                            } else {
                                if($ky != 'kota' && $ky != 'propinsi' && $ky != 'strnum'){
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
                                    $form['kateterisasi'][$ky] = array(
                                        '#type' => $ky == 'alamat' ? 'textarea' : 'info',
                                        '#value' => $vl,
                                        '#title' => __t($ky),
                                        '#tbpos' => $tbpos
                                    );
                                    if($ky == 'alamat'){
                                        $form['kateterisasi'][$ky]['#extra'] = 'readonly="true"';
                                        $form['kateterisasi'][$ky]['#cols'] = '55';
                                        $form['kateterisasi'][$ky]['#rows'] = '3';
                                    } elseif($ky == 'no_registrasi'){
                                        $form['kateterisasi'][$ky]['#link'] = '/user/kateterisasi/today_patient_lists';
                                        $form['kateterisasi'][$ky]['#value'] = $query['strnum'];
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
                        $form['kateterisasi']['kunjungan_ke'] = array(
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
                        $form['kateterisasi']['pengirim'] = array(
                            '#type' => 'info',
                            '#value' => $getsender->fields['nama'],
                            '#title' => __t('pengirim'),
                            '#tbpos' => 7
                        );
                        unset($getsender);
                    }
                }
                if($value != 'no_registrasi' && $value != 'kunjungan' && $value != 'patients'){
                    $form['kateterisasi'][$value] = array(
                        '#type' => $this->config->fields_form_type[$value],
                        '#value' => isset($vcache[$value]) ? $vcache[$value] : '',
                        '#size' => $this->config->fields_form_type[$value] != 'select' && $this->config->fields_form_type[$value] != 'date' ? 20 : 1,
                        '#title' => __t($value),
                        '#error' => isset($vcache['blank']) && in_array($value, $vcache['blank']) ? 1 : 0
                    );
                    if(in_array($value, $this->config->fieldsisarray)){
                        $form['kateterisasi'][$value]['#theref'] = $this->__get_refs($value);
                    }
                    if(in_array($value, $this->config->qrs_complex) || in_array($value, $this->config->segment_st) || $value == 'gelombang_t'){
                        $form['kateterisasi'][$value]['#customized']['title'] = in_array($value, $this->config->qrs_complex) ? __t('qrs_complex') : ($value == 'gelombang_t' ? __t('gelombang_t') : __t('segment_st'));
                        $form['kateterisasi'][$value]['#customized']['id'] = in_array($value, $this->config->qrs_complex) ? 'qrs_complex' : ($value == 'gelombang_t' ? 'gelombang_t' : 'segment_st');
                        if($this->config->fields_form_type[$value] == 'select2'){
                            $form['kateterisasi'][$value]['#customized']['option'] =  array(
                                '1mm - 2mm' => '1mm - 2mm',
                                '> 2mm - 3mm' => '> 2mm - 3mm',
                                '> 3mm' => '> 3mm'
                            );
                        } elseif ($this->config->fields_form_type[$value] == 'select3') {
                            $form['kateterisasi'][$value]['#customized']['option'] =  array(
                                'Q Patologi +' => 'Q Patologi +',
                                'Q Patologi -' => 'Q Patologi -'
                            );
                        } elseif ($value == 'gelombang_t') {
                            $form['kateterisasi'][$value]['#customized']['option'] =  array(
                                'Normal' => 'Normal',
                                'Inverted' => 'Inverted'
                            );
                        }
                    }
                }
                if($this->formhabit == 'readonly'){
                    $form['kateterisasi'][$value]['#readonly'] = TRUE;
                }
            }
        }

        $form['kateterisasi']['submit'] = array(
            '#type' => 'submit',
            '#value' => ($this->formhabit == 'readonly' ? __t('back') : __t('submit'))
        );
//        echo "<pre>";print_r($form);echo "</pre>";
        return $form;
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

    
    function form_submit(){
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
        $thefields = $this->__get_data_fields('kateterisasi', $this->query);
        foreach($this->vardump as $key => $value){
            if(in_array($key, $thefields)){
                if (is_array($value)){
                    ksort($value);
                    $thevalue[$key] = implode('|', $value);
                } else {
                    $thevalue[$key] = $value;
                }
            }
        } unset($thefields);
//        echo "<pre>";print_r($thevalue);echo "</pre>";
        $user = $this->__get_user_info();
        if($_POST['id'] != ''){
            $thevalue['updated'] = $user['userid'] . '|' . date('Y-m-d H:i:s', $this->config->time);
            $opr = 'update';
            $strid = array('id', $_POST['id']);
        } else {
            $thevalue['id'] = $this->__get_id_insert_value('kateterisasi', 'id', $this->query);
            $thevalue['inputer'] = $user['id'];
            $thevalue['inputtime'] = date('Y-m-d H:i:s', $this->config->time);
            $this->vardump['id'] = $thevalue['id'];
            $opr = 'insert';
            $strid = array('id', $thevalue['id']);
        }
//        echo $opr;
//        echo "<pre>";print_r($strid);echo "</pre>";
        $this->__exec_db_ops(
            $this->query,
            'kateterisasi',
            $opr,
            $strid,
            $thevalue
        );
        unset($thevalue, $opr, $strid);
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
        
        $this->__flush_caches();
        redirect_to('/user/kateterisasi/view');
    }

    function view(){
        return $this->__get_today_lists();
    }

    function lists(){
//        $this->sync_scheme('kateterisasi', $this->query);
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('daftar beberapa pasien');
        $result['description'] = __t('daftar beberapa pasien terakhir yang telah diperiksa');
        $result['addmenu']['#add'] = array(
            'title' => __t('add'),
            'action' => '/user/kateterisasi/form',
            'position' => 'top',
            'user_required' => 'users'
        );
        $result['addmenu']['#search'] = array(
            'title' => __t('search'),
            'action' => '/user/kateterisasi/search',
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
            array('kateterisasi'),
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
                $result['data'][$i]['goto'] = '/user/kateterisasi/detail_form/' . $getit->fields['id'];
                $result['data'][$i]['inputtime'] = date('j-n-Y H:i:s', strtotime($getit->fields['inputtime']));
                $getit->MoveNext();
            }
        }
        return $result;
    }
}