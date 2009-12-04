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
 *  hearthclass.php
 *  
 *  Created on Oct 4, 2009, 1:16:46 PM
 */

require_once MODULES_DIR . DS . 'hearth' . DS . 'config.inc';

class hearthModule extends mainModule
{
    var $title = 'hearth module';
    var $description = '';

    function menu(){
        $items['ref_hearth_inspection'] = array(
            'title' => __t('hearth_inspection'),
            'description' => __t('inspection reference form for hearth'),
            'path' => '/reference/hearth_inspection',
            'exec' => 'ref_inspection_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_inspection_detail'] = array(
            'title' => __t('detil hearth_inspection'),
            'description' => __t('inspection reference detail for hearth'),
            'path' => '/reference/hearth_inspection/detail',
            'exec' => 'ref_inspection_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_inspection_form'] = array(
            'title' => __t('hearth_inspection form'),
            'description' => __t('inspection reference form for hearth'),
            'path' => '/reference/hearth_inspection/form',
            'exec' => 'ref_inspection_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_inspection_form_submit'] = array(
            'title' => __t('hearth_inspection form'),
            'description' => __t('Execute inspection reference form for hearth'),
            'path' => '/reference/hearth_inspection/form_submit',
            'exec' => 'ref_inspection_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_inspection_edit'] = array(
            'title' => __t('hearth_inspection edit'),
            'description' => __t('Editing inspection reference form for hearth'),
            'path' => '/reference/hearth_inspection/edit',
            'exec' => 'ref_inspection_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_inspection_drop'] = array(
            'title' => __t('hearth_inspection drop'),
            'description' => __t('Remove inspection reference form for hearth'),
            'path' => '/reference/hearth_inspection/drop',
            'exec' => 'ref_inspection_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_palpation'] = array(
            'title' => __t('hearth_palpation'),
            'description' => __t('palpation reference form for hearth'),
            'path' => '/reference/hearth_palpation',
            'exec' => 'ref_palpation_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_palpation_detail'] = array(
            'title' => __t('detil hearth_palpation'),
            'description' => __t('palpation reference detail for hearth'),
            'path' => '/reference/hearth_palpation/detail',
            'exec' => 'ref_palpation_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_palpation_form'] = array(
            'title' => __t('hearth_palpation form'),
            'description' => __t('palpation reference form for hearth'),
            'path' => '/reference/hearth_palpation/form',
            'exec' => 'ref_palpation_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_palpation_form_submit'] = array(
            'title' => __t('hearth_palpation form'),
            'description' => __t('Execute palpation reference form for hearth'),
            'path' => '/reference/hearth_palpation/form_submit',
            'exec' => 'ref_palpation_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_palpation_edit'] = array(
            'title' => __t('hearth_palpation edit'),
            'description' => __t('Editing palpation reference form for hearth'),
            'path' => '/reference/hearth_palpation/edit',
            'exec' => 'ref_palpation_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_palpation_drop'] = array(
            'title' => __t('hearth_palpation drop'),
            'description' => __t('Remove palpation reference form for hearth'),
            'path' => '/reference/hearth_palpation/drop',
            'exec' => 'ref_palpation_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_percussion_top'] = array(
            'title' => __t('hearth_percussion_top'),
            'description' => __t('percussion_top reference form for hearth'),
            'path' => '/reference/hearth_percussion_top',
            'exec' => 'ref_percussion_top_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_percussion_top_detail'] = array(
            'title' => __t('detil hearth_percussion_top'),
            'description' => __t('percussion_top reference detail for hearth'),
            'path' => '/reference/hearth_percussion_top/detail',
            'exec' => 'ref_percussion_top_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_percussion_top_form'] = array(
            'title' => __t('hearth_percussion_top form'),
            'description' => __t('percussion_top reference form for hearth'),
            'path' => '/reference/hearth_percussion_top/form',
            'exec' => 'ref_percussion_top_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_percussion_top_form_submit'] = array(
            'title' => __t('hearth_percussion_top form'),
            'description' => __t('Execute percussion_top reference form for hearth'),
            'path' => '/reference/hearth_percussion_top/form_submit',
            'exec' => 'ref_percussion_top_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_percussion_top_edit'] = array(
            'title' => __t('hearth_percussion_top edit'),
            'description' => __t('Editing percussion_top reference form for hearth'),
            'path' => '/reference/hearth_percussion_top/edit',
            'exec' => 'ref_percussion_top_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_percussion_top_drop'] = array(
            'title' => __t('hearth_percussion_top drop'),
            'description' => __t('Remove percussion_top reference form for hearth'),
            'path' => '/reference/hearth_percussion_top/drop',
            'exec' => 'ref_percussion_top_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_percussion_bottom'] = array(
            'title' => __t('hearth_percussion_bottom'),
            'description' => __t('percussion_bottom reference form for hearth'),
            'path' => '/reference/hearth_percussion_bottom',
            'exec' => 'ref_percussion_bottom_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_percussion_bottom_detail'] = array(
            'title' => __t('detil hearth_percussion_bottom'),
            'description' => __t('percussion_bottom reference detail for hearth'),
            'path' => '/reference/hearth_percussion_bottom/detail',
            'exec' => 'ref_percussion_bottom_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_percussion_bottom_form'] = array(
            'title' => __t('hearth_percussion_bottom form'),
            'description' => __t('percussion_bottom reference form for hearth'),
            'path' => '/reference/hearth_percussion_bottom/form',
            'exec' => 'ref_percussion_bottom_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_percussion_bottom_form_submit'] = array(
            'title' => __t('hearth_percussion_bottom form'),
            'description' => __t('Execute percussion_bottom reference form for hearth'),
            'path' => '/reference/hearth_percussion_bottom/form_submit',
            'exec' => 'ref_percussion_bottom_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_percussion_bottom_edit'] = array(
            'title' => __t('hearth_percussion_bottom edit'),
            'description' => __t('Editing percussion_bottom reference form for hearth'),
            'path' => '/reference/hearth_percussion_bottom/edit',
            'exec' => 'ref_percussion_bottom_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_percussion_bottom_drop'] = array(
            'title' => __t('hearth_percussion_bottom drop'),
            'description' => __t('Remove percussion_bottom reference form for hearth'),
            'path' => '/reference/hearth_percussion_bottom/drop',
            'exec' => 'ref_percussion_bottom_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_percussion_right'] = array(
            'title' => __t('hearth_percussion_right'),
            'description' => __t('percussion_right reference form for hearth'),
            'path' => '/reference/hearth_percussion_right',
            'exec' => 'ref_percussion_right_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_percussion_right_detail'] = array(
            'title' => __t('detil hearth_percussion_right'),
            'description' => __t('percussion_right reference detail for hearth'),
            'path' => '/reference/hearth_percussion_right/detail',
            'exec' => 'ref_percussion_right_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_percussion_right_form'] = array(
            'title' => __t('hearth_percussion_right form'),
            'description' => __t('percussion_right reference form for hearth'),
            'path' => '/reference/hearth_percussion_right/form',
            'exec' => 'ref_percussion_right_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_percussion_right_form_submit'] = array(
            'title' => __t('hearth_percussion_right form'),
            'description' => __t('Execute percussion_right reference form for hearth'),
            'path' => '/reference/hearth_percussion_right/form_submit',
            'exec' => 'ref_percussion_right_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_percussion_right_edit'] = array(
            'title' => __t('hearth_percussion_right edit'),
            'description' => __t('Editing percussion_right reference form for hearth'),
            'path' => '/reference/hearth_percussion_right/edit',
            'exec' => 'ref_percussion_right_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_percussion_right_drop'] = array(
            'title' => __t('hearth_percussion_right drop'),
            'description' => __t('Remove percussion_right reference form for hearth'),
            'path' => '/reference/hearth_percussion_right/drop',
            'exec' => 'ref_percussion_right_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_percussion_left'] = array(
            'title' => __t('hearth_percussion_left'),
            'description' => __t('percussion_left reference form for hearth'),
            'path' => '/reference/hearth_percussion_left',
            'exec' => 'ref_percussion_left_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_percussion_left_detail'] = array(
            'title' => __t('detil hearth_percussion_left'),
            'description' => __t('percussion_left reference detail for hearth'),
            'path' => '/reference/hearth_percussion_left/detail',
            'exec' => 'ref_percussion_left_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_percussion_left_form'] = array(
            'title' => __t('hearth_percussion_left form'),
            'description' => __t('percussion_left reference form for hearth'),
            'path' => '/reference/hearth_percussion_left/form',
            'exec' => 'ref_percussion_left_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_percussion_left_form_submit'] = array(
            'title' => __t('hearth_percussion_left form'),
            'description' => __t('Execute percussion_left reference form for hearth'),
            'path' => '/reference/hearth_percussion_left/form_submit',
            'exec' => 'ref_percussion_left_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_percussion_left_edit'] = array(
            'title' => __t('hearth_percussion_left edit'),
            'description' => __t('Editing percussion_left reference form for hearth'),
            'path' => '/reference/hearth_percussion_left/edit',
            'exec' => 'ref_percussion_left_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_percussion_left_drop'] = array(
            'title' => __t('hearth_percussion_left drop'),
            'description' => __t('Remove percussion_left reference form for hearth'),
            'path' => '/reference/hearth_percussion_left/drop',
            'exec' => 'ref_percussion_left_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_auscultation_sound'] = array(
            'title' => __t('hearth_auscultation_sound'),
            'description' => __t('auscultation_sound reference form for hearth'),
            'path' => '/reference/hearth_auscultation_sound',
            'exec' => 'ref_auscultation_sound_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_auscultation_sound_detail'] = array(
            'title' => __t('detil hearth_auscultation_sound'),
            'description' => __t('auscultation_sound reference detail for hearth'),
            'path' => '/reference/hearth_auscultation_sound/detail',
            'exec' => 'ref_auscultation_sound_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_auscultation_sound_form'] = array(
            'title' => __t('hearth_auscultation_sound form'),
            'description' => __t('auscultation_sound reference form for hearth'),
            'path' => '/reference/hearth_auscultation_sound/form',
            'exec' => 'ref_auscultation_sound_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_auscultation_sound_form_submit'] = array(
            'title' => __t('hearth_auscultation_sound form'),
            'description' => __t('Execute auscultation_sound reference form for hearth'),
            'path' => '/reference/hearth_auscultation_sound/form_submit',
            'exec' => 'ref_auscultation_sound_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_auscultation_sound_edit'] = array(
            'title' => __t('hearth_auscultation_sound edit'),
            'description' => __t('Editing auscultation_sound reference form for hearth'),
            'path' => '/reference/hearth_auscultation_sound/edit',
            'exec' => 'ref_auscultation_sound_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_auscultation_sound_drop'] = array(
            'title' => __t('hearth_auscultation_sound drop'),
            'description' => __t('Remove auscultation_sound reference form for hearth'),
            'path' => '/reference/hearth_auscultation_sound/drop',
            'exec' => 'ref_auscultation_sound_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_localization'] = array(
            'title' => __t('hearth_localization'),
            'description' => __t('localization reference form for hearth'),
            'path' => '/reference/hearth_localization',
            'exec' => 'ref_localization_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_localization_detail'] = array(
            'title' => __t('detil hearth_localization'),
            'description' => __t('localization reference detail for hearth'),
            'path' => '/reference/hearth_localization/detail',
            'exec' => 'ref_localization_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_localization_form'] = array(
            'title' => __t('hearth_localization form'),
            'description' => __t('localization reference form for hearth'),
            'path' => '/reference/hearth_localization/form',
            'exec' => 'ref_localization_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_localization_form_submit'] = array(
            'title' => __t('hearth_localization form'),
            'description' => __t('Execute localization reference form for hearth'),
            'path' => '/reference/hearth_localization/form_submit',
            'exec' => 'ref_localization_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_localization_edit'] = array(
            'title' => __t('hearth_localization edit'),
            'description' => __t('Editing localization reference form for hearth'),
            'path' => '/reference/hearth_localization/edit',
            'exec' => 'ref_localization_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_localization_drop'] = array(
            'title' => __t('hearth_localization drop'),
            'description' => __t('Remove localization reference form for hearth'),
            'path' => '/reference/hearth_localization/drop',
            'exec' => 'ref_localization_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_intencity'] = array(
            'title' => __t('hearth_intencity'),
            'description' => __t('intencity reference form for hearth'),
            'path' => '/reference/hearth_intencity',
            'exec' => 'ref_intencity_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_intencity_detail'] = array(
            'title' => __t('detil hearth_intencity'),
            'description' => __t('intencity reference detail for hearth'),
            'path' => '/reference/hearth_intencity/detail',
            'exec' => 'ref_intencity_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_intencity_form'] = array(
            'title' => __t('hearth_intencity form'),
            'description' => __t('intencity reference form for hearth'),
            'path' => '/reference/hearth_intencity/form',
            'exec' => 'ref_intencity_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_intencity_form_submit'] = array(
            'title' => __t('hearth_intencity form'),
            'description' => __t('Execute intencity reference form for hearth'),
            'path' => '/reference/hearth_intencity/form_submit',
            'exec' => 'ref_intencity_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_intencity_edit'] = array(
            'title' => __t('hearth_intencity edit'),
            'description' => __t('Editing intencity reference form for hearth'),
            'path' => '/reference/hearth_intencity/edit',
            'exec' => 'ref_intencity_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_intencity_drop'] = array(
            'title' => __t('hearth_intencity drop'),
            'description' => __t('Remove intencity reference form for hearth'),
            'path' => '/reference/hearth_intencity/drop',
            'exec' => 'ref_intencity_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_penjalaran'] = array(
            'title' => __t('hearth_penjalaran'),
            'description' => __t('penjalaran reference form for hearth'),
            'path' => '/reference/hearth_penjalaran',
            'exec' => 'ref_penjalaran_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_penjalaran_detail'] = array(
            'title' => __t('detil hearth_penjalaran'),
            'description' => __t('penjalaran reference detail for hearth'),
            'path' => '/reference/hearth_penjalaran/detail',
            'exec' => 'ref_penjalaran_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_penjalaran_form'] = array(
            'title' => __t('hearth_penjalaran form'),
            'description' => __t('penjalaran reference form for hearth'),
            'path' => '/reference/hearth_penjalaran/form',
            'exec' => 'ref_penjalaran_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_penjalaran_form_submit'] = array(
            'title' => __t('hearth_penjalaran form'),
            'description' => __t('Execute penjalaran reference form for hearth'),
            'path' => '/reference/hearth_penjalaran/form_submit',
            'exec' => 'ref_penjalaran_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_penjalaran_edit'] = array(
            'title' => __t('hearth_penjalaran edit'),
            'description' => __t('Editing penjalaran reference form for hearth'),
            'path' => '/reference/hearth_penjalaran/edit',
            'exec' => 'ref_penjalaran_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_penjalaran_drop'] = array(
            'title' => __t('hearth_penjalaran drop'),
            'description' => __t('Remove penjalaran reference form for hearth'),
            'path' => '/reference/hearth_penjalaran/drop',
            'exec' => 'ref_penjalaran_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_auscultation_kind'] = array(
            'title' => __t('hearth_auscultation_kind'),
            'description' => __t('auscultation_kind reference form for hearth'),
            'path' => '/reference/hearth_auscultation_kind',
            'exec' => 'ref_auscultation_kind_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_auscultation_kind_detail'] = array(
            'title' => __t('detil hearth_auscultation_kind'),
            'description' => __t('auscultation_kind reference detail for hearth'),
            'path' => '/reference/hearth_auscultation_kind/detail',
            'exec' => 'ref_auscultation_kind_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_auscultation_kind_form'] = array(
            'title' => __t('hearth_auscultation_kind form'),
            'description' => __t('auscultation_kind reference form for hearth'),
            'path' => '/reference/hearth_auscultation_kind/form',
            'exec' => 'ref_auscultation_kind_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_auscultation_kind_form_submit'] = array(
            'title' => __t('hearth_auscultation_kind form'),
            'description' => __t('Execute auscultation_kind reference form for hearth'),
            'path' => '/reference/hearth_auscultation_kind/form_submit',
            'exec' => 'ref_auscultation_kind_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_auscultation_kind_edit'] = array(
            'title' => __t('hearth_auscultation_kind edit'),
            'description' => __t('Editing auscultation_kind reference form for hearth'),
            'path' => '/reference/hearth_auscultation_kind/edit',
            'exec' => 'ref_auscultation_kind_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_auscultation_kind_drop'] = array(
            'title' => __t('hearth_auscultation_kind drop'),
            'description' => __t('Remove auscultation_kind reference form for hearth'),
            'path' => '/reference/hearth_auscultation_kind/drop',
            'exec' => 'ref_auscultation_kind_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_auscultation_quality'] = array(
            'title' => __t('hearth_auscultation_quality'),
            'description' => __t('auscultation_quality reference form for hearth'),
            'path' => '/reference/hearth_auscultation_quality',
            'exec' => 'ref_auscultation_quality_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_auscultation_quality_detail'] = array(
            'title' => __t('detil hearth_auscultation_quality'),
            'description' => __t('auscultation_quality reference detail for hearth'),
            'path' => '/reference/hearth_auscultation_quality/detail',
            'exec' => 'ref_auscultation_quality_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_hearth_auscultation_quality_form'] = array(
            'title' => __t('hearth_auscultation_quality form'),
            'description' => __t('auscultation_quality reference form for hearth'),
            'path' => '/reference/hearth_auscultation_quality/form',
            'exec' => 'ref_auscultation_quality_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_auscultation_quality_form_submit'] = array(
            'title' => __t('hearth_auscultation_quality form'),
            'description' => __t('Execute auscultation_quality reference form for hearth'),
            'path' => '/reference/hearth_auscultation_quality/form_submit',
            'exec' => 'ref_auscultation_quality_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_auscultation_quality_edit'] = array(
            'title' => __t('hearth_auscultation_quality edit'),
            'description' => __t('Editing auscultation_quality reference form for hearth'),
            'path' => '/reference/hearth_auscultation_quality/edit',
            'exec' => 'ref_auscultation_quality_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_hearth_auscultation_quality_drop'] = array(
            'title' => __t('hearth_auscultation_quality drop'),
            'description' => __t('Remove auscultation_quality reference form for hearth'),
            'path' => '/reference/hearth_auscultation_quality/drop',
            'exec' => 'ref_auscultation_quality_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        return $items;
    }

    function ref_inspection_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi inspeksi jantung');
        $result['description'] = __t('Referensi pilihan inspeksi jantung pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/hearth_inspection/form',
            'position' => 'top',
            'user_required' => 'reference'
        );
        $result['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => 'inspection',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_hearth_inspection'),
            NULL,
            'inspection'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['inspection'] = ucwords($query->fields['inspection']);
                $result['data'][$i]['goto'] = '/reference/hearth_inspection/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_inspection_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add hearth_inspection'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'inspection',
            '#weight' => -3,
            '#action' => '/reference/hearth_inspection/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_hearth_inspection');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => 'text',
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
            }
            $query->MoveNext();
        } unset($query);
        $form['group']['submit'] = array(
            '#type' => 'submit',
            '#title' => '&nbsp;',
            '#value' => __t('input')
        );
        return $form;
    }

    function ref_inspection_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/hearth_inspection/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_hearth_inspection', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_hearth_inspection',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/hearth_inspection');
