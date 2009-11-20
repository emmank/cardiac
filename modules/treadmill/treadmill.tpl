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
 *  cardio.php
 *  
 *  Created on Oct 26, 2009, 5:28:48 AM
 */




//echo '<pre>'; print_r($data); echo '</pre>';
foreach($data as $key => $value){
//    if(isset($value['#error']) && $value['#error'] !== FALSE){
//        $result .= '<div class="error">' . $value['#error'] . '</div><br /><br />' . "\n";
//    }
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
    //echo '<pre>'; print_r($gettbpos); echo '</pre>';
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
    if(isset($value['tab_items']) && count($value['tab_items']) > 0){
        $result .= '<ul id="fisistabs" class="shadetabs">' . "\n";
        $ke = 1;
        foreach($value['tab_items'] as $ky => $vl){
            $result .= '<li><a href="#" rel="fisis' . $ke . '">' . $vl['#title'] . '</a></li>' . "\n";
            $ke++;
        } unset($ke);
        $result .= '</ul>' . "\n";
        $result .= '<div style="border:1px solid gray; width:725px; margin-bottom: 1em; padding: 10px">' . "\n";
        $ke = 1;
        foreach($value['tab_items'] as $ky => $vl){
            if(isset($vl['#tpl'])){
                require_once $vl['#tpl'];
                $ke++;
            }
        } unset($ke);
        $result .= '</div>' . "\n";
    }

    $result .= treadmill_form_tpl();

    if(isset($value['submit'])){
        $result .= '<div>' . "\n";
        $result .= '<input type="submit" value="' . $value['submit']['#value'] . '"' . (isset($value['submit']['#extra']) ? ' ' . $value['submit']['#extra'] : '') . '>';
        $result .= '</div>' . "\n";
    }
    $result .= __create_form_close();
    $result .= '<script type="text/javascript">' . "\n";
    $result .= 'var tabs=new ddtabcontent("fisistabs")' . "\n";
    $result .= 'tabs.setpersist(true)' . "\n";
    $result .= 'tabs.setselectedClassTarget("link") //"link" or "linkparent"' . "\n";
    $result .= 'tabs.init()' . "\n";
    $result .= '</script>' . "\n";
}


