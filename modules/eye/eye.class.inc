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
 *  eyeclass.php
 *  
 *  Created on Oct 4, 2009, 12:21:54 AM
 */

require_once MODULES_DIR . DS . 'eye' . DS . 'config.inc';

class eyeModule extends mainModule
{
    var $title = 'eye module';
    var $description = '';

    function menu(){
        $items['ref_eye_inspections'] = array(
            'title' => __t('Inspeksi Mata'),
            'description' => __t('inspections reference form for eye'),
            'path' => '/reference/eye_inspections',
            'exec' => 'ref_inspections_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_eye_inspections_detail'] = array(
            'title' => __t('detil rambut'),
            'description' => __t('inspections reference detail for eye'),
            'path' => '/reference/eye_inspections/detail',
            'exec' => 'ref_inspections_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_eye_inspections_form'] = array(
            'title' => __t('eye_inspections form'),
            'description' => __t('inspections reference form for eye'),
            'path' => '/reference/eye_inspections/form',
            'exec' => 'ref_inspections_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_inspections_form_submit'] = array(
            'title' => __t('eye_inspections form'),
            'description' => __t('Execute inspections reference form for eye'),
            'path' => '/reference/eye_inspections/form_submit',
            'exec' => 'ref_inspections_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_inspections_edit'] = array(
            'title' => __t('eye_inspections edit'),
            'description' => __t('Editing inspections reference form for eye'),
            'path' => '/reference/eye_inspections/edit',
            'exec' => 'ref_inspections_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_inspections_drop'] = array(
            'title' => __t('eye_inspections drop'),
            'description' => __t('Remove inspections reference form for eye'),
            'path' => '/reference/eye_inspections/drop',
            'exec' => 'ref_inspections_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_tekanan_bola_mata'] = array(
            'title' => __t('Tekanan Bola Mata'),
            'description' => __t('tekanan_bola_mata reference form for eye'),
            'path' => '/reference/eye_tekanan_bola_mata',
            'exec' => 'ref_tekanan_bola_mata_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_eye_tekanan_bola_mata_detail'] = array(
            'title' => __t('detil rambut'),
            'description' => __t('tekanan_bola_mata reference detail for eye'),
            'path' => '/reference/eye_tekanan_bola_mata/detail',
            'exec' => 'ref_tekanan_bola_mata_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_eye_tekanan_bola_mata_form'] = array(
            'title' => __t('eye_tekanan_bola_mata form'),
            'description' => __t('tekanan_bola_mata reference form for eye'),
            'path' => '/reference/eye_tekanan_bola_mata/form',
            'exec' => 'ref_tekanan_bola_mata_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_tekanan_bola_mata_form_submit'] = array(
            'title' => __t('eye_tekanan_bola_mata form'),
            'description' => __t('Execute tekanan_bola_mata reference form for eye'),
            'path' => '/reference/eye_tekanan_bola_mata/form_submit',
            'exec' => 'ref_tekanan_bola_mata_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_tekanan_bola_mata_edit'] = array(
            'title' => __t('eye_tekanan_bola_mata edit'),
            'description' => __t('Editing tekanan_bola_mata reference form for eye'),
            'path' => '/reference/eye_tekanan_bola_mata/edit',
            'exec' => 'ref_eye_tekanan_bola_mata_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_tekanan_bola_mata_drop'] = array(
            'title' => __t('eye_tekanan_bola_mata drop'),
            'description' => __t('Remove tekanan_bola_mata reference form for eye'),
            'path' => '/reference/eye_tekanan_bola_mata/drop',
            'exec' => 'ref_tekanan_bola_mata_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_kelopak_mata'] = array(
            'title' => __t('Kelopak Mata'),
            'description' => __t('kelopak_mata reference form for eye'),
            'path' => '/reference/eye_kelopak_mata',
            'exec' => 'ref_kelopak_mata_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_eye_kelopak_mata_detail'] = array(
            'title' => __t('detil rambut'),
            'description' => __t('kelopak_mata reference detail for eye'),
            'path' => '/reference/eye_kelopak_mata/detail',
            'exec' => 'ref_kelopak_mata_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_eye_kelopak_mata_form'] = array(
            'title' => __t('eye_kelopak_mata form'),
            'description' => __t('kelopak_mata reference form for eye'),
            'path' => '/reference/eye_kelopak_mata/form',
            'exec' => 'ref_kelopak_mata_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_kelopak_mata_form_submit'] = array(
            'title' => __t('eye_kelopak_mata form'),
            'description' => __t('Execute kelopak_mata reference form for eye'),
            'path' => '/reference/eye_kelopak_mata/form_submit',
            'exec' => 'ref_kelopak_mata_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_kelopak_mata_edit'] = array(
            'title' => __t('eye_kelopak_mata edit'),
            'description' => __t('Editing kelopak_mata reference form for eye'),
            'path' => '/reference/eye_kelopak_mata/edit',
            'exec' => 'ref_kelopak_mata_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_kelopak_mata_drop'] = array(
            'title' => __t('eye_kelopak_mata drop'),
            'description' => __t('Remove kelopak_mata reference form for eye'),
            'path' => '/reference/eye_kelopak_mata/drop',
            'exec' => 'ref_kelopak_mata_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_konjunctifa'] = array(
            'title' => __t('Konjunctifa'),
            'description' => __t('konjunctifa reference form for eye'),
            'path' => '/reference/eye_konjunctifa',
            'exec' => 'ref_konjunctifa_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_eye_konjunctifa_detail'] = array(
            'title' => __t('detil rambut'),
            'description' => __t('konjunctifa reference detail for eye'),
            'path' => '/reference/eye_konjunctifa/detail',
            'exec' => 'ref_konjunctifa_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_eye_konjunctifa_form'] = array(
            'title' => __t('eye_konjunctifa form'),
            'description' => __t('konjunctifa reference form for eye'),
            'path' => '/reference/eye_konjunctifa/form',
            'exec' => 'ref_konjunctifa_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_konjunctifa_form_submit'] = array(
            'title' => __t('eye_konjunctifa form'),
            'description' => __t('Execute konjunctifa reference form for eye'),
            'path' => '/reference/eye_konjunctifa/form_submit',
            'exec' => 'ref_konjunctifa_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_konjunctifa_edit'] = array(
            'title' => __t('eye_konjunctifa edit'),
            'description' => __t('Editing konjunctifa reference form for eye'),
            'path' => '/reference/eye_konjunctifa/edit',
            'exec' => 'ref_konjunctifa_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_konjunctifa_drop'] = array(
            'title' => __t('eye_konjunctifa drop'),
            'description' => __t('Remove konjunctifa reference form for eye'),
            'path' => '/reference/eye_konjunctifa/drop',
            'exec' => 'ref_konjunctifa_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_cornea'] = array(
            'title' => __t('cornea'),
            'description' => __t('cornea reference form for eye'),
            'path' => '/reference/eye_cornea',
            'exec' => 'ref_cornea_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_eye_cornea_detail'] = array(
            'title' => __t('detil rambut'),
            'description' => __t('cornea reference detail for eye'),
            'path' => '/reference/eye_cornea/detail',
            'exec' => 'ref_cornea_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_eye_cornea_form'] = array(
            'title' => __t('eye_cornea form'),
            'description' => __t('cornea reference form for eye'),
            'path' => '/reference/eye_cornea/form',
            'exec' => 'ref_cornea_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_cornea_form_submit'] = array(
            'title' => __t('eye_cornea form'),
            'description' => __t('Execute cornea reference form for eye'),
            'path' => '/reference/eye_cornea/form_submit',
            'exec' => 'ref_cornea_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_cornea_edit'] = array(
            'title' => __t('eye_cornea edit'),
            'description' => __t('Editing cornea reference form for eye'),
            'path' => '/reference/eye_cornea/edit',
            'exec' => 'ref_cornea_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_cornea_drop'] = array(
            'title' => __t('eye_cornea drop'),
            'description' => __t('Remove cornea reference form for eye'),
            'path' => '/reference/eye_cornea/drop',
            'exec' => 'ref_cornea_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_pupil'] = array(
            'title' => __t('pupil'),
            'description' => __t('pupil reference form for eye'),
            'path' => '/reference/eye_pupil',
            'exec' => 'ref_pupil_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_eye_pupil_detail'] = array(
            'title' => __t('detil rambut'),
            'description' => __t('pupil reference detail for eye'),
            'path' => '/reference/eye_pupil/detail',
            'exec' => 'ref_pupil_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_eye_pupil_form'] = array(
            'title' => __t('eye_pupil form'),
            'description' => __t('pupil reference form for eye'),
            'path' => '/reference/eye_pupil/form',
            'exec' => 'ref_pupil_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_pupil_form_submit'] = array(
            'title' => __t('eye_pupil form'),
            'description' => __t('Execute pupil reference form for eye'),
            'path' => '/reference/eye_pupil/form_submit',
            'exec' => 'ref_pupil_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_pupil_edit'] = array(
            'title' => __t('eye_pupil edit'),
            'description' => __t('Editing pupil reference form for eye'),
            'path' => '/reference/eye_pupil/edit',
            'exec' => 'ref_pupil_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_eye_pupil_drop'] = array(
            'title' => __t('eye_pupil drop'),
            'description' => __t('Remove pupil reference form for eye'),
            'path' => '/reference/eye_pupil/drop',
            'exec' => 'ref_pupil_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        return $items;
    }

    function ref_inspections_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Inspeksi Mata');
        $result['description'] = __t('Referensi pilihan inspeksi mata pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/eye_inspections/form',
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
                'field' => 'inspections',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_eye_inspections'),
            NULL,
            'inspections'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['inspections'] = ucwords($query->fields['inspections']);
                $result['data'][$i]['goto'] = '/reference/eye_inspections/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_inspections_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add eye_inspections'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'inspections',
            '#weight' => -3,
            '#action' => '/reference/eye_inspections/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_eye_inspections');
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

    function ref_inspections_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/eye_inspections/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_eye_inspections', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_eye_inspections',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/eye_inspections');
//        } else {
//            redirect_to('/reference/eye_inspections/form');
//        }
    }

