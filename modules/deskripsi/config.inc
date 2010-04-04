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
 *  Created on Oct 1, 2009, 1:10:09 PM
 */

class deskripsiConfig extends config
{
    var $rdbms = 'mysql';
    var $dbdeskripsi = array(
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
        'id', 'id_pasien'
    );
    var $fields_form_type_lv = array(
        'id' => 'hidden',
        'wall' => 'textarea',
        'conclusion' => 'textarea',
    );

    var $fieldsisarray = array(
//        'LCA_LM',
//        'LAD' ,
//        'D1' ,
//        'D2',
//        'Cx' ,
//        'OM1' ,
//        'OM2',
//        'PL' ,
//        'RCA',
//        'RV',
//        'AM' ,
//        'PD' ,
//        'LV_branch',
//        'komentar',
//        'anjuran'
    );

    var $reftable = array(
//        'LCA_LM' => array('ref_kateterisasiref_steunosis','steunosis'),
//        'LAD' => array('ref_kateterisasiref_steunosis','steunosis'),
//        'D1' => array('ref_kateterisasiref_steunosis','steunosis'),
//        'D2' => array('ref_kateterisasiref_steunosis','steunosis'),
//        'Cx' => array('ref_kateterisasiref_steunosis','steunosis'),
//        'OM1' => array('ref_kateterisasiref_steunosis','steunosis'),
//        'OM2' => array('ref_kateterisasiref_steunosis','steunosis'),
//        'PL' => array('ref_kateterisasiref_steunosis','steunosis'),
//        'RCA' => array('ref_kateterisasiref_steunosis','steunosis'),
//        'RV' => array('ref_kateterisasiref_steunosis','steunosis'),
//        'AM' => array('ref_kateterisasiref_steunosis','steunosis'),
//        'PD' => array('ref_kateterisasiref_steunosis','steunosis'),
//        'LV_branch' => array('ref_kateterisasiref_steunosis','steunosis'),
//        'komentar' => array('ref_kateterisasiref_komentar','komentar'),
//        'anjuran' => array('ref_kateterisasiref_anjuran', 'anjuran')
    );
    var $qrs_complex = array(
        'qrs_axis', 'qrs_durasi', 'qrs_konfigurasi_patologi', 'qrs_konfigurasi_r_s'
    );
    var $segment_st = array(
        'segmen_st_depresi', 'segmen_st_elevasi'
    );
    var $table_scheme = array(
        'deskripsi' => array(
            'id' => array(
                'type' => 'int(11)',
                'null' => 0,
                'key' => 'pri',
                'default' => NULL,
                'extra' => ''
            ),
            'wall' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'conclusion' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
        )
    );
}