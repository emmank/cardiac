{*
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
 *  head.tpl
 *  
 *  Created on Sep 6, 2009, 10:10:16 AM
 *}

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
	   "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
    <title>{$configs->systitle}</title>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <!--link rel="stylesheet" type="text/css" href="/themes/default/css/default.css"-->
    <link rel="stylesheet" type="text/css" href="/themes/default/css/{ if isset($body_login))}login{else}style{/if}.css">
    {if (!isset($body_login)}
        {*literal}
        <script type="text/JavaScript" src="/themes/default/js/curvycorners.src.js"></script>

        <script type="text/JavaScript">

          addEvent(window, 'load', initCorners);

          function initCorners() {
            var settings = {
              tl: { radius: 5 },
              tr: { radius: 5 },
              bl: { radius: 5 },
              br: { radius: 5 },
              antiAlias: true
            }

            /*
            Usage:

            curvyCorners(settingsObj, selectorStr);
            curvyCorners(settingsObj, Obj1[, Obj2[, Obj3[, . . . [, ObjN]]]]);

            selectorStr ::= complexSelector [, complexSelector]...
            complexSelector ::= singleSelector[ singleSelector]
            singleSelector ::= idType | classType
            idType ::= #id
            classType ::= [tagName].className
            tagName ::= div|p|form|blockquote|frameset // others may work
            className : .name
            selector examples:
              #mydiv p.rounded
              #mypara
              .rounded
            */
            curvyCorners(settings, "#content-title");
          }

        </script>
        {/literal*}
    {/if}
</head>
<body{if isset($body_login)} onLoad="{$body_login}"{/if}>