//        } else {
//            redirect_to('/reference/hearth_inspection/form');
//        }
    }

    function ref_inspection_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'inspection', 'hearth', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi inspection');
        $result['description'] = __t('informasi detil referensi inspection yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/hearth_inspection/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'inspection'),
            array('ref_hearth_inspection'),
            array(
                array('&&', "id=" . $keyid)
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if(isset($update)){
            $showsubmit = array('textarea', 'date');
        }
        foreach($query->fields as $key => $value){
            $result['data'][$key] = array(
                'key' => __t($key),
                'value' => $value,
                'link' => '/reference/hearth_inspection/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/hearth_inspection/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => 'text',
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->formtype_fields[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->formtype_fields[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        )
                    )
                );
                if(in_array($result['data'][$key]['form']['detail'][$key]['#type'], $showsubmit)){
                    $result['data'][$key]['form']['detail'][$key]['submit'] = array(
                        '#type' => 'submit',
                        '#value' => 'submit',
                        '#title' => 'hidden'
                    );
                }
            }
        } unset($query, $keyid);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function ref_inspection_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_hearth_inspection', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_hearth_inspection',
                        array(
                            $key => $value
                        ),
                        array(
                            array('&&', "id=" . $_POST['id'])
                        )
                    );
                    $this->query->conn->Execute($sql); unset($sql);
                    $this->query->close();
                }
            }
        }
        redirect_to('/reference/hearth_inspection/detail/' . $_POST['id']);
    }

    function ref_inspection_drop(){
        if($this->__is_dropable($_POST['id'], 'inspection', 'hearth', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_hearth_inspection',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/hearth_inspection');
    }

    function ref_palpation_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi palpasi jantung');
        $result['description'] = __t('Referensi pilihan palpasi jantung pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/hearth_palpation/form',
            'position' => 'top',
            'user_required' => 'reference'
        );
        $result['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => 'palpation',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_hearth_palpation'),
            NULL,
            'palpation'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['palpation'] = ucwords($query->fields['palpation']);
                $result['data'][$i]['goto'] = '/reference/hearth_palpation/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_palpation_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add hearth_palpation'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'palpation',
            '#weight' => -3,
            '#action' => '/reference/hearth_palpation/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_hearth_palpation');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => 'text',
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
            }
            $query->MoveNext();
        } unset($query);
        $form['group']['submit'] = array(
            '#type' => 'submit',
            '#title' => '&nbsp;',
            '#value' => __t('input')
        );
        return $form;
    }

    function ref_palpation_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/hearth_palpation/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_hearth_palpation', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_hearth_palpation',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/hearth_palpation');
