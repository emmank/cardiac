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
 *  Created on Oct 5, 2009, 11:28:54 AM
 */


class abdomenConfig extends config
{
    var $rdbms = 'mysql';
    var $dbabdomen = array(
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

    // ---- Dibawah ini sengaja saya comment, karena berbeda dengan config module lain ----
//    var $heparfield_types = array(
//        'id' => 'hidden',
//        'hepar' => 'text',
//        'type' => 'select'
//    );
//    var $liverfield_types = array(
//        'id' => 'hidden',
//        'liver' => 'text',
//        'type' => 'select'
//    );
//    var $ginjalfield_types = array(
//        'id' => 'hidden',
//        'ginjal' => 'text',
//        'type' => 'select'
//    );

    var $typeoffields = array(
        'id' => 'hidden',
        'relief' => 'select',
        'center' => 'select',
        'inspeksi_kulit' => 'checkbox',
        'gerakan_dinding_perut' => 'select',
        'palpasi_hepar' => 'text',
        'palpasi_hepar_derajat_pembesaran' => 'text',
        'palpasi_hepar_konsistensi' => 'text',
        'palpasi_hepar_permukaan' => 'text',
        'palpasi_hepar_tepi' => 'text',
        'palpasi_hepar_nyeri_tekan' => 'text',
        'palpasi_liver' => 'text',
        'palpasi_liver_derajat_pembesaran' => 'text',
        'palpasi_liver_konsistensi' => 'text',
        'palpasi_liver_permukaan' => 'text',
        'palpasi_liver_tepi' => 'text',
        'palpasi_liver_nyeri_tekan' => 'text',
        'palpasi_ginjal' => 'text',
        'ballottement' => 'text',
        'perkusi' => 'text',
        'auscultation' => 'text',
        'peristaltik_usus' => 'text'

    );

    var $fieldsisarray = array(
        'relief','center','inspeksi_kulit','gerakan_dinding_perut'
    );
    var $reftable = array(
        'relief' => array('ref_abdomen_relief','relief'),
        'center' => array('ref_abdomen_center', 'center'),
        'inspeksi_kulit' => array('ref_abdomen_skin', 'skin'),
        'gerakan_dinding_perut' => array('ref_abdomen_gerakan_dinding_perut', 'gerakan'),
        'gerakan_dinding_perut' => array('ref_abdomen_gerakan_dinding_perut', 'gerakan')
    );
}