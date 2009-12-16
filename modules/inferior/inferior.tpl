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
$result .= '<table width=100% class="table" border="1">' . "\n";
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
            $result .= '<td align="right" width="15%" rowspan="6">' . ucwords($lv['#title']) . '</td>' . "\n";
            $result .= '<td align="left" width="15%" rowspan="6">';
            if($lv['#type'] == 'select'){
                if(isset($lv['#readonly']) && trim($lv['#readonly']) != '' && $lv['#readonly'] !== FALSE){
                        $result .= $lv['#theref'][$lv['#value']];
                    } else {
                        if (preg_match('/vena/',$yk)){
                            $result .= '<select name="' . $yk . '[0]" size="1">';
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
                            foreach($lv['#theref'] as $kk => $vv){
                                $result .= '<option value="' . $kk . '"' . (isset($lv['#value']) && $lv['#value'] == $kk ? ' selected="selected"' : '') . '>' . $vv . '</option>';
                            }
                            $result .= '</select></td><td width="10%" align="right">';

                            $result .= 'Diameter </td><td>';
<<<<<<< HEAD
                            $result .= '<select name="' . $yk . '[0]" size="1">';
=======
                            $result .= '<select name="' . $yk . '[1]" size="1">';
>>>>>>> b9c8420f4362aab62a817374ce92e2cb8711d8da
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
                                $result .= '<option value="Normal">Normal </option>';
                                $result .= '<option value="Kecil">Kecil </option>';
                                $result .= '<option value="Lebar">Lebar </option>';
                            $result .= '</select><tr><td width="10%" align="right">';

                            $result .= 'Flow </td><td>';
<<<<<<< HEAD
                            $result .= '<select name="' . $yk . '[0]" size="1">';
=======
                            $result .= '<select name="' . $yk . '[2]" size="1">';
>>>>>>> b9c8420f4362aab62a817374ce92e2cb8711d8da
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
                                $result .= '<option value="Triphesic">Triphesic </option>';
                                $result .= '<option value="Biphesic">Biphesic </option>';
                                $result .= '<option value="Monophesic">Monophesic </option>';
                            $result .= '</select><tr><td width="10%" align="right">';

                            $result .= 'Compression ultrasonography </td><td>';
<<<<<<< HEAD
                            $result .= '<select name="' . $yk . '[0]" size="1">';
=======
                            $result .= '<select name="' . $yk . '[3]" size="1">';
>>>>>>> b9c8420f4362aab62a817374ce92e2cb8711d8da
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
                                $result .= '<option value="Positif">Positif </option>';
                                $result .= '<option value="Negatif">Negatif </option>';
                            $result .= '</select><tr><td width="10%" align="right">';

                            $result .= 'Uji Squeezing </td><td>';
<<<<<<< HEAD
                            $result .= '<select name="' . $yk . '[0]" size="1">';
=======
                            $result .= '<select name="' . $yk . '[4]" size="1">';
>>>>>>> b9c8420f4362aab62a817374ce92e2cb8711d8da
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
                                $result .= '<option value="Positif">Positif </option>';
                                $result .= '<option value="Negatif">Negatif </option>';
                            $result .= '</select><tr><td width="10%" align="right">';

                            $result .= 'Refluks </td><td>';
<<<<<<< HEAD
                            $result .= '<select name="' . $yk . '[0]" size="1">';
=======
                            $result .= '<select name="' . $yk . '[5]" size="1">';
>>>>>>> b9c8420f4362aab62a817374ce92e2cb8711d8da
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
                                $result .= '<option value="Positif">Positif </option>';
                                $result .= '<option value="Negatif">Negatif </option>';
                            $result .= '</select><tr><td width="10%" align="right">';

                            $result .= 'Thrambus </td><td>';
<<<<<<< HEAD
                            $result .= '<select name="' . $yk . '[0]" size="1">';
=======
                            $result .= '<select name="' . $yk . '[6]" size="1">';
>>>>>>> b9c8420f4362aab62a817374ce92e2cb8711d8da
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
                                $result .= '<option value="Kecil">Kecil </option>';
                                $result .= '<option value="Sedang">Sedang </option>';
                                $result .= '<option value="Besar">Besar </option>';
                            $result .= '</select>';
                        } else {
                            $result .= '<select name="' . $yk . '[0]" size="1">';
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
                            foreach($lv['#theref'] as $kk => $vv){
                                $result .= '<option value="' . $kk . '"' . (isset($lv['#value']) && $lv['#value'] == $kk ? ' selected="selected"' : '') . '>' . $vv . '</option>';
                            }
                            $result .= '</select></td><td width="10%" align="right">';

                            $result .= 'Diameter </td><td>';
<<<<<<< HEAD
                            $result .= '<select name="' . $yk . '[0]" size="1">';
=======
                            $result .= '<select name="' . $yk . '[1]" size="1">';
>>>>>>> b9c8420f4362aab62a817374ce92e2cb8711d8da
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
//                            foreach($lv['#theref'] as $kk => $vv){
                                $result .= '<option value="Normal">Normal </option>';
                                $result .= '<option value="Kecil">Kecil </option>';
                                $result .= '<option value="Lebar">Lebar </option>';
//                            }
                            $result .= '</select><tr><td width="10%" align="right">';
                            $result .= 'Flow </td><td>';
<<<<<<< HEAD
                            $result .= '<select name="' . $yk . '[0]" size="1">';
=======
                            $result .= '<select name="' . $yk . '[2]" size="1">';
>>>>>>> b9c8420f4362aab62a817374ce92e2cb8711d8da
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
//                            foreach($lv['#theref'] as $kk => $vv){
                                $result .= '<option value="Triphesic">Triphesic </option>';
                                $result .= '<option value="Biphesic">Biphesic </option>';
                                $result .= '<option value="Monophesic">Monophesic </option>';
//                            }
                            $result .= '</select><tr><td width="10%" align="right">';
                            $result .= 'Steunosis </td><td>';
<<<<<<< HEAD
                            $result .= '<select name="' . $yk . '[0]" size="1">';
=======
                            $result .= '<select name="' . $yk . '[3]" size="1">';
>>>>>>> b9c8420f4362aab62a817374ce92e2cb8711d8da
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
//                            foreach($lv['#theref'] as $kk => $vv){
                                $result .= '<option value="Mild">Mild </option>';
                                $result .= '<option value="Moderate">Moderate </option>';
                                $result .= '<option value="Severe">Severe </option>';
//                            }
                            $result .= '</select><tr><td width="10%" align="right">';
                            $result .= 'Thrambus </td><td>';
<<<<<<< HEAD
                            $result .= '<select name="' . $yk . '[0]" size="1">';
=======
                            $result .= '<select name="' . $yk . '[4]" size="1">';
>>>>>>> b9c8420f4362aab62a817374ce92e2cb8711d8da
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
//                            foreach($lv['#theref'] as $kk => $vv){
                                $result .= '<option value="Kecil">Kecil </option>';
                                $result .= '<option value="Sedang">Sedang </option>';
                                $result .= '<option value="Besar">Besar </option>';
                                $result .= '<option value="Tidak ada">Tidak ada</option>';
//                            }
                            $result .= '</select><tr><td width="10%" align="right">';
                            $result .= 'Kalsifkasi </td><td>';
<<<<<<< HEAD
                            $result .= '<select name="' . $yk . '[0]" size="1">';
=======
                            $result .= '<select name="' . $yk . '[5]" size="1">';
>>>>>>> b9c8420f4362aab62a817374ce92e2cb8711d8da
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
//                            foreach($lv['#theref'] as $kk => $vv){
                                $result .= '<option value="Mild">Mild </option>';
                                $result .= '<option value="Moderate">Moderate </option>';
                                $result .= '<option value="Severe">Severe </option>';
                                $result .= '<option value="Tidak">Tidak </option>';
//                            }
                            $result .= '</select><tr><td width="10%" align="right">';
                            $result .= 'Lain </td><td>';
<<<<<<< HEAD
                            $result .= '<select name="' . $yk . '[0]" size="1">';
=======
                            $result .= '<select name="' . $yk . '[6]" size="1">';
>>>>>>> b9c8420f4362aab62a817374ce92e2cb8711d8da
                            $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
//                            foreach($lv['#theref'] as $kk => $vv){
                                $result .= '<option value="Tourtous">Tourtous </option>';
                                $result .= '<option value="Ancurysma">Ancurysma </option>';
//                            }
                            $result .= '</select>';
                        }
                    }
//                if(isset($lv['#readonly']) && trim($lv['#readonly']) != '' && $lv['#readonly'] !== FALSE){
//                    $result .= $lv['#theref'][$lv['#value']];
//                } else {
//                    $result .= '<select name="' . $ky . '_' . $yk . '" size="1">' . "\n";
//                    $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>' . "\n";
//                    foreach($lv['#theref'] as $kk => $vv){
//                        $result .= '<option value="' . $kk . '"' . (isset($lv['#value']) && $lv['#value'] == $kk ? ' selected="selected"' : '') . '>' . $vv . '</option>' . "\n";
//                    }
//                    $result .= '</select>' . "\n";
//                }
//            } else {
//                if(isset($lv['#readonly']) && trim($lv['#readonly']) != '' && $lv['#readonly'] !== FALSE){
//                    $result .= $lv['#value'];
//                } else {
//                    $result .= '<input type="' . $lv['#type'] . '" name="' . $ky . '_' . $yk . '"' . (isset($lv['#size']) ? ' size="' . $lv['#size'] . '"' : '') . '>' . "\n";
//                }
//            }
//            $result .= '</td>' . "\n";
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
//            $result .= '<td align="left"' . ($lv['#type'] != 'select2' ? ' colspan="2"' : '') . '>';
//            if($yk != 'gelombang_t'){
//                if(isset($lv['#readonly']) && $lv['#readonly'] !== FALSE){
//                    $result .= ($lv['#type'] == 'select' ? $lv['#theref'][$lv['#value'][0]] : $lv['#value'][0]) . ($lv['#type'] == 'select' ? '' : ' ' . __t('pada sandapan') . ' ' . $lv['#theref'][$lv['#value'][1]]);
//                } else {
//                    if($lv['#type'] == 'select2'){
//    //                                echo '<pre>'; print_r($lv['#value']); echo '</pre>';
//                        $result .= '<select name="' . $ky . '_' . $yk . '[0]" size="1">' . "\n";
//                        $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>' . "\n";
//                        foreach($lv['#customized']['option'] as $kk => $vv){
//                            $result .= '<option value="' . $kk . '"' . (isset($lv['#value'][0]) && $lv['#value'][0] == $kk ? ' selected="selected"' : '') . '>' . $vv . '</option>' . "\n";
//                        }
//                        $result .= '</select>' . "\n";
//                    } elseif($lv['#type'] == 'select3') {
//                        $result .= '<select name="' . $ky . '_' . $yk . '[0]" size="1">' . "\n";
//                        $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>' . "\n";
//                        foreach($lv['#customized']['option'] as $kk => $vv){
//                            $result .= '<option value="' . $kk . '"' . (isset($lv['#value'][0]) && $lv['#value'][0] == $kk ? ' selected="selected"' : '') . '>' . $vv . '</option>' . "\n";
//                        }
//                        $result .= '</select>' . "\n";
//                        $result .= __t('pada sandapan') . "\n";
//                        $result .= '<select name="' . $ky . '_' . $yk . '[1]" size="1">' . "\n";
//                        $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>' . "\n";
//                        foreach($lv['#theref'] as $kk => $vv){
//                            $result .= '<option value="' . $kk . '"' . (isset($lv['#value'][1]) && $lv['#value'][1] == $kk ? ' selected="selected"' : '') . '>' . $vv . '</option>' . "\n";
//                        }
//                        $result .= '</select>' . "\n";
//                    } else {
//                        $result .= '<select name="' . $ky . '_' . $yk . '[0]" size="1">' . "\n";
//                        $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>' . "\n";
//                        foreach($lv['#theref'] as $kk => $vv){
//                            $result .= '<option value="' . $kk . '"' . (isset($lv['#value'][0]) && $lv['#value'][0] == $kk ? ' selected="selected"' : '') . '>' . $vv . '</option>' . "\n";
//                        }
//                        $result .= '</select>' . "\n";
//                    }
//                }
//            } else {
//                $result .= '<br />' . __t('pada sandapan') . "\n";
//                if(isset($lv['#readonly']) && $lv['#readonly'] !== FALSE){
//                    $result .= $lv['#theref'][$lv['#value'][1]];
//                } else {
//                    $result .= '<select name="' . $ky . '_' . $yk . '[1]" size="1">' . "\n";
//                    $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>' . "\n";
//                    foreach($lv['#theref'] as $kk => $vv){
//                        $result .= '<option value="' . $kk . '"' . (isset($lv['#value'][1]) && $lv['#value'][1] == $kk ? ' selected="selected"' : '') . '>' . $vv . '</option>' . "\n";
//                    }
//                    $result .= '</select>' . "\n";
//                }
//            }
//            $result .= '</td>' . "\n";
//            if($lv['#type'] == 'select2' && (!isset($lv['#readonly']) || $lv['#readonly'] !== TRUE)){
//                $result .= '<td align="left">' . "\n";
//                $result .= __t('pada sandapan') . "\n";
//                $result .= '<select name="' . $ky . '_' . $yk . '[1]" size="1">' . "\n";
//                $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>' . "\n";
//                foreach($lv['#theref'] as $kk => $vv){
//                    $result .= '<option value="' . $kk . '"' . (isset($lv['#value'][1]) && $lv['#value'][1] == $kk ? ' selected="selected"' : '') . '>' . $vv . '</option>' . "\n";
//                }
//                $result .= '</select>' . "\n";
//                $result .= '</td>';
//            }
        }
        $result .= '</tr>' . "\n";
    }
    }
} unset($rowspan, $dumpt);
$result .= '</table>' . "\n";
$result .= '</div>' . "\n";
