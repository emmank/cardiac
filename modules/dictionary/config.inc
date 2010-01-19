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
 *  Created on Dec 19, 2009, 8:52:39 PM
 */

class dictionaryConfig extends config
{
    var $rdbms = 'mysql';
    var $rows_of_shows = 100;
    var $table_scheme = array(
        'translations' => array(
            'strkey' => array(
                'type' => 'varchar(255)',
                'null' => 0,
                'key' => 'pri',
                'default' => NULL,
                'extra' => ''
            ),
            'indonesia' => array(
                'type' => 'int(11)',
                'null' => 0,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            )
        ),
        'dumptr' => array(
            'id' => array(
                'type' => 'varchar(255)',
                'null' => 0,
                'key' => 'pri',
                'default' => NULL,
                'extra' => ''
            )
        ),
        'isearch_translations' => array(
            'strkey' => array(
                'type' => 'varchar(255)',
                'null' => 0,
                'key' => 'pri',
                'default' => NULL,
                'extra' => ''
            ),
            'phrase' => array(
                'type' => 'varchar(255)',
                'null' => 0,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            )
        )
    );
}