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
 *  riwayatKesehatanclass.php
 *  
 *  Created on Dec 17, 2009, 8:40:22 AM
 */

require_once MODULES_DIR . DS . 'riwayatKesehatan' . DS . 'config.inc';

class riwayatKesehatanModule extends mainModule
{
    var $title = 'riwayatKesehatan';
    var $description = '';

    function menu(){
        $items['riwayatKesehatan_view'] = array(
            'title' => __t('riwayatKesehatan'),
            'description' => __t('daftar riwayatKesehatan'),
            'path' => '/care/riwayatKesehatan/view',
            'exec' => 'view',
            'weight' => 5,
            'user_required' => 'perawatan'
        );
        $items['riwayatKesehatan_form'] = array(
            'title' => __t('form riwayatKesehatan'),
            'description' => __t('formulir riwayatKesehatan pasien'),
            'path' => '/care/riwayatKesehatan/form',
            'exec' => 'form',
            'weight' => 5,
            'user_required' => 'perawatan'
        );
        $items['riwayatKesehatan_form_submit'] = array(
            'title' => __t('form riwayatKesehatan'),
            'description' => __t('formulir riwayatKesehatan pasien'),
            'path' => '/care/riwayatKesehatan/form_submit',
            'exec' => 'form_submit',
            'weight' => 5,
            'user_required' => 'perawatan'
        );
        $items['riwayatKesehatan_detail'] = array(
            'title' => __t('detail form riwayatKesehatan'),
            'description' => __t('formulir detil riwayatKesehatan pasien'),
            'path' => '/care/riwayatKesehatan/detail_form',
            'exec' => 'detail_form',
            'weight' => 5,
            'user_required' => 'perawatan'
        );
       return $items;
    }

    function detail_form(){
        $this->formhabit = 'readonly';
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        $vcache = $this->__get_riwayat_kesehatan_data((int)$dump[3]);
        $this->vardump = $this->__write_custom_cache($vcache);
        $this->vardump['readonly'] = $this->formhabit;
        $result = $this->__get_form($vcache['perawatan']);
        return $result;
    }

    function __get_perawatan_head($pid){
        $result = array();
        $this->__include_module('pengkajian');
        $result = $this->pengkajian_exec->__head_page($pid);
        unset($this->pengkajian_exec, $this->pengkajian_query, $this->pengkajian_config);
        return $result;
    }

    function __get_pengkajian_modules(){
        $result = array();
        $this->__include_module('pengkajian');
        foreach($this->pengkajian_config->module_included as $key => $value){
            if($this->module_is_active($value) !== FALSE){
                $result[$value] = __t($value);
            }
        }
        unset($this->pengkajian_exec, $this->pengkajian_query, $this->pengkajian_config);
        return $result;
    }

