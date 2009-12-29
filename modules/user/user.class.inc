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
 *  user.php
 *  
 *  Created on Sep 8, 2009, 9:28:36 PM
 */

require_once MODULES_DIR . DS . 'user' . DS . 'config.inc';

class userModule extends mainModule
{
    var $title = 'user module';
    var $hidefields = array(
        'id',
        'sandi',
        'sesi',
        'timelog',
        'inputtime'
    );
    var $formtype_fields = array(
        'id' => 'select',
        'userid' => 'text',
        'sandi' => 'text',
        'groups' => 'select',
        'theme' => 'select',
        'bahasa' => 'select',
        'sesi' => 'text',
        'timelog' => 'text',
        'nomor' => 'text',
        'nama' => 'text',
        'kelamin' => 'select',
        'tp_lahir' => 'text',
        'tgl_lahir' => 'date',
        'alamat' => 'textarea',
        'kota' => 'text',
        'propinsi' => 'text',
        'negara' => 'text',
        'no_ktp' => 'text',
        'agama' => 'select',
        'email' => 'text',
        'inputtime' => 'text'
    );
    var $users_fields = array(
        'id',
        'userid',
        'sandi',
        'groups',
        'theme',
        'bahasa',
        'sesi',
        'timelog'
    );
    var $stafs_fields = array(
        'id',
        'nomor',
        'nama',
        'kelamin',
        'tp_lahir',
        'tgl_lahir',
        'alamat',
        'kota',
        'propinsi',
        'negara',
        'no_ktp',
        'agama',
        'email',
        'sandi',
        'inputtime'
    );
    var $system_auto_insert_in_fields = array(
        'sesi',
        'timelog',
        'sandi',
        'groups',
        'theme',
        'bahasa'
    );
    var $hidden_fields = array(
        'sesi',
        'timelog',
        'id',
        'sandi',
        'groups'
    );

    function menu(){
        $items['user_view'] = array(
            'title' => __t('user'),
            'description' => __t('menu untuk menampilkan daftar pengguna yang terdaftar'),
            'path' => '/admin/user',
            'exec' => 'view',
            'weight' => '0',
            'user_required' => 'admin'
        );
        $items['user_detail'] = array(
            'title' => __t('user detail'),
            'description' => __t('menu untuk menampilkan detail pengguna terdaftar yang terpilih'),
            'path' => '/admin/user/detail',
            'exec' => 'detail',
            'weight' => '0',
            'user_required' => 'admin'
        );
        $items['user_edit'] = array(
            'title' => __t('user edit'),
            'description' => __t('eksekusi perintah edit untuk tabel users'),
            'path' => '/admin/user/edit',
            'exec' => 'edit',
            'weight' => '0',
            'user_required' => 'admin'
        );
        $items['user_drop'] = array(
            'title' => __t('delete user'),
            'description' => __t('eksekusi perintah delete users'),
            'path' => '/admin/user/drop',
            'exec' => 'delete',
            'weight' => '0',
            'user_required' => 'admin'
        );
        $items['user_add'] = array(
            'title' => __t('add user'),
            'description' => __t('formulir pendaftaran pengguna'),
            'path' => '/admin/user/form',
            'exec' => 'form',
            'weight' => '0',
            'user_required' => 'admin',
        );
        $items['user_add_submit'] = array(
            'title' => __t('add user'),
            'description' => __t('eksekusi formulir pendaftaran pengguna'),
            'path' => '/admin/user/form_submit',
            'exec' => 'form_submit',
            'weight' => '0',
            'user_required' => 'admin',
        );
        $items['user_settings'] = array(
            'title' => __t('user setings'),
            'description' => __t('perubahan informasi pengguna'),
            'path' => '/setting/edit',
            'exec' => 'seting_form',
            'weight' => '0',
            'user_required' => 'users',
        );
        $items['user_setting_form_submit'] = array(
            'title' => __t('user setings'),
            'description' => __t('eksekusi perubahan informasi pengguna'),
            'path' => '/setting/edit_submit',
            'exec' => 'seting_form_submit',
            'weight' => '0',
            'user_required' => 'users',
        );
        $items['user_password'] = array(
            'title' => __t('user password'),
            'description' => __t('perubahan sandi pengguna'),
            'path' => '/setting/sandi',
            'exec' => 'password_form',
            'weight' => '0',
            'user_required' => 'users',
        );
        $items['user_password_submit'] = array(
            'title' => __t('user password'),
            'description' => __t('eksekusi perubahan sandi pengguna'),
            'path' => '/setting/sandisubmit',
            'exec' => 'password_form_submit',
            'weight' => '0',
            'user_required' => 'users',
        );
        return $items;
    }

