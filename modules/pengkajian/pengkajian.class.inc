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
            }
        }
        return $result;
    }

    function view(){
        if(isset($_POST['id'])){
            $id = $_POST['id'];
        } else {
            $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
            if(count($dump) > 3){
                $id = $dump[3];
            }
        }
        $result['perawatan'] = array(
            '#type' => 'special',
            '#id' => 'perawatan',
            '#title' => __t('perawatan'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/user/perawatan/form' . ($this->formhabit == 'readonly' ? '/edit_' . $vcache['id'] : '_submit'),
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE,
            '#formtpl' => MODULES_DIR . DS . 'perawatan' . DS . 'perawatan.tpl',
            '#addmenu' => array(
                '#addmenu' => array(
                    'title' => __t('medical record'),
                    'action' => '/user/patient/medical_record/' . $vcache['patients'],
                    'position' => 'top',
                    'class' => 'button',
                    'methode' => 'choose',
                    'options' => $addmenuopts,
                    'filter' => 'bagian'
                )
            ),
            '#patientinfo' => $this->__head_page($id)
        ); unset($addmenuopts);
        return $result;
    }

}