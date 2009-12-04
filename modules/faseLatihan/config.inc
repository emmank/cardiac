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
 
    var $table_scheme = array(
        'latihan' => array(
            'id' => array(
                'type' => 'int(11)',
                'null' => 0,
                'key' => 'pri',
                'default' => NULL,
                'extra' => ''
            ),
            'protokol' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'rekaman_ekg' => array(
                'type' => 'varchar(200)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'rekaman_st_depresi' => array(
                'type' => 'varchar(200)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'rekaman_st_elevasi' => array(
                'type' => 'varchar(200)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'rekaman_st_konfigurasi' => array(
                'type' => 'varchar(200)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'aritmia' => array(
                'type' => 'varchar(200)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'perubahan_gelombang_r' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'lain_lain' => array(
                'type' => 'varchar(200)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'dihentikan_karena' => array(
                'type' => 'varchar(200)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'respon_denyut_jantung' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'puncak_denyut_jantung' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'lainlain_denyut_jantung' => array(
                'type' => 'varchar(200)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'respon_tekanan_darah' => array(
                'type' => 'tinyint(1)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'respon_hipertensi' => array(
                'type' => 'varchar(200)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'respon_hipertensip' => array(
                'type' => 'varchar(200)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'respon_menetap' => array(
                'type' => 'tinyint(1)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'tekanan_darah_puncak' => array(
                'type' => 'varchar(200)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            )
        )
    );
}