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
 *  dictionaryclass.php
 *  
 *  Created on Dec 19, 2009, 8:52:54 PM
 */

require_once MODULES_DIR . DS . 'dictionary' . DS . 'config.inc';

class dictionaryModule extends mainModule
{
    var $title = 'dictionary';

    function menu(){
        $items['dictionary_view'] = array(
            'title' => __t('dictionary'),
            'description' => __t('daftar bahasa yang tersedia'),
            'path' => '/admin/dictionary',
            'exec' => 'view',
            'weight' => '0',
            'user_required' => 'admin'
        );
        $items['dictionary_lang'] = array(
            'title' => __t('language form'),
            'description' => __t('form to manipulate language'),
            'path' => '/admin/dictionary/language',
            'exec' => 'lang_form',
            'weight' => '0',
            'user_required' => 'admin'
        );
        $items['dictionary_detail'] = array(
            'title' => __t('language detail'),
            'description' => __t('detail information of language translation'),
            'path' => '/admin/dictionary/detail',
            'exec' => 'lang_detail',
            'weight' => '0',
            'user_required' => 'admin'
        );
        $items['dictionary_newwords'] = array(
            'title' => __t('translate new'),
            'description' => __t('Translate new words into default language'),
            'path' => '/admin/dictionary/newwords',
            'exec' => 'translatenew',
            'weight' => '0',
            'user_required' => 'admin'
        );
        $items['dictionary_newwords_form'] = array(
            'title' => __t('translate new'),
            'description' => __t('Translate new words into default language'),
            'path' => '/admin/dictionary/newwords_form',
            'exec' => 'translatenew_form',
            'weight' => '0',
            'user_required' => 'admin'
        );
        $items['dictionary_newwords_submit'] = array(
            'title' => __t('translate new'),
            'description' => __t('Translate new words into default language'),
            'path' => '/admin/dictionary/new_submit',
            'exec' => 'new_submit',
            'weight' => '0',
            'user_required' => 'admin'
        );
        $items['dictionary_translate'] = array(
            'title' => __t('translate'),
            'description' => __t('Translate word into certain language'),
            'path' => '/admin/dictionary/translate',
            'exec' => 'translate_form',
            'weight' => '0',
            'user_required' => 'admin'
        );
        $items['dictionary_translate_submit'] = array(
            'title' => __t('translate'),
            'description' => __t('Translate word into certain language'),
            'path' => '/admin/dictionary/translate_submit',
            'exec' => 'translate_form_submit',
            'weight' => '0',
            'user_required' => 'admin'
        );
        $items['dictionary_cleardump'] = array(
            'title' => __t('clear dump'),
            'description' => __t('clear all dumped words that not translated yet'),
            'path' => '/admin/dictionary/cleardump',
            'exec' => 'clear_dump',
            'weight' => '0',
            'user_required' => 'admin'
        );
        return $items;
    }

    function clear_dump(){
        $sql = $this->sysquery->setDelete('dumptr');
        $this->sysquery->connect();
        $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        redirect_to('/admin/dictionary/newwords');
    }

    function new_submit(){
        $dump = $this->__write_form_cache();
        foreach($dump as $key => $value){
            if($key != 'submit' && $key != 'page'){
                if(trim($value) != ''){
                    $thevalue[$key] = $value;
                }
            }
        }
        if(isset($thevalue)){
            $sql = $this->sysquery->saveData(
                    'translations',
                    $thevalue
            );
            $this->sysquery->connect();
            $this->sysquery->conn->Execute($sql); unset($sql);
            $this->sysquery->close();
            unset($thevalue);
            $sql = $this->sysquery->setDelete(
                    'dumptr',
                    array(
                        array('&&', "id=" . $dump['strkey'])
                    )
            );
            $this->sysquery->connect();
            $this->sysquery->conn->Execute($sql); unset($sql);
            $this->sysquery->close();
        }
        $this->__flush_caches();
        redirect_to('/admin/dictionary/newwords/' . $dump['page']);
    }

