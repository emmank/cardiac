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
 *  mouthclass.php
 *  
 *  Created on Oct 4, 2009, 7:19:11 AM
 */

require_once MODULES_DIR . DS . 'mouth' . DS . 'config.inc';

class mouthModule extends mainModule
{
    var $title = 'mouth module';
    var $description = '';

    function menu(){
        $items['ref_mouth_inspections'] = array(
            'title' => __t('Inspeksi Mulut'),
            'description' => __t('inspections reference form for mouth'),
            'path' => '/reference/mouth_inspections',
            'exec' => 'ref_inspections_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_mouth_inspections_detail'] = array(
            'title' => __t('detil mulut'),
            'description' => __t('inspections reference detail for mouth'),
            'path' => '/reference/mouth_inspections/detail',
            'exec' => 'ref_inspections_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_mouth_inspections_form'] = array(
            'title' => __t('mouth_inspections form'),
            'description' => __t('inspections reference form for mouth'),
            'path' => '/reference/mouth_inspections/form',
            'exec' => 'ref_inspections_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_mouth_inspections_form_submit'] = array(
            'title' => __t('mouth_inspections form'),
            'description' => __t('Execute inspections reference form for mouth'),
            'path' => '/reference/mouth_inspections/form_submit',
            'exec' => 'ref_inspections_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_mouth_inspections_edit'] = array(
            'title' => __t('mouth_inspections edit'),
            'description' => __t('Editing inspections reference form for mouth'),
            'path' => '/reference/mouth_inspections/edit',
            'exec' => 'ref_inspections_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_mouth_inspections_drop'] = array(
            'title' => __t('mouth_inspections drop'),
            'description' => __t('Remove inspections reference form for mouth'),
            'path' => '/reference/mouth_inspections/drop',
            'exec' => 'ref_inspections_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_mouth_lips'] = array(
            'title' => __t('bibir'),
            'description' => __t('lips reference form for mouth'),
            'path' => '/reference/mouth_lips',
            'exec' => 'ref_lips_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_mouth_lips_detail'] = array(
            'title' => __t('detil bibir'),
            'description' => __t('lips reference detail for mouth'),
            'path' => '/reference/mouth_lips/detail',
            'exec' => 'ref_lips_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_mouth_lips_form'] = array(
            'title' => __t('mouth_lips form'),
            'description' => __t('lips reference form for mouth'),
            'path' => '/reference/mouth_lips/form',
            'exec' => 'ref_lips_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_mouth_lips_form_submit'] = array(
            'title' => __t('mouth_lips form'),
            'description' => __t('Execute lips reference form for mouth'),
            'path' => '/reference/mouth_lips/form_submit',
            'exec' => 'ref_lips_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_mouth_lips_edit'] = array(
            'title' => __t('mouth_lips edit'),
            'description' => __t('Editing lips reference form for mouth'),
            'path' => '/reference/mouth_lips/edit',
            'exec' => 'ref_lips_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_mouth_lips_drop'] = array(
            'title' => __t('mouth_lips drop'),
            'description' => __t('Remove lips reference form for mouth'),
            'path' => '/reference/mouth_lips/drop',
            'exec' => 'ref_lips_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_mouth_gums'] = array(
            'title' => __t('gusi'),
            'description' => __t('gums reference form for mouth'),
            'path' => '/reference/mouth_gums',
            'exec' => 'ref_gums_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_mouth_gums_detail'] = array(
            'title' => __t('detil gusi'),
            'description' => __t('gums reference detail for mouth'),
            'path' => '/reference/mouth_gums/detail',
            'exec' => 'ref_gums_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_mouth_gums_form'] = array(
            'title' => __t('mouth_gums form'),
            'description' => __t('gums reference form for mouth'),
            'path' => '/reference/mouth_gums/form',
            'exec' => 'ref_gums_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_mouth_gums_form_submit'] = array(
            'title' => __t('mouth_gums form'),
            'description' => __t('Execute gums reference form for mouth'),
            'path' => '/reference/mouth_gums/form_submit',
            'exec' => 'ref_gums_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_mouth_gums_edit'] = array(
            'title' => __t('mouth_gums edit'),
            'description' => __t('Editing gums reference form for mouth'),
            'path' => '/reference/mouth_gums/edit',
            'exec' => 'ref_gums_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_mouth_gums_drop'] = array(
            'title' => __t('mouth_gums drop'),
            'description' => __t('Remove gums reference form for mouth'),
            'path' => '/reference/mouth_gums/drop',
            'exec' => 'ref_gums_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_mouth_tongue'] = array(
            'title' => __t('lidah'),
            'description' => __t('tongue reference form for mouth'),
            'path' => '/reference/mouth_tongue',
            'exec' => 'ref_tongue_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_mouth_tongue_detail'] = array(
            'title' => __t('detil lidah'),
            'description' => __t('tongue reference detail for mouth'),
            'path' => '/reference/mouth_tongue/detail',
            'exec' => 'ref_tongue_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_mouth_tongue_form'] = array(
            'title' => __t('mouth_tongue form'),
            'description' => __t('tongue reference form for mouth'),
            'path' => '/reference/mouth_tongue/form',
            'exec' => 'ref_tongue_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_mouth_tongue_form_submit'] = array(
            'title' => __t('mouth_tongue form'),
            'description' => __t('Execute tongue reference form for mouth'),
            'path' => '/reference/mouth_tongue/form_submit',
            'exec' => 'ref_tongue_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_mouth_tongue_edit'] = array(
            'title' => __t('mouth_tongue edit'),
            'description' => __t('Editing tongue reference form for mouth'),
            'path' => '/reference/mouth_tongue/edit',
            'exec' => 'ref_tongue_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_mouth_tongue_drop'] = array(
            'title' => __t('mouth_tongue drop'),
            'description' => __t('Remove tongue reference form for mouth'),
            'path' => '/reference/mouth_tongue/drop',
            'exec' => 'ref_tongue_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        return $items;
    }

    function ref_inspections_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Inspeksi Mulut');
        $result['description'] = __t('Referensi pilihan inspeksi mulut pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/mouth_inspections/form',
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
            array('ref_mouth_inspections'),
            NULL,
            'inspections'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['inspections'] = ucwords($query->fields['inspections']);
                $result['data'][$i]['goto'] = '/reference/mouth_inspections/detail/' . $query->fields['id'];
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
            '#title' => __t('add mouth_inspections'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'inspections',
            '#weight' => -3,
            '#action' => '/reference/mouth_inspections/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_mouth_inspections');
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
                    redirect_to('/reference/mouth_inspections/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_mouth_inspections', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_mouth_inspections',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/mouth_inspections');
//        } else {
//            redirect_to('/reference/mouth_inspections/form');
//        }
    }

    function ref_inspections_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'inspections', 'mouth', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi inspections');
        $result['description'] = __t('informasi detil referensi inspections yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/mouth_inspections/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'inspections'),
            array('ref_mouth_inspections'),
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
                'link' => '/reference/mouth_inspections/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/mouth_inspections/edit/',
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
                if(in_array($key, $this->__get_data_fields('ref_mouth_inspections', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_mouth_inspections',
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
        redirect_to('/reference/mouth_inspections/detail/' . $_POST['id']);
    }

    function ref_inspections_drop(){
        if($this->__is_dropable($_POST['id'], 'inspections', 'mouth', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_mouth_inspections',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/mouth_inspections');
    }

    function ref_lips_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Bibir');
        $result['description'] = __t('Referensi pilihan bibir pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/mouth_lips/form',
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
                'field' => 'lips',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_mouth_lips'),
            NULL,
            'lips'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['lips'] = ucwords($query->fields['lips']);
                $result['data'][$i]['goto'] = '/reference/mouth_lips/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_lips_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add mouth_lips'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'lips',
            '#weight' => -3,
            '#action' => '/reference/mouth_lips/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_mouth_lips');
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

    function ref_lips_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/mouth_lips/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_mouth_lips', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_mouth_lips',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/mouth_lips');
//        } else {
//            redirect_to('/reference/mouth_lips/form');
//        }
    }

    function ref_lips_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'lips', 'mouth', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi lips');
        $result['description'] = __t('informasi detil referensi lips yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/mouth_lips/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'lips'),
            array('ref_mouth_lips'),
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
                'link' => '/reference/mouth_lips/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/mouth_lips/edit/',
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

    function ref_lips_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_mouth_lips', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_mouth_lips',
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
        redirect_to('/reference/mouth_lips/detail/' . $_POST['id']);
    }

    function ref_lips_drop(){
        if($this->__is_dropable($_POST['id'], 'lips', 'mouth', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_mouth_lips',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/mouth_lips');
    }

    function ref_gums_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Gusi');
        $result['description'] = __t('Referensi pilihan gusi pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/mouth_gums/form',
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
                'field' => 'gums',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_mouth_gums'),
            NULL,
            'gums'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['gums'] = ucwords($query->fields['gums']);
                $result['data'][$i]['goto'] = '/reference/mouth_gums/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_gums_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add mouth_gums'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'gums',
            '#weight' => -3,
            '#action' => '/reference/mouth_gums/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_mouth_gums');
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

    function ref_gums_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/mouth_gums/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_mouth_gums', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_mouth_gums',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/mouth_gums');
//        } else {
//            redirect_to('/reference/mouth_gums/form');
//        }
    }

    function ref_gums_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'gums', 'mouth', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi gums');
        $result['description'] = __t('informasi detil referensi gums yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/mouth_gums/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'gums'),
            array('ref_mouth_gums'),
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
                'link' => '/reference/mouth_gums/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/mouth_gums/edit/',
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

    function ref_gums_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_mouth_gums', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_mouth_gums',
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
        redirect_to('/reference/mouth_gums/detail/' . $_POST['id']);
    }

    function ref_gums_drop(){
        if($this->__is_dropable($_POST['id'], 'gums', 'mouth', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_mouth_gums',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/mouth_gums');
    }

    function ref_tongue_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Lidah');
        $result['description'] = __t('Referensi pilihan lidah pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/mouth_tongue/form',
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
                'field' => 'tongue',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_mouth_tongue'),
            NULL,
            'tongue'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['tongue'] = ucwords($query->fields['tongue']);
                $result['data'][$i]['goto'] = '/reference/mouth_tongue/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_tongue_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add mouth_tongue'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'tongue',
            '#weight' => -3,
            '#action' => '/reference/mouth_tongue/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_mouth_tongue');
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

    function ref_tongue_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/mouth_tongue/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_mouth_tongue', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_mouth_tongue',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/mouth_tongue');
//        } else {
//            redirect_to('/reference/mouth_tongue/form');
//        }
    }

    function ref_tongue_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'tongue', 'mouth', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi tongue');
        $result['description'] = __t('informasi detil referensi tongue yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/mouth_tongue/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'tongue'),
            array('ref_mouth_tongue'),
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
                'link' => '/reference/mouth_tongue/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/mouth_tongue/edit/',
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

    function ref_tongue_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_mouth_tongue', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_mouth_tongue',
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
        redirect_to('/reference/mouth_tongue/detail/' . $_POST['id']);
    }

    function ref_tongue_drop(){
        if($this->__is_dropable($_POST['id'], 'tongue', 'mouth', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_mouth_tongue',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/mouth_tongue');
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
        $result['#title'] = __t('Mulut');
        $result['#tpl'] = MODULES_DIR . DS . 'mouth' . DS . 'mouth.tpl';
        $datafields = $this->__get_data_fields('mouth', $this->query);
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
        $thefields = $this->__get_data_fields('mouth', $this->query);
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
                'mouth',
                $thevalue,
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
        } else {
            $sql = $this->query->saveData(
                'mouth',
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