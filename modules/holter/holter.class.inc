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
 *  holterclass.php
 *  
 *  Created on Oct 1, 2009, 1:12:45 PM
 */

require_once MODULES_DIR . DS . 'holter' . DS . 'config.inc';

class holterModule extends mainModule
{
    var $title = 'holter module';
    var $description = '';
    var $hidden_fields = array(
        'id', 'id_pasien', 'inputer','updated', 'inputtime','tgl'
    );
    var $vardump;

    function menu(){
        $items['holter_form'] = array(
            'title' => __t('form holter'),
            'description' => __t('formulir holter'),
            'path' => '/user/holter/form',
            'exec' => 'form',
            'weight' => '0',
            'user_required' => 'holter'
        );
        $items['holter_form_submit'] = array(
            'title' => __t('form holter submit'),
            'description' => __t('formulir holter'),
            'path' => '/user/holter/form_submit',
            'exec' => 'form_submit',
            'weight' => '0',
            'user_required' => 'holter'
        );
        $items['holter_get_lists'] = array(
            'title' => __t('form holter today list'),
            'description' => __t('formulir holter'),
            'path' => '/user/holter/today_holter_lists',
            'exec' => '__get_today_lists',
            'weight' => '0',
            'user_required' => 'holter'
        );
        $items['holter_message'] = array(
            'title' => __t('holter message'),
            'description' => __t('get holter message'),
            'path' => '/user/holter/message',
            'exec' => 'message',
            'weight' => 5,
            'user_required' => 'holter'
        );
        $items['holter_anak_message'] = array(
            'title' => __t('holter message'),
            'description' => __t('get holter message'),
            'path' => '/user/holter_anak/message',
            'exec' => 'message',
            'weight' => 5,
            'user_required' => 'holter'
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

    function __get_holter_data($id){
        $result = array();
        $this->query->connect();
        $this->query->getSelect(
            array(),
            array('holter'),
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
        } elseif(isset($holter_id) && !is_null($holter_id)){
            $vcache = $this->__get_holter_data($holter_id);
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
                redirect_to('/user/holter/today_holter_lists');
            } unset($dump);
        }
        $form['holter'] = array(
            '#type' => 'special',
            '#id' => 'holter',
            '#title' => __t('holter'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/user/holter/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE,
            '#formtpl' => MODULES_DIR . DS . 'holter' . DS . 'holter.tpl',
        );
        $form['holter']['idkunjungan'] = array(
            '#type' => 'hidden',
            '#value' => isset($vcache['idkunjungan']) ? $vcache['idkunjungan'] : ''
        );
        $thefields = $this->__get_data_fields('holter', $this->query);
//        echo '<pre>'; print_r($thefields); echo '</pre>';
        foreach($thefields as $value){
            if(in_array($value, $this->hidden_fields)){
                if($value == 'id'){
                    $form['holter'][$value] = array(
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
                    $form['holter'][$value] = array(
                        '#type' => 'hidden',
                        '#value' => $vcache['patients']
                    );
                    $query = $this->__get_patient_data($vcache['patients'], array('nama', 'tgl_lahir', 'alamat', 'kota', 'propinsi', 'nomor', 'kelamin', 'gol_darah'));
                    if(count($query) > 0){
                        foreach($query as $ky => $vl){
                            if($ky == 'tgl_lahir'){
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
                                    $form['holter'][$ky] = array(
                                        '#type' => $ky == 'alamat' ? 'textarea' : 'info',
                                        '#value' => $vl,
                                        '#title' => __t($ky),
                                        '#tbpos' => $tbpos
                                    );
                                    if($ky == 'alamat'){
                                        $form['holter'][$ky]['#extra'] = 'readonly="true"';
                                        $form['holter'][$ky]['#cols'] = '55';
                                        $form['holter'][$ky]['#rows'] = '3';
                                    } elseif($ky == 'no_registrasi'){
                                        $form['holter'][$ky]['#link'] = '/user/holter/today_patient_lists';
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
                        $form['holter']['kunjungan_ke'] = array(
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
                        $form['holter']['pengirim'] = array(
                            '#type' => 'info',
                            '#value' => $getsender->fields['nama'],
                            '#title' => __t('pengirim'),
                            '#tbpos' => 7
                        );
                        unset($getsender);
                    }
//                    $this->query->close();
                }
                // JIka value bukan id,tgl,patient
                if($value != 'no_registrasi'){
                    $form['holter'][$value] = array(
                        '#type' => $this->config->fields_form_type[$value],
                        '#value' => isset($vcache[$value]) ? $vcache[$value] : '',
                        '#size' => $this->config->fields_form_type[$value] != 'select' && $this->config->fields_form_type[$value] != 'date' ? 20 : 1,
                        '#title' => __t($value),
                        '#error' => isset($vcache['blank']) && in_array($value, $vcache['blank']) ? 1 : 0
                    );
//                    echo '<pre>'; print_r($form); echo '</pre>';

                    if(in_array($value, $this->config->fieldsisarray)){
                        $form['holter'][$value]['#theref'] = $this->__get_refs($value);
                    }
                }
                
            }
        }

        $form['holter']['submit'] = array(
            '#type' => 'submit',
            '#value' => 'submit',
            '#extra' => ' class="button"'
        );
//        echo '<pre>'; print_r($form); echo '</pre>';
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
        $thefields = $this->__get_data_fields('holter', $this->query);
        foreach($this->vardump as $key => $value){
            if(in_array($key, $thefields)){
                $thevalue[$key] = $value;
            }
        } unset($thefields);
        $user = $this->__get_user_info();
        if($_POST['id'] != ''){
            $thevalue['updated'] = $user['userid'] . '|' . date('Y-m-d H:i:s', $this->config->time);
            $sql = $this->query->updateData(
                'holter',
                $thevalue,
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
        } else {
            $thevalue['id'] = $this->__get_id_insert_value('holter', 'id', $this->query);
            $thevalue['inputer'] = $user['userid'];
            $thevalue['inputtime'] = date('Y-m-d H:i:s', $this->config->time);
            $sql = $this->query->saveData(
                'holter',
                $thevalue
            );
            $this->vardump['id'] = $thevalue['id'];
        }
        $this->query->connect();
        $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        unset($thevalue);

        if(!isset($_POST['id']) || is_null($_POST['id']) || $_POST['id'] == ''){
            $sql = $this->query->updateData(
                'kunjungan',
                array(
                    'doneby' => '1'
                ),
                array(
                    array('&&', "id=" . $_POST['idkunjungan'])
                )
            );
            $this->query->connect();
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/user/holter/form');
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