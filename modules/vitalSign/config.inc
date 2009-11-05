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
 *  Created on Oct 3, 2009, 8:37:06 PM
 */

class vitalSignConfig extends config
{
    var $rdbms = 'mysql';
    var $dbvitalSign = array(
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
        'tensi_systole' => 'text',
        'tensi_diastole' => 'text',
        'denyut_nadi' => 'text',
        'pulse_rythm' => 'select',
        'pernafasan' => 'text',
        'type' => 'select',
        'suhu_axilla' => 'text',
        'suhu_oral' => 'text',
        'suhu_rectal' => 'text',
        'kesadaran' => 'select'
    );
    var $fieldsisarray = array(
        'pulse_rythm', 'type', 'kesadaran'
    );
    var $reftable = array(
        'pulse_rythm' => array('ref_vitalsign_pulse_rythm', 'pulse_rythm'),
        'type' => array('ref_vitalsign_type', 'type'),
        'kesadaran' => array('ref_vitalsign_kesadaran', 'kesadaran')
        //'ilness_history' => array('ref_present_illness_history', 'illness_history')
    );

}