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
 *  punggungclass.php
 *  
 *  Created on Oct 6, 2009, 11:29:20 AM
 */

require_once MODULES_DIR . DS . 'punggung' . DS . 'config.inc';

class punggungModule extends mainModule
{
    var $title = 'punggung module';
    var $description = '';

    function menu(){
        $items['ref_punggung_inspections'] = array(
            'title' => __t('punggung_inspections'),
            'description' => __t('inspections reference form for punggung'),
            'path' => '/reference/punggung_inspections',
            'exec' => 'ref_inspections_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_punggung_inspections_detail'] = array(
            'title' => __t('detil punggung_inspections'),
            'description' => __t('inspections reference detail for punggung'),
            'path' => '/reference/punggung_inspections/detail',
            'exec' => 'ref_inspections_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_punggung_inspections_form'] = array(
            'title' => __t('punggung_inspections form'),
            'description' => __t('inspections reference form for punggung'),
            'path' => '/reference/punggung_inspections/form',
            'exec' => 'ref_inspections_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_punggung_inspections_form_submit'] = array(
            'title' => __t('punggung_inspections form'),
            'description' => __t('Execute inspections reference form for punggung'),
            'path' => '/reference/punggung_inspections/form_submit',
            'exec' => 'ref_inspections_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_punggung_inspections_edit'] = array(
            'title' => __t('punggung_inspections edit'),
            'description' => __t('Editing inspections reference form for punggung'),
            'path' => '/reference/punggung_inspections/edit',
            'exec' => 'ref_inspections_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_punggung_inspections_drop'] = array(
            'title' => __t('punggung_inspections drop'),
            'description' => __t('Remove inspections reference form for punggung'),
            'path' => '/reference/punggung_inspections/drop',
            'exec' => 'ref_inspections_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_punggung_palpations'] = array(
            'title' => __t('punggung_palpations'),
            'description' => __t('palpations reference form for punggung'),
            'path' => '/reference/punggung_palpations',
            'exec' => 'ref_palpations_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_punggung_palpations_detail'] = array(
            'title' => __t('detil punggung_palpations'),
            'description' => __t('palpations reference detail for punggung'),
            'path' => '/reference/punggung_palpations/detail',
            'exec' => 'ref_palpations_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_punggung_palpations_form'] = array(
            'title' => __t('punggung_palpations form'),
            'description' => __t('palpations reference form for punggung'),
            'path' => '/reference/punggung_palpations/form',
            'exec' => 'ref_palpations_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_punggung_palpations_form_submit'] = array(
            'title' => __t('punggung_palpations form'),
            'description' => __t('Execute palpations reference form for punggung'),
            'path' => '/reference/punggung_palpations/form_submit',
            'exec' => 'ref_palpations_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_punggung_palpations_edit'] = array(
            'title' => __t('punggung_palpations edit'),
            'description' => __t('Editing palpations reference form for punggung'),
            'path' => '/reference/punggung_palpations/edit',
            'exec' => 'ref_palpations_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_punggung_palpations_drop'] = array(
            'title' => __t('punggung_palpations drop'),
            'description' => __t('Remove palpations reference form for punggung'),
            'path' => '/reference/punggung_palpations/drop',
            'exec' => 'ref_palpations_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_punggung_bunyi_pernafasan'] = array(
            'title' => __t('punggung_bunyi_pernafasan'),
            'description' => __t('bunyi_pernafasan reference form for punggung'),
            'path' => '/reference/punggung_bunyi_pernafasan',
            'exec' => 'ref_bunyi_pernafasan_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_punggung_bunyi_pernafasan_detail'] = array(
            'title' => __t('detil punggung_bunyi_pernafasan'),
            'description' => __t('bunyi_pernafasan reference detail for punggung'),
            'path' => '/reference/punggung_bunyi_pernafasan/detail',
            'exec' => 'ref_bunyi_pernafasan_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_punggung_bunyi_pernafasan_form'] = array(
            'title' => __t('punggung_bunyi_pernafasan form'),
            'description' => __t('bunyi_pernafasan reference form for punggung'),
            'path' => '/reference/punggung_bunyi_pernafasan/form',
            'exec' => 'ref_bunyi_pernafasan_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_punggung_bunyi_pernafasan_form_submit'] = array(
            'title' => __t('punggung_bunyi_pernafasan form'),
            'description' => __t('Execute bunyi_pernafasan reference form for punggung'),
            'path' => '/reference/punggung_bunyi_pernafasan/form_submit',
            'exec' => 'ref_bunyi_pernafasan_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_punggung_bunyi_pernafasan_edit'] = array(
            'title' => __t('punggung_bunyi_pernafasan edit'),
            'description' => __t('Editing bunyi_pernafasan reference form for punggung'),
            'path' => '/reference/punggung_bunyi_pernafasan/edit',
            'exec' => 'ref_bunyi_pernafasan_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_punggung_bunyi_pernafasan_drop'] = array(
            'title' => __t('punggung_bunyi_pernafasan drop'),
            'description' => __t('Remove bunyi_pernafasan reference form for punggung'),
            'path' => '/reference/punggung_bunyi_pernafasan/drop',
            'exec' => 'ref_bunyi_pernafasan_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_punggung_bunyi_tambahan'] = array(
            'title' => __t('punggung_bunyi_tambahan'),
            'description' => __t('bunyi_tambahan reference form for punggung'),
            'path' => '/reference/punggung_bunyi_tambahan',
            'exec' => 'ref_bunyi_tambahan_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_punggung_bunyi_tambahan_detail'] = array(
            'title' => __t('detil punggung_bunyi_tambahan'),
            'description' => __t('bunyi_tambahan reference detail for punggung'),
            'path' => '/reference/punggung_bunyi_tambahan/detail',
            'exec' => 'ref_bunyi_tambahan_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_punggung_bunyi_tambahan_form'] = array(
            'title' => __t('punggung_bunyi_tambahan form'),
            'description' => __t('bunyi_tambahan reference form for punggung'),
            'path' => '/reference/punggung_bunyi_tambahan/form',
            'exec' => 'ref_bunyi_tambahan_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_punggung_bunyi_tambahan_form_submit'] = array(
            'title' => __t('punggung_bunyi_tambahan form'),
            'description' => __t('Execute bunyi_tambahan reference form for punggung'),
            'path' => '/reference/punggung_bunyi_tambahan/form_submit',
            'exec' => 'ref_bunyi_tambahan_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_punggung_bunyi_tambahan_edit'] = array(
            'title' => __t('punggung_bunyi_tambahan edit'),
            'description' => __t('Editing bunyi_tambahan reference form for punggung'),
            'path' => '/reference/punggung_bunyi_tambahan/edit',
            'exec' => 'ref_bunyi_tambahan_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_punggung_bunyi_tambahan_drop'] = array(
            'title' => __t('punggung_bunyi_tambahan drop'),
            'description' => __t('Remove bunyi_tambahan reference form for punggung'),
            'path' => '/reference/punggung_bunyi_tambahan/drop',
            'exec' => 'ref_bunyi_tambahan_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_punggung_others'] = array(
            'title' => __t('punggung_others'),
            'description' => __t('others reference form for punggung'),
            'path' => '/reference/punggung_others',
            'exec' => 'ref_others_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_punggung_others_detail'] = array(
            'title' => __t('detil punggung_others'),
            'description' => __t('others reference detail for punggung'),
            'path' => '/reference/punggung_others/detail',
            'exec' => 'ref_others_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_punggung_others_form'] = array(
            'title' => __t('punggung_others form'),
            'description' => __t('others reference form for punggung'),
            'path' => '/reference/punggung_others/form',
            'exec' => 'ref_others_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_punggung_others_form_submit'] = array(
            'title' => __t('punggung_others form'),
            'description' => __t('Execute others reference form for punggung'),
            'path' => '/reference/punggung_others/form_submit',
            'exec' => 'ref_others_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_punggung_others_edit'] = array(
            'title' => __t('punggung_others edit'),
            'description' => __t('Editing others reference form for punggung'),
            'path' => '/reference/punggung_others/edit',
            'exec' => 'ref_others_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_punggung_others_drop'] = array(
            'title' => __t('punggung_others drop'),
            'description' => __t('Remove others reference form for punggung'),
            'path' => '/reference/punggung_others/drop',
            'exec' => 'ref_others_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        return $items;
    }

    function ref_inspections_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi inspeksi punggung');
        $result['description'] = __t('Referensi pilihan inspeksi punggung pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/punggung_inspections/form',
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
            array('ref_punggung_inspections'),
            NULL,
            'inspections'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['inspections'] = ucwords($query->fields['inspections']);
                $result['data'][$i]['goto'] = '/reference/punggung_inspections/detail/' . $query->fields['id'];
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
            '#title' => __t('add punggung_inspections'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'inspections',
            '#weight' => -3,
            '#action' => '/reference/punggung_inspections/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_punggung_inspections');
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
                    redirect_to('/reference/punggung_inspections/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_punggung_inspections', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_punggung_inspections',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/punggung_inspections');
//        } else {
//            redirect_to('/reference/punggung_inspections/form');
//        }
    }

    function ref_inspections_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'inspections', 'punggung', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi inspections');
        $result['description'] = __t('informasi detil referensi inspections yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/punggung_inspections/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'inspections'),
            array('ref_punggung_inspections'),
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
                'link' => '/reference/punggung_inspections/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/punggung_inspections/edit/',
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
                if(in_array($key, $this->__get_data_fields('ref_punggung_inspections', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_punggung_inspections',
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
        redirect_to('/reference/punggung_inspections/detail/' . $_POST['id']);
    }

    function ref_inspections_drop(){
        if($this->__is_dropable($_POST['id'], 'inspections', 'punggung', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_punggung_inspections',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/punggung_inspections');
    }

    function ref_palpations_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi palpations punggung');
        $result['description'] = __t('Referensi pilihan palpations punggung pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/punggung_palpations/form',
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
                'field' => 'palpations',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_punggung_palpations'),
            NULL,
            'palpations'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['palpations'] = ucwords($query->fields['palpations']);
                $result['data'][$i]['goto'] = '/reference/punggung_palpations/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_palpations_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add punggung_palpations'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'palpations',
            '#weight' => -3,
            '#action' => '/reference/punggung_palpations/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_punggung_palpations');
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

    function ref_palpations_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/punggung_palpations/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_punggung_palpations', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_punggung_palpations',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/punggung_palpations');
//        } else {
//            redirect_to('/reference/punggung_palpations/form');
//        }
    }

    function ref_palpations_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'palpations', 'punggung', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi palpations');
        $result['description'] = __t('informasi detil referensi palpations yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/punggung_palpations/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'palpations'),
            array('ref_punggung_palpations'),
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
                'link' => '/reference/punggung_palpations/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/punggung_palpations/edit/',
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

    function ref_palpations_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_punggung_palpations', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_punggung_palpations',
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
        redirect_to('/reference/punggung_palpations/detail/' . $_POST['id']);
    }

    function ref_palpations_drop(){
        if($this->__is_dropable($_POST['id'], 'palpations', 'punggung', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_punggung_palpations',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/punggung_palpations');
    }

    function ref_bunyi_pernafasan_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi bunyi_pernafasan punggung');
        $result['description'] = __t('Referensi pilihan bunyi_pernafasan punggung pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/punggung_bunyi_pernafasan/form',
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
                'field' => 'bunyi_pernafasan',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_punggung_bunyi_pernafasan'),
            NULL,
            'bunyi_pernafasan'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['bunyi_pernafasan'] = ucwords($query->fields['bunyi_pernafasan']);
                $result['data'][$i]['goto'] = '/reference/punggung_bunyi_pernafasan/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_bunyi_pernafasan_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add punggung_bunyi_pernafasan'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'bunyi_pernafasan',
            '#weight' => -3,
            '#action' => '/reference/punggung_bunyi_pernafasan/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_punggung_bunyi_pernafasan');
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

    function ref_bunyi_pernafasan_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/punggung_bunyi_pernafasan/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_punggung_bunyi_pernafasan', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_punggung_bunyi_pernafasan',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/punggung_bunyi_pernafasan');
//        } else {
//            redirect_to('/reference/punggung_bunyi_pernafasan/form');
//        }
    }

    function ref_bunyi_pernafasan_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'bunyi_pernafasan', 'punggung', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi bunyi_pernafasan');
        $result['description'] = __t('informasi detil referensi bunyi_pernafasan yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/punggung_bunyi_pernafasan/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'bunyi_pernafasan'),
            array('ref_punggung_bunyi_pernafasan'),
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
                'link' => '/reference/punggung_bunyi_pernafasan/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/punggung_bunyi_pernafasan/edit/',
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

    function ref_bunyi_pernafasan_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_punggung_bunyi_pernafasan', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_punggung_bunyi_pernafasan',
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
        redirect_to('/reference/punggung_bunyi_pernafasan/detail/' . $_POST['id']);
    }

    function ref_bunyi_pernafasan_drop(){
        if($this->__is_dropable($_POST['id'], 'bunyi_pernafasan', 'punggung', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_punggung_bunyi_pernafasan',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/punggung_bunyi_pernafasan');
    }

    function ref_bunyi_tambahan_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi bunyi_tambahan punggung');
        $result['description'] = __t('Referensi pilihan bunyi_tambahan punggung pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/punggung_bunyi_tambahan/form',
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
                'field' => 'bunyi_tambahan',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_punggung_bunyi_tambahan'),
            NULL,
            'bunyi_tambahan'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['bunyi_tambahan'] = ucwords($query->fields['bunyi_tambahan']);
                $result['data'][$i]['goto'] = '/reference/punggung_bunyi_tambahan/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_bunyi_tambahan_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add punggung_bunyi_tambahan'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'bunyi_tambahan',
            '#weight' => -3,
            '#action' => '/reference/punggung_bunyi_tambahan/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_punggung_bunyi_tambahan');
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

    function ref_bunyi_tambahan_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/punggung_bunyi_tambahan/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_punggung_bunyi_tambahan', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_punggung_bunyi_tambahan',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/punggung_bunyi_tambahan');
//        } else {
//            redirect_to('/reference/punggung_bunyi_tambahan/form');
//        }
    }

    function ref_bunyi_tambahan_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'bunyi_tambahan', 'punggung', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi bunyi_tambahan');
        $result['description'] = __t('informasi detil referensi bunyi_tambahan yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/punggung_bunyi_tambahan/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'bunyi_tambahan'),
            array('ref_punggung_bunyi_tambahan'),
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
                'link' => '/reference/punggung_bunyi_tambahan/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/punggung_bunyi_tambahan/edit/',
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

    function ref_bunyi_tambahan_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_punggung_bunyi_tambahan', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_punggung_bunyi_tambahan',
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
        redirect_to('/reference/punggung_bunyi_tambahan/detail/' . $_POST['id']);
    }

    function ref_bunyi_tambahan_drop(){
        if($this->__is_dropable($_POST['id'], 'bunyi_tambahan', 'punggung', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_punggung_bunyi_tambahan',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/punggung_bunyi_tambahan');
    }

    function ref_others_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi others punggung');
        $result['description'] = __t('Referensi pilihan others punggung pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/punggung_others/form',
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
                'field' => 'others',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_punggung_others'),
            NULL,
            'others'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['others'] = ucwords($query->fields['others']);
                $result['data'][$i]['goto'] = '/reference/punggung_others/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_others_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add punggung_others'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'others',
            '#weight' => -3,
            '#action' => '/reference/punggung_others/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_punggung_others');
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

    function ref_others_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/punggung_others/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_punggung_others', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_punggung_others',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/punggung_others');
//        } else {
//            redirect_to('/reference/punggung_others/form');
//        }
    }

    function ref_others_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'others', 'punggung', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi others');
        $result['description'] = __t('informasi detil referensi others yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/punggung_others/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'others'),
            array('ref_punggung_others'),
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
                'link' => '/reference/punggung_others/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/punggung_others/edit/',
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

    function ref_others_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_punggung_others', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_punggung_others',
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
        redirect_to('/reference/punggung_others/detail/' . $_POST['id']);
    }

    function ref_others_drop(){
        if($this->__is_dropable($_POST['id'], 'others', 'punggung', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_punggung_others',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/punggung_others');
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
        $result['#title'] = __t('Punggung');
        $result['#tpl'] = MODULES_DIR . DS . 'punggung' . DS . 'punggung.tpl';
        $datafields = $this->__get_data_fields('punggung', $this->query);
        if (count($this->config->free_val) > 0){
            $vcache = $this->config->free_val;
            $sql = $this->query->getSelect(
                array(),
                array('panggung'),
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
        $thefields = $this->__get_data_fields('punggung', $this->query);
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
            $opr = 'update';
            $strid = array('id', $_POST['id']);
        } else {
            $opr = 'insert';
            $strid = array('id', $thevalue['id']);
        }
        $this->__exec_db_ops(
            $this->query,
            'punggung',
            $opr,
            $strid,
            $thevalue
        );
        unset($thevalue, $opr, $strid);
    }


}