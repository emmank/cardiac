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

class holterConfig extends config
{
    var $rdbms = 'mysql';
    var $dbholter = array(
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
        'patients' => 'hidden',
        'tgl' => 'hidden',
        'the_average_HR' => 'text',
        'the_maximum_HR' => 'text',
        'the_minimum_HR' => 'text',
        'pause' => 'text',
        'segment_st_depresi' => 'select',        
        'segment_st_elevasi' => 'select',
        'gelombang_t' => 'radio',
        'VES' => 'text',
        'AES' => 'text',
        'SVT' => 'text',
        'VT' => 'text',
        'AF' => 'text',
        'heart_block_1_degree' => 'text',
        'heart_block_2_degree' => 'text',
        'heart_block_3_degree' => 'text',
        'inputer' => 'hidden',
        'inputtime' => 'hedden',
        'updated' => 'hedden'
    );

    var $fieldsisarray = array(
        'segment_st_depresi',
        'segment_st_elevasi',
        'gelombang_t',
        'VES',
        'AES' ,
        'SVT' ,
        'AF' ,
        'heart_block_2_degree' 
    );
    var $fieldsisarray2 = array(
        'VES',
        'AES' ,
        'SVT' ,
        'AF' ,
        'heart_block_2_degree'
    );
    
    var $fieldtype = array(
        'pause',
        'VES',
        'AES',
        'SVT',
        'VT',
        'AF' ,
        'heart_block_1_degree',
        'heart_block_2_degree' ,
        'heart_block_3_degree' 
    );
//    var $fieldtype = array(
//        'pause' => 'text',
//        'VES' => 'select',
//        'AES' => 'select',
//        'SVT' => 'select',
//        'VT' => 'text',
//        'AF' => 'select',
//        'heart_block_1_degree' => 'text',
//        'heart_block_2_degree' => 'select',
//        'heart_block_3_degree' => 'text'
//    );



    var $reftable = array(
        'segment_st_depresi' => array('ref_ekg_sandapan', 'sandapan'),
        'segment_st_elevasi' => array('ref_ekg_sandapan', 'sandapan'),
        'gelombang_t' => array('ref_ekg_sandapan', 'sandapan'),
        'VES'  => array('ref_holterref_VES', 'VES'),
        'AES' => array('ref_holterref_VES', 'VES'),
        'SVT'  => array('ref_holterref_SVT', 'SVT'),
        'AF'  => array('ref_holterref_AF', 'AF'),
        'heart_block_2_degree'  => array('ref_holterref_heartblock', 'heartblock')
    );
}