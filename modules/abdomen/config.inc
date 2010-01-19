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
 *  Created on Oct 5, 2009, 11:28:54 AM
 */


class abdomenConfig extends config
{
    var $rdbms = 'mysql';
    var $dbabdomen = array(
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

    
    var $heparfield_types = array(
        'id' => 'hidden',
        'hepar' => 'text',
        'type' => 'select'
    );
    var $liverfield_types = array(
        'id' => 'hidden',
        'liver' => 'text',
        'type' => 'select'
    );
    var $ginjalfield_types = array(
        'id' => 'hidden',
        'ginjal' => 'text',
        'type' => 'select'
    );
    var $inspeksi_ginjalfield_types = array(
        'id' => 'hidden',
        'inspeksi_ginjal' => 'text',
        'type' => 'select'
    );

    var $typeoffields = array(
        'id' => 'hidden',
        'relief' => 'select',
        'center' => 'select',
        'inspeksi_kulit' => 'checkbox',
        'gerakan_dinding_perut' => 'select',
        'palpasi_hepar' => 'radio',
        'palpasi_hepar_derajat_pembesaran' => 'text',
        'palpasi_hepar_konsistensi' => 'text',
        'palpasi_hepar_permukaan' => 'text',
        'palpasi_hepar_tepi' => 'text',
        'palpasi_hepar_nyeri_tekan' => 'checkbox',
        'palpasi_liver' => 'radio',
        'palpasi_liver_derajat_pembesaran' => 'text',
        'palpasi_liver_konsistensi' => 'text',
        'palpasi_liver_permukaan' => 'text',
        'palpasi_liver_tepi' => 'text',
        'palpasi_liver_nyeri_tekan' => 'checkbox',
        'palpasi_ginjal' => 'radio',
        'inspeksi_ginjal' => 'checkbox',
        'perkusi' => 'checkbox',
        'auscultation' => 'checkbox',
        'peristaltik_usus' => 'select'

    );

    var $fieldsisarray = array(
        'relief','center','inspeksi_kulit','gerakan_dinding_perut','palpasi_hepar','palpasi_liver','palpasi_ginjal','inspeksi_ginjal',
        'inspeksi_ginjal','perkusi','auscultation','peristaltik_usus'
    );
    var $reftable = array(
        'relief' => array('ref_abdomen_relief','relief'),
        'center' => array('ref_abdomen_center', 'center'),
        'inspeksi_kulit' => array('ref_abdomen_skin', 'skin'),
        'gerakan_dinding_perut' => array('ref_abdomen_gerakan_dinding_perut', 'gerakan_dinding_perut'),
        'palpasi_hepar' => array('ref_abdomen_hepar', 'hepar'),
        'palpasi_liver' => array('ref_abdomen_liver', 'liver'),
        'palpasi_ginjal' => array('ref_abdomen_ginjal', 'ginjal'),
        'inspeksi_ginjal' => array('ref_abdomen_inspeksi_ginjal', 'inspeksi_ginjal'),
        'perkusi' => array('ref_abdomen_perkusi', 'perkusi'),
        'auscultation' => array('ref_abdomen_auscultation', 'auscultation'),
        'peristaltik_usus' => array('ref_abdomen_peristaltik_usus', 'peristaltik_usus')
    );
    var $table_scheme = array(
        'abdomen' => array(
            'id' => array(
                'type' => 'int(11)',
                'null' => 0,
                'key' => 'pri',
                'default' => NULL,
                'extra' => ''
            ),
            'relief' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'center' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'inspeksi_kulit' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'gerakan_dinding_perut' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'palpasi_hepar' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'palpasi_hepar_derajat_pembesaran' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'palpasi_hepar_konsistensi' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'palpasi_hepar_permukaan' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'palpasi_hepar_tepi' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'palpasi_hepar_nyeri_tekan' => array(
                'type' => 'tinyint(1)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'palpasi_liver' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'palpasi_liver_derajat_pembesaran' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'palpasi_liver_konsistensi' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'palpasi_liver_permukaan' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'palpasi_liver_tepi' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'palpasi_liver_nyeri_tekan' => array(
                'type' => 'tinyint(1)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'palpasi_ginjal' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'perkusi' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'peristaltik_usus' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            )
        )
    );
}