//        } else {
//            redirect_to('/reference/hearth_palpation/form');
//        }
    }

    function ref_palpation_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'palpation', 'hearth', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi palpation');
        $result['description'] = __t('informasi detil referensi palpation yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/hearth_palpation/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'palpation'),
            array('ref_hearth_palpation'),
            array(
                array('&&', "id=" . $keyid)
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if(isset($update)){
            $showsubmit = array('textarea', 'date');
        }
        foreach($query->fields as $key => $value){
            $result['data'][$key] = array(
                'key' => __t($key),
                'value' => $value,
                'link' => '/reference/hearth_palpation/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/hearth_palpation/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => 'text',
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->formtype_fields[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->formtype_fields[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        )
                    )
                );
                if(in_array($result['data'][$key]['form']['detail'][$key]['#type'], $showsubmit)){
                    $result['data'][$key]['form']['detail'][$key]['submit'] = array(
                        '#type' => 'submit',
                        '#value' => 'submit',
                        '#title' => 'hidden'
                    );
                }
            }
        } unset($query, $keyid);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function ref_palpation_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_hearth_palpation', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_hearth_palpation',
                        array(
                            $key => $value
                        ),
                        array(
                            array('&&', "id=" . $_POST['id'])
                        )
                    );
                    $this->query->conn->Execute($sql); unset($sql);
                    $this->query->close();
                }
            }
        }
        redirect_to('/reference/hearth_palpation/detail/' . $_POST['id']);
    }

    function ref_palpation_drop(){
        if($this->__is_dropable($_POST['id'], 'palpation', 'hearth', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_hearth_palpation',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/hearth_palpation');
    }

    function ref_percussion_top_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi perkusi batas atas jantung');
        $result['description'] = __t('Referensi pilihan perkusi batas atas jantung pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/hearth_percussion_top/form',
            'position' => 'top',
            'user_required' => 'reference'
        );
        $result['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => 'batas_atas',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_hearth_percussion_top'),
            NULL
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['batas_atas'] = ucwords($query->fields['batas_atas']);
                $result['data'][$i]['goto'] = '/reference/hearth_percussion_top/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_percussion_top_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add hearth_percussion_top'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'percussion_top',
            '#weight' => -3,
            '#action' => '/reference/hearth_percussion_top/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_hearth_percussion_top');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => 'text',
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
            }
            $query->MoveNext();
        } unset($query);
        $form['group']['submit'] = array(
            '#type' => 'submit',
            '#title' => '&nbsp;',
            '#value' => __t('input')
        );
        return $form;
    }

    function ref_percussion_top_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/hearth_percussion_top/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_hearth_percussion_top', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_hearth_percussion_top',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/hearth_percussion_top');
