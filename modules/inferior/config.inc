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

class inferiorConfig extends config
{
    var $rdbms = 'mysql';
    var $dbinferior = array(
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
        'artery_fermoralis_communis' => 'select',
        'artery_fermoralis_profunde' => 'select',
        'artery_fermoralis_superficial' => 'select',
        'artery_paplitca' => 'select',
        'artery_tibalin_arterior' => 'select',
        'artery_tibalin_rasterior' => 'select',
        'artery_aorsalin_pedia' => 'select',
        'vena' => 'select'
    );

    var $fieldsisarray = array(
        'artery_fermoralis_communis',
        'artery_fermoralis_profunde' ,
        'artery_fermoralis_superficial',
        'artery_paplitca',
        'artery_tibalin_arterior',
        'artery_tibalin_rasterior',
        'artery_aorsalin_pedia',
        'vena'
    );

    var $reftable = array(
        'artery_fermoralis_communis' => array('ref_kateterisasiref_steunosis','steunosis'),
        'artery_fermoralis_profunde' => array('ref_kateterisasiref_steunosis','steunosis'),
        'artery_fermoralis_superficial' => array('ref_kateterisasiref_steunosis','steunosis'),
        'artery_paplitca' => array('ref_kateterisasiref_steunosis','steunosis'),
        'artery_tibalin_arterior' => array('ref_kateterisasiref_steunosis','steunosis'),
        'artery_tibalin_rasterior' => array('ref_kateterisasiref_steunosis','steunosis'),
        'artery_aorsalin_pedia' => array('ref_kateterisasiref_steunosis','steunosis'),
        'vena' => array('ref_kateterisasiref_steunosis','steunosis')
    );
    var $qrs_complex = array(
        'qrs_axis', 'qrs_durasi', 'qrs_konfigurasi_patologi', 'qrs_konfigurasi_r_s'
    );
    var $segment_st = array(
        'segmen_st_depresi', 'segmen_st_elevasi'
    );
    var $table_scheme = array(
        'inferior' => array(
            'id' => array(
                'type' => 'int(11)',
                'null' => 0,
                'key' => 'pri',
                'default' => NULL,
                'extra' => ''
            ),
            'artery_fermoralis_communis' => array(
                'type' => 'varchar(150)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'artery_fermoralis_profunde' => array(
                'type' => 'varchar(150)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'artery_fermoralis_superficial' => array(
                'type' => 'varchar(150)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'artery_paplitca' => array(
                'type' => 'varchar(150)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'artery_tibalin_arterior' => array(
                'type' => 'varchar(150)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'artery_tibalin_rasterior' => array(
                'type' => 'varchar(150)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'artery_aorsalin_pedia' => array(
                'type' => 'varchar(150)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'vena' => array(
                'type' => 'varchar(150)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            )
        )
    );
}