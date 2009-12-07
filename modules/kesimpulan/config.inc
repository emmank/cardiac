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

class kesimpulanConfig extends config

{
    var $rdbms = 'mysql';
    var $dbkesimpulan = array(
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
        'uljb_jantung_koroner' => 'select',
        'respons_tekanan_darah' => 'select',
        'tingkat_kesegaran_jasmani' => 'select',
        'klasifikasi_fungsional' => 'select',
        'kapasitas_aerobik' => 'text',
        'kesimpulan_lainlain' => 'text'
    );
    var $fieldsisarray = array(
        'uljb_jantung_koroner',
        'respons_tekanan_darah',
        'tingkat_kesegaran_jasmani',
        'klasifikasi_fungsional'
    );
    var $reftable = array(
        'uljb_jantung_koroner' => array('ref_threadKesimpulanSaran_Ulib','Ulib'),
        'respons_tekanan_darah' => array('ref_threadKesimpulanSaran_tekananDarah', 'tekananDarah'),
        'tingkat_kesegaran_jasmani' => array('ref_threadKesimpulanSaran_kesegaran', 'kesegaran'),
        'klasifikasi_fungsional' => array('ref_threadKesimpulanSaran_fungsional', 'fungsional')
    );
    var $table_scheme = array(
        'kesimpulan' => array(
            'id' => array(
                'type' => 'int(11)',
                'null' => 0,
                'key' => 'pri',
                'default' => NULL,
                'extra' => ''
            ),
            'uljb_jantung_koroner' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'respons_tekanan_darah' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'tingkat_kesegaran_jasmani' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'klasifikasi_fungsional' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'kapasitas_aerobik' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'kesimpulan_lainlain' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            )
        )
    );
}