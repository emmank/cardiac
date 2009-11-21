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
 *  paruclass.php
 *  
 *  Created on Oct 4, 2009, 8:43:32 AM
 */

require_once MODULES_DIR . DS . 'paru' . DS . 'config.inc';

class paruModule extends mainModule
{
    var $title = 'paru module';
    var $description = '';

    function menu(){
        $items['ref_paru_fremitus_raba'] = array(
            'title' => __t('fremitus raba'),
            'description' => __t('fremitus_raba reference form for paru'),
            'path' => '/reference/paru_fremitus_raba',
            'exec' => 'ref_fremitus_raba_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_paru_fremitus_raba_detail'] = array(
            'title' => __t('detil fremitus raba'),
            'description' => __t('fremitus_raba reference detail for paru'),
            'path' => '/reference/paru_fremitus_raba/detail',
            'exec' => 'ref_fremitus_raba_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_paru_fremitus_raba_form'] = array(
            'title' => __t('paru_fremitus_raba form'),
            'description' => __t('fremitus_raba reference form for paru'),
            'path' => '/reference/paru_fremitus_raba/form',
            'exec' => 'ref_fremitus_raba_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_fremitus_raba_form_submit'] = array(
            'title' => __t('paru_fremitus_raba form'),
            'description' => __t('Execute fremitus_raba reference form for paru'),
            'path' => '/reference/paru_fremitus_raba/form_submit',
            'exec' => 'ref_fremitus_raba_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_fremitus_raba_edit'] = array(
            'title' => __t('paru_fremitus_raba edit'),
            'description' => __t('Editing fremitus_raba reference form for paru'),
            'path' => '/reference/paru_fremitus_raba/edit',
            'exec' => 'ref_fremitus_raba_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_fremitus_raba_drop'] = array(
            'title' => __t('paru_fremitus_raba drop'),
            'description' => __t('Remove fremitus_raba reference form for paru'),
            'path' => '/reference/paru_fremitus_raba/drop',
            'exec' => 'ref_fremitus_raba_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_kiri'] = array(
            'title' => __t('paru kiri'),
            'description' => __t('kiri reference form for paru'),
            'path' => '/reference/paru_kiri',
            'exec' => 'ref_kiri_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_paru_kiri_detail'] = array(
            'title' => __t('detil paru kiri'),
            'description' => __t('kiri reference detail for paru'),
            'path' => '/reference/paru_kiri/detail',
            'exec' => 'ref_kiri_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_paru_kiri_form'] = array(
            'title' => __t('paru_kiri form'),
            'description' => __t('kiri reference form for paru'),
            'path' => '/reference/paru_kiri/form',
            'exec' => 'ref_kiri_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_kiri_form_submit'] = array(
            'title' => __t('paru_kiri form'),
            'description' => __t('Execute kiri reference form for paru'),
            'path' => '/reference/paru_kiri/form_submit',
            'exec' => 'ref_kiri_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_kiri_edit'] = array(
            'title' => __t('paru_kiri edit'),
            'description' => __t('Editing kiri reference form for paru'),
            'path' => '/reference/paru_kiri/edit',
            'exec' => 'ref_kiri_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_kiri_drop'] = array(
            'title' => __t('paru_kiri drop'),
            'description' => __t('Remove kiri reference form for paru'),
            'path' => '/reference/paru_kiri/drop',
            'exec' => 'ref_kiri_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_kanan'] = array(
            'title' => __t('paru kanan'),
            'description' => __t('kanan reference form for paru'),
            'path' => '/reference/paru_kanan',
            'exec' => 'ref_kanan_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_paru_kanan_detail'] = array(
            'title' => __t('detil paru kanan'),
            'description' => __t('kanan reference detail for paru'),
            'path' => '/reference/paru_kanan/detail',
            'exec' => 'ref_kanan_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_paru_kanan_form'] = array(
            'title' => __t('paru_kanan form'),
            'description' => __t('kanan reference form for paru'),
            'path' => '/reference/paru_kanan/form',
            'exec' => 'ref_kanan_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_kanan_form_submit'] = array(
            'title' => __t('paru_kanan form'),
            'description' => __t('Execute kanan reference form for paru'),
            'path' => '/reference/paru_kanan/form_submit',
            'exec' => 'ref_kanan_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_kanan_edit'] = array(
            'title' => __t('paru_kanan edit'),
            'description' => __t('Editing kanan reference form for paru'),
            'path' => '/reference/paru_kanan/edit',
            'exec' => 'ref_kanan_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_kanan_drop'] = array(
            'title' => __t('paru_kanan drop'),
            'description' => __t('Remove kanan reference form for paru'),
            'path' => '/reference/paru_kanan/drop',
            'exec' => 'ref_kanan_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_belakang_kiri'] = array(
            'title' => __t('paru belakang_kiri'),
            'description' => __t('belakang_kiri reference form for paru'),
            'path' => '/reference/paru_belakang_kiri',
            'exec' => 'ref_belakang_kiri_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_paru_belakang_kiri_detail'] = array(
            'title' => __t('detil paru belakang_kiri'),
            'description' => __t('belakang_kiri reference detail for paru'),
            'path' => '/reference/paru_belakang_kiri/detail',
            'exec' => 'ref_belakang_kiri_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_paru_belakang_kiri_form'] = array(
            'title' => __t('paru_belakang_kiri form'),
            'description' => __t('belakang_kiri reference form for paru'),
            'path' => '/reference/paru_belakang_kiri/form',
            'exec' => 'ref_belakang_kiri_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_belakang_kiri_form_submit'] = array(
            'title' => __t('paru_belakang_kiri form'),
            'description' => __t('Execute belakang_kiri reference form for paru'),
            'path' => '/reference/paru_belakang_kiri/form_submit',
            'exec' => 'ref_belakang_kiri_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_belakang_kiri_edit'] = array(
            'title' => __t('paru_belakang_kiri edit'),
            'description' => __t('Editing belakang_kiri reference form for paru'),
            'path' => '/reference/paru_belakang_kiri/edit',
            'exec' => 'ref_belakang_kiri_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_belakang_kiri_drop'] = array(
            'title' => __t('paru_belakang_kiri drop'),
            'description' => __t('Remove belakang_kiri reference form for paru'),
            'path' => '/reference/paru_belakang_kiri/drop',
            'exec' => 'ref_belakang_kiri_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_belakang_kanan'] = array(
            'title' => __t('paru belakang_kanan'),
            'description' => __t('belakang_kanan reference form for paru'),
            'path' => '/reference/paru_belakang_kanan',
            'exec' => 'ref_belakang_kanan_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_paru_belakang_kanan_detail'] = array(
            'title' => __t('detil paru belakang_kanan'),
            'description' => __t('belakang_kanan reference detail for paru'),
            'path' => '/reference/paru_belakang_kanan/detail',
            'exec' => 'ref_belakang_kanan_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_paru_belakang_kanan_form'] = array(
            'title' => __t('paru_belakang_kanan form'),
            'description' => __t('belakang_kanan reference form for paru'),
            'path' => '/reference/paru_belakang_kanan/form',
            'exec' => 'ref_belakang_kanan_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_belakang_kanan_form_submit'] = array(
            'title' => __t('paru_belakang_kanan form'),
            'description' => __t('Execute belakang_kanan reference form for paru'),
            'path' => '/reference/paru_belakang_kanan/form_submit',
            'exec' => 'ref_belakang_kanan_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_belakang_kanan_edit'] = array(
            'title' => __t('paru_belakang_kanan edit'),
            'description' => __t('Editing belakang_kanan reference form for paru'),
            'path' => '/reference/paru_belakang_kanan/edit',
            'exec' => 'ref_belakang_kanan_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_belakang_kanan_drop'] = array(
            'title' => __t('paru_belakang_kanan drop'),
            'description' => __t('Remove belakang_kanan reference form for paru'),
            'path' => '/reference/paru_belakang_kanan/drop',
            'exec' => 'ref_belakang_kanan_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_hepar'] = array(
            'title' => __t('paru hepar'),
            'description' => __t('hepar reference form for paru'),
            'path' => '/reference/paru_hepar',
            'exec' => 'ref_hepar_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_paru_hepar_detail'] = array(
            'title' => __t('detil paru hepar'),
            'description' => __t('hepar reference detail for paru'),
            'path' => '/reference/paru_hepar/detail',
            'exec' => 'ref_hepar_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_paru_hepar_form'] = array(
            'title' => __t('paru_hepar form'),
            'description' => __t('hepar reference form for paru'),
            'path' => '/reference/paru_hepar/form',
            'exec' => 'ref_hepar_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_hepar_form_submit'] = array(
            'title' => __t('paru_hepar form'),
            'description' => __t('Execute hepar reference form for paru'),
            'path' => '/reference/paru_hepar/form_submit',
            'exec' => 'ref_hepar_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_hepar_edit'] = array(
            'title' => __t('paru_hepar edit'),
            'description' => __t('Editing hepar reference form for paru'),
            'path' => '/reference/paru_hepar/edit',
            'exec' => 'ref_hepar_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_hepar_drop'] = array(
            'title' => __t('paru_hepar drop'),
            'description' => __t('Remove hepar reference form for paru'),
            'path' => '/reference/paru_hepar/drop',
            'exec' => 'ref_hepar_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_bunyi_pernafasan'] = array(
            'title' => __t('paru bunyi_pernafasan'),
            'description' => __t('bunyi_pernafasan reference form for paru'),
            'path' => '/reference/paru_bunyi_pernafasan',
            'exec' => 'ref_bunyi_pernafasan_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_paru_bunyi_pernafasan_detail'] = array(
            'title' => __t('detil paru bunyi_pernafasan'),
            'description' => __t('bunyi_pernafasan reference detail for paru'),
            'path' => '/reference/paru_bunyi_pernafasan/detail',
            'exec' => 'ref_bunyi_pernafasan_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_paru_bunyi_pernafasan_form'] = array(
            'title' => __t('paru_bunyi_pernafasan form'),
            'description' => __t('bunyi_pernafasan reference form for paru'),
            'path' => '/reference/paru_bunyi_pernafasan/form',
            'exec' => 'ref_bunyi_pernafasan_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_bunyi_pernafasan_form_submit'] = array(
            'title' => __t('paru_bunyi_pernafasan form'),
            'description' => __t('Execute bunyi_pernafasan reference form for paru'),
            'path' => '/reference/paru_bunyi_pernafasan/form_submit',
            'exec' => 'ref_bunyi_pernafasan_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_bunyi_pernafasan_edit'] = array(
            'title' => __t('paru_bunyi_pernafasan edit'),
            'description' => __t('Editing bunyi_pernafasan reference form for paru'),
            'path' => '/reference/paru_bunyi_pernafasan/edit',
            'exec' => 'ref_bunyi_pernafasan_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_bunyi_pernafasan_drop'] = array(
            'title' => __t('paru_bunyi_pernafasan drop'),
            'description' => __t('Remove bunyi_pernafasan reference form for paru'),
            'path' => '/reference/paru_bunyi_pernafasan/drop',
            'exec' => 'ref_bunyi_pernafasan_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_bunyi_tambahan'] = array(
            'title' => __t('paru bunyi_tambahan'),
            'description' => __t('bunyi_tambahan reference form for paru'),
            'path' => '/reference/paru_bunyi_tambahan',
            'exec' => 'ref_bunyi_tambahan_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_paru_bunyi_tambahan_detail'] = array(
            'title' => __t('detil paru bunyi_tambahan'),
            'description' => __t('bunyi_tambahan reference detail for paru'),
            'path' => '/reference/paru_bunyi_tambahan/detail',
            'exec' => 'ref_bunyi_tambahan_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_paru_bunyi_tambahan_form'] = array(
            'title' => __t('paru_bunyi_tambahan form'),
            'description' => __t('bunyi_tambahan reference form for paru'),
            'path' => '/reference/paru_bunyi_tambahan/form',
            'exec' => 'ref_bunyi_tambahan_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_bunyi_tambahan_form_submit'] = array(
            'title' => __t('paru_bunyi_tambahan form'),
            'description' => __t('Execute bunyi_tambahan reference form for paru'),
            'path' => '/reference/paru_bunyi_tambahan/form_submit',
            'exec' => 'ref_bunyi_tambahan_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_bunyi_tambahan_edit'] = array(
            'title' => __t('paru_bunyi_tambahan edit'),
            'description' => __t('Editing bunyi_tambahan reference form for paru'),
            'path' => '/reference/paru_bunyi_tambahan/edit',
            'exec' => 'ref_bunyi_tambahan_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_paru_bunyi_tambahan_drop'] = array(
            'title' => __t('paru_bunyi_tambahan drop'),
            'description' => __t('Remove bunyi_tambahan reference form for paru'),
            'path' => '/reference/paru_bunyi_tambahan/drop',
            'exec' => 'ref_bunyi_tambahan_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        return $items;
    }

    function ref_fremitus_raba_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi fremitus raba');
        $result['description'] = __t('Referensi pilihan fremitus raba pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/paru_fremitus_raba/form',
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
                'field' => 'fremitus_raba',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_paru_fremitus_raba'),
            NULL,
            'fremitus_raba'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['fremitus_raba'] = ucwords($query->fields['fremitus_raba']);
                $result['data'][$i]['goto'] = '/reference/paru_fremitus_raba/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_fremitus_raba_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add paru_fremitus_raba'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'fremitus_raba',
            '#weight' => -3,
            '#action' => '/reference/paru_fremitus_raba/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_paru_fremitus_raba');
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

    function ref_fremitus_raba_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/paru_fremitus_raba/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_paru_fremitus_raba', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_paru_fremitus_raba',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/paru_fremitus_raba');
//        } else {
//            redirect_to('/reference/paru_fremitus_raba/form');
//        }
    }

