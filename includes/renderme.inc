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
 *  renderme.tpl.php
 *
 *  Created on Sep 6, 2009, 11:03:48 AM
 */
//echo '<pre>'; print_r($content); echo '</pre>';

require_once THEMES_DIR . DS . $theme . DS . 'config.inc';
if(isset($content['output']['form'])){
//        echo 'i am here !';
    $formlists = array();
    foreach($content['output']['form'] as $value){
        foreach($value as $key=>$val){
            $formlists[] = $key;
            ${$key} = $val;
        }
    }
    if(in_array('auth_login_form', $content['exec'])){
        $userkey = '';
        foreach($login as $key=>$value){
            if(!eregi('#', $key)){
                $userkey = $key; break;
            }
        }
        $body_login = "javascript:document." . $formlists[0] . "." . $userkey . ".focus()";
    }
}

$itemselement = array(
    'type',
    'title',
    'collapsible',
    'collapsed',
    'weight',
    'action',
    'message',
    'error'
);

//echo '<pre>'; print_r($content['output']['form']); echo '</pre>';

function __create_form_special($data){
    global $forminput, $formtextarea, $formselect;
    $result = '';
//    echo "<pre>"; print_r ($data); echo "</pre>";
    foreach($data as $key=>$value){
        $formtpl = $value['#formtpl']; break;
    }
    require_once $formtpl; unset($formtpl);
    return $result;
}

function __create_add_menu($data){
    $user = __get_vars_of_active_user();
    $result = '';
    foreach($data as $ky => $vl){
        if(eregi('#', $ky)){
            if(!isset($vl['user_required'])){
                if(!isset($ok)){$ok = array();}
                $ok[$ky] = 1;
            } elseif($vl['user_required'] == $user['groups'] || $user['groups'] == 'admin'){
                if(!isset($ok)){$ok = array();}
                $ok[$ky] = 1;
            } elseif(__get_group_permission($vl['user_required']) !== FALSE){
                if(!isset($ok)){$ok = array();}
                $ok[$ky] = 1;
            }
        }
    }
    if(!isset($ok)){
        if(!isset($data['user_required'])){$ok = 1;}
        elseif($data['user_required'] == $user['groups'] || $user['groups'] == 'admin'){$ok = 1;}
        elseif(__get_group_permission($data['user_required']) !== FALSE){$ok = 1;}
    }
    if(isset($ok)){
//            $result .= '<div id="sticky-button">';
        $result .= '<div id="button">';
        if(is_array($ok)){
//                $result .= '<table align="center" cellspacing="10" cellpadding="0" <width="100%"><tr>';
            $result .= '<table align="left" cellspacing="10" cellpadding="0" ><tr>';
            $i = 0;
            foreach($ok as $ky => $vl){
                $valadd['add'] = array(
                    '#type' => 'fieldset',
                    '#title' => 'hidden',
                    '#action' => $data[$ky]['action']
                );
                if(isset($data[$ky]['methode']) && $data[$ky]['methode'] == 'choose'){
                    $valadd['add'][$data[$ky]['filter']] = array(
                        '#type' => 'select',
                        '#size' => 1,
                        '#option' => $data[$ky]['options'],
                        '#extra' => 'onchange="javascript:this.form.submit()"'
                    );
                } else {
                    $valadd['add']['submit'] = array(
                        '#type' => 'submit',
                        '#value' => $data[$ky]['title'],
                        '#class' => 'button'
                    );
                }
                $result .= '<td align="' . ($i < 1 ? 'left' : 'right') . '">';
                $result .= __create_form($valadd);
                $result .= '</td>';
                $i++; unset($valadd);
            }
            $result .= '</tr></table>';
        } else {
            $valadd['add'] = array(
                '#type' => 'fieldset',
                '#title' => 'hidden',
                '#action' => $data['action'],
            );
            if(isset($data['methode']) && $data['methode'] == 'choose'){
                $valadd['add'][$data['filter']] = array(
                    '#type' => 'select',
                    '#size' => 1,
                    '#option' => $data['options'],
                    '#extra' => 'onchange="javascript:this.form.submit()"'
                );
            } else {
                $valadd['add']['submit'] = array(
                    '#type' => 'submit',
                    '#value' => $data['title'],
                    '#class' => 'button'
                );
            }
            $result .= __create_form($valadd);
        } unset($ok, $valadd);
        $result .= '</div>';
    }
    return $result;
}

