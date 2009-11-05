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
 *  renderme.tpl.php
 *
 *  Created on Sep 6, 2009, 11:03:48 AM
 */

//echo '<pre>'; print_r($user); echo '</pre>';
//echo '<pre>'; print_r($showpage); echo '</pre>';
/*foreach($showpage as $key=>$value){
    ${$key} = $value;
}
 *
 */

require_once THEMES_DIR . DS . 'default' . DS . 'libs' . DS . 'smarty' . DS . 'Smarty.class.php';
$smarty = new Smarty;
$smarty->template_dir = THEMES_DIR . DS . 'default' . DS . 'templates';
$smarty->compile_dir = THEMES_DIR . DS . 'default' . DS . 'templates' . DS . 'compile';
$smarty->cache_dir = THEMES_DIR . DS . 'default' . DS . 'templates' . DS . 'cache';

require_once THEMES_DIR . DS . 'default' . DS . 'config.inc';
$formlists = array();
if(isset($content['output']['form'])){
    foreach($content['output']['form'] as $value){
        foreach($value as $key=>$val){
            $formlists[] = $key;
            ${$key} = $val;
        }
    }
    if($content['exec'] == 'auth_login_form'){
        $userkey = '';
        foreach($login as $key=>$value){
            if(!eregi('#', $key)){
                $userkey = $key; break;
            }
        }
//    echo '<pre>'; print_r($login); echo '</pre>';
        $smarty->assign('body_login', "javascript:document." . $formlists[0] . "." . $userkey . ".focus()");
    }
}

$smarty->assign('configs', $configs);
$smarty->display('head.tpl');

if($content['exec'] != 'auth_login_form'){
    $smarty->assign('mymenu', $managed_menus);
    require_once THEMES_DIR . DS . 'default' . DS . 'header.tpl.php';
}

require_once THEMES_DIR . DS . 'default' . DS . 'container.tpl.php';

if($content['exec'] != 'auth_login_form'){
    require_once THEMES_DIR . DS . 'default' . DS . 'footer.tpl.php';
}

$smarty->display('foot.tpl');
