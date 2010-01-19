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
 *  neck.php
 *  
 *  Created on Oct 28, 2009, 9:51:59 AM
 */

$result .= '<div id="fisis' . $ke . '" class="tabcontent">' . "\n";
$result .= $vl['datafields']['neck']['title'];
$result .= '<table width=100% class="table">' . "\n";
$cnt = 0;
// echo '<pre>'; print_r($vl['datafields']); echo '</pre>';
foreach($vl['datafields'] as $yk => $lv){
    if($lv['type'] != 'hidden'){
        if($cnt < 1){
            $result .= '<tr valign="top">' . "\n";
        }
        $result .= '<td width="25%">' .ucwords (str_replace ("_"," ", $lv['title'])) . '</td>';
        $result .= '<td>';
        if($lv['type'] == 'select'){
            if($lv['readonly'] === true){
//                $result .= $lv['theref'][$lv['value']] . "\n";
                $lv['value'] = explode('|',$lv['value']);
                $result .= $lv['value'][0] . ', ' . $lv['value'][1] . ', ' . $lv['value'][2] . ', ukuran: ' . $lv['value'][3];
//                echo '<pre>'; print_r($lv); echo '</pre>';
            } else {
                $result .= '<select name="' . $yk . '[0]" size="' . $lv['size']. '" style="width:110px;">' . "\n";
                if(isset($lv['blankopt'])){
                    $result .= '<option value=""></option>';
                }
//                foreach($lv['theref'] as $kc => $isi){
                    $result .= '<option value="-"> - </option>' . "\n";
                    $result .= '<option value="Teraba bagian kiri">Teraba bagian kiri</option>' . "\n";
                    $result .= '<option value="Teraba bagian kanan">Teraba bagian kanan</option>' . "\n";
                    $result .= '<option value="Tidak Teraba">Tidak Teraba</option>' . "\n";
//                }
                $result .= '</select>' . "\n";
                $result .= '<select name="' . $yk . '[1]" size="' . $lv['size']. '" style="width:110px;">' . "\n";
                if(isset($lv['blankopt'])){
                    $result .= '<option value=""></option>';
                }
//                foreach($lv['theref'] as $kc => $isi){
                    $result .= '<option value="-"> - </option>' . "\n";
                    $result .= '<option value="Bisa digerakkan">Bisa digerakkan</option>' . "\n";
                    $result .= '<option value="Tidak bisa digerakkan">Tidak bisa digerakkan</option>' . "\n";
//                }
                $result .= '</select>' . "\n";
                $result .= '<select name="' . $yk . '[2]" size="' . $lv['size']. '" style="width:110px;">' . "\n";
                if(isset($lv['blankopt'])){
                    $result .= '<option value=""></option>';
                }
//                foreach($lv['theref'] as $kc => $isi){
                    $result .= '<option value="-"> - </option>' . "\n";
                    $result .= '<option value="Terasa nyeri">Terasa nyeri</option>' . "\n";
                    $result .= '<option value="Tidak nyeri">Tidak nyeri</option>' . "\n";
//                }
                $result .= '</select>' . "\n";
                $result .= 'ukuran <input type="text" name="' . $yk . '[3]" size="4" maxlength="4">' . "\n";
            }
        } elseif($lv['type'] == 'select2'){
//            $lv['value'] = explode('|', $lv['value']);
            if($lv['readonly'] === true){
//                $lv['value'] = explode('|',$lv['value']);
//                echo '<pre>'; print_r($lv); echo '</pre>';
                $result .= $lv['value'];
                
            } else {
                $result .= '<select name="' . $yk . '" size="' . $lv['size']. '" style="width:110px;">' . "\n";
                if(isset($lv['blankopt'])){
                    $result .= '<option value=""></option>';
                }
//                foreach($lv['theref'] as $kc => $isi){
                    $result .= '<option value="-"> - </option>' . "\n";
                    $result .= '<option value="Deviasi ke kiri">Deviasi ke kiri</option>' . "\n";
                    $result .= '<option value="Deviasi ke kanan">Deviasi ke kanan</option>' . "\n";
                    $result .= '<option value="Normal">Normal</option>' . "\n";
//                }
                $result .= '</select>' . "\n";
            }
        } elseif($lv['type'] == 'select3'){
            if($lv['readonly'] === true){
                $result .= $lv['theref'][$lv['value']];
            } else {
                $result .= '<select name="' . $yk . '" size="' . $lv['size']. '" style="width:110px;">' . "\n";
                if(isset($lv['blankopt'])){
                    $result .= '<option value=""></option>';
                }
//                foreach($lv['theref'] as $kc => $isi){
                    $result .= '<option value="-"> - </option>' . "\n";
                    $result .= '<option value="Ada">Ada</option>' . "\n";
                    $result .= '<option value="Tidak ada">Tidak ada</option>' . "\n";
//                }
                $result .= '</select>' . "\n";
            }
        } elseif($lv['type'] == 'datetime'){
            if(isset($lv['value'])){
                $datetime = $lv['value'];
            } else {
                $datetime = date('Y-m-d H:i:s', $lv['timenow']);
            }
            list($dumptgl, $dumptime) = explode(' ', $datetime);
            unset($datetime);
            $dumptgl = explode('-', $dumptgl);
            $dumptime = explode(':', $dumptime);
            if($lv['readonly'] === true){
                $result .= $dumptgl[2] . "&nbsp;";
                $result .= $lv['theref'][$dumptgl[1]] . "&nbsp;";
                $result .= $dumptgl[0] . "&nbsp;";
                $result .= $dumptime[0] . ":";
                $result .= $dumptime[1] . ":";
                $result .= $dumptime[2];
            } else {
                $result .= '<input type="text" name="' . $yk . '[2]" size="2" maxlength="2" value="' . $dumptgl[2] . '">' . "&nbsp";
                $result .= '<select name="' . $yk . '[1]" size="1">' . "\n";
                foreach($lv['theref'] as $kc => $isi){
                    $result .= '<option value="' . $kc . '"' . ($dumptgl[1] == $kc ? ' selected=selected' : '') . '>' . $isi . '</option>' . "\n";
                }
                $result .= '</select>' . "&nbsp;";
                $result .= '<input type="text" name="' . $yk . '[0]" size="4" maxlength="4" value="' . $dumptgl[0] . '">' . "<br />\n";
                $result .= '<input type="text" name="' . $yk . '[3]" size="2" maxlength="2" value="' . $dumptime[0] . '">' . ":";
                $result .= '<input type="text" name="' . $yk . '[4]" size="2" maxlength="2" value="' . $dumptime[1] . '">' . ":";
                $result .= '<input type="text" name="' . $yk . '[5]" size="2" maxlength="2" value="' . $dumptime[2] . '">' . "\n";
            }
        } else {
            if($lv['readonly'] === true){
                $result .= $lv['value'];
            } else {
                $result .= '<input type="' . $lv['type'] . '" name="' . $yk . '"' . (isset($lv['size']) ? ' size="6"' : '') . (isset($lv['value']) ? ' value="' . $lv['value'] . '"' : '') . '>' . "\n";
            }
        }
        $result .= '</td>' . "\n";
//        $cnt++;
        if($cnt > 1){
            $cnt = 0;
            $result .= '</tr>' . "\n";
        }
    }
} unset($cnt);
$result .= '</table>' . "\n";
$result .= '</div>' . "\n";