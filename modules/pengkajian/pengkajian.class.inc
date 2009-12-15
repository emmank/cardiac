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
            'path' => '/care/pengkajian',
            'exec' => '__view',
            'weight' => 5,
            'user_required' => NULL
        );
       return $items;
    }

    function __head_page($id){
        $this->sync_scheme('pengkajian', $this->query);
        $result = array();
        $sql = $this->query->getSelect(
            array(),
            array('perawatan'),
            array(
                array('&&', "id=" . $id)
            )
        );
        $this->query->connect();
        $getit = $this->query->conn->Execute($qsl); unset($sql);
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
            }
        }
        return $result;
    }

    function __view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Gizi');
        $result['description'] = __t('Referensi isian gizi yang dipakai untuk menilai kadar suatu keadaan terkini pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/nutrient/form',
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
                'field' => 'nutrient',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_present_nutrient'),
            NULL,
            'nutrient'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['nutrient'] = ucwords($query->fields['nutrient']);
                $result['data'][$i]['goto'] = '/reference/nutrient/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

}