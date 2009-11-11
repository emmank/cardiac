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
 *  fekgclass.php
 *  
 *  Created on Oct 3, 2009, 8:39:24 PM
 */

require_once MODULES_DIR . DS . 'fekg' . DS . 'config.inc';

class fekgModule extends mainModule
{
    var $title = 'fekg module';
    var $description = '';

    function menu(){
        //--------------------1. Irama -----------------------------------------
        $items['ref_ekg_irama'] = array(
            'title' => __t('fekg irama dasar'),
            'description' => __t('irama reference form for fekg'),
            'path' => '/reference/fekg_irama',
            'exec' => 'ref_irama_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_ekg_irama_detail'] = array(
            'title' => __t('detil irama dasar'),
            'description' => __t('irama reference detail for fekg'),
            'path' => '/reference/fekg_irama/detail',
            'exec' => 'ref_irama_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_ekg_irama_form'] = array(
            'title' => __t('fekg_irama form'),
            'description' => __t('irama reference form for fekg'),
            'path' => '/reference/fekg_irama/form',
            'exec' => 'ref_irama_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekg_irama_form_submit'] = array(
            'title' => __t('fekg_irama form'),
            'description' => __t('Execute irama reference form for fekg'),
            'path' => '/reference/fekg_irama/form_submit',
            'exec' => 'ref_irama_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekg_irama_edit'] = array(
            'title' => __t('fekg_irama edit'),
            'description' => __t('Editing irama reference form for fekg'),
            'path' => '/reference/fekg_irama/edit',
            'exec' => 'ref_irama_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekg_irama_drop'] = array(
            'title' => __t('fekg_irama drop'),
            'description' => __t('Remove irama reference form for fekg'),
            'path' => '/reference/fekg_irama/drop',
            'exec' => 'ref_irama_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );

        //-------------------2. denyut_jantung----------------------------------
        $items['ref_ekg_denyut_jantung'] = array(
            'title' => __t('fekg denyut jantung'),
            'description' => __t('denyut_jantung reference form for fekg'),
            'path' => '/reference/fekg_denyut_jantung',
            'exec' => 'ref_denyut_jantung_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_ekg_denyut_jantung_detail'] = array(
            'title' => __t('detil denyut_jantung'),
            'description' => __t('denyut_jantung reference detail for fekg'),
            'path' => '/reference/fekg_denyut_jantung/detail',
            'exec' => 'ref_denyut_jantung_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_ekg_denyut_jantung_form'] = array(
            'title' => __t('fekg_denyut_jantung form'),
            'description' => __t('denyut_jantung reference form for fekg'),
            'path' => '/reference/fekg_denyut_jantung/form',
            'exec' => 'ref_denyut_jantung_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekg_denyut_jantung_form_submit'] = array(
            'title' => __t('fekg_denyut_jantung form'),
            'description' => __t('Execute denyut_jantung reference form for fekg'),
            'path' => '/reference/fekg_denyut_jantung/form_submit',
            'exec' => 'ref_denyut_jantung_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekg_denyut_jantung_edit'] = array(
            'title' => __t('fekg_denyut_jantung edit'),
            'description' => __t('Editing denyut_jantung reference form for fekg'),
            'path' => '/reference/fekg_denyut_jantung/edit',
            'exec' => 'ref_denyut_jantung_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekg_denyut_jantung_drop'] = array(
            'title' => __t('fekg_denyut_jantung drop'),
            'description' => __t('Remove denyut_jantung reference form for fekg'),
            'path' => '/reference/fekg_denyut_jantung/drop',
            'exec' => 'ref_denyut_jantung_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );

        //------------------------3. Gelombang P -------------------------------
        $items['ref_ekg_gelombangP'] = array(
            'title' => __t('fekg gelombang P'),
            'description' => __t('gelombang P reference form for fekg'),
            'path' => '/reference/fekg_gelombangP',
            'exec' => 'ref_gelombangP_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_ekg_gelombangP_detail'] = array(
            'title' => __t('detil gelombang P'),
            'description' => __t('gelombang P reference detail for fekg'),
            'path' => '/reference/fekg_gelombangP/detail',
            'exec' => 'ref_gelombangP_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_ekg_gelombangP_form'] = array(
            'title' => __t('fekg_gelombang P form'),
            'description' => __t('gelombang P reference form for fekg'),
            'path' => '/reference/fekg_gelombangP/form',
            'exec' => 'ref_gelombangP_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekg_gelombangP_form_submit'] = array(
            'title' => __t('fekg_gelombang P form'),
            'description' => __t('Execute gelombang P reference form for fekg'),
            'path' => '/reference/fekg_gelombangP/form_submit',
            'exec' => 'ref_gelombangP_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekg_gelombangP_edit'] = array(
            'title' => __t('fekg_gelombang P edit'),
            'description' => __t('Editing gelombang P reference form for fekg'),
            'path' => '/reference/fekg_gelombangP/edit',
            'exec' => 'ref_gelombangP_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekg_gelombangP_drop'] = array(
            'title' => __t('fekg_gelombang P drop'),
            'description' => __t('Remove gelombang P reference form for fekg'),
            'path' => '/reference/fekg_gelombangP/drop',
            'exec' => 'ref_gelombangP_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        
        //--------------------------4. Interval P-R ------------------------------
        $items['ref_ekg_intervalPR'] = array(
            'title' => __t('interval P-R'),
            'description' => __t('intervalPR reference form for fekg'),
            'path' => '/reference/fekg_intervalPR',
            'exec' => 'ref_intervalPR_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_ekg_intervalPR_detail'] = array(
            'title' => __t('detil intervalPR fekg'),
            'description' => __t('intervalPR reference detail for fekg'),
            'path' => '/reference/fekg_intervalPR/detail',
            'exec' => 'ref_intervalPR_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_ekg_intervalPR_form'] = array(
            'title' => __t('fekg_intervalPR form'),
            'description' => __t('intervalPR reference form for fekg'),
            'path' => '/reference/fekg_intervalPR/form',
            'exec' => 'ref_intervalPR_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekg_intervalPR_form_submit'] = array(
            'title' => __t('fekg_intervalPR form'),
            'description' => __t('Execute intervalPR reference form for fekg'),
            'path' => '/reference/fekg_intervalPR/form_submit',
            'exec' => 'ref_intervalPR_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekg_intervalPR_edit'] = array(
            'title' => __t('fekg_intervalPR edit'),
            'description' => __t('Editing intervalPR reference form for fekg'),
            'path' => '/reference/fekg_intervalPR/edit',
            'exec' => 'ref_intervalPR_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekg_intervalPR_drop'] = array(
            'title' => __t('fekg_intervalPR drop'),
            'description' => __t('Remove intervalPR reference form for fekg'),
            'path' => '/reference/fekg_intervalPR/drop',
            'exec' => 'ref_intervalPR_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );

        //----------------------------Form fekg ----------------------------
        $items['fekg_form'] = array(
            'title' => __t('Form fekg'),
            'description' => __t('Form for fekg'),
            'path' => '/user/fekg_form',
            'exec' => 'tampil_form',
            'weight' => '0',
            'user_required' => 'fekg'
        );
        $items['ref_ekg_respon_jantung_detail'] = array(
            'title' => __t('detil respon_jantung fase latihan'),
            'description' => __t('respon_jantung reference detail for fekg'),
            'path' => '/reference/fekg_respon_jantung/detail',
            'exec' => 'ref_respon_jantung_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_ekg_respon_jantung_form'] = array(
            'title' => __t('fekg_respon_jantung form'),
            'description' => __t('respon_jantung reference form for fekg'),
            'path' => '/reference/fekg_respon_jantung/form',
            'exec' => 'ref_respon_jantung_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekg_respon_jantung_form_submit'] = array(
            'title' => __t('fekg_respon_jantung form'),
            'description' => __t('Execute respon_jantung reference form for fekg'),
            'path' => '/reference/fekg_respon_jantung/form_submit',
            'exec' => 'ref_respon_jantung_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekg_respon_jantung_edit'] = array(
            'title' => __t('fekg_respon_jantung edit'),
            'description' => __t('Editing respon_jantung reference form for fekg'),
            'path' => '/reference/fekg_respon_jantung/edit',
            'exec' => 'ref_respon_jantung_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_ekg_respon_jantung_drop'] = array(
            'title' => __t('fekg_respon_jantung drop'),
            'description' => __t('Remove respon_jantung reference form for fekg'),
            'path' => '/reference/fekg_respon_jantung/drop',
            'exec' => 'ref_respon_jantung_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );

        return $items;
    }

//------------------------------1. Function irama ------------------------------
    function ref_irama_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi irama dasar');
        $result['description'] = __t('Referensi isian irama dasar');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/fekg_irama/form',
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
                'field' => 'irama',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_ekg_irama'),
            NULL,'id'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['type'] = ucwords($query->fields['irama']);
                $result['data'][$i]['goto'] = '/reference/fekg_irama/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_irama_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add fekg_irama'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'irama',
            '#weight' => -3,
            '#action' => '/reference/fekg_irama/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_ekg_irama');
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
        echo '<pre>'; print_r ($form); echo '</pre>';
        return $form;
    }

    function ref_irama_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/fekg_irama/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_ekg_irama', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_ekg_irama',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/fekg_irama');
//        } else {
//            redirect_to('/reference/fekg_irama/form');
//        }
    }

    function ref_irama_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'irama', 'fekg irama dasar', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi irama dasar');
        $result['description'] = __t('informasi detil referensi irama dasar yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/fekg_irama/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'irama'),
            array('ref_ekg_irama'),
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
                'link' => '/reference/fekg_irama/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/fekg_irama/edit/',
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

    function ref_irama_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_ekg_irama', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_ekg_irama',
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
        redirect_to('/reference/fekg_irama/detail/' . $_POST['id']);
    }

    function ref_irama_drop(){
        if($this->__is_dropable($_POST['id'], 'irama', 'fekg irama dasar', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_ekg_irama',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/fekg_irama');
    }

//---------------------2. Function denyut_jantung ------------------------------
    function ref_denyut_jantung_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi denyut_jantung');
        $result['description'] = __t('Referensi isian denyut_jantung');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/fekg_denyut_jantung/form',
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
                'field' => 'denyut_jantung',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_ekg_denyut_jantung'),
            NULL,'id'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['denyut_jantung'] = ucwords($query->fields['denyut_jantung']);
                $result['data'][$i]['goto'] = '/reference/fekg_denyut_jantung/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_denyut_jantung_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add fekg_denyut_jantung'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'denyut_jantung',
            '#weight' => -3,
            '#action' => '/reference/fekg_denyut_jantung/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_ekg_denyut_jantung');
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

    function ref_denyut_jantung_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/fekg_denyut_jantung/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_ekg_denyut_jantung', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_ekg_denyut_jantung',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/fekg_denyut_jantung');
//        } else {
//            redirect_to('/reference/fekg_denyut_jantung/form');
//        }
    }

    function ref_denyut_jantung_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'denyut_jantung', 'fekg denyut jantung', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi denyut_jantung');
        $result['description'] = __t('informasi detil referensi denyut_jantung yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/fekg_denyut_jantung/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'denyut_jantung'),
            array('ref_ekg_denyut_jantung'),
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
                'link' => '/reference/fekg_denyut_jantung/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/fekg_denyut_jantung/edit/',
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

    function ref_denyut_jantung_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_ekg_denyut_jantung', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_ekg_denyut_jantung',
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
        redirect_to('/reference/fekg_denyut_jantung/detail/' . $_POST['id']);
    }

    function ref_denyut_jantung_drop(){
        if($this->__is_dropable($_POST['id'], 'denyut_jantung', 'fekg_denyut_jantung', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_ekg_denyut_jantung',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/fekg_denyut_jantung');
    }

//--------------------------3. gelombang P -------------------------------------
    function ref_gelombangP_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi gelombang P');
        $result['description'] = __t('Referensi isian gelombang P pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/fekg_gelombangP/form',
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
                'field' => 'gelombangP',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_ekg_gelombangP'),
            NULL,
            'gelombangP'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['gelombangP'] = ucwords($query->fields['gelombangP']);
                $result['data'][$i]['goto'] = '/reference/fekg_gelombangP/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_gelombangP_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add fekg_gelombangP'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'gelombangP',
            '#weight' => -3,
            '#action' => '/reference/fekg_gelombangP/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_ekg_gelombangP');
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

    function ref_gelombangP_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/fekg_gelombangP/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_ekg_gelombangP', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_ekg_gelombangP',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/fekg_gelombangP');
//        } else {
//            redirect_to('/reference/fekg_gelombangP/form');
//        }
    }

    function ref_gelombangP_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'gelombangP', 'fekg_gelombang_P', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi gelombang P');
        $result['description'] = __t('informasi detil referensi gelombang P yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/fekg_gelombangP/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'gelombangP'),
            array('ref_ekg_gelombangP'),
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
                'link' => '/reference/fekg_gelombangP/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/fekg_gelombangP/edit/',
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

    function ref_gelombangP_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_ekg_gelombangP', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_ekg_gelombangP',
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
        redirect_to('/reference/fekg_gelombangP/detail/' . $_POST['id']);
    }

    function ref_gelombangP_drop(){
        if($this->__is_dropable($_POST['id'], 'gelombangP', 'fekg_gelombang_P', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_ekg_gelombangP',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/fekg_gelombangP');
    }

//------------------------4. Function intervalPR -------------------------------
    function ref_intervalPR_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi intervalPR fekg');
        $result['description'] = __t('Referensi isian intervalPR fekg');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/fekg_intervalPR/form',
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
                'field' => 'intervalPR',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_ekg_intervalPR'),
            NULL
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['type'] = ucwords($query->fields['intervalPR']);
                $result['data'][$i]['goto'] = '/reference/fekg_intervalPR/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_intervalPR_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add fekg_intervalPR'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'intervalPR',
            '#weight' => -3,
            '#action' => '/reference/fekg_intervalPR/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_ekg_intervalPR');
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

    function ref_intervalPR_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/fekg_intervalPR/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_ekg_intervalPR', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_ekg_intervalPR',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/fekg_intervalPR');
//        } else {
//            redirect_to('/reference/fekg_intervalPR/form');
//        }
    }

