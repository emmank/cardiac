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
 *  vitalSignclass.php
 *  
 *  Created on Oct 3, 2009, 8:39:24 PM
 */

require_once MODULES_DIR . DS . 'vitalSign' . DS . 'config.inc';

class vitalSignModule extends mainModule
{
    var $title = 'vitalSign module';
    var $description = '';

    function menu(){
        $items['ref_vitalsign_type'] = array(
            'title' => __t('tipe tanda vital'),
            'description' => __t('type reference form for vitalsign'),
            'path' => '/reference/vitalsign_type',
            'exec' => 'ref_type_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_vitalsign_type_detail'] = array(
            'title' => __t('detil tipe tanda vital'),
            'description' => __t('type reference detail for vitalsign'),
            'path' => '/reference/vitalsign_type/detail',
            'exec' => 'ref_type_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_vitalsign_type_form'] = array(
            'title' => __t('vitalsign_type form'),
            'description' => __t('type reference form for vitalsign'),
            'path' => '/reference/vitalsign_type/form',
            'exec' => 'ref_type_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_vitalsign_type_form_submit'] = array(
            'title' => __t('vitalsign_type form'),
            'description' => __t('Execute type reference form for vitalsign'),
            'path' => '/reference/vitalsign_type/form_submit',
            'exec' => 'ref_type_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_vitalsign_type_edit'] = array(
            'title' => __t('vitalsign_type edit'),
            'description' => __t('Editing type reference form for vitalsign'),
            'path' => '/reference/vitalsign_type/edit',
            'exec' => 'ref_type_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_vitalsign_type_drop'] = array(
            'title' => __t('vitalsign_type drop'),
            'description' => __t('Remove type reference form for vitalsign'),
            'path' => '/reference/vitalsign_type/drop',
            'exec' => 'ref_type_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_vitalsign_pulse_rythm'] = array(
            'title' => __t('irama nadi'),
            'description' => __t('pulse rythm reference form for vitalsign'),
            'path' => '/reference/vitalsign_pulse_rythm',
            'exec' => 'ref_pulse_rythm_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_vitalsign_pulse_rythm_detail'] = array(
            'title' => __t('detil tipe tanda vital'),
            'description' => __t('pulse_rythm reference detail for vitalsign'),
            'path' => '/reference/vitalsign_pulse_rythm/detail',
            'exec' => 'ref_pulse_rythm_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_vitalsign_pulse_rythm_form'] = array(
            'title' => __t('vitalsign_pulse_rythm form'),
            'description' => __t('pulse_rythm reference form for vitalsign'),
            'path' => '/reference/vitalsign_pulse_rythm/form',
            'exec' => 'ref_pulse_rythm_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_vitalsign_pulse_rythm_form_submit'] = array(
            'title' => __t('vitalsign_pulse_rythm form'),
            'description' => __t('Execute pulse_rythm reference form for vitalsign'),
            'path' => '/reference/vitalsign_pulse_rythm/form_submit',
            'exec' => 'ref_pulse_rythm_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_vitalsign_pulse_rythm_edit'] = array(
            'title' => __t('vitalsign_pulse_rythm edit'),
            'description' => __t('Editing pulse_rythm reference form for vitalsign'),
            'path' => '/reference/vitalsign_pulse_rythm/edit',
            'exec' => 'ref_pulse_rythm_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_vitalsign_pulse_rythm_drop'] = array(
            'title' => __t('vitalsign_pulse_rythm drop'),
            'description' => __t('Remove pulse_rythm reference form for vitalsign'),
            'path' => '/reference/vitalsign_pulse_rythm/drop',
            'exec' => 'ref_pulse_rythm_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_vitalsign_kesadaran'] = array(
            'title' => __t('kesadaran'),
            'description' => __t('kesadaran reference form for vitalsign'),
            'path' => '/reference/vitalsign_kesadaran',
            'exec' => 'ref_kesadaran_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_vitalsign_kesadaran_detail'] = array(
            'title' => __t('detil tipe tanda vital'),
            'description' => __t('kesadaran reference detail for vitalsign'),
            'path' => '/reference/vitalsign_kesadaran/detail',
            'exec' => 'ref_kesadaran_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_vitalsign_kesadaran_form'] = array(
            'title' => __t('vitalsign_kesadaran form'),
            'description' => __t('kesadaran reference form for vitalsign'),
            'path' => '/reference/vitalsign_kesadaran/form',
            'exec' => 'ref_kesadaran_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_vitalsign_kesadaran_form_submit'] = array(
            'title' => __t('vitalsign_kesadaran form'),
            'description' => __t('Execute kesadaran reference form for vitalsign'),
            'path' => '/reference/vitalsign_kesadaran/form_submit',
            'exec' => 'ref_kesadaran_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_vitalsign_kesadaran_edit'] = array(
            'title' => __t('vitalsign_kesadaran edit'),
            'description' => __t('Editing kesadaran reference form for vitalsign'),
            'path' => '/reference/vitalsign_kesadaran/edit',
            'exec' => 'ref_kesadaran_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_vitalsign_kesadaran_drop'] = array(
            'title' => __t('vitalsign_kesadaran drop'),
            'description' => __t('Remove kesadaran reference form for vitalsign'),
            'path' => '/reference/vitalsign_kesadaran/drop',
            'exec' => 'ref_kesadaran_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        return $items;
    }

    function ref_type_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Tipe Tanda Vital');
        $result['description'] = __t('Referensi isian tipe tanda vital pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/vitalsign_type/form',
            'position' => 'top',
            'user_required' => 'reference'
        );
        $result['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => 'type',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_vitalsign_type'),
            NULL,
            'type'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['type'] = ucwords($query->fields['type']);
                $result['data'][$i]['goto'] = '/reference/vitalsign_type/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_type_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add vitalsign_type'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'type',
            '#weight' => -3,
            '#action' => '/reference/vitalsign_type/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_vitalsign_type');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => 'text',
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
            }
            $query->MoveNext();
        } unset($query);
        $form['group']['submit'] = array(
            '#type' => 'submit',
            '#title' => '&nbsp;',
            '#value' => __t('input')
        );
        return $form;
    }

    function ref_type_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/vitalsign_type/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_vitalsign_type', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_vitalsign_type',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/vitalsign_type');
