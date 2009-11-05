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
 *  constant.inc
 *
 *  Created on Sep 6, 2009, 11:03:48 AM
 */

    if(!defined('DS')){
        define ('DS', DIRECTORY_SEPARATOR);
    }

    if(!defined('LIBS_DIR')){
            define ('LIBS_DIR', 'libs');
    }

    if(!defined('DBSTRINGS_DIR')){
        define ('DBSTRINGS_DIR', 'databases');
    }

    if(!defined('CONFIGS_DIR')){
        define ('CONFIGS_DIR', 'configs');
    }

    if(!defined('INCLUDES_DIR')){
        define ('INCLUDES_DIR', 'includes');
    }

    if(!defined('FILES_DIR')){
        define('FILES_DIR', 'files');
    }

    if(!defined('REGISTRY_DIR')){
        define('REGISTRY_DIR', FILES_DIR . DS . 'registry');
    }

    if(!defined('DEFAULTS_DIR')){
        define('DEFAULTS_DIR', INCLUDES_DIR . DS . 'defaults');
    }

    if(!defined('MODULES_DIR')){
        define ('MODULES_DIR', 'modules');
    }

    if(!defined('THEMES_DIR')){
        define('THEMES_DIR', 'themes');
    }

