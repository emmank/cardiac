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
 *  Created on Oct 4, 2009, 5:15:09 AM
 */

class eyeConfig extends config
{
    var $rdbms = 'mysql';
    var $dbeye = array(
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
        'inspections' => 'checkbox',
        'tekanan_bola_mata' => 'select',
        'kelopak_mata' => 'select',
        'konjuctifa' => 'select',
        'cornea' => 'select',
        'pupil' => 'select'
    );
    var $fieldsisarray = array(
        'inspections','tekanan_bola_mata','kelopak_mata','kelopak_mata','konjuctifa','cornea','pupil'
    );
    var $reftable = array(
        'inspections' => array('ref_eye_inspections','inspections'),
        'tekanan_bola_mata' => array('ref_eye_tekanan_bola_mata', 'tekanan_bola_mata'),
        'kelopak_mata' => array('ref_eye_kelopak_mata', 'kelopak_mata'),
        'konjuctifa' => array('ref_eye_konjunctifa', 'konjunctifa'),
        'cornea' => array('ref_eye_cornea', 'cornea'),
        'pupil' => array('ref_eye_pupil','pupil')
    );

    var $table_scheme = array(
        'eye' => array(
            'id' => array(
                'type' => 'int(11)',
                'null' => 0,
                'key' => 'pri',
                'default' => NULL,
                'extra' => ''
            ),
            'inspections' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'tekanan_bola_mata' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'kelopak_mata' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'konjuctifa' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'cornea' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'pupil' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => '0',
                'extra' => ''
            )
        )
    );
}