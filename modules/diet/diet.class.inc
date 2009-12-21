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
 *  dietclass.php
 *  
 *  Created on Oct 3, 2009, 4:35:17 PM
 */

require_once MODULES_DIR . DS . 'diet' . DS . 'config.inc';

class dietModule extends mainModule
{
    var $title = 'diet';
    var $description = '';

    function menu(){
        $items['diet_view'] = array(
            'title' => __t('diet perawatan'),
            'description' => __t('daftar diet perawatan'),
            'path' => '/care/perawatan/diet',
            'exec' => 'view',
            'weight' => 5,
            'user_required' => 'perawatan'
        );
        $items['diet_form'] = array(
            'title' => __t('form diet'),
            'description' => __t('formulir diet pasien'),
            'path' => '/care/diet/form',
            'exec' => 'form',
            'weight' => 5,
            'user_required' => 'perawatan'
        );
        $items['diet_form_submit'] = array(
            'title' => __t('form diet'),
            'description' => __t('formulir diet pasien'),
            'path' => '/care/diet/form_submit',
            'exec' => 'form_submit',
            'weight' => 5,
            'user_required' => 'perawatan'
        );
        $items['diet_detail'] = array(
            'title' => __t('detail form diet'),
            'description' => __t('formulir detil diet pasien'),
            'path' => '/care/diet/detail_form',
            'exec' => 'detail_form',
            'weight' => 5,
            'user_required' => 'perawatan'
        );
       return $items;
    }

    function detail_form(){
        $this->formhabit = 'readonly';
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        $vcache = $this->__get_diet_data((int)$dump[3]);
        $this->vardump = $this->__write_custom_cache($vcache);
        $this->vardump['readonly'] = $this->formhabit;
        $result = $this->__get_form($vcache['perawatan']);
        return $result;
    }

    function __head_page($id){
        $this->sync_scheme('diet', $this->query);
        $result = array();
        if(!is_null($id) && trim($id) != ''){
            $sql = $this->query->getSelect(
                array(),
                array('perawatan'),
                array(
                    array('&&', "id=" . $id)
                )
            );
            $this->query->connect();
            $getit = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            if($getit->_numOfRows > 0){
                $result = $getit->fields;
                $sql = $this->query->getSelect(
                    array('nama'),
                    array('patients'),
                    array(
                        array('&&', "id=" . $getit->fields['patients'])
                    )
                );
                $this->query->connect();
                $getthis = $this->query->conn->Execute($sql); unset($sql);
                $this->query->close();
                if($getthis->_numOfRows > 0){
                    $result['nama'] = $getthis->fields['nama'];
                } unset($getthis);
                $sql = $this->query->getSelect(
                    array('ruang'),
                    array('ruang'),
                    array(
                        array('&&', "id=" . $getit->fields['ruang'])
                    )
                );
                $this->query->connect();
                $getthis = $this->query->conn->Execute($sql); unset($sql);
                $this->query->close();
                if($getthis->_numOfRows > 0){
                    $result['ruang'] = $getthis->fields['ruang'];
                } unset($getthis);
                $result['pukul_masuk'] = date('j', strtotime($getit->fields['pukul_masuk']));
                $result['pukul_masuk'] .= ' ' . __t($this->nama_bulan[date('n', strtotime($getit->fields['pukul_masuk']))]);
                $result['pukul_masuk'] .= ' ' . date('Y H:i:s', strtotime($getit->fields['pukul_masuk']));
            }
        }
        return $result;
    }

    function view(){
        if(isset($_POST['pid'])){
            $pid = $_POST['pid'];
        } else {
            $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
            if(count($dump) > 3){
                $pid = $dump[3];
            }
        }
        if(isset($pid)){
            return $this->__get_view($pid);
        } else {
            return $this->__get_view();
        }
    }

