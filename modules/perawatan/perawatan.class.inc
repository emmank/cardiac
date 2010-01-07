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
    var $description = 'Manajemen data digital pasien rawat inap';
    var $hidden_fields = array(
        'id', 'inputer','updated', 'inputtime', 'pukul_keluar'
    );

    function menu(){
        $items['perawatan_register'] = array(
            'title' => __t('Registrasi Perawatan'),
            'description' => __t('Registrasi Pendaftaran Pasien Rawat Inap'),
            'path' => '/user/perawatan/form',
            'exec' => 'form',
            'weight' => '0',
            'user_required' => 'perawatan'
        );
        $items['perawatan_register_submit'] = array(
            'title' => __t('Registrasi Perawatan'),
            'description' => __t('Eksekusi Registrasi Pendaftaran Pasien Rawat Inap'),
            'path' => '/user/perawatan/form_submit',
            'exec' => 'form_submit',
            'weight' => '0',
            'user_required' => 'perawatan'
        );
        $items['perawatan_daftar'] = array(
            'title' => __t('perawatan'),
            'description' => __t('Daftar Pasien Rawat Inap'),
            'path' => '/user/perawatan/view',
            'exec' => 'view',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['perawatan_view'] = array(
            'title' => __t('perawatan'),
            'description' => __t('Daftar Pasien Rawat Inap'),
            'path' => '/user/perawatan/lists',
            'exec' => '__get_view',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['perawatan_search'] = array(
            'title' => __t('Cari Pasien'),
            'description' => __t('Cari Pasien Rawat Inap'),
            'path' => '/user/perawatan/search',
            'exec' => 'search',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['perawatan_antrian'] = array(
            'title' => __t('Antrian Pasien'),
            'description' => __t('Antrian Pasien Rawat Inap'),
            'path' => '/user/perawatan/today_patient_lists',
            'exec' => '__get_today_lists',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['perawatan_message'] = array(
            'title' => __t('perawatan message'),
            'description' => __t('get perawatan message'),
            'path' => '/user/perawatan/message',
            'exec' => 'message',
            'weight' => 5,
            'user_required' => 'perawatan'
        );
        $items['perawatan_detail'] = array(
            'title' => __t('detail perawatan'),
            'description' => __t("detail perawatan's patients"),
            'path' => '/user/perawatan/detail_form',
            'exec' => '_detail_form',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['perawatan_search'] = array(
            'title' => __t('search perawatan'),
            'description' => __t("search perawatan's patients"),
            'path' => '/user/perawatan/search',
            'exec' => '_search',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['perawatan_search_submit'] = array(
            'title' => __t('submitted search perawatan'),
            'description' => __t("submitted search perawatan's patients"),
            'path' => '/user/perawatan/search_submit',
            'exec' => '_search_submit',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['perawatan_redirect'] = array(
            'title' => __t('redirect to perawatans item'),
            'description' => __t("redirect perawatan's patients to it's items"),
            'path' => '/care/perawatan',
            'exec' => '__redirect',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['perawatan_mainreport'] = array(
            'title' => __t('perawatans report'),
            'description' => __t("report of perawatan handle"),
            'path' => '/care/perawatan/mainprint',
            'exec' => 'report_execprint',
            'weight' => '0',
            'user_required' => 'users'
        );
        return $items;
    }

    function report_execprint(){
        $output['type'] = 'whatever';
        $output['renderfile'] = MODULES_DIR . DS . 'perawatan' . DS . 'mainreport.render';
        $vcache = $this->__get_perawatan_data((int)$_POST['id']);
        $this->formhabit = 'readonly';
        $this->__write_custom_cache($vcache);
        $output['data'] = $this->form();
        return $output;
    }

    function __redirect(){
        redirect_to('/care/perawatan/' . $_POST['items'] . '/' . $_POST['pid']);
    }

    function _search(){
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
                    array('&&', "patients|nama like '" . strtolower($value) . "%'")
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
        return $result;
    }

    function _search_submit(){
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
        return $result;
    }

    function view(){
        $this->sync_scheme('perawatan', $this->query);
        $this->sync_scheme('ruang', $this->query);
        $this->sync_scheme('perawatan_items', $this->query);
        return $this->__get_today_lists();
    }

    function __get_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('daftar beberapa pasien');
        $result['description'] = __t('daftar beberapa pasien terakhir yang telah diperiksa');
        $result['addmenu']['#add'] = array(
            'title' => __t('register'),
            'action' => '/user/perawatan/form',
            'position' => 'top',
            'user_required' => 'users'
        );
        $result['addmenu']['#search'] = array(
            'title' => __t('search'),
            'action' => '/care/perawatan/search',
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
                'field' => 'pukul_masuk',
                'caption' => __t('tanggal masuk'),
                'width' => '25%',
                'align' => 'right'
            )
        );

        $sql = $this->query->getSelect(
            array(),
            array('perawatan'),
            array(
                array('&&', "pukul_keluar is null")
            ),
            'inputtime desc',
            '0,10'
        ); unset($where);
        $this->query->connect();
        $getit = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($getit->_numOfRows > 0){
            for($i=0; $i<$getit->_numOfRows; $i++){
                $sql = $this->query->getSelect(
                    array('id', 'nama', 'tgl_lahir'),
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
                $result['data'][$i]['pukul_masuk'] = date('j-n-Y H:i:s', strtotime($getit->fields['pukul_masuk']));
                $getit->MoveNext();
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

    function _detail_form(){
        $this->formhabit = 'readonly';
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        $vcache = $this->__get_perawatan_data((int)$dump[3]);
        $this->vardump = $this->__write_custom_cache($vcache);
        $this->vardump['readonly'] = $this->formhabit;
        $result = $this->form();
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

    function form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        } else {
//            if(!isset($vcache['id']) || trim($vcache['id']) == '' || !is_numeric($vcache['id'])){
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
                    redirect_to('/user/perawatan/today_patient_lists');
                } unset($dump);
//            }
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
        $rujukanopts = array(
            '' => __t('-- perawatan --')
        );
        $dumprjk = $this->__get_perawatan_lists();
        foreach($dumprjk as $key => $value){
            $rujukanopts[$key] = $value;
        } unset($dumprjk);
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
            '#title' => __t('perawatan'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/user/perawatan/form' . ($this->formhabit == 'readonly' ? '/edit_' . $vcache['id'] : '_submit'),
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE,
            '#formtpl' => MODULES_DIR . DS . 'perawatan' . DS . 'perawatan.tpl',
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
                if($value == 'pukul_masuk'){
                    if(!isset($vcache['pukul_masuk']) || $vcache['pukul_masuk'] == ''){
                        $vcache['pukul_masuk'] = date('Y-m-d H:i:s', $this->config->time);
                    }
                } elseif($value == 'patients'){
                    $form['perawatan'][$value] = array(
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
                            'kelamin',
                            'gol_darah',
                            'tinggi',
                            'berat',
                            'tekanan_darah',
                            'indikasi'
                        )
                    );
                    if(count($query) > 0){
                        if($this->formhabit == 'readonly'){
                            $form['perawatan']['#addmenu']['#addmenu0'] = array(
                                'title' => __t('dirujuk ke'),
                                'action' => '/care/perawatan',
                                'position' => 'top',
                                'class' => 'button',
                                'methode' => 'choose',
                                'options' => $rujukanopts,
                                'user_required' => 'perawatan',
                                'filter' => 'items',
                                'items' => array (
                                    'pid' => $vcache['id']
                                )
                            );
                            $form['perawatan']['#addmenu']['#printed'] = array(
                                'title' => __t('print'),
                                'action' => '/care/perawatan/mainprint',
                                'position' => 'top',
                                'class' => 'button',
                                'user_required' => 'perawatan',
                                'filter' => 'items',
                                'items' => array (
                                    'id' => $vcache['id']
                                )
                            );
                        } unset($rujukanopts);
                        foreach($query as $ky => $vl){
                            if($ky == 'tgl_lahir'){
                                $vl = round(($this->agecount_in_month(strtotime($vl))/12),0);
                                $form['perawatan']['umur'] = array(
                                    '#type' => 'info',
                                    '#value' => $vl . ' tahun',
                                    '#title' => __t('umur'),
                                    '#tbpos' => 2
                                );
                                $usiapatient = floor($vl);
                            } else {
                                if($ky != 'kota' && $ky != 'propinsi'){
                                    if($ky == 'alamat'){
                                        $proplists = $this->__get_propinsi_options('nama_propinsi');
                                        $kablists = $this->__get_kabupaten_options('kabupaten');
                                        $vl = $vl . ' ' . $kablists[$query['kota']] . ' ' . $proplists[$query['propinsi']];
                                        $tbpos = 3;
                                        unset($proplists, $kablists);
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
                                    $form['perawatan'][$ky] = array(
                                        '#type' => $ky == 'alamat' ? 'textarea' : 'info',
                                        '#value' => $vl,
                                        '#title' => __t($ky),
                                        '#tbpos' => $tbpos,
                                        '#readonly' => true
                                    );
                                    if($ky == 'alamat'){
                                        $form['perawatan'][$ky]['#extra'] = 'readonly="true"';
                                        $form['perawatan'][$ky]['#cols'] = '30';
                                        $form['perawatan'][$ky]['#rows'] = '3';
                                    } elseif($ky == 'no_registrasi'){
                                        $form['perawatan'][$ky]['#link'] = '/user/perawatan/today_patient_lists';
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
                        $form['perawatan']['handleby'] = array(
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
                        $form['perawatan']['kunjungan_ke'] = array(
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
                        $form['perawatan']['pengirim'] = array(
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
                        $form['perawatan']['denyut_jantung_max'] = array(
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
                        $form['perawatan']['target_denyut_jantung_max'] = array(
                            '#type' => 'info',
                            '#value' => $getthis->fields['nadi_85'],
                            '#title' => __t('target_denyut_jantung_max'),
                            '#tbpos' => 14,
                            '#readonly' => true
                        ); unset($getthis);
                    }
                }
                if($value != 'no_registrasi' && $value != 'kunjungan' && $value != 'patients'){
                    $form['perawatan'][$value] = array(
                        '#type' => $this->config->fields_form_type[$value],
                        '#value' => isset($vcache[$value]) ? $vcache[$value] : '',
                        '#size' => $this->config->fields_form_type[$value] != 'select' && $this->formtype_fields[$value] != 'date' ? 20 : 1,
                        '#title' => __t($value),
                        '#error' => isset($vcache['blank']) && in_array($value, $vcache['blank']) ? 1 : 0
                    );
                    if($this->config->fields_form_type[$value] == 'datetime'){
                        $form['perawatan'][$value]['#theref'] = $this->nama_bulan;
                        $form['perawatan'][$value]['#value'] = isset($vcache[$value]) ? $vcache[$value] : date('Y-m-d H:i:s', $this->config->time);
                    } elseif($value == 'ruang'){
                        $ruanglists = $this->__get_ruang_options('ruang');
                        foreach($ruanglists as $ky => $vl){
                            $sql = $this->query->getSelect(
                                array('ruang'),
                                array('perawatan'),
                                array(
                                    array('&&', "ruang=" . $ky)
                                )
                            );
                            $this->query->connect();
                            $getit = $this->query->conn->Execute($sql); unset($sql);
                            $this->query->close();
                            if($getit->_numOfRows < 1){
                                $form['perawatan'][$value]['#option'][$ky] = $vl;
                            } elseif($ky == $vcache[$value]){
                                $form['perawatan'][$value]['#option'][$ky] = $vl;
                            } unset($getit);
                        }
                        if($this->formhabit == 'readonly'){
                            $form['perawatan'][$value]['#value'] = $ruanglists[$vcache['ruang']];
                        } unset($ruanglists);
                    }
                }
                if($this->formhabit == 'readonly'){
                    $form['perawatan'][$value]['#readonly'] = TRUE;
                }
            }
        }
        if(!isset($vcache['inputtime']) || $vcache['inputtime'] == '0000-00-00 00:00:00' || is_null($vcache['inputtime'] || trim($vcache['inputtime']) == '')){
            $vcache['inputtime'] = date('Y-m-d H:i:s', $this->config->time);
        }
        $form['perawatan']['tanggal'] = array(
            '#type' => 'info',
            '#value' => date('j-n-Y', strtotime($vcache['inputtime'])),
            '#title' => __t('tanggal'),
            '#tbpos' => 8,
            '#readonly' => true
        );

        $form['perawatan']['submit'] = array(
            '#type' => 'submit',
            '#value' => ($this->formhabit == 'readonly' ? __t('edit') : __t('submit'))
        );
        if(isset($vcache['inputtime']) && date('Y-n-j', strtotime($vcache['inputtime'])) == date('Y-n-j', $this->config->time)){
            $getvisit_info = $this->patient_visit_lists(date('Y-m-d', $this->config->time), 'perawatan', $vcache['patients']);
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
            $form['perawatan']['submit']['#extra'] = ' disabled="true"';
            unset($forbidden);
        }
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
        );
        unset($query);
        $thefields = $this->__get_data_fields('perawatan', $this->query);

        foreach($this->vardump as $key => $value){
//            echo "<pre>";print_r($value);echo "</pre>";
            if(in_array($key, $thefields)){
                if($this->config->typeoffields[$key] == 'date'){
                    $value = explode('|', $value);
                    $value = implode('-', $value);
                } elseif($this->config->typeoffields[$key] == 'datetime'){
                    $value = explode('-', $value);
                    $value = $value[0] . '-' . $value[1] . '-' . $value[2] . ' ' . $value[3] . ':' . $value[4] . ':' . $value[5];
                }
                $thevalue[$key] = $value;
            }
        } unset($thefields);
        $user = $this->__get_user_info();
        if($_POST['id'] != ''){
            $thevalue['updated'] = $_COOKIE[$this->config->cookieid] . '|' . date('Y-m-d H:i:s', $this->config->time);
            $opr = 'update';
            $strid = array('id', $_POST['id']);
        } else {
            $thevalue['id'] = $this->__get_id_insert_value('perawatan', 'id', $this->query);
            $thevalue['inputer'] = $user['userid'];
            $thevalue['inputtime'] = date('Y-m-d H:i:s', $this->config->time);
            $this->vardump['id'] = $thevalue['id'];
            $opr = 'insert';
            $strid = array('id', $thevalue['id']);
        }
        $this->__exec_db_ops(
            $this->query,
            'perawatan',
            $opr,
            $strid,
            $thevalue
        );
        $iddata = $thevalue['id'];
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
        redirect_to('/user/perawatan/detail_form/' . $iddata);
    }
}