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
 *  content.tpl.php
 *  
 *  Created on Sep 6, 2009, 11:03:48 AM
 */

$smarty->display('open_content.tpl');

if(isset($content['output']['form'])){
    $itemselement = array(
        'type',
        'title',
        'collapsible',
        'collapsed',
        'weight',
        'action',
        'message',
        'error'
    );
    $smarty->assign('itemselement', $itemselement); unset($itemselement);
    foreach($content['output']['form'] as $key => $value){
        $items = array();
        foreach($value as $ky => $vl){
            foreach($vl as $ke => $val){
                $ke = eregi_replace('#', '', $ke);
                $items[$ky][$ke] = $val;
                if(is_array($val) && $ke != 'message'){
                    foreach($val as $yk => $lv){
                        unset($items[$ky][$ke][$yk]);
                        $yk = eregi_replace('#', '', $yk);
                        $items[$ky][$ke][$yk] = $lv;
                    }
                }
            }
        }
//        echo '<pre>'; print_r($items); echo '</pre>';
        $smarty->assign('form', $items); unset($items);
//        echo '<pre>'; print_r($smarty->get_template_vars('form')); echo '</pre>';
        $smarty->display('form.tpl');
        $smarty->clear_assign('form');
    }
}
//echo '<pre>'; print_r($showpage); echo '</pre>';

$smarty->display('close_content.tpl');
