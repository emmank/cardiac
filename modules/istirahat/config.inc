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
 *  config.php
 *  
 *  Created on Oct 3, 2009, 4:31:28 PM
 */

class istirahatConfig extends config
{
    var $rdbms = 'mysql';
    var $dbistirahat = array(
        'name' => 'layanan_kesehatan',
        'prefix' => '',
        'suffix' => '',
        'tbprefix' => '',
        'tbsuffix' => '',
        'host' => 'localhost',
        'user' => 'root',
        'passwd' => 'emmank'
    );
    var $hiddenfields = array(
        'id'
    );
    var $typeoffields = array(
        'id' => 'hidden',
        'tall' => 'text',
        'weight' => 'text',
        'tension' => 'text',
        'risk_factor' => 'checkbox',
        'catched' => 'datetime',
        'nutrient' => 'select',
        'main_soreness' => 'select',
        'ilness_history' => 'checkbox'
    );
    var $fieldsisarray = array(
        'nutrient', 'main_soreness', 'risk_factor', 'ilness_history'
    );
    var $reftable = array(
        'risk_factor' => array('ref_present_risk_factor', 'risk_factor'),
        'nutrient' => array('ref_present_nutrient', 'nutrient'),
        'main_soreness' => array('ref_present_soreness', 'soreness'),
        'ilness_history' => array('ref_present_illness_history', 'illness_history')
    );
}