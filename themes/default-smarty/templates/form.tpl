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
 *  form.tpl
 *  
 *  Created on Sep 6, 2009, 10:15:17 AM
 *}


{foreach from=$form item=value key=key}
<div id="{if isset($body_login)}login-form{else}form{/if}">
<!--fieldset value="{$value.title}"-->
    <form name="{$key}" action="{$value.action}" method="POST">
    {if isset($value.message) && count($value.message) > 0}
        {foreach from=$value.message item=vl key=ky}
            {if $ky<1}
                {if isset($body_login)}<font class="login-title">{/if}{$vl}{if isset($body_login)}</font>{/if}
            {else}
                {$vl}
            {/if}
            <br />
        {/foreach}
        <br />
    {/if}
    {foreach from=$value item=vl key=ky}
        {if !in_array($ky, $itemselement)}
           {if isset($vl.title)}<label for="{$ky}"{if isset($vl.error) && $vl.error==1} id="error"{/if}>{$vl.title|capitalize:true}</label>{/if}
           {if $vl.type == "textfield" || $vl.type == "password" || $vl.type == "input"}
               <input type="{$vl.type}" name="{$ky}" id="userpass" size="{$vl.size}" value="{if isset($vl.value)}{$vl.value}{/if}" />
           {elseif $vl.type == "textarea"}
               <textarea cols="{$vl.cols}" rows="{$vl.rows}" name="{$ky}">{if isset($vl.value)}{$vl.value}{/if}</textarea>
           {elseif $vl.type == "submit"}
               <input type="submit" value="{if isset($vl.value)}{$vl.value|capitalize:true}{/if}" class="button" />
           {/if}
           <br />
        {/if}
    {/foreach}
    </form>
<!--/fieldset-->
</div>
{if isset($value.error)}
<div style="clear:both"><font id="error_message">{$value.error}</font></div>
{/if}
{/foreach}