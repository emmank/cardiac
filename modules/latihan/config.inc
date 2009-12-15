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
        'protokol' => 'text',
	'irama_dasar' => 'select',
        'perubahan_gelombang_r' => 'select',
        'dihentikan_karena' => 'select',
        'respon_denyut_jantung' => 'select',
        'puncak_denyut_jantung' => 'select',
        'tekanan_darah' => 'radio',
        'tekanan_darah_puncak' => 'text',
        'segmen_st_depresi' => 'text',
        'segmen_st_elevasi' => 'text',
        'segmen_st_konfigurasi' => 'text',
        'denyut_jantung_lainlain' => 'text',
        'rekaman_ekg_lainlain' => 'text'
    );
    var $fieldsisarray = array(
        'irama_dasar',
        'perubahan_gelombang_r' ,
        'dihentikan_karena' ,
        'respon_denyut_jantung',
        'puncak_denyut_jantung',
        'tekanan_darah',
        'segmen_st_depresi',
        'segmen_st_elevasi',
        'segmen_st_konfigurasi'
    );
    var $reftable = array(
        'irama_dasar' => array('ref_ekg_irama','irama'),
        'perubahan_gelombang_r' => array('ref_faseLatihan_perubahan_gelombang', 'perubahan_gelombang'),
        'dihentikan_karena' => array('ref_faseLatihan_dihentikan', 'dihentikan'),
        'respon_denyut_jantung' => array('ref_faseLatihan_respon_jantung', 'respon_jantung'),
        'puncak_denyut_jantung' => array('ref_ekg_denyut_jantung', 'denyut_jantung'),
        'tekanan_darah' => array('ref_threadKesimpulanSaran_tekananDarah', 'tekananDarah'),
    );
    var $urutanform = array(
        'A' => array(
            'protokol' => 'protokol'
        ),
        'B' => array(
            'rekaman_ekg' => array(
                'rekaman_st' => array(
                    'segmen_st_depresi',
                    'segmen_st_elevasi',
                    'segmen_st_konfigurasi'
                ),
                'irama_dasar',
                'perubahan_gelombang_r',
                'rekaman_ekg_lainlain'
            )
        ),
        'C' => array(
            'dihentikan_karena' => 'dihentikan_karena'
        ),
        'D' => array(
            'perubahan_hemodinamik' => array(
                'denyut_jantung' => array(
                    'respon_denyut_jantung',
                    'puncak_denyut_jantung',
                    'denyut_jantung_lainlain'
                ),
                'tekanan_darah' => array(
                    'tekanan_darah',
                    'tekanan_darah_puncak'
                )
            )
        )
    );
    var $table_scheme = array(
        'latihan' => array(
            'id' => array(
                'type' => 'int(11)',
                'null' => 0,
                'key' => 'pri',
                'default' => NULL,
                'extra' => ''
            ),
            'protokol' => array(
                'type' => 'varchar(100)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'segmen_st_depresi' => array(
                'type' => 'varchar(100)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'segmen_st_elevasi' => array(
                'type' => 'varchar(100)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'segmen_st_konfigurasi' => array(
                'type' => 'varchar(100)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'irama_dasar' => array(
                'type' => 'varchar(100)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'perubahan_gelombang_r' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'rekaman_ekg_lainlain' => array(
                'type' => 'varchar(100)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'dihentikan_karena' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'respon_denyut_jantung' => array(
                'type' => 'int(11)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'puncak_denyut_jantung' => array(
                'type' => 'varchar(100)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'denyut_jantung_lainlain' => array(
                'type' => 'varchar(100)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'tekanan_darah' => array(
                'type' => 'varchar(100)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            ),
            'tekanan_darah_puncak' => array(
                'type' => 'varchar(20)',
                'null' => 1,
                'key' => '',
                'default' => NULL,
                'extra' => ''
            )
        )
    );
}