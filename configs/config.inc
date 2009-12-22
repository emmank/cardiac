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
 *  setting.inc
 *
 *  Created on Sep 6, 2009, 11:03:48 AM
 */

class config
{
    var $debugshow = true;
    var $default_theme = 'default';
    var $default_lang = 'indonesia';
    var $default_module = array('user', 'auth', 'system', 'node', 'block');
    var $time;
    var $fcache;
    var $flog;
    var $synclang = TRUE;
    var $security_features = TRUE;
    var $clean_url = TRUE;
    var $cacheseparator = '][';
    var $systemdb = array(
        'rdbms' => 'mysql',
        'database' => array(
            'name' => 'mycms',
            'prefix' => '',
            'suffix' => '',
            'tbprefix' => '',
            'tbsuffix' => '',
            'host' => 'localhost',
            'user' => 'root',
            'passwd' => 'emmank'
        )
    );
    var $dbuser = array(
        'name' => 'layanan_kesehatan',
        'prefix' => '',
        'suffix' => '',
        'tbprefix' => '',
        'tbsuffix' => '',
        'host' => 'localhost',
        'user' => 'root',
        'passwd' => 'emmank'
    );
    var $auth_use_table = array(
        'users', //table
        'userid', //auth fields
        'sandi', //password fields
        'sesi', //unique session for auth key
        'id' //primary key of table
    );
    var $salt = array(12,6);
    var $use_time_limit = 'timelog';
    var $timelog_idle;
    var $cookieid = 'auth_user';
    var $cookiesession = 'PHPSESSID';
    var $identity_message = 'Fakultas Kedokteran Universitas Hasanuddin, Cardiac Center Rumah Sakit Wahidin Sudiro Husodo';
    var $systitle = 'Cardiac Center';
    var $user_required = FALSE;
    var $limitcacheindays = 2; //Batas maksimal antrian di simpan
    var $abjad = array('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z');
    var $formtypelists = array(
        'text' => 'text',
        'textarea' => 'textarea',
        'password' => 'password',
        'hidden' => 'hidden',
        'submit' => 'submit',
        'select' => 'select',
        'checkbox' => 'checkbox',
        'radio' => 'radio'
    );
    var $menu_sights = array(
        'admin' => array(
            'title' => 'administer',
            'description' => 'All menu thats used by administrator to manage entire system configurations',
            'user_required' => 'admin',
            'path' => '/admin',
            'exec' => 'core_show_admin_menus'
        ),
        'user' => array(
            'title' => 'pengguna',
            'description' => 'All menu thats used by user to manage their entry and self configurations',
            'user_required' => 'users',
            'path' => '/user',
            'exec' => 'core_show_user_menus'
        ),
        'node' => array(
            'title' => 'layanan',
            'description' => 'General information service for accessed by public',
            'user_required' => NULL,
            'path' => '/node',
            'exec' => 'core_show_node_menus'
        ),
        'reference' => array(
            'title' => 'referensi',
            'description' => 'Reference information for all system',
            'user_required' => 'users',
            'path' => '/reference',
            'exec' => 'core_show_node_menus'
        ),
        'care' => array(
            'title' => 'perawatan',
            'description' => 'Segala kegiatan dalam layanan rawat inap pasien',
            'user_required' => 'users',
            'path' => '/care',
            'exec' => 'core_show_care_menus'
        )
    );

}
