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
 *  echocardiography.tpl.php
 *  
 *  Created on Sep 16, 2009, 7:43:07 AM
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
    $result .= '<fieldset>' . "\n";
    $result .= '<legend>Patient Information</legend>';
//    echo '<pre>'; print_r($value); echo '</pre>'; exit();
    $rows = 0;
    for($i=0; $i<6; $i++){
        if($rows == 0){
            $result .= '<div id="kolom">' . "\n";
        }
        foreach($value as $ke => $val){
            if(!eregi('#', $ke) && $ke != 'data'){
                if(isset($val['#tbpos']) && $val['#tbpos'] == $i){
//                    __create_form_items($val);

                    if(isset($val['#title']) && $val['#title'] != 'hidden' && $val['#type'] != 'hidden'){
                        $result .= '<label>' . ucwords($val['#title']) . ' :</label>';
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
        $rows ++;
        if($rows > 3){
            $result .= '</div>' . "\n";
            $rows = 0;
        }
    } unset($rows, $i);
    $result .= '</fieldset>' . "\n";
    
    $result .= '<ul id="treadmilltabs" class="shadetabs">' . "\n";
    $result .= '<li><a href="#" rel="treadmill1" class="selected">Description and Conclusion</a></li>' . "\n";
    $result .= '<li><a href="#" rel="treadmill2">Measured Value</a></li>' . "\n";
    $result .= '</u>' . "\n";

    $result .= '<div  style="border:1px solid gray; width:725px; margin-bottom: 1em; padding: 10px">' . "\n";
    $result .= '<div id="treadmill1" class="tabcontent">' . "\n";
//    echo '<pre>'; print_r($value); echo '</pre>';
        foreach($value as $ke => $val){
//            echo '<pre>'; print_r($val['#type']); echo '</pre>';
            if(!eregi('#', $ke) && $ke != 'data'){
                if(!isset($val['#tbpos']) && !isset($val['#normal_value']) && $ke != 'submit'){
                    if($ke == 'interpretasi'){
                        $result .= '<br />';
                    }
                    
                    if(isset($val['#title']) && $val['#title'] != 'hidden' && $val['#type'] != 'hidden'){
                        $result .= '<label for="'. $ke .'" style="width:100px">' . ucwords($val['#title']) . ' :</label>';
                    }
                    if(isset($val['#message']) && $val['#message'] != 'hidden'){
                        if(is_array($val['#message'])){
                            foreach($val['#message'] as $ky => $vl){
                                $result .= '<div>';
                                if($val['#id'] == 'login' && $ky < 1){
                                    $result .= '<font class="login-title">';
                                }
                                $result .= ucwords($vl);
                                if($val['#id'] == 'login'){
                                    if($ky < 1){
                                        $result .= '</font>';
                                    } else {
                                        $result .= '<br /><br />';
                                    }
                                }
                                $result .= '</div>' . "\n";
                            }
                        } else {
                            $result .= '<div>'. ucwords($val['#message']) .'</div>' . "\n";
                        }
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
                    } elseif($val['#type'] == 'text'){
                        
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
//                    echo '<pre>'; print_r($val); echo '</pre>';

//                break;
                }
            }
            if ($val['#type'] == 'text'){
//                         echo '<pre>'; print_r($val); echo '</pre>';
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
    $result .= '</div>' . "\n";
    $result .= '<div id="treadmill2" class="tabcontent">' . "\n";
//    echo '<pre>'; print_r($value); echo '</pre>';
    $result .= '<table with="100%" align="center">' . "\n";
    $result .= '<tr>' . "\n";
    $result .= '<td align="center">&nbsp;</td>';
    $result .= '<td align="center">Measured Value</td>' . "\n";
    $result .= '<td align="center">Normal Value</td>';
    $result .= '</tr>' . "\n";
    foreach($value as $ke => $val){
        if(!eregi('#', $ke) && $ke != 'data'){
            if(isset($val['#normal_value'])){
                $result .= '<tr>' . "\n";
                $result .= '<td align="right">' . $val['#title'] . ' :</td>';
                $result .= '<td align="left"><input type="text" name="' . $ke . '" value="' . $val['#value'] . '"></td>' . "\n";
                $result .= '<td align="right">' . $val['#normal_value'] . '</td>';
                $result .= '</tr>' . "\n";
            }
        }
    }
    $result .= '</table>' . "\n";
    $result .= '</div>' . "\n";
    $result .= '</div>' . "\n";
    $result .= '<script type="text/javascript">' . "\n";
    $result .= 'var tabs=new ddtabcontent("treadmilltabs")' . "\n";
    $result .= 'tabs.setpersist(true)' . "\n";
    $result .= 'tabs.setselectedClassTarget("link") //"link" or "linkparent"' . "\n";
    $result .= 'tabs.init()' . "\n";
    $result .= '</script>' . "\n";

    $result .= '<div align="center">';
    $result .= '<input type="submit" value="submit">';
    $result .= '</div>';

    $result .= '</form>' . "\n";
}
