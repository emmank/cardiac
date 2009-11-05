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
 *  defaultvars.php
 *  
 *  Created on Sep 7, 2009, 1:50:47 PM
 */

session_start();

require_once CONFIGS_DIR . DS . 'config.inc';
$configs = new config();
$configs->time = time() - 3600;
$configs->timelog_idle = 60 * 15;
$configs->fcache = FILES_DIR . DS . 'cache' . DS . $_COOKIE[$configs->cookiesession];
$configs->flog = FILES_DIR . DS . 'log' . DS . date('Ymd', $configs->time);

require_once DBSTRINGS_DIR . DS . $configs->systemdb['rdbms'] . DS . 'dbquery.php';
require_once INCLUDES_DIR . DS . 'database.inc';
$systemquery = new sysDb();
$systemquery->dbname = $configs->systemdb['database']['name'];
$systemquery->dbprefix = $configs->systemdb['database']['prefix'];
$systemquery->dbsuffix = $configs->systemdb['database']['suffix'];
$systemquery->tbprefix = $configs->systemdb['database']['tbprefix'];
$systemquery->tbsuffix = $configs->systemdb['database']['tbsuffix'];
$systemquery->hostname = $configs->systemdb['database']['host'];
$systemquery->username = $configs->systemdb['database']['user'];
$systemquery->passwd = $configs->systemdb['database']['passwd'];
require_once LIBS_DIR . DS . 'adodb' . DS . 'adodb.inc.php';
$systemquery->conn = &ADONewConnection($configs->systemdb['rdbms']);

require_once INCLUDES_DIR . DS . 'translate.inc';
require_once INCLUDES_DIR . DS . 'menu.inc';
require_once INCLUDES_DIR . DS . 'path.inc';
require_once INCLUDES_DIR . DS . 'content.inc';
require_once INCLUDES_DIR . DS . 'theme.inc';
require_once INCLUDES_DIR . DS . 'main.class.php';
$main_module = new mainModule();

//echo '<pre>'; print_r($_COOKIE[$configs->cookiesession]); echo '</pre>';

$user = array();
$forminput = array('text', 'hidden', 'submit', 'radio', 'checkbox', 'password');
$formtextarea = array('textarea');
$formselect = array('select');


/*$menu = array();
$content = array();
$theme = array();
 *
 */