    function ref_intervalPR_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'intervalPR', 'fekg', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi intervalPR fase latihan');
        $result['description'] = __t('informasi detil referensi intervalPR fekg yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/fekg_intervalPR/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'intervalPR'),
            array('ref_ekg_intervalPR'),
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
                'link' => '/reference/fekg_intervalPR/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/fekg_intervalPR/edit/',
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

    function ref_intervalPR_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_ekg_intervalPR', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_ekg_intervalPR',
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
        redirect_to('/reference/fekg_intervalPR/detail/' . $_POST['id']);
    }

    function ref_intervalPR_drop(){
        if($this->__is_dropable($_POST['id'], 'intervalPR', 'fekg', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_ekg_intervalPR',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/fekg_intervalPR');
    }

    //---------------Form fekg---------------------------------------------
    function ref_respon_jantung_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi respon_jantung fase latihan');
        $result['description'] = __t('Referensi isian respon_jantung fase latihan');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/fekg_respon_jantung/form',
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
                'field' => 'respon_jantung',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_ekg_respon_jantung'),
            NULL,
            'respon_jantung'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['type'] = ucwords($query->fields['respon_jantung']);
                $result['data'][$i]['goto'] = '/reference/fekg_respon_jantung/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function tampil_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add fekg_form'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'irama_dasar',
            '#weight' => -3,
            '#action' => '/user/fekg_form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('fekg');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => $this->config->fekgfieldstype[$query->fields['Field']],
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
                if ($query->fields['Field'] == 'irama_dasar') {
                    $sql = $this->query->getSelect(
                        array(),
                        array('ref_ekg_irama')
                    );
                    $this->query->connect();
                    $query_irama = $this->query->conn->Execute($sql); unset($sql);
                    $this->query->close();
                    $items = array();
                    for ($a=0;$a<$query_irama->_numOfRows;$a++){
                        $items[$query_irama->fields['id']] = $query_irama->fields['irama'];
                        $query_irama->MoveNext();
                    }
                    $form['group'][$query->fields['Field']]['#option'] = $items; unset($items);
                }
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

    function ref_respon_jantung_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/fekg_respon_jantung/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_ekg_respon_jantung', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_ekg_respon_jantung',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/fekg_respon_jantung');
//        } else {
//            redirect_to('/reference/fekg_respon_jantung/form');
//        }
    }

    function ref_respon_jantung_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'respon_jantung', 'fase_latihan', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi respon_jantung fase latihan');
        $result['description'] = __t('informasi detil referensi respon_jantung fase latihan yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/fekg_respon_jantung/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'respon_jantung'),
            array('ref_ekg_respon_jantung'),
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
                'link' => '/reference/fekg_respon_jantung/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/fekg_respon_jantung/edit/',
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

    function ref_respon_jantung_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_ekg_respon_jantung', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_ekg_respon_jantung',
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
        redirect_to('/reference/fekg_respon_jantung/detail/' . $_POST['id']);
    }

    function ref_respon_jantung_drop(){
        if($this->__is_dropable($_POST['id'], 'respon_jantung', 'fase_latihan', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_ekg_respon_jantung',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/fekg_respon_jantung');
    }

}