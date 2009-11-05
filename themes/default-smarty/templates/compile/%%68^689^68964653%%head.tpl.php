<?php /* Smarty version 2.6.26, created on 2009-09-08 04:46:36
         compiled from head.tpl */ ?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
	   "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
    <title><?php echo $this->_tpl_vars['configs']->systitle; ?>
</title>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <!--link rel="stylesheet" type="text/css" href="/themes/default/css/default.css"-->
    <link rel="stylesheet" type="text/css" href="/themes/default/css/<?php if (isset ( $this->_tpl_vars['body_login'] )): ?>login<?php else: ?>style<?php endif; ?>.css">
    <?php if (! isset ( $this->_tpl_vars['body_login'] )): ?>
            <?php endif; ?>
</head>
<body<?php if (isset ( $this->_tpl_vars['body_login'] )): ?> onLoad="<?php echo $this->_tpl_vars['body_login']; ?>
"<?php endif; ?>>