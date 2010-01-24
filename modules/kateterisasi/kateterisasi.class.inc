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
    var $title = 'kateterisasi';
    var $description = 'Manajemen data digital pasien kateterisasilogi';
    var $hidden_fields = array(
        'id', 'teens', 'inputer','updated', 'inputtime'
    );

    function menu(){
        $items['kateterisasi_form'] = array(
            'title' => __t('form kateterisasi dewasa'),
            'description' => __t('formulir kateterisasi dewasa'),
            'path' => '/user/kateterisasi/form',
            'exec' => 'dewasa_form',
            'weight' => '0',
            'user_required' => 'kateterisasi'
        );
        $items['kateterisasi_form_submit'] = array(
            'title' => __t('form kateterisasi dewasa'),
            'description' => __t('formulir kateterisasi dewasa'),
            'path' => '/user/kateterisasi/form_submit',
            'exec' => 'dewasa_form_submit',
            'weight' => '0',
            'user_required' => 'kateterisasi'
        );
        $items['kateterisasi_get_lists'] = array(
            'title' => __t('list antrian kateterisasi dewasa'),
            'description' => __t('formulir kateterisasi dewasa'),
            'path' => '/user/kateterisasi/today_kateterisasi_lists',
            'exec' => '__get_today_lists',
            'weight' => '0',
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
            'description' => __t('explore kateterisasi dewasa'),
            'path' => '/user/kateterisasi/view',
            'exec' => 'dewasa_view',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['kateterisasi_detail'] = array(
            'title' => __t('detail kateterisasi dewasa'),
            'description' => __t("detail kateterisasi dewasa's patients"),
            'path' => '/user/kateterisasi/detail_form',
            'exec' => 'dewasa_detail_form',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['kateterisasi_search'] = array(
            'title' => __t('search kateterisasi dewasa'),
            'description' => __t("search kateterisasi dewasa's patients"),
            'path' => '/user/kateterisasi/search',
            'exec' => 'dewasa_search',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['kateterisasi_lists'] = array(
            'title' => __t('lists kateterisasi dewasa'),
            'description' => __t("lists kateterisasi dewasa's patients"),
            'path' => '/user/kateterisasi/lists',
            'exec' => 'dewasa_lists',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['kateterisasi_search_submit'] = array(
            'title' => __t('submitted search kateterisasi dewasa'),
            'description' => __t("submitted search kateterisasi dewasa's patients"),
            'path' => '/user/kateterisasi/search_submit',
            'exec' => 'dewasa_search_submit',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['kateterisasi_formreport'] = array(
            'title' => __t('kateterisasi form report'),
            'description' => __t("report of kateterisasi form"),
            'path' => '/user/kateterisasi/report',
            'exec' => 'report_execprint',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['kateterisasi_prescription'] = array(
            'title' => __t('kateterisasi anak form') . ' ' . __t('prescription'),
            'description' => __t("form of kateterisasi") . ' ' . __t('prescription'),
            'path' => '/user/kateterisasi/prescription',
            'exec' => 'prescription_form',
            'weight' => '0',
            'user_required' => 'kateterisasi'
        );
        $items['kateterisasi_prescription'] = array(
            'title' => __t('kateterisasi dewasa form') . ' ' . __t('prescription'),
            'description' => __t("form of kateterisasi") . ' ' . __t('prescription'),
            'path' => '/user/kateterisasi/prescription',
            'exec' => 'prescription_form',
            'weight' => '0',
            'user_required' => 'kateterisasi'
        );
        $items['kateterisasi_prescription_submit'] = array(
            'title' => __t('kateterisasi anak form') . ' ' . __t('prescription'),
            'description' => __t("form of kateterisasi") . ' ' . __t('prescription'),
            'path' => '/user/kateterisasi/prescription_submit',
            'exec' => 'prescription_submit',
            'weight' => '0',
            'user_required' => 'kateterisasi'
        );
        $items['kateterisasi_prescription_submit'] = array(
            'title' => __t('kateterisasi dewasa form') . ' ' . __t('prescription'),
            'description' => __t("form of kateterisasi") . ' ' . __t('prescription'),
            'path' => '/user/kateterisasi/prescription_submit',
            'exec' => 'prescription_submit',
            'weight' => '0',
            'user_required' => 'kateterisasi'
        );
        return $items;
    }

    function report_execprint(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(isset($dump[3])){
            $teens = 1;
        }
        $output['type'] = 'whatever';
        $output['renderfile'] = MODULES_DIR . DS . 'kateterisasi' . DS . 'form.report';
        $vcache = $this->__get_kateterisasi_data((int)$_POST['id']);
        $this->formhabit = 'readonly';
        $this->vardump = $this->__write_custom_cache($vcache);
        $this->vardump['readonly'] = $this->formhabit;
        $output['data'] = $this->__get_form(isset($teens) ? $teens : 0);
        return $output;
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
                        array('kateterisasi'),
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
                                $result['data'][$cnt]['links'] = '/user/kateterisasi_' . ($teens != 0 ? 'anak' : 'dewasa') . '/detail_form/' . $getit->fields['id'];
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
                    array('&&', "patients|nama like '" . strtolower($value) . "%'"),
                    array('&&', "teens=" . ($teens == 0 ? 0 : $teens))
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
            $result['result'] = $this->__get_search_submit($teens);
        } unset($dump);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function dewasa_view(){
        return $this->__get_today_lists();
    }

    function anak_view(){
        return $this->__get_today_lists(1);
    }

    function dewasa_lists(){
        return $this->__get_lists();
    }

    function anak_lists(){
        return $this->__get_lists(1);
    }

    function __get_lists($teens=0){
        $this->sync_scheme('kateterisasi', $this->query);
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
                'field' => 'strnum',
                'caption' => __t('No. RM'),
                'width' => '10%',
                'align' => 'left'
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
            array(),
//                array('&&', "teens=" . ($teens != 0 ? $teens : 0))
//            ),
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
                    array('id', 'nama', 'tgl_lahir', 'inputtime','strnum'),
                    array('patients'),
                    array(
                        array('&&', "id=" . $getit->fields['patients'])
                    )
                );
                $this->query->connect();
                $getthis = $this->query->conn->Execute($sql); unset($sql);
                $this->query->close();
                $result['data'][$i]['strnum'] = $getthis->fields['strnum'];
                $result['data'][$i]['nama'] = $getthis->fields['nama'];
                $result['data'][$i]['tgl_lahir'] = number_format(round($this->agecount_in_month(strtotime($getthis->fields['tgl_lahir']))/12, 1), 1, ',','.') . ' th';
                $result['data'][$i]['goto'] = '/user/kateterisasi/detail_form/' . $getit->fields['id'];
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
        $vcache = $this->__get_kateterisasi_data((int)$dump[3]);
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
//                if(!is_null($teens)){
//                    if($value['age'] <= $this->config->teenlimit){
                        $result['data'][$key] = $value;
//                    }
//                } else {
//                    if($value['age'] > $this->config->teenlimit){
//                        $result['data'][$key] = $value;
//                    }
//                }
            }
        }
//        echo '<pre>'; print_r($result); echo '</pre>';
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
                    $kateterisasi_id = preg_replace('/^edit_/','',$dump[3]);
                    $vcache = $this->__get_kateterisasi_data((int)$kateterisasi_id);
                    $this->vardump = $vcache;
                    unset($kateterisasi_id);
                } else {
                    $vcache['kunjungan'] = $dump[3]; unset($dump);
                }
            } else {
                redirect_to('/user/kateterisasi/today_kateterisasi_lists');
            } unset($dump);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('patients', 'inputer','pilihan_cara_bayar'),
            array('kunjungan'),
            array(
                array('&&', "id=" . $vcache['kunjungan'])
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        $pengirim = $query->fields['inputer'];
        if(!isset($vcache['patients'])){
            $vcache['patients'] = $query->fields['patients']; 
            $vcache['pilihan_cara_bayar'] = $query->fields['pilihan_cara_bayar']; unset($query);
        }
        $addmenuopts = array(
            '' => __t('-- medical record --'),
            'all' => __t('semua')
        );
        $rujukanopts = array(
            '' => __t('-- dirujuk ke --')
        );
        $dump_addmenus = $this->__get_bagian_lists();
//        echo '<pre>'; print_r($dump_addmenus); echo '</pre>';
        foreach($dump_addmenus as $key => $value){
            if ($value=='kateterisasi'){
                
            } else {
                $rujukanopts[$key] = $value;
            }
//            echo '<pre>'; print_r($value); echo '</pre>';
            $sql = $this->query->getSelect(
                array('id','pilihan_cara_bayar'),
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
            '#title' => __t('Kateterisasi'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/user/kateterisasi/form' . ($this->formhabit == 'readonly' ? '/edit_' . $vcache['id'] : '_submit'),
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE,
            '#formtpl' => MODULES_DIR . DS . 'kateterisasi' . DS . 'kateterisasi.tpl',
            '#addmenu' => array(
                '#addmenu' => array(
                    'title' => __t('medical record'),
                    'action' => '/user/patient/medical_record/' . $vcache['patients'],
                    'position' => 'top',
                    'class' => 'button',
                    'methode' => 'choose',
                    'options' => $addmenuopts,
                    'filter' => 'bagian'
                )
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
                    $query = $this->__get_patient_data(
                        $vcache['patients'],
                        array(
                            'nama',
                            'tgl_lahir',
                            'alamat',
                            'kota',
                            'propinsi',
                            'nomor',
                            'kelamin',
                            'gol_darah',
                            'strnum'
                        )
                    );
//                    echo '<pre>'; print_r($query); echo '</pre>';
                    if(count($query) > 0){
                        if($this->formhabit == 'readonly'){
                            if(isset($vcache['inputtime']) && date('Y-n-j', strtotime($vcache['inputtime'])) == date('Y-n-j', $this->config->time)){
                                $getvisit_info = $this->patient_visit_lists(date('Y-m-d', $this->config->time), 'kateterisasi', $vcache['patients']);
                                if(count($getvisit_info) > 0){
                                    foreach($getvisit_info as $ky => $vl){
                                        if(is_null($vl['doneby'])){
                                            $forbidden = 0; break;
                                        }
                                    }
                                }
                                if(!isset($forbidden)){
                                    $form['kateterisasi']['#addmenu']['#addmenu0'] = array(
                                        'title' => __t('dirujuk ke'),
                                        'action' => '/user/patient/register_form_submit',
                                        'position' => 'top',
                                        'class' => 'button',
                                        'methode' => 'choose',
                                        'options' => $rujukanopts,
                                        'user_required' => 'kateterisasi',
                                        'filter' => 'bagian',
                                        'items' => array (
                                            'id' => $vcache['patients'],
                                            'strnum' => $query['strnum'],
                                            'pilihan_cara_bayar' => $vcache['pilihan_cara_bayar'],
                                        )
                                    );
                                    $form['kateterisasi']['#addmenu']['#prescription'] = array(
                                        'title' => __t('prescription'),
                                        'action' => '/user/kateterisasi/prescription/' . $vcache['id'],
                                        'position' => 'top',
                                        'class' => 'button',
                                        'user_required' => 'kateterisasi',
                                        'filter' => 'items',
                                        'items' => array (
                                            'id' => $vcache['id']
                                        )
                                    );
                                } else {
                                    unset($forbidden);
                                }
                            }
                            $form['kateterisasi']['#addmenu']['#printed'] = array(
                                'title' => __t('print'),
                                'action' => '/user/kateterisasi/report' . ($teens != 0 ? '/1' : ''),
                                'position' => 'top',
                                'class' => 'button',
                                'user_required' => 'kateterisasi',
                                'filter' => 'items',
                                'items' => array (
                                    'id' => $vcache['id']
                                )
                            );
                        } unset($rujukanopts);
                        foreach($query as $ky => $vl){
                            if($ky == 'tgl_lahir'){
                                $vl = round(($this->agecount_in_month(strtotime($vl))/12),0);
                                $form['kateterisasi']['umur'] = array(
                                    '#type' => 'info',
                                    '#value' => $vl . ' tahun',
                                    '#title' => __t('umur'),
                                    '#tbpos' => 3
                                );
                            } elseif($ky != 'strnum') {
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
//                                    echo '<pre>'; print_r($query); echo '</pre>';
                                    $form['kateterisasi'][$ky] = array(
                                        '#type' => $ky == 'alamat' ? 'textarea' : 'info',
                                        '#value' => $vl,
                                        '#title' => __t($ky),
                                        '#tbpos' => $tbpos
                                    );
                                    if ($ky=='no_registrasi'){
                                        $form['kateterisasi'][$ky] = array(
                                            '#type' => $ky == 'alamat' ? 'textarea' : 'info',
                                            '#value' => $query['strnum'],
                                            '#title' => __t($ky),
                                            '#tbpos' => $tbpos
                                        );
                                    }
                                    if($ky == 'alamat'){
                                        $form['kateterisasi'][$ky]['#extra'] = 'readonly="true"';
                                        $form['kateterisasi'][$ky]['#cols'] = '55';
                                        $form['kateterisasi'][$ky]['#rows'] = '3';
                                    } elseif($ky == 'no_registrasi'){
                                        $form['kateterisasi'][$ky]['#link'] = '/user/kateterisasi/today_patient_lists';
                                    }
                                    unset($tbpos);
                                }
                            }
                        }
//                        echo '<pre>'; print_r($form); echo '</pre>';
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
//                    $this->query->close();
                }
                if($value != 'no_registrasi' && $value != 'kunjungan' && $value != 'patients'){
                    $form['kateterisasi'][$value] = array(
                        '#type' => $this->config->fields_form_type[$value],
                        '#value' => isset($vcache[$value]) ? $vcache[$value] : '',
                        '#size' => $this->config->fields_form_type[$value] != 'select' && $this->formtype_fields[$value] != 'date' ? 20 : 1,
                        '#title' => __t($value),
                        '#error' => isset($vcache['blank']) && in_array($value, $vcache['blank']) ? 1 : 0
                    );
                }
                if($this->formhabit == 'readonly'){
                    $form['kateterisasi'][$value]['#extra'] = 'readonly="true"';
                }
            }
        }

        $form['kateterisasi']['tab_items']['lvGrafi'] = $this->__loadLvGrafi();
        $form['kateterisasi']['tab_items']['keterangan'] = $this->__loadKeterangan();

        $form['kateterisasi']['submit'] = array(
            '#type' => 'submit',
            '#value' => ($this->formhabit == 'readonly' ? __t('edit') : __t('submit'))
        );
        if($this->formhabit == 'readonly'){
            if(isset($vcache['inputtime']) && date('Y-n-j', strtotime($vcache['inputtime'])) == date('Y-n-j', $this->config->time)){
                $getvisit_info = $this->patient_visit_lists(date('Y-m-d', $this->config->time), 'kateterisasi', $vcache['patients']);
                if(count($getvisit_info) > 0){
                    foreach($getvisit_info as $ky => $vl){
                        if(is_null($vl['doneby'])){
                            $forbidden = 0; break;
                        }
                    }
                }
            } else {
                $forbidden = 0;
            }
            if(isset($forbidden)){
                $form['kateterisasi']['submit']['#extra'] = ' disabled="true"';
                unset($forbidden);
            }
        }
        
        return $form;
    }

    function __loadLvGrafi($exec=NULL){
        $this->__include_module('lvGrafi');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->lvGrafi_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->lvGrafi_exec->kateterisasi_submit();
            }
        } else {
            return $this->lvGrafi_exec->kateterisasi_menu();
        }
    }

    function __loadKeterangan($exec=NULL){
        $this->__include_module('keterangan');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->keterangan_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->keterangan_exec->kateterisasi_submit();
            }
        } else {
            return $this->keterangan_exec->kateterisasi_menu();
        }
    }

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
        $thefields = $this->__get_data_fields('kateterisasi', $this->query);
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
            $thevalue['id'] = $this->__get_id_insert_value('kateterisasi', 'id', $this->query);
            $thevalue['inputer'] = $user['userid'];
            $thevalue['inputtime'] = date('Y-m-d H:i:s', $this->config->time);
            $this->vardump['id'] = $thevalue['id'];
            $opr = 'insert';
            $strid = array('id', $thevalue['id']);
        }
        $this->__exec_db_ops(
            $this->query,
            'kateterisasi',
            $opr,
            $strid,
            $thevalue
        );
        unset($thevalue, $opr, $strid);
        $this->__loadLvGrafi('submit');
        $this->__loadKeterangan('submit');
        
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

}