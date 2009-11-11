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
    var $vardump;

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
            'user_required' => 'ekg'
        );
        $items['ekg_message'] = array(
            'title' => __t('ekg message'),
            'description' => __t('get ekg message'),
            'path' => '/user/ekg/message',
            'exec' => 'message',
            'weight' => 5,
            'user_required' => 'ekg'
        );
        $items['ekg_anak_message'] = array(
            'title' => __t('ekg message'),
            'description' => __t('get ekg message'),
            'path' => '/user/ekg_anak/message',
            'exec' => 'message',
            'weight' => 5,
            'user_required' => 'kardio anak'
        );
        return $items;
    }

    function __get_today_lists(){
        $result = array();
        $result = $this->today_patient_lists();
//        echo '<pre>'; print_r($result); echo '</pre>'; exit();
        if(count($result['data'])>0){
            foreach($result['data'] as $key => $value){
                $result['data'][$key] = $value;
            }
        }
        return $result;
    }

    function __get_ekg_data($id){
        $result = array();
        $this->query->connect();
        $this->query->getSelect(
            array(),
            array('ekg'),
            array(
                array('&&', "id=" . $id)
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            foreach($query->fields as $key => $value){
                $result[$key] = $value;
            }
        } unset($query);
        return $result;
    }

    function form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        } elseif(isset($ekg_id) && !is_null($ekg_id)){
            $vcache = $this->__get_ekg_data($ekg_id);
        } else {
            $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
            if(count($dump) > 3){
                $vcache['idkunjungan'] = $dump[3]; unset($dump);
                $this->query->connect();
                $sql = $this->query->getSelect(
                    array('patients', 'inputer'),
                    array('kunjungan'),
                    array(
                        array('&&', "id=" . $vcache['idkunjungan'])
                    )
                );
                $query = $this->query->conn->Execute($sql); unset($sql);
                $this->query->close();
                $pengirim = $query->fields['inputer'];
                $idpatients = $query->fields['patients']; unset($query);
                $vcache['patients'] = $idpatients;
                unset($idpatients);

            } else {
                redirect_to('/user/ekg/today_ekg_lists');
            } unset($dump);
        }
        $form['ekg'] = array(
            '#type' => 'special',
            '#id' => 'ekg',
            '#title' => __t('EKG'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/user/ekg/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE,
            '#formtpl' => MODULES_DIR . DS . 'ekg' . DS . 'ekg.tpl',
        );
        $form['ekg']['idkunjungan'] = array(
            '#type' => 'hidden',
            '#value' => isset($vcache['idkunjungan']) ? $vcache['idkunjungan'] : ''
        );
        $thefields = $this->__get_data_fields('ekg', $this->query);
//        echo '<pre>'; print_r($thefields); echo '</pre>';
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
                    $query = $this->__get_patient_data($vcache['patients'], array('nama', 'tgl_lahir', 'alamat', 'kota', 'propinsi', 'nomor', 'kelamin', 'gol_darah'));
                    if(count($query) > 0){
                        foreach($query as $ky => $vl){
                            if($ky == 'tgl_lahir'){
//                                $vl = $this->agecount_in_month(strtotime($vl));
                                $vl = round(($this->agecount_in_month(strtotime($vl))/12),0);
                                $form['ekg']['umur'] = array(
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
//                    $this->query->close();
                }
                if($value != 'no_registrasi'){
                    $form['ekg'][$value] = array(
                        '#type' => $this->config->fields_form_type[$value],
                        '#value' => isset($vcache[$value]) ? $vcache[$value] : '',
                        '#size' => $this->config->fields_form_type[$value] != 'select' && $this->config->fields_form_type[$value] != 'date' ? 20 : 1,
                        '#title' => __t($value),
                        '#error' => isset($vcache['blank']) && in_array($value, $vcache['blank']) ? 1 : 0
                    );
                }
                
            }
        }
//        echo '<pre>'; print_r ($form); echo '</pre>';
//        $form['ekg'] = $this->__loadFekg();
//        $form['ekg']['tab_items']['vitalSign'] = $this->__loadVitalSign();
//        $form['ekg']['tab_items']['eye'] = $this->__loadEye();
//        $form['ekg']['tab_items']['ear'] = $this->__loadEar();
//        $form['ekg']['tab_items']['nose'] = $this->__loadNose();
//        $form['ekg']['tab_items']['headface'] = $this->__loadHeadFace();
//        $form['ekg']['tab_items']['neck'] = $this->__loadNeck();
//        $form['ekg']['tab_items']['mouth'] = $this->__loadMouth();
//        $form['ekg']['tab_items']['thorax'] = $this->__loadThorax();
//        $form['ekg']['tab_items']['paru'] = $this->__loadParu();
//        $form['ekg']['tab_items']['hearth'] = $this->__loadHearth();
//        $form['ekg']['tab_items']['abdomen'] = $this->__loadAbdomen();
//        $form['ekg']['tab_items']['anusrectum'] = $this->__loadAnusrectum();
//        $form['ekg']['tab_items']['punggung'] = $this->__loadPunggung();
//        $form['ekg']['tab_items']['extermitas'] = $this->__loadExtermitas();

        $form['ekg']['submit'] = array(
            '#type' => 'submit',
            '#value' => 'submit',
//            '#extra' => ' class="button"'
        );
//        echo '<pre>'; print_r($form); echo '</pre>';
        return $form;
    }

//    function __loadHearth($exec=NULL){
//        $this->__include_module('hearth');
//        if(isset($this->vardump) && count($this->vardump) > 0){
//            $this->hearth_config->free_val = $this->vardump;
//        }
//        if(!is_null($exec)){
//            if($exec == 'submit'){
//                return $this->hearth_exec->ekg_submit();
//            }
//        } else {
//            return $this->hearth_exec->ekg_menu();
//        }
//    }
//
//    function __loadAbdomen($exec=NULL){
//        $this->__include_module('abdomen');
//        if(isset($this->vardump) && count($this->vardump) > 0){
//            $this->abdomen_config->free_val = $this->vardump;
//        }
//        if(!is_null($exec)){
//            if($exec == 'submit'){
//                return $this->abdomen_exec->ekg_submit();
//            }
//        } else {
//            return $this->abdomen_exec->ekg_menu();
//        }
//    }
//
//    function __loadAnusrectum($exec=NULL){
//        $this->__include_module('anusrectum');
//        if(isset($this->vardump) && count($this->vardump) > 0){
//            $this->anusrectum_config->free_val = $this->vardump;
//        }
//        if(!is_null($exec)){
//            if($exec == 'submit'){
//                return $this->anusrectum_exec->ekg_submit();
//            }
//        } else {
//            return $this->anusrectum_exec->ekg_menu();
//        }
//    }
//
//    function __loadPunggung($exec=NULL){
//        $this->__include_module('punggung');
//        if(isset($this->vardump) && count($this->vardump) > 0){
//            $this->punggung_config->free_val = $this->vardump;
//        }
//        if(!is_null($exec)){
//            if($exec == 'submit'){
//                return $this->punggung_exec->ekg_submit();
//            }
//        } else {
//            return $this->punggung_exec->ekg_menu();
//        }
//    }
//
//    function __loadExtermitas($exec=NULL){
//        $this->__include_module('extermitas');
//        if(isset($this->vardump) && count($this->vardump) > 0){
//            $this->extermitas_config->free_val = $this->vardump;
//        }
//        if(!is_null($exec)){
//            if($exec == 'submit'){
//                return $this->extermitas_exec->ekg_submit();
//            }
//        } else {
//            return $this->extermitas_exec->ekg_menu();
//        }
//    }
//
//    function __loadParu($exec=NULL){
//        $this->__include_module('paru');
//        if(isset($this->vardump) && count($this->vardump) > 0){
//            $this->paru_config->free_val = $this->vardump;
//        }
//        if(!is_null($exec)){
//            if($exec == 'submit'){
//                return $this->paru_exec->ekg_submit();
//            }
//        } else {
//            return $this->paru_exec->ekg_menu();
//        }
//    }
//
//    function __loadThorax($exec=NULL){
//        $this->__include_module('thorax');
//        if(isset($this->vardump) && count($this->vardump) > 0){
//            $this->thorax_config->free_val = $this->vardump;
//        }
//        if(!is_null($exec)){
//            if($exec == 'submit'){
//                return $this->thorax_exec->ekg_submit();
//            }
//        } else {
//            return $this->thorax_exec->ekg_menu();
//        }
//    }
//
//    function __loadNeck($exec=NULL){
//        $this->__include_module('neck');
//        if(isset($this->vardump) && count($this->vardump) > 0){
//            $this->neck_config->free_val = $this->vardump;
//        }
//        if(!is_null($exec)){
//            if($exec == 'submit'){
//                return $this->neck_exec->ekg_submit();
//            }
//        } else {
//            return $this->neck_exec->ekg_menu();
//        }
//    }
//
//    function __loadMouth($exec=NULL){
//        $this->__include_module('mouth');
//        if(isset($this->vardump) && count($this->vardump) > 0){
//            $this->mouth_config->free_val = $this->vardump;
//        }
//        if(!is_null($exec)){
//            if($exec == 'submit'){
//                return $this->mouth_exec->ekg_submit();
//            }
//        } else {
//            return $this->mouth_exec->ekg_menu();
//        }
//    }

//    function __loadFekg($exec=NULL){
//        $this->__include_module('fekg');
//        if(isset($this->vardump) && count($this->vardump) > 0){
//            $this->fekg_config->free_val = $this->vardump;
//        }
//        if(!is_null($exec)){
//            if($exec == 'submit'){
//                return $this->fekg_exec->fekg_submit();
//            }
//        } else {
//            return $this->fekg_exec->menu();
//        }
//    }

//    function __loadVitalSign($exec=NULL){
//        $this->__include_module('vitalSign');
//        if(isset($this->vardump) && count($this->vardump) > 0){
//            $this->vitalSign_config->free_val = $this->vardump;
//        }
//        if(!is_null($exec)){
//            if($exec == 'submit'){
//                return $this->vitalSign_exec->ekg_submit();
//            }
//        } else {
//            return $this->vitalSign_exec->ekg_menu();
//        }
//    }
//
//    function __loadHeadFace($exec=NULL){
//        $this->__include_module('headface');
//        if(isset($this->vardump) && count($this->vardump) > 0){
//            $this->headface_config->free_val = $this->vardump;
//        }
//        if(!is_null($exec)){
//            if($exec == 'submit'){
//                return $this->headface_exec->ekg_submit();
//            }
//        } else {
//            return $this->headface_exec->ekg_menu();
//        }
//    }
//
//    function __loadEye($exec=NULL){
//        $this->__include_module('eye');
//        if(isset($this->vardump) && count($this->vardump) > 0){
//            $this->eye_config->free_val = $this->vardump;
//        }
//        if(!is_null($exec)){
//            if($exec == 'submit'){
//                return $this->eye_exec->ekg_submit();
//            }
//        } else {
//            return $this->eye_exec->ekg_menu();
//        }
//    }
//
//    function __loadNose($exec=NULL){
//        $this->__include_module('nose');
//        if(isset($this->vardump) && count($this->vardump) > 0){
//            $this->nose_config->free_val = $this->vardump;
//        }
//        if(!is_null($exec)){
//            if($exec == 'submit'){
//                return $this->nose_exec->ekg_submit();
//            }
//        } else {
//            return $this->nose_exec->ekg_menu();
//        }
//    }
//
//    function __loadEar($exec=NULL){
//        $this->__include_module('ear');
//        if(isset($this->vardump) && count($this->vardump) > 0){
//            $this->ear_config->free_val = $this->vardump;
//        }
//        if(!is_null($exec)){
//            if($exec == 'submit'){
//                return $this->ear_exec->ekg_submit();
//            }
//        } else {
//            return $this->ear_exec->ekg_menu();
//        }
//    }


    
    function form_submit(){
        $this->vardump = $this->__write_form_cache();
        $sql = $this->query->getSelect(
            array(),
            array('kunjungan'),
            array(
                array('&&', "id=" . $_POST['idkunjungan'])
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
                $thevalue[$key] = $value;
            }
        } unset($thefields);
        $user = $this->__get_user_info();
        if($_POST['id'] != ''){
            $thevalue['updated'] = $user['userid'] . '|' . date('Y-m-d H:i:s', $this->config->time);
            $sql = $this->query->updateData(
                'ekg',
                $thevalue,
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
        } else {
            $thevalue['id'] = $this->__get_id_insert_value('ekg', 'id', $this->query);
            $thevalue['inputer'] = $user['userid'];
            $thevalue['inputtime'] = date('Y-m-d H:i:s', $this->config->time);
            $sql = $this->query->saveData(
                'ekg',
                $thevalue
            );
            $this->vardump['id'] = $thevalue['id'];
        }
//        $this->query->connect();
//        $this->query->conn->Execute($sql); unset($sql);
//        $this->query->close();
        unset($thevalue);
        $this->__loadPresentStatus('submit');
        $this->__loadVitalSign('submit');
        $this->__loadEye('submit');
        $this->__loadEar('submit');
        $this->__loadNose('submit');
        $this->__loadHeadFace('submit');
        $this->__loadNeck('submit');
        $this->__loadMouth('submit');
        $this->__loadThorax('submit');
        $this->__loadParu('submit');
        $this->__loadHearth('submit');
        $this->__loadAbdomen('submit');
        $this->__loadAnusrectum('submit');
//        redirect_to('/user/ekg/form');
    }

    function __include_module($module){
        require MODULES_DIR . DS . $module . DS . $module . '.module';
        $this->{$module . '_config'} = ${$module . '_config'};
        $this->{$module . '_config'}->time = $this->config->time;
        $this->{$module . '_config'}->timelog_idle = $this->onfig->timelog_idle;
        $this->{$module . '_config'}->fcache = $this->config->fcache;
        $this->{$module . '_config'}->flog = $this->config->flog;
        $funcdb = $module == 'user' || $module == 'auth' || $module == 'group' ? 'dbuser' : 'db' . $module;
        $this->{$module . '_query'} = ${$module . '_query'};
        $this->{$module . '_query'}->dbname = $this->{$module . '_config'}->{$funcdb}['name'];
        $this->{$module . '_query'}->dbprefix = $this->{$module . '_config'}->{$funcdb}['prefix'];
        $this->{$module . '_query'}->dbsuffix = $this->{$module . '_config'}->{$funcdb}['suffix'];
        $this->{$module . '_query'}->tbprefix = $this->{$module . '_config'}->{$funcdb}['tbprefix'];
        $this->{$module . '_query'}->tbsuffix = $this->{$module . '_config'}->{$funcdb}['tbsuffix'];
        $this->{$module . '_query'}->hostname = $this->{$module . '_config'}->{$funcdb}['host'];
        $this->{$module . '_query'}->username = $this->{$module . '_config'}->{$funcdb}['user'];
        $this->{$module . '_query'}->passwd = $this->{$module . '_config'}->{$funcdb}['passwd'];
        $this->{$module . '_query'}->conn = &ADONewConnection($this->{$module . '_config'}->rdbms);
        $this->{$module . '_exec'} = ${$module . '_exec'};
        $this->{$module . '_exec'}->config = $this->{$module . '_config'};
        $this->{$module . '_exec'}->sysquery = $this->sysquery;
        $this->{$module . '_exec'}->query = $this->{$module . '_query'};
   }

}