function treadmill_form_tpl() {
$result .=<<< treadmill
<form>
<ul id="treadmilltabs" class="shadetabs">
<li><a href="#" rel="treadmill1" class="selected">Fase Istirahat,Latihan &amp;Recovery </a></li>
<li><a href="#" rel="treadmill2">Kesimpulan &amp; Saran</a></li>
<li><a href="#" rel="treadmill3">Anjuran</a></li>
</ul>

<div style="border:1px solid gray; width:725px; margin-bottom: 1em; padding: 10px">

<div id="treadmill1" class="tabcontent">
<!--<fieldset>
<legend>Fase Istirahat</legend>-->
<strong>Fase Istirahat</strong>
<table width=100% class="table">
<TR  bgcolor=#f2f2f2><TD></TD><td>Berbaring</td><td>Berdiri</td><td>Hiperventilasi</td></TR>

	<TR>
		<TD>A. Tensi</TD>
		<td><input type="text" size=4> / <input type="text" size=4>mmHg</td>
		<td><input type="text" size=4> / <input type="text" size=4>mmHg</td>
		<td><input type="text" size=4> / <input type="text" size=4>mmHg</td>
	</TR>

	<TR>
		<TD>B. Denyut Jantung</TD><td><input type="text" size=8 /></td>
		<td><input type="text" size=8 ></td>
		<td><input type="text" size=8 ></td>
	</TR>

	<TR>
		<TD>C. E K G</TD><td><input type="text" size=8 /></td>
		<td><input type="text" size=8 ></td>
		<td><input type="text" size=8 ></td>
	</TR>
</table>
<!--</fieldset>-->


<strong>Fase Latihan</strong><br>
<table width=100% class="table" border="0">
	<TR>
		<TD colspan="5"><strong>A. Protokol</strong></TD>
	</TR>
	<TR>
		<TD width="25"></TD>
		<TD width="200"></TD>
        <td colspan="2"><select><option>Bruce</option></select>stage</td>
		<td>lamanya<input type="text" size=4> menit</td>
	</TR>
	<TR>
		<TD colspan="2"><strong>B. Rekaman EKG</strong></TD>
		<td colspan="3"><input type="text" /></td>
	</TR>
	<tr>
		<TD></TD>
		<TD>1. Rekaman ST</TD>
		<TD>Depresi</TD>
		<TD> <input type="text" size="4" />mm</TD>
		<TD>Pada menit ke <input type="text" size="4" /></TD>
	</tr>
	<tr>
		<TD></TD>
		<TD></TD>
		<TD>Elevasi </TD>
		<TD><input type="text" size="4" />mm</TD>
		<TD>Pada menit ke <input type="text" size="4" /></TD>
	</tr>
	<tr>
		<TD></TD>
		<TD></TD>
		<TD>Konfigurasi</TD>
		<TD> <select></select></TD>
		<TD></TD>
	</tr>
	<tr>
		<TD></TD>
		<TD>2. Aritmia Berupa</TD>
		<TD colspan="2"><input type="text" /></TD>
		<TD>Pada menit ke <input type="text" size="4" /></TD>
	</tr>

	<tr>
		<TD></TD>
		<TD>3. Perubahan Gelombang R</TD>
		<TD colspan="2">
			<select>
				<option>Menetap</option>
				<option>Meninggi</option>
				<option>Menurun</option>
			</select>
		</TD>
		<TD></TD>
	</tr>

	<tr>
		<TD></TD>
		<TD>4. Lain - lain</TD>
		<TD colspan="3"><input type="text" /></TD>
	</tr>


	<TR>
		<TD colspan="2" valign="top"><strong>C. Dihentikan Karena</strong></TD>
		<TD colspan="2">
			<input type="radio">Nyeri Dada<br>
			<input type="radio">Kecapean<br>
			<input type="radio">THR Tercapai<br>
		</td>
		<td>
			<input type="radio">Aritmia<br>
			<input type="radio">Dyspnoe<br>
			<input type="radio">Lain - lain (pusing)

		</TD>
	</TR>
	<TR>
		<TD colspan="4"><strong>D. Perubahan Hermodinamik</strong></TD>
	</TR>
	<tr>
		<TD></TD>
		<TD>1. Denyut Jantung</TD>
		<TD>Respons</TD>
		<TD colspan="2">
			<select>
				<option>Kurang</option>
				<option>Tidak mencapai 129 x/ menit wlp ULJB cukup</option>
			</select>
		</TD>
		<TD></TD>
	</tr>
	<tr>
		<TD></TD>
		<TD></TD>
		<TD colspan="2">Puncak Denyut Jantung</TD>
		<TD><input type="text" size="5" />
		</TD>
		<TD></TD>
	</tr>
	<tr>
		<TD></TD>
		<TD></TD>
		<TD colspan="2">Lain - lain</TD>
		<TD><input type="text"  size="5" />
		</TD>
		<TD></TD>
	</tr>
	<tr>
		<TD></TD>
		<TD>2. Tekanan Darah</TD>
		<TD>Respons</TD>
		<TD colspan="2">
			<select>
				<option>Kurang</option>
				<option>Tidak mencapai 140 mmHg</option>
			</select>
		</TD>
		<TD></TD>
	</tr>
	<tr>
		<TD></TD>
		<td></td>
		<TD>Respon hgipertensi</TD>
		<TD>Sistolik</TD>
		<TD><input type="text" size="5" /> mmHg
		</TD>
		<TD></TD>
	</tr>
	<tr>
		<TD></TD>
		<td></td>
		<TD></TD>
		<TD>Diastolik</TD>
		<TD><input type="text" size="5" /> mmHg
		</TD>
		<TD></TD>
	</tr>
	<tr>
		<TD></TD>
		<td></td>
		<TD>Respon hipertensip</TD>
		<TD>Sistolik</TD>
		<TD><input type="text" size="5" /> mmHg
		</TD>
		<TD></TD>
	</tr>
	<tr>
		<TD></TD>
		<td></td>
		<TD></TD>
		<TD>Diastolik</TD>
		<TD><input type="text" size="5" /> mmHg
		</TD>
		<TD></TD>
	</tr>
	<tr>
		<TD></TD>
		<td></td>
		<TD>Respon Menetap</TD>
		<TD colspan="2"><input type="text" size="5" /> mmHg
		</TD>
		<TD></TD>
	</tr>
	<tr>
		<TD></TD>
		<td></td>
		<TD colspan="2">Tekanan darah puncak latihan</TD>
		<TD><input type="text" size="5" /> mmHg
		</TD>
		<TD></TD>
	</tr>
</table>

<strong>Fase Recovery</strong>
<table width="100%" class="table">
	<TR>
		<TD>Segment ST</TD>
		<td>Depresi</td>
		<td><input type="text" size="5"> mm</td>
	</TR>
	<TR>
		<TD></TD>
		<td>Elevasi</td>
		<td><input type="text" size="5"> mm</td>
	</TR>
	<TR>
		<TD>Aritmia Berupa</TD>
		<td colspan="2"><input type="text"></td>
	</TR>
	<TR>
		<TD>Lain - lain</TD>
		<td colspan="2"><input type="text"></td>
	</TR>
</table>

</div>

<div id="treadmill2" class="tabcontent">

<table>
  <tbody>
    <tr>
      <td>ULIB dengan treadmill terhadap penyakit jantung koroner</td>
      <td>
<select>
	<option>Positif</option>
	<option>Negatif</option>
	<option>Meragukan</option>
	<option>Tidak dapat di interpretasi</option>
</select>
	</td>
    </tr>
    <tr>
      <td>Respon tekanan Darah</td>
      <td><input type="text">
	  </td>
    </tr>
    <tr>
      <td>Tingkat Kesegaran Jasmani</td>
      <td><select>
	<option>Rendah</option>
	<option>Kurang</option>
	<option>Rata - rata</option>
	<option>Baik</option>
    <option>Baik Sekali</option>
</select></td>
    </tr>
    <tr>
      <td>Klasifikasi Fungsional</td>
      <td><select>
	<option>I (Normal)</option>
	<option>II</option>
	<option>III</option>
</select></td>
    </tr>
    <tr>
      <td>Kapasitas Aerobik</td>
      <td><input type=text> Metz</td>
    </tr>
    <tr>
      <td>Lain - lain</td>
      <td><input type=text></td>
    </tr>
  </tbody>
</table>

</div>

<div id="treadmill3" class="tabcontent">
<strong>Anjuran</strong>

<table class="table" width="100%">
  <tbody>
    <tr>
      <td colspan="3">1. Olahraga</td>
    </tr>
    <tr>
      <td width="25"></td>
      <td>Jalan Kaki / Jogging</td>
      <td><input type="text"> km / 30 menit</td>
    </tr>
    <tr>
      <td></td>
      <td>Lari</td>
      <td><input type="text"> km / 30 menit</td>
    </tr>
    <tr>
      <td></td>
      <td>Bersepeda</td>
      <td><input type="text"> km / 30 menit</td>
    </tr>
    <tr>
      <td></td>
      <td>Dengan Frekuensi</td>
      <td><input type="text" size="30"> x / minggu</td>
    </tr>
    <tr>
      <td></td>
      <td>Nadi Latihan</td>
      <td><input type="text" size="30"> x / minggu</td>
    </tr>


    <tr>
      <td colspan="2">2. Obat - obatan</td>
      <td><textarea cols="30" rows="3"></textarea> </td>
    </tr>

    <tr>
      <td colspan="2">3. Usul</td>
      <td></td>
    </tr>

    <tr>
      <td></td>
      <td>a. Pemeriksaan Lanjut</td>
      <td><input type="text"></td>
    </tr>

    <tr>
      <td></td>
      <td>b. Konsultasi dengan</td>
      <td><input type="text"></td>
    </tr>

    <tr>
      <td></td>
      <td>c. ULIB dengan treadmill diulang setelah</td>
      <td><input type="text"> bulan / tahun</td>
    </tr>

    <tr>
      <td></td>
      <td>d. Lain - lain</td>
      <td><input type="text"></td>
    </tr>

  </tbody>
</table>

</div>

</div>

<script type="text/javascript">

var tabs=new ddtabcontent("treadmilltabs")
tabs.setpersist(true)
tabs.setselectedClassTarget("link") //"link" or "linkparent"
tabs.init()

</script>

</form>
treadmill;

return $result;
}