//        } else {
//            redirect_to('/reference/vitalsign_type/form');
//        }
    }

    function ref_type_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'type', 'vital_sign', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi tipe tanda vital');
        $result['description'] = __t('informasi detil referensi tipe tanda vital yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/vitalsign_type/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'type'),
            array('ref_vitalsign_type'),
            array(
                array('&&', "id=" . $keyid)
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if(isset($update)){
            $showsubmit = array('textarea', 'date');
        }
        foreach($query->fields as $key => $value){
            $result['data'][$key] = array(
                'key' => __t($key),
                'value' => $value,
                'link' => '/reference/vitalsign_type/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/vitalsign_type/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => 'text',
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->formtype_fields[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->formtype_fields[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        )
                    )
                );
                if(in_array($result['data'][$key]['form']['detail'][$key]['#type'], $showsubmit)){
                    $result['data'][$key]['form']['detail'][$key]['submit'] = array(
                        '#type' => 'submit',
                        '#value' => 'submit',
                        '#title' => 'hidden'
                    );
                }
            }
        } unset($query, $keyid);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function ref_type_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_vitalsign_type', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_vitalsign_type',
                        array(
                            $key => $value
                        ),
                        array(
                            array('&&', "id=" . $_POST['id'])
                        )
                    );
                    $this->query->conn->Execute($sql); unset($sql);
                    $this->query->close();
                }
            }
        }
        redirect_to('/reference/vitalsign_type/detail/' . $_POST['id']);
    }

    function ref_type_drop(){
        if($this->__is_dropable($_POST['id'], 'type', 'vital_sign', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_vitalsign_type',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/vitalsign_type');
    }

    function ref_pulse_rythm_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Irama Nadi');
        $result['description'] = __t('Referensi isian irama nadi pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/vitalsign_pulse_rythm/form',
            'position' => 'top',
            'user_required' => 'reference'
        );
        $result['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => 'pulse_rythm',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_vitalsign_pulse_rythm'),
            NULL,
            'pulse_rythm'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['pulse_rythm'] = ucwords($query->fields['pulse_rythm']);
                $result['data'][$i]['goto'] = '/reference/vitalsign_pulse_rythm/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_pulse_rythm_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add vitalsign_pulse_rythm'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'pulse_rythm',
            '#weight' => -3,
            '#action' => '/reference/vitalsign_pulse_rythm/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_vitalsign_pulse_rythm');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => 'text',
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
            }
            $query->MoveNext();
        } unset($query);
        $form['group']['submit'] = array(
            '#type' => 'submit',
            '#title' => '&nbsp;',
            '#value' => __t('input')
        );
        return $form;
    }

    function ref_pulse_rythm_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/vitalsign_pulse_rythm/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_vitalsign_pulse_rythm', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_vitalsign_pulse_rythm',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/vitalsign_pulse_rythm');
