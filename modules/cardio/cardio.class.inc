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
 *  cardioclass.php
 *  
 *  Created on Oct 1, 2009, 1:12:45 PM
 */

require_once MODULES_DIR . DS . 'cardio' . DS . 'config.inc';

class cardioModule extends mainModule
{
    var $title = 'cardio';
    var $description = 'Manajemen data digital pasien cardiologi';
    var $hidden_fields = array(
        'id', 'teens', 'inputer','updated', 'inputtime'
    );

    function menu(){
        $items['cardio_dewasa_form'] = array(
            'title' => __t('form cardio dewasa'),
            'description' => __t('formulir cardio dewasa'),
            'path' => '/user/cardio_dewasa/form',
            'exec' => 'dewasa_form',
            'weight' => '0',
            'user_required' => 'kardio dewasa'
        );
        $items['cardio_anak_form'] = array(
            'title' => __t('form cardio anak'),
            'description' => __t('formulir cardio anak'),
            'path' => '/user/cardio_anak/form',
            'exec' => 'anak_form',
            'weight' => '0',
            'user_required' => 'kardio anak'
        );
        $items['cardio_dewasa_form_submit'] = array(
            'title' => __t('form cardio dewasa'),
            'description' => __t('formulir cardio dewasa'),
            'path' => '/user/cardio_dewasa/form_submit',
            'exec' => 'dewasa_form_submit',
            'weight' => '0',
            'user_required' => 'kardio dewasa'
        );
        $items['cardio_anak_form_submit'] = array(
            'title' => __t('form cardio anak'),
            'description' => __t('formulir cardio anak'),
            'path' => '/user/cardio_anak/form_submit',
            'exec' => 'anak_form_submit',
            'weight' => '0',
            'user_required' => 'kardio anak'
        );
        $items['cardio_anak_get_lists'] = array(
            'title' => __t('list antrian cardio anak'),
            'description' => __t('list antrian cardio anak'),
            'path' => '/user/cardio_anak/today_cardio_lists',
            'exec' => '__get_today_lists',
            'weight' => '0',
            'user_required' => 'kardio anak'
        );
        $items['cardio_dewasa_get_lists'] = array(
            'title' => __t('list antrian cardio dewasa'),
            'description' => __t('formulir cardio dewasa'),
            'path' => '/user/cardio_dewasa/today_cardio_lists',
            'exec' => '__get_today_lists',
            'weight' => '0',
            'user_required' => 'kardio dewasa'
        );
        $items['cardio_dewasa_message'] = array(
            'title' => __t('cardio message'),
            'description' => __t('get cardio message'),
            'path' => '/user/cardio_dewasa/message',
            'exec' => 'message',
            'weight' => 5,
            'user_required' => 'kardio dewasa'
        );
        $items['cardio_anak_view'] = array(
            'title' => __t('cardio anak'),
            'description' => __t('explore cardio anak'),
            'path' => '/user/cardio_anak/view',
            'exec' => 'anak_view',
            'weight' => 5,
            'user_required' => 'users'
        );
        $items['cardio_dewasa_view'] = array(
            'title' => __t('cardio dewasa'),
            'description' => __t('explore cardio dewasa'),
            'path' => '/user/cardio_dewasa/view',
            'exec' => 'dewasa_view',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['cardio_anak_detail'] = array(
            'title' => __t('detail cardio anak'),
            'description' => __t("detail cardio anak's patients"),
            'path' => '/user/cardio_anak/detail_form',
            'exec' => 'anak_detail_form',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['cardio_dewasa_detail'] = array(
            'title' => __t('detail cardio dewasa'),
            'description' => __t("detail cardio dewasa's patients"),
            'path' => '/user/cardio_dewasa/detail_form',
            'exec' => 'dewasa_detail_form',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['cardio_dewasa_search'] = array(
            'title' => __t('search cardio dewasa'),
            'description' => __t("search cardio dewasa's patients"),
            'path' => '/user/cardio_dewasa/search',
            'exec' => 'dewasa_search',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['cardio_anak_search'] = array(
            'title' => __t('search cardio anak'),
            'description' => __t("search cardio anak's patients"),
            'path' => '/user/cardio_anak/search',
            'exec' => 'anak_search',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['cardio_dewasa_search_submit'] = array(
            'title' => __t('submitted search cardio dewasa'),
            'description' => __t("submitted search cardio dewasa's patients"),
            'path' => '/user/cardio_dewasa/search_submit',
            'exec' => 'dewasa_search_submit',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['cardio_anak_search_submit'] = array(
            'title' => __t('submitted search cardio anak'),
            'description' => __t("submitted search cardio anak's patients"),
            'path' => '/user/cardio_anak/search_submit',
            'exec' => 'anak_search_submit',
            'weight' => '0',
            'user_required' => 'users'
        );
        return $items;
    }

    function dewasa_search_submit(){
        return $this->__get_search_submit();
    }

    function anak_search_submit(){
        return $this->__get_search_submit(1);
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
                        array('cardio'),
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
                                $result['data'][$cnt]['links'] = '/user/cardio_' . ($teens != 0 ? 'anak' : 'dewasa') . '/detail_form/' . $getit->fields['id'];
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

    function dewasa_search(){
        return $this->__get_search();
    }

    function anak_search(){
        return $this->__get_search(1);
    }

    function __get_search($teens=0){
        $result = array();
        $result['type'] = 'search';
        $result['title'] = __t('Cari data pasien cardio');
        $result['description'] = __t('Mencari data pasien cardio');
        $result['dataform']['character'] = array(
            '#type' => 'character'
        );
        $i = 0;
        foreach($this->config->abjad as $value){
            $result['dataform']['character']['data'][$i]['show'] = $value;
            $sql = $this->query->getSelect(
                array('cardio|id as cardio_id'),
                array('cardio', 'patients'),
                array(
                    array('&&', "cardio|patients=patients|id"),
                    array('&&', "patients|nama like '" . strtolower($value) . "%'"),
                    array('&&', "teens=" . ($teens == 0 ? 0 : $teens))
                )
            );
            $this->query->connect();
            $getit = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            $result['dataform']['character']['data'][$i]['links'] = $getit->_numOfRows > 0 ? '/user/cardio_' . ($teens == 0 ? 'dewasa' : 'anak') . '/search/' . $value : NULL;
            unset($getit); $i++;
        } unset($i);
        $result['dataform']['form'] = array(
            '#type' => 'form',
            '#action' => '/user/cardio_' . ($teens == 0 ? 'dewasa' : 'anak') . '/search',
            '#id' => 'cardio_search',
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

    function dewasa_view(){
        return $this->__get_view();
    }

    function anak_view(){
        return $this->__get_view(1);
    }

    function __get_view($teens=0){
        $this->sync_scheme('cardio', $this->query);
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('daftar beberapa pasien');
        $result['description'] = __t('daftar beberapa pasien terakhir yang telah diperiksa');
        $result['addmenu']['#add'] = array(
            'title' => __t('add'),
            'action' => '/user/cardio_' . ($teens == 0 ? 'dewasa' : 'anak') . '/form',
            'position' => 'top',
            'user_required' => 'users'
        );
        $result['addmenu']['#search'] = array(
            'title' => __t('search'),
            'action' => '/user/cardio_' . ($teens == 0 ? 'dewasa' : 'anak') . '/search',
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
            array('cardio'),
            array(
                array('&&', "teens=" . ($teens != 0 ? $teens : 0))
            ),
            'inputtime desc',
            '0,10'
        ); unset($where);
        $this->query->connect();
//        $this->query->conn->debug=true;
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
                $result['data'][$i]['goto'] = '/user/cardio_' . ($teens == 0 ? 'dewasa' : 'anak') . '/detail_form/' . $getit->fields['id'];
                $result['data'][$i]['inputtime'] = date('j-n-Y H:i:s', strtotime($getit->fields['inputtime']));
                $getit->MoveNext();
            }
        }
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function dewasa_detail_form(){
        return $this->__detail_form();
    }

    function anak_detail_form(){
        return $this->__detail_form(1);
    }

    function __detail_form($teens=0){
        $this->formhabit = 'readonly';
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        $vcache = $this->__get_cardio_data((int)$dump[3]);
        $this->vardump = $this->__write_custom_cache($vcache);
        $this->vardump['readonly'] = $this->formhabit;
        if($teens == 0){
            $result = $this->dewasa_form();
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

    function __get_cardio_data($id){
        $result = array();
        $sql = $this->query->getSelect(
            array(),
            array('cardio'),
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

    function dewasa_form(){
        return $this->__get_form();
    }

    function anak_form(){
        return $this->__get_form(1);
    }

    function __get_form($teens=0){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        } else {
            $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
            if(count($dump) > 3){
                if(preg_match('/^edit_/', $dump[3])){
                    $cardio_id = preg_replace('/^edit_/','',$dump[3]);
                    $vcache = $this->__get_cardio_data((int)$cardio_id);
                    $this->vardump = $vcache;
                    unset($cardio_id);
                } else {
                    $vcache['kunjungan'] = $dump[3]; unset($dump);
                }
            } else {
                redirect_to('/user/cardio_' . ($teens == 0 ? 'dewasa' : 'anak') . '/today_cardio_lists');
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
        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')] = array(
            '#type' => 'special',
            '#id' => 'cardio_' . ($teens == 0 ? 'dewasa' : 'anak'),
            '#title' => __t('Kardio ' . ($teens == 0 ? 'dewasa' : 'anak')),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/user/cardio_' . ($teens == 0 ? 'dewasa' : 'anak') . '/form' . ($this->formhabit == 'readonly' ? '/edit_' . $vcache['id'] : '_submit'),
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE,
            '#formtpl' => MODULES_DIR . DS . 'cardio' . DS . 'cardio.tpl',
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
        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['kunjungan'] = array(
            '#type' => 'hidden',
            '#value' => isset($vcache['kunjungan']) ? $vcache['kunjungan'] : ''
        );
        $thefields = $this->__get_data_fields('cardio', $this->query);
        foreach($thefields as $value){
            if(in_array($value, $this->hidden_fields)){
                if($value == 'id'){
                    $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')][$value] = array(
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
                    $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')][$value] = array(
                        '#type' => 'hidden',
                        '#value' => $vcache['patients']
                    );
                    $query = $this->__get_patient_data($vcache['patients'], array('nama', 'tgl_lahir', 'alamat', 'kota', 'propinsi', 'nomor', 'kelamin', 'gol_darah'));
                    if(count($query) > 0){
                        foreach($query as $ky => $vl){
                            if($ky == 'tgl_lahir'){
                                $vl = round(($this->agecount_in_month(strtotime($vl))/12),0);
                                $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['umur'] = array(
                                    '#type' => 'info',
                                    '#value' => $vl . ' tahun',
                                    '#title' => __t('umur'),
                                    '#tbpos' => 3
                                );
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
                                    $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')][$ky] = array(
                                        '#type' => $ky == 'alamat' ? 'textarea' : 'info',
                                        '#value' => $vl,
                                        '#title' => __t($ky),
                                        '#tbpos' => $tbpos
                                    );
                                    if($ky == 'alamat'){
                                        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')][$ky]['#extra'] = 'readonly="true"';
                                        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')][$ky]['#cols'] = '55';
                                        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')][$ky]['#rows'] = '3';
                                    } elseif($ky == 'no_registrasi'){
                                        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')][$ky]['#link'] = '/user/cardio_' . ($teens == 0 ? 'dewasa' : 'anak') . '/today_patient_lists';
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
                        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['kunjungan_ke'] = array(
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
                        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['pengirim'] = array(
                            '#type' => 'info',
                            '#value' => $getsender->fields['nama'],
                            '#title' => __t('pengirim'),
                            '#tbpos' => 7
                        );
                        unset($getsender);
                    }
//                    $this->query->close();
                }
                if($value != 'no_registrasi' && $value != 'kunjungan' && $value != 'patients'){
                    $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')][$value] = array(
                        '#type' => $this->config->fields_form_type[$value],
                        '#value' => isset($vcache[$value]) ? $vcache[$value] : '',
                        '#size' => $this->config->fields_form_type[$value] != 'select' && $this->formtype_fields[$value] != 'date' ? 20 : 1,
                        '#title' => __t($value),
                        '#error' => isset($vcache['blank']) && in_array($value, $vcache['blank']) ? 1 : 0
                    );
                }
                if($this->formhabit == 'readonly'){
                    $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')][$value]['#extra'] = 'readonly="true"';
                }
            }
        }

        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['tab_items']['presentStatus'] = $this->__loadPresentStatus();
        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['tab_items']['vitalSign'] = $this->__loadVitalSign();
        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['tab_items']['eye'] = $this->__loadEye();
//        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['tab_items']['ear'] = $this->__loadEar();
        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['tab_items']['nose'] = $this->__loadNose();
        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['tab_items']['headface'] = $this->__loadHeadFace();
        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['tab_items']['neck'] = $this->__loadNeck();
        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['tab_items']['mouth'] = $this->__loadMouth();
        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['tab_items']['space'] = "";
        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['tab_items']['thorax'] = $this->__loadThorax();
        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['tab_items']['paru'] = $this->__loadParu();
        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['tab_items']['hearth'] = $this->__loadHearth();
        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['tab_items']['abdomen'] = $this->__loadAbdomen();
        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['tab_items']['anusrectum'] = $this->__loadAnusrectum();
        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['tab_items']['punggung'] = $this->__loadPunggung();
        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['tab_items']['extermitas'] = $this->__loadExtermitas();

        $form['cardio_' . ($teens == 0 ? 'dewasa' : 'anak')]['submit'] = array(
            '#type' => 'submit',
            '#value' => ($this->formhabit == 'readonly' ? __t('edit') : __t('submit'))
        );
        return $form;
    }

    function __loadHearth($exec=NULL){
        $this->__include_module('hearth');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->hearth_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->hearth_exec->cardio_submit();
            }
        } else {
            return $this->hearth_exec->cardio_menu();
        }
    }

    function __loadAbdomen($exec=NULL){
        $this->__include_module('abdomen');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->abdomen_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->abdomen_exec->cardio_submit();
            }
        } else {
            return $this->abdomen_exec->cardio_menu();
        }
    }
    
    function __loadAnusrectum($exec=NULL){
        $this->__include_module('anusrectum');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->anusrectum_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->anusrectum_exec->cardio_submit();
            }
        } else {
            return $this->anusrectum_exec->cardio_menu();
        }
    }

    function __loadPunggung($exec=NULL){
        $this->__include_module('punggung');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->punggung_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->punggung_exec->cardio_submit();
            }
        } else {
            return $this->punggung_exec->cardio_menu();
        }
    }

    function __loadExtermitas($exec=NULL){
        $this->__include_module('extermitas');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->extermitas_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->extermitas_exec->cardio_submit();
            }
        } else {
            return $this->extermitas_exec->cardio_menu();
        }
    }

    function __loadParu($exec=NULL){
        $this->__include_module('paru');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->paru_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->paru_exec->cardio_submit();
            }
        } else {
            return $this->paru_exec->cardio_menu();
        }
    }

    function __loadThorax($exec=NULL){
        $this->__include_module('thorax');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->thorax_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->thorax_exec->cardio_submit();
            }
        } else {
            return $this->thorax_exec->cardio_menu();
        }
    }