//        } else {
//            redirect_to('/reference/hearth_percussion_top/form');
//        }
    }

    function ref_percussion_top_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'batas_atas', 'hearth', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi percussion_top');
        $result['description'] = __t('informasi detil referensi percussion_top yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/hearth_percussion_top/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'batas_atas'),
            array('ref_hearth_percussion_top'),
            array(
                array('&&', "id=" . $keyid)
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if(isset($update)){
            $showsubmit = array('textarea', 'date');
        }
        foreach($query->fields as $key => $value){
            $result['data'][$key] = array(
                'key' => __t($key),
                'value' => $value,
                'link' => '/reference/hearth_percussion_top/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/hearth_percussion_top/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => 'text',
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->formtype_fields[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->formtype_fields[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        )
                    )
                );
                if(in_array($result['data'][$key]['form']['detail'][$key]['#type'], $showsubmit)){
                    $result['data'][$key]['form']['detail'][$key]['submit'] = array(
                        '#type' => 'submit',
                        '#value' => 'submit',
                        '#title' => 'hidden'
                    );
                }
            }
        } unset($query, $keyid);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function ref_percussion_top_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_hearth_percussion_top', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_hearth_percussion_top',
                        array(
                            $key => $value
                        ),
                        array(
                            array('&&', "id=" . $_POST['id'])
                        )
                    );
                    $this->query->conn->Execute($sql); unset($sql);
                    $this->query->close();
                }
            }
        }
        redirect_to('/reference/hearth_percussion_top/detail/' . $_POST['id']);
    }

    function ref_percussion_top_drop(){
        if($this->__is_dropable($_POST['id'], 'percussion_top', 'hearth', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_hearth_percussion_top',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/hearth_percussion_top');
    }

    function ref_percussion_bottom_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi perkusi batas bawah jantung');
        $result['description'] = __t('Referensi pilihan perkusi batas bawah jantung pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/hearth_percussion_bottom/form',
            'position' => 'top',
            'user_required' => 'reference'
        );
        $result['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => 'batas_bawah',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_hearth_percussion_bottom'),
            NULL
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['batas_bawah'] = ucwords($query->fields['batas_bawah']);
                $result['data'][$i]['goto'] = '/reference/hearth_percussion_bottom/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_percussion_bottom_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add hearth_percussion_bottom'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'batas_bawah',
            '#weight' => -3,
            '#action' => '/reference/hearth_percussion_bottom/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_hearth_percussion_bottom');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => 'text',
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
            }
            $query->MoveNext();
        } unset($query);
        $form['group']['submit'] = array(
            '#type' => 'submit',
            '#title' => '&nbsp;',
            '#value' => __t('input')
        );
        return $form;
    }

    function ref_percussion_bottom_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/hearth_percussion_bottom/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_hearth_percussion_bottom', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_hearth_percussion_bottom',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/hearth_percussion_bottom');
