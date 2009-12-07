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
 *  pemeriksaan.php
 *  
 *  Created on Oct 28, 2009, 9:51:59 AM
 */
$result .= '<div id="fisis' . $ke . '" class="tabcontent">' . "\n";
$result .= $vl['datafields']['pemeriksaan']['title'];
$result .= '<table width=100% class="table" border="0">' . "\n";
$cnt = 0;
//echo '<pre>'; print_r($vl); echo '</pre>';
foreach($vl['datafields'] as $yk => $lv){
    if($lv['type'] != 'hidden'){
        if($cnt < 1){
            $result .= '<tr valign="top">' . "\n";
        }
        $result .= '<td valign="top">' . ucwords (str_replace ("_"," ", $lv['title'])) . '</td>';
        $result .= '<td>';
        if($lv['type'] == 'select'){
            if($lv['readonly'] === true){
                $result .= $lv['theref'][$lv['value']] . "\n";
            } else {
                $result .= '<select name="' . $yk . '" size="' . $lv['size']. '">' . "\n";
                if(isset($lv['blankopt'])){
                    $result .= '<option value=""></option>';
                }
                foreach($lv['theref'] as $kc => $isi){
                    $result .= '<option value="' . $kc . '"' . (isset($lv['value']) && $lv['value'] == $kc ? ' selected=selected' : '') . '>' . $isi . '</option>' . "\n";
                }
                $result .= '</select>' . "\n";
            }
        } elseif($lv['type'] == 'checkbox'){
            $lv['value'] = explode(',', $lv['value']);
            if($lv['readonly'] === true){
                foreach($lv['value'] as $vv){
                    if(isset($koma)){$result .= ', ';}
                    $result .= $lv['theref'][$vv]; $koma = 1;
                } unset($koma);
            } else {
                $htg = 0;
                foreach($lv['theref'] as $kc => $isi){
                    $result .= '<input type="checkbox" name="' . $yk . '[' . $htg . ']" value="' . $kc . '"' . (count($lv['value']) > 0 && in_array($kc, $lv['value']) ? ' checked="true"' : '') . '>';
                    $result .= $isi . "<br />";
                    $htg++;
                } unset($htg);
            }
        } elseif($lv['type'] == 'radio'){
            if($lv['readonly'] === true){
                $result .= $lv['theref'][$lv['value']];
            } else {
                $htg = 0;
                foreach($lv['theref'] as $kc => $isi){
                    $result .= '<input type="radio" name="' . $yk . '[' . $htg . ']" value="' . $kc . '"' . ($kc == $lv['value'] ? ' checked="true"' : '') . '>';
                    $result .= $isi . "<br />";
                    $htg++;
                } unset($htg);
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
                if (preg_match('/pemasukan/',$yk)){
                    $result .= 'Oral <input type="' . $lv['type'] . '" name="' . $yk . '"' . (isset($lv['size']) ? ' size="' . $lv['size'] . '"' : '') . (isset($lv['value']) ? ' value="' . $lv['value'] . '"' : '') . '> cc <br />' . "\n";
                    $result .= 'NGT <input type="' . $lv['type'] . '" name="' . $yk . '"' . (isset($lv['size']) ? ' size="' . $lv['size'] . '"' : '') . (isset($lv['value']) ? ' value="' . $lv['value'] . '"' : '') . '> cc <br />' . "\n";
                    $result .= 'Paratera <input type="' . $lv['type'] . '" name="' . $yk . '"' . (isset($lv['size']) ? ' size="' . $lv['size'] . '"' : '') . (isset($lv['value']) ? ' value="' . $lv['value'] . '"' : '') . '> cc' . "\n";
                } elseif (preg_match('/pengeluaran/',$yk)) {
                    $result .= 'Muntah <input type="' . $lv['type'] . '" name="' . $yk . '"' . (isset($lv['size']) ? ' size="' . $lv['size'] . '"' : '') . (isset($lv['value']) ? ' value="' . $lv['value'] . '"' : '') . '> cc <br />' . "\n";
                    $result .= 'NGT <input type="' . $lv['type'] . '" name="' . $yk . '"' . (isset($lv['size']) ? ' size="' . $lv['size'] . '"' : '') . (isset($lv['value']) ? ' value="' . $lv['value'] . '"' : '') . '> cc <br />' . "\n";
                    $result .= 'BAK <input type="' . $lv['type'] . '" name="' . $yk . '"' . (isset($lv['size']) ? ' size="' . $lv['size'] . '"' : '') . (isset($lv['value']) ? ' value="' . $lv['value'] . '"' : '') . '> cc <br />' . "\n";
                    $result .= 'WSD <input type="' . $lv['type'] . '" name="' . $yk . '"' . (isset($lv['size']) ? ' size="' . $lv['size'] . '"' : '') . (isset($lv['value']) ? ' value="' . $lv['value'] . '"' : '') . '> cc <br />' . "\n";
                    $result .= 'Drain <input type="' . $lv['type'] . '" name="' . $yk . '"' . (isset($lv['size']) ? ' size="' . $lv['size'] . '"' : '') . (isset($lv['value']) ? ' value="' . $lv['value'] . '"' : '') . '> cc' . "\n";
                } else {
                    $result .= '<input type="' . $lv['type'] . '" name="' . $yk . '"' . (isset($lv['size']) ? ' size="' . $lv['size'] . '"' : '') . (isset($lv['value']) ? ' value="' . $lv['value'] . '"' : '') . '>' . "\n";
                }
            }
        }
        $result .= '</td>' . "\n";
        $cnt++;
        if($cnt > 2){
            $cnt = 0;
            $result .= '</tr>' . "\n";
        }
    }
} unset($cnt,$yk,$lv);
$result .= '</table>' . "\n";
//$result .= '</div>' . "\n";
//$result .= '<div>' . "\n";
$result .= '<table width=100% class="table">' . "\n";
//$result .= '<th>' . "\n";
$cnt = 0;

foreach($vl['data'] as $yk=>$lv ){
//    if($lv['type'] != 'hidden'){
//    echo '<pre>'; print_r($lv); echo '</pre>';
    foreach ($lv as $hd => $dh) {
//        echo '<pre>'; print_r($lv); echo '</pre>';
        if (is_array($dh)){
            $result .= '<th>' . $dh['caption'] .'</th>';;
        }
    }
    $result .= '<tr>';
    $result .= '<td>' . $lv['id'] .'</td>';
    $result .= '<td>' . $lv['tgl_periksa'] .'</td>';
    $result .= '<td>' . $lv['tensi_sistolik'] .'</td>';
    $result .= '<td>' . $lv['tensi_diastolik'] .'</td>';
    $result .= '<td>' . $lv['nps'] .'</td>';
    $result .= '<td>' . $lv['kesadaran'] .'</td>';
    $result .= '<td>' . $lv['penivien'] .'</td>';
    $result .= '<td>' . $lv['pemasukan'] .'</td>';
    $result .= '<td>' . $lv['pengeluaran'] .'</td>';
    $result .= '<tr>';
//        if ($cnt<1){
//            $result .= '<th>' . $lv[''] .'</th>';
//        }
//        $result .= '';

//    }
}
$result .= '</table>' . "\n";
$result .= '</div>' . "\n";