    function ref_fremitus_raba_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'fremitus_raba', 'paru', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi fremitus_raba');
        $result['description'] = __t('informasi detil referensi fremitus_raba yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/paru_fremitus_raba/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'fremitus_raba'),
            array('ref_paru_fremitus_raba'),
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
                'link' => '/reference/paru_fremitus_raba/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/paru_fremitus_raba/edit/',
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

    function ref_fremitus_raba_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_paru_fremitus_raba', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_paru_fremitus_raba',
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
        redirect_to('/reference/paru_fremitus_raba/detail/' . $_POST['id']);
    }

    function ref_fremitus_raba_drop(){
        if($this->__is_dropable($_POST['id'], 'fremitus_raba', 'paru', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_paru_fremitus_raba',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/paru_fremitus_raba');
    }

    function ref_kiri_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi paru kiri');
        $result['description'] = __t('Referensi pilihan paru kiri pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/paru_kiri/form',
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
                'field' => 'kiri',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_paru_kiri'),
            NULL,
            'kiri'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['kiri'] = ucwords($query->fields['kiri']);
                $result['data'][$i]['goto'] = '/reference/paru_kiri/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_kiri_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add paru_kiri'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'kiri',
            '#weight' => -3,
            '#action' => '/reference/paru_kiri/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_paru_kiri');
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

    function ref_kiri_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/paru_kiri/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_paru_kiri', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_paru_kiri',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/paru_kiri');
//        } else {
//            redirect_to('/reference/paru_kiri/form');
//        }
    }

