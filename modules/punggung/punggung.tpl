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
$result .= $vl['datafields']['punggung']['title'];
$result .= '<table width=100% class="table">' . "\n";
$cnt = 0;
 //echo '<pre>'; print_r($vl['datafields']); echo '</pre>';
foreach($vl['datafields'] as $yk => $lv){
    if($lv['type'] != 'hidden'){
        if($cnt < 1){
            $result .= '<tr valign="top">' . "\n";
        }
        $result .= '<td>' . $lv['title'] . '</td>';
        $result .= '<td>';
        if($lv['type'] == 'select'){
            $result .= '<select name="' . $yk . '" size="' . $lv['size']. '">' . "\n";
            if(isset($lv['blankopt'])){
                $result .= '<option value=""></option>';
            }
            foreach($lv['theref'] as $kc => $isi){
                $result .= '<option value="' . $kc . '"' . (isset($lv['value']) && $lv['value'] == $kc ? ' selected=selected' : '') . '>' . $isi . '</option>' . "\n";
            }
            $result .= '</select>' . "\n";
        } elseif($lv['type'] == 'checkbox'){
            $cnt = 0;
            foreach($lv['theref'] as $kc => $isi){
                $result .= '<input type="checkbox" name="' . $yk . '[' . $cnt . ']" value="' . $kc . '">';
                $result .= $isi . "<br />";
                $cnt++;
            } unset($cnt);
        } elseif($lv['type'] == 'radio'){
            $cnt = 0;
            foreach($lv['theref'] as $kc => $isi){
                $result .= '<input type="radio" name="' . $yk . '[' . $cnt . ']" value="' . $kc . '">';
                $result .= $isi . "<br />";
                $cnt++;
            } unset($cnt);
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
        } else {
            $result .= '<input type="' . $lv['type'] . '" name="' . $yk . '"' . (isset($lv['size']) ? ' size="' . $lv['size'] . '"' : '') . '>' . "\n";
        }
        $result .= '</td>' . "\n";
        $cnt++;
        if($cnt > 1){
            $cnt = 0;
            $result .= '</tr>' . "\n";
        }
    }
} unset($cnt);
$result .= '</table>' . "\n";
$result .= '</div>' . "\n";