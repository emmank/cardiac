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
 *  pemeriksaanclass.php
 *  
 *  Created on Oct 3, 2009, 4:35:17 PM
 */

require_once MODULES_DIR . DS . 'pemeriksaan' . DS . 'config.inc';

class pemeriksaanModule extends mainModule
{
    var $title = 'pemeriksaan module';
    var $description = '';

    function menu(){
        $items['ref_present_nutrient'] = array(
            'title' => __t('gizi'),
            'description' => __t('nutrient reference for present status'),
            'path' => '/reference/nutrient',
            'exec' => 'nutrient_view',
            'weight' => 5,
            'user_required' => NULL
        );
        $items['ref_present_nutrient_detail'] = array(
            'title' => __t('nutrient detail'),
            'description' => __t('nutrient reference detail for present status'),
            'path' => '/reference/nutrient/detail',
            'exec' => 'nutrient_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_present_nutrient_form'] = array(
            'title' => __t('nutrient form'),
            'description' => __t('nutrient reference form for present status'),
            'path' => '/reference/nutrient/form',
            'exec' => 'nutrient_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_present_nutrient_form_submit'] = array(
            'title' => __t('nutrient form'),
            'description' => __t('Execute nutrient reference form for present status'),
            'path' => '/reference/nutrient/form_submit',
            'exec' => 'nutrient_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_present_nutrient_edit'] = array(
            'title' => __t('nutrient edit'),
            'description' => __t('Editing nutrient reference form for present status'),
            'path' => '/reference/nutrient/edit',
            'exec' => 'nutrient_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_present_nutrient_drop'] = array(
            'title' => __t('nutrient drop'),
            'description' => __t('Remove nutrient reference form for present status'),
            'path' => '/reference/nutrient/drop',
            'exec' => 'nutrient_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
         $items['ref_present_soreness'] = array(
            'title' => __t('Keluhan Utama'),
            'description' => __t('soreness reference form for present status'),
            'path' => '/reference/soreness',
            'exec' => 'soreness_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_present_soreness_detail'] = array(
            'title' => __t('detil keluhan'),
            'description' => __t('soreness reference detail for present status'),
            'path' => '/reference/soreness/detail',
            'exec' => 'soreness_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_present_soreness_form'] = array(
            'title' => __t('soreness form'),
            'description' => __t('soreness reference form for present status'),
            'path' => '/reference/soreness/form',
            'exec' => 'soreness_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_present_soreness_form_submit'] = array(
            'title' => __t('soreness form'),
            'description' => __t('Execute soreness reference form for present status'),
            'path' => '/reference/soreness/form_submit',
            'exec' => 'soreness_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_present_soreness_edit'] = array(
            'title' => __t('soreness edit'),
            'description' => __t('Editing soreness reference form for present status'),
            'path' => '/reference/soreness/edit',
            'exec' => 'soreness_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_present_soreness_drop'] = array(
            'title' => __t('soreness drop'),
            'description' => __t('Remove soreness reference form for present status'),
            'path' => '/reference/soreness/drop',
            'exec' => 'soreness_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_present_risk_factor'] = array(
            'title' => __t('Faktor Resiko'),
            'description' => __t('risk_factor reference form for present status'),
            'path' => '/reference/risk_factor',
            'exec' => 'ref_risk_factor_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_present_risk_factor_detail'] = array(
            'title' => __t('detil keluhan'),
            'description' => __t(' risk_factor reference detail for present status'),
            'path' => '/reference/risk_factor/detail',
            'exec' => 'ref_risk_factor_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_present_risk_factor_form'] = array(
            'title' => __t('risk_factor form'),
            'description' => __t(' risk_factor reference form for present status'),
            'path' => '/reference/risk_factor/form',
            'exec' => 'ref_risk_factor_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_present_risk_factor_form_submit'] = array(
            'title' => __t('risk_factor form'),
            'description' => __t('Execute risk_factor reference form for present status'),
            'path' => '/reference/risk_factor/form_submit',
            'exec' => 'ref_risk_factor_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_present_risk_factor_edit'] = array(
            'title' => __t('risk_factor edit'),
            'description' => __t('Editing  risk_factor reference form for present status'),
            'path' => '/reference/risk_factor/edit',
            'exec' => 'ref_risk_factor_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_present_risk_factor_drop'] = array(
            'title' => __t('risk_factor drop'),
            'description' => __t('Remove  risk_factor reference form for present status'),
            'path' => '/reference/risk_factor/drop',
            'exec' => 'ref_risk_factor_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_present_illness_history'] = array(
            'title' => __t('Riwayat Penyakit'),
            'description' => __t('illness_history reference form for present status'),
            'path' => '/reference/illness_history',
            'exec' => 'ref_illness_history_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_present_illness_history_detail'] = array(
            'title' => __t('detil keluhan'),
            'description' => __t('illness_history reference detail for present status'),
            'path' => '/reference/illness_history/detail',
            'exec' => 'ref_illness_history_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_present_illness_history_form'] = array(
            'title' => __t('illness_history form'),
            'description' => __t('illness_history reference form for present status'),
            'path' => '/reference/illness_history/form',
            'exec' => 'ref_illness_history_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_present_illness_history_form_submit'] = array(
            'title' => __t('illness_history form'),
            'description' => __t('Execute illness_history reference form for present status'),
            'path' => '/reference/illness_history/form_submit',
            'exec' => 'ref_illness_history_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_present_illness_history_edit'] = array(
            'title' => __t('illness_history edit'),
            'description' => __t('Editing illness_history reference form for present status'),
            'path' => '/reference/illness_history/edit',
            'exec' => 'ref_illness_history_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_present_illness_history_drop'] = array(
            'title' => __t('illness_history drop'),
            'description' => __t('Remove illness_history reference form for present status'),
            'path' => '/reference/illness_history/drop',
            'exec' => 'ref_illness_history_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
       return $items;
    }

    function nutrient_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Gizi');
        $result['description'] = __t('Referensi isian gizi yang dipakai untuk menilai kadar suatu keadaan terkini pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/nutrient/form',
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
                'field' => 'nutrient',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_present_nutrient'),
            NULL,
            'nutrient'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['nutrient'] = ucwords($query->fields['nutrient']);
                $result['data'][$i]['goto'] = '/reference/nutrient/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function nutrient_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add nutrient'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'nutrient',
            '#weight' => -3,
            '#action' => '/reference/nutrient/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_present_nutrient');
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

    function nutrient_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/nutrient/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_present_nutrient', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_present_nutrient',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/nutrient');
//        } else {
//            redirect_to('/reference/cardionutrient/form');
//        }
    }

    function nutrient_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'nutrient', 'pemeriksaan', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi gizi');
        $result['description'] = __t('informasi detil referensi gizi yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/nutrient/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'nutrient'),
            array('ref_present_nutrient'),
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
                'link' => '/reference/nutrient/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/nutrient/edit/',
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

    function nutrient_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_present_nutrient', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_present_nutrient',
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
        redirect_to('/reference/nutrient/detail/' . $_POST['id']);
    }

    function nutrient_drop(){
        if($this->__is_dropable($_POST['id'], 'nutrient', 'pemeriksaan', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_present_nutrient',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/nutrient');
    }

    function soreness_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Keluhan Utama');
        $result['description'] = __t('Referensi isian keluhan yang dirasakan pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/soreness/form',
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
                'field' => 'soreness',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_present_soreness'),
            NULL,
            'soreness'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['soreness'] = ucwords($query->fields['soreness']);
                $result['data'][$i]['goto'] = '/reference/soreness/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function soreness_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add soreness'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'soreness',
            '#weight' => -3,
            '#action' => '/reference/soreness/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_present_soreness');
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

    function soreness_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/soreness/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_present_soreness', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_present_soreness',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/soreness');
//        } else {
//            redirect_to('/reference/cardiosoreness/form');
//        }
    }

    function soreness_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'soreness', 'pemeriksaan', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi gizi');
        $result['description'] = __t('informasi detil referensi gizi yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/soreness/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'soreness'),
            array('ref_present_soreness'),
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
                'link' => '/reference/soreness/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/soreness/edit/',
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

    function soreness_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_present_soreness', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_present_soreness',
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
        redirect_to('/reference/soreness/detail/' . $_POST['id']);
    }

    function soreness_drop(){
        if($this->__is_dropable($_POST['id'], 'soreness', 'pemeriksaan', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_present_soreness',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/soreness');
    }

    function ref_risk_factor_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Faktor Resiko');
        $result['description'] = __t('Referensi isian faktor resiko pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/risk_factor/form',
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
                'field' => 'risk_factor',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_present_risk_factor'),
            NULL,
            'risk_factor'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['risk_factor'] = ucwords($query->fields['risk_factor']);
                $result['data'][$i]['goto'] = '/reference/risk_factor/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_risk_factor_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add risk_factor'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'risk_factor',
            '#weight' => -3,
            '#action' => '/reference/risk_factor/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_present_risk_factor');
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

    function ref_risk_factor_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/risk_factor/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_present_risk_factor', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_present_risk_factor',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/risk_factor');
//        } else {
//            redirect_to('/reference/risk_factor/form');
//        }
    }

    function ref_risk_factor_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'risk_factor', 'pemeriksaan', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi gizi');
        $result['description'] = __t('informasi detil referensi gizi yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/risk_factor/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'risk_factor'),
            array('ref_present_risk_factor'),
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
                'link' => '/reference/risk_factor/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/risk_factor/edit/',
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

    function ref_risk_factor_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_present_risk_factor', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_present_risk_factor',
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
        redirect_to('/reference/risk_factor/detail/' . $_POST['id']);
    }

    function ref_risk_factor_drop(){
        if($this->__is_dropable($_POST['id'], 'risk_factor', 'pemeriksaan', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_present_risk_factor',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/risk_factor');
    }

    function ref_illness_history_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Riwayat Penyakit');
        $result['description'] = __t('Referensi isian riwayat penyakit pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/illness_history/form',
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
                'field' => 'illness_history',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_present_illness_history'),
            NULL,
            'illness_history'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['illness_history'] = ucwords($query->fields['illness_history']);
                $result['data'][$i]['goto'] = '/reference/illness_history/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_illness_history_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add illness_history'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'illness_history',
            '#weight' => -3,
            '#action' => '/reference/illness_history/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_present_illness_history');
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

    function ref_illness_history_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/illness_history/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_present_illness_history', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_present_illness_history',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/illness_history');
//        } else {
//            redirect_to('/reference/illness_history/form');
//        }
    }

    function ref_illness_history_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'illness_history', 'pemeriksaan', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi gizi');
        $result['description'] = __t('informasi detil referensi gizi yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/illness_history/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'illness_history'),
            array('ref_present_illness_history'),
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
                'link' => '/reference/illness_history/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/illness_history/edit/',
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

    function ref_illness_history_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_present_illness_history', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_present_illness_history',
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
        redirect_to('/reference/illness_history/detail/' . $_POST['id']);
    }

    function ref_illness_history_drop(){
        if($this->__is_dropable($_POST['id'], 'illness_history', 'pemeriksaan', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_present_illness_history',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/illness_history');
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

    function perawatan_menu(){
        $result = array();
        $result['#title'] = __t('pemeriksaan');
        $result['#tpl'] = MODULES_DIR . DS . 'pemeriksaan' . DS . 'pemeriksaan.tpl';
        $datafields = $this->__get_data_fields('pemeriksaan', $this->query);
        if (count($this->config->free_val) > 0){
            $vcache = $this->config->free_val;
            $sql = $this->query->getSelect(
                array(),
                array('pemeriksaan'),
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
            if($value == 'catched'){
                if(!isset($vcache['catched']) || $vcache['catched'] == ''){
                    $vcache['catched'] = date('Y-m-d H:i:s', $this->config->time);
                }
            }
            $result['datafields'][$value] = array(
                'title' => __t($value),
                'type' => $this->config->typeoffields[$value],
                'value' => isset($vcache[$value]) ? $vcache[$value] : ''
            );
            if(in_array($value, $this->config->fieldsisarray)){
                $result['datafields'][$value]['theref'] = $this->__get_refs($value);
                $result['datafields'][$value]['blankopt'] = 1;
            } elseif($this->config->typeoffields[$value] == 'datetime'){
                $result['datafields'][$value]['theref'] = $this->nama_bulan;
                $result['datafields'][$value]['timenow'] = $this->config->time;
            } else {
                $result['datafields'][$value]['size'] = 6;
            }
            $result['datafields'][$value]['readonly'] = isset($this->config->free_val['readonly']) ? true : false;
        }
        // add by emk
        $result['data']['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => 'tgl_periksa',
                'caption' => __t('Tgl periksa'),
                'align' => 'left'
            ),
            array(
                'field' => 'tensi_sistolik',
                'caption' => __t('Tensi Sistolik'),
                'align' => 'left'
            ),
            array(
                'field' => 'tensi_diastolik',
                'caption' => __t('Tensi__diastolik'),
                'align' => 'left'
            ),
            array(
                'field' => 'nps',
                'caption' => __t('NPS'),
                'align' => 'left'
            ),
            array(
                'field' => 'kesadaran',
                'caption' => __t('Kesadaran'),
                'align' => 'left'
            ),
            array(
                'field' => 'penivien',
                'caption' => __t('penivien'),
                'align' => 'left'
            ),
            array(
                'field' => 'pemasukan',
                'caption' => __t('Pemasukan'),
                'align' => 'left'
            ),
            array(
                'field' => 'pengeluaran',
                'caption' => __t('Pengeluaran'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('pemeriksaan'),
            NULL,
            'tgl_periksa'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['tgl_periksa'] = ucwords($query->fields['tgl_periksa']);
                $result['data'][$i]['goto'] = '/reference/tgl_periksa/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function cardio_submit(){
        $thefields = $this->__get_data_fields('pemeriksaan', $this->query);
        foreach($this->config->free_val as $key => $value){
            if(in_array($key, $thefields)){
                if($key == 'catched'){
                    $value = $value[0] . '-' . $value[1] . '-' . $value[2] . ' ' . $value[3] . ':' . $value[4] . ':' . $value[5];
                } elseif($key == 'risk_factor' || $key == 'ilness_history'){
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
                'pemeriksaan',
                $thevalue,
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
        } else {
            $sql = $this->query->saveData(
                'pemeriksaan',
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