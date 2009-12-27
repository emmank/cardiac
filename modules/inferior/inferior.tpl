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
 *  inferior.php
 *
 *  Created on Oct 28, 2009, 9:51:59 AM
 */
//echo '<pre>'; print_r($vl); echo '</pre>';
$result .= '<div id="fisis' . $ke . '" class="tabcontent">' . "\n";
//$result .= $vl['#title'];
$result .= '<a id="toggle-ainferiorhidden-div" href="#toggle-ainferiorhidden-div">Artery </a><br />';
$result .= '<a id="toggle-vinferiorhidden-div" href="#toggle-vinferiorhidden-div">Vena </a>';
$result .= '<div id="ainferiorhidden-div" style="display: none">';
$result .= '<table width=100% class="table" border="0">' . "\n";
foreach($vl['datafields'] as $yk => $lv){
    if($lv['#type'] != 'hidden'){
        if(isset($lv['#customized'])){
            if(!isset($rowspan[$lv['#customized']['id']])){$rowspan[$lv['#customized']['id']] = array();}
            $rowspan[$lv['#customized']['id']][] = $yk;
        }
    }
}
//Retrieve data from class
//echo "<pre>";print_r($vl);echo "</pre>";
foreach($vl['datafields'] as $yk => $lv){
    if($lv['#type'] != 'hidden'){
        $result .= '<tr valign="top">' . "\n";
        if(!isset($lv['#customized'])){
            if (preg_match('/vena/',$yk)){

            } else {
                $result .= '<td align="right" width="25%" rowspan="6">' . ucwords($lv['#title']) . ': </td>' . "\n";
                $result .= '<td align="left" width="10%" rowspan="6">';
            }
            if($lv['#type'] == 'select'){
                if(isset($lv['#readonly']) && trim($lv['#readonly']) != '' && $lv['#readonly'] !== FALSE){
//                        $result .= $lv['#theref'][$lv['#value']];
                   if (preg_match('/vena/',$yk)){
                            //Something todo
                        }
                        else {
                            $nilai = explode('|',$lv['#value']);
//                            echo "<pre>";print_r($lv);echo "</pre>";
    //                        echo "<pre>";print_r($nilai);echo "</pre>";
                            $result .= $lv['#theref'][$nilai[0]];
                            $result .= '</td><td width="10%" align="right">';
                            $result .= 'Diameter : </td><td>' . $nilai[1] . '</td>';
                            $result .= '<tr><td width="10%" align="right">';
                            $result .= 'Flow : </td><td>' . $nilai[2] . '</td>';
                            $result .= '<tr><td width="10%" align="right">';
                            $result .= 'Steunosis : </td><td>' . $nilai[3] . '</td>';
                            $result .= '<tr><td width="10%" align="right">';
                            $result .= 'Thrambus : </td><td>' . $nilai[4] . '</td>';
                            $result .= '<tr><td width="10%" align="right">';
                            $result .= 'Kalsifkasi : </td><td>' . $nilai[5] . '</td>';
                            $result .= '<tr><td width="10%" align="right">';
                            $result .= 'Lain : </td><td>' . $nilai[6];
                    }
                    } else {

                        if (preg_match('/vena/',$yk)){
                            //Something todo
                        }
                        else {

                            $result .= '<select name="' . $yk . '[0]" size="1">';
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
                            foreach($lv['#theref'] as $kk => $vv){
                                $result .= '<option value="' . $kk . '"' . (isset($lv['#value']) && $lv['#value'] == $kk ? ' selected="selected"' : '') . '>' . $vv . '</option>';
                            }
                            $result .= '</select></td><td width="10%" align="right">';

                            $result .= 'Diameter </td><td>';
                            $result .= '<select name="' . $yk . '[1]" size="1">';
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
//                            foreach($lv['#theref'] as $kk => $vv){
                                $result .= '<option value="Normal">Normal </option>';
                                $result .= '<option value="Kecil">Kecil </option>';
                                $result .= '<option value="Lebar">Lebar </option>';
//                            }
                            $result .= '</select><tr><td width="10%" align="right">';
                            $result .= 'Flow </td><td>';
                            $result .= '<select name="' . $yk . '[2]" size="1">';
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
//                            foreach($lv['#theref'] as $kk => $vv){
                                $result .= '<option value="Triphesic">Triphesic </option>';
                                $result .= '<option value="Biphesic">Biphesic </option>';
                                $result .= '<option value="Monophesic">Monophesic </option>';
//                            }
                            $result .= '</select><tr><td width="10%" align="right">';
                            $result .= 'Steunosis </td><td>';
                            $result .= '<select name="' . $yk . '[3]" size="1">';
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
//                            foreach($lv['#theref'] as $kk => $vv){
                                $result .= '<option value="Mild">Mild </option>';
                                $result .= '<option value="Moderate">Moderate </option>';
                                $result .= '<option value="Severe">Severe </option>';
//                            }
                            $result .= '</select><tr><td width="10%" align="right">';
                            $result .= 'Thrambus </td><td>';
                            $result .= '<select name="' . $yk . '[4]" size="1">';
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
//                            foreach($lv['#theref'] as $kk => $vv){
                                $result .= '<option value="Kecil">Kecil </option>';
                                $result .= '<option value="Sedang">Sedang </option>';
                                $result .= '<option value="Besar">Besar </option>';
                                $result .= '<option value="Tidak ada">Tidak ada</option>';
//                            }
                            $result .= '</select><tr><td width="10%" align="right">';
                            $result .= 'Kalsifkasi </td><td>';
                            $result .= '<select name="' . $yk . '[5]" size="1">';
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
//                            foreach($lv['#theref'] as $kk => $vv){
                                $result .= '<option value="Mild">Mild </option>';
                                $result .= '<option value="Moderate">Moderate </option>';
                                $result .= '<option value="Severe">Severe </option>';
                                $result .= '<option value="Tidak">Tidak </option>';
//                            }
                            $result .= '</select><tr><td width="10%" align="right">';
                            $result .= 'Lain </td><td>';
                            $result .= '<select name="' . $yk . '[6]" size="1">';
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
//                            foreach($lv['#theref'] as $kk => $vv){
                                $result .= '<option value="Tourtous">Tourtous </option>';
                                $result .= '<option value="Ancurysma">Ancurysma </option>';
//                            }
                            $result .= '</select>';


                        }
                    }

        } else {
            if(!is_array($lv['#value'])){
//                $lv['#value'] = explode('|', $lv['#value']);
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
//                    $result .= $lv['#value'][0];
                } else {
                    foreach($lv['#customized']['option'] as $kk => $vv){
                        if(isset($koma)){
                            $result .= '<br />';
                        }
                        $result .= '<input type="radio" name="' . $ky . '_' . $yk . '[0]" value="' . $kk . '"' . (isset($lv['#value'][0]) && $lv['#value'][0] == $kk ? ' checked="true"' : '') . '> ' . $vv . "\n";
                        $koma = 0;
                    } unset($koma);
                }
            }
            $result .= '</td>' . "\n";
        }
        $result .= '</tr>' . "\n";

    }
    }

} unset($rowspan, $dumpt);

