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
 *  patientclass.php
 *  
 *  Created on Sep 27, 2009, 2:23:27 PM
 */

require_once MODULES_DIR . DS . 'patient' . DS . 'config.inc';

class patientModule extends mainModule
{
    var $title = 'patient';
    var $description = 'Pengelola data pasien mulai dari pendaftaran s.d. registrasi';
    var $hidden_fields = array(
        'id', 'nomor', 'inputer', 'inputtime', 'updated', 'sandi', 'sesi', 'timelog', 'groups', 'strnum', 'foto'
    );
    var $formtype_fields = array(
        'id' => 'hidden',
        'nomor' => 'hidden',
        'nama' => 'text',
        'kelamin' => 'select',
        'tp_lahir' => 'text',
        'tgl_lahir' => 'date',
        'gol_darah' => 'text',
        'alamat' => 'textarea',
        'kota' => 'select',
        'propinsi' => 'select',
        'kode_pos' => 'text',
        'no_tlp' => 'text',
        'no_hp' => 'text',
        'no_identitas' => 'text',
        'sandi' => 'password',
        'status' => 'select',
        'nama_suami_istri' => 'text',
        'pekerjaan_suami_istri' => 'text',
        'foto' => 'hidden',
        'pekerjaan' => 'text',
        'pendidikan' => 'text',
        'agama' => 'select',
        'suku' => 'text',
        'nama_ayah' => 'text',
        'pekerjaan_ayah' => 'text',
        'nama_ibu' => 'text',
        'pekerjaan_ibu' => 'text',
        'inputtime' => 'hidden',
        'sesi' => 'hidden',
        'timelog' => 'hidden',
        'strnum' => 'text',
        'groups' => 'hidden',
        'inputer' => 'hidden',
        'updated' => 'hidden'
    );

    function menu(){
        $items['patient_lists'] = array(
            'title' => __t('patient lists'),
            'description' => __t('lists of patient'),
            'path' => '/node/patient',
            'exec' => 'view',
            'weight' => 5,
            'user_required' => FALSE
        );
        $items['patient_form'] = array(
            'title' => __t('patient form'),
            'description' => __t('patient check form'),
            'path' => '/node/patient/form',
            'exec' => 'form',
            'weight' => 5,
            'user_required' => FALSE
        );
        $items['patient_form_submit'] = array(
            'title' => __t('patient form'),
            'description' => __t('patient check form'),
            'path' => '/node/patient/form_submit',
            'exec' => 'form_submit',
            'weight' => 5,
            'user_required' => FALSE
        );
        $items['patient_strnum'] = array(
            'title' => __t('Get Strnum Form'),
            'description' => __t('patient get strnum form'),
            'path' => '/node/patient/strnumform',
            'exec' => 'strnum_form',
            'weight' => 5,
            'user_required' => FALSE
        );
        $items['patient_strnumset'] = array(
            'title' => __t('Get Strnum'),
            'description' => __t('patient get strnum info'),
            'path' => '/node/patient/setstrnum',
            'exec' => 'setstrnum',
            'weight' => 5,
            'user_required' => FALSE
        );
        $items['patient_showme'] = array(
            'title' => __t('Patient Detail'),
            'description' => __t('get patient detail info'),
            'path' => '/node/patient/showme',
            'exec' => 'showme',
            'weight' => 5,
            'user_required' => FALSE
        );
        $items['patient_register'] = array(
            'title' => __t('Patient Register'),
            'description' => __t('register patient into database'),
            'path' => '/user/patient',
            'exec' => 'register',
            'weight' => 5,
            'user_required' => 'patient'
        );
        $items['register_form'] = array(
            'title' => __t('Patient Register'),
            'description' => __t('execute registering patient into database'),
            'path' => '/user/patient/register',
            'exec' => 'register_form',
            'weight' => 5,
            'user_required' => 'patient'
        );
        $items['register_form_submit'] = array(
            'title' => __t('Patient Register'),
            'description' => __t('execute registering patient into database'),
            'path' => '/user/patient/register_form_submit',
            'exec' => 'register_submit',
            'weight' => 5,
            'user_required' => 'patient'
        );
        return $items;
    }

