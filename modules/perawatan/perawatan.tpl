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
 *  perawatan.php
 *  
 *  Created on Oct 26, 2009, 5:28:48 AM
 */

foreach($data as $key => $value){
    if(isset($value['#addmenu'])){
        $result .= __create_add_menu($value['#addmenu']);
    }
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
    foreach($gettbpos as $ky => $vl){
        if((int)$ky < 1 || (int)$ky % 8 == 0){
            $result .= '<div id="kolom">' . "\n";
            $setdiv = 1;
        }
        $result .= '<label>' . ucwords (str_replace ("_"," ",$vl['#title'])) . '</label>';
        if($vl['#type'] != 'textarea'){
            $result .= '<input type="text" value="' . $vl['#value'] .'" readonly="true"> <br />' . "\n";
        } else {
            $result .= '<textarea  readonly="true" rows="' . (isset($vl['#rows']) ? $vl['#rows'] : 3) . '" cols="' . (isset($vl['#cols']) ? $vl['#cols'] : 30) . '">' . $vl['#value'] .'</textarea> <br />' . "\n";
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

    $result .= '<fieldset>' . "\n";
    foreach($value as $ky => $vl){
        if(!eregi('#', $ky)){
            if(!isset($vl['#tbpos'])){
                $result .= '<div><label>' . ucwords (str_replace ("_"," ",$vl['#title'])) . '</label></div>' . "\n";
                $result .= '<div>' . "\n";
                if($vl['#type'] == 'datetime'){
                    if(isset($vl['#value'])){
                        $datetime = $vl['#value'];
                    }
                    list($dumptgl, $dumptime) = explode(' ', $datetime);
                    unset($datetime);
                    $dumptgl = explode('-', $dumptgl);
                    $dumptime = explode(':', $dumptime);
                    if($vl['#readonly'] === true){
                        $result .= $dumptgl[2] . "&nbsp;";
                        $result .= ucwords(__t($vl['#theref'][$dumptgl[1]])) . "&nbsp;";
                        $result .= $dumptgl[0] . "&nbsp;";
                        $result .= $dumptime[0] . ":";
                        $result .= $dumptime[1] . ":";
                        $result .= $dumptime[2];
                    } else {
                        $result .= '<input type="text" name="' . $ky . '[2]" size="2" maxlength="2" value="' . $dumptgl[2] . '" style="text-align:right">' . "&nbsp" . "\n";
                        $result .= '<select name="' . $ky . '[1]" size="1">' . "\n";
                        foreach($vl['#theref'] as $kc => $isi){
                            $result .= '<option value="' . $kc . '"' . ($dumptgl[1] == $kc ? ' selected=selected' : '') . '>' . ucwords(__t($isi)) . '</option>' . "\n";
                        }
                        $result .= '</select>' . "&nbsp;" . "\n";
                        $result .= '<input type="text" name="' . $ky . '[0]" size="4" maxlength="4" value="' . $dumptgl[0] . '" style="text-align:right">&nbsp;' . "\n";
                        $result .= '<input type="text" name="' . $ky . '[3]" size="2" maxlength="2" value="' . $dumptime[0] . '" style="text-align:right">' . ":";
                        $result .= '<input type="text" name="' . $ky . '[4]" size="2" maxlength="2" value="' . $dumptime[1] . '" style="text-align:right">' . ":";
                        $result .= '<input type="text" name="' . $ky . '[5]" size="2" maxlength="2" value="' . $dumptime[2] . '" style="text-align:right">' . "\n";
                    }
                } elseif($ky == 'ruang') {
                    if(isset($vl['#readonly']) && $vl['#readonly'] !== FALSE){
                        $result .= $vl['#value'] . "\n";
                    } else {
                        $result .= '<select name="' . $ky . '" size="1">' . "\n";
                        if(count($vl['#option']) > 0){
                            foreach($vl['#option'] as $yk => $lv){
                                $result .= '<option value="' . $yk . '"' . (isset($vl['#value']) && $vl['#value'] == $yk ? ' selected' : '') . '>' . ucwords(__t($lv)) . '</option>' . "\n";
                            }
                        }
                        $result .= '</select>' . "\n";
                    }
                }
                $result .= '</div>' . "\n";
            }
        }
    }
    $result .= '</fieldset>' . "\n";

    if(isset($value['submit'])){
        $result .= '<div>' . "\n";
        $result .= '<input type="submit" value="' . $value['submit']['#value'] . '"' . (isset($value['submit']['#extra']) ? ' ' . $value['submit']['#extra'] : '') . '>';
        $result .= '</div>' . "\n";
    }
    $result .= __create_form_close();
}
