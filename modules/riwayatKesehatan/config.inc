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
 *  Created on Dec 17, 2009, 8:38:00 AM
 */

class riwayatKesehatanConfig extends config
{
    var $rdbms = 'mysql';
    var $dbriwayatKesehatan = array(
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
        'id', 'inputer', 'inputtime', 'updated', 'perawatan'
    );
    var $typeoffields = array(
        'id' => 'hidden',
        'perawatan' => 'hidden',
        'tgl' => 'datetime',
        'cara_masuk' => 'text',
        'keluhan' => 'text',
        'pernah_diopname' => 'text',
        'pernah_berobat' => 'checkbox',
        'berat_sebelum_sakit' => 'text',
        'berat_sekarang' => 'text',
        'pernah_dioperasi' => 'checkbox',
        'hari_pasca_operasi' => 'text',
        'kesadaran' => 'text',
        'pengertian_klien' => 'checkbox',
        'r_haid_menarche' => 'text',
        'r_haid_dys_menarche' => 'text',
        'r_haid_siklus' => 'text',
        'r_haid_lamanya' => 'text',
        'r_haid_alat_kb' => 'text',
        'r_hamil_hamil' => 'text',
        'r_hamil_hpht' => 'date',
        'r_hamil_taksiran_pantas' => 'text',
        'r_hamil_usia' => 'text',
        'inputer' => 'system',
        'inputtime' => 'system',
        'updated' => 'system'
    );
    var $fieldsisarray = array(

    );
    var $reftable = array(
        'risk_factor' => array('ref_present_risk_factor', 'risk_factor', 'id'),
    );

    var $table_scheme = array(
        'riwayat_kesehatan' => array(
            'id' => array(
                'type' => 'int(11)',
                'null' => 0,
                'key' => 'pri',
                'default' => NULL,
                'extra' => ''
            ),
            'perawatan' => array(
                'type' => 'int(11)',
                'null' => 0,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'tgl' => array(
                'type' => 'datetime',
                'null' => 0,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'cara_masuk' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'keluhan' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'pernah_diopname' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'pernah_berobat' => array(
                'type' => 'tinyint(1)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'berat_sebelum_sakit' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'berat_sekarang' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'pernah_dioperasi' => array(
                'type' => 'tinyint(1)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'hari_pasca_operasi' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'kesadaran' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'pengertian_klien' => array(
                'type' => 'tinyint(1)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'r_haid_menarche' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'r_haid_dys_menarche' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'r_haid_siklus' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'r_haid_lamanya' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'r_haid_alat_kb' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'r_hamil_hamil' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'r_hamil_hpht' => array(
                'type' => 'date',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'r_hamil_taksiran_pantas' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'r_hamil_usia' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'inputer' => array(
                'type' => 'int(11)',
                'null' => 0,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'inputtime' => array(
                'type' => 'datetime',
                'null' => 0,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'updated' => array(
                'type' => 'varchar(100)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            )
        )
    );
}