    function ref_kiri_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'kiri', 'paru', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi paru kiri');
        $result['description'] = __t('informasi detil referensi kiri yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/paru_kiri/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'kiri'),
            array('ref_paru_kiri'),
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
                'link' => '/reference/paru_kiri/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/paru_kiri/edit/',
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

    function ref_kiri_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_paru_kiri', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_paru_kiri',
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
        redirect_to('/reference/paru_kiri/detail/' . $_POST['id']);
    }

    function ref_kiri_drop(){
        if($this->__is_dropable($_POST['id'], 'kiri', 'paru', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_paru_kiri',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/paru_kiri');
    }

    function ref_kanan_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi paru kanan');
        $result['description'] = __t('Referensi pilihan paru kanan pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/paru_kanan/form',
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
                'field' => 'kanan',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_paru_kanan'),
            NULL,
            'kanan'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['kanan'] = ucwords($query->fields['kanan']);
                $result['data'][$i]['goto'] = '/reference/paru_kanan/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_kanan_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add paru_kanan'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'kanan',
            '#weight' => -3,
            '#action' => '/reference/paru_kanan/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_paru_kanan');
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

    function ref_kanan_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/paru_kanan/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_paru_kanan', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_paru_kanan',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/paru_kanan');
//        } else {
//            redirect_to('/reference/paru_kanan/form');
//        }
    }

