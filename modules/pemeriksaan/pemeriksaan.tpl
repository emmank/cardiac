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

foreach($data as $key => $value){
    if(isset($value['#addmenu'])){
        $result .= __create_add_menu($value['#addmenu']);
    }
    $result .= '<fieldset>' . "\n";
    $result .= '<legend>' . __t('Identitas Pasien') . '</legend>' . "\n";
    $result .= '<div id="kolom">' . "\n";
    $result .= '<label>' . __t('nama') . '</label>';
    $result .= $value['#patientinfo']['nama'] . '<br />' . "\n";
    $result .= '<label>' . __t('ruang') . '</label>';
    $result .= $value['#patientinfo']['ruang'] . '<br />' . "\n";
    $result .= '<label>' . __t('pukul_masuk') . '</label>';
    $result .= $value['#patientinfo']['pukul_masuk'] . '<br />' . "\n";
    $result .= '</div>' . "\n";
    $result .= '</fieldset>' . "\n";

    $result .= __create_form_open($value, $key);
    $result .= '<fieldset>' . "\n";
    $result .= '<div id="form">' . "\n";
    foreach($value as $ky => $vl){
        if(!eregi('#', $ky) && $ky != 'submit'){
            $vl['#name'] = $ky;
            $result .= '<div id="block">' . "\n";
            $result .= '<LABEL>' . ucwords(__t($vl['#title'])) . '</LABEL>';
            $result .= __create_items_of_form($vl) . "\n";
            $result .= '</div>' . "\n";
        }
    }
    $result .= '</div>' . "\n";
    $result .= '</fieldset>' . "\n";
    if(isset($value['submit'])){
        $result .= '<div>' . "\n";
        $result .= '<input type="submit" value="' . $value['submit']['#value'] . '"' . (isset($value['submit']['#extra']) ? ' ' . $value['submit']['#extra'] : '') . '>';
        $result .= '</div>' . "\n";
    }
    $result .= __create_form_close();
}