//        } else {
//            redirect_to('/reference/vitalsign_pulse_rythm/form');
//        }
    }

    function ref_pulse_rythm_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'pulse_rythm', 'vital_sign', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi irama nadi');
        $result['description'] = __t('informasi detil referensi irama nadi yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/vitalsign_pulse_rythm/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'pulse_rythm'),
            array('ref_vitalsign_pulse_rythm'),
            array(
                array('&&', "id=" . $keyid)
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if(isset($update)){
            $showsubmit = array('textarea', 'date');
        }
        foreach($query->fields as $key => $value){
            $result['data'][$key] = array(
                'key' => __t($key),
                'value' => $value,
                'link' => '/reference/vitalsign_pulse_rythm/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/vitalsign_pulse_rythm/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => 'text',
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->formtype_fields[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->formtype_fields[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        )
                    )
                );
                if(in_array($result['data'][$key]['form']['detail'][$key]['#type'], $showsubmit)){
                    $result['data'][$key]['form']['detail'][$key]['submit'] = array(
                        '#type' => 'submit',
                        '#value' => 'submit',
                        '#title' => 'hidden'
                    );
                }
            }
        } unset($query, $keyid);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function ref_pulse_rythm_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_vitalsign_pulse_rythm', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_vitalsign_pulse_rythm',
                        array(
                            $key => $value
                        ),
                        array(
                            array('&&', "id=" . $_POST['id'])
                        )
                    );
                    $this->query->conn->Execute($sql); unset($sql);
                    $this->query->close();
                }
            }
        }
        redirect_to('/reference/vitalsign_pulse_rythm/detail/' . $_POST['id']);
    }

    function ref_pulse_rythm_drop(){
        if($this->__is_dropable($_POST['id'], 'pulse_rythm', 'vital_sign', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_vitalsign_pulse_rythm',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/vitalsign_pulse_rythm');
    }

    function ref_kesadaran_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Kesadaran');
        $result['description'] = __t('Referensi isian kesadaran pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/vitalsign_kesadaran/form',
            'position' => 'top',
            'user_required' => 'reference'
        );
        $result['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => 'kesadaran',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_vitalsign_kesadaran'),
            NULL,
            'kesadaran'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['kesadaran'] = ucwords($query->fields['kesadaran']);
                $result['data'][$i]['goto'] = '/reference/vitalsign_kesadaran/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_kesadaran_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add vitalsign_kesadaran'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'kesadaran',
            '#weight' => -3,
            '#action' => '/reference/vitalsign_kesadaran/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_vitalsign_kesadaran');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => 'text',
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
            }
            $query->MoveNext();
        } unset($query);
        $form['group']['submit'] = array(
            '#type' => 'submit',
            '#title' => '&nbsp;',
            '#value' => __t('input')
        );
        return $form;
    }

    function ref_kesadaran_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/vitalsign_kesadaran/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_vitalsign_kesadaran', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_vitalsign_kesadaran',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/vitalsign_kesadaran');