    function __get_staf_options($field){
        $result = array();
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('stafs'),
            NULL,
            'nama'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            $result[$query->fields['id']] = $query->fields[$field];
            $query->MoveNext();
        }
        return $result;
    }

    function password_form_submit(){
        $dump = $this->__write_form_cache();
        $thevalue = array();
        foreach($dump as $key => $value){
            if($key == 'sandi0'){
                $thevalue[$key] = $value;
            }
            if($value == ''){
                if(!isset($blank)){$blank = array($key);}
                elseif(!in_array($key, $blank)){$blank[] = $key;}
            }
        }
        if(isset($blank)){
            $this->__write_custom_cache(array("###blank###" => implode('|', $blank)), 1);
            $this->__write_custom_cache(array("error" => __t('Mohon diisi semua')), 1);
        }
        $userinfo = $this->__get_user_info();
        $salt = substr($userinfo[$this->config->auth_use_table[2]], 0, $this->config->salt[0]);
        $passwd = substr_replace(sha1($_POST[$this->config->auth_use_table[2] . '0']), $salt, 0, $this->config->salt[1]);
        if($passwd == $userinfo[$this->config->auth_use_table[2]]){
            if($_POST['sandi1'] != $_POST['sandi2']){
                $strerror['error'] = __t("New password doesn't match");
                $this->__write_custom_cache($strerror, 1);
                redirect_to('/user/sandi');
            } else {
                $newpassword = substr_replace(sha1($_POST[$this->config->auth_use_table[2] . '1']), $salt, 0, $this->config->salt[1]);
                $this->sysquery->connect();
                $sql = $this->sysquery->updateData(
                    $this->config->auth_use_table[0],
                    array(
                        $this->config->auth_use_table[2] => $newpassword
                    ),
                    array(
                        array('&&', $this->config->auth_use_table[4] . "=" . $_COOKIE[$this->config->cookieid])
                    )
                );
                $this->sysquery->conn->Execute($sql); unset($sql);
                $this->sysquery->close();
                redirect_to('/');
            }
        } else {
            redirect_to('/logout');
        }
    }

    function password_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        } else {
            $vcache = $this->__get_user_info();
        }
        $form['user'] = array(
            '#type' => 'fieldset',
            '#id' => 'user',
            '#title' => __t("user's password"),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/user/sandisubmit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $form['user']['sandi0'] = array(
            '#type' => 'password',
            '#title' => __t('sandi lama'),
            '#value' => isset($vcache['error']) || isset($vcache['blank']) ? $vcache[$this->config->auth_use_table[2] . '0'] : '',
            '#error' => isset($vcache['blank']) && in_array('sandi0', $vcache['blank']) ? 1 : 0
        );
        $form['user']['sandi1'] = array(
            '#type' => 'password',
            '#title' => __t('sandi baru'),
            '#error' => isset($vcache['blank']) && in_array('sandi1', $vcache['blank']) ? 1 : 0
        );
        $form['user']['sandi2'] = array(
            '#type' => 'password',
            '#title' => __t('sandi konfirmasi'),
            '#error' => isset($vcache['blank']) && in_array('sandi2', $vcache['blank']) ? 1 : 0
        );
        $form['user']['submit'] = array(
            '#type' => 'submit',
            '#value' => __t('update'),
            '#title' => '&nbsp;'
        );
        return $form;
    }

    function seting_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        } else {
            $vcache = $this->__get_user_info();
        }
        $form['user'] = array(
            '#type' => 'fieldset',
            '#id' => 'user',
            '#title' => __t('user settings'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/setting/edit_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        foreach($this->users_fields as $value){
            if(!in_array($value, $this->hidden_fields)){
                $form['user'][$value] = array(
                    '#type' => $this->formtype_fields[$value],
                    '#title' => __t($value),
                    '#value' => $vcache[$value],
                    '#error' => isset($vcache['blank']) && in_array($value, $vcache['blank']) ? 1 : 0
                );
                if($form['user'][$value]['#type'] == 'select'){
                    if($value == 'groups'){
                        $form['user'][$value]['#option'] = $this->__get_group_options('name');
                    } elseif($value == 'theme'){
                        $form['user'][$value]['#option'] = $this->__get_theme_options();
                    } elseif($value == 'bahasa'){
                        $form['user'][$value]['#option'] = $this->__get_bahasa_options();
                    }
                }
            } elseif($value == $this->config->auth_use_table[2]){
                $form['user'][$value] = array(
                    '#type' => 'info',
                    '#title' => __t($value),
                    '#value' => '<a href="/setting/sandi">' . __t('change password') . '</a>'
                );
            }
        }
        $form['user']['submit'] = array(
            '#type' => 'submit',
            '#title' => '&nbsp;',
            '#value' => __t('update')
        );
        return $form;
    }

    function form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['user'] = array(
            '#type' => 'fieldset',
            '#id' => 'user',
            '#title' => __t('add user'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/admin/user/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->sysquery->connect();
        $sql = $this->sysquery->getDescribe($this->config->auth_use_table[0]);
        $query = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], $this->system_auto_insert_in_fields)){
                $form['user'][$query->fields['Field']] = array(
                    '#type' => $this->formtype_fields[$query->fields['Field']],
                    '#title' => __t($query->fields['Field'] == 'id' ? 'staf' : $query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
                if($form['user'][$query->fields['Field']]['#type'] == 'select'){
                    if($query->fields['Field'] == 'groups'){
                        $form['user'][$query->fields['Field']]['#option'] = $this->__get_group_options('name');
                    } elseif($query->fields['Field'] == 'theme'){
                        $form['user'][$query->fields['Field']]['#option'] = $this->__get_theme_options();
                    } elseif($query->fields['Field'] == 'bahasa'){
                        $form['user'][$query->fields['Field']]['#option'] = $this->__get_bahasa_options();
                    } elseif($query->fields['Field'] == 'id'){
//                    echo '<pre>'; print_r($this->conf->auth_use_table); echo '</pre>';
                        $dump = $this->__get_staf_options('nama');
                        $arrayopts = array();
                        $this->sysquery->connect();
                        $sql = $this->sysquery->getSelect(
                            array($this->config->auth_use_table[4]),
                            array($this->config->auth_use_table[0])
                        );
                        $opts = $this->sysquery->conn->Execute($sql); unset($sql);
                        $this->sysquery->close();
                        for($u=0; $u<$opts->_numOfRows; $u++){
                            $arrayopts[] = $opts->fields[$this->config->auth_use_table[4]];
                            $opts->MoveNext();
                        } unset($opts);
                        foreach($dump as $key => $value){
                            if (in_array($key, $arrayopts)){unset($dump[$key]);}
                        } unset($arrayopts);
                        $form['user'][$query->fields['Field']]['#option'] = $dump;
                        unset($dump);
                    }
                    $form['user'][$query->fields['Field']]['#option_blank'] = 0;
                }
            }
            $query->MoveNext();
        } unset($query);
        $form['user']['submit'] = array(
            '#type' => 'submit',
            '#title' => '&nbsp;',
            '#value' => __t('input')
        );
//        echo '<pre>'; print_r($form); echo '</pre>'; exit();
        return $form;
    }

    function seting_form_submit(){
        $dump = $this->__write_form_cache();
        foreach($dump as $key => $value){
            if($value == ''){
                $this->__write_custom_cache(
                    array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                );
                redirect_to('/setting/edit');
                exit();
            }
            if($key != 'blank' && $key != 'submit'){
                $thevalue[$key] = $value;
            }
        } unset($dump);
        $this->sysquery->connect();
        $sql = $this->sysquery->saveData(
            $this->config->auth_use_table[0],
            $thevalue,
            array(
                array('&&', $this->config->auth_use_table[4] . "=" . $_COOKIE[$this->config->cookieid])
            )
        );
        $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        unset($thevalue);
        redirect_to('/setting');
    }

    function form_submit(){
        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/admin/user/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $this->query->connect();
            $sql = $this->query->getSelect(
                array($this->config->auth_use_table[2]),
                array('stafs'),
                array(
                    array('&&', $this->config->auth_use_table[4] . "=" . $_POST['id'])
                )
            );
//            $this->query->conn->debug=true;
            $query = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            $thevalue[$this->config->auth_use_table[2]] = $query->fields[$this->config->auth_use_table[2]];
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->sysquery->connect();
            $sql = $this->sysquery->saveData(
                $this->config->auth_use_table[0],
                $thevalue
            );
            $this->sysquery->conn->Execute($sql); unset($sql);
            $this->sysquery->close();
            unset($thevalue);
            redirect_to('/admin/user');
        } else {
            redirect_to('/admin/user/form');
        }
    }

    function delete(){
        if($_POST['id'] != '0' && $_POST['id'] != $_COOKIE[$this->config->cookieid]){
            $this->sysquery->connect();
            $sql = $this->sysquery->setDelete(
                $this->config->auth_use_table[0],
                array(
                    array('&&', $this->config->auth_use_table[4] . "=" . $_POST['id'])
                )
            );
            $this->sysquery->conn->Execute($sql); unset($sql);
            $this->sysquery->close();
        }
        redirect_to('/admin/user');
    }

    function edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->users_fields)){
                    $sql = $this->sysquery->updateData(
                        $this->config->auth_use_table[0],
                        array(
                            $key => $value
                        ),
                        array(
                            array('&&', $this->config->auth_use_table[4] . "=" . $_POST['id'])
                        )
                    );
                    $this->sysquery->connect();
                    $this->sysquery->conn->Execute($sql); unset($sql);
                    $this->sysquery->close();
                } elseif(in_array($key, $this->stafs_fields)){
                    if(eregi('tgl', $key)){
                        if(is_array($value)){
                            ksort($value);
                            $value = implode('-', $value);
                        }
                    }
                    $sql = $this->query->updateData(
                        'stafs',
                        array(
                            $key => $value
                        ),
                        array(
                            array('&&', $this->config->auth_use_table[4] . "=" . $_POST['id'])
                        )
                    );
                    $this->query->connect();
                    $this->query->conn->Execute($sql); unset($sql);
                    $this->query->close();
                } else {
                    if($key == 'group_access'){
                        $this->sysquery->connect();
                        $sql = $this->sysquery->getSelect(
                            array(),
                            array('groups'),
                            NULL,
                            'id'
                        );
                        $query = $this->sysquery->conn->Execute($sql); unset($sql);
                        $this->sysquery->close();
                        if($query->_numOfRows > 0){
                            for($i=0; $i<$query->_numOfRows; $i++){
                                $useradd = array();
                                if(!is_null($query->fields['useradd']) && $query->fields['useradd'] != ''){
                                    $useradd = explode(',', $query->fields['useradd']);
                                }
                                if(in_array($query->fields['id'], $value)){
                                    if(!in_array($_POST['id'], $useradd)){
                                        $useradd[] = $_POST['id'];
                                    }
                                } else {
                                    if(in_array($_POST['id'], $useradd)){
                                        $getkey = array_search($_POST['id'], $useradd);
                                        unset($useradd[$getkey], $getkey);
                                    }
                                }
                                if(count($useradd) > 0){
                                    $useradd = implode(',', $useradd);
                                } else {
                                    $useradd = NULL;
                                }
                                $this->sysquery->connect();
                                $sql = $this->sysquery->updateData(
                                    'groups',
                                    array('useradd' => $useradd),
                                    array(
                                        array('&&', "id=" . $query->fields['id'])
                                    )
                                );
                                $this->sysquery->conn->Execute($sql); unset($sql);
                                $this->sysquery->close();
                                unset($useradd);
                                $query->MoveNext();
                            }
                        }
                    }
                }
            }
        }
        redirect_to('/admin/user/detail/' . $_POST['id']);
    }

    function detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil pengguna');
        $result['description'] = __t('informasi detil pengguna terdaftar yang terpilih');
        $result['id'] = $keyid;
        $result['dropable'] = $keyid != 0 && $keyid != $_COOKIE[$this->config->cookieid] ? '/admin/user/drop' : '0';
        $this->sysquery->connect();
        $sql = $this->sysquery->getSelect(
            array(),
            array($this->config->auth_use_table[0]),
            array(
                array('&&', $this->config->auth_use_table[4] . "=" . $keyid)
            )
        );
        $query = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        if(isset($update)){
            $showsubmit = array('textarea', 'date');
        }
        foreach($query->fields as $key => $value){
            if($key == 'groups' || $key == 'theme' || $key == 'bahasa'){
                $options = array();
                if($key == 'groups'){
                    $options = $this->__get_group_options('name');
                } elseif($key == 'theme'){
                    $options = $this->__get_theme_options();
                } elseif($key == 'bahasa'){
                    $options = $this->__get_bahasa_options();
                }
            }
            $result['data'][$key] = array(
                'key' => __t($key),
                'value' => $key == 'groups' || $key == 'theme' || $key == 'bahasa' ? $options[$value] : $value,
                'link' => '/admin/user/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->hidefields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/admin/user/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => $this->formtype_fields[$key],
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->formtype_fields[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->formtype_fields[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        )
                    )
                );
                if($result['data'][$key]['form']['detail'][$key]['#type'] == 'select'){
//                    if($key == 'groups' || $key == 'theme' || $key == 'bahasa'){
                        $result['data'][$key]['form']['detail'][$key]['#option'] = $options;
//                    }
                }
                if(in_array($result['data'][$key]['form']['detail'][$key]['#type'], $showsubmit)){
                    $result['data'][$key]['form']['detail'][$key]['submit'] = array(
                        '#type' => 'submit',
                        '#value' => 'submit',
                        '#title' => 'hidden'
                    );
                }
            } unset($options);
        } unset($query);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('stafs'),
            array(
                array('&&', "id=" . $keyid)
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        foreach($query->fields as $key => $value){
            if($key == 'kelamin' || $key == 'agama' || eregi('tgl', $key)){
                $options = array();
                if($key == 'kelamin'){
                    $options = $this->__get_kelamin_options();
                } elseif($key == 'agama'){
                    $options = $this->__get_agama_options();
                } elseif(eregi('tgl', $key)){
                    $options = $this->nama_bulan;
                    if(!isset($update) || $key != $update){
                        $value = !is_null($value) ? $value : '1970-01-01';
//                        echo $value;
                        $value = explode('-', $value);
                        krsort($value);
                        $value[1] = $options[(int)$value[1]];
                        $value = implode(' ', $value);
                    }
                }
            }
            $result['data'][$key] = array(
                'key' => __t($key),
                'value' => $key == 'kelamin' || $key == 'agama' ? $options[$value] : $value,
                'link' => '/admin/user/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->hidefields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/admin/user/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => $this->formtype_fields[$key],
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->formtype_fields[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->formtype_fields[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        ),
                    )
                );
                if($result['data'][$key]['form']['detail'][$key]['#type'] == 'select' || $result['data'][$key]['form']['detail'][$key]['#type'] == 'date'){
//                    if ($key == 'kelamin' || $key == 'agama' || eregi('tgl', $key)){
                        $result['data'][$key]['form']['detail'][$key]['#option'] = $options;
//                    }
                }
                if(in_array($result['data'][$key]['form']['detail'][$key]['#type'], $showsubmit)){
//                    echo 'here';
                    $result['data'][$key]['form']['detail']['submit'] = array(
                        '#type' => 'submit',
                        '#value' => 'submit',
                        '#title' => '&nbsp;'
                    );
                }
            } unset($options);
        } unset($query);
        
        $this->sysquery->connect();
        $sql = $this->sysquery->getSelect(
            array(),
            array('groups'),
            NULL,
            'name'
        );
        $query = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        $useradd = array();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                if($this->__check_group_access($query->fields['id'], $keyid) !== FALSE){
                    $useradd[] = $query->fields['id'];
                }
                $query->MoveNext();
            }
        } unset($query);
        if($keyid > 0){
            $vuseradd = array();
            foreach($useradd as $key=>$value){
                $this->sysquery->connect();
                $sql = $this->sysquery->getSelect(
                    array('name'),
                    array('groups'),
                    array(
                        array('&&', "id=" . $value)
                    )
                );
                $query = $this->sysquery->conn->Execute($sql); unset($sql);
                $this->sysquery->connect();
                if($query->_numOfRows > 0){
                    $vuseradd[] = $query->fields['name'];
                } unset($query);
            }
            $result['data']['group_access'] = array(
                'key' => __t('akses ke group'),
                'value' => count($vuseradd) > 0 ? implode(', ', $vuseradd) : __t('None'),
                'link' => '/admin/user/detail/' . $keyid . '/group_access',
                'hide' => 0
            ); unset($vuseradd);
            if (isset($update) && $update == 'group_access'){
                $options = $this->__get_group_lists();
                $result['data']['group_access']['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/admin/user/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        'group_access' => array(
                            '#type' => 'checkbox',
                            '#value' => $useradd,
                            '#title' => 'hidden',
                            '#option' => $options
                        ),
                        'submit' => array(
                            '#type' => 'submit',
                            '#value' => 'submit',
                            '#title' => '&nbsp;',
                        )
                    )
                ); unset($options);
            }
        }
        unset($useradd, $keyid);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('daftar pengguna');
        $result['description'] = __t('pengguna yang terdaftar sebagai operator dan administrator system ini');
        $result['addmenu'] = array(
            'title' => __t('add user'),
            'action' => '/admin/user/form',
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
                'field' => 'userid',
                'caption' => __t('User-ID'),
                'width' => '15%',
                'align' => 'center'
            ),
            array(
                'field' => 'nama',
                'caption' => __t('name'),
                'align' => 'left'
            ),
            array(
                'field' =>'groups',
                'caption' => __t('groups'),
                'width' => '15%',
                'align' => 'center'
            )
        );
        $this->sysquery->connect();
        $sql = $this->sysquery->getSelect(
            array(),
            array($this->config->auth_use_table[0])
        );
        $query = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            $this->query->connect();
            $sql = $this->query->getSelect(
                array('nama'),
                array('stafs'),
                array(
                    array('&&', "id=" . $query->fields[$this->config->auth_use_table[4]])
                )
            );
            $getquery = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            if($getquery->_numOfRows > 0){
                $this->sysquery->connect();
                $sql = $this->sysquery->getSelect(
                    array('name'),
                    array('groups'),
                    array(
                        array('&&', "id=" . $query->fields['groups'])
                    )
                );
                $getgroups = $this->sysquery->conn->Execute($sql); unset($sql);
                $this->sysquery->close();
                $query->fields['groups'] = $getgroups->fields['name'];
                unset($getgroups);
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['nama'] = ucwords($getquery->fields['nama']);
                $result['data'][$i]['goto'] = '/admin/user/detail/' . $query->fields['id'];
            } unset($getquery);
            $query->MoveNext();
        } unset($query);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

}