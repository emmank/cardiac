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

 *  ekg.tpl
 *  
 *  Created on Oct 26, 2009, 5:28:48 AM
 */
//echo "<pre>";print_r($data);echo "</pre>";
foreach($data as $key => $value){
    if(isset($value['#addmenu'])){
        $result .= __create_add_menu($value['#addmenu']);
    }
    $result .= __create_form_open($value, $key);
    $result .= "\n" . '<fieldset>' . "\n";
    $result .= '<legend>' . __t('Identitas Pasien') . '</legend>' . "\n";
    foreach($value as $ky => $vl){
        if(!eregi('#', $ky)){
            if($vl['#type'] == 'hidden'){
                $result .= '<input type="hidden" name="' . $ky . '" value="' . $vl['#value'] . '">' . "\n";
            }
        }
    }
    $gettbpos = array();
    foreach($value as $ky => $vl){
        if(!eregi('#', $ky)){
            if($ky != 'tab_items'){
                if(isset($vl['#tbpos'])){
                    $gettbpos[$vl['#tbpos']] = $vl;
                    $gettbpos[$vl['#tbpos']]['#key'] = $ky;
                }
            }
        }
    }
    ksort($gettbpos);
    foreach($gettbpos as $ky => $vl){
        if((int)$ky < 1 || (int)$ky % 5 == 0){
            $result .= '<div id="kolom">' . "\n";
            $setdiv = 1;
        }
        $result .= '<label>' . ucwords($vl['#title']) . '</label>';
        if($vl['#type'] != 'textarea'){
            $result .= '<input type="text" value="' . $vl['#value'] .'" readonly="true"> <br />' . "\n";
        } else {
            $result .= '<textarea  readonly="true">' . $vl['#value'] .'</textarea> <br />' . "\n";
        }
        if((int)$ky > 3 && ((int)$ky + 1) % 5 == 0){
            unset($setdiv);
            $result .= '</div>' . "\n";
        }
    } unset($gettbpos);
    if(isset($setdiv)){
        $result .= '</div>' . "\n";
        unset($setdiv);
    }
    $result .= '</fieldset>' . "\n";
    
    $result .= '<div>' . "\n";
    //-----------------------------------------------------------------

//    $result .= '<a id="toggle-katcvphidden-div" href="#toggle-katcvphidden-div">C V P</a><br />';
//    $result .= '<a id="toggle-katcvqhidden-div" href="#toggle-katcvqhidden-div">C V Q</a><br />';
//    $result .= '<a id="toggle-katcvrhidden-div" href="#toggle-katcvrhidden-div">C V R</a><br />';
//    $result .= '<a id="toggle-katcvshidden-div" href="#toggle-katcvshidden-div">C V S</a><br />';
//    $result .= '<a id="toggle-katcvthidden-div" href="#toggle-katcvthidden-div">C V T</a><br />';
//    $result .= '<div id="katcvphidden-div" style="display: none">';
    $result .= '<table width=100% class="table" border="0">' . "\n";
    $cnt = 0;
    foreach($value as $yk => $lv){
        if(!eregi('#', $yk) && is_array($lv) && $yk != 'submit'){
//            echo "<pre>";print_r($lv);echo "</pre>";
            if($lv['#type'] != 'hidden' && !isset($lv['#tbpos'])){
                $result .= '<tr valign="top">' . "\n";
                if(!isset($lv['#customized'])){
//                    $result .= '<td align="right" width="15%">' . ucwords($lv['#title']) . '</td>' . "\n";
//                    $result .= '<td align="left" colspan="4">';
                        $result .= '<td align="left" width="15%">' . ucwords($lv['#title']) . '</td>' . "\n";
                        $result .= '<td align="left" colspan="4">';
                        if(isset($lv['#readonly']) && trim($lv['#readonly']) !== FALSE){
                            $result .= $lv['#value'];
                        } else {
                            $result .= '<input type="' . $lv['#type'] . '" name="dicom[]"' . (isset($lv['#size']) ? ' size="' . $lv['#size'] . '"' : '') . '>';
                        }
                        $result .= '</td>' . "\n";
                }
                    
//                }
                $result .= '</tr>' . "\n";
                $cnt++;
            }
        }
    } unset($dumpt, $cnt, $rowspan);
    $result .= '</table>' . "\n";
//    $result .= '</div>';
//    //----------------------------------------------------------------------------------------
//    $result .= '<div id="katcvqhidden-div" style="display: none">';
//    $result .= '<table width=100% class="table" border="0">' . "\n";
//    $cnt = 0;
//    foreach($value as $yk => $lv){
//        if(!eregi('#', $yk) && is_array($lv) && $yk != 'submit'){
//            if($lv['#type'] != 'hidden' && !isset($lv['#tbpos'])){
//                $result .= '<tr valign="top">' . "\n";
////                if(!isset($lv['#customized'])){
//
//                    if($lv['#mark'] == 'cvq'){
//                        $result .= '<td align="right" width="15%">' . ucwords($lv['#title']) . '</td>' . "\n";
//                        $result .= '<td align="left" colspan="4">';
//                        if(isset($lv['#readonly']) && trim($lv['#readonly']) !== FALSE){
//                            $result .= $lv['#value'];
//                        } else {
//                            $result .= '<input type="' . $lv['#type'] . '" name="' . $yk . '"' . (isset($lv['#size']) ? ' size="' . $lv['#size'] . '"' : '') . '>';
//                        }
//                        $result .= '</td>' . "\n";
//                    }
//
////                }
//                $result .= '</tr>' . "\n";
//                $cnt++;
//            }
//        }
//    } unset($dumpt, $cnt, $rowspan);
//    $result .= '</table>' . "\n";
//    $result .= '</div>';
//    //--------------------------------------------------------------
//    $result .= '<div id="katcvrhidden-div" style="display: none">';
//    $result .= '<table width=100% class="table" border="0">' . "\n";
//    $cnt = 0;
//    foreach($value as $yk => $lv){
//        if(!eregi('#', $yk) && is_array($lv) && $yk != 'submit'){
//            if($lv['#type'] != 'hidden' && !isset($lv['#tbpos'])){
//                $result .= '<tr valign="top">' . "\n";
////                if(!isset($lv['#customized'])){
//
//                    if($lv['#mark'] == 'cvr'){
//                        $result .= '<td align="right" width="15%">' . ucwords($lv['#title']) . '</td>' . "\n";
//                        $result .= '<td align="left" colspan="4">';
//                        if(isset($lv['#readonly']) && trim($lv['#readonly']) !== FALSE){
//                            $result .= $lv['#value'];
//                        } else {
//                            $result .= '<input type="' . $lv['#type'] . '" name="' . $yk . '"' . (isset($lv['#size']) ? ' size="' . $lv['#size'] . '"' : '') . '>';
//                        }
//                        $result .= '</td>' . "\n";
//                    }
//
////                }
//                $result .= '</tr>' . "\n";
//                $cnt++;
//            }
//        }
//    } unset($dumpt, $cnt, $rowspan);
//    $result .= '</table>' . "\n";
//    $result .= '</div>';
//    //--------------------------------------------------------------
//    $result .= '<div id="katcvshidden-div" style="display: none">';
//    $result .= '<table width=100% class="table" border="0">' . "\n";
//    $cnt = 0;
//    foreach($value as $yk => $lv){
//        if(!eregi('#', $yk) && is_array($lv) && $yk != 'submit'){
//            if($lv['#type'] != 'hidden' && !isset($lv['#tbpos'])){
//                $result .= '<tr valign="top">' . "\n";
////                if(!isset($lv['#customized'])){
//
//                    if($lv['#mark'] == 'cvs'){
//                        $result .= '<td align="right" width="15%">' . ucwords($lv['#title']) . '</td>' . "\n";
//                        $result .= '<td align="left" colspan="4">';
//                        if(isset($lv['#readonly']) && trim($lv['#readonly']) !== FALSE){
//                            $result .= $lv['#value'];
//                        } else {
//                            $result .= '<input type="' . $lv['#type'] . '" name="' . $yk . '"' . (isset($lv['#size']) ? ' size="' . $lv['#size'] . '"' : '') . '>';
//                        }
//                        $result .= '</td>' . "\n";
//                    }
//
////                }
//                $result .= '</tr>' . "\n";
//                $cnt++;
//            }
//        }
//    } unset($dumpt, $cnt, $rowspan);
//    $result .= '</table>' . "\n";
//    $result .= '</div>';
//    //--------------------------------------------------------------
//    $result .= '<div id="katcvthidden-div" style="display: none">';
//    $result .= '<table width=100% class="table" border="0">' . "\n";
//    $cnt = 0;
//    foreach($value as $yk => $lv){
//        if(!eregi('#', $yk) && is_array($lv) && $yk != 'submit'){
//            if($lv['#type'] != 'hidden' && !isset($lv['#tbpos'])){
//                $result .= '<tr valign="top">' . "\n";
////                if(!isset($lv['#customized'])){
//
//                    if($lv['#mark'] == 'cvt'){
//                        $result .= '<td align="right" width="15%">' . ucwords($lv['#title']) . '</td>' . "\n";
//                        $result .= '<td align="left" colspan="4">';
//                        if(isset($lv['#readonly']) && trim($lv['#readonly']) !== FALSE){
//                            $result .= $lv['#value'];
//                        } else {
//                            $result .= '<input type="' . $lv['#type'] . '" name="' . $yk . '"' . (isset($lv['#size']) ? ' size="' . $lv['#size'] . '"' : '') . '>';
//                        }
//                        $result .= '</td>' . "\n";
//                    }
//
////                }
//                $result .= '</tr>' . "\n";
//                $cnt++;
//            }
//        }
//    } unset($dumpt, $cnt, $rowspan);
//    $result .= '</table>' . "\n";
//    $result .= '</div>';




    //--------------------------------------------------
    $result .= '</div>' . "\n";
    
    if(isset($value['submit'])){
        $result .= '<div>' . "\n";
        $result .= '<input type="submit" value="' . $value['submit']['#value'] . '"' . (isset($value['submit']['#extra']) ? ' ' . $value['submit']['#extra'] : '') . '>';
        $result .= '</div>' . "\n";
    }
    $result .= __create_form_close();
//    $result .= '<script type="text/javascript">' . "\n";
//    $result .= 'var tabs=new ddtabcontent("fisistabs")' . "\n";
//    $result .= 'tabs.setpersist(true)' . "\n";
//    $result .= 'tabs.setselectedClassTarget("link") //"link" or "linkparent"' . "\n";
//    $result .= 'tabs.init()' . "\n";
//    $result .= '</script>' . "\n";
}