//        } else {
//            redirect_to('/reference/vitalsign_kesadaran/form');
//        }
    }

    function ref_kesadaran_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'kesadaran', 'vital_sign', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi kesadaran');
        $result['description'] = __t('informasi detil referensi kesadaran yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/vitalsign_kesadaran/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'kesadaran'),
            array('ref_vitalsign_kesadaran'),
            array(
                array('&&', "id=" . $keyid)
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if(isset($update)){
            $showsubmit = array('textarea', 'date');
        }
        foreach($query->fields as $key => $value){
            $result['data'][$key] = array(
                'key' => __t($key),
                'value' => $value,
                'link' => '/reference/vitalsign_kesadaran/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/vitalsign_kesadaran/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => 'text',
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->formtype_fields[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->formtype_fields[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        )
                    )
                );
                if(in_array($result['data'][$key]['form']['detail'][$key]['#type'], $showsubmit)){
                    $result['data'][$key]['form']['detail'][$key]['submit'] = array(
                        '#type' => 'submit',
                        '#value' => 'submit',
                        '#title' => 'hidden'
                    );
                }
            }
        } unset($query, $keyid);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function ref_kesadaran_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_vitalsign_kesadaran', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_vitalsign_kesadaran',
                        array(
                            $key => $value
                        ),
                        array(
                            array('&&', "id=" . $_POST['id'])
                        )
                    );
                    $this->query->conn->Execute($sql); unset($sql);
                    $this->query->close();
                }
            }
        }
        redirect_to('/reference/vitalsign_kesadaran/detail/' . $_POST['id']);
    }

    function ref_kesadaran_drop(){
        if($this->__is_dropable($_POST['id'], 'kesadaran', 'vital_sign', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_vitalsign_kesadaran',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/vitalsign_kesadaran');
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

    function cardio_menu(){
        $result = array();
        $result['#title'] = __t('Tanda Vital');
        $result['#tpl'] = MODULES_DIR . DS . 'vitalSign' . DS . 'vitalSign.tpl';
        $datafields = $this->__get_data_fields('vital_sign', $this->query);
        foreach($datafields as $key => $value){
            $result['datafields'][$value] = array(
                'title' => __t($value),
                'type' => $this->config->typeoffields[$value]
            );
            if(in_array($value, $this->config->fieldsisarray)){
                $result['datafields'][$value]['theref'] = $this->__get_refs($value);
            } elseif($this->config->typeoffields[$value] == 'datetime'){
                $result['datafields'][$value]['theref'] = $this->nama_bulan;
                $result['datafields'][$value]['timenow'] = $this->config->time;
            } else {
                $result['datafields'][$value]['size'] = 6;
            }
        }
        return $result;
    }

    function cardio_submit(){
        $thefields = $this->__get_data_fields('vital_sign', $this->query);
        foreach($this->config->free_val as $key => $value){
            if(in_array($key, $thefields)){
                $thevalue[$key] = $value;
            }
        } unset($thefields);
        if($_POST['id'] != ''){
            unset($thevalue['id']);
            $sql = $this->query->updateData(
                'vital_sign',
                $thevalue,
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
        } else {
            $sql = $this->query->saveData(
                'vital_sign',
                $thevalue
            );
        }
//        echo '<pre>'; print_r($thevalue); echo '</pre>';
        unset($thevalue);
//        $this->query->connect();
//        $this->conn->execute($sql); unset($sql);
//        $this->query->close();
    }
}