function __get_vars_of_active_user(){
    global $systemquery, $configs;
    $sql = $systemquery->getSelect(
        array(),
        array($configs->auth_use_table[0]),
        array(
            array('&&', $configs->auth_use_table[3] . "=" . $_COOKIE[$configs->cookiesession])
        )
    );
    $systemquery->connect();
    $getit = $systemquery->conn->Execute($sql); unset($sql);
    $systemquery->close();
    $user = array();
    if($getit->_numOfRows > 0){
        foreach($getit->fields as $key=>$val){
            $user[$key] = $val;
        }
    } unset($getit);
    return $user;
}

function __create_items_detail($value){
    global $forminput, $formtextarea, $formselect;
    $user = __get_vars_of_active_user();
    $result = '<div id=form>';
    if(isset($value['title']) && $value['title'] != 'hidden'){
//        $result .= '<div>'. ucwords($value['title']) .'</div>' . "\n";
        $result .= '<div>'. ucwords($value['title']) .'</div>' . "\n";
    }
    foreach($value['data'] as $key => $val){
        if(isset($val['form'])){
            if(in_array($val['form']['detail'][$key]['#type'], $forminput) || in_array($val['form']['detail'][$key]['#type'], $forminput)){
                $result .= '<body onload="javascript:document.detail.' . $key . '.focus()">';
                break;
            }
        }
    }
    $result .= '<div>' . "\n";
    foreach($value['data'] as $key => $val){
            if ($val['hide'] != '1'){
            if(!isset($value['update_access'])){$ok = 1;}
            elseif($value['update_access'] == $user['groups'] || $user['groups'] == 'admin'){$ok = 1;}
            elseif(__get_group_permission($value['update_access']) !== FALSE){$ok = 1;}
            $result .= '<div id=block>';
            $result .= '<label for="' . $key . '" style="font-weight:bold">' . ucwords($val['key']) . ' :</label>';
            if(isset($val['form'])){
                if(isset($ok)){
                    $result .= '<table align="left" cellspacing="0" cellpadding="0">' . "\n";
                    $result .= '<tr valign="top"><td align="left">' . "\n";
                    $result .= __create_form($val['form']);
                    $result .= '</td></tr>' . "\n";
                    $result .= '</table>' . "\n";
                }
            } else {
                if (isset($val['link']) && isset($ok)){
                    $result .= '<a href="' . $val['link'] . '">';
                }
                $result .= $val['value']!='' ? ucwords($val['value']) : ' &nbsp;&nbsp;&nbsp; ';
                if(isset($val['link']) && isset($ok)){
                    $result .= '</a>';
                }
            }
            $result .= '</div>' . "\n";
            unset($ok);
        }
    }
    $result .= '</div>'. "\n";
    if($value['dropable'] != '0'){
        if(!isset($value['update_access'])){$ok = 1;}
        elseif($value['update_access'] == $user['groups'] || $user['groups'] == 'admin'){$ok = 1;}
        elseif(__get_group_permission($value['update_access']) !== FALSE){$ok = 1;}
        if(isset($ok)){
            unset($ok);
            $valdrop[$value['id']] = array(
                '#type' => 'fieldset',
                '#title' => 'hidden',
                '#action' => $value['dropable'],
                'id' => array(
                    '#type' => 'hidden',
                    '#value' => $value['id']
                ),
                'submit' => array(
                    '#type' => 'submit',
                    '#value' => __t('drop'),
                    '#style' => ''
                )
            );
            $result .= '<div class="error" style="text-align:center;right:20%;clear:both">';
            $result .= '<table align="left">' . "\n";
            $result .= '<tr valign="top"><td align="left">' . "\n";
            $result .= __create_form($valdrop);
            $result .= '</td></tr>' . "\n";
            $result .= '</table>' . "\n";
            $result .= '</div>';
        }
    }
    return $result;
}

