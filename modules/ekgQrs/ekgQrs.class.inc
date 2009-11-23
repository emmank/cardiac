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
 *  ekgQrsclass.php
 *  
 *  Created on Oct 3, 2009, 8:39:24 PM
 */

require_once MODULES_DIR . DS . 'ekgQrs' . DS . 'config.inc';

class ekgQrsModule extends mainModule
{
    var $title = 'ekgQrs module';
    var $description = '';

    function menu(){
//---------------------------1. Axis -------------------------------------------
        $items['ref_ekgQrs_axis'] = array(
            'title' => __t('axis'),
            'description' => __t('axis reference form for ekgQrs'),
            'path' => '/reference/ekgQrs_axis',
            'exec' => 'ref_axis_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_ekgQrs_axis_detail'] = array(
            'title' => __t('detil axis fase latihan'),
            'description' => __t('axis reference detail for ekgQrs'),
            'path' => '/reference/ekgQrs_axis/detail',
            'exec' => 'ref_axis_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_ekgQrs_axis_form'] = array(
            'title' => __t('ekgQrs_axis form'),
            'description' => __t('axis reference form for ekgQrs'),
            'path' => '/reference/ekgQrs_axis/form',
            'exec' => 'ref_axis_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekgQrs_axis_form_submit'] = array(
            'title' => __t('ekgQrs_axis form'),
            'description' => __t('Execute axis reference form for ekgQrs'),
            'path' => '/reference/ekgQrs_axis/form_submit',
            'exec' => 'ref_axis_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekgQrs_axis_edit'] = array(
            'title' => __t('ekgQrs_axis edit'),
            'description' => __t('Editing axis reference form for ekgQrs'),
            'path' => '/reference/ekgQrs_axis/edit',
            'exec' => 'ref_axis_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekgQrs_axis_drop'] = array(
            'title' => __t('ekgQrs_axis drop'),
            'description' => __t('Remove axis reference form for ekgQrs'),
            'path' => '/reference/ekgQrs_axis/drop',
            'exec' => 'ref_axis_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );

//-------------------------2. Durasi--------------------------------------------
        $items['ref_ekgQrs_durasi'] = array(
            'title' => __t('durasi'),
            'description' => __t('durasi reference form for ekgQrs'),
            'path' => '/reference/ekgQrs_durasi',
            'exec' => 'ref_durasi_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_ekgQrs_durasi_detail'] = array(
            'title' => __t('detil durasi'),
            'description' => __t('durasi reference detail for ekgQrs'),
            'path' => '/reference/ekgQrs_durasi/detail',
            'exec' => 'ref_durasi_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_ekgQrs_durasi_form'] = array(
            'title' => __t('ekgQrs_durasi form'),
            'description' => __t('durasi reference form for ekgQrs'),
            'path' => '/reference/ekgQrs_durasi/form',
            'exec' => 'ref_durasi_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekgQrs_durasi_form_submit'] = array(
            'title' => __t('ekgQrs_durasi form'),
            'description' => __t('Execute durasi reference form for ekgQrs'),
            'path' => '/reference/ekgQrs_durasi/form_submit',
            'exec' => 'ref_durasi_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekgQrs_durasi_edit'] = array(
            'title' => __t('ekgQrs_durasi edit'),
            'description' => __t('Editing durasi reference form for ekgQrs'),
            'path' => '/reference/ekgQrs_durasi/edit',
            'exec' => 'ref_durasi_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekgQrs_durasi_drop'] = array(
            'title' => __t('ekgQrs_durasi drop'),
            'description' => __t('Remove durasi reference form for ekgQrs'),
            'path' => '/reference/ekgQrs_durasi/drop',
            'exec' => 'ref_durasi_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );

//-----------------------------3. Q Patologi -----------------------------------
        $items['ref_ekgQrs_Qpatologi'] = array(
            'title' => __t('Qpatologi'),
            'description' => __t('Qpatologi reference form for ekgQrs'),
            'path' => '/reference/ekgQrs_Qpatologi',
            'exec' => 'ref_Qpatologi_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_ekgQrs_Qpatologi_detail'] = array(
            'title' => __t('detil perubahan gelombang R'),
            'description' => __t('Qpatologi reference detail for ekgQrs'),
            'path' => '/reference/ekgQrs_Qpatologi/detail',
            'exec' => 'ref_Qpatologi_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_ekgQrs_Qpatologi_form'] = array(
            'title' => __t('ekgQrs_Qpatologi form'),
            'description' => __t('Qpatologi reference form for ekgQrs'),
            'path' => '/reference/ekgQrs_Qpatologi/form',
            'exec' => 'ref_Qpatologi_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekgQrs_Qpatologi_form_submit'] = array(
            'title' => __t('ekgQrs_Qpatologi form'),
            'description' => __t('Execute Qpatologi reference form for ekgQrs'),
            'path' => '/reference/ekgQrs_Qpatologi/form_submit',
            'exec' => 'ref_Qpatologi_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekgQrs_Qpatologi_edit'] = array(
            'title' => __t('ekgQrs_Qpatologi edit'),
            'description' => __t('Editing Qpatologi reference form for ekgQrs'),
            'path' => '/reference/ekgQrs_Qpatologi/edit',
            'exec' => 'ref_Qpatologi_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekgQrs_Qpatologi_drop'] = array(
            'title' => __t('ekgQrs_Qpatologi drop'),
            'description' => __t('Remove Qpatologi reference form for ekgQrs'),
            'path' => '/reference/ekgQrs_Qpatologi/drop',
            'exec' => 'ref_Qpatologi_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        
//----------------------------4. R > S--------------------------------
        $items['ref_ekgQrs_RlbS'] = array(
            'title' => __t('RlbS'),
            'description' => __t('RlbS reference form for ekgQrs'),
            'path' => '/reference/ekgQrs_RlbS',
            'exec' => 'ref_RlbS_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_ekgQrs_RlbS_detail'] = array(
            'title' => __t('detil RlbS QRS Complex'),
            'description' => __t('RlbS reference detail for ekgQrs'),
            'path' => '/reference/ekgQrs_RlbS/detail',
            'exec' => 'ref_RlbS_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_ekgQrs_RlbS_form'] = array(
            'title' => __t('ekgQrs_RlbS form'),
            'description' => __t('RlbS reference form for ekgQrs'),
            'path' => '/reference/ekgQrs_RlbS/form',
            'exec' => 'ref_RlbS_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekgQrs_RlbS_form_submit'] = array(
            'title' => __t('ekgQrs_RlbS form'),
            'description' => __t('Execute RlbS reference form for ekgQrs'),
            'path' => '/reference/ekgQrs_RlbS/form_submit',
            'exec' => 'ref_RlbS_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekgQrs_RlbS_edit'] = array(
            'title' => __t('ekgQrs_RlbS edit'),
            'description' => __t('Editing RlbS reference form for ekgQrs'),
            'path' => '/reference/ekgQrs_RlbS/edit',
            'exec' => 'ref_RlbS_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekgQrs_RlbS_drop'] = array(
            'title' => __t('ekgQrs_RlbS drop'),
            'description' => __t('Remove RlbS reference form for ekgQrs'),
            'path' => '/reference/ekgQrs_RlbS/drop',
            'exec' => 'ref_RlbS_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );

        //----------------------------respon_jantung----------------------------
        
        return $items;
    }

    function ref_axis_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi axis fase latihan');
        $result['description'] = __t('Referensi isian axis fase latihan');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/ekgQrs_axis/form',
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
                'field' => 'axis',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_ekgQrs_axis'),
            NULL
           
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['type'] = ucwords($query->fields['axis']);
                $result['data'][$i]['goto'] = '/reference/ekgQrs_axis/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_axis_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add ekgQrs_axis'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'axis',
            '#weight' => -3,
            '#action' => '/reference/ekgQrs_axis/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_ekgQrs_axis');
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

    function ref_axis_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/ekgQrs_axis/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_ekgQrs_axis', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_ekgQrs_axis',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/ekgQrs_axis');
//        } else {
//            redirect_to('/reference/ekgQrs_axis/form');
//        }
    }

    function ref_axis_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'axis', 'ekg_Qrs_axis', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi axis fase latihan');
        $result['description'] = __t('informasi detil referensi axis fase latihan yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/ekgQrs_axis/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'axis'),
            array('ref_ekgQrs_axis'),
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
                'link' => '/reference/ekgQrs_axis/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/ekgQrs_axis/edit/',
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

    function ref_axis_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_ekgQrs_axis', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_ekgQrs_axis',
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
        redirect_to('/reference/ekgQrs_axis/detail/' . $_POST['id']);
    }

    function ref_axis_drop(){
        if($this->__is_dropable($_POST['id'], 'axis', 'ekg_Qrs_axis', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_ekgQrs_axis',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/ekgQrs_axis');
    }

//--------------------------2. durasi ------------------------------------------
    function ref_durasi_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi konfigurasi');
        $result['description'] = __t('Referensi isian konfigurasi');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/ekgQrs_durasi/form',
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
                'field' => 'durasi',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_ekgQrs_durasi'),
            NULL
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['durasi'] = ucwords($query->fields['durasi']);
                $result['data'][$i]['goto'] = '/reference/ekgQrs_durasi/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_durasi_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add ekgQrs_durasi'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'durasi',
            '#weight' => -3,
            '#action' => '/reference/ekgQrs_durasi/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_ekgQrs_durasi');
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

    function ref_durasi_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/ekgQrs_durasi/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_ekgQrs_durasi', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_ekgQrs_durasi',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/ekgQrs_durasi');
//        } else {
//            redirect_to('/reference/ekgQrs_durasi/form');
//        }
    }

    function ref_durasi_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'durasi', 'ekg_Qrs_durasi', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi konfigurasi');
        $result['description'] = __t('informasi detil referensi konfigurasi yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/ekgQrs_durasi/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'durasi'),
            array('ref_ekgQrs_durasi'),
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
                'link' => '/reference/ekgQrs_durasi/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/ekgQrs_durasi/edit/',
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

    function ref_durasi_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_ekgQrs_durasi', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_ekgQrs_durasi',
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
        redirect_to('/reference/ekgQrs_durasi/detail/' . $_POST['id']);
    }

    function ref_durasi_drop(){
        if($this->__is_dropable($_POST['id'], 'durasi', 'ekgQrs_durasi', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_ekgQrs_durasi',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/ekgQrs_durasi');
    }

//---------------------------3. Q patologi -------------------------------------
    function ref_Qpatologi_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Qpatologi');
        $result['description'] = __t('Referensi isian Qpatologi pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/ekgQrs_Qpatologi/form',
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
                'field' => 'Qpatologi',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_ekgQrs_Qpatologi'),
            NULL
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['Qpatologi'] = ucwords($query->fields['Qpatologi']);
                $result['data'][$i]['goto'] = '/reference/ekgQrs_Qpatologi/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_Qpatologi_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add ekgQrs_Qpatologi'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'Qpatologi',
            '#weight' => -3,
            '#action' => '/reference/ekgQrs_Qpatologi/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_ekgQrs_Qpatologi');
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

    function ref_Qpatologi_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/ekgQrs_Qpatologi/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_ekgQrs_Qpatologi', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_ekgQrs_Qpatologi',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/ekgQrs_Qpatologi');
//        } else {
//            redirect_to('/reference/ekgQrs_Qpatologi/form');
//        }
    }

    function ref_Qpatologi_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'Qpatologi', 'ekg_Qrs_Qpatologi', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi Qpatologi');
        $result['description'] = __t('informasi detil referensi Qpatologi yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/ekgQrs_Qpatologi/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'Qpatologi'),
            array('ref_ekgQrs_Qpatologi'),
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
                'link' => '/reference/ekgQrs_Qpatologi/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/ekgQrs_Qpatologi/edit/',
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

    function ref_Qpatologi_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_ekgQrs_Qpatologi', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_ekgQrs_Qpatologi',
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
        redirect_to('/reference/ekgQrs_Qpatologi/detail/' . $_POST['id']);
    }

    function ref_Qpatologi_drop(){
        if($this->__is_dropable($_POST['id'], 'Qpatologi', 'ekg_Qrs_Qpatologi', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_ekgQrs_Qpatologi',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/ekgQrs_Qpatologi');
    }

//-----------------------------4. RlbS -----------------------------------------
    function ref_RlbS_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi RlbS fase latihan');
        $result['description'] = __t('Referensi isian RlbS fase latihan');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/ekgQrs_RlbS/form',
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
                'field' => 'RlbS',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_ekgQrs_RlbS'),
            NULL
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['type'] = ucwords($query->fields['RlbS']);
                $result['data'][$i]['goto'] = '/reference/ekgQrs_RlbS/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_RlbS_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add ekgQrs_RlbS'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'RlbS',
            '#weight' => -3,
            '#action' => '/reference/ekgQrs_RlbS/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_ekgQrs_RlbS');
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

    function ref_RlbS_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/ekgQrs_RlbS/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_ekgQrs_RlbS', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_ekgQrs_RlbS',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/ekgQrs_RlbS');
//        } else {
//            redirect_to('/reference/ekgQrs_RlbS/form');
//        }
    }

    function ref_RlbS_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'RlbS', 'fase_latihan', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi RlbS fase latihan');
        $result['description'] = __t('informasi detil referensi RlbS fase latihan yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/ekgQrs_RlbS/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'RlbS'),
            array('ref_ekgQrs_RlbS'),
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
                'link' => '/reference/ekgQrs_RlbS/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/ekgQrs_RlbS/edit/',
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

    function ref_RlbS_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_ekgQrs_RlbS', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_ekgQrs_RlbS',
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
        redirect_to('/reference/ekgQrs_RlbS/detail/' . $_POST['id']);
    }

    function ref_RlbS_drop(){
        if($this->__is_dropable($_POST['id'], 'RlbS', 'fase_latihan', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_ekgQrs_RlbS',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/ekgQrs_RlbS');
    }

    

}