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
 *  holterrefclass.php
 *  
 *  Created on Oct 3, 2009, 8:39:24 PM
 */

require_once MODULES_DIR . DS . 'holterref' . DS . 'config.inc';

class holterrefModule extends mainModule
{
    var $title = 'holterref module';
    var $description = '';

    function menu(){
//---------------------------1. SVT -------------------------------------------
        $items['ref_holterref_SVT'] = array(
            'title' => __t('SVT'),
            'description' => __t('SVT reference form for holterref'),
            'path' => '/reference/holterref_SVT',
            'exec' => 'ref_SVT_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_holterref_SVT_detail'] = array(
            'title' => __t('detil SVT fase latihan'),
            'description' => __t('SVT reference detail for holterref'),
            'path' => '/reference/holterref_SVT/detail',
            'exec' => 'ref_SVT_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_holterref_SVT_form'] = array(
            'title' => __t('holterref_SVT form'),
            'description' => __t('SVT reference form for holterref'),
            'path' => '/reference/holterref_SVT/form',
            'exec' => 'ref_SVT_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_holterref_SVT_form_submit'] = array(
            'title' => __t('holterref_SVT form'),
            'description' => __t('Execute SVT reference form for holterref'),
            'path' => '/reference/holterref_SVT/form_submit',
            'exec' => 'ref_SVT_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_holterref_SVT_edit'] = array(
            'title' => __t('holterref_SVT edit'),
            'description' => __t('Editing SVT reference form for holterref'),
            'path' => '/reference/holterref_SVT/edit',
            'exec' => 'ref_SVT_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_holterref_SVT_drop'] = array(
            'title' => __t('holterref_SVT drop'),
            'description' => __t('Remove SVT reference form for holterref'),
            'path' => '/reference/holterref_SVT/drop',
            'exec' => 'ref_SVT_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );

//-------------------------2. VES--------------------------------------------
        $items['ref_holterref_VES'] = array(
            'title' => __t('VES'),
            'description' => __t('VES reference form for holterref'),
            'path' => '/reference/holterref_VES',
            'exec' => 'ref_VES_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_holterref_VES_detail'] = array(
            'title' => __t('detil VES'),
            'description' => __t('VES reference detail for holterref'),
            'path' => '/reference/holterref_VES/detail',
            'exec' => 'ref_VES_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_holterref_VES_form'] = array(
            'title' => __t('holterref_VES form'),
            'description' => __t('VES reference form for holterref'),
            'path' => '/reference/holterref_VES/form',
            'exec' => 'ref_VES_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_holterref_VES_form_submit'] = array(
            'title' => __t('holterref_VES form'),
            'description' => __t('Execute VES reference form for holterref'),
            'path' => '/reference/holterref_VES/form_submit',
            'exec' => 'ref_VES_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_holterref_VES_edit'] = array(
            'title' => __t('holterref_VES edit'),
            'description' => __t('Editing VES reference form for holterref'),
            'path' => '/reference/holterref_VES/edit',
            'exec' => 'ref_VES_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_holterref_VES_drop'] = array(
            'title' => __t('holterref_VES drop'),
            'description' => __t('Remove VES reference form for holterref'),
            'path' => '/reference/holterref_VES/drop',
            'exec' => 'ref_VES_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );

//-----------------------------3. Q Patologi -----------------------------------
        $items['ref_holterref_AF'] = array(
            'title' => __t('AF'),
            'description' => __t('AF reference form for holterref'),
            'path' => '/reference/holterref_AF',
            'exec' => 'ref_AF_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_holterref_AF_detail'] = array(
            'title' => __t('detil perubahan gelombang R'),
            'description' => __t('AF reference detail for holterref'),
            'path' => '/reference/holterref_AF/detail',
            'exec' => 'ref_AF_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_holterref_AF_form'] = array(
            'title' => __t('holterref_AF form'),
            'description' => __t('AF reference form for holterref'),
            'path' => '/reference/holterref_AF/form',
            'exec' => 'ref_AF_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_holterref_AF_form_submit'] = array(
            'title' => __t('holterref_AF form'),
            'description' => __t('Execute AF reference form for holterref'),
            'path' => '/reference/holterref_AF/form_submit',
            'exec' => 'ref_AF_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_holterref_AF_edit'] = array(
            'title' => __t('holterref_AF edit'),
            'description' => __t('Editing AF reference form for holterref'),
            'path' => '/reference/holterref_AF/edit',
            'exec' => 'ref_AF_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_holterref_AF_drop'] = array(
            'title' => __t('holterref_AF drop'),
            'description' => __t('Remove AF reference form for holterref'),
            'path' => '/reference/holterref_AF/drop',
            'exec' => 'ref_AF_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        
//----------------------------4. R > S--------------------------------
        $items['ref_holterref_heartblock'] = array(
            'title' => __t('heartblock'),
            'description' => __t('heartblock reference form for holterref'),
            'path' => '/reference/holterref_heartblock',
            'exec' => 'ref_heartblock_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_holterref_heartblock_detail'] = array(
            'title' => __t('detil heartblock QRS Complex'),
            'description' => __t('heartblock reference detail for holterref'),
            'path' => '/reference/holterref_heartblock/detail',
            'exec' => 'ref_heartblock_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_holterref_heartblock_form'] = array(
            'title' => __t('holterref_heartblock form'),
            'description' => __t('heartblock reference form for holterref'),
            'path' => '/reference/holterref_heartblock/form',
            'exec' => 'ref_heartblock_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_holterref_heartblock_form_submit'] = array(
            'title' => __t('holterref_heartblock form'),
            'description' => __t('Execute heartblock reference form for holterref'),
            'path' => '/reference/holterref_heartblock/form_submit',
            'exec' => 'ref_heartblock_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_holterref_heartblock_edit'] = array(
            'title' => __t('holterref_heartblock edit'),
            'description' => __t('Editing heartblock reference form for holterref'),
            'path' => '/reference/holterref_heartblock/edit',
            'exec' => 'ref_heartblock_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_holterref_heartblock_drop'] = array(
            'title' => __t('holterref_heartblock drop'),
            'description' => __t('Remove heartblock reference form for holterref'),
            'path' => '/reference/holterref_heartblock/drop',
            'exec' => 'ref_heartblock_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );

        //----------------------------respon_jantung----------------------------
        
        return $items;
    }

    function ref_SVT_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi SVT fase latihan');
        $result['description'] = __t('Referensi isian SVT fase latihan');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/holterref_SVT/form',
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
                'field' => 'SVT',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_holterref_SVT'),
            NULL
           
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['type'] = ucwords($query->fields['SVT']);
                $result['data'][$i]['goto'] = '/reference/holterref_SVT/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_SVT_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add holterref_SVT'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'SVT',
            '#weight' => -3,
            '#action' => '/reference/holterref_SVT/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_holterref_SVT');
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

    function ref_SVT_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/holterref_SVT/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_holterref_SVT', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_holterref_SVT',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/holterref_SVT');
//        } else {
//            redirect_to('/reference/holterref_SVT/form');
//        }
    }

    function ref_SVT_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'SVT', 'ekg_Qrs_SVT', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi SVT fase latihan');
        $result['description'] = __t('informasi detil referensi SVT fase latihan yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/holterref_SVT/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'SVT'),
            array('ref_holterref_SVT'),
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
                'link' => '/reference/holterref_SVT/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/holterref_SVT/edit/',
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

    function ref_SVT_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_holterref_SVT', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_holterref_SVT',
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
        redirect_to('/reference/holterref_SVT/detail/' . $_POST['id']);
    }

    function ref_SVT_drop(){
        if($this->__is_dropable($_POST['id'], 'SVT', 'ekg_Qrs_SVT', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_holterref_SVT',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/holterref_SVT');
    }

//--------------------------2. VES ------------------------------------------
    function ref_VES_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi konfigurasi');
        $result['description'] = __t('Referensi isian konfigurasi');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/holterref_VES/form',
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
                'field' => 'VES',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_holterref_VES'),
            NULL
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['VES'] = ucwords($query->fields['VES']);
                $result['data'][$i]['goto'] = '/reference/holterref_VES/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_VES_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add holterref_VES'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'VES',
            '#weight' => -3,
            '#action' => '/reference/holterref_VES/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_holterref_VES');
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

    function ref_VES_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/holterref_VES/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_holterref_VES', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_holterref_VES',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/holterref_VES');
//        } else {
//            redirect_to('/reference/holterref_VES/form');
//        }
    }

    function ref_VES_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'VES', 'ekg_Qrs_VES', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi konfigurasi');
        $result['description'] = __t('informasi detil referensi konfigurasi yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/holterref_VES/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'VES'),
            array('ref_holterref_VES'),
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
                'link' => '/reference/holterref_VES/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/holterref_VES/edit/',
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

    function ref_VES_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_holterref_VES', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_holterref_VES',
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
        redirect_to('/reference/holterref_VES/detail/' . $_POST['id']);
    }

    function ref_VES_drop(){
        if($this->__is_dropable($_POST['id'], 'VES', 'holterref_VES', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_holterref_VES',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/holterref_VES');
    }

//---------------------------3. Q patologi -------------------------------------
    function ref_AF_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi AF');
        $result['description'] = __t('Referensi isian AF pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/holterref_AF/form',
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
                'field' => 'AF',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_holterref_AF'),
            NULL
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['AF'] = ucwords($query->fields['AF']);
                $result['data'][$i]['goto'] = '/reference/holterref_AF/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_AF_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add holterref_AF'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'AF',
            '#weight' => -3,
            '#action' => '/reference/holterref_AF/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_holterref_AF');
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

    function ref_AF_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/holterref_AF/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_holterref_AF', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_holterref_AF',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/holterref_AF');
//        } else {
//            redirect_to('/reference/holterref_AF/form');
//        }
    }

    function ref_AF_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'AF', 'ekg_Qrs_AF', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi AF');
        $result['description'] = __t('informasi detil referensi AF yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/holterref_AF/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'AF'),
            array('ref_holterref_AF'),
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
                'link' => '/reference/holterref_AF/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/holterref_AF/edit/',
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

    function ref_AF_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_holterref_AF', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_holterref_AF',
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
        redirect_to('/reference/holterref_AF/detail/' . $_POST['id']);
    }

    function ref_AF_drop(){
        if($this->__is_dropable($_POST['id'], 'AF', 'ekg_Qrs_AF', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_holterref_AF',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/holterref_AF');
    }

//-----------------------------4. heartblock -----------------------------------------
    function ref_heartblock_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi heartblock fase latihan');
        $result['description'] = __t('Referensi isian heartblock fase latihan');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/holterref_heartblock/form',
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
                'field' => 'heartblock',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_holterref_heartblock'),
            NULL
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['type'] = ucwords($query->fields['heartblock']);
                $result['data'][$i]['goto'] = '/reference/holterref_heartblock/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_heartblock_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add holterref_heartblock'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'heartblock',
            '#weight' => -3,
            '#action' => '/reference/holterref_heartblock/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_holterref_heartblock');
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

    function ref_heartblock_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/holterref_heartblock/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_holterref_heartblock', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_holterref_heartblock',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/holterref_heartblock');
//        } else {
//            redirect_to('/reference/holterref_heartblock/form');
//        }
    }

    function ref_heartblock_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'heartblock', 'fase_latihan', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi heartblock fase latihan');
        $result['description'] = __t('informasi detil referensi heartblock fase latihan yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/holterref_heartblock/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'heartblock'),
            array('ref_holterref_heartblock'),
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
                'link' => '/reference/holterref_heartblock/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/holterref_heartblock/edit/',
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

    function ref_heartblock_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_holterref_heartblock', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_holterref_heartblock',
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
        redirect_to('/reference/holterref_heartblock/detail/' . $_POST['id']);
    }

    function ref_heartblock_drop(){
        if($this->__is_dropable($_POST['id'], 'heartblock', 'fase_latihan', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_holterref_heartblock',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/holterref_heartblock');
    }

    

}