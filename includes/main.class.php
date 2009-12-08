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
 *  mainclass.php
 *  
 *  Created on Sep 10, 2009, 5:17:23 AM
 */

class mainModule
{
    var $config;
    var $sysquery;
    var $path_vars;
    var $vardump;
    var $formhabit;
    var $kelamin = array(
        'perempuan',
        'laki-laki'
    );

    var $goldarah = array(
        'A',
        'B',
        'AB',
        'O'
    );


    var $agama = array(
        'islam',
        'kristen protestan',
        'kristen katolik',
        'hindu',
        'budha',
        'lainnya'
    );
    var $nama_bulan = array(
        '1' => 'januari',
        '2' => 'februari',
        '3' => 'maret',
        '4' => 'april',
        '5' => 'mei',
        '6' => 'juni',
        '7' => 'juli',
        '8' => 'agustus',
        '9' => 'september',
        '10' => 'oktober',
        '11' => 'november',
        '12' => 'desember'
    );
    var $maritalStatus = array(
        'kawin',
        'tidak kawin',
        'cerai'
    );
    var $string_to_shuffle = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890';

    function __get_module_table_lists(){
        $result = array();
        foreach($this->config->table_scheme as $key => $value){
            $result[] = $key;
        }
        return $result;
    }

    function __get_field_lists($tablename){
        $result =array();
        if($this->config->table_scheme[$tablename]){
            foreach($this->config->table_scheme[$tablename] as $key => $value){
                $result[] = $key;
            }
        }
        return $result;
    }

    function __check_field_exist($tablename, $fieldname){
        $lists = $this->__get_field_lists($tablename);
        if(in_array($fieldname, $lists)){
            unset($lists);
            return TRUE;
        } else {
            unset($lists);
            return FALSE;
        }
    }

    function __drop_field($tablename, $fieldname, $interpreter){
        $thefields = $this->__get_data_fields($tablename, $interpreter);
        if(in_array($fieldname, $thefields)){
            $sql = $interpreter->alterTableColumn(
                $tablename,
                array($fieldname)
            );
            $interpreter->connect();
            $interpreter->conn->Execute($sql); unset($sql);
            $interpreter->close();
        }
    }

    function __get_db_table_lists($interpreter){
        $result = array();
        $sql = $interpreter->showTables();
        $interpreter->connect();
        $getit = $interpreter->conn->Execute($sql); unset($sql);
        $interpreter->close();
        if($getit->_numOfRows > 0){
            for($i=0; $i<$getit->_numOfRows; $i++){
                $result[] = $getit->fields['Tables_in_' . $interpreter->getDbName()];
                $getit->MoveNext();
            }
        }
        return $result;
    }

