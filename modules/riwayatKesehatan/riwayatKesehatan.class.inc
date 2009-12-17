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
            'user_required' => NULL
        );
        $items['riwayatKesehatan_form'] = array(
            'title' => __t('form riwayatKesehatan'),
            'description' => __t('formulir riwayatKesehatan pasien'),
            'path' => '/care/riwayatKesehatan/form',
            'exec' => 'form',
            'weight' => 5,
            'user_required' => NULL
        );
       return $items;
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
                'field' => 'inputer',
                'caption' => __t('pengambil data'),
                'align' => 'left'
            ),
            array(
                'field' => 'tgl',
                'caption' => __t('tanggal'),
                'width' => '20%',
                'align' => 'right'
            )
        );
        $sql = $this->query->getSelect(
                array(),
                array('riwayatKesehatan'),
                array(
                    array('&&', "perawatan=" . $pid)
                )
        );
        $this->query->connect();
        $getit = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$getit->_numOfRows; $i++){
            $sql = $this->query->getSelect(
                    array('nama'),
                    array('stafs'),
                    array('&&', "id=" . $getit->fields['inputer'])
            );
            $this->query->connect();
            $getthis = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            $result['data'][$i]['inputer'] = $getthis->fields['nama'];
            unset($getthis);
            $result['data'][$i]['goto'] = '/care/riwayatKesehatan/detail_form/' . $pid . '/' . $getit->fields['id'];
            $result['data'][$i]['tgl'] = date('j', strtotime($getthis->fields['tgl']));
            $result['data'][$i]['tgl'] .= ucwords(__t($this->nama_bulan[date('n', strtotime($getthis->fields['tgl']))]));
            $result['data'][$i]['tgl'] .= date('Y H:i:s', strtotime($getthis->fields['tgl']));
        } unset($getit);
        return $result;
    }

    function form(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 3){
            return $this->__get_form($dump[3]);
        } else {
            redirect_to('/care/perawatan/pengkajian');
        }
    }

    function __get_form($pid){
        $patientinfo = $this->__head_page($pid);
        if(count($patientinfo) < 1){
            redirect_to('/'); exit();
        }

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
            '#action' => '/care/perawatan/pengkajian/form' . ($this->formhabit == 'readonly' ? '/edit_' . $vcache['id'] : '_submit'),
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE,
            '#formtpl' => MODULES_DIR . DS . 'pengkajian' . DS . 'pengkajian.tpl',
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
                if($key != 'pengkajian'){
                    $rujukanopts[$key] = $value;
                }
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
                    'id' => $patientinfo['id']
                )
            );
            $pkjitems = array(
                '' => __t('-- pengkajian --')
            );
            $dumppkj = $this->__get_pengkajian_lists();
            foreach($dumppkj as $key => $value){
                $pkjitems[$key] = $value;
            } unset($dumppkj);
            $result['pengkajian']['#addmenu']['#addmenu1'] = array(
                'title' => __t('pengkajian'),
                'action' => '/care/perawatan/pengkajian_items',
                'position' => 'top',
                'class' => 'button',
                'methode' => 'choose',
                'options' => $pkjitems,
                'user_required' => 'perawatan',
                'filter' => 'items',
                'items' => array (
                    'id' => $patientinfo['id']
                )
            );
        unset($rujukanopts, $pkjitems);
        }
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

}