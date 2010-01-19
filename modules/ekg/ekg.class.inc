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
 *  ekgclass.php
 *  
 *  Created on Oct 1, 2009, 1:12:45 PM
 */

require_once MODULES_DIR . DS . 'ekg' . DS . 'config.inc';

class ekgModule extends mainModule
{
    var $title = 'ekg module';
    var $description = '';
    var $hidden_fields = array(
        'id', 'id_pasien', 'inputer','updated', 'inputtime','tgl'
    );

    function menu(){
        $items['ekg_form'] = array(
            'title' => __t('form ekg'),
            'description' => __t('formulir ekg'),
            'path' => '/user/ekg/form',
            'exec' => 'form',
            'weight' => '0',
            'user_required' => 'ekg'
        );
        $items['ekg_form_submit'] = array(
            'title' => __t('form ekg'),
            'description' => __t('formulir ekg'),
            'path' => '/user/ekg/form_submit',
            'exec' => 'form_submit',
            'weight' => '0',
            'user_required' => 'ekg'
        );
        $items['ekg_get_lists'] = array(
            'title' => __t('form ekg'),
            'description' => __t('formulir ekg'),
            'path' => '/user/ekg/today_ekg_lists',
            'exec' => '__get_today_lists',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['ekg_message'] = array(
            'title' => __t('ekg message'),
            'description' => __t('get ekg message'),
            'path' => '/user/ekg/message',
            'exec' => 'message',
            'weight' => 5,
            'user_required' => 'ekg'
        );
        $items['ekg_lists'] = array(
            'title' => __t('Formulir EKG'),
            'description' => __t('get ekg lists'),
            'path' => '/user/ekg/lists',
            'exec' => 'lists',
            'weight' => 5,
            'user_required' => 'ekg'
        );
        $items['ekg_view'] = array(
            'title' => __t('ekg'),
            'description' => __t('explore ekg'),
            'path' => '/user/ekg/view',
            'exec' => 'view',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['ekg_detail'] = array(
            'title' => __t('detail ekg'),
            'description' => __t("detail ekg's patients"),
            'path' => '/user/ekg/detail_form',
            'exec' => 'detail_form',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['ekg_search'] = array(
            'title' => __t('search ekg'),
            'description' => __t("search ekg's patients"),
            'path' => '/user/ekg/search',
            'exec' => 'search',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['ekg_search_submit'] = array(
            'title' => __t('submitted search ekg'),
            'description' => __t("submitted search ekg's patients"),
            'path' => '/user/ekg/search_submit',
            'exec' => 'search_submit',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['ekg_prescription'] = array(
            'title' => __t('ekg form') . ' ' . __t('prescription'),
            'description' => __t("form of ekg") . ' ' . __t('prescription'),
            'path' => '/user/ekg/prescription',
            'exec' => 'prescription_form',
            'weight' => '0',
            'user_required' => 'ekg'
        );
        $items['ekg_prescription_submit'] = array(
            'title' => __t('ekg form') . ' ' . __t('prescription'),
            'description' => __t("form of ekg") . ' ' . __t('prescription'),
            'path' => '/user/ekg/prescription_submit',
            'exec' => 'prescription_submit',
            'weight' => '0',
            'user_required' => 'ekg'
        );
        $items['ekg_storejpgdata'] = array(
            'title' => __t('ekg store'),
            'description' => __t("file of ekg"),
            'path' => '/user/ekg/storethis',
            'exec' => 'store_jpgdata',
            'weight' => '0',
            'user_required' => 'ekg'
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
                        array('ekg'),
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
                                $result['data'][$cnt]['links'] = '/user/ekg/detail_form/' . $getit->fields['id'];
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
        $result['title'] = __t('Cari data pasien ekg');
        $result['description'] = __t('Mencari data pasien ekg');
        $result['dataform']['character'] = array(
            '#type' => 'character'
        );
        $i = 0;
        foreach($this->config->abjad as $value){
            $result['dataform']['character']['data'][$i]['show'] = $value;
            $sql = $this->query->getSelect(
                array('ekg|id as ekg_id'),
                array('ekg', 'patients'),
                array(
                    array('&&', "ekg|patients=patients|id"),
                    array('&&', "patients|nama like '" . strtolower($value) . "%'")
                )
            );
            $this->query->connect();
            $getit = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            $result['dataform']['character']['data'][$i]['links'] = $getit->_numOfRows > 0 ? '/user/ekg/search/' . $value : NULL;
            unset($getit); $i++;
        } unset($i);
        $result['dataform']['form'] = array(
            '#type' => 'form',
            '#action' => '/user/ekg/search',
            '#id' => 'ekg_search',
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
//        echo '<pre>'; print_r($result); echo '</pre>'; //exit();
        return $result;
    }

    function __get_ekg_data($id){
        $result = array();
        $sql = $this->query->getSelect(
            array(),
            array('ekg'),
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
        $vcache = $this->__get_ekg_data((int)$dump[3]);
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
                if(preg_match('/^edit_/', $dump[3])){
                    $ekg_id = preg_replace('/^edit_/','',$dump[3]);
                    $vcache = $this->__get_ekg_data((int)$ekg_id);
                    $this->vardump = $vcache;
                    unset($ekg_id);
//                    redirect_to('/user/ekg/view');
                } else {
                    $vcache['kunjungan'] = $dump[3]; unset($dump);
                }
            } else {
                redirect_to('/user/ekg/today_ekg_lists');
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
        $rujukanopts = array(
            '' => __t('-- dirujuk ke --')
        );
        $dump_addmenus = $this->__get_bagian_lists();
        foreach($dump_addmenus as $key => $value){
            $rujukanopts[$key] = $value;
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
        $form['ekg'] = array(
            '#type' => 'special',
            '#id' => 'ekg',
            '#title' => __t('EKG'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#extraform' => 'enctype="multipart/form-data"',
            '#action' => '/user/ekg/' . ($this->formhabit == 'readonly' ? 'form/edit_' . $vcache['id'] : 'form_submit'),
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE,
            '#formtpl' => MODULES_DIR . DS . 'ekg' . DS . 'ekg.tpl',
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
        $form['ekg']['kunjungan'] = array(
            '#type' => 'hidden',
            '#value' => isset($vcache['kunjungan']) ? $vcache['kunjungan'] : ''
        );
        $thefields = $this->__get_data_fields('ekg', $this->query);
        foreach($thefields as $value){
            if(in_array($value, $this->hidden_fields)){
                if($value == 'id'){
                    $form['ekg'][$value] = array(
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
                    $form['ekg'][$value] = array(
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
                            'kelamin',
                            'gol_darah',
                            'strnum'
                        )
                    );
                    if(count($query) > 0){
                        if($this->formhabit == 'readonly'){
                            if(isset($vcache['inputtime']) && date('Y-n-j', strtotime($vcache['inputtime'])) == date('Y-n-j', $this->config->time)){
                                $getvisit_info = $this->patient_visit_lists(date('Y-m-d', $this->config->time), 'EKG', $vcache['patients']);
                                if(count($getvisit_info) > 0){
                                    foreach($getvisit_info as $ky => $vl){
                                        if(is_null($vl['doneby'])){
                                            $forbidden = 0; break;
                                        }
                                    }
                                }
                                if(!isset($forbidden)){
                                    $form['ekg']['#addmenu']['#addmenu0'] = array(
                                        'title' => __t('dirujuk ke'),
                                        'action' => '/user/patient/register_form_submit',
                                        'position' => 'top',
                                        'class' => 'button',
                                        'methode' => 'choose',
                                        'options' => $rujukanopts,
                                        'user_required' => 'ekg',
                                        'filter' => 'bagian',
                                        'items' => array (
                                            'id' => $vcache['patients'],
                                            'strnum' => $query['strnum']
                                        )
                                    );
                                    $form['ekg']['#addmenu']['#prescription'] = array(
                                        'title' => __t('prescription'),
                                        'action' => '/user/ekg/prescription/' . $vcache['id'],
                                        'position' => 'top',
                                        'class' => 'button',
                                        'user_required' => 'ekg',
                                        'filter' => 'items',
                                        'items' => array (
                                            'id' => $vcache['id']
                                        )
                                    );
                                } else {
                                    unset($forbidden);
                                }
                            }
                            $form['ekg']['#addmenu']['#printed'] = array(
                                'title' => __t('print'),
                                'action' => '/user/ekg/report',
                                'position' => 'top',
                                'class' => 'button',
                                'user_required' => 'ekg',
                                'filter' => 'items',
                                'items' => array (
                                    'id' => $vcache['id']
                                )
                            );
                            $checkmyfile = $this->__check_myfile($vcache['id']);
//                            echo "<pre>vcache File : ";print_r($vcache['file']);echo "</pre>";
                            $form['ekg']['#addmenu']['#file'] = array(
                                'title' => ($checkmyfile !== FALSE ? __t('show') : __t('get')) . ' ' . __t('file'),
                                'action' => $checkmyfile !== FALSE ? $vcache['file'] : '/user/ekg/storethis',
                                'position' => 'top',
                                'class' => 'button',
                                'user_required' => 'ekg',
                                'filter' => 'items',
                                'items' => array (
                                    'id' => $vcache['id']
                                )
                            );

//                            echo "<pre>Show File : ";print_r($form['ekg']['#addmenu']['#file']);echo "</pre>";
                            if($checkmyfile !== FALSE){
                                $form['ekg']['#addmenu']['#file']['extraform']='target="_blank"';
                            } else {
                                $form['ekg']['#addmenu']['#uploadfile'] = array(
                                    'title' => __t('upload'),
                                    'action' => '/user/ekg/storethis',
                                    'extraform' => 'enctype="multipart/form-data"',
                                    'position' => 'top',
                                    'class' => 'button',
                                    'user_required' => 'ekg',
                                    'filter' => 'items',
                                    'items' => array (
                                        'id' => $vcache['id'],
                                        'MAX_FILE_SIZE' => 80000,
                                        'filedigital' => array(
                                            'type' => 'file',
                                            'value' => ''
                                        )
                                    )
                                );
                            } unset($checkmyfile);
                        } unset($rujukanopts);
                        foreach($query as $ky => $vl){
                            if($ky == 'tgl_lahir'){
//                                $vl = $this->agecount_in_month(strtotime($vl));
//                                $vl = round(($this->agecount_in_month(strtotime($vl))/12),0);
//                                $form['ekg']['umur'] = array(
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
                                    } elseif($ky == 'strnum'){
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
                                    $form['ekg'][$ky] = array(
                                        '#type' => $ky == 'alamat' ? 'textarea' : 'info',
                                        '#value' => $vl,
                                        '#title' => __t($ky),
                                        '#tbpos' => $tbpos
                                    );
                                    if($ky == 'alamat'){
                                        $form['ekg'][$ky]['#extra'] = 'readonly="true"';
                                        $form['ekg'][$ky]['#cols'] = '55';
                                        $form['ekg'][$ky]['#rows'] = '3';
                                    } elseif($ky == 'no_registrasi'){
                                        $form['ekg'][$ky]['#link'] = '/user/ekg/today_patient_lists';
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
                        $form['ekg']['kunjungan_ke'] = array(
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
                        $form['ekg']['pengirim'] = array(
                            '#type' => 'info',
                            '#value' => $getsender->fields['nama'],
                            '#title' => __t('pengirim'),
                            '#tbpos' => 7
                        );
                        unset($getsender);
                    }
                }
                if($value != 'no_registrasi' && $value != 'kunjungan' && $value != 'patients' && $value != 'file'){
                    $form['ekg'][$value] = array(
                        '#type' => $this->config->fields_form_type[$value],
                        '#value' => isset($vcache[$value]) ? $vcache[$value] : '',
                        '#size' => $this->config->fields_form_type[$value] != 'select' && $this->config->fields_form_type[$value] != 'date' ? 20 : 1,
                        '#title' => __t($value),
                        '#error' => isset($vcache['blank']) && in_array($value, $vcache['blank']) ? 1 : 0
                    );
                    if(in_array($value, $this->config->fieldsisarray)){
                        $form['ekg'][$value]['#theref'] = $this->__get_refs($value);
                    }
                    if(in_array($value, $this->config->qrs_complex) || in_array($value, $this->config->segment_st) || $value == 'gelombang_t'){
                        $form['ekg'][$value]['#customized']['title'] = in_array($value, $this->config->qrs_complex) ? __t('qrs_complex') : ($value == 'gelombang_t' ? __t('gelombang_t') : __t('segment_st'));
                        $form['ekg'][$value]['#customized']['id'] = in_array($value, $this->config->qrs_complex) ? 'qrs_complex' : ($value == 'gelombang_t' ? 'gelombang_t' : 'segment_st');
                        if($this->config->fields_form_type[$value] == 'select2'){
                            $form['ekg'][$value]['#customized']['option'] =  array(
                                '1mm - 2mm' => '1mm - 2mm',
                                '> 2mm - 3mm' => '> 2mm - 3mm',
                                '> 3mm' => '> 3mm'
                            );
                        } elseif ($this->config->fields_form_type[$value] == 'select3') {
                            $form['ekg'][$value]['#customized']['option'] =  array(
                                'Q Patologi +' => 'Q Patologi +',
                                'Q Patologi -' => 'Q Patologi -'
                            );
                        } elseif ($value == 'gelombang_t') {
                            $form['ekg'][$value]['#customized']['option'] =  array(
                                'Normal' => 'Normal',
                                'Inverted' => 'Inverted'
                            );
                        }
                    }
                }
                if($this->formhabit == 'readonly'){
                    $form['ekg'][$value]['#readonly'] = TRUE;
                }
            }
        }

        if($this->formhabit != 'readonly'){
            $form['ekg']['MAX_FILE_SIZE'] = array(
                '#type' => 'hidden',
                '#value' => '80000'
            );
            $form['ekg']['filedigital'] = array(
                '#title' => __t('upload file'),
                '#type' => 'file'
            );
        }
        $form['ekg']['submit'] = array(
            '#type' => 'submit',
            '#value' => ($this->formhabit == 'readonly' ? __t('edit') : __t('submit'))
        );
        if ($this->formhabit == 'readonly'){
            if(isset($vcache['inputtime']) && date('Y-n-j', strtotime($vcache['inputtime'])) == date('Y-n-j', $this->config->time)){
                $getvisit_info = $this->patient_visit_lists(date('Y-m-d', $this->config->time), 'EKG', $vcache['patients']);
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
                $form['ekg']['submit']['#extra'] = ' disabled="true"';
                unset($forbidden);
            }
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
            'tgl' => date('Y-m-d', strtotime($query->fields['pukul']))
        );
        unset($query);
        $thefields = $this->__get_data_fields('ekg', $this->query);
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
        $user = $this->__get_user_info();
        if($_POST['id'] != ''){
            $thevalue['updated'] = $user['userid'] . '|' . date('Y-m-d H:i:s', $this->config->time);
            $opr = 'update';
            $strid = array('id', $_POST['id']);
        } else {
            $thevalue['id'] = $this->__get_id_insert_value('ekg', 'id', $this->query);
            $thevalue['inputer'] = $user['id'];
            $thevalue['inputtime'] = date('Y-m-d H:i:s', $this->config->time);
            $this->vardump['id'] = $thevalue['id'];
            $opr = 'insert';
            $strid = array('id', $thevalue['id']);
        }
//        echo "<pre>";print_r($thevalue);echo "</pre>";
        $this->__exec_db_ops(
            $this->query,
            'ekg',
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
//            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        $this->__flush_caches();
        $this->store_jpgdata($iddata, 1);
        redirect_to('/user/ekg/detail_form/' . $iddata);
    }

    function view(){
        return $this->__get_today_lists();
    }

    function lists(){
        $this->sync_scheme('ekg', $this->query);
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('daftar beberapa pasien');
        $result['description'] = __t('daftar beberapa pasien terakhir yang telah diperiksa');
        $result['addmenu']['#add'] = array(
            'title' => __t('add'),
            'action' => '/user/ekg/form',
            'position' => 'top',
            'user_required' => 'users'
        );
        $result['addmenu']['#search'] = array(
            'title' => __t('search'),
            'action' => '/user/ekg/search',
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
            array('ekg'),
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
                $result['data'][$i]['goto'] = '/user/ekg/detail_form/' . $getit->fields['id'];
                $result['data'][$i]['inputtime'] = date('j-n-Y H:i:s', strtotime($getit->fields['inputtime']));
                $getit->MoveNext();
            }
        }
        return $result;
    }

    function __check_ekgdir(){
        $ekgdir = __get_file_lists($_SERVER['DOCUMENT_ROOT'] . DS . $this->config->ekgdata_dir);
        if(!in_array(date('Ymd', $this->config->time), $ekgdir)){
            mkdir($_SERVER['DOCUMENT_ROOT'] . DS . $this->config->ekgdata_dir . DS . date('Ymd', $this->config->time), 0700);
        } unset($ekgdir);
    }

//    function __sync_ekg_data(){
//        //updating data
//        $this->__check_ekgdir();
//        shell_exec('rsync --progress --stats -axvl root@' . $this->config->source_server . ':/' . $this->config->source_path . '/ ' . $this->config->ekgdata_dir . '/' . date('Ymd', $this->config->time) . '/');
//    }

    function __get_datadigital($id){
        $this->__sync_ekg_data();
        $getdataarray = __get_file_lists($_SERVER['DOCUMENT_ROOT'] . DS . $this->config->ekgdata_dir . '/' . date('Ymd', $this->config->time));
        $arraydata = array();
        foreach($getdataarray as $key => $value){
            if(preg_match("/^$id/", $value)){
                $dump = explode('.', $value);
                $arraydata[] = $dump[0];
                unset($dump);
            }
        }
        if(count($arraydata) > 0){
            rsort($arraydata);
            $filetarget = $arraydata[0];
            unset($arraydata);
            return $filetarget . '.' . $this->config->filedata_extension;
        } else {
            return FALSE;
        }
    }

    function __check_myfile($id){
        $sql = $this->query->getSelect(
                array('file'),
                array('ekg'),
                array(
                    array('&&', "id=" . $id)
                )
        );
        $this->query->connect();
        $getit = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($getit->_numOfRows < 1){
            return FALSE;
        } elseif(is_null($getit->fields['file'])){
            return FALSE;
        } elseif(trim($getit->fields['file']) == ''){
            return FALSE;
        } else {
            return TRUE;
        }
    }

    function __store_uploadedfile(){
        $this->__check_ekgdir();
//        $_FILES['filedigital']['tmp_name'];
        if (move_uploaded_file($_FILES['filedigital']['tmp_name'], $_SERVER['DOCUMENT_ROOT'] . DS . $this->config->ekgdata_dir . DS . date('Ymd', $this->config->time) . DS . basename($_FILES['filedigital']['name']))) {
            return basename($_FILES['filedigital']['name']);
        } else {
            return FALSE;
        }
        
    }

    function store_jpgdata($storeid = NULL, $free = NULL){
        if(is_null($storeid)){
            if(isset($_POST['id'])){
                $id = $_POST['id'];
            }
        } else {
            $id = $storeid;
        }
        $sql = $this->query->getSelect(
                array('patients|strnum as patients'),
                array('ekg', 'patients'),
                array(
                    array('&&', "ekg|id=" . $id),
                    array('&&', "ekg|patients=patients|id")
                )
        );
        $this->query->connect();
        $this->query->conn->debug=true;
        $getthis = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($getthis->_numOfRows > 0){
            if(!isset($_FILES)){
                $filetarget = $this->__get_datadigital($getthis->fields['patients']);
            } else {
                $filetarget = $this->__store_uploadedfile();
            }
//            echo "<pre>file target : ";print_r($_FILES);echo "</pre>";
//            if ($_FILES["file"]["error"] > 0){
//                  echo "Error: " . $_FILES["filedigital"]["error"] . "<br />";
//            } else {
//                  echo "Upload: " . $_FILES["filedigital"]["name"] . "<br />";
//                  echo "Type: " . $_FILES["filedigital"]["type"] . "<br />";
//                  echo "Size: " . ($_FILES["filedigital"]["size"] / 1024) . " Kb<br />";
//                  echo "Stored in: " . $_FILES["filedigital"]["tmp_name"];
//            }
            if($this->__check_myfile($id) === FALSE && $filetarget !== FALSE){
                $sql = $this->query->updateData(
                        'ekg',
                        array(
                            'file' => $this->config->ekgdata_dir . DS . date('Ymd', $this->config->time) . DS . $filetarget
                        ),
                        array(
                            array('&&', "id=" . $id)
                        )
                );
                $this->query->connect();
                $this->query->conn->Execute($sql); unset($sql);
                $this->query->close();
            } unset($filetarget);
        } unset($getthis);
        if(is_null($free)){
            redirect_to(DS . 'user' . DS . 'ekg' . DS . 'detail_form' . DS . $id);
        }
    }

}