function __create_table($value){
//    echo "<pre>";
//    print_r ($value);
//    echo "</pre>";

    $user = __get_vars_of_active_user();
    $result .= '';
    if(isset($value['addmenu'])){
        $result .= __create_add_menu($value['addmenu']);
    }

    $result .= "<!--div style=\"font-wieght:bold;font-size:1em\">" . strtoupper($value['title']) . "</div-->\n";
    $result .= '<div>' . strtoupper($value['title']) . '</div>' . "\n";
    $result .= '<table width="100%" class="tbl">' . "\n";
    foreach($value['header'] as $key=>$val){
        $result .= '<th' . (isset($val['width']) ? ' width="' . $val['width'] . '"' : '') . '>' . ucwords($val['caption']) . '</th>' . "\n";
    }
    if(count($value['data']) > 0){
        foreach($value['data'] as $key => $val){
            $result .= '<tr class="menu_plain" onmouseover=\'this.className="menu_highlight"\' onmouseout=\'this.className="menu_plain"\' style="cursor:pointer" onclick=\'location.href="' . $val['goto'] . '"\'>' . "\n";
            foreach($value['header'] as $ky=>$vl){
                $result .= '<td align="' . $vl['align'] . '">' . "\n";
                if($vl['field'] == 'none'){
                    $result .= $key+1;
                } else {
                    $result .= $val[$vl['field']];
                }
                $result .= '</td>' . "\n";
            }
            $result .= '</tr>' . "\n";
        }
    }
    $result .= '</table>';

    if(isset($value['add_patient'])){
        $result .= "<br /><div id=search><font class=judul>Pendaftaran</font>";
        $result .= __create_form($value['add_patient']);
        $result .= "</div>";
    }
    
    if (isset($value['search'])) {
//        echo "disini";
        $result .= "<br /><br />";
        $result .= __create_search($value["search"]);
    }
    return $result;
}