    function register(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('daftar pasien yang mendaftar hari ini');
        $result['description'] = __t('antrian pasien yang mendaftar pada hari ini');
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
                'width' => '25%',
                'align' => 'left'
            ),
            array(
                'field' => 'tgl_lahir',
                'caption' => __t('usia'),
                'width' => '10%',
                'align' => 'right'
            ),
            array(
                'field' => 'alamat',
                'caption' => __t('alamat'),
                'align' => 'left'
            )
        );

        $thedir = $this->__set_dqueue();
        $lists = __get_file_lists($thedir);
        if(count($lists) > 0){
            sort($lists); $i = 0;
            foreach($lists as $key => $value){
                $handle = fopen($thedir . DS . $value, 'r');
                while (!feof($handle)){
                    $buffer = fgets($handle);
                    if(trim($buffer) != ''){
                        list($ky, $vl) = explode('=>', trim($buffer));
                        if($ky == 'nama' || $ky == 'tgl_lahir' || $ky == 'alamat'){
                            if($ky == 'tgl_lahir'){
                                $vl = number_format(round($this->agecount_in_month(strtotime($vl))/12, 1), 1, ',','.') . ' th';
                            }
                            $result['data'][$i][$ky] = $vl;
                        }
                    }
                }
                $result['data'][$i]['goto'] = '/user/patient/register/' . $value;
                $i++;
                fclose($handle); unset($handle);
            }
        }
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function register_form(){
        if (is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        } else {
            $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
            if(isset($dump[3])){
                $filename = $dump[3];
                $filedump = $this->__set_dqueue() . DS . $filename;
                $vcache['fqueue'] = $filename;
                if(is_file($filedump)){
                    $handle = fopen($filedump, 'r');
                    while (!feof($handle)){
                        $buffer = fgets($handle);
                        if(trim($buffer) != ''){
                            list($key, $value) = explode('=>', trim($buffer));
                            $vcache[$key] = $value;
                            unset($key, $value);
                        } unset($buffer);
                    }
                    fclose($handle); unset($handle);
                }
            } unset($dump[3]);
            $this->query->connect();
            $sql = $this->query->getSelect(
                array(),
                array('patients'),
                array(
                    array('&&', "strnum=" . $vcache['strnum'])
                )
            );
            $query = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            if($query->_numOfRows > 0){
                foreach($query->fields as $key => $value){
                    if(!isset($vcache[$key]) || $vcache[$key] == ''){
                        $vcache[$key] = $value;
                    } elseif($value != $vcache[$key]){
                        if(!isset($warning)){$warning = array();}
                        $warning[$key] = $value;
                    }
                }
            }
        }
            $form['patient'] = array(
                '#type' => 'fieldset',
                '#id' => 'patient',
                '#title' => __t('patient'),
                '#collapsible' => TRUE,
                '#collapsed' => FALSE,
                '#weight' => -3,
                '#action' => '/user/patient/register_form_submit',
                '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE,
                '#focused_item' => 'nama'
            );
            $datafields = $this->__get_data_fields('patients', $this->query);
            if(count($datafields) > 0){
                foreach($datafields as $value){
                    if(!in_array($value, $this->hidden_fields)){
                        $form['patient'][$value] = array(
                            '#type' => $this->formtype_fields[$value],
                            '#title' => __t($value),
                            '#value' => (isset($vcache[$value]) ? $vcache[$value] : '') . (isset($warning[$key]) ? ' &laquo; ' . __t('update from old value') . ' ' . $warning[$key] : ''),
                            '#error' => isset($vcache['blank']) && in_array($value, $vcache['blank']) ? 1 : 0
                        );
                    } elseif($value == 'id'){
                        $form['patient'][$value] = array(
                            '#type' => $this->formtype_fields[$value],
                            '#title' => __t($value),
                            '#value' => isset($vcache[$value]) ? $vcache[$value] : '',
                            '#error' => isset($vcache['blank']) && in_array($value, $vcache['blank']) ? 1 : 0
                        );
                    }
                    if($this->formtype_fields[$value] == 'select' || $this->formtype_fields[$value] == 'date'){
                        if($value == 'kelamin') {
                            $options = $this->__get_kelamin_options();
                        } elseif($this->formtype_fields[$value] == 'date'){
                            $options = $this->nama_bulan;
                        }
                        $form['patient'][$value]['#option'] = $options;
                    } elseif($value == 'strnum'){
                        $form['patient'][$value]['#extra'] = 'readonly="true"';
                    }
                } unset($options);
                $form['patient']['keluhan'] = array(
                    '#type' => 'textarea',
                    '#value' => isset($vcache['keluhan']) ? $vcache['keluhan'] : '',
                    '#title' => __t('keluhan'),
                    '#error' => isset($vcache['blank']) && in_array('keluhan', $vcache['blank']) ? 1 : 0
                );
                $options = $this->__get_bagian_lists();
                $form['patient']['rujukan'] = array(
                    '#type' => 'select',
                    '#value' => isset($vcache['rujukan']) ? $vcache['rujukan'] : '',
                    '#title' => __t('rujukan'),
                    '#error' => isset($vcache['blank']) && in_array('rujukan', $vcache['blank']) ? 1 : 0,
                    '#option' => $options,
                    '#option_blank' => 1
                ); unset($options);
                $form['patient']['fqueue'] = array(
                    '#type' => 'hidden',
                    '#value' => isset($vcache['fqueue']) ? $vcache['fqueue'] : ''
                );
                $form['patient']['submit'] = array(
                    '#type' => 'submit',
                    '#value' => __t('register'),
    //                '#title' => __t('&nbsp;'),
                    '#extra' => ' class="button"'
               );
            }
            return $form;
    }

    function register_submit(){
        $dump = $this->__write_form_cache();
        $thevalue = array();
        foreach($dump as $key => $value){
            if($key == 'nama' || $key == 'alamat' || $key == 'kota' || $key == 'rujukan'){
                if(trim($value) == ''){
                    $this->__write_custom_cache(array('error=>' . __t('Kolom nama, alamat, kota, dan rujukan tidak boleh kosong !')), 1);
                    redirect_to('/user/patient/register'); exit;
                }
            } elseif ($key == 'date'){
                $tgldump = explode('-', trim($value));
                foreach($tgldump as $ky => $vl){
                    if(trim($vl) == ''){
                        $this->__write_custom_cache('error=>' . __t('Kolom tanggal tidak boleh kosong !'), 1);
                        redirect_to('/user/patient/register'); exit;
                    } elseif(!ctype_digit($vl)){
                        $this->__write_custom_cache('error=>' . __t('Kolom tanggal harus numeric !'), 1);
                        redirect_to('/user/patient/register'); exit;
                    }
                }
                if(checkdate((int)$tgldump[1], (int)$tgldump[2], (int)$tgldump[0]) === false){
                    $this->__write_custom_cache('error=>' . __t('Format tanggal salah !'), 1);
                    redirect_to('/user/patient/register'); exit;
                } unset($tgldump);
            }
            if($key != 'submit' && $key != 'blank' && $key != 'keluhan' && $key != 'rujukan' && $key != 'id' && $key != 'fqueue'){
                $thevalue[$key] = $value;
            }
        }
        if(trim($dump['id']) == ''){
            $nom = 1;
            $this->query->connect();
            $sql = $this->query->getSelect(
                array('max(nomor) as no'),
                array('patients')
            );
            $query = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            if($query->_numOfRows > 0){
                $nom += $query->fields['no'];
            }
            $thevalue['nomor'] = $nom;
            $thevalue['strnum'] = str_repeat('0', $this->config->digit_of_number - strlen($nom)) . $nom;
            unset($nom);
            $dump['id'] = $this->__get_id_insert_value('patients', 'id', $this->query);
            $thevalue['id'] = $dump['id'];
            $thevalue['inputer'] = $_COOKIE[$this->config->cookieid];
            $thevalue['inputtime'] = date('Y-m-d H:i:s', $this->config->time);
            $sql = $this->query->saveData(
                'patients',
                $thevalue
            );
        } else {
            $thevalue['updated'] = $_COOKIE[$this->config->cookieid] . '|' . date('Y-m-d H:i:s', $this->config->time);
            $sql = $this->query->updateData(
                'patients',
                $thevalue,
                array(
                    array('&&', "id=" . $dump['id'])
                )
            );
        }
        $this->query->connect();
//        $this->query->conn->debug=true;
        $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        unset($thevalue);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('bagian'),
            array('bagian'),
            array(
                array('&&', "id=" . $dump['rujukan'])
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        $bagian = $query->fields['bagian']; unset($query);
        $this->query->connect();
        $no = 1;
        $sql = $this->query->getSelect(
            array('max(nourut) as no'),
            array('kunjungan'),
            array(
                array('&&', "bagian=" . $bagian),
                array('&&', "year(pukul)=" . date('Y', $this->config->time)),
                array('&&', "month(pukul)=" . date('n', $this->config->time)),
                array('&&', "day(pukul)=" . date('j', $this->config->time))
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            $no += $query->fields['no'];
        } unset($query);
        $thevalue = array(
            'pukul' => date('Y-m-d H:i:s', $this->config->time),
            'patients' => $dump['id'],
            'bagian' => $bagian,
            'nourut' => $no,
            'keluhan' => $dump['keluhan'],
            'inputer' => $_COOKIE[$this->config->cookieid]
        );
        $thevalue['id'] = $this->__get_id_insert_value('kunjungan', 'id', $this->query);
        $this->query->connect();
        $sql = $this->query->saveData(
            'kunjungan',
            $thevalue
        );
        $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        $dirqueue = $this->__set_dqueue();
        unlink($dirqueue . DS . $dump['fqueue']);
        unlink($this->config->fcache);
        unset($dump, $dirqueue);
        redirect_to('/user/patient');
    }

    function __clean_queue(){
        $dirqueue = FILES_DIR . DS . 'queue';
        $getlists = __get_file_lists($dirqueue);
        foreach($getlists as $key => $value){
            if(strtotime($value) < ($this->config->time - 86400)){
                $dirdrop = $dirqueue . DS . $value;
                __remove_folder($dirdrop . DS . 'increment');
            }
        }
    }

    function view(){
        $this->__clean_queue();
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('daftar pasien yang mendaftar hari ini');
        $result['description'] = __t('antrian pasien yang mendaftar pada hari ini');
        $result['addmenu'] = array(
            'title' => __t('add patient'),
            'action' => '/node/patient/form',
            'position' => 'top'
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
                'width' => '25%',
                'align' => 'left'
            ),
            array(
                'field' => 'tgl_lahir',
                'caption' => __t('usia'),
                'width' => '10%',
                'align' => 'right'
            ),
            array(
                'field' => 'alamat',
                'caption' => __t('alamat'),
                'align' => 'left'
            )
        );

        $thedir = $this->__set_dqueue();
        $lists = __get_file_lists($thedir);
        if(count($lists) > 0){
            sort($lists); $i = 0;
            foreach($lists as $key => $value){
                $handle = fopen($thedir . DS . $value, 'r');
                while (!feof($handle)){
                    $buffer = fgets($handle);
                    if(trim($buffer) != ''){
                        list($ky, $vl) = explode('=>', trim($buffer));
                        if($ky == 'nama' || $ky == 'tgl_lahir' || $ky == 'alamat'){
                            if($ky == 'tgl_lahir'){
                                $vl = number_format(round($this->agecount_in_month(strtotime($vl))/12, 1), 1, ',','.') . ' th';
                            }
                            $result['data'][$i][$ky] = $vl;
                        }
                    }
                }
                $result['data'][$i]['goto'] = '/node/patient/showme/' . $value;
                $i++;
                fclose($handle); unset($handle);
            }
        }
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function showme(){
//        echo 'here';
        $result = array();
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
//        echo '<pre>'; print_r($dump); echo '</pre>';
        if(isset($dump[3])){
            $filename = $dump[3];
            $filename = FILES_DIR . DS . 'queue' . DS . date('Y-m-d', $this->config->time) . DS . 'queue' . DS . $filename;
            if(is_file($filename)){
                $thevalue = $this->__read_queue($filename);
                $result['type'] = 'items_detail';
                $result['title'] = __t('detil pasien');
                $result['description'] = __t('informasi detil pasien terpilih yang mendaftar antrian');
                $result['id'] = $thevalue['number'];
                $result['dropable'] = '0';
                $result['message'] = $thevalue['number'];
                foreach($thevalue as $key => $value){
                    if($key == 'kelamin'){
                        $value = __t($this->kelamin[$value]);
                    } elseif($key == 'tgl_lahir'){
                        $usia = floor($this->agecount_in_month(strtotime($value))/12) . 'th ' . (($this->agecount_in_month(strtotime($value))%12) > 0 ? ($this->agecount_in_month(strtotime($value))%12) . 'bl' : '');
                        $value = date('j-n-Y', strtotime($value));
                        $value .= ' (' . $usia . ')';
                        unset($usia);
                    } elseif($key == 'rujukan'){
                        $options = $this->__get_bagian_lists();
                        $value = $options[$value];
                        unset($options);
                    }
                    $result['data'][$key] = array(
                        'key' => __t($key),
                        'value' => $value,
                        'hide' => in_array($key, $this->hidden_fields) ? 1 : 0
                    );
                }
            } else {
                redirect_to('/node/patient');
            }
        } else {
            redirect_to('/node/patient');
        } unset($dump);
        return $result;
    }

    function strnum_form(){
        $form['patient'] = array(
            '#type' => 'fieldset',
            '#id' => 'patient',
            '#title' => __t('patient'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/node/patient/setstrnum',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE,
            '#focused_item' => 'strnum'
        );
        $form['patient']['strnum'] = array(
            '#type' => 'text',
            '#title' => __t('strnum'),
            '#size' => 15,
            '#message' => __t('&laquo; kosongkan bila Anda adalah pasien baru')
        );
        $form['patient']['submit'] = array(
            '#type' => 'submit',
            '#value' => __t('submit'),
            '#extra' => ' class="button"'
        );
        return $form;
    }

    function setstrnum(){
        $dump = $this->__write_form_cache();
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('patients'),
            array(
                array('&&', "strnum=" . $dump['strnum'])
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            $str = array();
            foreach($query->fields as $key => $value){
                $str[$key] = $value;
            }
            $this->__write_custom_cache($str, 1);
            unset($str);
        }
        redirect_to('/node/patient/form');
    }

    function form(){
        if($this->__check_caches() === true){
            $vcache = $this->__read_form_cache();
//            unlink($this->config->fcache);
//            echo '<pre>'; print_r($vcache); echo '</pre>';
        }
        if(!isset($vcache['strnum'])){
            redirect_to('/node/patient/strnumform'); exit;
        } else {
            if(!isset($vcache['nama'])){$vcache['strnum'] = '';}
            elseif($vcache['nama'] == ''){$vcache['strnum'] = '';}
        }
            $form['patient'] = array(
                '#type' => 'fieldset',
                '#id' => 'patient',
                '#title' => __t('patient'),
                '#collapsible' => TRUE,
                '#collapsed' => FALSE,
                '#weight' => -3,
                '#action' => '/node/patient/form_submit',
                '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE,
                '#focused_item' => 'nama'
            );
            $datafields = $this->__get_data_fields('patients', $this->query);
            if(count($datafields) > 0){
                foreach($datafields as $value){
                    if(!in_array($value, $this->hidden_fields)){
                        $form['patient'][$value] = array(
                            '#type' => $this->formtype_fields[$value],
                            '#title' => __t($value),
                            '#value' => isset($vcache[$value]) ? $vcache[$value] : '',
                            '#error' => isset($vcache['blank']) && in_array($value, $vcache['blank']) ? 1 : 0
                        );
                    } elseif($value == 'id'){
                        $form['patient'][$value] = array(
                            '#type' => $this->formtype_fields[$value],
                            '#title' => __t($value),
                            '#value' => isset($vcache[$value]) ? $vcache[$value] : '',
                            '#error' => isset($vcache['blank']) && in_array($value, $vcache['blank']) ? 1 : 0
                        );
                    }
                    if($this->formtype_fields[$value] == 'select' || $this->formtype_fields[$value] == 'date'){
                        if($value == 'kelamin') {
                            $options = $this->__get_kelamin_options();
                        } elseif($this->formtype_fields[$value] == 'date'){
                            $options = $this->nama_bulan;
                        } elseif($value == 'status'){
                            $options = $this->__get_statusm_options();
                        } elseif($value == 'kota'){
                            $options = $this->__get_kabupaten_options('kabupaten');
                        } elseif($value == 'propinsi'){
                            $options = $this->__get_propinsi_options('nama_propinsi');
                        } elseif($value == 'agama'){
                            $options = $this->__get_agama_options();
                        }
                        $form['patient'][$value]['#option'] = $options;
                    } elseif($value == 'strnum'){
                        $form['patient'][$value]['#extra'] = 'readonly="true"';
                    }
                } unset($options);
                $form['patient']['keluhan'] = array(
                    '#type' => 'textarea',
                    '#value' => isset($vcache['keluhan']) ? $vcache['keluhan'] : '',
                    '#title' => __t('keluhan'),
                    '#error' => isset($vcache['blank']) && in_array('keluhan', $vcache['blank']) ? 1 : 0
                );
                $options = $this->__get_bagian_lists();
                $form['patient']['rujukan'] = array(
                    '#type' => 'select',
                    '#value' => isset($vcache['rujukan']) ? $vcache['rujukan'] : '',
                    '#title' => __t('rujukan'),
                    '#error' => isset($vcache['blank']) && in_array('rujukan', $vcache['blank']) ? 1 : 0,
                    '#option' => $options,
                    '#option_blank' => 1
                ); unset($options);
                $form['patient']['submit'] = array(
                    '#type' => 'submit',
                    '#value' => __t('submit'),
    //                '#title' => __t('&nbsp;'),
                    '#extra' => ' class="button"'
               );
            }
            return $form;
    }

    function form_submit(){
        $dump = $this->__write_form_cache();
        $thevalue = array();
        foreach($dump as $key => $value){
            if($key == 'nama' || $key == 'alamat' || $key == 'kota'){
                if($value == ''){
                    $this->__write_custom_cache(array('error=>' . __t('Kolom nama, alamat, dan kota tidak boleh kosong !')), 1);
                    redirect_to('/node/patient/form'); break; exit;
                }
            } elseif ($key == 'date'){
                $tgldump = explode('-', $value);
                foreach($tgldump as $ky => $vl){
                    if($vl == ''){
                        $this->__write_custom_cache('error=>' . __t('Kolom tanggal tidak boleh kosong !'), 1);
                        redirect_to('/node/patient/form'); break; exit;
                    } elseif(!ctype_digit($vl)){
                        $this->__write_custom_cache('error=>' . __t('Kolom tanggal harus numeric !'), 1);
                        redirect_to('/node/patient/form'); break; exit;
                    }
                }
                if(checkdate($tgldump[1], $tgldump[2], $tgldump[0]) === false){
                    $this->__write_custom_cache('error=>' . __t('Format tanggal salah !'), 1);
                    redirect_to('/node/patient/form'); break; exit;
                } unset($tgldump);
            }
            if($key != 'submit' && $key != 'blank'){
                $thevalue[$key] = $value;
            }
        }
        $thevalue['strnum'] = $dump['strnum'] == '' ? substr(str_shuffle($this->string_to_shuffle), 7, 4) : $dump['strnum'];
        $fincrement = $this->__get_fqmax();
        $thevalue['number'] = basename($fincrement);
        $fqueue = $this->__get_fqueue(basename($fincrement));
        $this->__input_queue($fqueue, $thevalue);
        unlink($this->config->fcache);
        redirect_to('/node/patient/showme/' . basename($fqueue));
    }

}