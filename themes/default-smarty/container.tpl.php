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
 *  container.tpl.php
 *  
 *  Created on Sep 6, 2009, 1:08:39 PM
 */

$smarty->display('open_container.tpl');

if($content['exec'] != 'auth_login_form'){
    require_once THEMES_DIR . DS . 'default' . DS . 'block_left.tpl.php';
}

require_once THEMES_DIR . DS . 'default' . DS . 'content.tpl.php';

if($content['exec'] != 'auth_login_form'){
    require_once THEMES_DIR . DS . 'default' . DS . 'block_right.tpl.php';
}

$smarty->display('close_container.tpl');