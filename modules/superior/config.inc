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

class superiorConfig extends config
{
    var $rdbms = 'mysql';
    var $dbsuperior = array(
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
    var $fields_form_type = array(
        'id' => 'hidden',
        'artery_brachialis' => 'select',
        'artery_radialis' => 'select',
        'artery_ulmaris' => 'select',
        'vena_brachiacephalic' => 'select',
        'vena_subclavicula' => 'select',
        'vena_axillaris' => 'select',
        'vena_cephelic' => 'select',
        'vena_brachial' => 'select',
        'vena_cubitas' => 'select',
        'vena_radial' => 'select',
        'vena_ulnor' => 'select'
    );

    var $fieldsisarray = array(
        'artery_brachialis',
        'artery_radialis',
        'artery_ulmaris' ,
        'vena_brachiacephalic' ,
        'vena_subclavicula',
        'vena_axillaris',
        'vena_cephelic',
        'vena_brachial',
        'vena_cubitas',
        'vena_radial',
        'vena_ulnor'
    );

    var $reftable = array(
        'artery_brachialis' => array('ref_kateterisasiref_steunosis','steunosis'),
        'artery_radialis' => array('ref_kateterisasiref_steunosis','steunosis'),
        'artery_ulmaris' => array('ref_kateterisasiref_steunosis','steunosis'),
        'vena_brachiacephalic' => array('ref_kateterisasiref_steunosis','steunosis'),
        'vena_subclavicula' => array('ref_kateterisasiref_steunosis','steunosis'),
        'vena_axillaris' => array('ref_kateterisasiref_steunosis','steunosis'),
        'vena_cephelic' => array('ref_kateterisasiref_steunosis','steunosis'),
        'vena_brachial' => array('ref_kateterisasiref_steunosis','steunosis'),
        'vena_cubitas' => array('ref_kateterisasiref_steunosis','steunosis'),
        'vena_radial' => array('ref_kateterisasiref_steunosis','steunosis'),
        'vena_ulnor' => array('ref_kateterisasiref_steunosis','steunosis')
    );
    var $qrs_complex = array(
        'qrs_axis', 'qrs_durasi', 'qrs_konfigurasi_patologi', 'qrs_konfigurasi_r_s'
    );
    var $segment_st = array(
        'segmen_st_depresi', 'segmen_st_elevasi'
    );
    var $table_scheme = array(
        'superior' => array(
            'id' => array(
                'type' => 'int(11)',
                'null' => 0,
                'key' => 'pri',
                'default' => NULL,
                'extra' => ''
            ),
            'artery_brachialis' => array(
                'type' => 'varchar(150)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'artery_radialis' => array(
                'type' => 'varchar(150)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'artery_ulmaris' => array(
                'type' => 'varchar(150)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'vena_brachiacephalic' => array(
                'type' => 'varchar(150)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'vena_subclavicula' => array(
                'type' => 'varchar(150)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'vena_axillaris' => array(
                'type' => 'varchar(150)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'vena_cephelic' => array(
                'type' => 'varchar(150)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'vena_brachial' => array(
                'type' => 'varchar(150)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'vena_cubitas' => array(
                'type' => 'varchar(150)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'vena_radial' => array(
                'type' => 'varchar(150)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'vena_ulnor' => array(
                'type' => 'varchar(150)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            )
        )
    );
}