    function sync_scheme($tablename, $interpreter){
        $lists = $this->__get_db_table_lists($interpreter);
//        echo '<pre>'; print_r($lists); echo '</pre>';
        if(in_array($tablename, $lists)){
            unset($lists);
            $lists = $this->__get_field_lists($tablename);
            $thefields = $this->__get_data_fields($tablename, $interpreter);
            $dbfieldlists = $this->__get_data_fields($tablename, $interpreter, 1);
            foreach($thefields as $value){
                if(!in_array($value, $lists)){
                    $this->__drop_field($tablename, $value, $interpreter);
                }
            }
            foreach($lists as $value){
                if(!in_array($value, $thefields)){
                    $sql = $interpreter->alterTableColumn(
                        $tablename,
                        array($value),
                        'add',
                        $this->config->table_scheme[$tablename][$value]['type'],
                        $this->config->table_scheme[$tablename][$value]['key'],
                        ($this->config->table_scheme[$tablename][$value]['null'] > 0 ? FALSE : TRUE),
                        $this->config->table_scheme[$tablename][$value]['default'],
                        (trim($this->config->table_scheme[$tablename][$value]['extra']) != '' ? $this->config->table_scheme[$tablename][$value]['extra'] : NULL)
                    );
                } else {
                    if($dbfieldlists[$value]['Type'] != $this->config->table_scheme[$tablename][$value]['type'] ||
                        (trim($this->config->table_scheme[$tablename][$value]['key']) != '' && !eregi($dbfieldlists[$value]['Key'], $this->config->table_scheme[$tablename][$value]['key'])) ||
                        $dbfieldlists[$value]['Null'] != $this->config->table_scheme[$tablename][$value]['null'] ||
                        $dbfieldlists[$value]['Default'] != $this->config->table_scheme[$tablename][$value]['default'] ||
                        $dbfieldlists[$value]['extra'] != $this->config->table_scheme[$tablename][$value]['extra']){
                        $fieldsarray = array($value, $value);
                    }
                    if(isset($fieldsarray)){
                        $sql = $interpreter->alterTableColumn(
                            $tablename,
                            $fieldsarray,
                            'change',
                            $this->config->table_scheme[$tablename][$value]['type'],
                            $this->config->table_scheme[$tablename][$value]['key'],
                            ($this->config->table_scheme[$tablename][$value]['null'] > 0 ? FALSE : TRUE),
                            $this->config->table_scheme[$tablename][$value]['default'],
                            (trim($this->config->table_scheme[$tablename][$value]['extra']) != '' ? $this->config->table_scheme[$tablename][$value]['extra'] : NULL)
                        );
                        unset($fieldsarray);
                    }
                }
                if(isset($sql)){
                    $interpreter->connect();
                    $interpreter->conn->Execute($sql); unset($sql);
                    $interpreter->close();
                }
            } unset($thefields);
        } else {
            if(isset($this->config->table_scheme[$tablename])){
                $elements = array();
                foreach($this->config->table_scheme[$tablename] as $key => $value){
                    $elements[$key] = $value['type'] . (trim($value['key']) != '' && eregi('uni', $value['key']) ? ' UNIQUE' : '') . ($value['null'] < 1 ? ' NOT NULL' : '') . (!is_null($value['default']) ? ' DEFAULT ' . $value['default'] : '') . (trim($value['extra']) != '' ? ' ' . $value['extra'] : '');
                    if(trim($value['key']) != '' && eregi('pri', $value['key'])){
                        $primarykey = $key;
                    }
                }
                $sql = $interpreter->createTable(
                    $tablename,
                    $elements,
                    (isset($primarykey) ? $primarykey : NULL)
                );
                $interpreter->connect();
                $interpreter->conn->Execute($sql); unset($sql);
                $interpreter->close();
            }
        }
    }

    function __exec_db_ops($interpreter, $tbname, $opr, $id, $arrayval=NULL){
        if(eregi('delete', $opr) || eregi('insert', $opr) || eregi('update', $opr)){
            $thevalue['dbname'] = $interpreter->dbname;
            $thevalue['tbname'] = $tbname;
            $thevalue['operation'] = $opr;
            $thevalue['inputer'] = isset($arrayval['inputer']) ? $arrayval['inputer'] : $_COOKIE[$this->config->cookieid];
            $thevalue['inputtime'] = isset($arrayval['inputtime']) ? $arrayval['inputtime'] : date('Y-m-d H:i:s', $this->config->time);
            $thevalue['iddata'] = $id[1];
            $dumpval = '';
            if(eregi('delete', $opr)){
                $sql = $interpreter->getSelect(
                    array(),
                    array($tbname),
                    array(
                        array('&&', $id[0] . "=" . $id[1])
                    )
                );
                $interpreter->connect();
                $getit = $interpreter->conn->Execute($sql); unset($sql);
                $interpreter->close();
                if($getit->_numOfRows > 0){
                    foreach($getit->fields as $key => $value){
                        if(isset($koma)){
                            $dumpval .= '][';
                        }
                        $dumpval .= $key . '=>' . $value;
                        $koma = 0;
                    } unset($koma);
                }
                $sql = $interpreter->setDelete(
                    $tbname,
                    array(
                        array('&&', $id[0] . "=" . $id[1])
                    )
                );
                $interpreter->connect();
                $interpreter->conn->Execute($sql); unset($sql);
                $interpreter->close();
            } else {
                if(eregi('insert', $opr)){
                    $sql = $interpreter->saveData(
                        $tbname,
                        $arrayval
                    );
                    $interpreter->connect();
                    $interpreter->conn->Execute($sql); unset($sql);
                    $interpreter->close();
                } else {
                    $sql = $interpreter->updateData(
                        $tbname,
                        $arrayval,
                        array(
                            array('&&', $id[0] . "=" . $id[1])
                        )
                    );
                    $interpreter->connect();
                    $interpreter->conn->Execute($sql); unset($sql);
                    $interpreter->close();
                }
                foreach($arrayval as $key => $value){
                    if(isset($koma)){
                        $dumpval .= '][';
                    }
                    $dumpval .= $key . '=>' . $value;
                    $koma = 0;
                } unset($koma);
            }
            if(trim($dumpval) != ''){
                $thevalue['volume'] = $dumpval;
                unset($dumpval);
            }
            $sql = $this->sysquery->saveData(
                'logtrack',
                $thevalue
            );
            $this->sysquery->connect();
            $this->sysquery->conn->Execute($sql); unset($sql);
            $this->sysquery->close();
            unset($thevalue);
        }
    }
    