function __create_form_items($data, $iditem=NULL, $classitem=NULL){
    global $forminput, $formtextarea, $formselect;
    $result = '<div id=form>';
//    $result = '<div>';
//    echo '<pre>'; print_r($data); echo '</pre>';
    foreach($data as $key => $value){
        $result .= '<div id=block>' . "\n";
        if(isset($value['#title']) && $value['#title'] != 'hidden' && $value['#type'] != 'hidden' && trim($value['#title']) != '' && !is_null($value['#title']) && $value['#type'] != 'submit'){
            $result .= '<label for="'. $key .'">' . ucwords($value['#title']) . '</label>' . "\n";
        }
        if(in_array($value['#type'], $forminput)){
            if($value['#type'] == 'checkbox' || $value['#type'] == 'radio'){
//                $result .= '<div>' . "\n"; $o = 0;
                if(isset($value['#readonly']) && $value['readonly'] !== FALSE){
                    $dumpit = array();
                    $value['#value'] = explode(',', $value['#value']);
                    foreach($value['#value'] as $ky => $vl){
                        $dumpit[] = $vl;
                    }
                    $result .= implode(', ', $dumpit) . "\n";
                    unset($dumpit);
                } else {
                    foreach($value['#option'] as $ky => $vl){
                        $namekey = $value['#type'] == 'checkbox' ? $key . '[' . $o . ']' : $key;
                        if($o > 0){
//                            $result .= '<label for="'. $namekey .'">&nbsp;</label>';
                        }
                        $result .= '<div style="clear:both">' . "\n";
                        $result .= '<input type="' . $value['#type'] . '" name="' . $namekey . '" value="' . $ky . '"';
    //                    echo '<pre>'; print_r($value); echo '</pre>';
                        if(in_array($ky, $value['#value'])){
                            $result .= ' checked="true"';
//                            echo "test";
                        }
                        if(isset($value['#style'])){
                            $result .= ' style="' . $value['#style'] . '"';
                        }
                        if(isset($value['#extra'])){
                            $result .= ' ' . $value['#extra'];
                        }
                        if(isset($iditem) && !is_null($iditem)){
                            $result .= ' id="' . $iditem . '"';
                        }
                        if(isset($classitem) && !is_null($classitem)){
                            $result .= ' class="' . $classitem . '"';
                        }
                        $result .= '>';
                        $result .= ' ' . $vl;
                        $result .= '</div>' . "\n";
                        $o++;
                        unset($namekey);
                    }
                }
//                $result .= '</div>' . "\n";
            } else {
                if($value['#type'] == 'submit' && !isset($value['#title'])){$result .= '<div style="clear:both">' . "\n";}
                $result .= '<input type="' . $value['#type'] . '" name="' . $key . '"';
                if(isset($value['#size'])){
                    $result .= ' size="' . $value['#size'] . '"';
                }
                if(isset($value['#value'])){
                    $result .= ' value="' . ($value['#type'] == 'submit' ? ucwords($value['#value']) : $value['#value']) . '"';
                }
                if(isset($value['#style'])){
                    $result .= ' style="' . $value['#style'] . '"';
                }
                if(isset($value['#readonly']) && $value['#readonly'] !== FALSE){
                    $result .= ' readonly="' . $value['#readonly'] . '"';
                }
                if(isset($value['#extra'])){
                    $result .= ' ' . $value['#extra'];
                }
                if(isset($iditem) && !is_null($iditem)){
                    $result .= ' id="' . $iditem . '"';
                }
                if(isset($classitem) && !is_null($classitem)){
                    $result .= ' class="' . $classitem . '"';
                }
                if($value['#id'] == 'login' && $value['#type'] == 'submit'){
                    $result .= ' class="button"';
                }
                $result .= '>' . "\n";
                if($value['#type'] == 'submit' && !isset($value['#title'])){$result .= '</div>' . "\n";}
            }
        } elseif(in_array($value['#type'], $formtextarea)){
            $result .= '<textarea name="' . $key . '" cols="' . (isset($value['#cols']) ? $value['#cols'] : '40') . '" rows="' . (isset($value['#rows']) ? $value['#rows'] : '3') . '"';
            if(isset($value['#style'])){
                $result .= ' style="' . $value['#style'] . '"';
            }
            if(isset($value['#readonly']) && $value['#readonly'] !== FALSE){
                $result .= ' readonly="' . $value['#readonly'] . '"';
            }
            if(isset($value['#extra'])){
                $result .= ' ' . $value['#extra'];
            }
            if(isset($iditem) && !is_null($iditem)){
                $result .= ' id="' . $iditem . '"';
            }
            if(isset($classitem) && !is_null($classitem)){
                $result .= ' class="' . $classitem . '"';
            }
            $result .= '>';
            if(isset($value['#value'])){
                $result .= $value['#value'];
            }
            $result .= '</textarea>' . "\n";
        } elseif(in_array($value['#type'], $formselect)){

//            echo "<pre>";
//            print($value);
//            echo "</pre>";

            if(isset($value['#readonly']) && $value['#readonly'] !== FALSE){
                $result .= $value['#option'][$value['#value']] . "\n";
            } else {
                $result .= '<select name="' . $key . '" size="' . (isset($value['#size']) ? $value['#size'] : 1) . '"';
                if(isset($value['#style'])){
                    $result .= ' style="' . $value['#style'] . '"';
                }
                if(isset($value['#extra'])){
                    $result .= ' ' . $value['#extra'];
                }
                if(isset($iditem) && !is_null($iditem)){
                    $result .= ' id="' . $iditem . '"';
                }
                if(isset($value['#id'])){
                    $result .= ' id="' . $value['#id'] . '"';
                }

                if(isset($classitem) && !is_null($classitem)){
                    $result .= ' class="' . $classitem . '"';
                }
                $result .= '>' . "\n";
                if(isset($value['#option_blank']) && $value['#option_blank'] == '1'){
                    $result .= '<option value=""></option>' . "\n";
                }
                foreach($value['#option'] as $yk => $lv){
                    $result .= '<option value="' . $yk . '"';
                    if($yk == $value['#value']){
                        $result .= ' selected';
                    }
                    $result .= '>' . $lv . '</option>' . "\n";
                }
                $result .= '</select>' . "\n";
            }
        } elseif($value['#type'] == 'date'){
            $value['#value'] = $value['#value'] == '' ? array('1970', '01', '01') : explode('-', $value['#value']);
            krsort($value['#value']);
            foreach($value['#value'] as $kk => $vv){
                if($kk == 1){
                    if(isset($value['#readonly']) && $value['#readonly'] !== FALSE){
                        $result .= ucwords($value['#option'][(int)$vv]) . "\n";
                    } else {
                        $result .= '<select name="' . $key . '[' . $kk . ']" size="1"';
                        if(isset($value['#style'])){
                            $result .= ' style="' . $value['#style'] . '"';
                        }
                        if(isset($value['#extra'])){
                            $result .= ' ' . $value['#extra'];
                        }
                        if(isset($iditem) && !is_null($iditem)){
                            $result .= ' id="' . $iditem . '"';
                        }
                        if(isset($classitem) && !is_null($classitem)){
                            $result .= ' class="' . $classitem . '"';
                        }
                        $result .= '>';
                        foreach($value['#option'] as $yk => $lv){
                            $result .= '<option value="' . $yk . '"';
                            if($yk == (int)$vv){
                                $result .= ' selected';
                            }
                            $result .= '>' . ucwords($lv) . '</option>';
                        }
                        $result .= '</select>' . "\n";
                    }
                } else {
                    $result .= '<input type="text" name="' . $key . '[' . $kk . ']" maxlength="' . ($kk > 0 ? 2 : 4) . '" size="' . ($kk > 0 ? 2 : 4) . '"';
                    if(isset($value['#value'])){
                        $result .= ' value="' . $vv . '"';
                    }
                    if(isset($value['#style'])){
                        $result .= ' style="' . $value['#style'] . '"';
                    }
                    if(isset($value['#readonly']) && $value['#readonly'] !== FALSE){
                        $result .= ' readonly="' . $value['#readonly'] . '"';
                    }
                    if(isset($value['#extra'])){
                        $result .= ' ' . $value['#extra'];
                    }
                    if(isset($iditem) && !is_null($iditem)){
                        $result .= ' id="' . $iditem . '"';
                    }
                    if(isset($classitem) && !is_null($classitem)){
                        $result .= ' class="' . $classitem . '"';
                    }
                    if($value['#id'] == 'login' && $value['#type'] == 'submit'){
                        $result .= ' class="button"';
                    }
                    $result .= '>' . "\n";
                }
            }
        } elseif($value['#type'] == 'info'){
            $result .= ucwords(strtolower($value['#value']));
        }
        if(isset($value['#message'])){
            $result .= ' ' . $value['#message'];
        }
//        $result .= '</br>' . "\n";
        $result .= '</div>' . "\n";
//        $result .= '</div>' . "\n";
    }
    $result .= '</div>' . "\n";
    return $result;
}

