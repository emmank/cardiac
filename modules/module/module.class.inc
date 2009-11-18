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
 *  moduleclass.php
 *  
 *  Created on Nov 18, 2009, 1:18:19 AM
 */

require_once MODULES_DIR . DS . 'module' . DS . 'config.inc';

class moduleModule extends mainModule
{
    var $title = 'module module';
    var $description = '';

    function menu(){
        $items['module_form'] = array(
            'title' => __t('module_form'),
            'description' => __t('listed module form'),
            'path' => '/admin/module/form',
            'exec' => 'form',
            'weight' => '0',
            'user_required' => 'admin'
        );
        return $items;
    }

    function form(){
        $result = array();
        $result['module'] = array(
            '#type' => 'fieldset',
            '#id' => 'module',
            '#title' => __t('list of modules'),
            '#description' => __t('Get Active or Inactive Listed Modules'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#weight' => -3,
            '#action' => '/admin/module/form_submit',
        );
        $result['module']['module']['#type'] = 'checkbox';
        $lists = __get_file_lists(MODULES_DIR);
        $actives = array();
        $sql = $this->sysquery->getSelect(
            array('module'),
            array('modules'),
            NULL,
            'module'
        );
        $this->sysquery->connect();
        $getit = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        if($getit->_numOfRows > 0){
            for($i=0; $i<$getit->_nuOfRows; $i++){
                $actives[] = $getit->fields['module'];
                $getit->MoveNext();
            }
        } unset($getit);
        $result['module']['module']['#value'] = $actives;
        $result['module']['module']['#title'] = '';
        unset($actives);
        $options = array();
        foreach($lists as $value){
            $this->__include_module($value);
            $dumpopt = __t($this->{$value . '_exec'}->title);
            $dumpopt .= ' => ' . __t($this->{$value . '_exec'}->description);
            $options[$value] = $dumpopt;
            unset($dumpopt);
        }
        $result['module']['module']['#option'] = $options;
        return($result);
    }
}