    function ref_inspections_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'inspections', 'eye', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi inspections');
        $result['description'] = __t('informasi detil referensi inspections yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/eye_inspections/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'inspections'),
            array('ref_eye_inspections'),
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
                'link' => '/reference/eye_inspections/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/eye_inspections/edit/',
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

    function ref_inspections_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_eye_inspections', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_eye_inspections',
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
        redirect_to('/reference/eye_inspections/detail/' . $_POST['id']);
    }

    function ref_inspections_drop(){
        if($this->__is_dropable($_POST['id'], 'inspections', 'eye', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_eye_inspections',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/eye_inspections');
    }

    function ref_tekanan_bola_mata_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Tekanan Bola Mata');
        $result['description'] = __t('Referensi pilihan tekanan bola mata pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/eye_tekanan_bola_mata/form',
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
                'field' => 'tekanan_bola_mata',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_eye_tekanan_bola_mata'),
            NULL,
            'tekanan_bola_mata'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['tekanan_bola_mata'] = ucwords($query->fields['tekanan_bola_mata']);
                $result['data'][$i]['goto'] = '/reference/eye_tekanan_bola_mata/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_tekanan_bola_mata_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add eye_tekanan_bola_mata'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'tekanan_bola_mata',
            '#weight' => -3,
            '#action' => '/reference/eye_tekanan_bola_mata/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_eye_tekanan_bola_mata');
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

    function ref_tekanan_bola_mata_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/eye_tekanan_bola_mata/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_eye_tekanan_bola_mata', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_eye_tekanan_bola_mata',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/eye_tekanan_bola_mata');
//        } else {
//            redirect_to('/reference/eye_tekanan_bola_mata/form');
//        }
    }

