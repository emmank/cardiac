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
 *  pengkajianclass.php
 *  
 *  Created on Oct 3, 2009, 4:35:17 PM
 */

require_once MODULES_DIR . DS . 'pengkajian' . DS . 'config.inc';

class pengkajianModule extends mainModule
{
    var $title = 'pengkajian module';
    var $description = '';

    function menu(){
        $items['pengkajian_view'] = array(
            'title' => __t('pengkajian'),
            'description' => __t('daftar pengkajian'),
            'path' => '/care/perawatan/pengkajian',
            'exec' => 'view',
            'weight' => 5,
            'user_required' => NULL
        );
       return $items;
    }

    function __head_page($id){
        $this->sync_scheme('pengkajian', $this->query);
        $result = array();
        $sql = $this->query->getSelect(
            array(),
            array('perawatan'),
            array(
                array('&&', "id=" . $id)
            )
        );
        $this->query->connect();
        $getit = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($getit->_numOfRows > 0){
            $result = $getit->fields;
            $sql = $this->query->getSelect(
                array('nama'),
                array('patients'),
                array(
                    array('&&', "id=" . $getit->fields['patients'])
                )
            );
            $this->query->connect();
            $getthis = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            if($getthis->_numOfRows > 0){
                $result['nama'] = $getthis->fields['nama'];
            }
        }
        return $result;
    }

    function view(){
        if(isset($_POST['id'])){
            $id = $_POST['id'];
        } else {
            $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
            if(count($dump) > 3){
                $id = $dump[3];
            }
        }
        $result['perawatan'] = array(
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
            ),
            '#patientsinfo' => $this->__head_page($id)
        ); unset($addmenuopts);
        return $result;
    }

    function __form(){
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
                redirect_to('/user/perawatan/today_patient_lists');
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
        return $form;
    }

}