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
 *  dbquery.php
 *
 *  Created on Sep 6, 2009, 11:03:48 AM
 */

class dbset
{

    var $dbprefix;
    var $dbsuffix;
    var $tbprefix;
    var $tbsuffix;
    var $dbname;
    var $hostname;
    var $username;
    var $passwd;
    var $conn;

	function connect($fetchMode=NULL){
        $this->conn->Connect($this->hostname,$this->username,$this->passwd,$this->getDbName());
        $adofetchmode = (!is_null($fetchMode)&&$fetchMode!=''&&ctype_digit($fetchMode)?$fetchMode:ADODB_FETCH_ASSOC);
        $this->conn->SetFetchMode($adofetchmode);
	}

	function close(){
        $this->conn->Close();
        }

        function showTables(){
            $result = '';
            $result .= 'SHOW TABLES';
            return $result;
        }

        function alterTableColumn($table, $colname = array(), $operation='drop', $type='int', $thekey='', $notnull=FALSE, $default='', $extra=NULL){
            $result = '';
            if(count($colname) > 0){
                $result .= 'ALTER TABLE ' . $this->getTblName($table) . ' ' . strtoupper($operation) . ' COLUMN ' . $colname[0];
                if($operation == "change"){
                    $result .=  ' ' . $colname[1];
                }
                if(!eregi('drop', $operation)){
                    $result .= ' ' . $type;
                    if(trim($thekey) != '' && !eregi('pri', $thekey)){
                        if(eregi('uni', $thekey)){
                            $result .= ' UNIQUE';
                        }
                    }
                    if($notnull !== FALSE){
                        $result .= ' NOT NULL';
                    }
                    if(trim($default) != ''){
                        $result .= ' DEFAULT ' . $default;
                    }
                    if(!is_null($extra)){
                        $result .= ' ' . $extra;
                    }
                }
            }
            return $result;
        }

	function getDbName(){
	$dbname = (!is_null($this->dbprefix)&&$this->dbprefix!=''?$this->dbprefix.'_':'').$this->dbname.(!is_null($this->dbsuffix)&&$this->dbsuffix!=''?'_'.$this->dbsuffix:'');
	return $dbname;
	}

	function getTblName($tbname){
	$tbname = (!is_null($this->tbprefix)&&$this->tbprefix!=''?$this->tbprefix.'_':'').$tbname.(!is_null($this->tbsuffix)&&$this->tbsuffix!=''?'_'.$this->tbsuffix:'');
	return $tbname;
	}
	
	function getDescribe($table){
	$sql = 'DESC '.$this->getTblName($table);
	return $sql;
	}

        function createTable($table, $elements, $primary=NULL, $tabletype=NULL){
            $sql = 'CREATE TABLE ' . $this->getTblName($table) . ' (';
            foreach($elements as $key => $value){
                if(isset($koma)){
                    $sql .= ', ';
                }
                $sql .= $key . ' ' . $value;
                $koma = 0;
            } unset($koma);
            if(!is_null($primary)){
                $sql .= ', PRIMARY KEY (';
                if(is_array($primary)){
                    foreach($primary as $key => $value){
                        if(isset($koma)){$sql .= ', ';}
                        $sql .= $value;
                        $koma = 0;
                    } unset($koma);
                } else {
                    $sql .= $primary;
                }
                $sql .= ')';
            }
            if(!is_null($tabletype)){
                $sql .= ' ' . $tabletype;
            }
            $sql .= ')';
            return $sql;
        }

	function setDelete($table,$where=NULL){
	$sql = 'DELETE FROM '.$this->getTblName($table);
		if(isset($where) && !is_null($where) && is_array($where)){$sql .= $this->getWhere($where);}
	return $sql;
	}

	function saveData($table, $thevalue){
		if (!is_array($thevalue)){$sql = "error";} else {
		$sql = "INSERT INTO ".$this->getTblName($table)." ("; $first = 1;
			foreach($thevalue as $key=>$value){
				if (!isset($first)){$sql .= ", ";} else {unset($first);}
			$sql .= $key;
			}
		$sql .= ") values ("; $first = 1;
			foreach($thevalue as $value){
				if (!isset($first)){$sql .= ", ";} else {unset($first);}
			$sql .= is_null($value)?"NULL":"'".mysql_escape_string($value)."'";
			}
		$sql .= ")";
		}
	return $sql;
	}

