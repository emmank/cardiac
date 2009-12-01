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

class kesimpulanConfig extends config

{
    var $rdbms = 'mysql';
    var $dbkesimpulan = array(
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
        'patients' => 'hidden',
        'hasil_treadmill' => 'select',
        'respon_tekanan_darah' => 'select',
        'tingkat_kesegaran_jasmani' => 'select',
        'klasifikasi_fungsional' => 'select',
        'kapasitas_aerobik' => 'text'

    );
    var $fieldsisarray = array(
        'hasil_treadmill',
        'respon_tekanan_darah',
        'tingkat_kesegaran_jasmani',
        'klasifikasi_fungsional',
        'kapasitas_aerobik'
    );
    var $reftable = array(
        'hasil_treadmill' => array('ref_ekg_irama','irama'),
        'respon_tekanan_darah' => array('ref_fasekesimpulan_respon_jantung', 'respon_jantung'),
        'tingkat_kesegaran_jasmani' => array('ref_ekg_denyut_jantung', 'denyut_jantung'),
        'klasifikasi_fungsional' => array('ref_ekg_gelombangP', 'gelombangP'),
        'kapasitas_aerobik' => array('ref_ekg_intervalPR', 'intervalPR')
    );
    
    var $qrs_complex = array(
        'qrs_axis', 'qrs_durasi', 'qrs_konfigurasi_patologi', 'qrs_konfigurasi_r_s'
    );
    var $segment_st = array(
        'segmen_st_depresi', 'segmen_st_elevasi'
    );
}