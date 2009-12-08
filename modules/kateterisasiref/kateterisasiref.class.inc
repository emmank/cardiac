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
 *  kateterisasirefclass.php
 *  
 *  Created on Oct 3, 2009, 8:39:24 PM
 */

require_once MODULES_DIR . DS . 'kateterisasiref' . DS . 'config.inc';

class kateterisasirefModule extends mainModule
{
    var $title = 'kateterisasiref module';
    var $description = '';

    function menu(){
//---------------------------1. depresi -------------------------------------------
        $items['ref_kateterisasiref_steunosis'] = array(
            'title' => __t('kateterisasi steunosis'),
            'description' => __t('steunosis reference form for kateterisasiref'),
            'path' => '/reference/kateterisasiref_steunosis',
            'exec' => 'ref_steunosis_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_kateterisasiref_steunosis_detail'] = array(
            'title' => __t('detil steunosis pada kateterisasi'),
            'description' => __t('referensi steunosis pada kateterisasi'),
            'path' => '/reference/kateterisasiref_steunosis/detail',
            'exec' => 'ref_steunosis_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_kateterisasiref_steunosis_form'] = array(
            'title' => __t('kateterisasiref_steunosis form'),
            'description' => __t('referensi steunosis pada kateterisasi'),
            'path' => '/reference/kateterisasiref_steunosis/form',
            'exec' => 'ref_steunosis_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_kateterisasiref_steunosis_form_submit'] = array(
            'title' => __t('kateterisasiref_steunosis form'),
            'description' => __t('Execute referensi steunosis pada kateterisasi'),
            'path' => '/reference/kateterisasiref_steunosis/form_submit',
            'exec' => 'ref_steunosis_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_kateterisasiref_steunosis_edit'] = array(
            'title' => __t('kateterisasiref_steunosis edit'),
            'description' => __t('Editing referensi steunosis pada kateterisasi'),
            'path' => '/reference/kateterisasiref_steunosis/edit',
            'exec' => 'ref_steunosis_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_kateterisasiref_steunosis_drop'] = array(
            'title' => __t('kateterisasiref_steunosis drop'),
            'description' => __t('Remove referensi steunosis pada kateterisasi'),
            'path' => '/reference/kateterisasiref_steunosis/drop',
            'exec' => 'ref_steunosis_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );

//-------------------------2. komentar--------------------------------------------
        $items['ref_kateterisasiref_komentar'] = array(
            'title' => __t('kateterisasi komentar'),
            'description' => __t('komentar reference form for kateterisasiref'),
            'path' => '/reference/kateterisasiref_komentar',
            'exec' => 'ref_komentar_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_kateterisasiref_komentar_detail'] = array(
            'title' => __t('detil komentar'),
            'description' => __t('komentar reference detail for kateterisasiref'),
            'path' => '/reference/kateterisasiref_komentar/detail',
            'exec' => 'ref_komentar_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_kateterisasiref_komentar_form'] = array(
            'title' => __t('kateterisasiref_komentar form'),
            'description' => __t('komentar reference form for kateterisasiref'),
            'path' => '/reference/kateterisasiref_komentar/form',
            'exec' => 'ref_komentar_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_kateterisasiref_komentar_form_submit'] = array(
            'title' => __t('kateterisasiref_komentar form'),
            'description' => __t('Execute komentar reference form for kateterisasiref'),
            'path' => '/reference/kateterisasiref_komentar/form_submit',
            'exec' => 'ref_komentar_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_kateterisasiref_komentar_edit'] = array(
            'title' => __t('kateterisasiref_komentar edit'),
            'description' => __t('Editing komentar reference form for kateterisasiref'),
            'path' => '/reference/kateterisasiref_komentar/edit',
            'exec' => 'ref_komentar_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_kateterisasiref_komentar_drop'] = array(
            'title' => __t('kateterisasiref_komentar drop'),
            'description' => __t('Remove komentar reference form for kateterisasiref'),
            'path' => '/reference/kateterisasiref_komentar/drop',
            'exec' => 'ref_komentar_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        //-------------------------- 3. Anjuran --------------------------------
        $items['ref_kateterisasiref_anjuran'] = array(
            'title' => __t('Katerisasi anjuran'),
            'description' => __t('anjuran reference form for kateterisasiref'),
            'path' => '/reference/kateterisasiref_anjuran',
            'exec' => 'ref_anjuran_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_kateterisasiref_anjuran_detail'] = array(
            'title' => __t('detil anjuran kateterisasi'),
            'description' => __t('anjuran reference detail for kateterisasiref'),
            'path' => '/reference/kateterisasiref_anjuran/detail',
            'exec' => 'ref_anjuran_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_kateterisasiref_anjuran_form'] = array(
            'title' => __t('kateterisasiref_anjuran form'),
            'description' => __t('anjuran reference form for kateterisasiref'),
            'path' => '/reference/kateterisasiref_anjuran/form',
            'exec' => 'ref_anjuran_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_kateterisasiref_anjuran_form_submit'] = array(
            'title' => __t('kateterisasiref_anjuran form'),
            'description' => __t('Execute anjuran reference form for kateterisasiref'),
            'path' => '/reference/kateterisasiref_anjuran/form_submit',
            'exec' => 'ref_anjuran_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_kateterisasiref_anjuran_edit'] = array(
            'title' => __t('kateterisasiref_anjuran edit'),
            'description' => __t('Editing anjuran reference form for kateterisasiref'),
            'path' => '/reference/kateterisasiref_anjuran/edit',
            'exec' => 'ref_anjuran_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_kateterisasiref_anjuran_drop'] = array(
            'title' => __t('kateterisasiref_anjuran drop'),
            'description' => __t('Remove anjuran reference form for kateterisasiref'),
            'path' => '/reference/kateterisasiref_anjuran/drop',
            'exec' => 'ref_anjuran_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        
        return $items;
    }

    function ref_steunosis_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi steunosis pada kateterisasi');
        $result['description'] = __t('Referensi isian steunosis pada kateterisasi');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/kateterisasiref_steunosis/form',
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
                'field' => 'steunosis',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_kateterisasiref_steunosis'),
            NULL
           
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['type'] = ucwords($query->fields['steunosis']);
                $result['data'][$i]['goto'] = '/reference/kateterisasiref_steunosis/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_steunosis_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add kateterisasiref_steunosis'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'steunosis',
            '#weight' => -3,
            '#action' => '/reference/kateterisasiref_steunosis/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_kateterisasiref_steunosis');
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

    function ref_steunosis_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/kateterisasiref_steunosis/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_kateterisasiref_steunosis', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_kateterisasiref_steunosis',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/kateterisasiref_steunosis');
//        } else {
//            redirect_to('/reference/kateterisasiref_steunosis/form');
//        }
    }

    function ref_steunosis_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'steunosis', 'kateterisasi_steunosis', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi steunosis pada kateterisasi');
        $result['description'] = __t('informasi detil referensi steunosis pada kateterisasi yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/kateterisasiref_steunosis/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'steunosis'),
            array('ref_kateterisasiref_steunosis'),
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
                'link' => '/reference/kateterisasiref_steunosis/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/kateterisasiref_steunosis/edit/',
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

    function ref_steunosis_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_kateterisasiref_steunosis', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_kateterisasiref_steunosis',
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
        redirect_to('/reference/kateterisasiref_steunosis/detail/' . $_POST['id']);
    }

    function ref_steunosis_drop(){
        if($this->__is_dropable($_POST['id'], 'steunosis', 'kateterisasi_steunosis', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_kateterisasiref_steunosis',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/kateterisasiref_steunosis');
    }

//--------------------------2. komentar ------------------------------------------
   function ref_komentar_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi komentar pada kateterisasi');
        $result['description'] = __t('Referensi isian komentar pada kateterisasi');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/kateterisasiref_komentar/form',
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
                'field' => 'komentar',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_kateterisasiref_komentar'),
            NULL
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['komentar'] = ucwords($query->fields['komentar']);
                $result['data'][$i]['goto'] = '/reference/kateterisasiref_komentar/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_komentar_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add kateterisasiref_komentar'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'komentar',
            '#weight' => -3,
            '#action' => '/reference/kateterisasiref_komentar/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_kateterisasiref_komentar');
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

    function ref_komentar_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/kateterisasiref_komentar/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_kateterisasiref_komentar', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_kateterisasiref_komentar',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/kateterisasiref_komentar');
//        } else {
//            redirect_to('/reference/kateterisasiref_komentar/form');
//        }
    }