    function ref_tekanan_bola_mata_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'tekanan_bola_mata', 'eye', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi tekanan_bola_mata');
        $result['description'] = __t('informasi detil referensi tekanan_bola_mata yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/eye_tekanan_bola_mata/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'tekanan_bola_mata'),
            array('ref_eye_tekanan_bola_mata'),
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
                'link' => '/reference/eye_tekanan_bola_mata/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/eye_tekanan_bola_mata/edit/',
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

    function ref_tekanan_bola_mata_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_eye_tekanan_bola_mata', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_eye_tekanan_bola_mata',
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
        redirect_to('/reference/eye_tekanan_bola_mata/detail/' . $_POST['id']);
    }

    function ref_tekanan_bola_mata_drop(){
        if($this->__is_dropable($_POST['id'], 'tekanan_bola_mata', 'eye', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_eye_tekanan_bola_mata',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/eye_tekanan_bola_mata');
    }

    function ref_kelopak_mata_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Kelopak Mata');
        $result['description'] = __t('Referensi pilihan kelopak mata pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/eye_kelopak_mata/form',
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
                'field' => 'kelopak_mata',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_eye_kelopak_mata'),
            NULL,
            'kelopak_mata'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['kelopak_mata'] = ucwords($query->fields['kelopak_mata']);
                $result['data'][$i]['goto'] = '/reference/eye_kelopak_mata/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_kelopak_mata_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add eye_kelopak_mata'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'kelopak_mata',
            '#weight' => -3,
            '#action' => '/reference/eye_kelopak_mata/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_eye_kelopak_mata');
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

    function ref_kelopak_mata_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/eye_kelopak_mata/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_eye_kelopak_mata', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_eye_kelopak_mata',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/eye_kelopak_mata');
//        } else {
//            redirect_to('/reference/eye_kelopak_mata/form');
//        }
    }

