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
 *  page.php
 *  
 *  Created on Sep 9, 2009, 5:27:45 AM
 */
//echo '<pre>'; print count($user); echo '</pre>';
/*
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
	   "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
*/
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html><head>

    <title><?php echo $configs->systitle; ?></title>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <!--link rel="stylesheet" type="text/css" href="/themes/<?php echo $theme;?>/css/default.css"-->
    <link rel="stylesheet" type="text/css" href="/themes/<?php echo $theme;?>/css/<?php if(isset($body_login)){echo 'login';} else {echo 'style';}?>.css">
    <link rel="stylesheet" type="text/css" href="/themes/<?php echo $theme;?>/css/tabcontent.css">
    <link href="main_files/column4.css" media="all" rel="stylesheet" type="text/css">

<script type="text/javascript" src="/themes/<?php echo $theme;?>/js/tabcontent.js">

/***********************************************
* Tab Content script v2.2- Â© Dynamic Drive DHTML code library (www.dynamicdrive.com)
* This notice MUST stay intact for legal use
* Visit Dynamic Drive at http://www.dynamicdrive.com/ for full source code
***********************************************/

</script>
</head>
<body<?php if (isset($body_login)){echo " onLoad=\"".$body_login. "\"";}?>>

<div id="container">

<?php if(!isset($body_login)){?>
<div id="header">
<a href="/regload"><IMG src="/themes/<?php echo $theme;?>/images/cardiac_logo.png" border="0" align="left"></a>
</div>
    <?php if(isset($managed_menus['primary_links'])){?>
    <div id=main-nav>
        <?php foreach ($managed_menus['primary_links'] as $key=>$value){ ?>
            <?php if($key > 0){?>|<?php }?> &nbsp; <a href="<?php echo $value['path'];?>"><?php echo ucwords($value['title']); ?></a>
        <?php }?>
    </div>
    <?php }?>
<?php }?>

    <div id="<?php if(!isset($body_login)){ echo 'main-content';} else { echo 'main-container';}?>">
    <?php if(!isset($body_login)){?>
        <div id="left<?php if(!isset($body_login)){echo '-container';}?>">
            <div id="picture"><a href="/"><IMG SRC="/themes/<?php echo $theme;?>/images/default_user.png" border="0" height="160" width="160" alt="theme logo"></a></div>
            <div id="left">
                <dl>
                <?php if(isset($managed_menus['navigations'])){?>
                    <?php foreach($managed_menus['navigations'] as $key => $value){?>
                        <?php if(!is_null($value['parent'])){?>
                            <?php
                            $exp_vpath = explode('/', preg_replace('/^\//','',$value['path']));
//                            echo '<pre>'; print_r($value); echo '</pre>';
                            ?>
                            <?php if($exp_vpath[0] == $path['main']){?>
                                <dt><a href="<?php echo $value['path']; ?>"<?php if (is_null($value['parent'])){?> style="font-weight:bold"<?php }?>><?php echo !is_null($value['parent']) ? ucwords($value['title']) : strtoupper($value['title']);?></a></dt>
                            <?php unset($exp_vpath);}?>
                        <?php } else {?>
                            <p class="title"><a href="<?php echo $value['path']; ?>"<?php if (is_null($value['parent'])){?> style="font-weight:bold;color:white;padding-left:3px"<?php }?>><?php echo !is_null($value['parent']) ? ucwords($value['title']) : strtoupper($value['title']);?></a></p>
                        <?php }?>
                    <?php }?>
                <?php }?>
                </dl>
            </div>
        </div>
    <?php }?>

<?php require_once THEMES_DIR . DS . $theme . DS . 'content.tpl.php';?>

    <?php if(!isset($body_login)){?>
        <div id="right">
            <dl>
                <dt></dt>
            </dl>
        </div>
    <?php }?>
    </div>
</div>

    <div id="<?php if (!isset($body_login)){echo 'message-';}?>footer"><?php echo $configs->identity_message;?></div>

<?php if(!isset($body_login)){?>
<div id="footer">
</div>
<?php }?>

</body>
</html>