    function __get_id_insert_value($table, $id, $interpreter){
        $result = 1;
        $interpreter->connect();
        $sql = $interpreter->getSelect(
            array($id),
            array($table)
        );
        $query = $interpreter->conn->Execute($sql); unset($sql);
        $interpreter->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $interpreter->connect();
                $sql = $interpreter->getSelect(
                    array($id),
                    array($table),
                    array(
                        array('&&', $id . '=' . $result)
                    )
                );
                $value = $interpreter->conn->Execute($sql); unset($sql);
                $interpreter->close();
                if($value->_numOfRows < 1){
                    unset($query, $value);
                    break;
                }
                $result++;
            }
        }
        return $result;
    }

    function __get_user_info($cookietype = NULL){
        $result = array();
        if(is_null($cookietype)){
            $where = array(
                array('&&', $this->config->auth_use_table[4] . "=" . $_COOKIE[$this->config->cookieid])
            );
        } else {
            $where = array(
                array('&&', $this->config->auth_use_table[3] . "=" . $_COOKIE[$this->config->cookiesession])
            );
        }
        $this->sysquery->connect();
        $sql = $this->sysquery->getSelect(
            array(),
            array($this->config->auth_use_table[0]),
            $where
        );
        $query = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        foreach($query->fields as $key => $value){
            $result[$key] = $value;
        }
        return $result;
    }

    function __get_agama_options(){
        $result = array();
        ksort($this->agama);
        foreach($this->agama as $key => $value){
            $result[$value] = ucwords(__t($value));
        }
        return $result;
    }

    function __get_kelamin_options(){
        $result = array();
        krsort($this->kelamin);
        foreach($this->kelamin as $key => $value){
            $result[$key] = ucwords(__t($value));
        }
        return $result;
    }
    // ------ add by emmank ----
    function __get_goldarah_options(){
        $result = array();
        krsort($this->goldarah);
        foreach($this->goldarah as $key => $value){
            $result[$value] = ucwords(__t($value));
        }
        return $result;
    }



    function __get_statusm_options(){
        $result = array();
//        krsort($this->maritalStatus);
        foreach($this->maritalStatus as $key => $value){
            $result[$value] = ucwords(__t($value));
        }
        return $result;
    }

    function __get_bahasa_options(){
        $result = array();
        $this->sysquery->connect();
        $sql = $this->sysquery->getDescribe('translations');
        $query = $this->sysquery->conn->Execute($sql); unset($sql);
        for($i=0; $i<$query->_numOfRows; $i++){
            if($query->fields['Field'] != 'strkey'){
                $result[$query->fields['Field']] = ucwords(__t($query->fields['Field']));
            }
            $query->MoveNext();
        } unset($query);
        $this->sysquery->close();
        return $result;
    }

    function __get_group_options($field){
        $result = array();
        $this->sysquery->connect();
        $sql = $this->sysquery->getSelect(
            array(),
            array('groups'),
            NULL,
            'name'
        );
        $query = $this->sysquery->conn->Execute($sql); unset($sql);
        for($i=0; $i<$query->_numOfRows; $i++){
            $result[$query->fields['id']] = ucwords(__t($query->fields[$field]));
            $query->MoveNext();
        } unset($query);
        $this->sysquery->close();
        return $result;
    }

    function __get_theme_options(){
        $result = array();
        $lists = __get_theme_lists();
        foreach($lists as $value){
            $result[$value] = ucwords(__t($value));
        }
        return $result;
    }

    function __get_kabupaten_options($field){
        $result = array();
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('kabupaten'),
            NULL,
            $field
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        for($i=0; $i<$query->_numOfRows; $i++){
            $result[$query->fields['id_kab']] = ucwords(__t($query->fields[$field]));
            $query->MoveNext();
        } unset($query);
        $this->query->close();
        return $result;
    }

    function __get_propinsi_options($field){
        $result = array();
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('propinsi'),
            NULL,
            $field
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        for($i=0; $i<$query->_numOfRows; $i++){
            $result[$query->fields['kode_bps']] = ucwords(__t($query->fields[$field]));
            $query->MoveNext();
        } unset($query);
        $this->query->close();
//        print_r ($result);
        return $result;
    }

    function __write_form_cache(){
        $result = array();
        $handle = '';
        $row = 0;
        foreach($_POST as $key=>$value){
            if($row > 0){
                $handle .= $this->config->cacheseparator;
            }
            if(eregi('tgl', $key)){
                if(is_array($value)){
                    foreach($value as $ke=>$val){
                        if($val == ''){$false = 0; break;}
                        elseif(!is_int($val)){$false = 0; break;}
                    }
                    if(isset($false)){
                        if(!isset($blank)){
                            $blank = array();
                        }
                        if(!in_array($key, $blank)){
                            $blank[] = $key;
                        }
                    }
                } else {
                    $value = explode('-', $value);
                }
                if(checkdate($value[1], $value[2], $value[0]) === false){
                    if(!isset($blank)){
                        $blank = array();
                    }
                    if(!in_array($key, $blank)){
                        $blank[] = $key;
                    }
                }
                ksort($value);
                $value = implode('-', $value);
                $result[$key] = $value;
            } elseif(is_array($value)){
                $result[$key] = $value;
                $value = implode('|', $value);
            } else {
                if($value == ''){
                    if(!isset($blank)){
                        $blank = array();
                    }
                    if(!in_array($key, $blank)){
                        $blank[] = $key;
                    }
                }
                $value = $this->__reduce_newline($value);
                $result[$key] = $value;
            }
            $handle .= $key . '=>' . $value; $row++;
        } unset($row);
        if(isset($blank)){
            $result['blank'] = $blank;
            $handle .= $this->config->cacheseparator . "###blank###" . implode('|', $blank);
        }
        $sql = $this->sysquery->getSelect(
            array('id'),
            array('caches'),
            array(
                array('&&', "id=" . $_COOKIE[$this->config->cookiesession])
            )
        );
        $this->sysquery->connect();
        $checkit = $this->sysquery->conn->Execute($sql);unset($sql);
        $this->sysquery->close();
        if($checkit->_numOfRows > 0){
            $sql = $this->sysquery->setDelete(
                'caches',
                array(
                    array('&&', "id=" . $_COOKIE[$this->config->cookiesession])
                )
            );
            $this->sysquery->connect();
            $this->sysquery->conn->Execute($sql); unset($sql);
            $this->sysquery->close();
        }
        $sql = $this->sysquery->saveData(
            'caches',
            array(
                'id' => $_COOKIE[$this->config->cookiesession],
                'caches' => $handle
            )
        );
        unset($handle);
        $this->sysquery->connect();
        $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        return $result;
    }

    function __write_custom_cache($strvar, $add=NULL){
        $result = array();
        $handle = '';
        if(!is_null($add)){
            $sql = $this->sysquery->getSelect(
                array('caches'),
                array('caches'),
                array(
                    array('&&', "id=" . $_COOKIE[$this->config->cookiesession])
                )
            );
            $this->sysquery->connect();
            $getit = $this->sysquery->conn->Execute($sql); unset($sql);
            $this->sysquery->close();
            $handle = $getit->fields['caches'];
            unset($getit);
        }
        $sql = $this->sysquery->setDelete(
            'caches',
            array(
                array('&&', "id=" . $_COOKIE[$this->config->cookiesession])
            )
        );
        $this->sysquery->connect();
        $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        $handle .= $this->config->cacheseparator;
        if(count($strvar) > 0){
            foreach($strvar as $key => $value){
                if(isset($nl)){$handle .= $this->config->cacheseparator;}
                $result[$key] = $value;
                $handle .= $key . '=>' . $value; $nl = 0;
            } unset($nl);
        }
        $sql = $this->sysquery->saveData(
            'caches',
            array(
                'id' => $_COOKIE[$this->config->cookiesession],
                'caches' => $handle
            )
        );
        $this->sysquery->connect();
        $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        unset($handle);
        return $result;
    }

    function __reduce_newline($string){
        $result = preg_replace('/(\s+)(\n)/',''.' ',$string);
        return($result);
    }

    function __check_caches(){
        $sql = $this->sysquery->getSelect(
            array(),
            array('caches'),
            array(
                array('&&', "id=" . $_COOKIE[$this->config->cookiesession])
            )
        );
        $this->sysquery->connect();
        $getit = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        if($getit->_numOfRows > 0){
            return TRUE;
        } else {
            return FALSE;
        }
    }

    function __read_form_cache(){
        $sql = $this->sysquery->getSelect(
            array(),
            array('caches'),
            array(
                array('&&', "id=" . $_COOKIE[$this->config->cookiesession])
            )
        );
        $this->sysquery->connect();
        $getit = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        $handle = explode($this->config->cacheseparator, $getit->fields['caches']);
        unset($getit);
        foreach ($handle as $ky => $buffer){
            if(trim($buffer) != ''){
                if(!eregi('###blank###',trim($buffer))){
                    list($key, $value) = explode('=>', trim($buffer));
                    if(eregi('tgl', $key)){
//                        $value = explode('-', trim($value));
                    } elseif(preg_match('/\|/', trim($value))){
                        $value = explode('|', trim($value));
                    }
                    $result[$key] = $value;
                    unset($value, $key);
                } else {
                    $result['blank'] = explode('|', str_ireplace('###blank###', '', trim($buffer)));
                }
            }
        } unset($handle);
        $this->__flush_caches();
        return $result;
    }

    function __flush_caches($all = NULL){
        if(!is_null($all)){
            $sql = $this->sysquery->setDelete(
                'caches'
            );
            $this->sysquery->connect();
            $this->sysquery->conn->Execute($sql); unset($sql);
            $this->sysquery->close();
        } else {
            $this->__delete_cache($_COOKIE[$this->config->cookiesession]);
        }
    }

    function __delete_cache($id){
        $sql = $this->sysquery->setDelete(
            'caches',
            array(
                array('&&', "id=" . $id)
            )
        );
        $this->sysquery->connect();
        $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
    }

    function __get_cache_lists(){
        $result = array();
        $sql = $this->sysquery->getSelect(
            array('id'),
            array('caches')
        );
        $this->sysquery->connect();
        $getit = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        if($getit->_numOfRows > 0){
            for ($i=0; $i<$getit->_numOfRows; $i++){
                $result[] = $getit->fields['id'];
                $getit->MoveNext();
            }
        }
        return $result;
    }

    function __cache_inspects(){
        $sql = $this->sysquery->getSelect(
            array('sesi'),
            array('users'),
            array(
                array('&&', "sesi is not null")
            )
        );
        $this->sysquery->connect();
        $getit = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        if($getit->_numOfRows > 0){
            $lists = array();
            for($i=0; $i<$getit->_numOfRows; $i++){
                $lists[] = $getit->fields['sesi'];
                $getit->MoveNext();
            }
            $cachelists = $this->__get_cache_lists();
            foreach($cachelists as $value){
                if(!in_array($value, $lists)){
                    $this->__delete_cache($value);
                }
            } unset($cachelists, $lists);
        } else {
            $this->__flush_caches(1);
        }
    }

    function agecount_in_month($birthdate){
        $yeardate = date("Y",$birthdate);
        return ((date("Y",$this->config->time)-date("Y",$birthdate))*12)+date("n",$this->config->time)-date("n",$birthdate);
    }

    function message(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        $message = $dump[(count($dump) - 1)]; unset($dump);
        $result = array(
            'type' => 'info',
            'show' => ucfirst(__t($message))
        ); unset($message);
//        echo '<pre>'; print_r($result); echo '</pre>'; exit();
        return $result;
    }

    function __get_patient_data($idp, $fields = array()){
        $result = array();
        $this->query->connect();
        $sql = $this->query->getSelect(
            $fields,
            array('patients'),
            array(
                array('&&', "id=" . $idp)
            )
        );
//        $this->conn->debug = true;
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            foreach($query->fields as $key => $value){
                $result[$key] = $value;
            }
        } unset($query);
        return $result;
    }

    function __get_data_fields($table, $interpreter, $elements=NULL){
        $result = array();
        $interpreter->connect();
        $sql = $interpreter->getDescribe($table);
//        $this->query->conn->debug = true;
        $query = $interpreter->conn->Execute($sql); unset($sql);
        $interpreter->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!is_null($elements)){
                $result[$query->fields['Field']] = $query->fields;
            } else {
                $result[] = $query->fields['Field'];
            }
            $query->MoveNext();
        } unset($query);