    function __get_view($pid = NULL){
        if(!is_null($pid)){
            $patientinfo = $this->__head_page($pid);
        }
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('diet perawatan pasien') . (!is_null($pid) ? ' ' . __t('a.n.') . ' ' . $patientinfo['nama'] : '');
        $result['description'] = (!is_null($pid) ? __t('daftar diet perawatan pasien') . ' ' . __t('a.n.') . ' ' . $patientinfo['nama'] : __t('daftar diet perawatan beberapa pasien terakhir'));
        if(!is_null($pid)){
            $result['addmenu']['#add'] = array(
                'title' => __t('add'),
                'action' => '/care/diet/form/' . $pid,
                'position' => 'top',
                'user_required' => 'perawatan'
            );
            $addmenuopts = array(
                '' => __t('-- medical record --'),
                'all' => __t('semua')
            );
            $dump_addmenus = $this->__get_bagian_lists();
            foreach($dump_addmenus as $key => $value){
                $sql = $this->query->getSelect(
                    array('id'),
                    array('kunjungan'),
                    array(
                        array('&&', "patients=" . $patientinfo['patients']),
                        array('&&', "bagian=" . $value),
                        array('&&', "doneby is not null")
                    )
                );
                $this->query->connect();
                $getit = $this->query->conn->Execute($sql); unset($sql);
                $this->query->close();
                if($getit->_numOfRows > 0){
                    $addmenuopts[$key] = $value;
                } unset($getit);
            } unset($dump_addmenus);
            $result['addmenu']['#medical_record'] = array(
                'title' => __t('medical record'),
                'action' => '/user/patient/medical_record/' . $patientinfo['patients'],
                'position' => 'top',
                'class' => 'button',
                'methode' => 'choose',
                'options' => $addmenuopts,
                'filter' => 'bagian'
            );
            $rujukanopts = array(
                '' => __t('-- perawatan --')
            );
            $dumprjk = $this->__get_perawatan_lists();
            foreach($dumprjk as $key => $value){
                if($key != 'diet'){
                    $rujukanopts[$key] = $value;
                }
            } unset($dumprjk);
            $result['addmenu']['#dirujuk_ke'] = array(
                'title' => __t('dirujuk ke'),
                'action' => '/care/perawatan',
                'position' => 'top',
                'class' => 'button',
                'methode' => 'choose',
                'options' => $rujukanopts,
                'user_required' => 'perawatan',
                'filter' => 'items',
                'items' => array (
                    'pid' => $patientinfo['id']
                )
            ); unset($rujukanopts);
        }
        $result['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => (!is_null($pid) ? 'nama_diet' : 'nama'),
                'caption' => (!is_null($pid) ? __t('nama diet') : __t('nama')),
                'align' => 'left'
            ),
            array(
                'field' => (!is_null($pid) ? 'catatan' : 'usia'),
                'caption' => (!is_null($pid) ? __t('catatan') : __t('usia')),
                'width' => (!is_null($pid) ? '15%' : '25%'),
                'align' => (!is_null($pid) ? 'center' : 'right')
            ),
            array(
                'field' => (!is_null($pid) ? 'inputer' : 'pukul_masuk'),
                'caption' => (!is_null($pid) ? __t('pengambil data') : __t('tanggal masuk')),
                'width' => '25%',
                'align' => (!is_null($pid) ? 'center' : 'right')
            )
        );