    function ref_komentar_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'komentar', 'kateterisasi', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi komentar pada kateterisasi');
        $result['description'] = __t('informasi detil referensi komentar yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/kateterisasiref_komentar/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'komentar'),
            array('ref_kateterisasiref_komentar'),
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
                'link' => '/reference/kateterisasiref_komentar/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/kateterisasiref_komentar/edit/',
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

    function ref_komentar_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_kateterisasiref_komentar', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_kateterisasiref_komentar',
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
        redirect_to('/reference/kateterisasiref_komentar/detail/' . $_POST['id']);
    }

    function ref_komentar_drop(){
        if($this->__is_dropable($_POST['id'], 'komentar', 'kateterisasi', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_kateterisasiref_komentar',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/kateterisasiref_komentar');
    }

//---------------------------3. Anjuran -------------------------------------
    function ref_anjuran_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi anjuran');
        $result['description'] = __t('Referensi isian anjuran kateterisasi');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/kateterisasiref_anjuran/form',
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
                'field' => 'anjuran',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_kateterisasiref_anjuran'),
            NULL
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['anjuran'] = ucwords($query->fields['anjuran']);
                $result['data'][$i]['goto'] = '/reference/kateterisasiref_anjuran/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_anjuran_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add kateterisasiref_anjuran'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'anjuran',
            '#weight' => -3,
            '#action' => '/reference/kateterisasiref_anjuran/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_kateterisasiref_anjuran');
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

    function ref_anjuran_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/kateterisasiref_anjuran/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_kateterisasiref_anjuran', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_kateterisasiref_anjuran',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/kateterisasiref_anjuran');
//        } else {
//            redirect_to('/reference/kateterisasiref_anjuran/form');
//        }
    }

    function ref_anjuran_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'anjuran', 'kateterisasi', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi anjuran');
        $result['description'] = __t('informasi detil referensi anjuran yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/kateterisasiref_anjuran/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'anjuran'),
            array('ref_kateterisasiref_anjuran'),
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
                'link' => '/reference/kateterisasiref_anjuran/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/kateterisasiref_anjuran/edit/',
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

    function ref_anjuran_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_kateterisasiref_anjuran', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_kateterisasiref_anjuran',
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
        redirect_to('/reference/kateterisasiref_anjuran/detail/' . $_POST['id']);
    }

    function ref_anjuran_drop(){
        if($this->__is_dropable($_POST['id'], 'anjuran', 'kateterisasi', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_kateterisasiref_anjuran',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/kateterisasiref_anjuran');
    }

}