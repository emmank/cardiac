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

class faseLatihanConfig extends config
{
    var $rdbms = 'mysql';
    var $dbfaseLatihan = array(
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
    var $faseLatihan = array (
        'fase_istirahat' => array (
            "tensi_berbaring_/_mmHg","tensi_berdiri_/_mmHg", "tensi_hiperventilasi_/_mmHg",
            "denyut_jantung_berbaring","denyut_jantung_berdiri","denyut_jantung_hiperventilasi",
            "ekg_berdiri","ekg_berbaring","ekg_hiperventilasi"
        ),
        'fase_latihan' => array (
            "protokol_bruce_stage", "rekaman_EKG"
        ),
        'fase_recovery' => array (
            
        )
    );
//    var $typeoffields = array(
//        'id' => 'hidden',
//        'inspections' => 'checkbox'
//
//    );

}