    function ref_kanan_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'kanan', 'paru', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi paru kanan');
        $result['description'] = __t('informasi detil referensi kanan yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/paru_kanan/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'kanan'),
            array('ref_paru_kanan'),
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
                'link' => '/reference/paru_kanan/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/paru_kanan/edit/',
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

    function ref_kanan_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_paru_kanan', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_paru_kanan',
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
        redirect_to('/reference/paru_kanan/detail/' . $_POST['id']);
    }

    function ref_kanan_drop(){
        if($this->__is_dropable($_POST['id'], 'kanan', 'paru', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_paru_kanan',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/paru_kanan');
    }

    function ref_belakang_kiri_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi paru belakang_kiri');
        $result['description'] = __t('Referensi pilihan paru belakang_kiri pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/paru_belakang_kiri/form',
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
                'field' => 'belakang_kiri',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_paru_belakang_kiri'),
            NULL,
            'belakang_kiri'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['belakang_kiri'] = ucwords($query->fields['belakang_kiri']);
                $result['data'][$i]['goto'] = '/reference/paru_belakang_kiri/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_belakang_kiri_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add paru_belakang_kiri'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'belakang_kiri',
            '#weight' => -3,
            '#action' => '/reference/paru_belakang_kiri/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_paru_belakang_kiri');
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

    function ref_belakang_kiri_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/paru_belakang_kiri/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_paru_belakang_kiri', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_paru_belakang_kiri',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/paru_belakang_kiri');
//        } else {
//            redirect_to('/reference/paru_belakang_kiri/form');
//        }
    }

