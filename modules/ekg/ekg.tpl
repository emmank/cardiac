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
<<<<<<< HEAD:modules/ekg/ekg.tpl
 *  ekg.tpl
 *  
 *  Created on Oct 26, 2009, 5:28:48 AM
 */

//echo '<pre>'; print_r($data); echo '</pre>';
=======
 *  ekg.php
 *  
 *  Created on Nov 12, 2009, 5:40:49 AM
 */

// echo '<pre>'; print_r($data); echo '</pre>';
>>>>>>> 329ebf0fefff2f31f2daa02f987278e1875dcc72:modules/ekg/ekg.tpl
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
<<<<<<< HEAD:modules/ekg/ekg.tpl
//    echo '<pre>'; print_r($gettbpos); echo '</pre>';
=======
    //echo '<pre>'; print_r($gettbpos); echo '</pre>';
>>>>>>> 329ebf0fefff2f31f2daa02f987278e1875dcc72:modules/ekg/ekg.tpl
    foreach($gettbpos as $ky => $vl){
        if((int)$ky < 1 || (int)$ky % 5 == 0){
            $result .= '<div id="kolom">' . "\n";
            $setdiv = 1;
        }
        $result .= '<label>' . ucwords($vl['#title']) . '</label>';
        if($vl['#type'] != 'textarea'){
            $result .= '<input type="text" value="' . $vl['#value'] .'" readonly="true"> <br />' . "\n";
        } else {
            $result .= '<textarea  readonly="true">' . $vl['#value'] .'</textarea> <br />' . "\n";
        }
        if((int)$ky > 3 && ((int)$ky + 1) % 5 == 0){
            unset($setdiv);
            $result .= '</div>' . "\n";
        }
    } unset($gettbpos);
    if(isset($setdiv)){
        $result .= '</div>' . "\n";
        unset($setdiv);
    }
    $result .= '</fieldset>' . "\n";
<<<<<<< HEAD:modules/ekg/ekg.tpl
    
//    if(isset($value['tab_items']) && count($value['tab_items']) > 0){
//        $result .= '<ul id="fisistabs" class="shadetabs">' . "\n";
//        $ke = 1;
//        foreach($value['tab_items'] as $ky => $vl){
//            $result .= '<li><a href="#" rel="fisis' . $ke . '">' . $vl['#title'] . '</a></li>' . "\n";
//            $ke++;
//        } unset($ke);
//        $result .= '</ul>' . "\n";
//        $result .= '<div style="border:1px solid gray; width:725px; margin-bottom: 1em; padding: 10px">' . "\n";
//        $ke = 1;
//        foreach($value['tab_items'] as $ky => $vl){
//            if(isset($vl['#tpl'])){
//                require_once $vl['#tpl'];
//                $ke++;
//            }
//        } unset($ke);
//        $result .= '</div>' . "\n";
//  }

//$result .= '<div id="fisis' . $ke . '" class="tabcontent">' . "\n";
//$result .= $vl['datafields']['ekg']['title'];
$result .= '<table width=100% class="table">' . "\n";
$cnt = 0;

