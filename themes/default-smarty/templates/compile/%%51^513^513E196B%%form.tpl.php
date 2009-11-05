<?php /* Smarty version 2.6.26, created on 2009-09-08 09:13:40
         compiled from form.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('modifier', 'capitalize', 'form.tpl', 42, false),)), $this); ?>


<?php $_from = $this->_tpl_vars['form']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['key'] => $this->_tpl_vars['value']):
?>
<div id="<?php if (isset ( $this->_tpl_vars['body_login'] )): ?>login-form<?php else: ?>form<?php endif; ?>">
<!--fieldset value="<?php echo $this->_tpl_vars['value']['title']; ?>
"-->
    <form name="<?php echo $this->_tpl_vars['key']; ?>
" action="<?php echo $this->_tpl_vars['value']['action']; ?>
" method="POST">
    <?php if (isset ( $this->_tpl_vars['value']['message'] ) && count ( $this->_tpl_vars['value']['message'] ) > 0): ?>
        <?php $_from = $this->_tpl_vars['value']['message']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['ky'] => $this->_tpl_vars['vl']):
?>
            <?php if ($this->_tpl_vars['ky'] < 1): ?>
                <?php if (isset ( $this->_tpl_vars['body_login'] )): ?><font class="login-title"><?php endif; ?><?php echo $this->_tpl_vars['vl']; ?>
<?php if (isset ( $this->_tpl_vars['body_login'] )): ?></font><?php endif; ?>
            <?php else: ?>
                <?php echo $this->_tpl_vars['vl']; ?>

            <?php endif; ?>
            <br />
        <?php endforeach; endif; unset($_from); ?>
        <br />
    <?php endif; ?>
    <?php $_from = $this->_tpl_vars['value']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['ky'] => $this->_tpl_vars['vl']):
?>
        <?php if (! in_array ( $this->_tpl_vars['ky'] , $this->_tpl_vars['itemselement'] )): ?>
           <?php if (isset ( $this->_tpl_vars['vl']['title'] )): ?><label for="<?php echo $this->_tpl_vars['ky']; ?>
"<?php if (isset ( $this->_tpl_vars['vl']['error'] ) && $this->_tpl_vars['vl']['error'] == 1): ?> id="error"<?php endif; ?>><?php echo ((is_array($_tmp=$this->_tpl_vars['vl']['title'])) ? $this->_run_mod_handler('capitalize', true, $_tmp, true) : smarty_modifier_capitalize($_tmp, true)); ?>
</label><?php endif; ?>
           <?php if ($this->_tpl_vars['vl']['type'] == 'textfield' || $this->_tpl_vars['vl']['type'] == 'password' || $this->_tpl_vars['vl']['type'] == 'input'): ?>
               <input type="<?php echo $this->_tpl_vars['vl']['type']; ?>
" name="<?php echo $this->_tpl_vars['ky']; ?>
" id="userpass" size="<?php echo $this->_tpl_vars['vl']['size']; ?>
" value="<?php if (isset ( $this->_tpl_vars['vl']['value'] )): ?><?php echo $this->_tpl_vars['vl']['value']; ?>
<?php endif; ?>" />
           <?php elseif ($this->_tpl_vars['vl']['type'] == 'textarea'): ?>
               <textarea cols="<?php echo $this->_tpl_vars['vl']['cols']; ?>
" rows="<?php echo $this->_tpl_vars['vl']['rows']; ?>
" name="<?php echo $this->_tpl_vars['ky']; ?>
"><?php if (isset ( $this->_tpl_vars['vl']['value'] )): ?><?php echo $this->_tpl_vars['vl']['value']; ?>
<?php endif; ?></textarea>
           <?php elseif ($this->_tpl_vars['vl']['type'] == 'submit'): ?>
               <input type="submit" value="<?php if (isset ( $this->_tpl_vars['vl']['value'] )): ?><?php echo ((is_array($_tmp=$this->_tpl_vars['vl']['value'])) ? $this->_run_mod_handler('capitalize', true, $_tmp, true) : smarty_modifier_capitalize($_tmp, true)); ?>
<?php endif; ?>" class="button" />
           <?php endif; ?>
           <br />
        <?php endif; ?>
    <?php endforeach; endif; unset($_from); ?>
    </form>
<!--/fieldset-->
</div>
<?php if (isset ( $this->_tpl_vars['value']['error'] )): ?>
<div style="clear:both"><font id="error_message"><?php echo $this->_tpl_vars['value']['error']; ?>
</font></div>
<?php endif; ?>
<?php endforeach; endif; unset($_from); ?>