<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<?php
$con=mysql_connect("localhost","root","emmank");
if (!$con) {
	die('Disconnected : '.mysql_error());
}
mysql_select_db("cardiac",$con) or die(mysql_error());
?>
<html>
  <head>
  <title>Pedaftaran Pasien</title>
  <meta name="GENERATOR" content="Quanta Plus">
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8"><script type="text/javascript">

/***********************************************
* Disable "Enter" key in Form script- By Nurul Fadilah(nurul@REMOVETHISvolmedia.com)
* This notice must stay intact for use
* Visit http://www.dynamicdrive.com/ for full source code
***********************************************/
                
function handleEnter (field, event) {
		var keyCode = event.keyCode ? event.keyCode : event.which ? event.which : event.charCode;
		if (keyCode == 13) {
			var i;
			for (i = 0; i < field.form.elements.length; i++)
				if (field == field.form.elements[i])
					break;
			i = (i + 1) % field.form.elements.length;
			field.form.elements[i].focus();
			return false;
		} 
		else
		return true;
	}      

</script><script language="JavaScript" type="text/JavaScript">
 function showKab()
 {
 <?php
 
 // membaca semua propinsi
 $query = "SELECT kode_bps, nama_propinsi FROM propinsi";
 $hasil = mysql_query($query);
 
 // membuat if untuk masing-masing pilihan propinsi beserta isi option untuk combobox kedua
 while ($data = mysql_fetch_array($hasil))
 {
   $idProp = $data['kode_bps'];
 
   // membuat IF untuk masing-masing propinsi
   echo "if (document.daftar.propinsi.value == \"".$idProp."\")";
   echo "{";
 
   // membuat option kabupaten untuk masing-masing propinsi
   $query2 = "SELECT id_kab, kabupaten FROM kabupaten WHERE kode_bps = $idProp";
   $hasil2 = mysql_query($query2);
   $content = "document.getElementById('kabupaten').innerHTML = \"";
   while ($data2 = mysql_fetch_array($hasil2))
   {
       $content .= "<option value='".$data2['id_kab']."'>".$data2['kabupaten']."</option>";   
   }
   $content .= "\"";
   echo $content;
   echo "}\n";   
 }
 
 ?> 
 }
</script><script language="JavaScript" type="text/JavaScript">
 function showKec()
 {
 <?php
 
 // membaca semua kabupaten
 $query = "SELECT id_kab, kabupaten FROM kabupaten";
 $hasil = mysql_query($query);
 
 // membuat if untuk masing-masing pilihan kabupaten beserta isi option untuk combobox kedua
 while ($data = mysql_fetch_array($hasil))
 {
   $idProp = $data['id_kab'];
 
   // membuat IF untuk masing-masing kabupaten
   echo "if (document.daftar.kab.value == \"".$idProp."\")";
   echo "{";
 
   // membuat option kabupaten untuk masing-masing propinsi
   $query2 = "SELECT nama_kecamatan FROM kecamatan WHERE id_kab = $idProp";
   $hasil2 = mysql_query($query2);
   $content = "document.getElementById('kecamatan').innerHTML = \"";
   while ($data2 = mysql_fetch_array($hasil2))
   {
       $content .= "<option value='".$data2['nama_kecamatan']."'>".$data2['nama_kecamatan']."</option>";   
   }
   $content .= "\"";
   echo $content;
   echo "}\n";   
 }
 
 ?> 
 }
