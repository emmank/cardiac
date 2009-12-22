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
 *  echocardiographyclass.php
 *  
 *  Created on Sep 16, 2009, 3:51:41 AM
 */

require_once MODULES_DIR . DS . 'echocardiography' . DS . 'config.inc';

class echocardiographyModule extends mainModule
{
    var $title = 'echocardiography module';
    var $description = '';
    var $hidden_fields = array(
        'id', 'inputer', 'inputtime', 'updated'
    );
    var $formtype_fields = array(
        'patients' => 'hidden',
        'no_registrasi' => 'text',
        'cd' => 'text',
        'tgl_periksa' => 'text',
        'conclusion' => 'textarea',
        'description' => 'textarea'
    );
    var $measured_fields = array(
        'aortie_root_dimension',
        'aortie_valve_excursion',
        'left_atrium',
        'ivs_thickness',
        'mitral_valve_excursion',
        'velocity',
        'left_ventricular_posterior_wall_thickness',
        'right_ventricular_internal_dimension',
        'left_ventricular_end_diastolic_dimension',
        'left_ventricular_end_systolic_dimension',
        'left_ventricular_end_diastolic_volume',
        'left_ventricular_end_systolic_volume',
        'ejection_fraction',
        'velocity_circumfrential_shortening',
        'shortening_fraction'
    );
    var $fields_alias = array(
        'aortie_root_dimension' => array(
            'alias' => 'Aortie Root Dimension',
            'short' => 'Ao',
            'normal_value' => '2.0 - 3.7 cm'
        ),
        'aortie_valve_excursion' => array(
            'alias' => 'Aortie Valve Excursion',
            'short' => '',
            'normal_value' => '1.6 - 2.6 cm'
        ),
        'left_atrium' => array(
            'alias' => 'Left Atrium',
            'short' => 'LA',
            'normal_value' => '1.9 - 4.0 cm'
        ),
        'ivs_thickness' => array(
            'alias' => 'IVS Thickness',
            'short' => 'IVS',
            'normal_value' => '0.7 - 1.1 cm'
        ),
        'mitral_valve_excursion' => array(
            'alias' => 'Mitral Valve Excursion',
            'short' => '',
            'normal_value' => '20 - 35 cm'
        ),
        'velocity' => array(
            'alias' => 'Velocity',
            'short' => '',
            'normal_value' => '70 - 50 mm/sec'
        ),
        'left_ventricular_posterior_wall_thickness' => array(
            'alias' => 'Left Ventricular Posterior Wall Thickness',
            'short' => 'LVPW',
            'normal_value' => '0.7 - 1.1 cm'
        ),
        'right_ventricular_internal_dimension' => array(
            'alias' => 'Right Ventricular Internal Dimension',
            'short' => 'RV',
            'normal_value' => '0.7 - 2.5 cm'
        ),
        'left_ventricular_end_diastolic_dimension' => array(
            'alias' => 'Left Ventricular End Diastolic Dimension',
            'short' => 'LVEDD',
            'normal_value' => '3.7 - 5.4 cm'
        ),
        'left_ventricular_end_systolic_dimension' => array(
            'alias' => 'Left Ventricular End Systolic Dimension',
            'short' => 'LVESD',
            'normal_value' => '< 3.4 cm'
        ),
        'left_ventricular_end_diastolic_volume' => array(
            'alias' => 'Left Ventricular End Diastolic Volume',
            'short' => 'LVEDV',
            'normal_value' => '54 - 162 ml'
        ),
        'left_ventricular_end_systolic_volume' => array(
            'alias' => 'Left Ventricular End Systolic Volume',
            'short' => 'LV',
            'normal_value' => '< 81 ml'
        ),
        'ejection_fraction' => array(
            'alias' => 'Ejection Fraction',
            'short' => 'EF',
            'normal_value' => '> 50%'
        ),
        'velocity_circumfrential_shortening' => array(
            'alias' => 'Velocity Circumfrential Shortening',
            'short' => '',
            'normal_value' => '< 0.9'
        ),
        'shortening_fraction' => array(
            'alias' => '% Shortening Fraction = (LVEDD - LVESD) / LVEDD',
            'short' => 'SF',
            'normal_value' => '30 - 38%'
        ),
    );

