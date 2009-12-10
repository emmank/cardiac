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
 *  perawatanclass.php
 *  
 *  Created on Oct 1, 2009, 1:12:45 PM
 */

require_once MODULES_DIR . DS . 'perawatan' . DS . 'config.inc';

class perawatanModule extends mainModule
{
    var $title = 'perawatan';
    var $description = 'Manajemen data digital pasien perawatan';

    function menu(){
        $items['perawatan_register'] = array(
            'title' => __t('Registrasi'),
            'description' => __t('Registrasi Pendaftaran Pasien Rawat Inap'),
            'path' => '/care/register',
            'exec' => 'form',
            'weight' => '0',
            'user_required' => 'perawatan'
        );
        $items['perawatan_daftar'] = array(
            'title' => __t('Daftar Pasien'),
            'description' => __t('Daftar Pasien Rawat Inap'),
            'path' => '/care/list',
            'exec' => 'view',
            'weight' => '0',
            'user_required' => 'users'
        );
        $items['perawatan_search'] = array(
            'title' => __t('Cari Pasien'),
            'description' => __t('Cari Pasien Rawat Inap'),
            'path' => '/care/search',
            'exec' => 'search',
            'weight' => '0',
            'user_required' => 'users'
        );
        return $items;
    }

    function view(){
        $this->sync_scheme('perawatan', $this->query);
        $this->sync_scheme('ruang', $this->query);
        return $this->__get_view();
    }

    function __get_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('daftar beberapa pasien');
        $result['description'] = __t('daftar beberapa pasien terakhir yang telah diperiksa');
        $result['addmenu']['#add'] = array(
            'title' => __t('register'),
            'action' => '/care/register',
            'position' => 'top',
            'user_required' => 'users'
        );
        $result['addmenu']['#search'] = array(
            'title' => __t('search'),
            'action' => '/care/search',
            'position' => 'top',
            'user_required' => 'users'
        );
        $result['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => 'nama',
                'caption' => __t('nama'),
                'align' => 'left'
            ),
            array(
                'field' => 'tgl_lahir',
                'caption' => __t('usia'),
                'width' => '10%',
                'align' => 'right'
            ),
            array(
                'field' => 'pukul_masuk',
                'caption' => __t('tanggal masuk'),
                'width' => '25%',
                'align' => 'right'
            )
        );

        $sql = $this->query->getSelect(
            array(),
            array('perawatan'),
            array(
                array('&&', "pukul_keluar is null")
            ),
            'inputtime desc',
            '0,10'
        ); unset($where);
        $this->query->connect();
        $getit = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($getit->_numOfRows > 0){
            for($i=0; $i<$getit->_numOfRows; $i++){
                $sql = $this->query->getSelect(
                    array('id', 'nama', 'tgl_lahir', 'pukul_masuk'),
                    array('patients'),
                    array(
                        array('&&', "id=" . $getit->fields['patients'])
                    )
                );
                $this->query->connect();
                $getthis = $this->query->conn->Execute($sql); unset($sql);
                $this->query->close();
                $result['data'][$i]['nama'] = $getthis->fields['nama'];
                $result['data'][$i]['tgl_lahir'] = number_format(round($this->agecount_in_month(strtotime($getthis->fields['tgl_lahir']))/12, 1), 1, ',','.') . ' th';
                $result['data'][$i]['goto'] = '/user/perawatan/detail_form/' . $getit->fields['id'];
                $result['data'][$i]['pukul_masuk'] = date('j-n-Y H:i:s', strtotime($getit->fields['pukul_masuk']));
                $getit->MoveNext();
            }
        }
        return $result;
    }

    function form(){
        
    }

}