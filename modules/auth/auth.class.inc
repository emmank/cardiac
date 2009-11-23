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
 *  auth.module
 *
 *  Created on Sep 6, 2009, 11:03:48 AM
 */

require_once MODULES_DIR . DS . 'auth' . DS . 'config.inc';

class authModule extends mainModule
{
    var $title = 'auth';
    var $description = '';
    var $query;

    function menu(){
        $items['login'] = array(
            'title' => __t('login'),
            'description' => __t('View login form to access authenticated menu'),
            'path' => '/login',
            'exec' => 'login_form',
            'weight' => '-10',
            'user_required' => NULL
        );
        $items['logout'] = array(
            'title' => __t('logout'),
            'description' => __t('Logout and redirected to home'),
            'path' => '/logout',
            'exec' => 'logout',
            'weight' => '50',
            'user_required' => 'users'
        );
        $items['login_submit'] = array(
            'title' => __t('login_submit'),
            'path' => '/loginsubmit',
            'exec' => 'login_submit',
            'weight' => '50',
            'user_required' => NULL
        );
        $items['rewrite_registry'] = array(
            'title' => __t('rewrite_registry'),
            'path' => '/regload',
            'exec' => 'regload',
            'weight' => '50',
            'user_required' => NULL
        );
        return $items;
    }

    function get_user_vars(){
        $result = array();
        if(isset($_COOKIE[$this->config->cookieid])){
            $this->__check_user_validate($_COOKIE[$this->config->cookieid]);
            $this->__check_session($_COOKIE[$this->config->cookiesession]);
            if(!is_null($this->config->use_time_limit) && $this->config->use_time_limit != '' && $this->config->use_time_limit != '0'){
                $this->__check_time_session();
                $this->__set_time_session($_COOKIE[$this->config->cookieid], 1);
            }
            $result = $this->__get_vars($_COOKIE[$this->config->cookieid]);
        }
        return $result;
    }

    function __check_user_validate($uid){
        $this->sysquery->connect();
        $sql = $this->sysquery->getSelect(
            array(),
            array($this->config->auth_use_table[0]),
            array(
                array('&&', $this->config->auth_use_table[4] . "=" . $uid)
            )
        );
        $query = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        if($query->_numOfRows < 1){
            $this->logout();
        }
    }

    function __check_session($session){
        $uservar = $this->__get_vars($_COOKIE[$this->config->cookieid]);
        if($uservar[$this->config->auth_use_table[3]] != $session){
            $this->logout();
        }
    }

    function __check_time_session(){
        $uservar = $this->__get_vars($_COOKIE[$this->config->cookieid]);
        if(($this->config->time - strtotime($uservar[$this->config->use_time_limit])) > $this->config->timelog_idle){
            $this->logout();
        }
    }

    function __set_time_session($uid, $go=NULL){
        $this->sysquery->connect();
        $sql = $this->sysquery->updateData(
            $this->config->auth_use_table[0],
            array(
                $this->config->auth_use_table[3] => isset($go) && !is_null($go) ? $_COOKIE[$this->config->cookiesession] : NULL,
                $this->config->use_time_limit => isset($go) && !is_null($go) ? date('Y-m-d H:i:s', $this->config->time) : NULL
            ),
            array(
                array('&&', $this->config->auth_use_table[4] . "=" . $uid)
            )
        );
//        $this->sysquery->debug=true;
        $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
    }

