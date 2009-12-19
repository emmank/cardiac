<script language="JavaScript" type="text/JavaScript">

function showKab()
 {
     <?php
    // membaca semua propinsi

    global $systemquery;
    $result = array();
    $systemquery->connect();
    $sql = $systemquery->getSelect(
        array('kode_bps','nama_propinsi'),
        array('propinsi')
    );
//    $sql = $systemquery->showTables();
    $query = $systemquery->conn->Execute($sql); unset($sql);
    for($i=0; $i<$query->_numOfRows; $i++){
//        $result[] = $query->fields;
          $id_prop = $query->fields['kode_bps'];
//          echo $query->fields[0];
           echo "if (document.patient.propinsi.value == \"".$id_prop."\")";
           echo "{";

           $kota = $systemquery->getSelect (
               array('id_kab','kabupaten'),
               array('kabupaten'),
               array(
                    array('&&',"kode_bps=".$id_prop)
                    )
           );
//           echo $kota;
//           $systemquery->connect();
           $query_kota = $systemquery->conn->Execute($kota); unset($kota);
           $contentnya = "document.getElementById('kota').innerHTML = \"";
           for ($j=0; $j<$query_kota->_numOfRows; $j++) {
               $contentnya .= "<option value='".$query_kota->fields['id_kab']."'>".$query_kota->fields['kabupaten']."</option>";
               $query_kota->MoveNext();
           }
           unset ($query_kota);
           $contentnya .= "\"";
           echo $contentnya;
           echo "}\n";

        $query->MoveNext();
    
    } unset($query);
    $systemquery->close();
    ?>
 }

function changeLabel(bool) {
    if (document.forms[0].kelamin.value=="1"){
        document.getElementById("namapas").innerHTML="Nama Istri";
        document.getElementById("pekpas").innerHTML="Pekerjaan Istri";
    } else {
        document.getElementById("namapas").innerHTML="Nama Suami"
        document.getElementById("pekpas").innerHTML="Pekerjaan Suami"
    }
}

function disablePasangan(bool) {
    if (document.getElementById("status").value=="kawin") {
//        document.getElementById("tnamapas").value="";
//        document.getElementById("tpekpas").value="";
        document.getElementById("tnamapas").disabled=false;
        document.getElementById("tpekpas").disabled=false;
    } else {
//        document.getElementById("tnamapas").value="";
//        document.getElementById("tpekpas").value="";
        document.getElementById("tnamapas").disabled=true;
        document.getElementById("tpekpas").disabled=true;
    }
}

function disableChooseBerkunjung(bool) {
    if (document.getElementById("cara_berkunjung").value=="konsul") {
        document.getElementById("tchoosek").disabled=false;
        document.getElementById("tchoosed").disabled=true;
    } else if(document.getElementById("cara_berkunjung").value=="pilih dokter"){
        document.getElementById("tchoosek").disabled=true;
        document.getElementById("tchoosed").disabled=false;
    } else {
        document.getElementById("tchoosek").disabled=true;
        document.getElementById("tchoosed").disabled=true;
    }
}

function disableCaraBayar(bool) {
    if (document.getElementById("cara_bayar").value=="asuransi") {
        document.getElementById("tchooseb").disabled=false;
    } else {
        document.getElementById("tchooseb").disabled=true;
    }
}
</script>