    function __loadNeck($exec=NULL){
        $this->__include_module('neck');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->neck_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->neck_exec->cardio_submit();
            }
        } else {
            return $this->neck_exec->cardio_menu();
        }
    }

    function __loadMouth($exec=NULL){
        $this->__include_module('mouth');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->mouth_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->mouth_exec->cardio_submit();
            }
        } else {
            return $this->mouth_exec->cardio_menu();
        }
    }

    function __loadPresentStatus($exec=NULL){
        $this->__include_module('presentStatus');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->presentStatus_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->presentStatus_exec->cardio_submit();
            }
        } else {
            return $this->presentStatus_exec->cardio_menu();
        }
    }

    function __loadVitalSign($exec=NULL){
        $this->__include_module('vitalSign');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->vitalSign_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->vitalSign_exec->cardio_submit();
            }
        } else {
            return $this->vitalSign_exec->cardio_menu();
        }
    }

    function __loadHeadFace($exec=NULL){
        $this->__include_module('headface');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->headface_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->headface_exec->cardio_submit();
            }
        } else {
            return $this->headface_exec->cardio_menu();
        }
    }

    function __loadEye($exec=NULL){
        $this->__include_module('eye');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->eye_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->eye_exec->cardio_submit();
            }
        } else {
            return $this->eye_exec->cardio_menu();
        }
    }

    function __loadNose($exec=NULL){
        $this->__include_module('nose');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->nose_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->nose_exec->cardio_submit();
            }
        } else {
            return $this->nose_exec->cardio_menu();
        }
    }

