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
 *  threadKesimpulanSaranclass.php
 *  
 *  Created on Oct 3, 2009, 8:39:24 PM
 */

require_once MODULES_DIR . DS . 'threadKesimpulanSaran' . DS . 'config.inc';

class threadKesimpulanSaranModule extends mainModule
{
    var $title = 'threadKesimpulanSaran module';
    var $description = '';

    function menu(){
        $items['ref_threadKesimpulanSaran_Ulib'] = array(
            'title' => __t('ULIB'),
            'description' => __t('Ulib reference form for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_Ulib',
            'exec' => 'ref_Ulib_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_threadKesimpulanSaran_Ulib_detail'] = array(
            'title' => __t('detil tipe tanda vital'),
            'description' => __t('Ulib reference detail for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_Ulib/detail',
            'exec' => 'ref_Ulib_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_threadKesimpulanSaran_Ulib_form'] = array(
            'title' => __t('threadKesimpulanSaran_Ulib form'),
            'description' => __t('Ulib reference form for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_Ulib/form',
            'exec' => 'ref_Ulib_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_threadKesimpulanSaran_Ulib_form_submit'] = array(
            'title' => __t('threadKesimpulanSaran_Ulib form'),
            'description' => __t('Execute Ulib reference form for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_Ulib/form_submit',
            'exec' => 'ref_Ulib_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_threadKesimpulanSaran_Ulib_edit'] = array(
            'title' => __t('threadKesimpulanSaran_Ulib edit'),
            'description' => __t('Editing Ulib reference form for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_Ulib/edit',
            'exec' => 'ref_Ulib_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_threadKesimpulanSaran_Ulib_drop'] = array(
            'title' => __t('threadKesimpulanSaran_Ulib drop'),
            'description' => __t('Remove Ulib reference form for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_Ulib/drop',
            'exec' => 'ref_Ulib_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );

        //------------------- Respon Tekanan Darah -------------------------
        $items['ref_threadKesimpulanSaran_tekananDarah'] = array(
            'title' => __t('Respon tekanan darah'),
            'description' => __t('respon tekanan darah reference form for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_tekananDarah',
            'exec' => 'ref_tekananDarah_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_threadKesimpulanSaran_tekananDarah_detail'] = array(
            'title' => __t('detil respon tekanan darah'),
            'description' => __t('tekananDarah reference detail for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_tekananDarah/detail',
            'exec' => 'ref_tekananDarah_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_threadKesimpulanSaran_tekananDarah_form'] = array(
            'title' => __t('threadKesimpulanSaran_tekananDarah form'),
            'description' => __t('tekananDarah reference form for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_tekananDarah/form',
            'exec' => 'ref_tekananDarah_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_threadKesimpulanSaran_tekananDarah_form_submit'] = array(
            'title' => __t('threadKesimpulanSaran_tekananDarah form'),
            'description' => __t('Execute tekananDarah reference form for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_tekananDarah/form_submit',
            'exec' => 'ref_tekananDarah_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_threadKesimpulanSaran_tekananDarah_edit'] = array(
            'title' => __t('threadKesimpulanSaran_tekananDarah edit'),
            'description' => __t('Editing tekananDarah reference form for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_tekananDarah/edit',
            'exec' => 'ref_tekananDarah_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_threadKesimpulanSaran_tekananDarah_drop'] = array(
            'title' => __t('threadKesimpulanSaran_tekananDarah drop'),
            'description' => __t('Remove tekananDarah reference form for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_tekananDarah/drop',
            'exec' => 'ref_tekananDarah_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );

        //---------------- Tingkat kesegaran Jasmani ---------------------
        $items['ref_threadKesimpulanSaran_kesegaran'] = array(
            'title' => __t('Tingkat Kesegaran Jasmani'),
            'description' => __t('kesegaran reference form for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_kesegaran',
            'exec' => 'ref_kesegaran_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_threadKesimpulanSaran_kesegaran_detail'] = array(
            'title' => __t('detil tingkat kesegaran jasmani'),
            'description' => __t('kesegaran reference detail for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_kesegaran/detail',
            'exec' => 'ref_kesegaran_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_threadKesimpulanSaran_kesegaran_form'] = array(
            'title' => __t('threadKesimpulanSaran_kesegaran form'),
            'description' => __t('kesegaran reference form for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_kesegaran/form',
            'exec' => 'ref_kesegaran_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_threadKesimpulanSaran_kesegaran_form_submit'] = array(
            'title' => __t('threadKesimpulanSaran_kesegaran form'),
            'description' => __t('Execute kesegaran reference form for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_kesegaran/form_submit',
            'exec' => 'ref_kesegaran_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_threadKesimpulanSaran_kesegaran_edit'] = array(
            'title' => __t('threadKesimpulanSaran_kesegaran edit'),
            'description' => __t('Editing kesegaran reference form for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_kesegaran/edit',
            'exec' => 'ref_kesegaran_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_threadKesimpulanSaran_kesegaran_drop'] = array(
            'title' => __t('threadKesimpulanSaran_kesegaran drop'),
            'description' => __t('Remove kesegaran reference form for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_kesegaran/drop',
            'exec' => 'ref_kesegaran_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );

        //---------------- Klasifikasi fungsional ---------------------
        $items['ref_threadKesimpulanSaran_fungsional'] = array(
            'title' => __t('Klasifikasi Fungsional'),
            'description' => __t('fungsional reference form for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_fungsional',
            'exec' => 'ref_fungsional_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_threadKesimpulanSaran_fungsional_detail'] = array(
            'title' => __t('detil Klasifikasi fungsional'),
            'description' => __t('fungsional reference detail for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_fungsional/detail',
            'exec' => 'ref_fungsional_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_threadKesimpulanSaran_fungsional_form'] = array(
            'title' => __t('threadKesimpulanSaran_fungsional form'),
            'description' => __t('fungsional reference form for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_fungsional/form',
            'exec' => 'ref_fungsional_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_threadKesimpulanSaran_fungsional_form_submit'] = array(
            'title' => __t('threadKesimpulanSaran_fungsional form'),
            'description' => __t('Execute fungsional reference form for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_fungsional/form_submit',
            'exec' => 'ref_fungsional_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_threadKesimpulanSaran_fungsional_edit'] = array(
            'title' => __t('threadKesimpulanSaran_fungsional edit'),
            'description' => __t('Editing fungsional reference form for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_fungsional/edit',
            'exec' => 'ref_fungsional_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_threadKesimpulanSaran_fungsional_drop'] = array(
            'title' => __t('threadKesimpulanSaran_fungsional drop'),
            'description' => __t('Remove fungsional reference form for threadKesimpulanSaran'),
            'path' => '/reference/threadKesimpulanSaran_fungsional/drop',
            'exec' => 'ref_fungsional_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        return $items;
    }

    function ref_Ulib_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Ulib');
        $result['description'] = __t('Referensi isian Ulib pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/threadKesimpulanSaran_Ulib/form',
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
                'field' => 'Ulib',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_threadKesimpulanSaran_Ulib')
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['Ulib'] = ucwords($query->fields['Ulib']);
                $result['data'][$i]['goto'] = '/reference/threadKesimpulanSaran_Ulib/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_Ulib_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add threadKesimpulanSaran_Ulib'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'Ulib',
            '#weight' => -3,
            '#action' => '/reference/threadKesimpulanSaran_Ulib/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_threadKesimpulanSaran_Ulib');
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
		//echo '<pre>';print_r ($form);echo '</pre>';
        return $form;
    }

    function ref_Ulib_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/threadKesimpulanSaran_Ulib/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_threadKesimpulanSaran_Ulib', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_threadKesimpulanSaran_Ulib',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/threadKesimpulanSaran_Ulib');
//        } else {
//            redirect_to('/reference/threadKesimpulanSaran_type/form');
//        }
    }

    function ref_Ulib_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'Ulib', 'kesimpulan_saran', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi tipe tanda vital');
        $result['description'] = __t('informasi detil referensi tipe tanda vital yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/threadKesimpulanSaran_Ulib/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'Ulib'),
            array('ref_threadKesimpulanSaran_Ulib'),
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
                'link' => '/reference/threadKesimpulanSaran_Ulib/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/threadKesimpulanSaran_Ulib/edit/',
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

    function ref_Ulib_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_threadKesimpulanSaran_Ulib', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_threadKesimpulanSaran_Ulib',
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
        redirect_to('/reference/threadKesimpulanSaran_Ulib/detail/' . $_POST['id']);
    }

    function ref_Ulib_drop(){
        if($this->__is_dropable($_POST['id'], 'Ulib', 'kesimpulan_saran', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_threadKesimpulanSaran_Ulib',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/threadKesimpulanSaran_Ulib');
    }

    //------------------function tekanan darah-----------------------
    function ref_tekananDarah_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi tekanan Darah');
        $result['description'] = __t('Referensi isian tekanan Darah');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/threadKesimpulanSaran_tekananDarah/form',
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
                'field' => 'tekananDarah',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_threadKesimpulanSaran_tekananDarah'),
            NULL,
            'tekananDarah'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['tekananDarah'] = ucwords($query->fields['tekananDarah']);
                $result['data'][$i]['goto'] = '/reference/threadKesimpulanSaran_tekananDarah/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_tekananDarah_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add respon tekanan darah'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'tekananDarah',
            '#weight' => -3,
            '#action' => '/reference/threadKesimpulanSaran_tekananDarah/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_threadKesimpulanSaran_tekananDarah');
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
            //echo '<pre>';print_r ($form);echo '</pre>';
        return $form;
    }

    function ref_tekananDarah_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/threadKesimpulanSaran_tekananDarah/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_threadKesimpulanSaran_tekananDarah', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_threadKesimpulanSaran_tekananDarah',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/threadKesimpulanSaran_tekananDarah');
//        } else {
//            redirect_to('/reference/threadKesimpulanSaran_tekananDarah/form');
//        }
    }

    function ref_tekananDarah_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'tekananDarah', 'kesimpulan_saran', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi tekanan Darah');
        $result['description'] = __t('informasi detil referensi tekanan Darah yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/threadKesimpulanSaran_tekananDarah/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'tekananDarah'),
            array('ref_threadKesimpulanSaran_tekananDarah'),
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
                'link' => '/reference/threadKesimpulanSaran_tekananDarah/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/threadKesimpulanSaran_tekananDarah/edit/',
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

    function ref_tekananDarah_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_threadKesimpulanSaran_tekananDarah', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_threadKesimpulanSaran_tekananDarah',
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
        redirect_to('/reference/threadKesimpulanSaran_tekananDarah/detail/' . $_POST['id']);
    }

    function ref_tekananDarah_drop(){
        if($this->__is_dropable($_POST['id'], 'tekananDarah', 'kesimpulan_saran', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_threadKesimpulanSaran_tekananDarah',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/threadKesimpulanSaran_tekananDarah');
    }

    //--------------------Tingkat kesegaran jasmani ---------------------
    function ref_kesegaran_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi kesegaran');
        $result['description'] = __t('Referensi isian kesegaran pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/threadKesimpulanSaran_kesegaran/form',
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
                'field' => 'kesegaran',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_threadKesimpulanSaran_kesegaran'),
            NULL,
            'kesegaran'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['kesegaran'] = ucwords($query->fields['kesegaran']);
                $result['data'][$i]['goto'] = '/reference/threadKesimpulanSaran_kesegaran/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_kesegaran_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add threadKesimpulanSaran_kesegaran'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'kesegaran',
            '#weight' => -3,
            '#action' => '/reference/threadKesimpulanSaran_kesegaran/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_threadKesimpulanSaran_kesegaran');
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

    function ref_kesegaran_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/threadKesimpulanSaran_kesegaran/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_threadKesimpulanSaran_kesegaran', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_threadKesimpulanSaran_kesegaran',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/threadKesimpulanSaran_kesegaran');
//        } else {
//            redirect_to('/reference/threadKesimpulanSaran_kesegaran/form');
//        }
    }

    function ref_kesegaran_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'kesegaran', 'vital_sign', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi kesegaran');
        $result['description'] = __t('informasi detil referensi kesegaran yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/threadKesimpulanSaran_kesegaran/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'kesegaran'),
            array('ref_threadKesimpulanSaran_kesegaran'),
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
                'link' => '/reference/threadKesimpulanSaran_kesegaran/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/threadKesimpulanSaran_kesegaran/edit/',
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

    function ref_kesegaran_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_threadKesimpulanSaran_kesegaran', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_threadKesimpulanSaran_kesegaran',
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
        redirect_to('/reference/threadKesimpulanSaran_kesegaran/detail/' . $_POST['id']);
    }

    function ref_kesegaran_drop(){
        if($this->__is_dropable($_POST['id'], 'kesegaran', 'vital_sign', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_threadKesimpulanSaran_kesegaran',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/threadKesimpulanSaran_kesegaran');
    }

    //--------------------Function fungsional----------------------------
    function ref_fungsional_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi fungsional');
        $result['description'] = __t('Referensi isian fungsional pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/threadKesimpulanSaran_fungsional/form',
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
                'field' => 'fungsional',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_threadKesimpulanSaran_fungsional'),
            NULL,
            'fungsional'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['fungsional'] = ucwords($query->fields['fungsional']);
                $result['data'][$i]['goto'] = '/reference/threadKesimpulanSaran_fungsional/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_fungsional_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add threadKesimpulanSaran_fungsional'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'fungsional',
            '#weight' => -3,
            '#action' => '/reference/threadKesimpulanSaran_fungsional/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_threadKesimpulanSaran_fungsional');
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

    function ref_fungsional_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/threadKesimpulanSaran_fungsional/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_threadKesimpulanSaran_fungsional', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_threadKesimpulanSaran_fungsional',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/threadKesimpulanSaran_fungsional');
//        } else {
//            redirect_to('/reference/threadKesimpulanSaran_fungsional/form');
//        }
    }

    function ref_fungsional_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'fungsional', 'vital_sign', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi fungsional');
        $result['description'] = __t('informasi detil referensi fungsional yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/threadKesimpulanSaran_fungsional/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'fungsional'),
            array('ref_threadKesimpulanSaran_fungsional'),
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
                'link' => '/reference/threadKesimpulanSaran_fungsional/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/threadKesimpulanSaran_fungsional/edit/',
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

    function ref_fungsional_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_threadKesimpulanSaran_fungsional', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_threadKesimpulanSaran_fungsional',
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
        redirect_to('/reference/threadKesimpulanSaran_fungsional/detail/' . $_POST['id']);
    }

    function ref_fungsional_drop(){
        if($this->__is_dropable($_POST['id'], 'fungsional', 'vital_sign', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_threadKesimpulanSaran_fungsional',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/threadKesimpulanSaran_fungsional');
    }

}