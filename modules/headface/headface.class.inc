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
 *  headfaceclass.php
 *  
 *  Created on Oct 3, 2009, 11:31:36 PM
 */

require_once MODULES_DIR . DS . 'headface' . DS . 'config.inc';

class headfaceModule extends mainModule
{
    var $title = 'headface module';
    var $description = '';

    function menu(){
        $items['ref_headface_inspections'] = array(
            'title' => __t('inspeksi kepala & muka'),
            'description' => __t('inspections reference form for headface'),
            'path' => '/reference/headface_inspections',
            'exec' => 'ref_inspections_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_headface_inspections_detail'] = array(
            'title' => __t('detil tipe tanda vital'),
            'description' => __t('inspections reference detail for headface'),
            'path' => '/reference/headface_inspections/detail',
            'exec' => 'ref_inspections_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_headface_inspections_form'] = array(
            'title' => __t('headface_inspections form'),
            'description' => __t('inspections reference form for headface'),
            'path' => '/reference/headface_inspections/form',
            'exec' => 'ref_inspections_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_headface_inspections_form_submit'] = array(
            'title' => __t('headface_inspections form'),
            'description' => __t('Execute inspections reference form for headface'),
            'path' => '/reference/headface_inspections/form_submit',
            'exec' => 'ref_inspections_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_headface_inspections_edit'] = array(
            'title' => __t('headface_inspections edit'),
            'description' => __t('Editing inspections reference form for headface'),
            'path' => '/reference/headface_inspections/edit',
            'exec' => 'ref_inspections_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_headface_inspections_drop'] = array(
            'title' => __t('headface_inspections drop'),
            'description' => __t('Remove inspections reference form for headface'),
            'path' => '/reference/headface_inspections/drop',
            'exec' => 'ref_inspections_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_headface_expression'] = array(
            'title' => __t('Ekspresi'),
            'description' => __t('expression reference form for headface'),
            'path' => '/reference/headface_expression',
            'exec' => 'ref_expression_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_headface_expression_detail'] = array(
            'title' => __t('detil ekspresi'),
            'description' => __t('expression reference detail for headface'),
            'path' => '/reference/headface_expression/detail',
            'exec' => 'ref_expression_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_headface_expression_form'] = array(
            'title' => __t('headface_expression form'),
            'description' => __t('expression reference form for headface'),
            'path' => '/reference/headface_expression/form',
            'exec' => 'ref_expression_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_headface_expression_form_submit'] = array(
            'title' => __t('headface_expression form'),
            'description' => __t('Execute expression reference form for headface'),
            'path' => '/reference/headface_expression/form_submit',
            'exec' => 'ref_expression_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_headface_expression_edit'] = array(
            'title' => __t('headface_expression edit'),
            'description' => __t('Editing expression reference form for headface'),
            'path' => '/reference/headface_expression/edit',
            'exec' => 'ref_expression_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_headface_expression_drop'] = array(
            'title' => __t('headface_expression drop'),
            'description' => __t('Remove expression reference form for headface'),
            'path' => '/reference/headface_expression/drop',
            'exec' => 'ref_expression_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_headface_hair'] = array(
            'title' => __t('Rambut'),
            'description' => __t('hair reference form for headface'),
            'path' => '/reference/headface_hair',
            'exec' => 'ref_hair_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_headface_hair_detail'] = array(
            'title' => __t('detil rambut'),
            'description' => __t('hair reference detail for headface'),
            'path' => '/reference/headface_hair/detail',
            'exec' => 'ref_hair_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_headface_hair_form'] = array(
            'title' => __t('headface_hair form'),
            'description' => __t('hair reference form for headface'),
            'path' => '/reference/headface_hair/form',
            'exec' => 'ref_hair_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_headface_hair_form_submit'] = array(
            'title' => __t('headface_hair form'),
            'description' => __t('Execute hair reference form for headface'),
            'path' => '/reference/headface_hair/form_submit',
            'exec' => 'ref_hair_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_headface_hair_edit'] = array(
            'title' => __t('headface_hair edit'),
            'description' => __t('Editing hair reference form for headface'),
            'path' => '/reference/headface_hair/edit',
            'exec' => 'ref_hair_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_headface_hair_drop'] = array(
            'title' => __t('headface_hair drop'),
            'description' => __t('Remove hair reference form for headface'),
            'path' => '/reference/headface_hair/drop',
            'exec' => 'ref_hair_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        return $items;
    }

    function ref_inspections_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Inspeksi Kepala dan Muka');
        $result['description'] = __t('Referensi pilihan inspeksi kepala dan muka pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/headface_inspections/form',
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
            array('ref_headface_inspections'),
            NULL
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['inspections'] = ucwords($query->fields['inspections']);
                $result['data'][$i]['goto'] = '/reference/headface_inspections/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_inspections_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add headface_inspections'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'inspections',
            '#weight' => -3,
            '#action' => '/reference/headface_inspections/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_headface_inspections');
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
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/headface_inspections/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_headface_inspections', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_headface_inspections',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/headface_inspections');
//        } else {
//            redirect_to('/reference/headface_inspections/form');
//        }
    }