    function ref_kelopak_mata_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'kelopak_mata', 'eye', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi kelopak_mata');
        $result['description'] = __t('informasi detil referensi kelopak_mata yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/eye_kelopak_mata/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'kelopak_mata'),
            array('ref_eye_kelopak_mata'),
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
                'link' => '/reference/eye_kelopak_mata/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/eye_kelopak_mata/edit/',
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

    function ref_kelopak_mata_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_eye_kelopak_mata', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_eye_kelopak_mata',
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
        redirect_to('/reference/eye_kelopak_mata/detail/' . $_POST['id']);
    }

    function ref_kelopak_mata_drop(){
        if($this->__is_dropable($_POST['id'], 'kelopak_mata', 'eye', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_eye_kelopak_mata',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/eye_kelopak_mata');
    }

    function ref_konjunctifa_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Konjunctifa');
        $result['description'] = __t('Referensi pilihan konjunctifa pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/eye_konjunctifa/form',
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
                'field' => 'konjunctifa',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_eye_konjunctifa'),
            NULL,
            'konjunctifa'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['konjunctifa'] = ucwords($query->fields['konjunctifa']);
                $result['data'][$i]['goto'] = '/reference/eye_konjunctifa/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_konjunctifa_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add eye_konjunctifa'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'konjunctifa',
            '#weight' => -3,
            '#action' => '/reference/eye_konjunctifa/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_eye_konjunctifa');
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

    function ref_konjunctifa_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/eye_konjunctifa/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_eye_konjunctifa', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_eye_konjunctifa',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/eye_konjunctifa');
//        } else {
//            redirect_to('/reference/eye_konjunctifa/form');
//        }
    }

    function ref_konjunctifa_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'konjunctifa', 'eye', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi konjunctifa');
        $result['description'] = __t('informasi detil referensi konjunctifa yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/eye_konjunctifa/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'konjunctifa'),
            array('ref_eye_konjunctifa'),
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
                'link' => '/reference/eye_konjunctifa/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/eye_konjunctifa/edit/',
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

    function ref_konjunctifa_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_eye_konjunctifa', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_eye_konjunctifa',
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
        redirect_to('/reference/eye_konjunctifa/detail/' . $_POST['id']);
    }

    function ref_konjunctifa_drop(){
        if($this->__is_dropable($_POST['id'], 'konjunctifa', 'eye', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_eye_konjunctifa',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/eye_konjunctifa');
    }

    function ref_cornea_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi cornea');
        $result['description'] = __t('Referensi pilihan cornea pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/eye_cornea/form',
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
                'field' => 'cornea',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_eye_cornea'),
            NULL,
            'cornea'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['cornea'] = ucwords($query->fields['cornea']);
                $result['data'][$i]['goto'] = '/reference/eye_cornea/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_cornea_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add eye_cornea'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'cornea',
            '#weight' => -3,
            '#action' => '/reference/eye_cornea/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_eye_cornea');
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

    function ref_cornea_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/eye_cornea/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_eye_cornea', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_eye_cornea',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/eye_cornea');
//        } else {
//            redirect_to('/reference/eye_cornea/form');
//        }
    }