//        } else {
//            redirect_to('/reference/hearth_percussion_bottom/form');
//        }
    }

    function ref_percussion_bottom_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'batas_bawah', 'hearth', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi percussion_bottom');
        $result['description'] = __t('informasi detil referensi percussion_bottom yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/hearth_percussion_bottom/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'batas_bawah'),
            array('ref_hearth_percussion_bottom'),
            array(
                array('&&', "id=" . $keyid)
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if(isset($update)){
            $showsubmit = array('textarea', 'date');
        }
        foreach($query->fields as $key => $value){
            $result['data'][$key] = array(
                'key' => __t($key),
                'value' => $value,
                'link' => '/reference/hearth_percussion_bottom/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/hearth_percussion_bottom/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => 'text',
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->formtype_fields[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->formtype_fields[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        )
                    )
                );
                if(in_array($result['data'][$key]['form']['detail'][$key]['#type'], $showsubmit)){
                    $result['data'][$key]['form']['detail'][$key]['submit'] = array(
                        '#type' => 'submit',
                        '#value' => 'submit',
                        '#title' => 'hidden'
                    );
                }
            }
        } unset($query, $keyid);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function ref_percussion_bottom_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_hearth_percussion_bottom', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_hearth_percussion_bottom',
                        array(
                            $key => $value
                        ),
                        array(
                            array('&&', "id=" . $_POST['id'])
                        )
                    );
                    $this->query->conn->Execute($sql); unset($sql);
                    $this->query->close();
                }
            }
        }
        redirect_to('/reference/hearth_percussion_bottom/detail/' . $_POST['id']);
    }

    function ref_percussion_bottom_drop(){
        if($this->__is_dropable($_POST['id'], 'batas_bawah', 'hearth', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_hearth_percussion_bottom',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/hearth_percussion_bottom');
    }

    function ref_percussion_right_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi perkusi batas kanan jantung');
        $result['description'] = __t('Referensi pilihan perkusi batas kanan jantung pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/hearth_percussion_right/form',
            'position' => 'top',
            'user_required' => 'reference'
        );
        $result['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => 'batas_kanan',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_hearth_percussion_right'),
            NULL
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['batas_kanan'] = ucwords($query->fields['batas_kanan']);
                $result['data'][$i]['goto'] = '/reference/hearth_percussion_right/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_percussion_right_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add hearth_percussion_right'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'batas_kanan',
            '#weight' => -3,
            '#action' => '/reference/hearth_percussion_right/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_hearth_percussion_right');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => 'text',
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
            }
            $query->MoveNext();
        } unset($query);
        $form['group']['submit'] = array(
            '#type' => 'submit',
            '#title' => '&nbsp;',
            '#value' => __t('input')
        );
        return $form;
    }

    function ref_percussion_right_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/hearth_percussion_right/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_hearth_percussion_right', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_hearth_percussion_right',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/hearth_percussion_right');
//        } else {
//            redirect_to('/reference/hearth_percussion_right/form');
//        }
    }

    function ref_percussion_right_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'batas_kanan', 'hearth', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi percussion_right');
        $result['description'] = __t('informasi detil referensi percussion_right yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/hearth_percussion_right/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'batas_kanan'),
            array('ref_hearth_percussion_right'),
            array(
                array('&&', "id=" . $keyid)
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if(isset($update)){
            $showsubmit = array('textarea', 'date');
        }
        foreach($query->fields as $key => $value){
            $result['data'][$key] = array(
                'key' => __t($key),
                'value' => $value,
                'link' => '/reference/hearth_percussion_right/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/hearth_percussion_right/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => 'text',
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->formtype_fields[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->formtype_fields[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        )
                    )
                );
                if(in_array($result['data'][$key]['form']['detail'][$key]['#type'], $showsubmit)){
                    $result['data'][$key]['form']['detail'][$key]['submit'] = array(
                        '#type' => 'submit',
                        '#value' => 'submit',
                        '#title' => 'hidden'
                    );
                }
            }
        } unset($query, $keyid);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function ref_percussion_right_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_hearth_percussion_right', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_hearth_percussion_right',
                        array(
                            $key => $value
                        ),
                        array(
                            array('&&', "id=" . $_POST['id'])
                        )
                    );
                    $this->query->conn->Execute($sql); unset($sql);
                    $this->query->close();
                }
            }
        }
        redirect_to('/reference/hearth_percussion_right/detail/' . $_POST['id']);
    }

    function ref_percussion_right_drop(){
        if($this->__is_dropable($_POST['id'], 'batas_kanan', 'hearth', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_hearth_percussion_right',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/hearth_percussion_right');
    }

    function ref_percussion_left_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi perkusi batas kiri jantung');
        $result['description'] = __t('Referensi pilihan perkusi batas kiri jantung pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/hearth_percussion_left/form',
            'position' => 'top',
            'user_required' => 'reference'
        );
        $result['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => 'batas_kiri',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_hearth_percussion_left'),
            NULL
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['batas_kiri'] = ucwords($query->fields['batas_kiri']);
                $result['data'][$i]['goto'] = '/reference/hearth_percussion_left/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_percussion_left_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add hearth_percussion_left'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'batas_kiri',
            '#weight' => -3,
            '#action' => '/reference/hearth_percussion_left/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_hearth_percussion_left');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => 'text',
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
            }
            $query->MoveNext();
        } unset($query);
        $form['group']['submit'] = array(
            '#type' => 'submit',
            '#title' => '&nbsp;',
            '#value' => __t('input')
        );
        return $form;
    }

    function ref_percussion_left_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/hearth_percussion_left/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_hearth_percussion_left', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_hearth_percussion_left',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/hearth_percussion_left');
