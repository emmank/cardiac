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
 *  deskripsi.php
 *  
 *  Created on Oct 28, 2009, 9:51:59 AM
 */
$result .= '<div id="fisis' . $ke . '" class="tabcontent">' . "\n";
$result .= $vl['datafields']['deskripsi']['title'];
$result .= '<table width=100% class="table">' . "\n";
$cnt = 0;
//echo '<pre>'; print_r($ke); echo '</pre>';
foreach($vl['datafields'] as $yk => $lv){
    if($lv['type'] != 'hidden'){
        if($cnt < 1){
            $result .= '<tr valign="top">' . "\n";
        }
//        $result .= '<td width="10%">' . ucwords (str_replace ("_"," ", $lv['title'])) . '</td>';
//        $result .= 'Description of Wall Motion, Masses, Valves, Pericardium';
        $result .= '<td>';
        if($lv['type'] == 'select'){
//            echo '<pre>'; print_r($lv['readonly']); echo '</pre>';
            if($lv['readonly'] == '1'){
//                        echo '<pre>'; print_r($lv['value']); echo '</pre>';
                        $lv['value'] = explode('|', $lv['value']);
                        $result .= $lv['value'][0] . ', ' . $lv['value'][1] . ', '. $lv['value'][2] . ', ' . $lv['value'][3] ;
//                        $result .= ' ' . $lv['theref'][$lv['value'][2]];
                    } else {
                        $result .= '<input type="radio" name="' . $yk . '[0]" value="Normal"> Normal <br />';// value="' . $kk . '"' . (isset($lv['#value'][0]) && $lv['#value'][0] == $kk ? ' checked="true"' : '') . '> ' . $vv;
                        $result .= '<input type="radio" name="' . $yk . '[0]" value="Steunosis"> Steunosis ';
                        $result .= 'Proxmial ';
                        $result .= '<select style="width:40px;" name="' . $yk . '[1]" size="1">';
                        $result .= '<option value="-"> - </option>';
                        $result .= '<option value="Proxmial 5%">' . __t('5%') . '</option>';
                        $result .= '<option value="Proxmial 10%">' . __t('10%') . '</option>';
                        $result .= '<option value="Proxmial 15%">' . __t('15%') . '</option>';
                        $result .= '<option value="Proxmial 20%">' . __t('20%') . '</option>';
                        $result .= '<option value="Proxmial 25%">' . __t('25%') . '</option>';
                        $result .= '<option value="Proxmial 30%">' . __t('30%') . '</option>';
                        $result .= '<option value="Proxmial 35%">' . __t('35%') . '</option>';
                        $result .= '<option value="Proxmial 40%">' . __t('40%') . '</option>';
                        $result .= '<option value="Proxmial 45%">' . __t('45%') . '</option>';
                        $result .= '<option value="Proxmial 50%">' . __t('50%') . '</option>';
                        $result .= '<option value="Proxmial 55%">' . __t('55%') . '</option>';
                        $result .= '<option value="Proxmial 60%">' . __t('60%') . '</option>';
                        $result .= '<option value="Proxmial 65%">' . __t('65%') . '</option>';
                        $result .= '<option value="Proxmial 70%">' . __t('70%') . '</option>';
                        $result .= '<option value="Proxmial 75%">' . __t('75%') . '</option>';
                        $result .= '<option value="Proxmial 80%">' . __t('80%') . '</option>';
                        $result .= '<option value="Proxmial 85%">' . __t('85%') . '</option>';
                        $result .= '<option value="Proxmial 90%">' . __t('90%') . '</option>';
                        $result .= '<option value="Proxmial 95%">' . __t('95%') . '</option>';
                        $result .= '<option value="Proxmial sub total oklusi">' . __t('sub total oklusi') . '</option>';
                        $result .= '<option value="Proxmial total oklusi">' . __t('total oklusi') . '</option>';
                        $result .= '</select> ';
                        $result .= 'Mid ';
                        $result .= '<select style="width:40px;" name="' . $yk . '[2]" size="1">';
                        $result .= '<option value="-"> - </option>';
                        $result .= '<option value="Mid 5%">' . __t('5%') . '</option>';
                        $result .= '<option value="Mid 10%">' . __t('10%') . '</option>';
                        $result .= '<option value="Mid 15%">' . __t('15%') . '</option>';
                        $result .= '<option value="Mid 20%">' . __t('20%') . '</option>';
                        $result .= '<option value="Mid 25%">' . __t('25%') . '</option>';
                        $result .= '<option value="Mid 30%">' . __t('30%') . '</option>';
                        $result .= '<option value="Mid 35%">' . __t('35%') . '</option>';
                        $result .= '<option value="Mid 40%">' . __t('40%') . '</option>';
                        $result .= '<option value="Mid 45%">' . __t('45%') . '</option>';
                        $result .= '<option value="Mid 50%">' . __t('50%') . '</option>';
                        $result .= '<option value="Mid 55%">' . __t('55%') . '</option>';
                        $result .= '<option value="Mid 60%">' . __t('60%') . '</option>';
                        $result .= '<option value="Mid 65%">' . __t('65%') . '</option>';
                        $result .= '<option value="Mid 70%">' . __t('70%') . '</option>';
                        $result .= '<option value="Mid 75%">' . __t('75%') . '</option>';
                        $result .= '<option value="Mid 80%">' . __t('80%') . '</option>';
                        $result .= '<option value="Mid 85%">' . __t('85%') . '</option>';
                        $result .= '<option value="Mid 90%">' . __t('90%') . '</option>';
                        $result .= '<option value="Mid 95%">' . __t('95%') . '</option>';
                        $result .= '<option value="Mid sub total oklusi">' . __t('sub total oklusi') . '</option>';
                        $result .= '<option value="Mid total oklusi">' . __t('total oklusi') . '</option>';
                        $result .= '</select> ';
                        $result .= 'Distal ';
                        $result .= '<select style="width:40px;" name="' . $yk . '[3]" size="1">';
                        $result .= '<option value=""> - </option>';
                        $result .= '<option value="Distal 5%">' . __t('5%') . '</option>';
                        $result .= '<option value="Distal 10%">' . __t('10%') . '</option>';
                        $result .= '<option value="Distal 15%">' . __t('15%') . '</option>';
                        $result .= '<option value="Distal 20%">' . __t('20%') . '</option>';
                        $result .= '<option value="Distal 25%">' . __t('25%') . '</option>';
                        $result .= '<option value="Distal 30%">' . __t('30%') . '</option>';
                        $result .= '<option value="Distal 35%">' . __t('35%') . '</option>';
                        $result .= '<option value="Distal 40%">' . __t('40%') . '</option>';
                        $result .= '<option value="Distal 45%">' . __t('45%') . '</option>';
                        $result .= '<option value="Distal 50%">' . __t('50%') . '</option>';
                        $result .= '<option value="Distal 55%">' . __t('55%') . '</option>';
                        $result .= '<option value="Distal 60%">' . __t('60%') . '</option>';
                        $result .= '<option value="Distal 65%">' . __t('65%') . '</option>';
                        $result .= '<option value="Distal 70%">' . __t('70%') . '</option>';
                        $result .= '<option value="Distal 75%">' . __t('75%') . '</option>';
                        $result .= '<option value="Distal 80%">' . __t('80%') . '</option>';
                        $result .= '<option value="Distal 85%">' . __t('85%') . '</option>';
                        $result .= '<option value="Distal 90%">' . __t('90%') . '</option>';
                        $result .= '<option value="Distal 95%">' . __t('95%') . '</option>';
                        $result .= '<option value="Distal sub total oklusi">' . __t('sub total oklusi') . '</option>';
                        $result .= '<option value="Distal total oklusi">' . __t('total oklusi') . '</option>';
                        $result .= '</select> ';
//                        $result .= '<select name="' . $yk . '[2]" size="1">';
//                        $result .= '<option value=""> --- ' . __t('Silahkan pilih') . ' --- </option>';
//                        foreach($lv['theref'] as $kk => $vv){
//                            $result .= '<option value="' . $kk . '"' . (isset($lv['#value']) && $lv['#value'] == $kk ? ' selected="selected"' : '') . '>' . $vv . '</option>';
//                        }
//                        $result .= '</select>';
                    }
                } else {
                if(trim($lv['readonly']) == '1'){
                    $result .= $lv['theref'][$lv['value']];
                } else {
//                        echo "<pre>";print_r($lv);echo "</pre>";
                    if ($cnt == 0){
                        $result .= '<b>Description of Wall Motion, Masses, Valves, Pericardium</b> <br />';
                        $result .= '<textarea name="' . $yk . '" cols="80" rows="10"></textarea>';
                    } else {
                        $result .= '<b>Conclusion :</b><br />';
                        $result .= '<textarea name="' . $yk . '" cols="80" rows="10"></textarea>';
                    }
//                        $result .= '<input type="' . $lv['#type'] . '" name="' . $yk . '"' . (isset($lv['#size']) ? ' size="' . $lv['#size'] . '"' : '') . '>';
                }
            }
            $result .= '</td>' . "\n";
//                }
            $result .= '</tr>' . "\n";
            $cnt++;
    }
} unset($cnt);
$result .= '</table>' . "\n";
$result .= '</div>' . "\n";