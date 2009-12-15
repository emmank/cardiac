<script language="JavaScript" type="text/JavaScript">

//function changeLabel(bool) {
//   document.getElementById("pret").innerHTML = (bool) ? "Nama Istri" : "Nama Suami";
//}

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

//function changeLabel(bool) {
//   <?php
//        echo "document.getElementById(\"Nama Suami Istri\").innerHTML = (bool) ? \"Nama Suami\" : \"Nama Istri\";";
//   ?>
//}

//function changeLabel2(bool) {
//   document.getElementById("namapas").innerHTML = (bool) ? "Nama Suami" : "Nama Istri";
//}

function changeLabel(bool) {
//    window.alert(bool);
//window.alert(document.forms[0].kelamin.value);
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
        document.getElementById("tnamapas").value="";
        document.getElementById("tpekpas").value="";
        document.getElementById("tnamapas").disabled=false;
        document.getElementById("tpekpas").disabled=false;
    } else {
        document.getElementById("tnamapas").value="";
        document.getElementById("tpekpas").value="";
        document.getElementById("tnamapas").disabled=true;
        document.getElementById("tpekpas").disabled=true;
    }
}



=======
</script>

<!--
<script language="JavaScript" type="text/JavaScript">
 function showKec()
 {
 <?php
/*
 // membaca semua kabupaten
 $query = "SELECT id_kab, kabupaten FROM kabupaten";
 $hasil = mysql_query($query);

global $systemquery;

$sql_kota = $systemquery->getSelect (
    array('id_kab','kabupaten'),
    array('kabupaten')
);

$systemquery->connect();
$query_kota = $systemquery->conn->Execute($sql_kota); unset($sql_kota);
for ($i=0; $i<$query_kota->_numOfRows;$i++) {
    $id_kab = $query_kota->fields['id_kab'];
    echo "if (document.patient.kota.value == \"".$id_kab."\")";
    echo "{";

    $sql_kecamatan = $systemquery->getSelect (
        array('id_kec','nama_kecamatan'),
        array('kecamatan'),
        array(
            array('&&',"id_kab=".$id_kab)
        )
    );
    $query_kec = $systemquery->conn->Execute($sql_kecamatan); unset ($sql_kecamatan);
    $kecamatannya = "document.getElementById('kecamatan').innerHTML = \"";
    for ($j=0; $j < $query_kec->_numOfRows;$j++) {
       $kecamatannya .= "<option value='".$query_kec->fields['id_kec']."'>".$query_kec->fields['nama_kecamatan']."</option>";
       $query_kec->MoveNext();
    }
    $kecamatannya .= "\"";
    echo $kecamatannya;
    echo "}\n";

$query_kota->MoveNext();
} unset($query);
$systemquery->close();



// // membuat if untuk masing-masing pilihan kabupaten beserta isi option untuk combobox kedua
// while ($data = mysql_fetch_array($hasil))
// {
//   $idProp = $data['id_kab'];
//
//   // membuat IF untuk masing-masing kabupaten
//   echo "if (document.daftar.kab.value == \"".$idProp."\")";
//   echo "{";
//
//   // membuat option kabupaten untuk masing-masing propinsi
//   $query2 = "SELECT id_kec, nama_kecamatan FROM kecamatan WHERE id_kab = $idProp";
//   $hasil2 = mysql_query($query2);
//   $content = "document.getElementById('kecamatan').innerHTML = \"";
//   while ($data2 = mysql_fetch_array($hasil2))
//   {
//       $content .= "<option value='".$data2['id_kec']."'>".$data2['nama_kecamatan']."</option>";
//   }
//   $content .= "\"";
//   echo $content;
//   echo "}\n";
// }
*/
 ?>
 }
</script>
-->