    function ref_belakang_kiri_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'belakang_kiri', 'paru', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi paru belakang_kiri');
        $result['description'] = __t('informasi detil referensi belakang_kiri yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/paru_belakang_kiri/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'belakang_kiri'),
            array('ref_paru_belakang_kiri'),
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
                'link' => '/reference/paru_belakang_kiri/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/paru_belakang_kiri/edit/',
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

    function ref_belakang_kiri_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_paru_belakang_kiri', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_paru_belakang_kiri',
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
        redirect_to('/reference/paru_belakang_kiri/detail/' . $_POST['id']);
    }

    function ref_belakang_kiri_drop(){
        if($this->__is_dropable($_POST['id'], 'belakang_kiri', 'paru', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_paru_belakang_kiri',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/paru_belakang_kiri');
    }

    function ref_belakang_kanan_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi paru belakang_kanan');
        $result['description'] = __t('Referensi pilihan paru belakang_kanan pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/paru_belakang_kanan/form',
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
                'field' => 'belakang_kanan',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_paru_belakang_kanan'),
            NULL,
            'belakang_kanan'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['belakang_kanan'] = ucwords($query->fields['belakang_kanan']);
                $result['data'][$i]['goto'] = '/reference/paru_belakang_kanan/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_belakang_kanan_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add paru_belakang_kanan'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'belakang_kanan',
            '#weight' => -3,
            '#action' => '/reference/paru_belakang_kanan/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_paru_belakang_kanan');
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

    function ref_belakang_kanan_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/paru_belakang_kanan/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_paru_belakang_kanan', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_paru_belakang_kanan',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/paru_belakang_kanan');
//        } else {
//            redirect_to('/reference/paru_belakang_kanan/form');
//        }
    }

    function ref_belakang_kanan_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'belakang_kanan', 'paru', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi paru belakang_kanan');
        $result['description'] = __t('informasi detil referensi belakang_kanan yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/paru_belakang_kanan/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'belakang_kanan'),
            array('ref_paru_belakang_kanan'),
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
                'link' => '/reference/paru_belakang_kanan/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/paru_belakang_kanan/edit/',
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

    function ref_belakang_kanan_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_paru_belakang_kanan', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_paru_belakang_kanan',
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
        redirect_to('/reference/paru_belakang_kanan/detail/' . $_POST['id']);
    }