//       print_r ($result);
        return $result;
    }

    function __get_bagian_id($bagian){
        $result = '';
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id'),
            array('bagian'),
            array(
                array('&&', "bagian=" . $bagian)
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            $result = $query->fields['id'];
        }
        return $result;
    }

    function __get_bagian_lists(){
        $result = array();
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('bagian'),
            NULL,
            'id'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result[$query->fields['id']] = $query->fields['bagian'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function today_patient_lists(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
//        echo '<pre>'; print_r($dump); echo '</pre>'; exit();
//        if(count($dump) > 3){
        $bagian = trim($dump[1]);
//        } else {
//            redirect_to('/');
//        }
        $result = array();
//        $idbagian = $this->__get_bagian_id($bagian);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('kunjungan'),
            array(
                array('&&', "year(pukul)=" . date('Y', $this->config->time)),
                array('&&', "month(pukul)=" . date('n', $this->config->time)),
                array('&&', "day(pukul)=" . date('j', $this->config->time)),
//                array('&&', "bagian=" . $idbagian),
                array('&&', "bagian=" . $bagian),
                array('&&', "doneby is null")
            ),
            'pukul'
        ); unset($idbagian);
//        $this->query->conn->debug = true;
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
//        exit();
        if($query->_numOfRows == 1){
            redirect_to('/user/' . $bagian . '/form/' . $query->fields['id']);
//            exit();
        } elseif($query->_numOfRows < 1){
//          echo 'di sini di bagian ' . $bagian; exit();
            $pesan = __t('tidak ada pasien hari ini !');
            redirect_to('/user/' . $bagian . '/message/' . urlencode($pesan));
        }
        for($i=0; $i<$query->_numOfRows; $i++){
            $result['type'] = 'table';
            $result['title'] = __t('antrian');
            $result['description'] = __t('Daftar Antrian Pasien');
            $result['header'] = array(
                array(
                    'field' => 'none',
                    'caption' => __t('no'),
                    'width' => '5%',
                    'align' => 'right'
                ),
                array(
                    'field' => 'nomor',
                    'caption' => __t('Nomor Register'),
                    'width' => '15%',
                    'align' => 'center'
                ),
                array(
                    'field' => 'patients',
                    'caption' => __t('Nama'),
                    'align' => 'left'
                ),
                array(
                    'field' =>'nourut',
                    'caption' => __t('No Urut'),
                    'width' => '15%',
                    'align' => 'center'
                )
            );
            $gpatient = $this->__get_patient_data($query->fields['patients']);
            if(count($gpatient) > 0){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['nomor'] = ucwords($gpatient['nomor']);
                $result['data'][$i]['patients'] = ucwords($gpatient['nama']);
                $age = $this->agecount_in_month(strtotime($gpatient['tgl_lahir']));
                $result['data'][$i]['age'] = floor($age / 12); unset($age);
                $result['data'][$i]['nourut'] = ucwords($query->fields['nourut']);
                $result['data'][$i]['goto'] = '/user/' . $bagian . '/form/' . $query->fields['id'];
            } unset($gpatient);
            $query->MoveNext();
        } unset($query);
        return $result;
    }

    function __check_group_access($group, $uid){
        $this->sysquery->connect();
        $sql = $this->sysquery->getSelect(
            array('useradd'),
            array('groups'),
            array(
                array('&&', "id=" . $group)
            )
        );
        $query = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->close();
        if($query->_numOfRows > 0){
            $dump = explode(',', $query->fields['useradd']);
            if(in_array($uid, $dump)){
                return TRUE;
            } else {
                return FALSE;
            }
        } else {
            return FALSE;
        }
    }

    function __get_group_lists(){
        $result = array();
        $this->sysquery->connect();
        $sql = $this->sysquery->getSelect(
            array('id', 'name'),
            array('groups'),
            array(
                array('&&', "name!=admin"),
                array('&&', "name!=users")
            ),
            'id'
        );
        $query = $this->sysquery->conn->Execute($sql); unset($sql);
        $this->sysquery->connect();
        for($i=0; $i<$query->_numOfRows; $i++){
            $result[$query->fields['id']] = $query->fields['name'];
            $query->MoveNext();
        }
        return $result;
    }

    function __read_queue($filename){
        $result = array();
        $handle = fopen($filename, 'r');
        while(!feof($handle)){
            $buffer = fgets($handle);
            if(trim($buffer) != ''){
                list($key, $value) = explode('=>', trim($buffer));
                $result[$key] = $value;
            }
        }
        fclose($handle); unset($handle);
        return $result;
    }

    function __input_queue($filename, $volume){
        $handle = fopen($filename, 'w');
        foreach($volume as $key => $value){
            fwrite($handle, $key . '=>' . $value . "\n");
        }
        fclose($handle); unset($handle);
    }

    function __get_fqueue($num){
        $result = $this->__set_dqueue();
        $result .= DS . 'queue_' . str_repeat('0', 4-strlen($num)) . $num;
        return $result;
    }

    function __set_dqueue(){
        $dircache = FILES_DIR . DS . 'queue';
        if(!is_dir($dircache . DS . date('Y-m-d', $this->config->time))){
            mkdir ($dircache . DS . date('Y-m-d', $this->config->time), 0700);
        }
        $dircache .= DS . date('Y-m-d', $this->config->time);
        if(!is_dir($dircache . DS . 'queue')){
            mkdir ($dircache . DS . 'queue', 0700);
        }
        return $dircache . DS . 'queue';
    }

    function __set_dincrement(){
        $dircache = FILES_DIR . DS . 'queue';
        if(!is_dir($dircache . DS . date('Y-m-d', $this->config->time))){
            mkdir ($dircache . DS . date('Y-m-d', $this->config->time), 0700);
        }
        $dircache .= DS . date('Y-m-d', $this->config->time);
        if(!is_dir($dircache . DS . 'increment')){
            mkdir ($dircache . DS . 'increment', 0700);
        }
        return $dircache . DS . 'increment';
    }

    function __get_fqmax(){
        $result = 1;
        $sql = $this->query->getSelect(
            array('max(nourut) as nourut'),
            array('antrian'),
            array(
                array('&&', "year(pukul)=" . date('Y', $this->config->time)),
                array('&&', "month(pukul)=" . date('n', $this->config->time)),
                array('&&', "day(pukul)=" . date('j', $this->config->time))
            )
        );
        $this->query->connect();
        $getit = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($getit->_numOfRows > 0){
            $result = $getit->fields['nourut'] + 1;
        }
        return $result;
    }

    function __is_dropable($id, $fieldname, $referenceby, $interpreter){
        $interpreter->connect();
        $sql = $interpreter->getSelect(
            array('id'),
            array($referenceby),
            array(
                array('&&', $fieldname . "=" . $id)
            )
        );
//        $interpreter->conn->debug=true;
        $query = $interpreter->conn->Execute($sql); unset($sql);
        $interpreter->close();
        if($query->_numOfRows < 1){
            return TRUE;
        } else {
            return FALSE;
        }
    }

    function __include_module($module){
        require MODULES_DIR . DS . $module . DS . $module . '.module';
        $this->{$module . '_config'} = ${$module . '_config'};
        $this->{$module . '_config'}->time = $this->config->time;
        $this->{$module . '_config'}->timelog_idle = $this->onfig->timelog_idle;
        $this->{$module . '_config'}->fcache = $this->config->fcache;
        $this->{$module . '_config'}->flog = $this->config->flog;
        $funcdb = $module == 'user' || $module == 'auth' || $module == 'group' ? 'dbuser' : 'db' . $module;
        $this->{$module . '_query'} = ${$module . '_query'};
        $this->{$module . '_query'}->dbname = $this->{$module . '_config'}->{$funcdb}['name'];
        $this->{$module . '_query'}->dbprefix = $this->{$module . '_config'}->{$funcdb}['prefix'];
        $this->{$module . '_query'}->dbsuffix = $this->{$module . '_config'}->{$funcdb}['suffix'];
        $this->{$module . '_query'}->tbprefix = $this->{$module . '_config'}->{$funcdb}['tbprefix'];
        $this->{$module . '_query'}->tbsuffix = $this->{$module . '_config'}->{$funcdb}['tbsuffix'];
        $this->{$module . '_query'}->hostname = $this->{$module . '_config'}->{$funcdb}['host'];
        $this->{$module . '_query'}->username = $this->{$module . '_config'}->{$funcdb}['user'];
        $this->{$module . '_query'}->passwd = $this->{$module . '_config'}->{$funcdb}['passwd'];
        $this->{$module . '_query'}->conn = &ADONewConnection($this->{$module . '_config'}->rdbms);
        $this->{$module . '_exec'} = ${$module . '_exec'};
        $this->{$module . '_exec'}->config = $this->{$module . '_config'};
        $this->{$module . '_exec'}->sysquery = $this->sysquery;
        $this->{$module . '_exec'}->query = $this->{$module . '_query'};
   }

   function __iterate($data){
       $result = array();
       foreach($data as $key => $value){
           $result[] = $value;
           $dump = $value;
           for($i=($key+1); $i<count($data); $i++){
               $dump .= ' ' . $data[$i];
               $result[] = $dump;
           }
       }
       return $result;
   }

   function __get_patients_search($data){
       $result = array();
       $patient_fields = $this->__get_data_fields('patients', $this->query);
       if(strlen(trim($data)) < 2){
           $sql = $this->query->getSelect(
               array('id'),
               array('patients'),
               array(
                   array('&&', "nama like '" . trim($data) . "%'")
               )
           );
           $this->query->connect();
           $getit = $this->query->conn->Execute($sql); unset($sql);
           $this->query->close();
           if($getit->_numOfRows > 0){
               $dump = array();
               for($i=0; $i<$getit->_numOfRows; $i++){
                   $dump[] = $getit->fields['id'];
                   $getit->MoveNext();
               }
               $result[trim($data)] = $dump;
               unset($dump);
           } unset($getit);
       } else {
           $dump = explode(' ', trim($data));
           $getdump = array();
           foreach($dump as $value){
               $getdump[] = trim($value);
           } unset($dump);
           $dump = $this->__iterate($getdump);
    //       echo '<pre>'; print_r($dump); echo '</re>'; exit();
           unset($getdump);
           foreach($dump as $key => $value){
               $sql = $this->query->getSelect(
                   array(),
                   array('isearch_patients'),
                   array(
                       array('&&', "phrase like '%" . $value . "%'")
                   )
               );
               $this->query->connect();
    //           $this->query->conn->debug=true;
               $getit = $this->query->conn->Execute($sql); unset($sql);
               $this->query->close();
               if($getit->_numOfRows > 0){
                   $getdump = array();
                   for($i=0; $i<$getit->_numOfRows; $i++){
                       $getdump[] = $getit->fields['id'];
                       $getit->MoveNext();
                   }
                   $result[$value] = $getdump;
                   unset($getdump);
               }
           } unset($dump);
       }
//       echo '<pre>'; print_r($result); echo '</pre>';
       return $result;
   }

}
