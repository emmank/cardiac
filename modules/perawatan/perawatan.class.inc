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
 *  perawatanclass.php
 *  
 *  Created on Oct 1, 2009, 1:12:45 PM
 */

require_once MODULES_DIR . DS . 'perawatan' . DS . 'config.inc';

class perawatanModule extends mainModule
{
    var $title = 'perawatan';
    var $description = 'Manajemen data digital pasien perawatanlogi';
    var $hidden_fields = array(
        'id', 'teens', 'inputer','updated', 'inputtime'
    );

    function menu(){
        $items['perawatan_form'] = array(
            'title' => __t('form perawatan'),
            'description' => __t('formulir perawatan'),
            'path' => '/user/perawatan/form',
            'exec' => 'dewasa_form',
            'weight' => '0',
            'user_required' => 'kardio dewasa'
        );
//        $items['perawatan_anak_form'] = array(
//            'title' => __t('form perawatan anak'),
//            'description' => __t('formulir perawatan anak'),
//            'path' => '/user/perawatan_anak/form',
//            'exec' => 'anak_form',
//            'weight' => '0',
//            'user_required' => 'kardio anak'
//        );
        $items['perawatan_form_submit'] = array(
            'title' => __t('form perawatan'),
            'description' => __t('formulir perawatan'),
            'path' => '/user/perawatan/form_submit',
            'exec' => 'dewasa_form_submit',
            'weight' => '0',
            'user_required' => 'kardio dewasa'
        );
//        $items['perawatan_anak_form_submit'] = array(
//            'title' => __t('form perawatan anak'),
//            'description' => __t('formulir perawatan anak'),
//            'path' => '/user/perawatan_anak/form_submit',
//            'exec' => 'anak_form_submit',
//            'weight' => '0',
//            'user_required' => 'kardio anak'
//        );
//        $items['perawatan_anak_get_lists'] = array(
//            'title' => __t('list antrian perawatan anak'),
//            'description' => __t('list antrian perawatan anak'),
//            'path' => '/user/perawatan_anak/today_perawatan_lists',
//            'exec' => '__get_today_lists',
//            'weight' => '0',
//            'user_required' => 'kardio anak'
//        );
        $items['perawatan_get_lists'] = array(
            'title' => __t('list antrian perawatan'),
            'description' => __t('formulir perawatan'),
            'path' => '/user/perawatan/today_perawatan_lists',
            'exec' => '__get_today_lists',
            'weight' => '0',
            'user_required' => 'kardio dewasa'
        );
        $items['perawatan_message'] = array(
            'title' => __t('perawatan message'),
            'description' => __t('get perawatan message'),
            'path' => '/user/perawatan/message',
            'exec' => 'message',
            'weight' => 5,
            'user_required' => 'kardio dewasa'
        );
//        $items['perawatan_anak_view'] = array(
//            'title' => __t('perawatan anak'),
//            'description' => __t('explore perawatan anak'),
//            'path' => '/user/perawatan_anak/view',
//            'exec' => 'anak_view',
//            'weight' => 5,
//            'user_required' => 'users'
//        );
        $items['perawatan_view'] = array(
            'title' => __t('perawatan'),
            'description' => __t('explore perawatan'),
            'path' => '/user/perawatan/view',
            'exec' => 'view',
            'weight' => '0',
            'user_required' => 'users'
        );
//        $items['perawatan_anak_detail'] = array(
//            'title' => __t('detail perawatan anak'),
//            'description' => __t("detail perawatan anak's patients"),
//            'path' => '/user/perawatan_anak/detail_form',
//            'exec' => 'anak_detail_form',
//            'weight' => '0',
//            'user_required' => 'users'
//        );
        $items['perawatan_detail'] = array(
            'title' => __t('detail perawatan'),
            'description' => __t("detail perawatan's patients"),
            'path' => '/user/perawatan/detail_form',
            'exec' => 'dewasa_detail_form',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['perawatan_search'] = array(
            'title' => __t('search perawatan'),
            'description' => __t("search perawatan's patients"),
            'path' => '/user/perawatan/search',
            'exec' => 'dewasa_search',
            'weight' => '0',
            'user_required' => 'users'
        );
//        $items['perawatan_anak_search'] = array(
//            'title' => __t('search perawatan anak'),
//            'description' => __t("search perawatan anak's patients"),
//            'path' => '/user/perawatan_anak/search',
//            'exec' => 'anak_search',
//            'weight' => '0',
//            'user_required' => 'users'
//        );
        $items['perawatan_search_submit'] = array(
            'title' => __t('submitted search perawatan'),
            'description' => __t("submitted search perawatan's patients"),
            'path' => '/user/perawatan/search_submit',
            'exec' => 'dewasa_search_submit',
            'weight' => '0',
            'user_required' => 'users'
        );
//        $items['perawatan_anak_search_submit'] = array(
//            'title' => __t('submitted search perawatan anak'),
//            'description' => __t("submitted search perawatan anak's patients"),
//            'path' => '/user/perawatan_anak/search_submit',
//            'exec' => 'anak_search_submit',
//            'weight' => '0',
//            'user_required' => 'users'
//        );
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
                        array('perawatan'),
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
                                $result['data'][$cnt]['links'] = '/user/perawatan/detail_form/' . $getit->fields['id'];
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
        $result['title'] = __t('Cari data pasien perawatan');
        $result['description'] = __t('Mencari data pasien perawatan');
        $result['dataform']['character'] = array(
            '#type' => 'character'
        );
        $i = 0;
        foreach($this->config->abjad as $value){
            $result['dataform']['character']['data'][$i]['show'] = $value;
            $sql = $this->query->getSelect(
                array('perawatan|id as perawatan_id'),
                array('perawatan', 'patients'),
                array(
                    array('&&', "perawatan|patients=patients|id"),
                    array('&&', "patients|nama like '" . strtolower($value) . "%'"),
                    array('&&', "teens=" . ($teens == 0 ? 0 : $teens))
                )
            );
            $this->query->connect();
            $getit = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            $result['dataform']['character']['data'][$i]['links'] = $getit->_numOfRows > 0 ? '/user/perawatan/search/' . $value : NULL;
            unset($getit); $i++;
        } unset($i);
        $result['dataform']['form'] = array(
            '#type' => 'form',
            '#action' => '/user/perawatan/search',
            '#id' => 'perawatan_search',
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
        return $this->__get_view();
    }

    function anak_view(){
        return $this->__get_view(1);
    }

    function __get_view($teens=0){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('daftar beberapa pasien');
        $result['description'] = __t('daftar beberapa pasien terakhir yang telah diperiksa');
        $result['addmenu']['#add'] = array(
            'title' => __t('add'),
            'action' => '/user/perawatan/form',
            'position' => 'top',
            'user_required' => 'users'
        );
        $result['addmenu']['#search'] = array(
            'title' => __t('search'),
            'action' => '/user/perawatan/search',
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
            array('perawatan'),
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
                $result['data'][$i]['goto'] = '/user/perawatan/detail_form/' . $getit->fields['id'];
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
        $vcache = $this->__get_perawatan_data((int)$dump[3]);
        $this->vardump = $this->__write_custom_cache($vcache);
        $this->vardump['readonly'] = $this->formhabit;
        if($teens == 0){
            $result = $this->dewasa_form();
        } else {
            $result = $this->anak_form();
        }
        return $result;
    }

    function __get_today_lists(){
        $result = array();
//        echo "disini";
        $result = $this->today_patient_lists();
//        echo "<pre>"; print_r($result); echo "</pre>";
        if(count($result['data'])>0){
//            echo "disini";
            
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

    function __get_perawatan_data($id){
        $result = array();
        $sql = $this->query->getSelect(
            array(),
            array('perawatan'),
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
                    $perawatan_id = preg_replace('/^edit_/','',$dump[3]);
                    $vcache = $this->__get_perawatan_data((int)$perawatan_id);
                    $this->vardump = $vcache;
                    unset($perawatan_id);
                } else {
                    $vcache['kunjungan'] = $dump[3]; unset($dump);
                }
            } else {
//                echo "test";
                redirect_to('/user/perawatan/today_perawatan_lists');
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
        $form['perawatan'] = array(
            '#type' => 'special',
            '#id' => 'perawatan',
            '#title' => __t('Perawatan'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/user/perawatan/form/' . ($this->formhabit == 'readonly' ? 'edit_' . $vcache['id'] : '/form_submit'),
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE,
            '#formtpl' => MODULES_DIR . DS . 'perawatan' . DS . 'perawatan.tpl',
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
        $form['perawatan']['kunjungan'] = array(
            '#type' => 'hidden',
            '#value' => isset($vcache['kunjungan']) ? $vcache['kunjungan'] : ''
        );
        $thefields = $this->__get_data_fields('perawatan', $this->query);
        foreach($thefields as $value){
            if(in_array($value, $this->hidden_fields)){
                if($value == 'id'){
                    $form['perawatan'][$value] = array(
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
                    $form['perawatan'][$value] = array(
                        '#type' => 'hidden',
                        '#value' => $vcache['patients']
                    );
                    $query = $this->__get_patient_data($vcache['patients'], array('nama', 'tgl_lahir', 'alamat', 'kota', 'propinsi', 'nomor', 'kelamin', 'gol_darah'));
                    if(count($query) > 0){
                        foreach($query as $ky => $vl){
                            if($ky == 'tgl_lahir'){
                                $vl = round(($this->agecount_in_month(strtotime($vl))/12),0);
                                $form['perawatan']['umur'] = array(
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
                                    $form['perawatan'][$ky] = array(
                                        '#type' => $ky == 'alamat' ? 'textarea' : 'info',
                                        '#value' => $vl,
                                        '#title' => __t($ky),
                                        '#tbpos' => $tbpos
                                    );
                                    if($ky == 'alamat'){
                                        $form['perawatan'][$ky]['#extra'] = 'readonly="true"';
                                        $form['perawatan'][$ky]['#cols'] = '55';
                                        $form['perawatan'][$ky]['#rows'] = '3';
                                    } elseif($ky == 'no_registrasi'){
                                        $form['perawatan'][$ky]['#link'] = '/user/perawatan/today_patient_lists';
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
                        $form['perawatan']['kunjungan_ke'] = array(
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
                        $form['perawatan']['pengirim'] = array(
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
                    $form['perawatan'][$value] = array(
                        '#type' => $this->config->fields_form_type[$value],
                        '#value' => isset($vcache[$value]) ? $vcache[$value] : '',
                        '#size' => $this->config->fields_form_type[$value] != 'select' && $this->formtype_fields[$value] != 'date' ? 20 : 1,
                        '#title' => __t($value),
                        '#error' => isset($vcache['blank']) && in_array($value, $vcache['blank']) ? 1 : 0
                    );
                }
                if($this->formhabit == 'readonly'){
                    $form['perawatan'][$value]['#extra'] = 'readonly="true"';
                }
            }
        }

        $form['perawatan']['tab_items']['pengkajian'] = $this->__loadPengkajian();
        $form['perawatan']['tab_items']['rencana'] = $this->__loadRencana();
        $form['perawatan']['tab_items']['pemeriksaan'] = $this->__loadPemeriksaan();
        $form['perawatan']['tab_items']['tindakan'] = $this->__loadTindakan();
        $form['perawatan']['tab_items']['pemberian'] = $this->__loadPemberian();
        $form['perawatan']['tab_items']['perkembangan'] = $this->__loadPerkembangan();
//        $form['perawatan']['tab_items']['nose'] = $this->__loadNose();
//        $form['perawatan']['tab_items']['headface'] = $this->__loadHeadFace();
//        $form['perawatan']['tab_items']['neck'] = $this->__loadNeck();
//        $form['perawatan']['tab_items']['mouth'] = $this->__loadMouth();
//        $form['perawatan']['tab_items']['space'] = "";
//        $form['perawatan']['tab_items']['thorax'] = $this->__loadThorax();
//        $form['perawatan']['tab_items']['paru'] = $this->__loadParu();
//        $form['perawatan']['tab_items']['hearth'] = $this->__loadHearth();
//        $form['perawatan_' . ($teens == 0 ? 'dewasa' : 'anak')]['tab_items']['abdomen'] = $this->__loadAbdomen();
//        $form['perawatan_' . ($teens == 0 ? 'dewasa' : 'anak')]['tab_items']['anusrectum'] = $this->__loadAnusrectum();
//        $form['perawatan_' . ($teens == 0 ? 'dewasa' : 'anak')]['tab_items']['punggung'] = $this->__loadPunggung();
//        $form['perawatan_' . ($teens == 0 ? 'dewasa' : 'anak')]['tab_items']['extermitas'] = $this->__loadExtermitas();

        $form['perawatan']['submit'] = array(
            '#type' => 'submit',
            '#value' => ($this->formhabit == 'readonly' ? __t('edit') : __t('submit'))
        );
        return $form;
    }

    function __loadPengkajian($exec=NULL){
        $this->__include_module('pengkajian');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->pengkajian_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->pengkajian_exec->perawatan_submit();
            }
        } else {
//            echo "disini";
            return $this->pengkajian_exec->perawatan_menu();
        }
    }

    function __loadRencana($exec=NULL){
        $this->__include_module('rencana');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->vitalSign_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->rencana_exec->perawatan_submit();
            }
        } else {
            return $this->rencana_exec->perawatan_menu();
        }
    }
////
    function __loadPemeriksaan($exec=NULL){
        $this->__include_module('pemeriksaan');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->pemeriksaan_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->pemeriksaan_exec->perawatan_submit();
            }
        } else {
            return $this->pemeriksaan_exec->perawatan_menu();
        }
    }
    
    function __loadTindakan($exec=NULL){
        $this->__include_module('tindakan');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->tindakan_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->tindakan_exec->perawatan_submit();
            }
        } else {
            return $this->tindakan_exec->perawatan_menu();
        }
    }
    
    function __loadPerkembangan($exec=NULL){
        $this->__include_module('perkembangan');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->perkembangan_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->perkembangan_exec->perawatan_submit();
            }
        } else {
            return $this->perkembangan_exec->perawatan_menu();
        }
    }

    function __loadPemberian($exec=NULL){
        $this->__include_module('pemberian');
        if(isset($this->vardump) && count($this->vardump) > 0){
            $this->pemberian_config->free_val = $this->vardump;
        }
        if(!is_null($exec)){
            if($exec == 'submit'){
                return $this->pemberian_exec->perawatan_submit();
            }
        } else {
            return $this->pemberian_exec->perawatan_menu();
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
        $thefields = $this->__get_data_fields('perawatan', $this->query);
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
                'perawatan',
                $thevalue,
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
        } else {
            $thevalue['id'] = $this->__get_id_insert_value('perawatan', 'id', $this->query);
            $thevalue['inputer'] = $user['userid'];
            $thevalue['inputtime'] = date('Y-m-d H:i:s', $this->config->time);
            $sql = $this->query->saveData(
                'perawatan',
                $thevalue
            );
            $this->vardump['id'] = $thevalue['id'];
        }
        $this->query->connect();
        $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        unset($thevalue);
        $this->__loadPengkajian('submit');
        $this->__loadRencana('submit');
        $this->__loadPemeriksaan('submit');
        $this->__loadTindakan('submit');
        $this->__loadPemberian('submit');
        $this->__loadPerkembangan('submit');
//        $this->__loadNose('submit');
//        $this->__loadHeadFace('submit');
//        $this->__loadNeck('submit');
//        $this->__loadMouth('submit');
//        $this->__loadThorax('submit');
//        $this->__loadParu('submit');
//        $this->__loadHearth('submit');
//        $this->__loadAbdomen('submit');
//        $this->__loadAnusrectum('submit');
//        $this->__loadPunggung('submit');
//        $this->__loadExtermitas('submit');
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
        redirect_to('/user/perawatan/view');
    }

}