<?php /* Smarty version 2.6.26, created on 2009-09-08 18:49:39
         compiled from header.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('modifier', 'capitalize', 'header.tpl', 29, false),)), $this); ?>

<div id=header>
<a href="/"><IMG src="/themes/default/images/header_logo1.png" border="0"></a>
    <?php if (isset ( $this->_tpl_vars['mymenu']['primary_links'] )): ?>
    <div id=main-nav>
        <?php $_from = $this->_tpl_vars['mymenu']['primary_links']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['key'] => $this->_tpl_vars['value']):
?>
            <?php if ($this->_tpl_vars['key'] > 0): ?>|<?php endif; ?> &nbsp; <a href="<?php echo $this->_tpl_vars['value']['path']; ?>
"><?php echo ((is_array($_tmp=$this->_tpl_vars['value']['title'])) ? $this->_run_mod_handler('capitalize', true, $_tmp, true) : smarty_modifier_capitalize($_tmp, true)); ?>
</a>
        <?php endforeach; endif; unset($_from); ?>
    </div>
    <?php endif; ?>
</div>