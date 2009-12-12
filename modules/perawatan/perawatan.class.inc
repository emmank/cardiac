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
    var $description = 'Manajemen data digital pasien perawatan';

    function menu(){
        $items['perawatan_register'] = array(
            'title' => __t('Registrasi Perawatan'),
            'description' => __t('Registrasi Pendaftaran Pasien Rawat Inap'),
            'path' => '/user/perawatan/form',
            'exec' => 'form',
            'weight' => '0',
            'user_required' => 'perawatan'
        );
        $items['perawatan_daftar'] = array(
            'title' => __t('perawatan'),
            'description' => __t('Daftar Pasien Rawat Inap'),
            'path' => '/user/perawatan/list',
            'exec' => 'view',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['perawatan_search'] = array(
            'title' => __t('Cari Pasien'),
            'description' => __t('Cari Pasien Rawat Inap'),
            'path' => '/care/perawatan/search',
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
        return $items;
    }

    function view(){
        $this->sync_scheme('perawatan', $this->query);
        $this->sync_scheme('ruang', $this->query);
        return $this->__get_view();
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
                    array('id', 'nama', 'tgl_lahir', 'pukul_masuk'),
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
                $result['data'][$i]['goto'] = '/care/perawatan/detail_form/' . $getit->fields['id'];
                $result['data'][$i]['pukul_masuk'] = date('j-n-Y H:i:s', strtotime($getit->fields['pukul_masuk']));
                $getit->MoveNext();
            }
        }
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
            $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
            if(count($dump) > 3){
                $vcache['kunjungan'] = $dump[3]; unset($dump);
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
        $form['perawatan'] = array(
            '#type' => 'special',
            '#id' => 'perawatan',
            '#title' => __t('perawatan'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/user/perawatan/' . ($this->formhabit == 'readonly' ? 'form/edit_' . $vcache['id'] : 'form_submit'),
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
                ),
                '#addmenu0' => array(
                    'title' => __t('dirujuk ke'),
                    'action' => '/user/patient/register_form_submit',
                    'position' => 'top',
                    'class' => 'button',
                    'methode' => 'choose',
                    'options' => $rujukanopts,
                    'user_required' => 'ekg',
                    'filter' => 'bagian',
                    'items' => array(
                        'id' => $vcache['patients'],
                        'strnum' => $vcache['strnum']
                    )
                )
            )
        ); unset($addmenuopts, $rujukanopts);
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
                                $vl = $this->agecount_in_month(strtotime($vl));
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
                                        $form['perawatan'][$ky]['#link'] = '/care/perawatan/today_patient_lists';
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
                }
                if($value != 'no_registrasi' && $value != 'kunjungan' && $value != 'patients'){
                    $form['perawatan'][$value] = array(
                        '#type' => $this->config->fields_form_type[$value],
                        '#value' => isset($vcache[$value]) ? $vcache[$value] : '',
                        '#size' => $this->config->fields_form_type[$value] != 'select' && $this->config->fields_form_type[$value] != 'date' ? 20 : 1,
                        '#title' => __t($value),
                        '#error' => isset($vcache['blank']) && in_array($value, $vcache['blank']) ? 1 : 0
                    );
                    if(in_array($value, $this->config->fieldsisarray)){
                        $form['perawatan'][$value]['#theref'] = $this->__get_refs($value);
                    }
                }
                if($this->formhabit == 'readonly'){
                    $form['perawatan'][$value]['#readonly'] = TRUE;
                }
            }
        }

        $form['perawatan']['submit'] = array(
            '#type' => 'submit',
            '#value' => ($this->formhabit == 'readonly' ? __t('back') : __t('submit'))
        );
        return $form;
    }

}