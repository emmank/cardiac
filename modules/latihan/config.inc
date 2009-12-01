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

class latihanConfig extends config

{
    var $rdbms = 'mysql';
    var $dblatihan = array(
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
        'protokol' => 'text',
        'tensi_sistolik' => 'text',
        'tensi_diastolik' => 'text',
        'respon_denyut_jantung' => 'select',
        'puncak_denyut_jantung' => 'select',
	'irama_dasar' => 'select',
        'gelombang_p' => 'select',
        'segment_st_konfigurasi' => 'select',
        'qrs_konfigurasi_rs' => 'select',
        'segment_st_depresi' => 'select',
        'segment_st_elevasi' => 'select',
        'perubahan_gelombang_r' => 'select',
        'dihentikan_karena' => 'select',
        'gelombang_t' => 'select',
        'q_interval' => 'select'
    );
    var $fieldsisarray = array(
        'irama_dasar',
        'respon_denyut_jantung',
        'puncak_denyut_jantung',
        'gelombang_p',
        'interval_pr',
        'qrs_axis',
        'qrs_durasi',
        'segment_st_konfigurasi',
        'qrs_konfigurasi_rs',
        'segment_st_depresi' ,
        'segment_st_elevasi' ,
        'perubahan_gelombang_r' ,
        'dihentikan_karena' ,
        'gelombang_t',
        'q_interval'
    );
    var $reftable = array(
        'irama_dasar' => array('ref_ekg_irama','irama'),
        'respon_denyut_jantung' => array('ref_faseLatihan_respon_jantung', 'respon_jantung'),
        'puncak_denyut_jantung' => array('ref_ekg_denyut_jantung', 'denyut_jantung'),
        'gelombang_p' => array('ref_ekg_gelombangP', 'gelombangP'),
        'interval_pr' => array('ref_ekg_intervalPR', 'intervalPR'),
        'qrs_axis' => array('ref_ekgQrs_axis', 'axis'),
        'qrs_durasi' => array('ref_ekgQrs_durasi', 'durasi'),
        'segment_st_konfigurasi' => array('ref_ekg_sandapan', 'sandapan'),
        'qrs_konfigurasi_rs' => array('ref_ekgQrs_RlbS', 'RlbS'),
        'segment_st_depresi' => array('ref_ekg_sandapan', 'sandapan'),
        'segment_st_elevasi' => array('ref_ekg_sandapan', 'sandapan'),
        'perubahan_gelombang_r' => array('ref_faseLatihan_perubahan_gelombang', 'perubahan_gelombang'),
        'dihentikan_karena' => array('ref_faseLatihan_dihentikan', 'dihentikan'),
        'gelombang_t' => array('ref_ekg_sandapan', 'sandapan'),
        'q_interval' => array('ref_ekg_q_interval', 'q_interval')
    );
    var $qrs_complex = array(
        'qrs_axis', 'qrs_durasi', 'qrs_konfigurasi_patologi', 'qrs_konfigurasi_r_s'
    );
    var $segment_st = array(
        'segmen_st_depresi', 'segmen_st_elevasi'
    );
}