//        } else {
//            redirect_to('/reference/hearth_percussion_left/form');
//        }
    }

    function ref_percussion_left_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'batas_kiri', 'hearth', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi percussion_left');
        $result['description'] = __t('informasi detil referensi percussion_left yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/hearth_percussion_left/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'batas_kiri'),
            array('ref_hearth_percussion_left'),
            array(
                array('&&', "id=" . $keyid)
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if(isset($update)){
            $showsubmit = array('textarea', 'date');
        }
        foreach($query->fields as $key => $value){
            $result['data'][$key] = array(
                'key' => __t($key),
                'value' => $value,
                'link' => '/reference/hearth_percussion_left/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/hearth_percussion_left/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => 'text',
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->formtype_fields[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->formtype_fields[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        )
                    )
                );
                if(in_array($result['data'][$key]['form']['detail'][$key]['#type'], $showsubmit)){
                    $result['data'][$key]['form']['detail'][$key]['submit'] = array(
                        '#type' => 'submit',
                        '#value' => 'submit',
                        '#title' => 'hidden'
                    );
                }
            }
        } unset($query, $keyid);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function ref_percussion_left_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_hearth_percussion_left', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_hearth_percussion_left',
                        array(
                            $key => $value
                        ),
                        array(
                            array('&&', "id=" . $_POST['id'])
                        )
                    );
                    $this->query->conn->Execute($sql); unset($sql);
                    $this->query->close();
                }
            }
        }
        redirect_to('/reference/hearth_percussion_left/detail/' . $_POST['id']);
    }

    function ref_percussion_left_drop(){
        if($this->__is_dropable($_POST['id'], 'batas_kiri', 'hearth', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_hearth_percussion_left',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/hearth_percussion_left');
    }

    function ref_auscultation_sound_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Auskultasi Bunyi Tambahan jantung');
        $result['description'] = __t('Referensi pilihan auskultasi bunyi tambahan jantung pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/hearth_auscultation_sound/form',
            'position' => 'top',
            'user_required' => 'reference'
        );
        $result['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => 'auscultation_sound',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_hearth_auscultation_sound'),
            NULL,
            'auscultation_sound'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['auscultation_sound'] = ucwords($query->fields['auscultation_sound']);
                $result['data'][$i]['goto'] = '/reference/hearth_auscultation_sound/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_auscultation_sound_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add hearth_auscultation_sound'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'auscultation_sound',
            '#weight' => -3,
            '#action' => '/reference/hearth_auscultation_sound/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_hearth_auscultation_sound');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => 'text',
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
            }
            $query->MoveNext();
        } unset($query);
        $form['group']['submit'] = array(
            '#type' => 'submit',
            '#title' => '&nbsp;',
            '#value' => __t('input')
        );
        return $form;
    }

    function ref_auscultation_sound_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/hearth_auscultation_sound/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_hearth_auscultation_sound', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_hearth_auscultation_sound',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/hearth_auscultation_sound');
//        } else {
//            redirect_to('/reference/hearth_auscultation_sound/form');
//        }
    }

    function ref_auscultation_sound_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'auscultation_sound', 'hearth', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi auscultation_sound');
        $result['description'] = __t('informasi detil referensi auscultation_sound yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/hearth_auscultation_sound/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'auscultation_sound'),
            array('ref_hearth_auscultation_sound'),
            array(
                array('&&', "id=" . $keyid)
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if(isset($update)){
            $showsubmit = array('textarea', 'date');
        }
        foreach($query->fields as $key => $value){
            $result['data'][$key] = array(
                'key' => __t($key),
                'value' => $value,
                'link' => '/reference/hearth_auscultation_sound/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/hearth_auscultation_sound/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => 'text',
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->formtype_fields[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->formtype_fields[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        )
                    )
                );
                if(in_array($result['data'][$key]['form']['detail'][$key]['#type'], $showsubmit)){
                    $result['data'][$key]['form']['detail'][$key]['submit'] = array(
                        '#type' => 'submit',
                        '#value' => 'submit',
                        '#title' => 'hidden'
                    );
                }
            }
        } unset($query, $keyid);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function ref_auscultation_sound_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_hearth_auscultation_sound', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_hearth_auscultation_sound',
                        array(
                            $key => $value
                        ),
                        array(
                            array('&&', "id=" . $_POST['id'])
                        )
                    );
                    $this->query->conn->Execute($sql); unset($sql);
                    $this->query->close();
                }
            }
        }
        redirect_to('/reference/hearth_auscultation_sound/detail/' . $_POST['id']);
    }

    function ref_auscultation_sound_drop(){
        if($this->__is_dropable($_POST['id'], 'auscultation_sound', 'hearth', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_hearth_auscultation_sound',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/hearth_auscultation_sound');
    }

    function ref_localization_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi Lokalisasi jantung');
        $result['description'] = __t('Referensi pilihan lokalisasi jantung pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/hearth_localization/form',
            'position' => 'top',
            'user_required' => 'reference'
        );
        $result['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => 'localization',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_hearth_localization'),
            NULL,
            'localization'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['localization'] = ucwords($query->fields['localization']);
                $result['data'][$i]['goto'] = '/reference/hearth_localization/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_localization_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add hearth_localization'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'localization',
            '#weight' => -3,
            '#action' => '/reference/hearth_localization/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_hearth_localization');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => 'text',
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
            }
            $query->MoveNext();
        } unset($query);
        $form['group']['submit'] = array(
            '#type' => 'submit',
            '#title' => '&nbsp;',
            '#value' => __t('input')
        );
        return $form;
    }

    function ref_localization_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/hearth_localization/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_hearth_localization', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_hearth_localization',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/hearth_localization');
//        } else {
//            redirect_to('/reference/hearth_localization/form');
//        }
    }

    function ref_localization_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'localization', 'hearth', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi localization');
        $result['description'] = __t('informasi detil referensi localization yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/hearth_localization/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'localization'),
            array('ref_hearth_localization'),
            array(
                array('&&', "id=" . $keyid)
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if(isset($update)){
            $showsubmit = array('textarea', 'date');
        }
        foreach($query->fields as $key => $value){
            $result['data'][$key] = array(
                'key' => __t($key),
                'value' => $value,
                'link' => '/reference/hearth_localization/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/hearth_localization/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => 'text',
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->formtype_fields[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->formtype_fields[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        )
                    )
                );
                if(in_array($result['data'][$key]['form']['detail'][$key]['#type'], $showsubmit)){
                    $result['data'][$key]['form']['detail'][$key]['submit'] = array(
                        '#type' => 'submit',
                        '#value' => 'submit',
                        '#title' => 'hidden'
                    );
                }
            }
        } unset($query, $keyid);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function ref_localization_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_hearth_localization', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_hearth_localization',
                        array(
                            $key => $value
                        ),
                        array(
                            array('&&', "id=" . $_POST['id'])
                        )
                    );
                    $this->query->conn->Execute($sql); unset($sql);
                    $this->query->close();
                }
            }
        }
        redirect_to('/reference/hearth_localization/detail/' . $_POST['id']);
    }

    function ref_localization_drop(){
        if($this->__is_dropable($_POST['id'], 'localization', 'hearth', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_hearth_localization',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/hearth_localization');
    }

    function ref_intencity_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi intensitas jantung');
        $result['description'] = __t('Referensi pilihan intensitas jantung pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/hearth_intencity/form',
            'position' => 'top',
            'user_required' => 'reference'
        );
        $result['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => 'intencity',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_hearth_intencity'),
            NULL,
            'intencity'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['intencity'] = ucwords($query->fields['intencity']);
                $result['data'][$i]['goto'] = '/reference/hearth_intencity/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_intencity_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add hearth_intencity'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'intencity',
            '#weight' => -3,
            '#action' => '/reference/hearth_intencity/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_hearth_intencity');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => 'text',
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
            }
            $query->MoveNext();
        } unset($query);
        $form['group']['submit'] = array(
            '#type' => 'submit',
            '#title' => '&nbsp;',
            '#value' => __t('input')
        );
        return $form;
    }

    function ref_intencity_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/hearth_intencity/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_hearth_intencity', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_hearth_intencity',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/hearth_intencity');
