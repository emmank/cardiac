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
 *  faseLatihanclass.php
 *  
 *  Created on Oct 3, 2009, 8:39:24 PM
 */

require_once MODULES_DIR . DS . 'faseLatihan' . DS . 'config.inc';

class faseLatihanModule extends mainModule
{
    var $title = 'faseLatihan module';
    var $description = '';

    function menu(){
        $items['ref_faseLatihan_protokol'] = array(
            'title' => __t('protokol'),
            'description' => __t('protokol reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_protokol',
            'exec' => 'ref_protokol_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_faseLatihan_protokol_detail'] = array(
            'title' => __t('detil protokol fase latihan'),
            'description' => __t('protokol reference detail for faseLatihan'),
            'path' => '/reference/faseLatihan_protokol/detail',
            'exec' => 'ref_protokol_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_faseLatihan_protokol_form'] = array(
            'title' => __t('faseLatihan_protokol form'),
            'description' => __t('protokol reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_protokol/form',
            'exec' => 'ref_protokol_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_faseLatihan_protokol_form_submit'] = array(
            'title' => __t('faseLatihan_protokol form'),
            'description' => __t('Execute protokol reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_protokol/form_submit',
            'exec' => 'ref_protokol_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_faseLatihan_protokol_edit'] = array(
            'title' => __t('faseLatihan_protokol edit'),
            'description' => __t('Editing protokol reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_protokol/edit',
            'exec' => 'ref_protokol_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_faseLatihan_protokol_drop'] = array(
            'title' => __t('faseLatihan_protokol drop'),
            'description' => __t('Remove protokol reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_protokol/drop',
            'exec' => 'ref_protokol_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );

        //-------------------Konfigurasi----------------------------------------
        $items['ref_faseLatihan_konfig_rekaman'] = array(
            'title' => __t('Konfigurasi'),
            'description' => __t('konfigurasi reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_konfig_rekaman',
            'exec' => 'ref_konfig_rekaman_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_faseLatihan_konfig_rekaman_detail'] = array(
            'title' => __t('detil konfigurasi'),
            'description' => __t('konfig_rekaman reference detail for faseLatihan'),
            'path' => '/reference/faseLatihan_konfig_rekaman/detail',
            'exec' => 'ref_konfig_rekaman_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_faseLatihan_konfig_rekaman_form'] = array(
            'title' => __t('faseLatihan_konfig_rekaman form'),
            'description' => __t('konfig_rekaman reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_konfig_rekaman/form',
            'exec' => 'ref_konfig_rekaman_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_faseLatihan_konfig_rekaman_form_submit'] = array(
            'title' => __t('faseLatihan_konfig_rekaman form'),
            'description' => __t('Execute konfig_rekaman reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_konfig_rekaman/form_submit',
            'exec' => 'ref_konfig_rekaman_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_faseLatihan_konfig_rekaman_edit'] = array(
            'title' => __t('faseLatihan_konfig_rekaman edit'),
            'description' => __t('Editing konfig_rekaman reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_konfig_rekaman/edit',
            'exec' => 'ref_konfig_rekaman_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_faseLatihan_konfig_rekaman_drop'] = array(
            'title' => __t('faseLatihan_konfig_rekaman drop'),
            'description' => __t('Remove konfig_rekaman reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_konfig_rekaman/drop',
            'exec' => 'ref_konfig_rekaman_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );

        //------------------------perubahan Gelombang---------------------------
        $items['ref_faseLatihan_perubahan_gelombang'] = array(
            'title' => __t('perubahan_gelombang'),
            'description' => __t('perubahan_gelombang reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_perubahan_gelombang',
            'exec' => 'ref_perubahan_gelombang_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_faseLatihan_perubahan_gelombang_detail'] = array(
            'title' => __t('detil perubahan gelombang R'),
            'description' => __t('perubahan_gelombang reference detail for faseLatihan'),
            'path' => '/reference/faseLatihan_perubahan_gelombang/detail',
            'exec' => 'ref_perubahan_gelombang_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_faseLatihan_perubahan_gelombang_form'] = array(
            'title' => __t('faseLatihan_perubahan_gelombang form'),
            'description' => __t('perubahan_gelombang reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_perubahan_gelombang/form',
            'exec' => 'ref_perubahan_gelombang_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_faseLatihan_perubahan_gelombang_form_submit'] = array(
            'title' => __t('faseLatihan_perubahan_gelombang form'),
            'description' => __t('Execute perubahan_gelombang reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_perubahan_gelombang/form_submit',
            'exec' => 'ref_perubahan_gelombang_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_faseLatihan_perubahan_gelombang_edit'] = array(
            'title' => __t('faseLatihan_perubahan_gelombang edit'),
            'description' => __t('Editing perubahan_gelombang reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_perubahan_gelombang/edit',
            'exec' => 'ref_perubahan_gelombang_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_faseLatihan_perubahan_gelombang_drop'] = array(
            'title' => __t('faseLatihan_perubahan_gelombang drop'),
            'description' => __t('Remove perubahan_gelombang reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_perubahan_gelombang/drop',
            'exec' => 'ref_perubahan_gelombang_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        
        //----------------------------dihentikan--------------------------------
        $items['ref_faseLatihan_dihentikan'] = array(
            'title' => __t('dihentikan'),
            'description' => __t('dihentikan reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_dihentikan',
            'exec' => 'ref_dihentikan_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_faseLatihan_dihentikan_detail'] = array(
            'title' => __t('detil dihentikan fase latihan'),
            'description' => __t('dihentikan reference detail for faseLatihan'),
            'path' => '/reference/faseLatihan_dihentikan/detail',
            'exec' => 'ref_dihentikan_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_faseLatihan_dihentikan_form'] = array(
            'title' => __t('faseLatihan_dihentikan form'),
            'description' => __t('dihentikan reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_dihentikan/form',
            'exec' => 'ref_dihentikan_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_faseLatihan_dihentikan_form_submit'] = array(
            'title' => __t('faseLatihan_dihentikan form'),
            'description' => __t('Execute dihentikan reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_dihentikan/form_submit',
            'exec' => 'ref_dihentikan_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_faseLatihan_dihentikan_edit'] = array(
            'title' => __t('faseLatihan_dihentikan edit'),
            'description' => __t('Editing dihentikan reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_dihentikan/edit',
            'exec' => 'ref_dihentikan_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_faseLatihan_dihentikan_drop'] = array(
            'title' => __t('faseLatihan_dihentikan drop'),
            'description' => __t('Remove dihentikan reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_dihentikan/drop',
            'exec' => 'ref_dihentikan_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );

        //----------------------------respon_jantung----------------------------
        $items['ref_faseLatihan_respon_jantung'] = array(
            'title' => __t('respon_jantung'),
            'description' => __t('respon_jantung reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_respon_jantung',
            'exec' => 'ref_respon_jantung_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_faseLatihan_respon_jantung_detail'] = array(
            'title' => __t('detil respon_jantung fase latihan'),
            'description' => __t('respon_jantung reference detail for faseLatihan'),
            'path' => '/reference/faseLatihan_respon_jantung/detail',
            'exec' => 'ref_respon_jantung_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_faseLatihan_respon_jantung_form'] = array(
            'title' => __t('faseLatihan_respon_jantung form'),
            'description' => __t('respon_jantung reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_respon_jantung/form',
            'exec' => 'ref_respon_jantung_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_faseLatihan_respon_jantung_form_submit'] = array(
            'title' => __t('faseLatihan_respon_jantung form'),
            'description' => __t('Execute respon_jantung reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_respon_jantung/form_submit',
            'exec' => 'ref_respon_jantung_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_faseLatihan_respon_jantung_edit'] = array(
            'title' => __t('faseLatihan_respon_jantung edit'),
            'description' => __t('Editing respon_jantung reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_respon_jantung/edit',
            'exec' => 'ref_respon_jantung_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_faseLatihan_respon_jantung_drop'] = array(
            'title' => __t('faseLatihan_respon_jantung drop'),
            'description' => __t('Remove respon_jantung reference form for faseLatihan'),
            'path' => '/reference/faseLatihan_respon_jantung/drop',
            'exec' => 'ref_respon_jantung_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );

        return $items;
    }

    function ref_protokol_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi protokol fase latihan');
        $result['description'] = __t('Referensi isian protokol fase latihan');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/faseLatihan_protokol/form',
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
                'field' => 'protokol',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_faseLatihan_protokol'),
            NULL,
            'protokol'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['type'] = ucwords($query->fields['protokol']);
                $result['data'][$i]['goto'] = '/reference/faseLatihan_protokol/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_protokol_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add faseLatihan_protokol'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'protokol',
            '#weight' => -3,
            '#action' => '/reference/faseLatihan_protokol/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_faseLatihan_protokol');
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

    function ref_protokol_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/faseLatihan_protokol/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_faseLatihan_protokol', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_faseLatihan_protokol',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/faseLatihan_protokol');
//        } else {
//            redirect_to('/reference/faseLatihan_protokol/form');
//        }
    }

    function ref_protokol_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'protokol', 'fase_latihan', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi protokol fase latihan');
        $result['description'] = __t('informasi detil referensi protokol fase latihan yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/faseLatihan_protokol/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'protokol'),
            array('ref_faseLatihan_protokol'),
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
                'link' => '/reference/faseLatihan_protokol/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/faseLatihan_protokol/edit/',
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

    function ref_protokol_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_faseLatihan_protokol', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_faseLatihan_protokol',
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
        redirect_to('/reference/faseLatihan_protokol/detail/' . $_POST['id']);
    }

    function ref_protokol_drop(){
        if($this->__is_dropable($_POST['id'], 'protokol', 'fase_latihan', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_faseLatihan_protokol',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/faseLatihan_protokol');
    }

    //---------------------Konfigurasi------------------------------------------
    function ref_konfig_rekaman_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi konfigurasi');
        $result['description'] = __t('Referensi isian konfigurasi');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/faseLatihan_konfig_rekaman/form',
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
                'field' => 'konfig_rekaman',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_faseLatihan_konfig_rekaman'),
            NULL,
            'konfig_rekaman'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['konfig_rekaman'] = ucwords($query->fields['konfig_rekaman']);
                $result['data'][$i]['goto'] = '/reference/faseLatihan_konfig_rekaman/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_konfig_rekaman_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add faseLatihan_konfig_rekaman'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'konfig_rekaman',
            '#weight' => -3,
            '#action' => '/reference/faseLatihan_konfig_rekaman/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_faseLatihan_konfig_rekaman');
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

    function ref_konfig_rekaman_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/faseLatihan_konfig_rekaman/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_faseLatihan_konfig_rekaman', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_faseLatihan_konfig_rekaman',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/faseLatihan_konfig_rekaman');
//        } else {
//            redirect_to('/reference/faseLatihan_konfig_rekaman/form');
//        }
    }

    function ref_konfig_rekaman_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'konfig_rekaman', 'fase_latihan', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi konfigurasi');
        $result['description'] = __t('informasi detil referensi konfigurasi yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/faseLatihan_konfig_rekaman/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'konfig_rekaman'),
            array('ref_faseLatihan_konfig_rekaman'),
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
                'link' => '/reference/faseLatihan_konfig_rekaman/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/faseLatihan_konfig_rekaman/edit/',
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

    function ref_konfig_rekaman_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_faseLatihan_konfig_rekaman', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_faseLatihan_konfig_rekaman',
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
        redirect_to('/reference/faseLatihan_konfig_rekaman/detail/' . $_POST['id']);
    }

    function ref_konfig_rekaman_drop(){
        if($this->__is_dropable($_POST['id'], 'konfig_rekaman', 'fase_latihan', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_faseLatihan_konfig_rekaman',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/faseLatihan_konfig_rekaman');
    }

    //-----------------------perubahan gelombang--------------------------------
    function ref_perubahan_gelombang_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi perubahan_gelombang');
        $result['description'] = __t('Referensi isian perubahan_gelombang pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/faseLatihan_perubahan_gelombang/form',
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
                'field' => 'perubahan_gelombang',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_faseLatihan_perubahan_gelombang'),
            NULL,
            'perubahan_gelombang'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['perubahan_gelombang'] = ucwords($query->fields['perubahan_gelombang']);
                $result['data'][$i]['goto'] = '/reference/faseLatihan_perubahan_gelombang/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_perubahan_gelombang_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add faseLatihan_perubahan_gelombang'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'perubahan_gelombang',
            '#weight' => -3,
            '#action' => '/reference/faseLatihan_perubahan_gelombang/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_faseLatihan_perubahan_gelombang');
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

    function ref_perubahan_gelombang_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/faseLatihan_perubahan_gelombang/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_faseLatihan_perubahan_gelombang', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_faseLatihan_perubahan_gelombang',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/faseLatihan_perubahan_gelombang');
//        } else {
//            redirect_to('/reference/faseLatihan_perubahan_gelombang/form');
//        }
    }

    function ref_perubahan_gelombang_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'perubahan_gelombang', 'fase_latihan', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi perubahan_gelombang');
        $result['description'] = __t('informasi detil referensi perubahan_gelombang yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/faseLatihan_perubahan_gelombang/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'perubahan_gelombang'),
            array('ref_faseLatihan_perubahan_gelombang'),
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
                'link' => '/reference/faseLatihan_perubahan_gelombang/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/faseLatihan_perubahan_gelombang/edit/',
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

    function ref_perubahan_gelombang_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_faseLatihan_perubahan_gelombang', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_faseLatihan_perubahan_gelombang',
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
        redirect_to('/reference/faseLatihan_perubahan_gelombang/detail/' . $_POST['id']);
    }

    function ref_perubahan_gelombang_drop(){
        if($this->__is_dropable($_POST['id'], 'perubahan_gelombang', 'fase_latihan', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_faseLatihan_perubahan_gelombang',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/faseLatihan_perubahan_gelombang');
    }

    //---------------dihentikan-------------------------------------------------
    function ref_dihentikan_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi dihentikan fase latihan');
        $result['description'] = __t('Referensi isian dihentikan fase latihan');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/faseLatihan_dihentikan/form',
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
                'field' => 'dihentikan',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_faseLatihan_dihentikan'),
            NULL,
            'dihentikan'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['type'] = ucwords($query->fields['dihentikan']);
                $result['data'][$i]['goto'] = '/reference/faseLatihan_dihentikan/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_dihentikan_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add faseLatihan_dihentikan'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'dihentikan',
            '#weight' => -3,
            '#action' => '/reference/faseLatihan_dihentikan/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_faseLatihan_dihentikan');
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

    function ref_dihentikan_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/faseLatihan_dihentikan/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_faseLatihan_dihentikan', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_faseLatihan_dihentikan',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/faseLatihan_dihentikan');
//        } else {
//            redirect_to('/reference/faseLatihan_dihentikan/form');
//        }
    }

    function ref_dihentikan_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'dihentikan', 'fase_latihan', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi dihentikan fase latihan');
        $result['description'] = __t('informasi detil referensi dihentikan fase latihan yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/faseLatihan_dihentikan/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'dihentikan'),
            array('ref_faseLatihan_dihentikan'),
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
                'link' => '/reference/faseLatihan_dihentikan/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/faseLatihan_dihentikan/edit/',
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

    function ref_dihentikan_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_faseLatihan_dihentikan', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_faseLatihan_dihentikan',
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
        redirect_to('/reference/faseLatihan_dihentikan/detail/' . $_POST['id']);
    }

    function ref_dihentikan_drop(){
        if($this->__is_dropable($_POST['id'], 'dihentikan', 'fase_latihan', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_faseLatihan_dihentikan',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/faseLatihan_dihentikan');
    }

    //---------------respon jantung---------------------------------------------
    function ref_respon_jantung_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi respon_jantung fase latihan');
        $result['description'] = __t('Referensi isian respon_jantung fase latihan');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/faseLatihan_respon_jantung/form',
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
            array('ref_faseLatihan_respon_jantung'),
            NULL,
            'respon_jantung'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['type'] = ucwords($query->fields['respon_jantung']);
                $result['data'][$i]['goto'] = '/reference/faseLatihan_respon_jantung/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_respon_jantung_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add faseLatihan_respon_jantung'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'respon_jantung',
            '#weight' => -3,
            '#action' => '/reference/faseLatihan_respon_jantung/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_faseLatihan_respon_jantung');
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

    function ref_respon_jantung_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/faseLatihan_respon_jantung/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_faseLatihan_respon_jantung', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_faseLatihan_respon_jantung',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/faseLatihan_respon_jantung');
//        } else {
//            redirect_to('/reference/faseLatihan_respon_jantung/form');
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
        $result['dropable'] = $dropable !== FALSE ? '/reference/faseLatihan_respon_jantung/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'respon_jantung'),
            array('ref_faseLatihan_respon_jantung'),
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
                'link' => '/reference/faseLatihan_respon_jantung/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/faseLatihan_respon_jantung/edit/',
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
                if(in_array($key, $this->__get_data_fields('ref_faseLatihan_respon_jantung', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_faseLatihan_respon_jantung',
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
        redirect_to('/reference/faseLatihan_respon_jantung/detail/' . $_POST['id']);
    }

    function ref_respon_jantung_drop(){
        if($this->__is_dropable($_POST['id'], 'respon_jantung', 'fase_latihan', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_faseLatihan_respon_jantung',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/faseLatihan_respon_jantung');
    }

    function treadmill_menu(){
        $result = array();
        $result['#title'] = __t('Fase Latihan');
        $result['#tpl'] = MODULES_DIR . DS . 'faseLatihan' . DS . 'faseLatihan.tpl';
        $datafields = $this->__get_data_fields('treadmill_faselatihan', $this->query);
        //echo '<pre>'; print_r($this->config->faseLatihan); echo '</pre>';
        foreach($this -> config->faseLatihan as $key => $value){

            $result['datafields'][$key] = array(
                'title' => __t($key),
            );

            foreach ($value as $isi) {
                $result['datafields'][$key][$isi]= array (
                    'title' => __t($isi),
                    'type' => "text",
                    'size' => '5'
                );
            }

//            if(in_array($value, $this->config->fieldsisarray)){
//                $result['datafields'][$value]['theref'] = $this->__get_refs($value);
//            } elseif($this->config->typeoffields[$value] == 'datetime'){
//                $result['datafields'][$value]['theref'] = $this->nama_bulan;
//                $result['datafields'][$value]['timenow'] = $this->config->time;
//            } else {
//                $result['datafields'][$value]['size'] = 6;
//            }
        }
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }




}

