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
 *  bagianclass.php
 *  
 *  Created on Nov 23, 2009, 10:01:40 AM
 */

require_once MODULES_DIR . DS . 'bagian' . DS . 'config.inc';

class bagianModule extends mainModule
{
    var $title = 'bagian';
    var $description = 'Manage Bagian Menus';

    function menu(){
        $items['bagian_view'] = array(
            'title' => __t('Daftar Bagian'),
            'description' => __t('List Bagian'),
            'path' => '/reference/bagian',
            'exec' => 'view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['bagian_form'] = array(
            'title' => __t('Formulir Input Bagian'),
            'description' => __t('Formulir Input Bagian'),
            'path' => '/reference/bagian/form',
            'exec' => 'form',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['bagian_detail'] = array(
            'title' => __t('detail bagian'),
            'description' => __t('detail bagian'),
            'path' => '/reference/bagian/detail',
            'exec' => 'detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['bagian_form_submit'] = array(
            'title' => __t('bagian form submit'),
            'description' => __t('Execute bagian reference form'),
            'path' => '/reference/bagian/form_submit',
            'exec' => 'form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['bagian_edit'] = array(
            'title' => __t('bagian edit'),
            'description' => __t('Editing bagian reference form'),
            'path' => '/reference/bagian/edit',
            'exec' => 'edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['bagian_drop'] = array(
            'title' => __t('bagian drop'),
            'description' => __t('Remove bagian reference form'),
            'path' => '/reference/bagian/drop',
            'exec' => 'drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        return $items;
    }

    function view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Daftar Bagian');
        $result['description'] = __t('Referensi Bagian');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/bagian/form',
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
                'field' => 'bagian',
                'caption' => __t('bagian'),
                'align' => 'left'
            ),
            array(
                'field' => 'tableuse',
                'caption' => __t('Nama Tabel'),
                'width' => '25%',
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('bagian'),
            NULL,
            'bagian'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['bagian'] = ucwords($query->fields['bagian']);
                $result['data'][$i]['goto'] = '/reference/bagian/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $sql = $this->query->getSelect(
            array('id', 'bagian', 'tableuse'),
            array('bagian'),
            array(
                array('&&', "id=" . $keyid)
            )
        );
        $this->query->connect();
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        $dropable = $this->__is_dropable($query->fields['bagian'], 'bagian', 'kunjungan', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi bagian');
        $result['description'] = __t('informasi detil referensi bagian yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/bagian/drop' : '0';
        unset($dropable);
        if(isset($update)){
            $showsubmit = array('textarea', 'date');
        }
        foreach($query->fields as $key => $value){
            $result['data'][$key] = array(
                'key' => __t($key),
                'value' => $value,
                'link' => '/reference/bagian/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/bagian/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => $this->config->typeoffields[$key],
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->config->typeoffields[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->config->typeoffields[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : '',
                            '#option' => $this->config->typeoffields[$key] == 'select' ? $this->__refTable() : ''
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

    function form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        } else {
            $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
            if(isset($dump[3])){
                $sql = $this->query->getSelect(
                    array(),
                    array('bagian'),
                    array(
                        array('&&', "id=" . trim($dump[3]))
                    )
                );
                $this->query->connect();
                $getit = $this->query->conn->Execute($sql); unset($sql);
                $this->query->close();
                if($getit->_numOfRows > 0){
                    foreach($getit->fields as $key => $value){
                        $vcache[$key] = $value;
                    }
                } unset($getit);
            }
        }
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add bagian'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'bagian',
            '#weight' => -3,
            '#action' => '/reference/bagian/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('bagian');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => ($query->fields['Field'] == 'bagian' ? 'text' : 'select'),
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0,
                    '#option' => ($query->fields['Field'] == 'bagian' ? '' : $this->__refTable())
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

    function __refTable(){
        $result = array();
        $sql = 'SHOW TABLES';
        $this->query->connect();
        $getit = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($getit->_numOfRows > 0){
            for($i=0; $i<$getit->_numOfRows; $i++){
                if(!preg_match('/^ref_/', preg_replace('/^' . $this->query->tbprefix . "_/", '', $getit->fields['Tables_in_' . $this->query->getDbName()]))){
                    $tbname = preg_replace("/^" . $this->query->tbprefix . "_/", '', $getit->fields['Tables_in_' . $this->query->getDbName()]);
                    $tbname = preg_replace("/_" . $this->query->tbsuffix . "$/", '', $getit->fields['Tables_in_' . $this->query->getDbName()]);
                    $result[$tbname] = $tbname;
                    unset($tbname);
                } $getit->MoveNext();
            }
        }
//        echo '<pre>'; print_r($result); echo '</pre>'; exit();
        return $result;
    }

    function form_submit(){
        $dump = $this->__write_form_cache();
        foreach($dump as $key => $value){
            if($value == ''){
                $this->__write_custom_cache(
                    array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                );
                redirect_to('/reference/bagian/form');
                exit();
            }
            if($key != 'blank' && $key != 'submit'){
                $thevalue[$key] = $value;
            }
        } unset($dump);
        $thevalue['id'] = $this->__get_id_insert_value('bagian', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
        $this->query->connect();
        $sql = $this->query->saveData(
            'bagian',
            $thevalue
        );
        $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        unset($thevalue);
        redirect_to('/reference/bagian');
    }

    function edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('bagian', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'bagian',
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
        redirect_to('/reference/bagian/detail/' . $_POST['id']);
    }

    function drop(){
        if($this->__is_dropable($_POST['id'], 'bagian', 'kunjungan', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'bagian',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/bagian');
    }

}