    function __get_vars($userid){
        $result = array();
        $this->sysquery->connect();
        $sql = $this->sysquery->getSelect(
            array(),
            array($this->config->auth_use_table[0]),
            array(
                array('&&', $this->config->auth_use_table[4] . "=" . $userid)
            )
        );
        $query = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        foreach($query->fields as $key=>$value){
            if($key == 'groups'){
                $this->sysquery->connect();
                $sql = $this->sysquery->getSelect(
                    array('name'),
                    array('groups'),
                    array(
                        array('&&', "id=" . $value)
                    )
                );
                $groups = $this->sysquery->conn->Execute($sql); unset($sql);
                $this->sysquery->connect();
                $value = $groups->fields['name']; unset($groups);
            }
            $result[$key] = $value;
        } unset($query);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('stafs'),
            array(
                array('&&', "id=" . $userid)
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        foreach($query->fields as $key=>$value){
            $result[$key] = $value;
        } unset($query);
        return $result;
    }

    function login_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
        $form['login'] = array(
            '#type' => 'fieldset',
            '#id' => 'login',
            '#title' => 'hidden',
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/loginsubmit',
            '#message' => array(
                __t('Selamat datang di Cardiac Center'),
                __t('Silahkan login sebelum menggunakan aplikasi ini')
            ),
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $form['login']['userid'] = array(
            '#type' => 'text',
            '#title' => __t('username'),
            '#size' => 20,
            '#value' => isset($vcache['userid']) ? $vcache['userid'] : '',
            '#error' => isset($vcache['blank']) && in_array('userid', $vcache['blank']) ? 1 : 0
        );
        $form['login']['sandi'] = array(
            '#type' => 'password',
            '#title' => __t('password'),
            '#size' => 20,
            '#error' => isset($vcache['blank']) && in_array('userid', $vcache['blank']) ? 1 : 0
        );
        $form['login']['submit'] = array(
//            '#title' => '&nbsp;',
            '#type' => 'submit',
            '#value' => __t('login'),
            '#extra' => ' class="button"'
        );
        return $form;
    }

    function login_submit(){
        $this->__write_form_cache();
//        echo '<pre>'; print_r($_POST); echo '</pre>'; exit();
        $this->sysquery->connect();
        $sql = $this->sysquery->getSelect(
            array(),
            array($this->config->auth_use_table[0]),
            array(
                array('&&', $this->config->auth_use_table[1] . "=" . $_POST[$this->config->auth_use_table[1]])
            )
        );
        $getdata = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
//        echo '<pre>'; print_r($getdata); echo '</pre>'; exit();
        if($getdata->_numOfRows > 0){
            $salt = substr($getdata->fields[$this->config->auth_use_table[2]], 0, $this->config->salt[0]);
            $passwd = substr_replace(sha1($_POST[$this->config->auth_use_table[2]]), $salt, 0, $this->config->salt[1]);
//            echo $salt . '<br />' . $passwd . '<br />' . $getdata->fields[$this->config->auth_use_table[2]]; exit();
            if($passwd == $getdata->fields[$this->config->auth_use_table[2]]){
                $this->sysquery->connect();
                $sql = $this->sysquery->updateData(
                    $this->config->auth_use_table[0],
                    array(
                        $this->config->auth_use_table[2] => $passwd,
                        $this->config->auth_use_table[3] => $_COOKIE[$this->config->cookiesession],
                        $this->config->use_time_limit => date('Y-m-d H:i:s', $this->config->time)
                    ),
                    array(
                        array('&&', $this->config->auth_use_table[4] . "=" . $getdata->fields[$this->config->auth_use_table[4]])
                    )
                );
                $this->sysquery->conn->Execute($sql); unset($sql);
                unset($getdata);
                $sql = $this->sysquery->getSelect(
                    array(),
                    array($this->config->auth_use_table[0]),
                    array(
                        array('&&', $this->config->auth_use_table[1] . "=" . $_POST[$this->config->auth_use_table[1]])
                    )
                );
                $getdata = $this->sysquery->conn->Execute($sql); unset($sql);
                $this->sysquery->close();
                setcookie($this->config->cookieid, $getdata->fields[$this->config->auth_use_table[4]]);
                unset($getdata);
                $sql = $this->sysquery->setDelete(
                    'registry',
                    array(
                        array('&&', "id=" . $_COOKIE[$this->config->cookiesession])
                    )
                );
                $this->sysquery->connect();
                $this->sysquery->conn->Execute($sql); unset($sql);
                $this->sysquery->close();
//                echo '<pre>'; print_r($user); echo '</pre>'; exit();
//                __write_registry();
                redirect_to('/');
            } else {
                $strvar = array("error" => __t("Your passcode doesn't match !"));
                $this->__write_custom_cache($strvar, 1);
                redirect_to('/login');
            }
        } else {
            $strvar = array("error" => __t('No data available, you unauthorized !'));
            $this->__write_custom_cache($strvar, 1);
            redirect_to('/login');
        }
    }

    function __flush_registry(){
        $sql = $this->sysquery->setDelete(
            'registry',
            array(
                array('&&', "id=" . $_COOKIE[$this->config->cookiesession])
            )
        );
        $this->sysquery->connect();
        $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
    }

    function logout(){
        $this->__flush_registry();
        setcookie($this->config->cookieid,"");
        if(!is_null($this->config->use_time_limit) && $this->config->use_time_limit != '' && $this->config->use_time_limit != '0'){
            $this->__set_time_session($_COOKIE[$this->config->cookieid]);
        }
        session_destroy();
        redirect_to('/regload');
    }

    function regload(){
        __write_registry();
    }

}