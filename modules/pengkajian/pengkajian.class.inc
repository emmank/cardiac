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
 *  pengkajianclass.php
 *  
 *  Created on Oct 3, 2009, 4:35:17 PM
 */

require_once MODULES_DIR . DS . 'pengkajian' . DS . 'config.inc';

class pengkajianModule extends mainModule
{
    var $title = 'pengkajian module';
    var $description = '';

    function menu(){
        $items['pengkajian_view'] = array(
            'title' => __t('pengkajian'),
            'description' => __t('daftar pengkajian'),
            'path' => '/care/perawatan/pengkajian',
            'exec' => 'view_form',
            'weight' => 5,
            'user_required' => NULL
        );
       return $items;
    }

    function __head_page($id){
        $this->sync_scheme('pengkajian', $this->query);
        $this->sync_scheme('pengkajian_items', $this->query);
        $result = array();
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
        return $result;
    }

    function view_form(){
        if(isset($_POST['id'])){
            $id = $_POST['id'];
        } else {
            $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
            if(count($dump) > 3){
                $id = $dump[3];
            }
        }
        $patientinfo = $this->__head_page($id);
        $rujukanopts = array(
            '' => __t('-- perawatan --')
        );
        $dumprjk = $this->__get_perawatan_lists();
        foreach($dumprjk as $key => $value){
            if($key != 'pengkajian'){
                $rujukanopts[$key] = $value;
            }
        } unset($dumprjk);
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
        $pkjitems = array(
            '' => __t('-- pengkajian --')
        );
        $dumppkj = $this->__get_pengkajian_lists();
        foreach($dumppkj as $key => $value){
            $pkjitems[$key] = $value;
        } unset($dumppkj);
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
//        if($this->formhabit == 'readonly'){
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
//        }
        unset($rujukanopts, $pkjitems);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

}