    function ref_cornea_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'cornea', 'eye', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi cornea');
        $result['description'] = __t('informasi detil referensi cornea yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/eye_cornea/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'cornea'),
            array('ref_eye_cornea'),
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
                'link' => '/reference/eye_cornea/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/eye_cornea/edit/',
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

    function ref_cornea_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_eye_cornea', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_eye_cornea',
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
        redirect_to('/reference/eye_cornea/detail/' . $_POST['id']);
    }

    function ref_cornea_drop(){
        if($this->__is_dropable($_POST['id'], 'cornea', 'eye', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_eye_cornea',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/eye_cornea');
    }

    function ref_pupil_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi pupil');
        $result['description'] = __t('Referensi pilihan pupil pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/eye_pupil/form',
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
                'field' => 'pupil',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_eye_pupil'),
            NULL,
            'pupil'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['pupil'] = ucwords($query->fields['pupil']);
                $result['data'][$i]['goto'] = '/reference/eye_pupil/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_pupil_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add eye_pupil'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'pupil',
            '#weight' => -3,
            '#action' => '/reference/eye_pupil/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_eye_pupil');
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

    function ref_pupil_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/eye_pupil/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_eye_pupil', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_eye_pupil',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/eye_pupil');
//        } else {
//            redirect_to('/reference/eye_pupil/form');
//        }
    }

    function ref_pupil_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'pupil', 'eye', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi pupil');
        $result['description'] = __t('informasi detil referensi pupil yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/eye_pupil/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'pupil'),
            array('ref_eye_pupil'),
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
                'link' => '/reference/eye_pupil/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/eye_pupil/edit/',
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

    function ref_pupil_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_eye_pupil', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_eye_pupil',
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
        redirect_to('/reference/eye_pupil/detail/' . $_POST['id']);
    }

    function ref_pupil_drop(){
        if($this->__is_dropable($_POST['id'], 'pupil', 'eye', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_eye_pupil',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/eye_pupil');
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
        $result['#title'] = __t('Mata');
        $result['#tpl'] = MODULES_DIR . DS . 'eye' . DS . 'eye.tpl';
        $datafields = $this->__get_data_fields('eye', $this->query);
        if (count($this->config->free_val) > 0){
            $vcache = $this->config->free_val;
            $sql = $this->query->getSelect(
                array(),
                array('eye'),
                array(
                    array('&&', "id=" . $vcache['id'])
                )
            ); unset($vcache);
            $this->query->connect();
            $getit = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            if($getit->_numOfRows > 0){
                foreach($getit->fields as $key => $value){
                    $vcache[$key] = $value;
                }
            }
        }
        foreach($datafields as $key => $value){
            $result['datafields'][$value] = array(
                'title' => __t($value),
                'type' => $this->config->typeoffields[$value],
                'value' => isset($vcache[$value]) ? $vcache[$value] : ''
            );
            if(in_array($value, $this->config->fieldsisarray)){
                $result['datafields'][$value]['theref'] = $this->__get_refs($value);
            } elseif($this->config->typeoffields[$value] == 'datetime'){
                $result['datafields'][$value]['theref'] = $this->nama_bulan;
                $result['datafields'][$value]['timenow'] = $this->config->time;
            } else {
                $result['datafields'][$value]['size'] = 6;
            }
            $result['datafields'][$value]['readonly'] = isset($this->config->free_val['readonly']) ? true : false;
        }
        return $result;
    }

    function cardio_submit(){
        $thefields = $this->__get_data_fields('eye', $this->query);
        foreach($this->config->free_val as $key => $value){
            if(in_array($key, $thefields)){
                if($key == 'inspections'){
                    if(count($value) > 0){
                        $value = implode(',', $value);
                    }
                }
                $thevalue[$key] = $value;
            }
        } unset($thefields);
        if($_POST['id'] != ''){
            unset($thevalue['id']);
            $sql = $this->query->updateData(
                'eye',
                $thevalue,
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
        } else {
            $sql = $this->query->saveData(
                'eye',
                $thevalue
            );
        }
//        echo '<pre>'; print_r($thevalue); echo '</pre>';
        unset($thevalue);
        $this->query->connect();
        $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
    }
}