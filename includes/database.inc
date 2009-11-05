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
 *  database.inc
 *
 *  Created on Sep 6, 2009, 11:03:48 AM
 */

class sysDb extends dbset
{
    var $conn;

	function connect($fetchMode=NULL){
        $this->conn->Connect($this->hostname,$this->username,$this->passwd,$this->getDbName());
        $adofetchmode = (!is_null($fetchMode)&&$fetchMode!=''&&ctype_digit($fetchMode)?$fetchMode:ADODB_FETCH_ASSOC);
        $this->conn->SetFetchMode($adofetchmode);
	}

	function close(){
        $this->conn->Close();
    }
}
