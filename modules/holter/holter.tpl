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

 *  holter.tpl
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
        if((int)$ky < 1 || (int)$ky % 5 == 0){
            $result .= '<div id="kolom">' . "\n";
            $setdiv = 1;
        }
        $result .= '<label>' . ucwords($vl['#title']) . '</label>';
        if($vl['#type'] != 'textarea'){
            $result .= '<input type="text" value="' . $vl['#value'] .'" readonly="true"> <br />' . "\n";
        } else {
            $result .= '<textarea  readonly="true" rows="3" cols="30">' . $vl['#value'] .'</textarea> <br />' . "\n";
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
    //-------------------Form dibawah

    $result .= '<div>' . "\n";
    $result .= '<table width=100% class="table" border="0">' . "\n";
    foreach($value as $yk => $lv){
        if(!eregi('#', $yk) && is_array($lv) && $yk != 'submit'){
            if($lv['#type'] != 'hidden' && !isset($lv['#tbpos'])){
                if(isset($lv['#customized'])){
                    if(!isset($rowspan[$lv['#customized']['id']])){$rowspan[$lv['#customized']['id']] = array();}
                    $rowspan[$lv['#customized']['id']][] = $yk;
                }
            }
        }
    }
    $cnt = 0;
    foreach($value as $yk => $lv){
        if(!eregi('#', $yk) && is_array($lv) && $yk != 'submit' && !in_array($yk, $value['#lookother'])){
            if($lv['#type'] != 'hidden' && !isset($lv['#tbpos'])){
                $result .= '<tr valign="top">' . "\n";
                if(!isset($lv['#customized'])){
                    if(isset($lv['#value']) && trim($lv['#value']) != '' && !is_array($lv['#value'])){
                        $lv['#value'] = explode('|', $lv['#value']);
                    }
                    $lv['#value'][1] = explode(':', $lv['#value'][1]);
                    $result .= '<td align="right" width="15%">' . ucwords($lv['#title']) . '</td>' . "\n";
                    $result .= '<td align="left" colspan="3">';
                    if($lv['#type'] == 'select'){
                        if(isset($lv['#readonly']) && trim($lv['#readonly']) !== FALSE){
                            $result .= $lv['#theref'][$lv['#value']];
                        } else {
                            $result .= '<select name="' . $yk . '" size="1">';
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
                            foreach($lv['#theref'] as $kk => $vv){
                                $result .= '<option value="' . $kk . '"' . (isset($lv['#value']) && $lv['#value'] == $kk ? ' selected="selected"' : '') . '>' . $vv . '</option>';
                            }
                            $result .= '</select>';
                        }
                    } else {
                        if(isset($lv['#readonly']) && trim($lv['#readonly']) !== FALSE){
                            $result .= $lv['#value'][0] . ' ' . __t('per menit') . ' ' . str_repeat('&nbsp;', 15) . __t('waktu') . ' ' . $lv['#value'][1][0] . ':' . $lv['#value'][1][1] . "\n";
                        } else {
                            $result .= '<input type="' . $lv['#type'] . '" name="' . $yk . '[0]" size="' . (isset($lv['#size']) ? $lv['#size']: '5') . '"' . (is_array($lv['#value']) && isset($lv['#value'][0]) ? ' value="' . $lv['#value'][0] . '"' : '') . '>' . "\n";
                            $result .= ' ' . __t('per menit') . ' ' . str_repeat('&nbsp;', 15) . __t('waktu') . ' ' . "\n";
                            $result .= '<input type="' . $lv['#type'] . '" name="' . $yk . '[1][0]" size="2"' . (is_array($lv['#value']) && isset($lv['#value'][1][0]) ? ' value="' . $lv['#value'][1][0] . '"' : '') . '>' . "\n";
                            $result .= ':' . "\n";
                            $result .= '<input type="' . $lv['#type'] . '" name="' . $yk . '[1][1]" size="2"' . (is_array($lv['#value']) && isset($lv['#value'][1][1]) ? ' value="' . $lv['#value'][1][1] . '"' : '') . '>' . "\n";
                        }
                    }
                    $result .= '</td>' . "\n";
                } else {
                    if(!is_array($lv['#value'])){
                        $lv['#value'] = explode('|', $lv['#value']);
                    }
                    if(!isset($dumpt)){$dumpt = array();}
                    if(!in_array($lv['#customized']['title'], $dumpt)){
                        $dumpt[] = $lv['#customized']['title'];
                        $result .= '<td align="right" rowspan="' . count($rowspan[$lv['#customized']['id']]) . '">' . ucwords($lv['#customized']['title']) . '</td>' . "\n";
                    }
                    $result .= '<td width="15%" align="' . ($yk != 'gelombang_t' ? 'right' : 'left') . '">';
                    if($yk != 'gelombang_t'){
                        $result .= ucwords($lv['#title']);
                    } else {
                        if(isset($lv['#readonly']) && $lv['#readonly'] !== FALSE){
                            $result .= $lv['#value'][0];
                        } else {
                            foreach($lv['#customized']['option'] as $kk => $vv){
                                if(isset($koma)){
                                    $result .= '<br />';
                                }
                                $result .= '<input type="radio" name="' . $yk . '[0]" value="' . $kk . '"' . (isset($lv['#value'][0]) && $lv['#value'][0] == $kk ? ' checked="true"' : '') . '> ' . $vv;
                                $koma = 0;
                            } unset($koma);
                        }
                    }
                    $result .= '</td>' . "\n";
                    $result .= '<td align="left"' . ($lv['#type'] != 'select2' ? ' colspan="2"' : '') . '>';
                    if($yk != 'gelombang_t'){
                        if(isset($lv['#readonly']) && $lv['#readonly'] !== FALSE){
                            $result .= ($lv['#type'] == 'select' ? $lv['#theref'][$lv['#value'][0]] : $lv['#value'][0]) . ($lv['#type'] == 'select' ? '' : ' ' . __t('pada sandapan') . ' ' . $lv['#theref'][$lv['#value'][1]]);
                        } else {
                            if($lv['#type'] == 'select2'){
                                $result .= '<select name="' . $yk . '[0]" size="1">';
                                $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>' . "\n";
                                foreach($lv['#customized']['option'] as $kk => $vv){
                                    $result .= '<option value="' . $kk . '"' . (isset($lv['#value'][0]) && $lv['#value'][0] == $kk ? ' selected="selected"' : '') . '>' . $vv . '</option>' . "\n";
                                }
                                $result .= '</select>' . "\n";
                                $result .= __t('pada sandapan') . "\n";
                                $result .= '<select name="' . $yk . '[1]" size="1">';
                                $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>' . "\n";
                                foreach($lv['#theref'] as $kk => $vv){
                                    $result .= '<option value="' . $kk . '"' . (isset($lv['#value'][1]) && $lv['#value'][1] == $kk ? ' selected="selected"' : '') . '>' . $vv . '</option>' . "\n";
                                }
                                $result .= '</select>' . "\n";
                            } elseif($lv['#type'] == 'select3') {
                                $result .= '<select name="' . $yk . '[0]" size="1">';
                                $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>' . "\n";
                                foreach($lv['#customized']['option'] as $kk => $vv){
                                    $result .= '<option value="' . $kk . '"' . (isset($lv['#value'][0]) && $lv['#value'][0] == $kk ? ' selected="selected"' : '') . '>' . $vv . '</option>' . "\n";
                                }
                                $result .= '</select>' . "\n";
                                $result .= __t('pada sandapan') . "\n";
                                $result .= '<select name="' . $yk . '[1]" size="1">';
                                $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>' . "\n";
                                foreach($lv['#theref'] as $kk => $vv){
                                    $result .= '<option value="' . $kk . '"' . (isset($lv['#value'][1]) && $lv['#value'][1] == $kk ? ' selected="selected"' : '') . '>' . $vv . '</option>' . "\n";
                                }
                                $result .= '</select>' . "\n";
                            } else {
                                $result .= '<select name="' . $yk . '[0]" size="1">';
                                $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>' . "\n";
                                foreach($lv['#theref'] as $kk => $vv){
                                    $result .= '<option value="' . $kk . '"' . (isset($lv['#value'][0]) && $lv['#value'][0] == $kk ? ' selected="selected"' : '') . '>' . $vv . '</option>' . "\n";
                                }
                                $result .= '</select>' . "\n";
                            }
                        }
                    } else {
                        $result .= (isset($lv['#readonly']) && $lv['#readonly'] !== FALSE ? (isset($lv['#value'][1]) ? __t('pada sandapan') : '') : '<br />' . __t('pada sandapan')) . "\n";
                        if(isset($lv['#readonly']) && $lv['#readonly'] !== FALSE){
                            $result .= $lv['#theref'][$lv['#value'][1]];
                        } else {
                            $result .= '<select name="' . $yk . '[1]" size="1">' . "\n";
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>' . "\n";
                            foreach($lv['#theref'] as $kk => $vv){
                                $result .= '<option value="' . $kk . '"' . (isset($lv['#value'][1]) && $lv['#value'][1] == $kk ? ' selected="selected"' : '') . '>' . $vv . '</option>' . "\n";
                            }
                            $result .= '</select>' . "\n";
                        }
                    }
                    $result .= '</td>' . "\n";
                }
                $result .= '</tr>' . "\n";
                $cnt++;
            }
        }
    } unset($dumpt, $cnt, $rowspan);
    $result .= '</table>' . "\n";
    $result .= '</div>' . "\n";

    $result .= '<div>' . "\n";
    $result .= '<table width=100% class="table" border="0">' . "\n";
    $result .= '<tr>' . "\n";
    $result .= '<td></td>' . "\n";
    $result .= '<td width="20%" align="left" style="font-weight:bold">' . __t('type') . '</td>' . "\n";
    $result .= '<td width="25%" align="left" style="font-weight:bold">' . __t('kali') . '</td>' . "\n";
    $result .= '<td width="25%" align="left" style="font-weight:bold">' . __t('waktu') . '</td>' . "\n";
    $result .= '</tr>' . "\n";
    foreach($value['#otherlook'] as $yk => $lv){
        $result .= '<tr><td align="left">' . ucwords($lv['#title']) . '</td>' . "\n";
        $result .= '<td align="left">' . "\n";
        if(isset($lv['#value']) && trim($lv['#value']) != '' && !is_array($lv['#value'])){
            $lv['#value'] = explode('|', $lv['#value']);
        }
        if($lv['#type'] == 'select'){
            if(isset($lv['#readonly']) && trim($lv['#readonly']) !== FALSE){
                $result .= $lv['#theref'][$lv['#value'][0]] . "\n";
            } else {
                $result .= '<select name="' . $yk . '[0]" size="1">' . "\n";
                $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>' . "\n";
                foreach($lv['#theref'] as $kk => $vv){
                    $result .= '<option value="' . $kk . '"' . (isset($lv['#value'][0]) && $lv['#value'][0] == $kk ? ' selected="selected"' : '') . '>' . $vv . '</option>' . "\n";
                }
                $result .= '</select>' . "\n";
            }
        } else {
            if(isset($lv['#readonly']) && trim($lv['#readonly']) !== FALSE){
                $result .= $lv['#value'][0] . "\n";
            } else {
                $result .= '<input type="' . $lv['#type'] . '" name="' . $yk . '[0]" size="' . (isset($lv['#size']) ? $lv['#size']: '5') . '"' . (is_array($lv['#value']) && isset($lv['#value'][0]) ? ' value="' . $lv['#value'][0] . '"' : '') . '>' . "\n";
            }
        }
        $result .= '</td>' . "\n";
        $result .= '<td align="left">' . "\n";
        if(isset($lv['#readonly']) && trim($lv['#readonly']) !== FALSE){
            $result .= $lv['#value'][1] . "\n";
        } else {
            $result .= '<input type="text" name="' . $yk . '[1]" size="' . (isset($lv['#size']) && $lv['#type'] != 'select' ? $lv['#size']: '5') . '"' . (is_array($lv['#value']) && isset($lv['#value'][1]) ? ' value="' . $lv['#value'][1] . '"' : '') . '>' . "\n";
        }
        $result .= ' </td>' . "\n";
        $result .= '<td align="left">' . "\n";
        if(isset($lv['#readonly']) && trim($lv['#readonly']) !== FALSE){
            $result .= $lv['#value'][2] . "\n";
        } else {
            $result .= '<input type="text" name="' . $yk . '[2]" size="' . (isset($lv['#size']) && $lv['#type'] != 'select' ? $lv['#size']: '5') . '"' . (is_array($lv['#value']) && isset($lv['#value'][2]) ? ' value="' . $lv['#value'][2] . '"' : '') . '>' . "\n";
        }
        $result .= '</td></tr>' . "\n";
    }
    $result .= '</table>' . "\n";
    $result .= '</div>' . "\n";

    if(isset($value['submit'])){
        $result .= '<div>' . "\n";
        $result .= '<input type="submit" value="' . $value['submit']['#value'] . '"' . (isset($value['submit']['#extra']) ? ' ' . $value['submit']['#extra'] : '') . '>';
        $result .= '</div>' . "\n";
    }
    $result .= __create_form_close();
}
