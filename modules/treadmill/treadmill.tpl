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
 *  treadmill.php
 *  
 *  Created on Oct 26, 2009, 5:28:48 AM
 */

//echo '<pre>'; print_r($data); echo '</pre>';
foreach($data as $key => $value){
//    if(isset($value['#error']) && $value['#error'] !== FALSE){
//        $result .= '<div class="error">' . $value['#error'] . '</div><br /><br />' . "\n";
//    }
    $result .= __create_form_open($value, $key);
    $result .= "\n" . '<fieldset>' . "\n";
    $result .= '<legend>' . __t('Identitas Pasien') . '</legend>' . "\n";
    foreach($value as $ky => $vl){
        if(!eregi('#', $ky)){
            if($vl['#type'] == 'hidden'){
                $result .= '<input type="hidden" name="' . $ky . '" value="' . $vl['#value'] . '">' . "\n";
            }
        }
    }
    $gettbpos = array();
    foreach($value as $ky => $vl){
        if(!eregi('#', $ky)){
            if($ky != 'tab_items'){
                if(isset($vl['#tbpos'])){
                    $gettbpos[$vl['#tbpos']] = $vl;
                    $gettbpos[$vl['#tbpos']]['#key'] = $ky;
                }
            }
        }
    }
    ksort($gettbpos);
//    echo '<pre>'; print_r($gettbpos); echo '</pre>';
    foreach($gettbpos as $ky => $vl){
        if((int)$ky < 1 || (int)$ky % 8 == 0){
            $result .= '<div id="kolom">' . "\n";
            $setdiv = 1;
        }
        $result .= '<label>' . ucwords (str_replace ("_"," ",$vl['#title'])) . '</label>';
        if($vl['#type'] != 'textarea'){
            $result .= '<input type="text" value="' . $vl['#value'] .'" readonly="true"> <br />' . "\n";
        } else {
            $result .= '<textarea  readonly="true">' . $vl['#value'] .'</textarea> <br />' . "\n";
        }
        if((int)$ky > 3 && ((int)$ky + 1) % 8 == 0){
            unset($setdiv);
            $result .= '</div>' . "\n";
        }
    } unset($gettbpos);
    if(isset($setdiv)){
        $result .= '</div>' . "\n";
        unset($setdiv);
    }
    $result .= '</fieldset>' . "\n";
    if(isset($value['tab_items']) && count($value['tab_items']) > 0){
        $result .= '<ul id="fisistabs" class="shadetabs">' . "\n";
        $ke = 1;
        foreach($value['tab_items'] as $ky => $vl){
            if ($ky != "space") {
                $result .= '<li><a href="#" rel="fisis' . $ke . '">' . $vl['#title'] . '</a></li>' . "\n";
            } else {
                $result .= "<p></p>";
                $ke--;
            }
            $ke++;
        } unset($ke);
        $result .= '</ul>' . "\n";
        $result .= '<div style="border:1px solid gray; width:725px; margin-bottom: 1em; padding: 10px">' . "\n";
        $ke = 1;
        foreach($value['tab_items'] as $ky => $vl){
            if(isset($vl['#tpl'])  ){
//                require_once $vl['#tpl'];
                $ke++;
            }
        } unset($ke);
        $result .= '</div>' . "\n";
    }
    if(isset($value['submit'])){
        $result .= '<div>' . "\n";
        $result .= '<input type="submit" value="' . $value['submit']['#value'] . '"' . (isset($value['submit']['#extra']) ? ' ' . $value['submit']['#extra'] : '') . '>';
        $result .= '</div>' . "\n";
    }
    $result .= __create_form_close();
    $result .= '<script type="text/javascript">' . "\n";
    $result .= 'var tabs=new ddtabcontent("fisistabs")' . "\n";
    $result .= 'tabs.setpersist(true)' . "\n";
    $result .= 'tabs.setselectedClassTarget("link") //"link" or "linkparent"' . "\n";
    $result .= 'tabs.init()' . "\n";
    $result .= '</script>' . "\n";
}