	function updateData($table, $thevalue, $where=NULL){
		if (!is_array($thevalue)){$sql = "error";}
		else {
		$sql = "UPDATE ".$this->getTblName($table)." SET "; $first = 1;
			foreach($thevalue as $key=>$value){
				if (!isset($first)){$sql .= ", ";} else {unset($first);}
			$sql .= "$key=".(is_null($value)?"NULL":"'".mysql_escape_string($value)."'");
			}
			if(!is_null($where)){
			$sql .= $this->getWhere($where);
			} else {$sql = "error";}
		}
	return $sql;
	}

	
	function getSelect($select,$table,$where=NULL,$order=NULL){
		if (is_null($select) || is_null($table)){$sql = 'error';} elseif(!is_array($select) || !is_array($table)){
		$sql = "error";
		} elseif(count($table) < 1){
		$sql = "error";
		} else {
		$sql = "SELECT ";
			if(count($select)<1){ $sql .= "* ";} else {
				foreach($select as $key=>$value){
					if($key > 0){$sql .= ", ";}
					if(preg_match("/\s/",$value)){
					$listcl = explode(" ",$value);
						foreach($listcl as $ky=>$vl){
							if ($ky > 0){$sql .= " ";}
							if(preg_match("/\|/",$vl)){
							list($tbl,$clm) = explode("|",$vl);
							$sql .= $this->getTblName($tbl).".".$clm; unset($tbl,$clm);
							} else {$sql .= $vl;}
						}
					} else {
						if(preg_match("/\|/",$value)){
						list($tbl,$clm) = explode("|",$value);
						$sql .= $this->getTblName($tbl).".".$clm; unset($tbl,$clm);
						} else {$sql .= $value;}
					}
				}
			}
		$sql .= " FROM ";
			foreach ($table as $key=>$value){
				if($key > 0){$sql .= ", ";}
				if(preg_match("/\|/",$value)){
				list($dtbs,$tbl) = explode("|",$value);
				$sql .= $this->getDbName($dtbs).".".$this->getTblName($tbl); unset($dtbs,$tbl);
				} else {$sql .= $this->getTblName($value);}
			}
			if (isset($where) && !is_null($where) && is_array($where) && count($where) > 0){
			$sql .= $this->getWhere($where);
			}
			if(!is_null($order) && $order != '' && $order != '0'){
			$sql .= " ORDER BY ";
			$order = explode(",",$order); $first = 1;
				foreach ($order as $value){
					if (!isset($first)){$sql .= ", ";} else {unset($first);}
					if(preg_match("/\|/",$value)){
					$rdr = explode("|",$value);
						if (count($rdr)>2){
						$rdr[0] = $this->getDbName($rdr[0]);
						}
					$rdr[(count($rdr)>2?1:0)] = $this->getTblName($rdr[(count($rdr)>2?1:0)]);
					$sql .= implode(".",$rdr); unset($rdr);
					} else {$sql .= $value;}
				}
			}
		}
	return $sql;
	}
	
	function getWhere($where=NULL){
		if(is_null($where)){return NULL;} elseif(!is_array($where)){return NULL;} else {
			if(!isset($sql)){$sql = '';}
		$sql .= " WHERE ";
			if (count($where) > 1){
// 			echo '<pre>'; print_r($where); echo '</pre>';
				foreach($where as $key=>$value){
					if ($key > 0){$sql .= " ".$value[0]." ";}
				preg_match("/!=|=|<=|>=|<|>/",$value[1],$matches);
					if(count($matches)>0){
					$anunya = explode($matches[0],$value[1]);
// 				echo '<pre>'; print_r($value); echo '</pre>';
						if (preg_match("/\(/",$anunya[0])){
						$anunya0 = explode("(",$anunya[0]); $anunya0[1] = preg_replace("/\)/","",$anunya0[1]);
							if(preg_match("/\|/",$anunya0[1])){
							list($tble,$clme) = explode("|",$anunya0[1]);
							$anunya1 = $this->getTblName($tble).".".$clme; unset($tble,$clme);
							} else {$anunya1 = $anunya0[1];}
						$anunya[0] = $anunya0[0]."(".$anunya1.")"; unset($anunya0,$anunya1);
						} else {
							if (preg_match("/\|/",$anunya[0])){
							list($tble,$clme) = explode("|",$anunya[0]);
							$anunya[0] = $this->getTblName($tble).".".$clme; unset($tble,$clme);
							}
						}
						if (preg_match("/\|/",$anunya[1])){
						list($tble,$clme) = explode("|",$anunya[1]);
						$anunya[1] = $this->getTblName($tble).".".$clme; unset($tble,$clme);
						} else {
						$anunya[1] = !is_null($anunya[1])&&$anunya[1]!='NULL'?"'".mysql_escape_string($anunya[1])."'":'NULL';
						}
					$sql .= implode($matches[0],$anunya); unset($anunya);
// 					echo $sql.'<br>';
					} else {
					$anunya = explode(" ",$value[1]);
						if (preg_match("/\|/",$anunya[0])){
						list($tble,$clme) = explode("|",$anunya[0]);
						$anunya[0] = $this->getTblName($tble).".".$clme; unset($tble,$clme);
						}
					$sql .= implode(" ",$anunya);
					} unset($anunya);
				} //exit();
			} else {
			preg_match("/!=|=|<=|>=|<|>/",$where[0][1],$matches);
				if(count($matches)>0){
				$anunya = explode($matches[0],$where[0][1]);
					if (preg_match("/\(/",$anunya[0])){
					$anunya0 = explode("(",$anunya[0]); $anunya0[1] = preg_replace("/\)/","",$anunya0[1]);
						if(preg_match("/\|/",$anunya0[1])){
						list($tble,$clme) = explode("|",$anunya0[1]);
						$anunya1 = $this->getTblName($tble).".".$clme; unset($tble,$clme);
						} else {$anunya1 = $anunya0[1];}
					$anunya[0] = $anunya0[0]."(".$anunya1.")"; unset($anunya0,$anunya1);
					} else {
						if (preg_match("/\|/",$anunya[0])){
						list($tble,$clme) = explode("|",$anunya[0]);
						$anunya[0] = $this->getTblName($tble).".".$clme; unset($tble,$clme);
						}
					}
					if (preg_match("/\|/",$anunya[1])){
					list($tble,$clme) = explode("|",$anunya[1]);
					$anunya[1] = $this->getTblName($tble).".".$clme; unset($tble,$clme);
					} else {
					$anunya[1] = !is_null($anunya[1])&&$anunya[1]!=''?"'".mysql_escape_string($anunya[1])."'":'NULL';
					}
				$sql .= implode($matches[0],$anunya); unset($anunya);
				} else {
				$anunya = explode(" ",$where[0][1]);
					if (preg_match("/\|/",$anunya[0])){
					list($tble,$clme) = explode("|",$anunya[0]);
					$anunya[0] = $this->getTblName($tble).".".$clme; unset($tble,$clme);
					}
				$sql .= implode(" ",$anunya);
				} unset($anunya);
			}
		return $sql;
		}
	}
}
?>
