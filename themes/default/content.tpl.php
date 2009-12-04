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
 *  content.tpl.php
 *  
 *  Created on Sep 6, 2009, 11:03:48 AM
 */
//echo '<div align="left"><pre>'; print_r($content['output']['form']['0']['user']); echo '</pre></div>';

?>
<div id="header-info">
<?php 
//echo "<pre>";
//print_r($content);
//echo "</pre>";
if ($menu_info['id'] != "login") {
    echo '<div class="title">'. ucwords($menu_info['title']).'</div>'. ucfirst ($menu_info['description']);
}
?>
</div>
<div id="main-<?php if(isset($body_login)){?>content<?php } else {?>info<?php }?>">
<?php if (isset($body_login)){?>
		<div id=content-left>
			<a href="/"><IMG src="/themes/<?php echo $theme;?>/images/main_image.png" width="480" height="181" align="left" border="0"></a>
		</div>
<?php } else {?>
    <!--div id=content-title>Cardiac Center</div-->
<?php }?>

<?php if(isset($content['output']['form'])){?>

    <?php foreach($content['output']['form'] as $key => $value){?>
        <?php foreach($value as $ke => $val){
            $formtype = $val['#type'];
            $formname = $ke;
            if($formtype == 'module'){
                $tplform = $val['#formtpl'];
            }
            break;
        }?>
        
        <?php if($formname == 'login'){?> <div id="login-form"><?php }?>

        <?php if($formtype == 'special'){?>
            <?php
            echo __create_form_special($value);
            ?>
        <?php } elseif($formtype == 'module') {?>
            <?php //echo "pret";
            echo __create_form($value);
            ?>
            <?php
            require_once $tplform; unset($tplform);
            ?>
        <?php } else {?>
            <?php echo __create_form($value);?>
        <?php }?>
        <?php if ($formname == "login") {?>
        </div>
        <?php }?>

        <?php unset($formname, $formtype);?>
        
    <?php }?>
<?php } else { ?>
    <?php
        /*
         * cek $content['output'] punya key, jika ada, set display berdasarkan key.
         * jika tidak buatkan default display
         */
        if (count ($content['output']) > 0) {;
    ?>
    <?php foreach($content['output'] as $value){?>
    <?php
//    echo "<pre>";
//    print_r ($content['output']);
//    echo "</pre>";
    ?>
            <?php if ($value['type'] == 'table'){?>
                <?php echo __create_table($value);?>
            <?php } elseif($value['type'] == 'items_detail') {?>
                <?php echo __create_items_detail($value);?>
            <?php } elseif($value['type'] == 'info') {?>
                <?php echo __create_info($value);?>
            <?php } elseif($value['type'] == 'search') {?>
                <?php echo __create_search($value);?>
            <?php } elseif($value['type'] == 'notelist') {?>
                <?php echo __create_notelist($value);?>
            <?php }?>
        <?php }?>
    <?php } else {?>
        <?php echo __create_main_image(); ?>
    <?php } ?>
<?php }?>


</div>