//    function __loadEar($exec=NULL){
//        $this->__include_module('ear');
//        if(isset($this->vardump) && count($this->vardump) > 0){
//            $this->ear_config->free_val = $this->vardump;
//        }
//        if(!is_null($exec)){
//            if($exec == 'submit'){
//                return $this->ear_exec->cardio_submit();
//            }
//        } else {
//            return $this->ear_exec->cardio_menu();
//        }
//    }

    function dewasa_form_submit(){
        return $this->__get_form_submit();
    }

    function anak_form_submit(){
        return $this->__get_form_submit(1);
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
        $thefields = $this->__get_data_fields('cardio', $this->query);
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
            $opr = 'update';
            $strid = array('id', $_POST['id']);
        } else {
            $thevalue['id'] = $this->__get_id_insert_value('cardio', 'id', $this->query);
            $thevalue['inputer'] = $user['userid'];
            $thevalue['inputtime'] = date('Y-m-d H:i:s', $this->config->time);
            $this->vardump['id'] = $thevalue['id'];
            $opr = 'insert';
            $strid = array('id', $thevalue['id']);
        }
        $this->__exec_db_ops(
            $this->query,
            'cardio',
            $opr,
            $strid,
            $thevalue
        );
        unset($thevalue, $opr, $strid);
        $this->__loadPresentStatus('submit');
        $this->__loadVitalSign('submit');
        $this->__loadEye('submit');
//        $this->__loadEar('submit');
        $this->__loadNose('submit');
        $this->__loadHeadFace('submit');
        $this->__loadNeck('submit');
        $this->__loadMouth('submit');
        $this->__loadThorax('submit');
        $this->__loadParu('submit');
        $this->__loadHearth('submit');
        $this->__loadAbdomen('submit');
        $this->__loadAnusrectum('submit');
        $this->__loadPunggung('submit');
        $this->__loadExtermitas('submit');
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
        redirect_to('/user/cardio_' . ($teens == 0 ? 'dewasa' : 'anak') . '/view');
    }

}