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
 *  thoraxclass.php
 *  
 *  Created on Oct 4, 2009, 8:19:50 AM
 */

require_once MODULES_DIR . DS . 'thorax' . DS . 'config.inc';

class thoraxModule extends mainModule
{
    var $title = 'thorax module';
    var $description = '';

    function menu(){
        $items['ref_thorax_inspections'] = array(
            'title' => __t('Inspeksi Thorax'),
            'description' => __t('inspections reference form for thorax'),
            'path' => '/reference/thorax_inspections',
            'exec' => 'ref_inspections_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_thorax_inspections_detail'] = array(
            'title' => __t('detil thorax'),
            'description' => __t('inspections reference detail for thorax'),
            'path' => '/reference/thorax_inspections/detail',
            'exec' => 'ref_inspections_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_thorax_inspections_form'] = array(
            'title' => __t('thorax_inspections form'),
            'description' => __t('inspections reference form for thorax'),
            'path' => '/reference/thorax_inspections/form',
            'exec' => 'ref_inspections_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_thorax_inspections_form_submit'] = array(
            'title' => __t('thorax_inspections form'),
            'description' => __t('Execute inspections reference form for thorax'),
            'path' => '/reference/thorax_inspections/form_submit',
            'exec' => 'ref_inspections_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_thorax_inspections_edit'] = array(
            'title' => __t('thorax_inspections edit'),
            'description' => __t('Editing inspections reference form for thorax'),
            'path' => '/reference/thorax_inspections/edit',
            'exec' => 'ref_inspections_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_thorax_inspections_drop'] = array(
            'title' => __t('thorax_inspections drop'),
            'description' => __t('Remove inspections reference form for thorax'),
            'path' => '/reference/thorax_inspections/drop',
            'exec' => 'ref_inspections_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_thorax_relief'] = array(
            'title' => __t('Bentuk Thorax'),
            'description' => __t('relief reference form for thorax'),
            'path' => '/reference/thorax_relief',
            'exec' => 'ref_relief_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_thorax_relief_detail'] = array(
            'title' => __t('detil bentuk thorax'),
            'description' => __t('relief reference detail for thorax'),
            'path' => '/reference/thorax_relief/detail',
            'exec' => 'ref_relief_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_thorax_relief_form'] = array(
            'title' => __t('thorax_relief form'),
            'description' => __t('relief reference form for thorax'),
            'path' => '/reference/thorax_relief/form',
            'exec' => 'ref_relief_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_thorax_relief_form_submit'] = array(
            'title' => __t('thorax_relief form'),
            'description' => __t('Execute relief reference form for thorax'),
            'path' => '/reference/thorax_relief/form_submit',
            'exec' => 'ref_relief_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_thorax_relief_edit'] = array(
            'title' => __t('thorax_relief edit'),
            'description' => __t('Editing relief reference form for thorax'),
            'path' => '/reference/thorax_relief/edit',
            'exec' => 'ref_relief_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_thorax_relief_drop'] = array(
            'title' => __t('thorax_relief drop'),
            'description' => __t('Remove relief reference form for thorax'),
            'path' => '/reference/thorax_relief/drop',
            'exec' => 'ref_relief_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        return $items;
    }

    function ref_inspections_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Inspeksi Thorax');
        $result['description'] = __t('Referensi pilihan inspeksi thorax pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/thorax_inspections/form',
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
            array('ref_thorax_inspections'),
            NULL,
            'inspections'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['inspections'] = ucwords($query->fields['inspections']);
                $result['data'][$i]['goto'] = '/reference/thorax_inspections/detail/' . $query->fields['id'];
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
            '#title' => __t('add thorax_inspections'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'inspections',
            '#weight' => -3,
            '#action' => '/reference/thorax_inspections/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_thorax_inspections');
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
                    redirect_to('/reference/thorax_inspections/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_thorax_inspections', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_thorax_inspections',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/thorax_inspections');
//        } else {
//            redirect_to('/reference/thorax_inspections/form');
//        }
    }

    function ref_inspections_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'inspections', 'thorax', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi inspeksi thorax');
        $result['description'] = __t('informasi detil referensi inspections yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/thorax_inspections/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'inspections'),
            array('ref_thorax_inspections'),
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
                'link' => '/reference/thorax_inspections/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/thorax_inspections/edit/',
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
                if(in_array($key, $this->__get_data_fields('ref_thorax_inspections', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_thorax_inspections',
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
        redirect_to('/reference/thorax_inspections/detail/' . $_POST['id']);
    }

    function ref_inspections_drop(){
        if($this->__is_dropable($_POST['id'], 'inspections', 'thorax', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_thorax_inspections',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/thorax_inspections');
    }

    function ref_relief_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Bentuk Thorax');
        $result['description'] = __t('Referensi pilihan bentuk thorax pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/thorax_relief/form',
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
                'field' => 'relief',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_thorax_relief'),
            NULL,
            'relief'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['relief'] = ucwords($query->fields['relief']);
                $result['data'][$i]['goto'] = '/reference/thorax_relief/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_relief_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add thorax_relief'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'relief',
            '#weight' => -3,
            '#action' => '/reference/thorax_relief/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_thorax_relief');
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

    function ref_relief_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/thorax_relief/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_thorax_relief', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_thorax_relief',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/thorax_relief');
//        } else {
//            redirect_to('/reference/thorax_relief/form');
//        }
    }

    function ref_relief_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'relief', 'thorax', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi relief');
        $result['description'] = __t('informasi detil referensi relief yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/thorax_relief/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'relief'),
            array('ref_thorax_relief'),
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
                'link' => '/reference/thorax_relief/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/thorax_relief/edit/',
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

    function ref_relief_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_thorax_relief', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_thorax_relief',
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
        redirect_to('/reference/thorax_relief/detail/' . $_POST['id']);
    }

    function ref_relief_drop(){
        if($this->__is_dropable($_POST['id'], 'relief', 'thorax', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_thorax_relief',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/thorax_relief');
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
        $result['#title'] = __t('Thorax');
        $result['#tpl'] = MODULES_DIR . DS . 'thorax' . DS . 'thorax.tpl';
        $datafields = $this->__get_data_fields('thorax', $this->query);
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
        $thefields = $this->__get_data_fields('thorax', $this->query);
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
                'thorax',
                $thevalue,
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
        } else {
            $sql = $this->query->saveData(
                'thorax',
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