if(is_array($value) && !isset($value['#tbpos'])){
//    echo '<pre>'; print_r($value); echo '</pre>';
    foreach($value as $yk => $lv){
//    echo $yk . ' = ' . $lv['type'] . '<br />';
//    echo '<pre>'; print_r($lv); echo '</pre>';
    if($lv['#type'] != 'hidden'){
//        echo 'here';
        if($cnt < 1){
            $result .= '<tr valign="top">' . "\n";
        }
//        $result .= '<td>' . $lv['title'] . '</td>';
        $result .= '<td>';
         
        if($lv['#type'] == 'select'){
            $result .= '<select name="' . $yk . '" size="' . $lv['size']. '">' . "\n";
            if(isset($lv['blankopt'])){
                $result .= '<option value=""></option>';
            }
                echo '<pre>'; print_r($lv); echo '</pre>';
            foreach($lv['theref'] as $kc => $isi){
                $result .= '<option value="' . $kc . '"' . (isset($lv['value']) && $lv['value'] == $kc ? ' selected=selected' : '') . '>' . $isi . '</option>' . "\n";
            }
            $result .= '</select>' . "\n";
        } elseif($lv['#type'] == 'checkbox'){
            if (count($lv['theref'])>0) {
//            $cnt = 0;
            foreach($lv['theref'] as $kc => $isi){
                $result .= '<input type="checkbox" name="' . $yk . '[' . $cnt . ']" value="' . $kc . '">';
                $result .= $isi . "<br />";
//                $cnt++;
            } //unset($cnt);
            } else {
                $result .= '<input type="checkbox" name="' . $yk . '" value="1">';
            }
        } elseif($lv['#type'] == 'radio'){
//            $cnt = 0;
            foreach($lv['theref'] as $kc => $isi){
                $result .= '<input type="radio" name="' . $yk . '[' . $cnt . ']" value="' . $kc . '">';
                $result .= $isi . "<br />";
//                $cnt++;
            } //unset($cnt);
        } elseif($lv['#type'] == 'datetime'){
            if(isset($lv['value'])){
                $datetime = $lv['value'];
            } else {
                $datetime = date('Y-m-d H:i:s', $lv['timenow']);
            }
            list($dumptgl, $dumptime) = explode(' ', $datetime);
            unset($datetime);
            $dumptgl = explode('-', $dumptgl);
            $dumptime = explode(':', $dumptime);
            $result .= '<input type="text" name="' . $yk . '[2]" size="2" maxlength="2" value="' . $dumptgl[2] . '">' . "&nbsp";
            $result .= '<select name="' . $yk . '[1]" size="1">' . "\n";
            foreach($lv['theref'] as $kc => $isi){
                $result .= '<option value="' . $kc . '"' . ($dumptgl[1] == $kc ? ' selected=selected' : '') . '>' . $isi . '</option>' . "\n";
            }
            $result .= '</select>' . "&nbsp;";
            
            $result .= '<input type="text" name="' . $yk . '[0]" size="4" maxlength="4" value="' . $dumptgl[0] . '">' . "<br />";
            $result .= '<input type="text" name="' . $yk . '[5]" size="2" maxlength="2" value="' . $dumptime[0] . '">' . ":";
            $result .= '<input type="text" name="' . $yk . '[6]" size="2" maxlength="2" value="' . $dumptime[1] . '">' . ":";
            $result .= '<input type="text" name="' . $yk . '[7]" size="2" maxlength="2" value="' . $dumptime[2] . '">' . "\n";
        } elseif($lv['#type'] == 'text') {
//            echo $yk . '<br />';
            $result .= '<input type="' . $lv['#type'] . '" name="' . $yk . '"' . (isset($lv['size']) ? ' size="' . $lv['size'] . '"' : '') . '>' . "\n";
//            echo '<pre>'; print_r ($lv); echo '</pre>';
//            echo $cnt;
        }
        $result .= '</td>' . "\n";
        $cnt++;
        if($cnt > 1){
            $cnt = 0;
            $result .= '</tr>' . "\n";
        }
    }
} unset($cnt);
}
$result .= '</table>' . "\n";
$result .= '</div>' . "\n";


