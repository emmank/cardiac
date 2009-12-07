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
 *  presentStatus.php
 *  
 *  Created on Oct 28, 2009, 9:51:59 AM
 */
$result .= '<div id="fisis' . $ke . '" class="tabcontent">' . "\n";
//$result .= $vl['datafields']['Fase Latihan']['title'];
$result .= '<table width=100% class="table" border="0">' . "\n";
foreach($vl['datafields'] as $yk => $lv){
    $result .= '<tr valign="top">' . "\n";
    $result .= '<td style="font-weight:bold" align="left" width="4%">' . strtoupper($yk) . '</td>' . "\n";
    $result .= '<td align="left">' . "\n";
    foreach($lv as $kk => $vv){
        $result .= '<div>' . __t($kk) .'</div>' . "\n";
        if(!isset($vv['type'])){
            $htg = 1;
            $result .= '<div>' . "\n";
            $result .= '<table width="100%" align="left">' . "\n";
            foreach($vv as $yy => $ll){
                $result .= '<tr valign="top">' . "\n";
                $result .= '<td align="right" width="5%">' . $htg . '. </td>' . "\n";
                $result .= '<td align="left" width="25%">' . __t($yy) . '</td>' . "\n";
                $result .= '<td align="' . (eregi('st', $yy) ? 'left' : 'left') . '">' . "\n";
                if(!isset($ll['type'])){
                    foreach($ll as $ee => $uu){
                        $result .= '<div>' . "\n";
                        if($ee != $yy) {
                            $result .= __t($uu['title']) . ' : ';
                        }
                        if(isset($uu['value'])){
                            $uu['value'] = explode('|', $uu['value']);
                        }
                        if($uu['type'] == 'select'){
                            $result .= '<select name="' . $ky . '_' . $ee . '[0]" size="1">' . "\n";
                            foreach($uu['theref'] as $ey => $al){
                                $result .= '<option name="' . $ey . '"' . (isset($uu['value'][0]) && $uu['value'][0] == $ey ? ' selected' : '') . '>' . __t($al) . '</option>' . "\n";
                            }
                            $result .= '</select>' . "\n";
                        } elseif($uu['type'] == 'radio'){
                            $result .= '<div>' . "\n";
                            $gth = 1;
                            foreach($uu['theref'] as $ey => $al){
                                $result .= '<input type="radio" name="' . $ky . '_' . $ee . '[0]" value="' . $ey . '"' . (isset($uu['value'][0]) && $uu['value'][0] == $ey ? ' checked="true"' : '') . '>' . __t($al);
                                if(eregi('hipert', $al)){
                                    $result .= ' ' . __t('sistolik') . ' <input type="text" name="' . $ky . '_' . $ee . '[' . $gth . ']"' . (isset($uu['value'][1]) && $uu['value'][0] == $ey ? ' value="' . $uu['value'][1] . '"' : '') . ' size="5"> mmHg' . "\n";
                                    $gth++;
                                    $result .= ', ' . __t('diastolik') . ' <input type="text" name="' . $ky . '_' . $ee . '[' . $gth . ']"' . (isset($uu['value'][2]) && $uu['value'][0] == $ey ? ' value="' . $uu['value'][2] . '"' : '') . ' size="5"> mmHg' . "\n";
                                    $gth++;
                                }
                                $result .= "<br />\n";
                            } unset($gth);
                            $result .= '</div>' . "\n";
                        } else {
                            $result .= '<input type="text" name="' . $ky . '_' . $ee . '[0]" size="' . (isset($uu['size']) ? $uu['size'] : '') . '">' . "\n";
                        }
                        if(!eregi('konfigurasi', $ee) && eregi('ekg', $kk)){
                            $result .= ' ' . __t('pada menit ke') . ' : ';
                            $result .= '<input type="text" name="' . $ky . '_' . $ee . '[1]" size="' . (isset($uu['size']) ? $uu['size'] : '') . '">' . "\n";
                        }
                        $result .= '</div>' . "\n";
                    }
                } else {
                    if(isset($ll['value'])){
                        $ll['value'] = explode('|', $ll['value']);
                    }
                    if($ll['type'] == 'select'){
                        $result .= '<select name="' . $ky . '_' . $yy . '[0]" size="1">' . "\n";
                        foreach($ll['theref'] as $ee => $uu){
                            $result .= '<option value="' . $ee . '"' . (isset($ll['value'][0]) && $ll['value'][0] == $ee ? ' selected' : '') . '>' . __t($uu) . '</option>' . "\n";
                        }
                        $result .= '</select>' . "\n";
                    } elseif($ll['type'] == 'radio'){
                        foreach($ll['theref'] as $ee => $uu){
                            $result .= '<input type="radio" name="' . $ky . '_' . $ee . '[0]" value="' . $ee . '"' . (isset($ll['value'][0]) && $ll['value'][0] == $ee ? ' checked="true"' : '') . '> ' . __t($uu) . "<br />\n";
                        }
                    } else {
                        $result .= '<input type="text" name="' . $ky . '_' . $yy . '[0]" size="' . (isset($ll['value'][0]) ? $ll['value'][0] : '') . '">' . "\n";
                    }
                    if(eregi('irama', $yy)){
                        $result .= ' ' . __t('pada menit ke') . ' <input type="text" name="' . $ky. '_' . $yy . '[1]" size="10">' . "\n";
                    }
                }
                $result .= '</td>' . "\n";
                $result .= '</tr>' . "\n";
                $htg++;
            } unset($htg);
            $result .= '</table>' . "\n";
            $result .= '</div>' . "\n";
        } else {
            if(isset($vv['value'])){
                $vv['value'] = explode('|', $vv['value']);
            }
            $result .= '<div>' . "\n";
            if($vv['type'] == 'text'){
                $result .= '<input type="text" name="' .   $ky . '_' . $kk . ($kk == 'protokol' ? '[0]' : '') . '" size="' . (isset($vv['size']) ? $vv['size'] : 20) . '">';
                if($kk == 'protokol'){
                    $result .= ' ' . __t('Stage') . ' ' . __t('lamanya') . ' : <input type="text" name="' . $ky . '_' . $kk . '[1]" size="' . (isset($vv['size']) ? $vv['size'] : 20) . '"> ' . __t('menit') . "\n";
                }
            } elseif($vv['type'] == 'select'){
                $result .= '<select name="' . $ky . '_' . $kk . '[0]" size="1">' . "\n";
                foreach($vv['theref'] as $yy => $ll){
                    $result .= '<option value="' . $yy . '"' . (isset($vv['value'][0]) && $vv['value'][0] == $yy ? ' selected' : '') . '>' . __t($ll) . '</option>' . "\n";
                }
                $result .= '</select>' . "\n";
            }
            $result .= '</div>' . "\n";
        }
    }
    $result .= '</td>' . "\n";
    $result .= '</tr>' . "\n";
}
$result .= '</table>' . "\n";
$result .= '</div>' . "\n";