    function ref_inspections_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'inspections', 'head_n_face', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi inspections');
        $result['description'] = __t('informasi detil referensi inspections yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/headface_inspections/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'inspections'),
            array('ref_headface_inspections'),
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
                'link' => '/reference/headface_inspections/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/headface_inspections/edit/',
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
                if(in_array($key, $this->__get_data_fields('ref_headface_inspections', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_headface_inspections',
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
        redirect_to('/reference/headface_inspections/detail/' . $_POST['id']);
    }

    function ref_inspections_drop(){
        if($this->__is_dropable($_POST['id'], 'inspections', 'head_n_face', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_headface_inspections',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/headface_inspections');
    }

    function ref_expression_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Ekspresi Kepala dan Muka');
        $result['description'] = __t('Referensi pilihan ekspresi kepala dan muka pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/headface_expression/form',
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
                'field' => 'expression',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_headface_expression'),
            NULL
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['expression'] = ucwords($query->fields['expression']);
                $result['data'][$i]['goto'] = '/reference/headface_expression/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_expression_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add headface_expression'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'expression',
            '#weight' => -3,
            '#action' => '/reference/headface_expression/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_headface_expression');
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

    function ref_expression_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/headface_expression/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_headface_expression', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_headface_expression',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/headface_expression');
//        } else {
//            redirect_to('/reference/headface_expression/form');
//        }
    }

    function ref_expression_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'expression', 'head_n_face', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi expression');
        $result['description'] = __t('informasi detil referensi expression yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/headface_expression/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'expression'),
            array('ref_headface_expression'),
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
                'link' => '/reference/headface_expression/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/headface_expression/edit/',
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

    function ref_expression_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_headface_expression', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_headface_expression',
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
        redirect_to('/reference/headface_expression/detail/' . $_POST['id']);
    }

    function ref_expression_drop(){
        if($this->__is_dropable($_POST['id'], 'expression', 'head_n_face', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_headface_expression',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/headface_expression');
    }

    function ref_hair_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Rambut Kepala dan Muka');
        $result['description'] = __t('Referensi pilihan ekspresi kepala dan muka pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/headface_hair/form',
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
                'field' => 'hair',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_headface_hair'),
            NULL
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['hair'] = ucwords($query->fields['hair']);
                $result['data'][$i]['goto'] = '/reference/headface_hair/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_hair_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add headface_hair'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'hair',
            '#weight' => -3,
            '#action' => '/reference/headface_hair/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_headface_hair');
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

    function ref_hair_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/headface_hair/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_headface_hair', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_headface_hair',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/headface_hair');
//        } else {
//            redirect_to('/reference/headface_hair/form');
//        }
    }

    function ref_hair_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'hair', 'head_n_face', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi hair');
        $result['description'] = __t('informasi detil referensi hair yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/headface_hair/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'hair'),
            array('ref_headface_hair'),
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
                'link' => '/reference/headface_hair/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/headface_hair/edit/',
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

    function ref_hair_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_headface_hair', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_headface_hair',
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
        redirect_to('/reference/headface_hair/detail/' . $_POST['id']);
    }

    function ref_hair_drop(){
        if($this->__is_dropable($_POST['id'], 'hair', 'head_n_face', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_headface_hair',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/headface_hair');
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
        $this->sync_scheme('head_n_face', $this->query);
        $result = array();
        $result['#title'] = __t('Kepala dan Muka');
        $result['#tpl'] = MODULES_DIR . DS . 'headface' . DS . 'headface.tpl';
        $datafields = $this->__get_data_fields('head_n_face', $this->query);
        if (count($this->config->free_val) > 0){
            $vcache = $this->config->free_val;
            $sql = $this->query->getSelect(
                array(),
                array('head_n_face'),
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
        $thefields = $this->__get_data_fields('head_n_face', $this->query);
        foreach($this->config->free_val as $key => $value){
            if(in_array($key, $thefields)){
//                if($key == 'inspections'){
//                    if(count($value) > 0){
//                        $value = implode(',', $value);
//                    }
//                }
                $thevalue[$key] = $value;
            }
        } unset($thefields);
        if($_POST['id'] != ''){
            unset($thevalue['id']);
            $opr = 'update';
            $strid = array('id', $_POST['id']);
        } else {
            $opr = 'insert';
            $strid = array('id', $thevalue['id']);
        }
//        echo '<pre>'; print_r($thevalue); echo '</pre>';
        $this->__exec_db_ops(
            $this->query,
            'head_n_face',
            $opr,
            $strid,
            $thevalue
        );
        unset($thevalue, $opr, $strid);
    }
}