function __create_form_open($data, $name, $idform=NULL, $classform=NULL){
//    echo "Id form :" . $data['#id'];
    $result = '';
    if(isset($data['#focused_item'])){
        $result .= '<body onload="javascript:document.' . $name . '.' . $data['#focused_item'] . '.focus()">';
    }
    if(isset($data['#error']) && $data['#error'] !== FALSE){
        $result .= '<div class="error">' . $data['#error'] . '</div><br /><br />' . "\n";
    }
    $result .= '<form action="' . $data['#action'] . '" method="POST" name="' . $name . '"';

    if(isset($idform) && !is_null($idform)){
        $result .= ' id="' . $idform . '"';
    }

    if (isset($data['#id'])) {
        $result .= ' id="' . $data['#id'] . '"';
    }

    
    if(isset($classform) && !is_null($classform)){
        $result .= ' class="' . $classform . '"';
    }
    $result .= '>' . "\n";
    /*
     * Title di matikan, yang dipake yang di file content.tpl
     * 
    if(isset($data['#title']) && $data['#title'] != 'hidden'){
        $result .= '<div class="judul">'. ucwords($data['#title']) .'</div>' . "\n";
    }
    */
    if(isset($data['#message']) && $data['#message'] != 'hidden'){
        if(is_array($data['#message'])){
            foreach($data['#message'] as $ky => $vl){
                $result .= '<div>';
                if($data['#id'] == 'login' && $ky < 1){
                    $result .= '<font class="login-title">';
                }
                $result .= ucwords($vl);
                if($data['#id'] == 'login'){
                    if($ky < 1){
                        $result .= '</font>';
                    } else {
                        $result .= '<br /><br />';
                    }
                }
                $result .= '</div>' . "\n";
            }
        } else {
            $result .= '<div>'. ucwords($data['#message']) .'</div>' . "\n";
        }
    }
    return $result;
}