    function view(){
        $this->sync_scheme('riwayat_kesehatan', $this->query);
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
            redirect_to('/care/perawatan/pengkajian');
        }
    }

    function __get_view($pid){
        $patientinfo = $this->__get_perawatan_head($pid);
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('riwayat kesehatan pasien') . ' ' . __t('a.n.') . ' ' . $patientinfo['nama'];
        $result['description'] = __t('daftar riwayat kesehatan pasien') . ' ' . __t('a.n.') . ' ' . $patientinfo['nama'];
        $result['addmenu']['#add'] = array(
            'title' => __t('add'),
            'action' => '/care/riwayatKesehatan/form/' . $pid,
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
        ); unset($addmenuopts);
        $rujukanopts = array(
            '' => __t('-- perawatan --')
        );
        $dumprjk = $this->__get_perawatan_lists();
        foreach($dumprjk as $key => $value){
            $rujukanopts[$key] = $value;
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
        $pkjopts = array(
            '' => __t('-- pengkajian --')
        );
        $dumppkj = $this->__get_pengkajian_modules();
        foreach($dumppkj as $key => $value){
            if($key != 'riwayatKesehatan'){
                $pkjopts[$key] = $value;
            }
        } unset($dumppkj);
        $result['addmenu']['#pengkajian'] = array(
            'title' => __t('pengkajian'),
            'action' => '/care/pengkajian/redirect',
            'position' => 'top',
            'class' => 'button',
            'methode' => 'choose',
            'options' => $pkjopts,
            'user_required' => 'perawatan',
            'filter' => 'items',
            'items' => array (
                'pid' => $patientinfo['id']
            )
        ); unset($pkjopts);
        $result['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => 'tgl',
                'caption' => __t('tanggal'),
                'width' => '30%',
                'align' => 'right'
            ),
            array(
                'field' => 'inputer',
                'caption' => __t('pengambil data'),
                'align' => 'left'
            )
        );
        $sql = $this->query->getSelect(
                array(),
                array('riwayat_kesehatan'),
                array(
                    array('&&', "perawatan=" . $pid)
                ),
                'tgl desc'
        );
        $this->query->connect();
        $getit = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($getit->_numOfRows > 0){
            for($i=0; $i<$getit->_numOfRows; $i++){
                $sql = $this->query->getSelect(
                        array('nama'),
                        array('stafs'),
                        array(
                            array('&&', "id=" . $getit->fields['inputer'])
                        )
                );
                $this->query->connect();
                $getthis = $this->query->conn->Execute($sql); unset($sql);
                $this->query->close();
                $result['data'][$i]['inputer'] = ucwords($getthis->fields['nama']);
                unset($getthis);
                $result['data'][$i]['goto'] = '/care/riwayatKesehatan/detail_form/' . $getit->fields['id'];
                $result['data'][$i]['tgl'] = date('j', strtotime($getit->fields['tgl']));
                $result['data'][$i]['tgl'] .= ' ' . ucwords(__t($this->nama_bulan[date('n', strtotime($getit->fields['tgl']))]));
                $result['data'][$i]['tgl'] .= ' ' . date('Y H:i:s', strtotime($getit->fields['tgl']));
                $getit->MoveNext();
            }
        } unset($getit);
        return $result;
    }

    function __get_riwayat_kesehatan_data($id){
        $result = array();
        $sql = $this->query->getSelect(
            array(),
            array('riwayat_kesehatan'),
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
            redirect_to('/care/perawatan/pengkajian');
        }
    }

    function __get_form($pid){
        $patientinfo = $this->__get_perawatan_head($pid);
        if(count($patientinfo) < 1){
            redirect_to('/'); exit();
        }

        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        } else {
            $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
            if(count($dump) > 4){
                if(preg_match('/^edit_/', $dump[4])){
                    $riwayat_id = preg_replace('/^edit_/','',$dump[4]);
                } else {
                    $riwayat_id = $dump[4];
                }
                $vcache = $this->__get_riwayat_kesehatan_data((int)$riwayat_id);
                unset($riwayat_id);
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
        $result['pengkajian'] = array(
            '#type' => 'special',
            '#id' => 'pengkajian',
            '#title' => __t('pengkajian'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/care/riwayatKesehatan/form' . (isset($this->formhabit) && $this->formhabit == 'readonly' ? '/' . $pid . '/edit_' . $vcache['id'] : '_submit'),
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE,
            '#formtpl' => MODULES_DIR . DS . 'riwayatKesehatan' . DS . 'riwayatKesehatan.tpl',
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
            $result['pengkajian']['#addmenu']['#addmenu0'] = array(
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
            );
            $pkjitems = array(
                '' => __t('-- pengkajian --')
            );
            $dumppkj = $this->__get_pengkajian_modules();
            foreach($dumppkj as $key => $value){
                $pkjitems[$key] = $value;
            } unset($dumppkj);
            $result['pengkajian']['#addmenu']['#addmenu1'] = array(
                'title' => __t('pengkajian'),
                'action' => '/care/pengkajian/redirect',
                'position' => 'top',
                'class' => 'button',
                'methode' => 'choose',
                'options' => $pkjitems,
                'user_required' => 'perawatan',
                'filter' => 'items',
                'items' => array (
                    'pid' => $patientinfo['id']
                )
            );
        unset($rujukanopts, $pkjitems);
        }
        $thefields = $this->__get_data_fields('riwayat_kesehatan', $this->query);
        foreach($thefields as $value){
            if(in_array($value, $this->config->hiddenfields)){
                if($this->config->typeoffields[$value] != 'system'){
                    $result['pengkajian'][$value] = array(
                        '#type' => 'hidden',
                        '#value' => isset($vcache[$value]) ? $vcache[$value] : ''
                    );
                }
            } else {
                $result['pengkajian'][$value] = array(
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
                        $result['rencana'][$value]['#style'] = 'text-align:right';
                    } else {
                        $options = $this->__get_ref_options($this->config->reftable[$value][0], $this->config->reftable[$value][1], $this->config->reftable[$value][2], $this->query);
                    }
                    $result['pengkajian'][$value]['#option'] = $options;
                    unset($options);
                }
                $result['pengkajian'][$value]['#value'] = isset($vcache[$value]) ? $vcache[$value] : '';
                if(isset($this->formhabit) && $this->formhabit == 'readonly'){
                    $result['pengkajian'][$value]['#readonly'] = true;
                }
            }
        }
        $result['pengkajian']['submit'] = array(
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
        $thefields = $this->__get_data_fields('riwayat_kesehatan', $this->query);
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
        if($_POST['id'] != ''){
            $thevalue['updated'] = $_COOKIE[$this->config->cookieid] . '|' . date('Y-m-d H:i:s', $this->config->time);
            $opr = 'update';
            $strid = array('id', $_POST['id']);
        } else {
            $thevalue['id'] = $this->__get_id_insert_value('riwayat_kesehatan', 'id', $this->query);
            $thevalue['inputer'] = $user['userid'];
            $thevalue['inputtime'] = date('Y-m-d H:i:s', $this->config->time);
            $this->vardump['id'] = $thevalue['id'];
            $opr = 'insert';
            $strid = array('id', $thevalue['id']);
        }
        $this->__exec_db_ops(
            $this->query,
            'riwayat_kesehatan',
            $opr,
            $strid,
            $thevalue
        );
        if(isset($thevalue['berat_sekarang']) && trim($thevalue['berat_sekarang']) != '' && ctype_digit($thevalue['berat_sekarang'])){
            $sql = $this->query->getSelect(
                    array('patients'),
                    array('perawatan'),
                    array(
                        array('&&', "id=" . $thevalue['perawatan'])
                    )
            );
            $this->query->connect();
            $getit = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            if($getit->_numOfRows > 0){
                $sql = $this->query->getSelect(
                        array('berat'),
                        array('patients'),
                        array(
                            array('&&', "id=" . $getit->fields['patients'])
                        )
                );
                $this->query->connect();
                $getthis = $this->query->conn->Execute($sql); unset($sql);
                $this->query->close();
                if($getthis->fields['berat'] != $thevalue['berat_sekarang']){
                    $this->__exec_db_ops(
                        $this->query,
                        'patients',
                        'update',
                        array('id', $getit->fields['patients']),
                        array('berat', $thevalue['berat_sekarang'])
                    );
                } unset($getthis);
            } unset($getit);
        }
        $iddata = $thevalue['id'];
        unset($thevalue, $opr, $strid);
        redirect_to('/care/riwayatKesehatan/detail_form/' . $iddata);
    }
}