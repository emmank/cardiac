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
 *  Created on Oct 4, 2009, 1:15:47 PM
 */


class hearthConfig extends config
{
    var $rdbms = 'mysql';
    var $dbhearth = array(
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
        'inspection' => 'radio',
        'palpation' => 'checkbox',
        'percussion_top' => 'select',
        'percussion_bottom' => 'select',
        'percussion_left' => 'select',
        'percussion_right' => 'select',
        'bunyi_jantung' => 'text',
        'auscultation_sound' => 'checkbox',
        'localization' => 'select',
        'intencity' => 'select',
        'penjalaran' => 'select',
        'kind' => 'select',
        'quality' => 'select'
    );

    var $fieldsisarray = array(
        'inspection','palpation','percussion_top','percussion_bottom' ,'percussion_left','percussion_right','auscultation_sound','localization' ,'intencity' ,'penjalaran' ,'kind' ,'quality'
    );
    var $reftable = array(        
        'inspection' => array('ref_hearth_inspection','inspection'),
        'palpation' => array('ref_hearth_palpation','palpation'),
        'percussion_top' => array('ref_hearth_percussion_top','percussion_top'),
        'percussion_bottom' => array('ref_hearth_percussion_bottom','percussion_bottom') ,
        'percussion_left' => array('ref_hearth_percussion_left','percussion_left'),
        'percussion_right' => array('ref_hearth_percussion_right','percussion_right'),
        'auscultation_sound' => array('ref_hearth_auscultation_sound','auscultation_sound'),
        'localization' => array('ref_hearth_localization','localization') ,
        'intencity'  => array('ref_hearth_intencity','intencity'),
        'penjalaran' => array('ref_hearth_penjalaran','penjalaran') ,
        'kind'  => array('ref_hearth_auscultation_kind','auscultation_kind'),
        'quality' => array('ref_hearth_auscultation_quality','auscultation_quality')
    );
    var $table_scheme = array(
        'hearth' => array(
            'id' => array(
                'type' => 'int(11)',
                'null' => 0,
                'key' => 'pri',
                'default' => NULL,
                'extra' => ''
            ),
            'inspection' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'palpation' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'percussion_top' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'percussion_bottom' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'percussion_left' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'percussion_right' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'bunyi_jantung' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'auscultation_sound' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'localization' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'intencity' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'penjalaran' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'kind' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'quality' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            )
        )
    );
}