        if(!is_null($pid)){
            $sql = $this->query->getSelect(
                array(),
                array('diet'),
                array(
                    array('&&', "perawatan=" . $pid)
                ),
                'inputtime desc'
            );
            $this->query->connect();
            $getit = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            if($getit->_numOfRows > 0){
                for($i=0; $i<$getit->_numOfRows; $i++){
                    $result['data'][$i] = $getit->fields;
                    $result['data'][$i]['goto'] = '/care/diet/detail_form/' . $getit->fields['id'];
                    $getit->MoveNext();
                }
            } unset($getit);
        } else {
            $sql = $this->query->getSelect(
                array(),
                array('perawatan'),
                array(
                    array('&&', "pukul_keluar is null")
                ),
                'inputtime desc'
            );
            $this->query->connect();
            $getit = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            if($getit->_numOfRows > 0){
                for($i=0; $i<$getit->_numOfRows; $i++){
                    $sql = $this->query->getSelect(
                        array('id', 'nama', 'tgl_lahir'),
                        array('patients'),
                        array(
                            array('&&', "id=" . $getit->fields['patients'])
                        )
                    ); unset($idpatient);
                    $this->query->connect();
                    $getthis = $this->query->conn->Execute($sql); unset($sql);
                    $this->query->close();
                    $result['data'][$i]['nama'] = $getthis->fields['nama'];
                    $result['data'][$i]['usia'] = number_format(round($this->agecount_in_month(strtotime($getthis->fields['tgl_lahir']))/12, 1), 1, ',','.') . ' th';
                    $result['data'][$i]['goto'] = '/care/perawatan/diet/' . $getit->fields['id'];
                    $result['data'][$i]['pukul_masuk'] = date('j-n-Y H:i:s', strtotime($getit->fields['pukul_masuk']));
                    $getit->MoveNext();
                }
            }
        }
        return $result;
    }
    
    function __get_diet_data($id){
        $result = array();
        $sql = $this->query->getSelect(
            array(),
            array('diet'),
            array(
                array('&&', "id=" . $id)
            )
        );
        $this->query->connect();
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            foreach($query->fields as $key => $value){
                $result[$key] = $value;
            }
        } unset($query);
        return $result;
    }

    function form(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 3){
            return $this->__get_form((int)$dump[3]);
        } else {
            unset($dump);
            redirect_to('/care/perawatan/diet');
        }
    }

    function __get_form($pid){
        $patientinfo = $this->__head_page($pid);
        if(count($patientinfo) < 1){
            redirect_to('/'); exit();
        }

        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        } else {
            $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
            if(count($dump) > 4){
                if(preg_match('/^edit_/', $dump[4])){
                    $diet_id = preg_replace('/^edit_/','',$dump[4]);
                } else {
                    $diet_id = $dump[4];
                }
                $vcache = $this->__get_diet_data((int)$diet_id);
                unset($diet_id);
                $this->vardump = $vcache;
            } unset($dump);
        }
        $vcache['perawatan'] = $pid;
        $addmenuopts = array(
            '' => __t('-- medical record --'),
            'all' => __t('semua')
        );
        $dump_addmenus = $this->__get_bagian_lists();
        foreach($dump_addmenus as $key => $value){
            $sql = $this->query->getSelect(
                array('id'),
                array('kunjungan'),
                array(
                    array('&&', "patients=" . $patientinfo['patients']),
                    array('&&', "bagian=" . $value),
                    array('&&', "doneby is not null")
                )
            );
            $this->query->connect();
            $getit = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            if($getit->_numOfRows > 0){
                $addmenuopts[$key] = $value;
            } unset($getit);
        } unset($dump_addmenus);
        $result['diet'] = array(
            '#type' => 'special',
            '#id' => 'diet',
            '#title' => __t('diet'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/care/diet/form' . (isset($this->formhabit) && $this->formhabit == 'readonly' ? '/' . $pid . '/edit_' . $vcache['id'] : '_submit'),
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE,
            '#formtpl' => MODULES_DIR . DS . 'diet' . DS . 'diet.tpl',
            '#addmenu' => array(
                '#addmenu' => array(
                    'title' => __t('medical record'),
                    'action' => '/user/patient/medical_record/' . $patientinfo['patients'],
                    'position' => 'top',
                    'class' => 'button',
                    'methode' => 'choose',
                    'options' => $addmenuopts,
                    'filter' => 'bagian'
                )
            ),
            '#patientinfo' => $patientinfo
        ); unset($addmenuopts);
        if($this->formhabit == 'readonly'){
            $rujukanopts = array(
                '' => __t('-- perawatan --')
            );
            $dumprjk = $this->__get_perawatan_lists();
            foreach($dumprjk as $key => $value){
                $rujukanopts[$key] = $value;
            } unset($dumprjk);
            $result['diet']['#addmenu']['#addmenu0'] = array(
                'title' => __t('dirujuk ke'),
                'action' => '/care/perawatan',
                'position' => 'top',
                'class' => 'button',
                'methode' => 'choose',
                'options' => $rujukanopts,
                'user_required' => 'perawatan',
                'filter' => 'items',
                'items' => array (
                    'pid' => $patientinfo['id']
                )
            ); unset($rujukanopts);
        }
        $thefields = $this->__get_data_fields('diet', $this->query);
        foreach($thefields as $value){
            if(in_array($value, $this->config->hiddenfields)){
                if($this->config->typeoffields[$value] != 'system'){
                    $result['diet'][$value] = array(
                        '#type' => 'hidden',
                        '#value' => isset($vcache[$value]) ? $vcache[$value] : ''
                    );
                }
            } else {
                $result['diet'][$value] = array(
                    '#type' => $this->config->typeoffields[$value],
                    '#title' => __t($value)
                );
                if($this->config->typeoffields[$value] == 'select' || $this->config->typeoffields[$value] == 'radio' || $this->config->typeoffields[$value] == 'date' || $this->config->typeoffields[$value] == 'datetime'){
                    if($this->config->typeoffields[$value] == 'date' || $this->config->typeoffields[$value] == 'datetime'){
                        $options = $this->nama_bulan;
                        if(!isset($vcache[$value]) || is_null($vcache[$value]) || trim($vcache[$value]) == ''){
                            if($this->config->typeoffields[$value] == 'date'){
                                $vcache[$value] = date('Y-m-d', $this->config->time);
                            } else {
                                $vcache[$value] = date('Y-m-d H:i:s', $this->config->time);
                            }
                        }
                        $result['diet'][$value]['#style'] = 'text-align:right';
                    } else {
                        $options = $this->__get_ref_options($this->config->reftable[$value][0], $this->config->reftable[$value][1], $this->config->reftable[$value][2], $this->query);
                    }
                    $result['diet'][$value]['#option'] = $options;
                    unset($options);
                }
                $result['diet'][$value]['#value'] = isset($vcache[$value]) ? $vcache[$value] : '';
                if(isset($this->formhabit) && $this->formhabit == 'readonly'){
                    $result['diet'][$value]['#readonly'] = true;
                }
            }
        }
        $result['diet']['submit'] = array(
            '#value' => isset($this->formhabit) && $this->formhabit == 'readonly' ? __t('edit') : __t('submit')
        );
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function form_submit(){
        return $this->__get_form_submit();
    }

    function __get_form_submit(){
        $this->vardump = $this->__write_form_cache();
        $thefields = $this->__get_data_fields('diet', $this->query);
        foreach($this->vardump as $key => $value){
            if(in_array($key, $thefields)){
                if($this->config->typeoffields[$key] == 'date'){
                    $value = explode('|', $value);
                    $value = implode('-', $value);
                } elseif($this->config->typeoffields[$key] == 'datetime'){
                    $value = explode('-', $value);
                    $value = $value[0] . '-' . $value[1] . '-' . $value[2] . ' ' . $value[3] . ':' . $value[4] . ':' . $value[5];
                }
                $thevalue[$key] = $value;
            }
        } unset($thefields);
        $user = $this->__get_user_info();
//        echo "<pre>";print_r($user);echo "</pre>";
        if($_POST['id'] != ''){
            $thevalue['updated'] = $_COOKIE[$this->config->cookieid] . '|' . date('Y-m-d H:i:s', $this->config->time);
            $opr = 'update';
            $strid = array('id', $_POST['id']);
        } else {
            $thevalue['id'] = $this->__get_id_insert_value('diet', 'id', $this->query);
            $thevalue['inputer'] = $user['id'];
            $thevalue['inputtime'] = date('Y-m-d H:i:s', $this->config->time);
            $this->vardump['id'] = $thevalue['id'];
            $opr = 'insert';
            $strid = array('id', $thevalue['id']);
        }
        $this->__exec_db_ops(
            $this->query,
            'diet',
            $opr,
            $strid,
            $thevalue
        );
        $iddata = $thevalue['id'];
        unset($thevalue, $opr, $strid);
        redirect_to('/care/diet/detail_form/' . $iddata);
    }
}