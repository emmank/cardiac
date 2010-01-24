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

class ekguploadConfig extends config
{
    var $rdbms = 'mysql';
    var $dbekgupload = array(
        'name' => 'layanan_kesehatan',
        'prefix' => '',
        'suffix' => '',
        'tbprefix' => '',
        'tbsuffix' => '',
        'host' => 'localhost',
        'user' => 'root',
        'passwd' => 'emmank'
    );
    var $ekgdata_dir = 'file/katdata';
//    var $source_server = 'www.cardiac.com';
//    var $source_path = 'home/herman/www/ekg_data';
//    var $source_jpg = 'home/herman/www/ekg_data/CPT_DATA/';
    var $filedata_extension = 'jpg';
    var $hiddenfields = array(
        'id', 'id_pasien'
    );
    var $fields_form_type = array(
        'id' => 'hidden',
        'patients' => 'hidden',
        'tgl' => 'hidden',
        'uploader' => 'hidden',
        'inputer' => 'hidden',
        'inputtime' => 'hidden',
        'updated' => 'hidden'
    );

    var $fieldsisarray = array(
//        'irama_dasar',
//        'denyut_jantung',
//        'gelombang_p',
//        'interval_pr',
//        'qrs_axis',
//        'qrs_durasi',
//        'qrs_konfigurasi_patologi',
//        'qrs_konfigurasi_r_s',
//        'segmen_st_depresi' ,
//        'segmen_st_elevasi' ,
//        'gelombang_t',
//        'q_interval'
    );

//    var $reftable = array(
//        'irama_dasar' => array('ref_ekg_irama','irama'),
//        'denyut_jantung' => array('ref_ekg_denyut_jantung', 'denyut_jantung'),
//        'gelombang_p' => array('ref_ekg_gelombangP', 'gelombangP'),
//        'interval_pr' => array('ref_ekg_intervalPR', 'intervalPR'),
//        'qrs_axis' => array('ref_ekgQrs_axis', 'axis'),
//        'qrs_durasi' => array('ref_ekgQrs_durasi', 'durasi'),
//        'qrs_konfigurasi_patologi' => array('ref_ekg_sandapan', 'sandapan'),
//        'qrs_konfigurasi_r_s' => array('ref_ekgQrs_RlbS', 'RlbS'),
//        'segmen_st_depresi' => array('ref_ekg_sandapan', 'sandapan'),
//        'segmen_st_elevasi' => array('ref_ekg_sandapan', 'sandapan'),
//        'gelombang_t' => array('ref_ekg_sandapan', 'sandapan'),
//        'q_interval' => array('ref_ekg_q_interval', 'q_interval')
//    );
//    var $qrs_complex = array(
//        'qrs_axis', 'qrs_durasi', 'qrs_konfigurasi_patologi', 'qrs_konfigurasi_r_s'
//    );
//    var $segment_st = array(
//        'segmen_st_depresi', 'segmen_st_elevasi'
//    );
    var $table_scheme = array(
        'ekg' => array(
            'id' => array(
                'type' => 'int(11)',
                'null' => 0,
                'key' => 'pri',
                'default' => NULL,
                'extra' => ''
            ),
            'file_dicom_cvp' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'file_dicom_cvq' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'file_dicom_cvr' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'file_dicom_cvs' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'file_dicom_cvt' => array(
                'type' => 'varchar(255)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
        )
    );
}