    function ref_belakang_kanan_drop(){
        if($this->__is_dropable($_POST['id'], 'belakang_kanan', 'paru', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_paru_belakang_kanan',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/paru_belakang_kanan');
    }

    function ref_hepar_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi paru hepar');
        $result['description'] = __t('Referensi pilihan paru hepar pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/paru_hepar/form',
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
                'field' => 'hepar',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_paru_hepar'),
            NULL,
            'hepar'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['hepar'] = ucwords($query->fields['hepar']);
                $result['data'][$i]['goto'] = '/reference/paru_hepar/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_hepar_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add paru_hepar'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'hepar',
            '#weight' => -3,
            '#action' => '/reference/paru_hepar/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_paru_hepar');
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

    function ref_hepar_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/paru_hepar/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_paru_hepar', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_paru_hepar',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/paru_hepar');
//        } else {
//            redirect_to('/reference/paru_hepar/form');
//        }
    }

    function ref_hepar_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'hepar', 'paru', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi paru hepar');
        $result['description'] = __t('informasi detil referensi hepar yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/paru_hepar/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'hepar'),
            array('ref_paru_hepar'),
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
                'link' => '/reference/paru_hepar/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/paru_hepar/edit/',
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

    function ref_hepar_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_paru_hepar', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_paru_hepar',
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
        redirect_to('/reference/paru_hepar/detail/' . $_POST['id']);
    }

    function ref_hepar_drop(){
        if($this->__is_dropable($_POST['id'], 'hepar', 'paru', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_paru_hepar',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/paru_hepar');
    }

    function ref_bunyi_pernafasan_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi paru bunyi_pernafasan');
        $result['description'] = __t('Referensi pilihan paru bunyi_pernafasan pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/paru_bunyi_pernafasan/form',
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
                'field' => 'bunyi_pernafasan',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_paru_bunyi_pernafasan'),
            NULL,
            'bunyi_pernafasan'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['bunyi_pernafasan'] = ucwords($query->fields['bunyi_pernafasan']);
                $result['data'][$i]['goto'] = '/reference/paru_bunyi_pernafasan/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_bunyi_pernafasan_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add paru_bunyi_pernafasan'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'bunyi_pernafasan',
            '#weight' => -3,
            '#action' => '/reference/paru_bunyi_pernafasan/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_paru_bunyi_pernafasan');
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

    function ref_bunyi_pernafasan_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/paru_bunyi_pernafasan/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_paru_bunyi_pernafasan', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_paru_bunyi_pernafasan',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/paru_bunyi_pernafasan');
//        } else {
//            redirect_to('/reference/paru_bunyi_pernafasan/form');
//        }
    }

    function ref_bunyi_pernafasan_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'bunyi_pernafasan', 'paru', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi paru bunyi_pernafasan');
        $result['description'] = __t('informasi detil referensi bunyi_pernafasan yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/paru_bunyi_pernafasan/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'bunyi_pernafasan'),
            array('ref_paru_bunyi_pernafasan'),
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
                'link' => '/reference/paru_bunyi_pernafasan/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/paru_bunyi_pernafasan/edit/',
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

    function ref_bunyi_pernafasan_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_paru_bunyi_pernafasan', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_paru_bunyi_pernafasan',
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
        redirect_to('/reference/paru_bunyi_pernafasan/detail/' . $_POST['id']);
    }

    function ref_bunyi_pernafasan_drop(){
        if($this->__is_dropable($_POST['id'], 'bunyi_pernafasan', 'paru', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_paru_bunyi_pernafasan',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/paru_bunyi_pernafasan');
    }

    function ref_bunyi_tambahan_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi paru bunyi_tambahan');
        $result['description'] = __t('Referensi pilihan paru bunyi_tambahan pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/paru_bunyi_tambahan/form',
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
                'field' => 'bunyi_tambahan',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_paru_bunyi_tambahan'),
            NULL,
            'bunyi_tambahan'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['bunyi_tambahan'] = ucwords($query->fields['bunyi_tambahan']);
                $result['data'][$i]['goto'] = '/reference/paru_bunyi_tambahan/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_bunyi_tambahan_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add paru_bunyi_tambahan'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'bunyi_tambahan',
            '#weight' => -3,
            '#action' => '/reference/paru_bunyi_tambahan/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_paru_bunyi_tambahan');
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

    function ref_bunyi_tambahan_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/paru_bunyi_tambahan/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_paru_bunyi_tambahan', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_paru_bunyi_tambahan',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/paru_bunyi_tambahan');
//        } else {
//            redirect_to('/reference/paru_bunyi_tambahan/form');
//        }
    }

