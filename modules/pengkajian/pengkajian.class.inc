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
            'exec' => 'view',
            'weight' => 5,
            'user_required' => NULL
        );
        $items['pengkajian_form'] = array(
            'title' => __t('form pengkajian'),
            'description' => __t('formulir pengkajian pasien'),
            'path' => '/care/pengkajian/form',
            'exec' => 'form',
            'weight' => 5,
            'user_required' => NULL
        );
       return $items;
    }

    function __head_page($id){
        $this->sync_scheme('pengkajian', $this->query);
        $this->sync_scheme('pengkajian_items', $this->query);
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
        $result['title'] = __t('pengkajian pasien') . (!is_null($pid) ? ' ' . __t('a.n.') . ' ' . $patientinfo['nama'] : '');
        $result['description'] = (!is_null($pid) ? __t('daftar pengkajian pasien') . ' ' . __t('a.n.') . ' ' . $patientinfo['nama'] : __t('daftar pengkajian beberapa pasien terakhir'));
        if(!is_null($pid)){
            $result['headerfill'] = array(
                'patient_info' => array(
                    'type' => 'fieldset',
                    'title' => __t('patient info'),
                    'datainfo' => $patientinfo
                )
            );
            $result['addmenu']['#add'] = array(
                'title' => __t('input'),
                'action' => '/care/pengkajian/form/' . $pid,
                'position' => 'top',
                'user_required' => 'users'
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
                if($key != 'pengkajian'){
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
                    'id' => $patientinfo['id']
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
                'field' => (!is_null($pid) ? 'inputer' : 'nama'),
                'caption' => (!is_null($pid) ? __t('ditangani oleh') : __t('nama')),
                'align' => 'left'
            ),
            array(
                'field' => (!is_null($pid) ? 'tgl' : 'pukul_masuk'),
                'caption' => (!is_null($pid) ? __t('tanggal') : __t('tanggal masuk')),
                'width' => '25%',
                'align' => 'right'
            )
        );

        if(!is_null($pid)){
            $sql = $this->query->getSelect(
                array(),
                array('pengkajian'),
                array(
                    array('&&', "perawatan=" . $pid)
                ),
                'inputtime desc'
            );
        } else {
            $sql = $this->query->getSelect(
                array(),
                array('perawatan'),
                array(
                    array('&&', "pukul_keluar is null")
                ),
                'inputtime desc'
            );
        }
        $this->query->connect();
        $getit = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($getit->_numOfRows > 0){
            for($i=0; $i<$getit->_numOfRows; $i++){
                if(!is_null($pid)){
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
                    $result['data'][$i]['inputer'] = $getthis->fields['nama'];
                    $result['data'][$i]['goto'] = '/care/pengkajian/detail_form/' . $getit->fields['id'];
                } else {
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
                    $result['data'][$i]['nama'] = $getthis->fields['nama'] . ' (' . number_format(round($this->agecount_in_month(strtotime($getthis->fields['tgl_lahir']))/12, 1), 1, ',','.') . ' th)';
                    $result['data'][$i]['goto'] = '/care/perawatan/pengkajian/' . $getit->fields['id'];
                    }
                $result['data'][$i]['pukul_masuk'] = date('j-n-Y H:i:s', strtotime($getit->fields['pukul_masuk']));
                $getit->MoveNext();
            }
        }
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