</script></head>
<?php
if (!isset($_POST['submit'])) {

	$sql_antrian="SELECT no_antrian,tgl_periksa,nama_pasien,t4_lahir,tgl_lahir,jns_kelamin,gol_darah,status,nama_suami_istri,pekerjaan_suami_istri,alamat, pekerjaan, pendidikan, propinsi, kabupaten_kodya, kecamatan, desa,kode_pos, no_tlp, agama, suku, no_ktp, nama_ayah, pekerjaan_ayah, nama_ibu, pekerjaan_ibu FROM temp_pasien where proses='0' order by no_antrian ASC LIMIT 1";
	$hasil = mysql_query($sql_antrian,$con) or die(mysql_error());
// 	$count = mysql_num_rows($hasil);
	$data=mysql_fetch_array($hasil);



?>

<BODY style="font:13px/1.22 arial,helvetica,clean,sans-serif;*font-size:small;*font:x-small;">
Tanggal : <?php echo date("d/M/Y");?><p></p>

    <FORM name="daftar" method="POST" action="<?php echo $PHP_SELF;?>">
		<TABLE border="0" width="100%" cellspacing="6">
		<TR>
			<TD width="30%" align="right">
				Nama Pasien 
			</TD>
			<TD>
				<INPUT type="text" name="nama_pasien" maxlength="40" size="30" value="<?php echo $data['nama_pasien']?>" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Tempat Lahir 
			</TD>
			<TD>
				<INPUT type="text" name="t4_lahir" maxlength="20" value="<?php echo $data['t4_lahir']?>" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Tanggal Lahir
			</TD>
			<TD>
				<INPUT type="text" name="t4_lahir" maxlength="20" value="<?php echo $data['tgl_lahir']?>" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Jenis Kelamin
			</TD>
			<TD>
				<INPUT type="text" name="jns_kelamin" size="2" maxlength="2" value="<?php echo $data['jns_kelamin']?>" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Golongan Darah
			</TD>
			<TD>
				<INPUT type="text" name="gol_darah" size="2" value="<?php echo $data['gol_darah']?>" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Status Pernikahan
			</TD>
			<TD>
				<INPUT type="text" name="status" maxlength="20" value="<?php echo $data['status']?>" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Nama Suami/Istri
			</TD>
			<TD>
				<INPUT type="text" name="nama_suami_istri" maxlength="35" value="<?php echo $data['nama_suami_istri']?>" onkeypress="return handleEnter(this, event)">
				Pekerjaan <INPUT type="text" name="pekerjaan_suami_istri" maxlength="35" value="<?php echo $data['pekerjaan_suami_istri']?>" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Alamat
			</TD>
			<TD>
				<INPUT type="text" name="alamat" maxlength="35" value="<?php echo $data['alamat']?>" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Pekerjaan
			</TD>
			<TD>
				<INPUT type="text" name="pekerjaan" maxlength="35" value="<?php echo $data['pekerjaan']?>" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Pendidikan
			</TD>
			<TD>
				<INPUT type="text" name="pendidikan" maxlength="35" value="<?php echo $data['pendidikan']?>" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Propinsi
			</TD>
			<TD>
				
				<?php
					$kd_bps = $data['propinsi'];
					$query2 = "SELECT kode_bps,nama_propinsi FROM propinsi where kode_bps = $kd_bps ";
                 	$hasil2 = mysql_query($query2);
					$data2 = mysql_fetch_array($hasil2);
                 	//{
//                     	echo "<option value='".$data['kode_bps']."'>".$data['nama_propinsi']."</option>";
                 	//}
                 	//$data2 = mysql_fetch_array($hasil2);
//                  	echo "<option value='".$data['kode_bps']."'>".$data['nama_propinsi']."</option>";
				?>
				<INPUT type="text" name="propinsi" maxlength="35" value="<?php echo $data2['nama_propinsi'] ?>" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Kabupaten/Kodya
			</TD>
			<TD>
				
				<?php
					$id_kab = $data['kabupaten_kodya'];
					$query2 = "SELECT id_kab, kabupaten FROM kabupaten WHERE id_kab = $id_kab ";
                 	$hasil2 = mysql_query($query2);
					$data2 = mysql_fetch_array($hasil2);
                 	//{
//                     	echo "<option value='".$data['kode_bps']."'>".$data['nama_propinsi']."</option>";
                 	//}
                 	//$data2 = mysql_fetch_array($hasil2);
//                  	echo "<option value='".$data['kode_bps']."'>".$data['nama_propinsi']."</option>";
				?>
				<INPUT type="text" name="kabupaten" maxlength="35" value="<?php echo $data2['kabupaten'] ?>" onkeypress="return handleEnter(this, event)">

			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
            Kecamatan
          </TD>
			<TD>
				<?php
					$id_kec = (int) $data['kecamatan'];
					$query2 = "SELECT id_kec, nama_kecamatan FROM kecamatan WHERE id_kec = $id_kec ";
                 	$hasil2 = mysql_query($query2);
					$data2 = mysql_fetch_array($hasil2);
                 	//{
//                     	echo "<option value='".$data['kode_bps']."'>".$data['nama_propinsi']."</option>";
                 	//}
                 	//$data2 = mysql_fetch_array($hasil2);
//                  	echo "<option value='".$data['kode_bps']."'>".$data['nama_propinsi']."</option>";
				?>
				<INPUT type="text" name="kecamatan" maxlength="35" value="<?php echo $data2['nama_kecamatan'] ?>" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Desa
			</TD>
			<TD>
				<INPUT type="text" name="desa" maxlength="30" value="<?php echo $data['desa'] ?>" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Kode Pos
			</TD>
			<TD>
				<INPUT type="text" name="kode_pos" maxlength="6" value="<?php echo $data['kode_pos'] ?>" size="8" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Nomor Tlp / HP
			</TD>
			<TD>
				<INPUT type="text" name="no_tlp" maxlength="35" size="30" value="<?php echo $data['no_tlp'] ?>" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Agama
			</TD>
			<TD>
				<INPUT type="text" name="agama" maxlength="35" size="30" value="<?php echo $data['agama'] ?>" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>

		<TR>
			<TD width="30%" align="right">
				Suku
			</TD>
			<TD>
				<INPUT type="text" name="suku" maxlength="15" value="<?php echo $data['suku'] ?>" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				No. KTP
			</TD>
			<TD>
				<INPUT type="text" name="no_ktp" maxlength="20" value="<?php echo $data['no_ktp'] ?>" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Nama Ayah
			</TD>
			<TD>
				<INPUT type="text" name="nama_ayah" maxlength="35" value="<?php echo $data['nama_ayah'] ?>" onkeypress="return handleEnter(this, event)">
				Pekerjaan <INPUT type="text" name="pekerjaan_ayah" maxlength="35" value="<?php echo $data['pekerjaan_ayah'] ?>" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Nama Ibu
			</TD>
			<TD>
				<INPUT type="text" name="nama_ibu" maxlength="35" value="<?php echo $data['nama_ibu'] ?>" onkeypress="return handleEnter(this, event)">
				Pekerjaan <INPUT type="text" name="pekerjaan_ibu" maxlength="35" value="<?php echo $data['pekerjaan_ibu'] ?>" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Cara Kunjungan
			</TD>
			<TD>
				<SELECT name="cara_kunjungan" onkeypress="return handleEnter(this, event)">
					<OPTION value="Konsul" Selected>Konsul</OPTION>
					<OPTION value="Dokter">Dokter</OPTION>
					<OPTION value="Puskesmas">Puskesmas</OPTION>
					<OPTION value="RS lain">RS. Lain</OPTION>
					<OPTION value="Instansi lain">Instansi lain</OPTION>
					<OPTION value="Kasus Polisi">Kasus Polisi</OPTION>
					<OPTION value="Datang Sendiri">Datang Sendiri</OPTION>
				</SELECT>
				<INPUT type="text" name="cara_kunjungan1" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Konsul dari bagian
			</TD>
			<TD>
				<SELECT name="konsul" onkeypress="return handleEnter(this, event)">
					<OPTION value="">Silahkan Pilih</OPTION>
					<option value="">------------------------</option>
          		<?php
             // query untuk menampilkan
                 $query = "SELECT id_konsul,nama_konsul FROM konsul";
                 $hasil = mysql_query($query);
                 while ($data = mysql_fetch_array($hasil))
                 {
                    echo "<OPTION value='".$data['id_konsul']."'>".$data['nama_konsul']."</OPTION>";
                 }
          		?>
				</SELECT> oleh <INPUT type="text" name="konsul_oleh" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Bagian yang dituju
			</TD>
			<TD>
				<SELECT name="id_bagian" onkeypress="return handleEnter(this, event)">
					<OPTION value="">Silahkan Pilih</OPTION>
					<option value="">------------------------</option>
          		<?php
             // query untuk menampilkan propinsi
                 $query = "SELECT id_bagian, nama_singkat FROM bagian";
                 $hasil = mysql_query($query);
                 while ($data = mysql_fetch_array($hasil))
                 {
                    echo "<OPTION value='".$data['id_bagian']."'>".$data['nama_singkat']."</OPTION>";
                 }
          		?>
				</SELECT>
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Ditangani Oleh
			</TD>
			<TD>
				<SELECT name="id_dokter" onkeypress="return handleEnter(this, event)">
					<OPTION value="">Silahkan Pilih</OPTION>
					<option value="">------------------------</option>
          		<?php
             // query untuk menampilkan propinsi
                 $query = "SELECT id_dokter, nama_dokter, gelar FROM dokter";
                 $hasil = mysql_query($query);
                 while ($data = mysql_fetch_array($hasil))
                 {
                    echo "<OPTION value='".$data['id_dokter']."'>".$data['nama_dokter'].",".$data['gelar']."</OPTION>";
                 }
          		?>
				</SELECT>
			</TD>
		</TR>
		<TR>
			<TD width="30%" align="right">
				Cara Bayar
			</TD>
			<TD>
				<SELECT name="id_asuransi" onkeypress="return handleEnter(this, event)">
				<?php
             // query untuk menampilkan propinsi
                 $query = "SELECT id_asuransi,nama_singkat FROM asuransi";
                 $hasil = mysql_query($query);
                 while ($data = mysql_fetch_array($hasil))
                 {
                    echo "<OPTION value='".$data['id_asuransi']."'>".$data['nama_singkat']."</OPTION>";
                 }
          		?>
				</SELECT>
				No. Asuransi <INPUT type="text" name="no_asuransi" size="8" onkeypress="return handleEnter(this, event)">
			</TD>
		</TR>
		<TR><TD><p></p></TD></TR>
		<TR>
			<TD align="center">
				<INPUT type="submit" name="submit" value="Simpan" style='margin:1em;height:2.5em;background:#222;float:right;color:#fff'>	
			</TD>
			<TD align="center">
				<INPUT type="reset" value="Reset" style='margin:1em;height:2.5em;background:#222;color:#fff'>
			</TD>
		</TR>
		</TABLE>
    </FORM>
<?php
}//dari isset
else {
	
	//echo "submit form";
	$tgl_registrasi=date("Y/m/d");
	$nama_pasien=$_POST["nama_pasien"];
	$t4_lahir=$_POST["t4_lahir"];
	$tgl_lahir=$_POST["tgl_lahir3"]."-".$_POST["tgl_lahir2"]."-".$_POST["tgl_lahir1"];
	$jns_kelamin=$_POST["jns_kelamin"];
	$gol_darah=$_POST["gol_darah"];
	$status=$_POST["status"];
	$nama_suami_istri=$_POST["nama_suami_istri"];
	$pekerjaan_suami_istri=$_POST["pekerjaan_suami_istri"];
	$alamat=$_POST["alamat"];
	$pekerjaan=$_POST["pekerjaan"];
	$pendidikan=$_POST["pendidikan"];
	$propinsi=$_POST["propinsi"];
	$kab=$_POST["kabupaten"];
	$kec=mysql_escape_string($_POST["kecamatan"]);
	$desa=$_POST["desa"];
	$kode_pos=$_POST["kode_pos"];
	$no_tlp=$_POST["no_tlp"];
	$agama=$_POST["agama"];
	$suku=$_POST["suku"];
	$no_ktp=$_POST["no_ktp"];
	$nama_ayah=$_POST["nama_ayah"];
	$pekerjaan_ayah=$_POST["pekerjaan_ayah"];
	$nama_ibu=$_POST["nama_ibu"];
	$pekerjaan_ibu=$_POST["pekerjaan_ibu"];

	$cara_kunjungan=$_POST["cara_kunjungan"];
	$desc_kunjungan=$_POST["cara_kunjungan1"];
	$konsul=$_POST["konsul"];
	$konsul_oleh=$_POST["konsul_oleh"];
	$bagian_dituju=$_POST["id_bagian"];
	$ditangani_oleh=$_POST["id_dokter"];
	$id_asuransi=$_POST["id_asuransi"];
	$no_asuransi=$_POST["no_asuransi"];

// 	Mengambil no atrian yang terbesar
	$query_id_pasien="select max(id_pasien) as id_pasien from pasien";
	$hasil = mysql_query($query_id_pasien);
	$data= mysql_fetch_array($hasil) or die(mysql_error());
// 	echo "id pasien sebelum dijumlah ".$data['id_pasien'];
	//echo $kode_pasien;
	if (is_null($data)) {
		$id_pasien="1";
	}else {
		$id_pasien=(int) $data['id_pasien']+1;
// 		$id_pasien=(str) $id;
	}

// 	echo "id pasien setelah dijumlah: ".$id_pasien;
	$insert_pasien="INSERT INTO pasien(id_pasien,tgl_registrasi,nama_pasien,t4_lahir,tgl_lahir,jns_kelamin,gol_darah,status,nama_suami_istri,pekerjaan_suami_istri,alamat, pekerjaan, pendidikan, propinsi, kabupaten_kodya, kecamatan, desa,kode_pos, no_tlp, agama, suku, no_ktp, nama_ayah, pekerjaan_ayah, nama_ibu, pekerjaan_ibu) VALUES ('$id_pasien','$tgl_registrasi','$nama_pasien','$t4_lahir','$tgl_lahir','$jns_kelamin','$gol_darah','$status','$nama_suami_istri','$pekerjaan_suami_istri','$alamat','$pekerjaan','$pendidikan','$propinsi','$kab','$kec','$desa','$kode_pos','$no_tlp','$agama','$suku','$no_ktp','$nama_ayah','$pekerjaan_ayah','$nama_ibu','$pekerjaan_ibu')";

// 	$query_jml_kunjungan="select max(jml_kunjungan) as jml_kunjungan from pasien where id_pasien=$id_pasien";
// 	$hasil = mysql_query($query_jml_kunjungan);
// 	$data= mysql_fetch_array($hasil) or die(mysql_error());
	//echo $kode_pasien;
	$jml_kunjungan=0;
// 	echo "jumlah kunjungan : ".$jml_kunjungan;
	$tgl_periksa=$tgl_registrasi;

	$insert_periksa="INSERT INTO periksa(id_pasien,id_periksa,tgl_periksa,id_bagian,cara_kunjungan,desc_kunjungan,id_konsul,konsul_oleh,ditangani_oleh,id_asuransi,no_asuransi,id_fisik,id_radiologi,id_echo,id_holter,id_treadmill,id_ekg) VALUES ('$id_pasien',$jml_kunjungan,'$tgl_periksa','$bagian_dituju','$cara_kunjungan','$desc_kunjungan','$konsul','$konsul_oleh','$ditangani_oleh','$id_asuransi','$no_asuransi','1','0','0','0','0','0') ";
// 	$insert_t_periksa="INSERT INTO t_periksa(tgl_periksa,kd_poli,kd_pasien,diagnosa,pemeriksaan,foto,kd_resep,kd_lab,kd_rad) VALUES ('$tgl_periksa','$kd_poli',$kd_pasien_conv,'','','','','','')";
// 	
// 	$insert_t_antrian="INSERT INTO t_antrian(kd_pasien,kd_poli,tgl_proses) VALUES ($kd_pasien_conv,'$kd_poli','$tgl_periksa')";
	$sql_antri="SELECT no_antrian FROM temp_pasien where proses='0' order by no_antrian ASC LIMIT 1";
	$hasil = mysql_query($sql_antri,$con) or die(mysql_error());
// 	$count = mysql_num_rows($hasil);
	$data=mysql_fetch_array($hasil);
	$no_antrian=(int) $data['no_antrian'];

	$update_temp_pasien="UPDATE temp_pasien SET proses = '1' WHERE no_antrian=$no_antrian LIMIT 1 ";
	$hasil = mysql_query($update_temp_pasien,$con) or die(mysql_error());
// 	$count = mysql_num_rows($hasil);
// 	$data=mysql_fetch_array($hasil);
	
	
	if (!mysql_query($insert_pasien,$con)) {
		die('Error: ' . mysql_error());
	}

	if (!mysql_query($insert_periksa,$con)) {
		die('Error: ' . mysql_error());
	}
	

	mysql_close($con);
?>
	<A href="main.php?page=antrian_registrasi&t=Antrian Registrasi" >Ke Daftar Antrian</A>
<?php
	}
?>
</BODY>
</html>