$result .= '</table>' . "\n";
$result .= '</div>';
unset($nilai);

$result .= '<div id="vinferiorhidden-div" style="display: none">';
$result .= '<table width=100% class="table" border="0">' . "\n";
foreach($vl['datafields'] as $yk => $lv){
    if($lv['#type'] != 'hidden'){
        if(isset($lv['#customized'])){
            if(!isset($rowspan[$lv['#customized']['id']])){$rowspan[$lv['#customized']['id']] = array();}
            $rowspan[$lv['#customized']['id']][] = $yk;
        }
    }
}

foreach($vl['datafields'] as $yk => $lv){
    if($lv['#type'] != 'hidden'){
        $result .= '<tr valign="top">' . "\n";
        if(!isset($lv['#customized'])){
            if (preg_match('/vena/',$yk)){
                $result .= '<td align="right" width="25%" rowspan="6">' . ucwords($lv['#title']) . ': </td>' . "\n";
                $result .= '<td align="left" width="10%" rowspan="6">';
            } else {

            }
            if($lv['#type'] == 'select'){
                if(isset($lv['#readonly']) && trim($lv['#readonly']) != '' && $lv['#readonly'] !== FALSE){
//                        $result .= $lv['#theref'][$lv['#value']];
                    if (preg_match('/vena/',$yk)){
                        $nilai = explode('|',$lv['#value']);
//                        echo "<pre>";print_r($lv['#theref']);echo "</pre>";
//                        echo "<pre>2222";echo "</pre>";
                        $result .= $lv['#theref'][$nilai[0]];
                        $result .= '</td><td width="10%" align="right">';
                        $result .= 'Diameter </td><td> : ' . $nilai[1] . '</td>';
                        $result .= '<tr><td width="10%" align="right">';
                        $result .= 'Flow </td><td> : ' . $nilai[2] . '</td>';
                        $result .= '<tr><td width="10%" align="right">';
                        $result .= 'Compression ultrasonography </td><td> : ' . $nilai[3] . '</td>';
                        $result .= '<tr><td width="10%" align="right">';
                        $result .= 'Uji Squeezing </td><td> : ' . $nilai[4] . '</td>';
                        $result .= '<tr><td width="10%" align="right">';
                        $result .= 'Refluks </td><td> : ' . $nilai[5] . '</td>';
                        $result .= '<tr><td width="10%" align="right">';
                        $result .= 'Thrambus </td><td> : ' . $nilai[6];
                    }
                    else {

                    }

                    } else {

                        if (preg_match('/vena/',$yk)){

                            $result .= '<select name="' . $yk . '[0]" size="1">';
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
                            foreach($lv['#theref'] as $kk => $vv){
                                $result .= '<option value="' . $kk . '"' . (isset($lv['#value']) && $lv['#value'] == $kk ? ' selected="selected"' : '') . '>' . $vv . '</option>';
                            }
                            $result .= '</select></td><td width="10%" align="right">';

                            $result .= 'Diameter </td><td>';
                            $result .= '<select name="' . $yk . '[1]" size="1">';
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
                                $result .= '<option value="Normal">Normal </option>';
                                $result .= '<option value="Kecil">Kecil </option>';
                                $result .= '<option value="Lebar">Lebar </option>';
                            $result .= '</select><tr><td width="10%" align="right">';

                            $result .= 'Flow </td><td>';
                            $result .= '<select name="' . $yk . '[2]" size="1">';
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
                                $result .= '<option value="Triphesic">Triphesic </option>';
                                $result .= '<option value="Biphesic">Biphesic </option>';
                                $result .= '<option value="Monophesic">Monophesic </option>';
                            $result .= '</select><tr><td width="10%" align="right">';

                            $result .= 'Compression ultrasonography </td><td>';
                            $result .= '<select name="' . $yk . '[3]" size="1">';
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
                                $result .= '<option value="Positif">Positif </option>';
                                $result .= '<option value="Negatif">Negatif </option>';
                            $result .= '</select><tr><td width="10%" align="right">';

                            $result .= 'Uji Squeezing </td><td>';
                            $result .= '<select name="' . $yk . '[4]" size="1">';
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
                                $result .= '<option value="Positif">Positif </option>';
                                $result .= '<option value="Negatif">Negatif </option>';
                            $result .= '</select><tr><td width="10%" align="right">';

                            $result .= 'Refluks </td><td>';
                            $result .= '<select name="' . $yk . '[5]" size="1">';
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
                                $result .= '<option value="Positif">Positif </option>';
                                $result .= '<option value="Negatif">Negatif </option>';
                            $result .= '</select><tr><td width="10%" align="right">';

                            $result .= 'Thrambus </td><td>';
                            $result .= '<select name="' . $yk . '[6]" size="1">';
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
                                $result .= '<option value="Kecil">Kecil </option>';
                                $result .= '<option value="Sedang">Sedang </option>';
                                $result .= '<option value="Besar">Besar </option>';
                            $result .= '</select>';

                        }
                        else {
                            //something todo

                        }
                    }

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
                        $result .= '<input type="radio" name="' . $ky . '_' . $yk . '[0]" value="' . $kk . '"' . (isset($lv['#value'][0]) && $lv['#value'][0] == $kk ? ' checked="true"' : '') . '> ' . $vv . "\n";
                        $koma = 0;
                    } unset($koma);
                }
            }
            $result .= '</td>' . "\n";
        }
        $result .= '</tr>' . "\n";
    }
    }

} unset($rowspan, $dumpt);

$result .= '</table>' . "\n";
$result .= '</div>';
unset($nilai);
$result .= '</div>' . "\n";