//        } else {
//            redirect_to('/reference/hearth_intencity/form');
//        }
    }

    function ref_intencity_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'intencity', 'hearth', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi intencity');
        $result['description'] = __t('informasi detil referensi intencity yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/hearth_intencity/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'intencity'),
            array('ref_hearth_intencity'),
            array(
                array('&&', "id=" . $keyid)
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if(isset($update)){
            $showsubmit = array('textarea', 'date');
        }
        foreach($query->fields as $key => $value){
            $result['data'][$key] = array(
                'key' => __t($key),
                'value' => $value,
                'link' => '/reference/hearth_intencity/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/hearth_intencity/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => 'text',
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->formtype_fields[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->formtype_fields[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        )
                    )
                );
                if(in_array($result['data'][$key]['form']['detail'][$key]['#type'], $showsubmit)){
                    $result['data'][$key]['form']['detail'][$key]['submit'] = array(
                        '#type' => 'submit',
                        '#value' => 'submit',
                        '#title' => 'hidden'
                    );
                }
            }
        } unset($query, $keyid);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function ref_intencity_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_hearth_intencity', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_hearth_intencity',
                        array(
                            $key => $value
                        ),
                        array(
                            array('&&', "id=" . $_POST['id'])
                        )
                    );
                    $this->query->conn->Execute($sql); unset($sql);
                    $this->query->close();
                }
            }
        }
        redirect_to('/reference/hearth_intencity/detail/' . $_POST['id']);
    }

    function ref_intencity_drop(){
        if($this->__is_dropable($_POST['id'], 'intencity', 'hearth', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_hearth_intencity',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/hearth_intencity');
    }

    function ref_penjalaran_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi penjalaran jantung');
        $result['description'] = __t('Referensi pilihan penjalaran jantung pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/hearth_penjalaran/form',
            'position' => 'top',
            'user_required' => 'reference'
        );
        $result['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => 'penjalaran',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_hearth_penjalaran'),
            NULL,
            'penjalaran'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['penjalaran'] = ucwords($query->fields['penjalaran']);
                $result['data'][$i]['goto'] = '/reference/hearth_penjalaran/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_penjalaran_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add hearth_penjalaran'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'penjalaran',
            '#weight' => -3,
            '#action' => '/reference/hearth_penjalaran/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_hearth_penjalaran');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => 'text',
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
            }
            $query->MoveNext();
        } unset($query);
        $form['group']['submit'] = array(
            '#type' => 'submit',
            '#title' => '&nbsp;',
            '#value' => __t('input')
        );
        return $form;
    }

    function ref_penjalaran_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/hearth_penjalaran/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_hearth_penjalaran', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_hearth_penjalaran',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/hearth_penjalaran');
//        } else {
//            redirect_to('/reference/hearth_penjalaran/form');
//        }
    }

    function ref_penjalaran_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'penjalaran', 'hearth', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi penjalaran');
        $result['description'] = __t('informasi detil referensi penjalaran yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/hearth_penjalaran/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'penjalaran'),
            array('ref_hearth_penjalaran'),
            array(
                array('&&', "id=" . $keyid)
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if(isset($update)){
            $showsubmit = array('textarea', 'date');
        }
        foreach($query->fields as $key => $value){
            $result['data'][$key] = array(
                'key' => __t($key),
                'value' => $value,
                'link' => '/reference/hearth_penjalaran/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/hearth_penjalaran/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => 'text',
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->formtype_fields[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->formtype_fields[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        )
                    )
                );
                if(in_array($result['data'][$key]['form']['detail'][$key]['#type'], $showsubmit)){
                    $result['data'][$key]['form']['detail'][$key]['submit'] = array(
                        '#type' => 'submit',
                        '#value' => 'submit',
                        '#title' => 'hidden'
                    );
                }
            }
        } unset($query, $keyid);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function ref_penjalaran_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_hearth_penjalaran', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_hearth_penjalaran',
                        array(
                            $key => $value
                        ),
                        array(
                            array('&&', "id=" . $_POST['id'])
                        )
                    );
                    $this->query->conn->Execute($sql); unset($sql);
                    $this->query->close();
                }
            }
        }
        redirect_to('/reference/hearth_penjalaran/detail/' . $_POST['id']);
    }

    function ref_penjalaran_drop(){
        if($this->__is_dropable($_POST['id'], 'penjalaran', 'hearth', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_hearth_penjalaran',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/hearth_penjalaran');
    }

    function ref_auscultation_kind_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi auscultation_kind jantung');
        $result['description'] = __t('Referensi pilihan auscultation_kind jantung pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/hearth_auscultation_kind/form',
            'position' => 'top',
            'user_required' => 'reference'
        );
        $result['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => 'kind',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_hearth_auscultation_kind'),
            NULL
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['kind'] = ucwords($query->fields['kind']);
                $result['data'][$i]['goto'] = '/reference/hearth_auscultation_kind/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_auscultation_kind_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add hearth_auscultation_kind'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'kind',
            '#weight' => -3,
            '#action' => '/reference/hearth_auscultation_kind/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_hearth_auscultation_kind');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => 'text',
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
            }
            $query->MoveNext();
        } unset($query);
        $form['group']['submit'] = array(
            '#type' => 'submit',
            '#title' => '&nbsp;',
            '#value' => __t('input')
        );
        return $form;
    }

    function ref_auscultation_kind_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/hearth_auscultation_kind/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_hearth_auscultation_kind', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_hearth_auscultation_kind',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/hearth_auscultation_kind');
