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
 *  Created on Oct 4, 2009, 8:41:16 AM
 */

class paruConfig extends config
{
    var $rdbms = 'mysql';
    var $dbparu = array(
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
        'fremitus_raba' => 'select',
        'nyeri_tekan' => 'checkbox',
        'paru_kiri' => 'select',
        'paru_kanan' => 'select',
        'batas_paru_belakang_kiri' => 'select',
        'batas_paru_belakang_kanan' => 'select',
        'batas_paru_hepar' => 'select',
        'bunyi_pernafasan' => 'select',
        'bunyi_tambahan' => 'select'

    );

    var $fieldsisarray = array(
        'fremitus_raba','paru_kiri','paru_kanan','batas_paru_belakang_kiri','batas_paru_belakang_kanan','batas_paru_hepar','bunyi_pernafasan','bunyi_tambahan'
    );
    
    var $reftable = array(
        'fremitus_raba' => array('ref_paru_fremitus_raba','fremitus_raba'),
        'paru_kiri' => array('ref_paru_kiri', 'kiri'),
        'paru_kanan' => array('ref_paru_kanan', 'kanan'),
        'batas_paru_belakang_kiri' => array('ref_paru_belakang_kiri', 'belakang_kiri'),
        'batas_paru_belakang_kanan' => array('ref_paru_belakang_kanan', 'belakang_kanan'),
        'batas_paru_hepar' => array('ref_paru_hepar', 'hepar'),
        'bunyi_pernafasan' => array('ref_paru_bunyi_pernafasan', 'bunyi_pernafasan'),
        'bunyi_tambahan' => array('ref_paru_bunyi_tambahan', 'bunyi_tambahan')
    );
}