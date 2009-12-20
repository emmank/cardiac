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

class pengkajianConfig extends config
{
    var $rdbms = 'mysql';
    var $dbpengkajian = array(
        'name' => 'layanan_kesehatan',
        'prefix' => '',
        'suffix' => '',
        'tbprefix' => '',
        'tbsuffix' => '',
        'host' => 'localhost',
        'user' => 'root',
        'passwd' => 'emmank'
    );
    var $module_included = array(
        'riwayatKesehatan',
        'alergi',
        'kondisi',
        'nutrisi',
        'cairan',
        'aktivitas',
        'eliminasi',
        'polatidur',
        'psikoSosial',
        'cairanAktivitas'
    );
    var $module_tableuse = array(
        'riwayatKesehatan' => 'riwayat_kesehatan',
        'alergi' => 'alergi',
        'kondisi' => 'kondisi',
        'nutrisi' => 'nutrisi',
        'cairan' => 'cairan',
        'aktivitas' => 'aktivitas',
        'eliminasi' => 'eliminasi',
        'polatidur' => 'polatidur',
        'psikoSosial' => 'psikoSosial',
        'cairanAktivitas' => 'cairan_aktivitas'
    );
}