function __create_form_close(){
    $result = '';
    $result .= '</form>' . "\n";
    return $result;
}

function __create_form($dataform, $idform=NULL, $classform=NULL, $iditem=NULL, $classitem=NULL){
    global $forminput, $formtextarea, $formselect;
//    echo '<pre>'; print_r($dataform); echo '</pre>';
    $result = '';
    foreach($dataform as $key => $value){
        $created = array(); $formhead = array();
        foreach($value as $ky=>$vl){
            if(!eregi('#', $ky)){
                $created[$ky] = $vl;
            } else {
                $formhead[$ky] = $vl;
            }
        }
        if(isset($value['#addmenu'])){
            $result .= __create_add_menu($value['#addmenu']);
        }
        $result .= __create_form_open($formhead, $key, $idform, $classform); unset($formhead);
        $result .= __create_form_items($created, $iditem, $classitem); unset($created);
        $result .= __create_form_close();
    } unset($created);
    return $result;
}

function __create_info($value){
    $result = '';
    $result .= '<div>';
    $result .= $value['show'];
    $result .= '</div>' . "\n";
    return $result;
}

function __create_search($value){
//    echo '<pre>'; print_r($value); echo '</pre>';
//    $result .= "<br />Search\n <hr>";
    $result .= "<div id=search>";
    $result .= "<font class=judul>Search</font>";
    if(is_array($value)){
        foreach($value as $yk => $lv){
//    echo '<pre>'; print_r($value); echo '</pre>';
            if($yk == 'dataform'){
                foreach($lv as $key => $val){
                    if(isset($next)){
//                        $result .= "\n" . "<hr>\n";
                    }
                    if($val['#type'] == 'character'){
                        $result .= "<div id=by_letter>Pencarian dengan huruf awalan : &nbsp;";
                        foreach($val['data'] as $ky => $vl){
                            if(isset($koma)){$result .= ', ';}
                            $result .= !is_null($vl['links']) ? '<a href="' . $vl['links'] . '"><strong>' : '';
                            $result .= $vl['show'];
                            $result .= !is_null($vl['links']) ? '</strong></a>' : '';
                            $koma = 0;
                        } unset($koma);
                    $result .= "</div>";
                    } elseif($val['#type'] == 'form'){
                        $getform[] = $val;
                        $result .= __create_form($getform);
                        unset($getform);
                    } $next = 0;
//                    $result .= "\n";
                } unset($next);
            } elseif($yk == 'result'){
                $result .= "</div>";
                $result .= __create_notelist($lv);
            }
        }
    }
    $result .= "</div>";
    return $result;
}

function __create_notelist($value){
//   echo '<pre>'; print_r($value); echo '</pre>';
    $result = "<br /><br />\n";
    $result .= '<div>' . "\n";
    $result .= '<div>' . $value['description'] . '</div>' . "\n";
    if(count($value['data']) > 0){
        foreach($value['data'] as $key => $val){
            $result .= '<hr>' . "\n";
            $result .= '<div><a href="' . $val['links'] . '"><strong><font size=+1>' . $val['caption'] . '</font></strong></a>' . "\n";
            $result .= '<div>' . "\n";
            foreach ($val['string'] as $ky => $vl){
                if(isset($koma)){$result .= '; ';}
                $result .= '<font style="color:green">' . $ky . '</font> ' . $vl; $koma = 0;
            } unset($koma);
            $result .= '</div>' . "\n";
        }
    }
    $result .= '</div>' . "\n";
    return $result;
}

function __create_main_image()
{
    $result .= '<center><IMG SRC="/themes/default/images/main_image.png"></center><br />';
    
    $result .= "<br />";
    return $result;
}

require_once THEMES_DIR . DS . $theme . DS . 'page.tpl';

//end of file;
