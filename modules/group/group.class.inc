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
 *  groupadmin.php
 *  
 *  Created on Sep 26, 2009, 10:28:19 AM
 */

require_once MODULES_DIR . DS . 'group' . DS . 'config.inc';

class groupModule extends mainModule
{
    var $title = 'group module';
    var $hidefields = array(
        'id',
        'useradd'
    );
    var $groups_fields = array(
        'id',
        'name',
        'useradd'
    );
    var $formtype_fields = array(
        'id' => 'hidden',
        'name' => 'text',
        'useradd' => 'textarea'
    );

    function menu(){
        $items['group_view'] = array(
            'title' => __t('group'),
            'description' => __t('menu untuk menampilkan daftar group yang terdaftar'),
            'path' => '/admin/group',
            'exec' => 'view',
            'weight' => '0',
            'user_required' => 'admin'
        );
        $items['group_detail'] = array(
            'title' => __t('group detail'),
            'description' => __t('menu untuk menampilkan detail group terdaftar yang terpilih'),
            'path' => '/admin/group/detail',
            'exec' => 'detail',
            'weight' => '0',
            'user_required' => 'admin'
        );
        $items['group_edit'] = array(
            'title' => __t('group edit'),
            'description' => __t('eksekusi perintah edit untuk tabel groups'),
            'path' => '/admin/group/edit',
            'exec' => 'edit',
            'weight' => '0',
            'user_required' => 'admin',
            'hidden' => TRUE
        );
        $items['group_add'] = array(
            'title' => __t('add group'),
            'description' => __t('formulir pendaftaran group'),
            'path' => '/admin/group/form',
            'exec' => 'form',
            'weight' => '0',
            'user_required' => 'admin',
        );
        $items['group_add_submit'] = array(
            'title' => __t('add group'),
            'description' => __t('eksekusi formulir pendaftaran group'),
            'path' => '/admin/group/form_submit',
            'exec' => 'form_submit',
            'weight' => '0',
            'user_required' => 'admin',
        );
        $items['group_drop'] = array(
            'title' => __t('delete group'),
            'description' => __t('eksekusi perintah delete groups'),
            'path' => '/admin/group/drop',
            'exec' => 'delete',
            'weight' => '0',
            'user_required' => 'admin',
            'hidden' => TRUE
        );
        return $items;
    }

    function __is_dropable($id){
        $this->sysquery->connect();
        $sql = $this->sysquery->getSelect(
            array($this->config->auth_use_table[4]),
            array($this->config->auth_use_table[0]),
            array(
                array('&&', "groups=" . $id)
            )
        );
        $query = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        if($query->_numOfRows < 1){
            return TRUE;
        } else {
            return FALSE;
        }
    }

    function delete(){
        if($this->__is_dropable($_POST['id']) !== FALSE){
            $this->sysquery->connect();
            $sql = $this->sysquery->setDelete(
                'groups',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->sysquery->conn->Execute($sql); unset($sql);
            $this->sysquery->close();
        }
        redirect_to('/admin/group');
    }

    function form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add group'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'name',
            '#weight' => -3,
            '#action' => '/admin/group/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->sysquery->connect();
        $sql = $this->sysquery->getDescribe('groups');
        $query = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], $this->hidefields)){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => $this->formtype_fields[$query->fields['Field']],
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

    function form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/admin/group/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('groups', 'id', $this->sysquery);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->sysquery->connect();
            $sql = $this->sysquery->saveData(
                'groups',
                $thevalue
            );
            $this->sysquery->conn->Execute($sql); unset($sql);
            $this->sysquery->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/admin/group');
//        } else {
//            redirect_to('/admin/group/form');
//        }
    }

    function edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->groups_fields)){
                    $this->sysquery->connect();
                    $sql = $this->sysquery->updateData(
                        'groups',
                        array(
                            $key => $value
                        ),
                        array(
                            array('&&', "id=" . $_POST['id'])
                        )
                    );
                    $this->sysquery->conn->Execute($sql); unset($sql);
                    $this->sysquery->close();
                }
            }
        }
        redirect_to('/admin/group/detail/' . $_POST['id']);
    }

    function detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil group');
        $result['description'] = __t('informasi detil group terdaftar yang terpilih');
        $result['id'] = $keyid;
        $result['dropable'] = $dropable !== FALSE ? '/admin/group/drop' : '0';
        unset($dropable);
        $this->sysquery->connect();
        $sql = $this->sysquery->getSelect(
            array('id', 'name'),
            array('groups'),
            array(
                array('&&', "id=" . $keyid)
            )
        );
        $query = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        if(isset($update)){
            $showsubmit = array('textarea', 'date');
        }
        foreach($query->fields as $key => $value){
            $result['data'][$key] = array(
                'key' => __t($key),
                'value' => $value,
                'link' => '/admin/group/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->hidefields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/admin/group/edit/',
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
        return $result;
    }


    function view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('daftar group');
        $result['description'] = __t('group yang terdaftar sebagai operator dan administrator system ini');
        $result['addmenu'] = array(
            'title' => __t('add group'),
            'action' => '/admin/group/form',
            'position' => 'top'
        );
        $result['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => 'name',
                'caption' => __t('name'),
                'align' => 'left'
            )
        );
        $this->sysquery->connect();
        $sql = $this->sysquery->getSelect(
            array('id', 'name'),
            array('groups')
        );
        $query = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            $result['data'][$i] = $query->fields;
            $result['data'][$i]['nama'] = ucwords($query->fields['name']);
            $result['data'][$i]['goto'] = '/admin/group/detail/' . $query->fields['id'];
        $query->MoveNext();
        } unset($query);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

}