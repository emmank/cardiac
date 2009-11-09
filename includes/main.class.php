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
    var $kelamin = array(
        'perempuan',
        'laki-laki'
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
    var $string_to_shuffle = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890';
    
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

    function __get_user_info(){
        $result = array();
        $this->sysquery->connect();
        $sql = $this->sysquery->getSelect(
            array(),
            array($this->config->auth_use_table[0]),
            array(
                array('&&', $this->config->auth_use_table[4] . "=" . $_COOKIE[$this->config->cookieid])
            )
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
            $result[$key] = ucwords(__t($value));
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

    function __write_form_cache(){
//        echo '<pre>'; print_r($_POST); echo '</pre>'; exit();
        $result = array();
        $handle = fopen($this->config->fcache, 'w');
        $row = 0;
        foreach($_POST as $key=>$value){
            if($row > 0){
                fwrite($handle, "\n");
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
            fwrite($handle, $key . '=>' . $value); $row++;
        } unset($row);
        if(isset($blank)){
            $result['blank'] = $blank;
            fwrite($handle, "\n###blank###" . implode('|', $blank));
        }
        fclose($handle); unset($handle);
        return $result;
    }

    function __write_custom_cache($strvar, $add=NULL){
        $handle = fopen($this->config->fcache, (!is_null($add) ? 'a+' : 'w'));
        fwrite($handle, "\n");
//        echo '<pre>'; print_r($strvar); echo '</pre>';
        if(count($strvar) > 0){
            foreach($strvar as $key => $value){
                if(isset($nl)){fwrite($handle, "\n");}
                fwrite($handle, $key . '=>' . $value); $nl = 0;
            } unset($nl);
        }
        fclose($handle); unset($handle);
    }

    function __reduce_newline($string){
        $result = preg_replace('/(\s+)(\n)/',''.' ',$string);
        return($result);
    }

    function __read_form_cache(){
        $handle = fopen($this->config->fcache, 'r');
        while(!feof($handle)){
            $buffer = fgets($handle);
            if(trim($buffer) != ''){
                if(!eregi('###blank###',trim($buffer))){
                    list($key, $value) = explode('=>', trim($buffer));
                    if(eregi('tgl', $key)){
//                        $value = explode('-', trim($value));
                    } elseif(preg_match('/\|/', trim($value))){
                        $value = explode('|', trim($value));
                    }
                    $result[$key] = $value;
                } else {
                    $result['blank'] = explode('|', str_ireplace('###blank###', '', trim($buffer)));
                }
            }
            unset($buffer);
        }
        fclose($handle); unset($handle);
        return $result;
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

    function __get_data_fields($table, $interpreter){
        $result = array();
        $interpreter->connect();
        $sql = $interpreter->getDescribe($table);
//        $this->query->conn->debug = true;
        $query = $interpreter->conn->Execute($sql); unset($sql);
        $interpreter->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            $result[] = $query->fields['Field'];
            $query->MoveNext();
        } unset($query);
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
        $result = $this->__set_dincrement();
        $lists = __get_file_lists($result);
        if(count($lists) > 0){
            $result .= DS . ((int)max($lists) + 1);
        } else {
            $result .= DS . '1';
        }
        $handle = fopen($result, 'w');
        fclose($handle); unset($handle);
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
        $query = $interpreter->conn->Execute($sql); unset($sql);
        $interpreter->close();
        if($query->_numOfRows < 1){
            return TRUE;
        } else {
            return FALSE;
        }
    }

}