    function menu(){
        $items['echocardiography_form'] = array(
            'title' => __t('echocardiography form'),
            'description' => __t('echocardiography check form'),
            'path' => '/user/echocardiography/form',
            'exec' => 'form',
            'weight' => 5,
            'user_required' => 'echocardiography'
        );
          $items['echocardiography_today_patient_lists'] = array(
            'title' => __t('echocardiography form'),
            'description' => __t('echocardiography check form'),
            'path' => '/user/echocardiography/today_patient_lists',
            'exec' => 'today_patient_lists',
            'weight' => 5,
            'user_required' => 'echocardiography'
        );
        $items['echocardiography_lists'] = array(
            'title' => __t('echocardiography'),
            'description' => __t('explore echocardiography'),
            'path' => '/user/echocardiography/lists',
            'exec' => 'lists',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['echocardiography_message'] = array(
            'title' => __t('echocardiography message'),
            'description' => __t('get echocardiography message'),
            'path' => '/user/echocardiography/message',
            'exec' => 'message',
            'weight' => 5,
            'user_required' => 'echocardiography'
        );
        $items['echocardiography_form_submit'] = array(
            'title' => __t('echocardiography form submit'),
            'description' => __t('execute echocardiography check form'),
            'path' => '/user/echocardiography/form_submit',
            'exec' => 'form_submit',
            'weight' => 5,
            'user_required' => 'echocardiography'
        );
      return $items;
    }

    function view(){
        return $this->__get_today_lists();
    }

    function lists(){
//        $this->sync_scheme('echocardiography', $this->query);
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('daftar beberapa pasien');
        $result['description'] = __t('daftar beberapa pasien terakhir yang telah diperiksa');
        $result['addmenu']['#add'] = array(
            'title' => __t('add'),
            'action' => '/user/echocardiography/form',
            'position' => 'top',
            'user_required' => 'users'
        );
        $result['addmenu']['#search'] = array(
            'title' => __t('search'),
            'action' => '/user/echocardiography/search',
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
            array('echocardiography'),
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
                $result['data'][$i]['goto'] = '/user/echocardiography/detail_form/' . $getit->fields['id'];
                $result['data'][$i]['inputtime'] = date('j-n-Y H:i:s', strtotime($getit->fields['inputtime']));
                $getit->MoveNext();
            }
        }
        return $result;
    }
    

