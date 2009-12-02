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
 *  vasculartpl.php
 *  
 *  Created on Sep 14, 2009, 10:23:14 AM
 */

//echo '<pre>'; print_r($data); echo '</pre>'; exit();

foreach($data as $key => $value){
    if(isset($value['#error']) && $value['#error'] !== FALSE){
        $result .= '<div class="error">' . $value['#error'] . '</div><br /><br />' . "\n";
    }
    $result .= '<form action="' . $value['#action'] . '" method="POST" name="' . $key . '"';
    if(isset($idform) && !is_null($idform)){
        $result .= ' id="' . $idform . '"';
    }
    if(isset($classform) && !is_null($classform)){
        $result .= ' class="' . $classform . '"';
    }
    $result .= '>' . "\n";
    if(isset($value['#title']) && $value['#title'] != 'hidden'){
        $result .= '<div align="center"><strong>'. ucwords($value['#title']) .'</strong></div>' . "\n";
    }
    if(isset($value['#message']) && $value['#message'] != 'hidden'){
        if(is_array($value['#message'])){
            foreach($value['#message'] as $ky => $vl){
                $result .= '<div>';
                if($value['#id'] == 'login' && $ky < 1){
                    $result .= '<font class="login-title">';
                }
                $result .= ucwords($vl);
                if($value['#id'] == 'login'){
                    if($ky < 1){
                        $result .= '</font>';
                    } else {
                        $result .= '<br /><br />';
                    }
                }
                $result .= '</div>' . "\n";
            }
        } else {
            $result .= '<div>'. ucwords($value['#message']) .'</div>' . "\n";
        }
    }
    $result .= '<div>' . "\n";
    $result .= '<table align="center" width="100%" border="0">' . "\n";
//    echo '<pre>'; print_r($value); echo '</pre>'; exit();
    $cols = 0;
    for($i=0; $i<6; $i++){
        if($cols == 0){
            $result .= '<tr>' . "\n";
        }
        $result .= '<td width="' . ($cols == 0 ? '45%' : '55%') . '" align="' . ($cols == 0 ? 'left' : 'left') . '"' . ($i == 3 ? ' rowspan=3' : '') . '>' . "\n";
        $result .= '<div>' . "\n";
        foreach($value as $ke => $val){
            if(!eregi('#', $ke) && $ke != 'data'){
                if(isset($val['#tbpos']) && $val['#tbpos'] == $i){
                    if(isset($val['#title']) && $val['#title'] != 'hidden' && $val['#type'] != 'hidden'){
                        $result .= '<label for="'. $ke .'" style="width:100px">' . ucwords($val['#title']) . ' :</label>';
                    }
                    if(in_array($val['#type'], $forminput)){
                        $result .= '<input type="' . $val['#type'] . '" name="' . $ke . '"';
                        if(isset($val['#size'])){
                            $result .= ' size="' . $val['#size'] . '"';
                        }
                        if(isset($val['#value'])){
                            $result .= ' value="' . ($val['#type'] == 'submit' ? ucwords($val['#value']) : $val['#value']) . '"';
                        }
                        if(isset($val['#style'])){
                            $result .= ' style="' . $val['#style'] . '"';
                        }
                        if(isset($val['#extra'])){
                            $result .= ' ' . $val['#extra'];
                        }
                        $result .= '>' . "\n";
                    } elseif(in_array($val['#type'], $formtextarea)){
                        $result .= '<textarea name="' . $ke . '" cols="' . (isset($val['#cols']) ? $val['#cols'] : '40') . '" rows="' . (isset($val['#rows']) ? $val['#rows'] : '3') . '"';
                        if(isset($val['#style'])){
                            $result .= ' style="' . $val['#style'] . '"';
                        }
                        if(isset($val['#extra'])){
                            $result .= ' ' . $val['#extra'];
                        }
                        $result .= '>';
                        if(isset($val['#value'])){
                            $result .= $val['#value'];
                        }
                        $result .= '</textarea>' . "\n";
                    } elseif(in_array($val['#type'], $formselect)){
                        $result .= '<select name="' . $ke . '" size="' . (isset($val['#size']) ? $val['#size'] : 1) . '"';
                        if(isset($val['#style'])){
                            $result .= ' style="' . $val['#style'] . '"';
                        }
                        if(isset($val['#extra'])){
                            $result .= ' ' . $val['#extra'];
                        }
                        $result .= '>';
                        if(isset($val['#option_blank']) && $val['#option_blank'] == '1'){
                            $result .= '<option value=""></option>' . "\n";
                        }
                        foreach($val['#option'] as $yk => $lv){
                            $result .= '<option value="' . $yk . '"';
                            if($yk == $val['#value']){
                                $result .= ' selected';
                            }
                            $result .= '>' . $lv . '</option>';
                        }
                        $result .= '</select>';
                    } elseif($val['#type'] == 'date'){
                        $val['#value'] = $val['#value'] == '' ? array('0000', '00', '00') : explode('-', $val['#value']);
                        krsort($val['#value']);
                        foreach($val['#value'] as $kk => $vv){
                           if($kk == 1){
                                $result .= '<select name="' . $ke . '[' . $kk . ']" size="1"';
                                if(isset($val['#style'])){
                                    $result .= ' style="' . $val['#style'] . '"';
                                }
                                if(isset($val['#extra'])){
                                    $result .= ' ' . $val['#extra'];
                                }
                                $result .= '>';
                                foreach($val['#option'] as $yk => $lv){
                                    $result .= '<option value="' . $yk . '"';
                                    if($yk == $vv){
                                          $result .= ' selected';
                                    }
                                    $result .= '>' . ucwords($lv) . '</option>';
                                }
                                $result .= '</select>' . "\n";
                            } else {
                                $result .= '<input type="text" name="' . $ke . '[' . $kk . ']" maxlength="' . ($kk > 0 ? 2 : 4) . '"';
                                if(isset($val['#size'])){
                                    $result .= ' size="' . ($kk > 0 ? 2 : 4) . '"';
                                }
                                if(isset($val['#value'])){
                                    $result .= ' value="' . $vv . '"';
                                }
                                if(isset($val['#style'])){
                                    $result .= ' style="' . $val['#style'] . '"';
                                }
                                if(isset($val['#extra'])){
                                    $result .= ' ' . $val['#extra'];
                                }
                                if($value['#id'] == 'login' && $val['#type'] == 'submit'){
                                    $result .= ' class="button"';
                                }
                                $result .= '>' . "\n";
                            }
                        }
                    } elseif($val['#type'] == 'info'){
                        if(isset($val['#link'])){
                            $result .= '<a href="' . $val['#link'] . '">';
                        }
                        $result .= ucwords(strtolower($val['#value']));
                        if(isset($val['#link'])){
                            $result .= '</a>' . "\n";
                        }
                    }
                    break;
                }
            }
        }
        $result .= '</div>' . "\n";
        $result .= '</td>' . "\n";
        $cols ++;
        if($i>3){$cols++;}
        if($cols > 1){
            $result .= '</tr>' . "\n";
            $cols = 0;
        }
    } unset($cols, $i);
    $result .= '</table>' . "\n";
    $result .= '</div>' . "\n";
    $result .= '<div>' . "\n";
//    echo '<pre>'; print_r($value['#intercols']); echo '</pre>';
    $result .= '<table width="100%" align="center" style="border:1px solid black">';
    $result .= '<tr>' . "\n";
    foreach($value['#interpos'] as $ke => $val){
        $result .= '<td width="' . (100/count($value['#interpos'])) . '%" align="center">';
        $result .= '<strong>' . strtoupper($val) . '</strong>';
        $result .= '</td>' . "\n";
    }
    $result .= '</tr>' . "\n";
    $result .= '<tr>' . "\n";
    foreach($value['#interpos'] as $ke => $val){
        $result .= '<td width="' . (100/count($value['#interpos'])) . '%" align="center">';
        $result .= '<table width="100%" align="center" border="1">';
        $result .= '<tr>';
        for($i=0; $i<2; $i++){
            $result .= '<td>&nbsp;</td>' . "\n";
        }
        foreach($value['#intercols'] as $ky => $vl){
            $result .= '<td>' . $vl . '</td>';
        }
        $result .= '</tr>';
        foreach($value['#interpreter'] as $ky => $vl){
            if(isset($vl['micro'])){
                $i = 0;
                foreach($vl['micro'] as $yk => $lv){
                    $result .= '<tr>' . "\n";
                    if($i < 1){$result .= '<td rowspan="2">' . $vl['alias'] . '</td>' . "\n";}
                    $result .= '<td>' . $lv . '</td>' . "\n";
                    foreach($value['#intercols'] as $yek => $lav){
                        $result .= '<td>';
                        foreach($value['data'] as $eyk => $eulav){
                            $dump = explode('_', $eyk);
                            if(count($dump) > 3 && $dump[0] == $val && $dump[1] == $ky && $dump[2] == $yk && $dump[3] == $yek){
                                $result .= '<input type="' . $eulav['#type'] . '" name="' . $eyk . '" value="' . $eulav['#value'] . '" size="' . $eulav['#size'] . '">';
                                unset($dump);
                                break;
                            }
                        }
                        $result .= '</td>';
                    } $i++;
                    $result .= '</tr>' . "\n";
                }
            } else {
                $result .= '<tr>' . "\n";
                $result .= '<td colspan=2>' . $vl['alias'] . '</td>';
                foreach($value['#intercols'] as $yk => $lv){
                    $result .= '<td>';
                    foreach($value['data'] as $yek => $lav){
                        $dump = explode('_', $yek);
                        if(count($dump) < 4 && $dump[0] == $val && $dump[1] == $ky && $dump[2] == $yk){
                            $result .= '<input type="' . $lav['#type'] . '" name="' . $yek . '" value="' . $lav['#value'] . '" size="' . $lav['#size'] . '">';
                            unset($dump);
                            break;
                        }
                    }
                    $result .= '</td>';
                }
                $result .= '</tr>' . "\n";
            }
        }
        $result .= '</table>' . "\n";
        $result .= '</td>' . "\n";
    }
    $result .= '</tr>' . "\n";
    $result .= '</table>' . "\n";
    $result .= '</div>' . "\n";
    $result .= '<div>' . "\n";
//    echo '<pre>'; print_r($value); echo '</pre>';
        foreach($value as $ke => $val){
            if(!eregi('#', $ke) && $ke != 'data'){
                if(!isset($val['#tbpos'])){
                    if($ke == 'interpretasi' || $ke == 'submit'){
                        $result .= '<br />' . ($ke == 'submit' ? '<br />' : '');
                    }
                    if(isset($val['#title']) && $val['#title'] != 'hidden' && $val['#type'] != 'hidden'){
                        $result .= '<label for="'. $ke .'" style="width:100px">' . ucwords($val['#title']) . ' :</label>';
                    }
                    if(in_array($val['#type'], $forminput)){
                        $result .= '<input type="' . $val['#type'] . '" name="' . $ke . '"';
                        if(isset($val['#size'])){
                            $result .= ' size="' . $val['#size'] . '"';
                        }
                        if(isset($val['#value'])){
                            $result .= ' value="' . ($val['#type'] == 'submit' ? ucwords($val['#value']) : $val['#value']) . '"';
                        }
                        if(isset($val['#style'])){
                            $result .= ' style="' . $val['#style'] . '"';
                        }
                        if(isset($val['#extra'])){
                            $result .= ' ' . $val['#extra'];
                        }
                        $result .= '>' . "\n";
                    } elseif(in_array($val['#type'], $formtextarea)){
                        $result .= '<textarea name="' . $ke . '" cols="' . (isset($val['#cols']) ? $val['#cols'] : '40') . '" rows="' . (isset($val['#rows']) ? $val['#rows'] : '3') . '"';
                        if(isset($val['#style'])){
                            $result .= ' style="' . $val['#style'] . '"';
                        }
                        if(isset($val['#extra'])){
                            $result .= ' ' . $val['#extra'];
                        }
                        $result .= '>';
                        if(isset($val['#value'])){
                            $result .= $val['#value'];
                        }
                        $result .= '</textarea>' . "\n";
                    } elseif(in_array($val['#type'], $formselect)){
                        $result .= '<select name="' . $ke . '" size="' . (isset($val['#size']) ? $val['#size'] : 1) . '"';
                        if(isset($val['#style'])){
                            $result .= ' style="' . $val['#style'] . '"';
                        }
                        if(isset($val['#extra'])){
                            $result .= ' ' . $val['#extra'];
                        }
                        $result .= '>';
                        if(isset($val['#option_blank']) && $val['#option_blank'] == '1'){
                            $result .= '<option value=""></option>' . "\n";
                        }
                        foreach($val['#option'] as $yk => $lv){
                            $result .= '<option value="' . $yk . '"';
                            if($yk == $val['#value']){
                                $result .= ' selected';
                            }
                            $result .= '>' . $lv . '</option>';
                        }
                        $result .= '</select>';
                    } elseif($val['#type'] == 'date'){
                        $val['#value'] = $val['#value'] == '' ? array('0000', '00', '00') : explode('-', $val['#value']);
                        krsort($val['#value']);
                        foreach($val['#value'] as $kk => $vv){
                           if($kk == 1){
                                $result .= '<select name="' . $ke . '[' . $kk . ']" size="1"';
                                if(isset($val['#style'])){
                                    $result .= ' style="' . $val['#style'] . '"';
                                }
                                if(isset($val['#extra'])){
                                    $result .= ' ' . $val['#extra'];
                                }
                                $result .= '>';
                                foreach($val['#option'] as $yk => $lv){
                                    $result .= '<option value="' . $yk . '"';
                                    if($yk == $vv){
                                          $result .= ' selected';
                                    }
                                    $result .= '>' . ucwords($lv) . '</option>';
                                }
                                $result .= '</select>' . "\n";
                            } else {
                                $result .= '<input type="text" name="' . $ke . '[' . $kk . ']" maxlength="' . ($kk > 0 ? 2 : 4) . '"';
                                if(isset($val['#size'])){
                                    $result .= ' size="' . ($kk > 0 ? 2 : 4) . '"';
                                }
                                if(isset($val['#value'])){
                                    $result .= ' value="' . $vv . '"';
                                }
                                if(isset($val['#style'])){
                                    $result .= ' style="' . $val['#style'] . '"';
                                }
                                if(isset($val['#extra'])){
                                    $result .= ' ' . $val['#extra'];
                                }
                                if($value['#id'] == 'login' && $val['#type'] == 'submit'){
                                    $result .= ' class="button"';
                                }
                                $result .= '>' . "\n";
                            }
                        }
                    } elseif($val['#type'] == 'info'){
                        if(isset($val['#link'])){
                            $result .= '<a href="' . $val['#link'] . '">';
                        }
                        $result .= ucwords(strtolower($val['#value']));
                        if(isset($val['#link'])){
                            $result .= '</a>' . "\n";
                        }
                    }
//                break;
                }
            }
        }
    $result .= '</div>' . "\n";
    $result .= '</form>' . "\n";
}