//        } else {
//            redirect_to('/reference/hearth_auscultation_kind/form');
//        }
    }

    function ref_auscultation_kind_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'kind', 'hearth', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi auscultation_kind');
        $result['description'] = __t('informasi detil referensi auscultation_kind yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/hearth_auscultation_kind/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'kind'),
            array('ref_hearth_auscultation_kind'),
            array(
                array('&&', "id=" . $keyid)
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if(isset($update)){
            $showsubmit = array('textarea', 'date');
        }
        foreach($query->fields as $key => $value){
            $result['data'][$key] = array(
                'key' => __t($key),
                'value' => $value,
                'link' => '/reference/hearth_auscultation_kind/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/hearth_auscultation_kind/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => 'text',
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->formtype_fields[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->formtype_fields[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        )
                    )
                );
                if(in_array($result['data'][$key]['form']['detail'][$key]['#type'], $showsubmit)){
                    $result['data'][$key]['form']['detail'][$key]['submit'] = array(
                        '#type' => 'submit',
                        '#value' => 'submit',
                        '#title' => 'hidden'
                    );
                }
            }
        } unset($query, $keyid);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function ref_auscultation_kind_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_hearth_auscultation_kind', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_hearth_auscultation_kind',
                        array(
                            $key => $value
                        ),
                        array(
                            array('&&', "id=" . $_POST['id'])
                        )
                    );
                    $this->query->conn->Execute($sql); unset($sql);
                    $this->query->close();
                }
            }
        }
        redirect_to('/reference/hearth_auscultation_kind/detail/' . $_POST['id']);
    }

    function ref_auscultation_kind_drop(){
        if($this->__is_dropable($_POST['id'], 'kind', 'hearth', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_hearth_auscultation_kind',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/hearth_auscultation_kind');
    }

    function ref_auscultation_quality_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi auscultation_quality jantung');
        $result['description'] = __t('Referensi pilihan auscultation_quality jantung pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/hearth_auscultation_quality/form',
            'position' => 'top',
            'user_required' => 'reference'
        );
        $result['header'] = array(
            array(
                'field' => 'none',
                'caption' => __t('no'),
                'width' => '5%',
                'align' => 'right'
            ),
            array(
                'field' => 'quality',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_hearth_auscultation_quality'),
            NULL
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['quality'] = ucwords($query->fields['quality']);
                $result['data'][$i]['goto'] = '/reference/hearth_auscultation_quality/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_auscultation_quality_form(){
        if ($this->__check_caches() === TRUE){
            $vcache = $this->__read_form_cache();
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add hearth_auscultation_quality'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'quality',
            '#weight' => -3,
            '#action' => '/reference/hearth_auscultation_quality/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_hearth_auscultation_quality');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => 'text',
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
            }
            $query->MoveNext();
        } unset($query);
        $form['group']['submit'] = array(
            '#type' => 'submit',
            '#title' => '&nbsp;',
            '#value' => __t('input')
        );
        return $form;
    }

    function ref_auscultation_quality_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error' => __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/hearth_auscultation_quality/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_hearth_auscultation_quality', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_hearth_auscultation_quality',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            redirect_to('/reference/hearth_auscultation_quality');
//        } else {
//            redirect_to('/reference/hearth_auscultation_quality/form');
//        }
    }

    function ref_auscultation_quality_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'quality', 'hearth', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi auscultation_quality');
        $result['description'] = __t('informasi detil referensi auscultation_quality yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/hearth_auscultation_quality/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'quality'),
            array('ref_hearth_auscultation_quality'),
            array(
                array('&&', "id=" . $keyid)
            )
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if(isset($update)){
            $showsubmit = array('textarea', 'date');
        }
        foreach($query->fields as $key => $value){
            $result['data'][$key] = array(
                'key' => __t($key),
                'value' => $value,
                'link' => '/reference/hearth_auscultation_quality/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/hearth_auscultation_quality/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => 'text',
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->formtype_fields[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->formtype_fields[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        )
                    )
                );
                if(in_array($result['data'][$key]['form']['detail'][$key]['#type'], $showsubmit)){
                    $result['data'][$key]['form']['detail'][$key]['submit'] = array(
                        '#type' => 'submit',
                        '#value' => 'submit',
                        '#title' => 'hidden'
                    );
                }
            }
        } unset($query, $keyid);
//        echo '<pre>'; print_r($result); echo '</pre>';
        return $result;
    }

    function ref_auscultation_quality_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_hearth_auscultation_quality', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_hearth_auscultation_quality',
                        array(
                            $key => $value
                        ),
                        array(
                            array('&&', "id=" . $_POST['id'])
                        )
                    );
                    $this->query->conn->Execute($sql); unset($sql);
                    $this->query->close();
                }
            }
        }
        redirect_to('/reference/hearth_auscultation_quality/detail/' . $_POST['id']);
    }

    function ref_auscultation_quality_drop(){
        if($this->__is_dropable($_POST['id'], 'quality', 'hearth', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_hearth_auscultation_quality',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/hearth_auscultation_quality');
    }

    function __get_refs($fields, $sort=NULL){
        $result = array();
        $sql = $this->query->getSelect(
            array(),
            array($this->config->reftable[$fields][0]),
            NULL,
            (!is_null($sort) ? $sort . ' asc' : 'id asc')
        );
        $this->query->connect();
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            $result[$query->fields['id']] = $query->fields[$this->config->reftable[$fields][1]];
            $query->MoveNext();
        }
        return $result;
    }

    function cardio_menu(){
        $result = array();
        $result['#title'] = __t('Jantung');
        $result['#tpl'] = MODULES_DIR . DS . 'hearth' . DS . 'hearth.tpl';
        $datafields = $this->__get_data_fields('hearth', $this->query);
        if (count($this->config->free_val) > 0){
            $vcache = $this->config->free_val;
            $sql = $this->query->getSelect(
                array(),
                array('hearth'),
                array(
                    array('&&', "id=" . $vcache['id'])
                )
            ); unset($vcache);
            $this->query->connect();
            $getit = $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            if($getit->_numOfRows > 0){
                foreach($getit->fields as $key => $value){
                    $vcache[$key] = $value;
                }
            }
        }
        foreach($datafields as $key => $value){
            $result['datafields'][$value] = array(
                'title' => __t($value),
                'type' => $this->config->typeoffields[$value],
                'value' => isset($vcache[$value]) ? $vcache[$value] : ''
            );
            if(in_array($value, $this->config->fieldsisarray)){
                $result['datafields'][$value]['theref'] = $this->__get_refs($value);
            } elseif($this->config->typeoffields[$value] == 'datetime'){
                $result['datafields'][$value]['theref'] = $this->nama_bulan;
                $result['datafields'][$value]['timenow'] = $this->config->time;
            } else {
                $result['datafields'][$value]['size'] = 6;
            }
            $result['datafields'][$value]['readonly'] = isset($this->config->free_val['readonly']) ? true : false;
        }
        return $result;
    }

    function cardio_submit(){
        $thefields = $this->__get_data_fields('hearth', $this->query);
        foreach($this->config->free_val as $key => $value){
            if(in_array($key, $thefields)){
                if($key == 'inspection' || $key == 'palpation' || $key == 'auscultation_sound'){
                    if(count($value) > 0){
                        $value = implode(',', $value);
                    }
                }
                $thevalue[$key] = $value;
            }
        } unset($thefields);
        if($_POST['id'] != ''){
            unset($thevalue['id']);
            $opr = 'update';
            $strid = array('id', $_POST['id']);
        } else {
            $opr = 'insert';
            $strid = array('id', $thevalue['id']);
        }
        $this->__exec_db_ops(
            $this->query,
            'hearth',
            $opr,
            $strid,
            $thevalue
        );
        unset($thevalue, $opr, $strid);
    }
}