=======

    $result .= '<div>' . "\n";
    $result .= '<table width=100% class="table">' . "\n";
    $cnt = 0;
    foreach($value as $yk => $lv){
        if(!eregi('#', $yk) && is_array($lv) && $yk != 'submit'){
            if($lv['#type'] != 'hidden' && !isset($lv['#tbpos'])){
                if($cnt < 1){
                    $result .= '<tr valign="top">' . "\n";
                }
                $result .= '<td>' . $lv['#title'] . '</td>';
                $result .= '<td>';
                if($lv['#type'] == 'select'){
                    $result .= '<select name="' . $yk . '" size="' . $lv['#size']. '">' . "\n";
                    if(isset($lv['#blankopt'])){
                        $result .= '<option value=""></option>';
                    }
                    foreach($lv['#theref'] as $kc => $isi){
                        $result .= '<option value="' . $kc . '"' . (isset($lv['#value']) && $lv['#value'] == $kc ? ' selected=selected' : '') . '>' . $isi . '</option>' . "\n";
                    }
                    $result .= '</select>' . "\n";
                } elseif($lv['#type'] == 'checkbox'){
                    foreach($lv['#theref'] as $kc => $isi){
                        $result .= '<input type="checkbox" name="' . $yk . '[' . $cnt . ']" value="' . $kc . '">';
                        $result .= $isi . "<br />";
                    }
                } elseif($lv['#type'] == 'radio'){
                    foreach($lv['#theref'] as $kc => $isi){
                        $result .= '<input type="radio" name="' . $yk . '[' . $cnt . ']" value="' . $kc . '">';
                        $result .= $isi . "<br />";
                    }
                } elseif($lv['#type'] == 'datetime'){
                    if(isset($lv['#value'])){
                        $datetime = $lv['#value'];
                    } else {
                        $datetime = date('Y-m-d H:i:s', $lv['#timenow']);
                    }
                    list($dumptgl, $dumptime) = explode(' ', $datetime);
                    unset($datetime);
                    $dumptgl = explode('-', $dumptgl);
                    $dumptime = explode(':', $dumptime);
                    $result .= '<input type="text" name="' . $yk . '[2]" size="2" maxlength="2" value="' . $dumptgl[2] . '">' . "&nbsp";
                    $result .= '<select name="' . $yk . '[1]" size="1">' . "\n";
                    foreach($lv['#theref'] as $kc => $isi){
                        $result .= '<option value="' . $kc . '"' . ($dumptgl[1] == $kc ? ' selected=selected' : '') . '>' . $isi . '</option>' . "\n";
                    }
                    $result .= '</select>' . "&nbsp;";
                    $result .= '<input type="text" name="' . $yk . '[0]" size="4" maxlength="4" value="' . $dumptgl[0] . '">' . "<br />";
                    $result .= '<input type="text" name="' . $yk . '[5]" size="2" maxlength="2" value="' . $dumptime[0] . '">' . ":";
                    $result .= '<input type="text" name="' . $yk . '[6]" size="2" maxlength="2" value="' . $dumptime[1] . '">' . ":";
                    $result .= '<input type="text" name="' . $yk . '[7]" size="2" maxlength="2" value="' . $dumptime[2] . '">' . "\n";
                } else {
                    $result .= '<input type="' . $lv['#type'] . '" name="' . $yk . '"' . (isset($lv['#size']) ? ' size="' . $lv['#size'] . '"' : '') . '>' . "\n";
                }
                $result .= '</td>' . "\n";
                $cnt++;
                if($cnt > 1){
                    $cnt = 0;
                    $result .= '</tr>' . "\n";
                }
            }
        }
    } unset($cnt);
    $result .= '</table>' . "\n";
    $result .= '</div>' . "\n";
>>>>>>> 329ebf0fefff2f31f2daa02f987278e1875dcc72:modules/ekg/ekg.tpl

    if(isset($value['submit'])){
        $result .= '<div>' . "\n";
        $result .= '<input type="submit" value="' . $value['submit']['#value'] . '"' . (isset($value['submit']['#extra']) ? ' ' . $value['submit']['#extra'] : '') . '>';
        $result .= '</div>' . "\n";
    }
    $result .= __create_form_close();
<<<<<<< HEAD:modules/ekg/ekg.tpl
//    $result .= '<script type="text/javascript">' . "\n";
//    $result .= 'var tabs=new ddtabcontent("fisistabs")' . "\n";
//    $result .= 'tabs.setpersist(true)' . "\n";
//    $result .= 'tabs.setselectedClassTarget("link") //"link" or "linkparent"' . "\n";
//    $result .= 'tabs.init()' . "\n";
//    $result .= '</script>' . "\n";
=======
>>>>>>> 329ebf0fefff2f31f2daa02f987278e1875dcc72:modules/ekg/ekg.tpl
}