    function form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        } elseif(isset($vascular_id) && !is_null($vascular_id)){
            $vcache = $this->__get_vascular_data($vascular_id);
        } else {
            $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
//            echo '<pre>'; print_r($dump); echo '</pre>'; exit();
            if(count($dump) > 3){
                $vcache['idkunjungan'] = $dump[3]; unset($dump);
                $this->query->connect();
                $sql = $this->query->getSelect(
                    array('patients'),
                    array('kunjungan'),
                    array(
                        array('&&', "id=" . $vcache['idkunjungan'])
                    )
                );
                $query = $this->query->conn->Execute($sql); unset($sql);
                $this->query->close();
                $idpatients = $query->fields['patients']; unset($query);
                $vcache['patients'] = $idpatients;
                unset($idpatients);
            } else {
                redirect_to('/user/echocardiography/today_patient_lists'); exit();
            } unset($dump);
        }
        $form['echocardiography'] = array(
            '#type' => 'special',
            '#id' => 'echocardiography',
            '#title' => __t('ECHOCARDIOGRAPH REPORT'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/user/echocardiography/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE,
            '#formtpl' => MODULES_DIR . DS . 'echocardiography' . DS . 'echocardiography.tpl.php',
            '#measured_fields' => $this->measured_fields,
            '#fields_alias' => $this->fields_alias,
        );
        $form['echocardiography']['idkunjungan'] = array(
            '#type' => 'hidden',
            '#value' => isset($vcache['idkunjungan']) ? $vcache['idkunjungan'] : ''
        );
        $thefields = $this->__get_data_fields('echocardiography', $this->query);
//        echo '<pre>'; print_r($thefields); echo '</pre>';
        foreach($thefields as $value){
            if(in_array($value, $this->hidden_fields)){
                if($value == 'id'){
                    $form['echocardiography'][$value] = array(
                        '#type' => 'hidden',
                        '#value' => isset($vcache['id']) ? $vcache['id'] : ''
                    );
                }
            } elseif(!in_array($value, $this->measured_fields)) {
                if($value == 'tgl_periksa'){
                    if(!isset($vcache['tgl_periksa']) || $vcache['tgl_periksa'] == ''){
                        $vcache['tgl_periksa'] =date('Y-m-d', $this->config->time);
                    }
                } elseif($value == 'patients'){
                    $form['echocardiography'][$value] = array(
                        '#type' => 'hidden',
                        '#value' => $vcache['patients']
                    );
                    $query = $this->__get_patient_data($vcache['patients'], array('nama', 'tgl_lahir', 'alamat', 'kota', 'propinsi', 'strnum'));
                    if(count($query) > 0){
                        foreach($query as $ky => $vl){
                            if($ky == 'tgl_lahir'){
//                                $vl = $this->agecount_in_month(strtotime($vl));
                                $vl = round(($this->agecount_in_month(strtotime($vl))/12),0);
                                $form['echocardiography']['umur'] = array(
                                    '#type' => 'text',
                                    '#value' => $vl . ' tahun',
                                    '#title' => __t('umur'),
                                    '#tbpos' => 2,
                                    '#extra' => 'readonly="true"'
                                );
                            } else {
                                if($ky != 'kota' && $ky != 'propinsi'){
                                    if($ky == 'alamat'){
                                        $vl = $vl . ' ' . $query['kota'] . ' ' . $query['propinsi'];
                                        $tbpos = 5;
                                    } elseif($ky == 'strnum'){
                                        $ky = 'no_registrasi';
                                        $tbpos = 0;
                                    } elseif($ky == 'nama'){
                                        $tbpos = 1;
                                    }
                                    $form['echocardiography'][$ky] = array(
                                        '#type' => $ky == 'alamat' ? 'textarea' : 'text',
                                        '#value' => $vl,
                                        '#title' => __t($ky),
                                        '#tbpos' => $tbpos,
                                        '#extra' => 'readonly="true"'
                                    );
                                    if($ky == 'alamat'){
                                        $form['echocardiography'][$ky]['#extra'] = 'readonly="true"';
                                        $form['echocardiography'][$ky]['#cols'] = '55';
                                        $form['echocardiography'][$ky]['#rows'] = '3';
                                    } elseif($ky == 'no_registrasi'){
                                        $form['echocardiography'][$ky]['#link'] = '/user/echocardiography/today_patient_lists';
                                    }
                                    unset($tbpos);
                                }
                            }
                        }
                    }
                    $this->query->close();
                }
                if($value != 'no_registrasi'){
                    $title = $value == 'description' ? 'Discription- Dimentional & Real Time Echocardiogram<br />Discription of Wall Motion, Masses, Valves, Pericardium' : $value;
                    $form['echocardiography'][$value] = array(
                        '#type' => $this->formtype_fields[$value],
                        '#value' => isset($vcache[$value]) ? $vcache[$value] : '',
                        '#size' => $this->formtype_fields[$value] != 'select' && $this->formtype_fields[$value] != 'date' ? 20 : 1,
                        '#title' => $value != 'conclusion' && $value != 'description' ? __t($title) : 'hidden',
                        '#error' => isset($vcache['blank']) && in_array($value, $vcache['blank']) ? 1 : 0
                    );
                }
                if($value == 'tgl_periksa'){
                    $dump = explode('-', $vcache['tgl_periksa']);
                    $form['echocardiography']['tgl_periksa']['#value'] = $dump[2] . ' ' . $this->nama_bulan[(int)$dump[1]] . ' ' . $dump[0];
                    $form['echocardiography']['tgl_periksa']['#tbpos'] = 4;
                    $form['echocardiography']['tgl_periksa']['#extra'] = 'readonly="true"';
                } elseif($value == 'cd'){
                    $form['echocardiography']['cd']['#tbpos'] = 3;
                    $form['echocardiography']['cd']['#size'] = 20;
                } elseif($value == 'conclusion' || $value == 'description'){
                    $form['echocardiography'][$value]['#cols'] = 95;
                    $form['echocardiography'][$value]['#rows'] = 8;
                    $form['echocardiography'][$value]['#message'] = __t($title);
                } unset($title);
            } else {
                foreach($this->fields_alias as $key => $val){
                    $form['echocardiography'][$key] = array(
                        '#type' => 'text',
                        '#value' => isset($vcache[$key]) ? $vcache[$key] : '',
                        '#title' => $val['alias'] . (isset($val['short']) && $val['short'] != '' ? ' (' . $val['short'] . ')' : ''),
                        '#error' => isset($vcache['blank']) && in_array($key, $vcache['blank']) ? 1 : 0,
                        '#normal_value' => $val['normal_value']
                    );
                }
            }
        }
        $form['echocardiography']['submit'] = array(
            '#type' => 'submit',
            '#value' => 'submit',
//            '#extra' => ' class="button"'
        );
//        echo '<pre>'; print_r($form); echo '</pre>';
        return $form;
    }

    function form_submit(){
        $ignoredfields = array(
            'alamat', 'submit', 'blank', 'id', 'idkunjungan'
        );
        $dump = $this->__write_form_cache();
        foreach($dump as $key => $value){
            if(!in_array($key, $ignoredfields)){
                $thevalue[$key] = $value;
            }
        }
        if($dump['id'] == ''){
            $thevalue['id'] = $this->__get_id_insert_value('echocardiography', 'id', $this->query);
            $thevalue['tgl_periksa'] = date('Y-m-d', $this->config->time);
            $thevalue['inputer'] = $_COOKIE[$this->config->cookieid];
            $thevalue['inputtime'] = date('Y-m-d H:i:s', $this->config->time);
//            echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->updateData(
                'kunjungan',
                array(
                    'doneby' => $_COOKIE[$this->config->cookieid]
                ),
                array(
                    array('&&', "id=" . $dump['idkunjungan'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        } else {
            $thevalue['updated'] = $_COOKIE[$this->config->cookieid] . '|' . date('Y-m-d H:i:s', $this->config->time);
        }
        echo "<pre>";print_r($thevalue);echo "</pre>";
        $this->query->connect();
        $sql = $this->query->saveData(
            'echocardiography', $thevalue
        );
        $this->query->conn->Execute($sql); unset($sql);
        $sql = $this->query->getSelect(
            array('nama'),
            array('patients'),
            array(
                array('&&', "id=" . $thevalue['patients'])
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        unset($dump, $thevalue);
//        unlink($this->config->fcache);
        $message = 'data pemeriksaan echocardiography pasien atas nama ' . $query->fields['nama'] . ' telah disimpan !';
        unset($query);
        redirect_to('/user/echocardiography/message/' . rawurlencode($message));
    }
}