    function ref_bunyi_tambahan_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'bunyi_tambahan', 'paru', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi paru bunyi_tambahan');
        $result['description'] = __t('informasi detil referensi bunyi_tambahan yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/paru_bunyi_tambahan/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'bunyi_tambahan'),
            array('ref_paru_bunyi_tambahan'),
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
                'link' => '/reference/paru_bunyi_tambahan/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/paru_bunyi_tambahan/edit/',
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

    function ref_bunyi_tambahan_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_paru_bunyi_tambahan', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_paru_bunyi_tambahan',
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
        redirect_to('/reference/paru_bunyi_tambahan/detail/' . $_POST['id']);
    }

    function ref_bunyi_tambahan_drop(){
        if($this->__is_dropable($_POST['id'], 'bunyi_tambahan', 'paru', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_paru_bunyi_tambahan',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/paru_bunyi_tambahan');
    }

    function __get_refs($fields, $sort=NULL){
        $result = array();
        $sql = $this->query->getSelect(
            array(),
            array($this->config->reftable[$fields][0]),
            NULL,
            (!is_null($sort) ? $sort . ' asc' : 'id asc')
        );
        $this->query->connect();
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            $result[$query->fields['id']] = $query->fields[$this->config->reftable[$fields][1]];
            $query->MoveNext();
        }
        return $result;
    }

    function cardio_menu(){
        $result = array();
        $result['#title'] = __t('Paru');
        $result['#tpl'] = MODULES_DIR . DS . 'paru' . DS . 'paru.tpl';
        $datafields = $this->__get_data_fields('paru', $this->query);
        if (count($this->config->free_val) > 0){
            $vcache = $this->config->free_val;
            $sql = $this->query->getSelect(
                array(),
                array('paru'),
                array(
                    array('&&', "id=" . $vcache['id'])
                )
            ); unset($vcache);
            $this->query->connect();
            $getit = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            if($getit->_numOfRows > 0){
                foreach($getit->fields as $key => $value){
                    $vcache[$key] = $value;
                }
            }
        }
        foreach($datafields as $key => $value){
            $result['datafields'][$value] = array(
                'title' => __t($value),
                'type' => $this->config->typeoffields[$value],
                'value' => isset($vcache[$value]) ? $vcache[$value] : ''
            );
            if(in_array($value, $this->config->fieldsisarray)){
                $result['datafields'][$value]['theref'] = $this->__get_refs($value);
            } elseif($this->config->typeoffields[$value] == 'datetime'){
                $result['datafields'][$value]['theref'] = $this->nama_bulan;
                $result['datafields'][$value]['timenow'] = $this->config->time;
            } else {
                $result['datafields'][$value]['size'] = 6;
            }
            $result['datafields'][$value]['readonly'] = isset($this->config->free_val['readonly']) ? true : false;
        }
        return $result;
    }

    function cardio_submit(){
        $thefields = $this->__get_data_fields('paru', $this->query);
        foreach($this->config->free_val as $key => $value){
            if(in_array($key, $thefields)){
//                if($key == 'inspections'){
//                    if(count($value) > 0){
//                        $value = implode(',', $value);
//                    }
//                }
                $thevalue[$key] = $value;
            }
        } unset($thefields);
        if($_POST['id'] != ''){
            unset($thevalue['id']);
            $sql = $this->query->updateData(
                'paru',
                $thevalue,
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
        } else {
            $sql = $this->query->saveData(
                'paru',
                $thevalue
            );
        }
//        echo '<pre>'; print_r($thevalue); echo '</pre>';
        unset($thevalue);
        $this->query->connect();
        $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
    }
}