    function translatenew_form(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(isset($dump[3])){
            $page = trim($dump[3]);
            if(isset($dump[4])){
                $strkey = eregi_replace('-_dan_-', '&', urldecode($dump[4]));
                $vcache['strkey'] = trim($strkey);
                unset($strkey);
            } else {
                redirect_to('/admin/dictionary/newwords/' . $page); exit();
            }
        } else {
            redirect_to('/admin/dictionary'); exit();
        } unset($dump);
        $themessage = '<font style="font-weight:bold">' . $vcache['strkey'] . '</font>' . "\n";
        $form['translate'] = array(
            '#type' => 'fieldset',
            '#id' => 'translate',
            '#title' => __t('translate') . ' ' . __t('in') . ' ' . __t($this->config->default_lang),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => $this->config->default_lang,
            '#weight' => 0,
            '#action' => '/admin/dictionary/new_submit',
            '#message' => $themessage,
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $form['translate']['strkey'] = array(
            '#type' => 'hidden',
            '#value' => $vcache['strkey']
        );
        $form['translate']['page'] = array(
            '#type' => 'hidden',
            '#value' => $page
        );
        $form['translate'][$this->config->default_lang] = array(
            '#type' => 'textarea',
            '#title' => __t('translate'),
            '#cols' => 40,
            '#rows' => 3,
            '#value' => $vcache[$this->config->default_lang]
        );
        $form['translate']['submit'] = array(
            '#type' => 'submit',
            '#title' => ' &nbsp;',
            '#value' => __t('submit'),
            '#extra' => 'class="button"'
        );
        return $form;
    }
    function translatenew(){
        $result['type'] = 'table';
        $result['title'] = __t('translations');
        $result['description'] = __t('words that translated in') . ' ' . __t($this->config->default_lang);
        $result['addmenu'] = array(
            'title' => __t('clear'),
            'action' => '/admin/dictionary/cleardump',
            'position' => 'top'
        );
        $pageamount = $this->__get_page_amount('dumptr');
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(isset($dump[3])){
            $pg = trim($dump[3]);
        } else {
            $pg = 1;
        }
        unset($dump);
        $themessage = __t('page') . ':<br />' . "\n";
        for($i=0; $i<$pageamount; $i++){
            if($i > 0){
                $themessage .= ', ';
            }
            if(($i+1) == $pg){
                $themessage .= '<font size="+2" style="font-weight:bold">';
            } else {
                $themessage .= '<a href="/admin/dictionary/newwords/' . ($i+1) . '">';
            }
            $themessage .= $i+1;
            if(($i+1) == $pg){
                $themessage .= '</font>';
            } else {
                $themessage .= '</a>';
            }
        }
        if($pageamount > 1){
            $result['addmessage'] = array(
                array(
                    'position' => 'top',
                    'message' => $themessage
                ),
                array(
                    'position' => 'bottom',
                    'message' => $themessage
                )
            );
        } unset($themessage);
        $result['header'] = array(
            array(
                'field' => 'id',
                'caption' => __t('words'),
                'width' => '30%',
                'align' => 'left'
            )
        );
        $limit = isset($pg) ? ($pg - 1) * $this->config->rows_of_shows : 0;
        $sql = $this->sysquery->getSelect(
                array(),
                array('dumptr'),
                NULL,
                NULL,
                $limit . ',' . $this->config->rows_of_shows
        );
//        echo $sql . '<br />';
        $this->sysquery->connect();
        $getit = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        if($getit->_numOfRows > 0){
            for($i=0; $i<$getit->_numOfRows; $i++){
                $strkey = eregi_replace('&', '-_dan_-', $getit->fields['id']);
                $result['data'][$i] = $getit->fields;
                $result['data'][$i]['goto'] = '/admin/dictionary/newwords_form/' . $pg . '/' . urlencode($strkey);
                unset($strkey);
                $getit->MoveNext();
            }
        }
        return $result;
    }

    function translate_form_submit(){
        $dump = $this->__write_form_cache();
        foreach($dump as $key => $value){
            if($key != 'submit' && $key != 'strkey' && $key != 'lang' && $key != 'page'){
                if(trim($value) != ''){
                    $thevalue[$key] = $value;
                }
            }
        }
        if(isset($thevalue)){
            $sql = $this->sysquery->updateData(
                    'translations',
                    $thevalue,
                    array(
                        array('&&', "strkey=" . $dump['strkey'])
                    )
            );
            $this->sysquery->connect();
            $this->sysquery->conn->Execute($sql); unset($sql);
            $this->sysquery->close();
            unset($thevalue);
        }
        $this->__flush_caches();
        redirect_to('/admin/dictionary/detail/' . $dump['lang'] . '/' . $dump['page']);
    }

    function translate_form(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(isset($dump[3])){
            $lang = trim($dump[3]);
            if(isset($dump[4])){
                $page = trim($dump[4]);
                if(isset($dump[5])){
                    $strkey = urldecode(trim($dump[5]));
                } else {
                    redirect_to('/admin/dictionary/detail/' . $lang . '/' . $page); exit();
                }
            } else {
                redirect_to('/admin/dictionary/detail/' . $lang); exit();
            }
        } else {
            redirect_to('/admin/dictionary'); exit();
        } unset($dump);
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        } else {
            $sql = $this->sysquery->getSelect(
                    array('strkey', $this->config->default_lang, $lang),
                    array('translations'),
                    array(
                        array('&&', "strkey=" . $strkey)
                    )
            );
            $this->sysquery->connect();
            $getit = $this->sysquery->conn->Execute($sql); unset($sql);
            $this->sysquery->close();
            if($getit->_numOfRows > 0){
                foreach($getit->fields as $key => $value){
                    $vcache[$key] = $value;
                }
            }
        }
        $themessage = '<font style="font-weight:bold">' . $strkey . '</font><br />' . "\n";
        $themessage .= $vcache[$this->config->default_lang];
        $form['translate'] = array(
            '#type' => 'fieldset',
            '#id' => 'translate',
            '#title' => __t('translate'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => $lang,
            '#weight' => 0,
            '#action' => '/admin/dictionary/translate_submit',
            '#message' => $themessage,
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $form['translate']['strkey'] = array(
            '#type' => 'hidden',
            '#value' => $vcache['strkey']
        );
        $form['translate']['lang'] = array(
            '#type' => 'hidden',
            '#value' => $lang
        );
        $form['translate']['page'] = array(
            '#type' => 'hidden',
            '#value' => $page
        );
        $form['translate'][$lang] = array(
            '#type' => 'textarea',
            '#title' => __t('translate'),
            '#cols' => 40,
            '#rows' => 3,
            '#value' => $vcache[$lang]
        );
        $form['translate']['submit'] = array(
            '#type' => 'submit',
            '#title' => ' &nbsp;',
            '#value' => __t('submit'),
            '#extra' => 'class="button"'
        );
        return $form;
    }

    function __get_amount_data($tablename, $condition=array()){
        $result = 0;
        $sql = $this->sysquery->getSelect(
                array('0'),
                array($tablename),
                count($condition) > 0 ? $condition : NULL
        );
        $this->sysquery->connect();
        $getit = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        $result += $getit->_numOfRows;
        return $result;
    }

    function __get_page_amount($tablename, $condition=array()){
        $result = $this->__get_amount_data(
                $tablename,
                count($condition) > 0 ? $condition : NULL
        );
        $result = ceil($result / $this->config->rows_of_shows);
        return $result;
    }

    function __is_dropable($id){
        $this->sysquery->connect();
        $sql = $this->sysquery->getSelect(
            array('bahasa'),
            array($this->config->auth_use_table[0]),
            array(
                array('&&', "bahasa=" . $id)
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

    function lang_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(isset($dump[3])){
            $lang = trim($dump[3]);
        }
        $result['type'] = 'table';
        $result['title'] = __t('translations') . ' ' . __t('in') . ' ' . __t($lang);
        $result['description'] = __t('words that translated in') . ' ' . __t($lang);
        $result['header'] = array(
            array(
                'field' => 'strkey',
                'caption' => __t('words'),
                'width' => '30%',
                'align' => 'left'
            ),
            array(
                'field' => $lang != $this->config->default_lang ? $this->config->default_lang : 'translate',
                'caption' => $lang != $this->config->default_lang ? __t($this->config->default_lang) : __t('translate'),
                'width' => $lang != $this->config->default_lang ? '30%' : '',
                'align' => 'left'
            ),
        );
        if($lang != $this->config->default_lang){
            $result['header'][] = array(
                'field' => 'translate',
                'caption' => __t('translate'),
                'align' => 'left'
            );
        }
        $pageamount = $this->__get_page_amount('translations');
        if(isset($dump[4])){
            $pg = trim($dump[4]);
        } else {
            $pg = 1;
        }
        unset($dump);
        $themessage = __t('page') . ':<br />' . "\n";
        for($i=0; $i<$pageamount; $i++){
            if($i > 0){
                $themessage .= ', ';
            }
            if(($i+1) == $pg){
                $themessage .= '<font size="+2" style="font-weight:bold">';
            } else {
                $themessage .= '<a href="/admin/dictionary/detail/' . $lang . '/' . ($i+1) . '">';
            }
            $themessage .= $i+1;
            if(($i+1) == $pg){
                $themessage .= '</font>';
            } else {
                $themessage .= '</a>';
            }
        }
        if($pageamount > 1){
            $result['addmessage'] = array(
                array(
                    'position' => 'top',
                    'message' => $themessage
                ),
                array(
                    'position' => 'bottom',
                    'message' => $themessage
                )
            );
        } unset($themessage);
        $limit = isset($pg) ? ($pg - 1) * $this->config->rows_of_shows : 0;
        $sql = $this->sysquery->getSelect(
                array(),
                array('translations'),
                NULL,
                $lang != $this->config->default_lang ? $this->config->default_lang : 'strkey',
                $limit . ',' . $this->config->rows_of_shows
        );
        $this->sysquery->connect();
        $getit = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        if($getit->_numOfRows > 0){
            for($i=0; $i<$getit->_numOfRows; $i++){
                $result['data'][$i] = $getit->fields;
                $result['data'][$i]['translate'] = $getit->fields[$lang];
                $result['data'][$i]['goto'] = '/admin/dictionary/translate/' . $lang . '/' . $pg . '/' . urlencode($getit->fields['strkey']);
                $getit->MoveNext();
            }
        } unset($getit);
        return $result;
    }

    function sync_tr(){
        $sql = $this->sysquery->getSelect(
                array(),
                array('dumptr')
        );
        $this->sysquery->connect();
        $getit = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        if($getit->_numOfRows > 0){
            for($i=0; $i<$getit->_numOfRows; $i++){
                $sql = $this->sysquery->getSelect(
                        array('strkey'),
                        array('translations'),
                        array(
                            array('&&', "strkey=" . $getit->fields['id'])
                        )
                );
                $this->sysquery->connect();
                $getthis = $this->sysquery->conn->Execute($sql); unset($sql);
                $this->sysquery->close();
                if($getthis->_numOfRows > 0){
                    $sql = $this->sysquery->setDelete(
                            'dumptr',
                            array(
                                array('&&', "strkey=" . $getit->fields['id'])
                            )
                    );
                    $this->sysquery->connect();
                    $this->sysquery->conn->Execute($sql); unset($sql);
                    $this->sysquery->close();
                } unset($getthis);
                $getit->MoveNext();
            }
        } unset($getit);
    }

    function view(){
        $list_of_tables = $this->__get_db_table_lists($this->sysquery);
        if(!in_array('translations', $list_of_tables)){
            $this->sync_scheme('translations', $this->sysquery);
        }
        $this->sync_scheme('dumptr', $this->sysquery);
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('daftar bahasa');
        $result['description'] = __t('daftar bahasa yang terdaftar dalam system ini');
//        $result['addmenu']['#add'] = array(
//            'title' => __t('add'),
//            'action' => '/admin/dictionary/language',
//            'position' => 'top'
//        );
//        $this->sync_tr();
        $sql = $this->sysquery->getSelect(
                array('id'),
                array('dumptr')
        );
        $this->sysquery->connect();
        $getit = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        $result['addmenu']['#newwords'] = array(
            'title' => __t('new words') . ' ' . __t('is amount') . ' ' . $getit->_numOfRows,
            'action' => '/admin/dictionary/newwords',
            'position' => 'top',
            'user_required' => 'admin'
        ); unset($getit);
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
            ),
            array(
                'field' => 'words_count',
                'caption' => __t('jumlah kata'),
                'width' => '15%',
                'align' => 'right'
            )
        );
        $thefields = $this->__get_data_fields('translations', $this->sysquery);
        $cnt = 0;
        foreach($thefields as $key => $value){
            if($value != 'strkey'){
                $result['data'][$cnt]['name'] = __t($value);
                $sql = $this->sysquery->getSelect(
                        array($value),
                        array('translations'),
                        array(
                            array('&&', $value . " is not null")
                        )
                );
                $this->sysquery->connect();
                $getit = $this->sysquery->conn->Execute($sql); unset($sql);
                $this->sysquery->close();
                $countit = 0;
                if($getit->_numOfRows > 0){
                    for($i=0; $i<$getit->_numOfRows; $i++){
                        if(trim($getit->fields[$value]) != ''){
                            $countit++;
                        }
                        $getit->MoveNext();
                    }
                } unset($getit);
                $result['data'][$cnt]['words_count'] = number_format($countit, 0, ',', '.');
                unset($countit);
                $result['data'][$cnt]['goto'] = '/admin/dictionary/detail/' . $value;
                $cnt++;
            }
        } unset($thefields);
        return $result;
    }

}