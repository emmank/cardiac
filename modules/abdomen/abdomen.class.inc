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
 *  abdomenclass.php
 *  
 *  Created on Oct 5, 2009, 11:29:26 AM
 */

require_once MODULES_DIR . DS . 'abdomen' . DS . 'config.inc';

class abdomenModule extends mainModule
{
    var $title = 'abdomen module';
    var $description = '';

    function menu(){
        $items['ref_abdomen_relief'] = array(
            'title' => __t('abdomen_relief'),
            'description' => __t('relief reference form for abdomen'),
            'path' => '/reference/abdomen_relief',
            'exec' => 'ref_relief_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_relief_detail'] = array(
            'title' => __t('detil abdomen_relief'),
            'description' => __t('relief reference detail for abdomen'),
            'path' => '/reference/abdomen_relief/detail',
            'exec' => 'ref_relief_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_relief_form'] = array(
            'title' => __t('abdomen_relief form'),
            'description' => __t('relief reference form for abdomen'),
            'path' => '/reference/abdomen_relief/form',
            'exec' => 'ref_relief_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_relief_form_submit'] = array(
            'title' => __t('abdomen_relief form'),
            'description' => __t('Execute relief reference form for abdomen'),
            'path' => '/reference/abdomen_relief/form_submit',
            'exec' => 'ref_relief_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_relief_edit'] = array(
            'title' => __t('abdomen_relief edit'),
            'description' => __t('Editing relief reference form for abdomen'),
            'path' => '/reference/abdomen_relief/edit',
            'exec' => 'ref_relief_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_relief_drop'] = array(
            'title' => __t('abdomen_relief drop'),
            'description' => __t('Remove relief reference form for abdomen'),
            'path' => '/reference/abdomen_relief/drop',
            'exec' => 'ref_relief_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_center'] = array(
            'title' => __t('abdomen_center'),
            'description' => __t('center reference form for abdomen'),
            'path' => '/reference/abdomen_center',
            'exec' => 'ref_center_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_center_detail'] = array(
            'title' => __t('detil abdomen_center'),
            'description' => __t('center reference detail for abdomen'),
            'path' => '/reference/abdomen_center/detail',
            'exec' => 'ref_center_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_center_form'] = array(
            'title' => __t('abdomen_center form'),
            'description' => __t('center reference form for abdomen'),
            'path' => '/reference/abdomen_center/form',
            'exec' => 'ref_center_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_center_form_submit'] = array(
            'title' => __t('abdomen_center form'),
            'description' => __t('Execute center reference form for abdomen'),
            'path' => '/reference/abdomen_center/form_submit',
            'exec' => 'ref_center_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_center_edit'] = array(
            'title' => __t('abdomen_center edit'),
            'description' => __t('Editing center reference form for abdomen'),
            'path' => '/reference/abdomen_center/edit',
            'exec' => 'ref_center_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_center_drop'] = array(
            'title' => __t('abdomen_center drop'),
            'description' => __t('Remove center reference form for abdomen'),
            'path' => '/reference/abdomen_center/drop',
            'exec' => 'ref_center_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_skin'] = array(
            'title' => __t('abdomen_skin'),
            'description' => __t('skin reference form for abdomen'),
            'path' => '/reference/abdomen_skin',
            'exec' => 'ref_skin_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_skin_detail'] = array(
            'title' => __t('detil abdomen_skin'),
            'description' => __t('skin reference detail for abdomen'),
            'path' => '/reference/abdomen_skin/detail',
            'exec' => 'ref_skin_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_skin_form'] = array(
            'title' => __t('abdomen_skin form'),
            'description' => __t('skin reference form for abdomen'),
            'path' => '/reference/abdomen_skin/form',
            'exec' => 'ref_skin_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_skin_form_submit'] = array(
            'title' => __t('abdomen_skin form'),
            'description' => __t('Execute skin reference form for abdomen'),
            'path' => '/reference/abdomen_skin/form_submit',
            'exec' => 'ref_skin_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_skin_edit'] = array(
            'title' => __t('abdomen_skin edit'),
            'description' => __t('Editing skin reference form for abdomen'),
            'path' => '/reference/abdomen_skin/edit',
            'exec' => 'ref_skin_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_skin_drop'] = array(
            'title' => __t('abdomen_skin drop'),
            'description' => __t('Remove skin reference form for abdomen'),
            'path' => '/reference/abdomen_skin/drop',
            'exec' => 'ref_skin_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_gerakan_dinding_perut'] = array(
            'title' => __t('abdomen_gerakan_dinding_perut'),
            'description' => __t('gerakan_dinding_perut reference form for abdomen'),
            'path' => '/reference/abdomen_gerakan_dinding_perut',
            'exec' => 'ref_gerakan_dinding_perut_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_gerakan_dinding_perut_detail'] = array(
            'title' => __t('detil abdomen_gerakan_dinding_perut'),
            'description' => __t('gerakan_dinding_perut reference detail for abdomen'),
            'path' => '/reference/abdomen_gerakan_dinding_perut/detail',
            'exec' => 'ref_gerakan_dinding_perut_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_gerakan_dinding_perut_form'] = array(
            'title' => __t('abdomen_gerakan_dinding_perut form'),
            'description' => __t('gerakan_dinding_perut reference form for abdomen'),
            'path' => '/reference/abdomen_gerakan_dinding_perut/form',
            'exec' => 'ref_gerakan_dinding_perut_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_gerakan_dinding_perut_form_submit'] = array(
            'title' => __t('abdomen_gerakan_dinding_perut form'),
            'description' => __t('Execute gerakan_dinding_perut reference form for abdomen'),
            'path' => '/reference/abdomen_gerakan_dinding_perut/form_submit',
            'exec' => 'ref_gerakan_dinding_perut_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_gerakan_dinding_perut_edit'] = array(
            'title' => __t('abdomen_gerakan_dinding_perut edit'),
            'description' => __t('Editing gerakan_dinding_perut reference form for abdomen'),
            'path' => '/reference/abdomen_gerakan_dinding_perut/edit',
            'exec' => 'ref_gerakan_dinding_perut_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_gerakan_dinding_perut_drop'] = array(
            'title' => __t('abdomen_gerakan_dinding_perut drop'),
            'description' => __t('Remove gerakan_dinding_perut reference form for abdomen'),
            'path' => '/reference/abdomen_gerakan_dinding_perut/drop',
            'exec' => 'ref_gerakan_dinding_perut_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_hepar'] = array(
            'title' => __t('abdomen_hepar'),
            'description' => __t('hepar reference form for abdomen'),
            'path' => '/reference/abdomen_hepar',
            'exec' => 'ref_hepar_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_hepar_detail'] = array(
            'title' => __t('detil abdomen_hepar'),
            'description' => __t('hepar reference detail for abdomen'),
            'path' => '/reference/abdomen_hepar/detail',
            'exec' => 'ref_hepar_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_hepar_form'] = array(
            'title' => __t('abdomen_hepar form'),
            'description' => __t('hepar reference form for abdomen'),
            'path' => '/reference/abdomen_hepar/form',
            'exec' => 'ref_hepar_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_hepar_form_submit'] = array(
            'title' => __t('abdomen_hepar form'),
            'description' => __t('Execute hepar reference form for abdomen'),
            'path' => '/reference/abdomen_hepar/form_submit',
            'exec' => 'ref_hepar_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_hepar_edit'] = array(
            'title' => __t('abdomen_hepar edit'),
            'description' => __t('Editing hepar reference form for abdomen'),
            'path' => '/reference/abdomen_hepar/edit',
            'exec' => 'ref_hepar_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_hepar_drop'] = array(
            'title' => __t('abdomen_hepar drop'),
            'description' => __t('Remove hepar reference form for abdomen'),
            'path' => '/reference/abdomen_hepar/drop',
            'exec' => 'ref_hepar_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_liver'] = array(
            'title' => __t('abdomen_liver'),
            'description' => __t('liver reference form for abdomen'),
            'path' => '/reference/abdomen_liver',
            'exec' => 'ref_liver_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_liver_detail'] = array(
            'title' => __t('detil abdomen_liver'),
            'description' => __t('liver reference detail for abdomen'),
            'path' => '/reference/abdomen_liver/detail',
            'exec' => 'ref_liver_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_liver_form'] = array(
            'title' => __t('abdomen_liver form'),
            'description' => __t('liver reference form for abdomen'),
            'path' => '/reference/abdomen_liver/form',
            'exec' => 'ref_liver_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_liver_form_submit'] = array(
            'title' => __t('abdomen_liver form'),
            'description' => __t('Execute liver reference form for abdomen'),
            'path' => '/reference/abdomen_liver/form_submit',
            'exec' => 'ref_liver_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_liver_edit'] = array(
            'title' => __t('abdomen_liver edit'),
            'description' => __t('Editing liver reference form for abdomen'),
            'path' => '/reference/abdomen_liver/edit',
            'exec' => 'ref_liver_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_liver_drop'] = array(
            'title' => __t('abdomen_liver drop'),
            'description' => __t('Remove liver reference form for abdomen'),
            'path' => '/reference/abdomen_liver/drop',
            'exec' => 'ref_liver_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_ginjal'] = array(
            'title' => __t('abdomen_ginjal'),
            'description' => __t('ginjal reference form for abdomen'),
            'path' => '/reference/abdomen_ginjal',
            'exec' => 'ref_ginjal_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_ginjal_detail'] = array(
            'title' => __t('detil abdomen_ginjal'),
            'description' => __t('ginjal reference detail for abdomen'),
            'path' => '/reference/abdomen_ginjal/detail',
            'exec' => 'ref_ginjal_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_ginjal_form'] = array(
            'title' => __t('abdomen_ginjal form'),
            'description' => __t('ginjal reference form for abdomen'),
            'path' => '/reference/abdomen_ginjal/form',
            'exec' => 'ref_ginjal_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_ginjal_form_submit'] = array(
            'title' => __t('abdomen_ginjal form'),
            'description' => __t('Execute ginjal reference form for abdomen'),
            'path' => '/reference/abdomen_ginjal/form_submit',
            'exec' => 'ref_ginjal_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_ginjal_edit'] = array(
            'title' => __t('abdomen_ginjal edit'),
            'description' => __t('Editing ginjal reference form for abdomen'),
            'path' => '/reference/abdomen_ginjal/edit',
            'exec' => 'ref_ginjal_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_ginjal_drop'] = array(
            'title' => __t('abdomen_ginjal drop'),
            'description' => __t('Remove ginjal reference form for abdomen'),
            'path' => '/reference/abdomen_ginjal/drop',
            'exec' => 'ref_ginjal_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        //-----------------inspeksi_ginjal [Herman]-----------------------------
        $items['ref_abdomen_inspeksi_ginjal'] = array(
            'title' => __t('abdomen_inspeksi_ginjal'),
            'description' => __t('inspeksi_ginjal reference form for abdomen'),
            'path' => '/reference/abdomen_inspeksi_ginjal',
            'exec' => 'ref_inspeksi_ginjal_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_inspeksi_ginjal_detail'] = array(
            'title' => __t('detil abdomen_inspeksi_ginjal'),
            'description' => __t('inspeksi_ginjal reference detail for abdomen'),
            'path' => '/reference/abdomen_inspeksi_ginjal/detail',
            'exec' => 'ref_inspeksi_ginjal_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_inspeksi_ginjal_form'] = array(
            'title' => __t('abdomen_inspeksi_ginjal form'),
            'description' => __t('inspeksi_ginjal reference form for abdomen'),
            'path' => '/reference/abdomen_inspeksi_ginjal/form',
            'exec' => 'ref_inspeksi_ginjal_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_inspeksi_ginjal_form_submit'] = array(
            'title' => __t('abdomen_inspeksi_ginjal form'),
            'description' => __t('Execute inspeksi_ginjal reference form for abdomen'),
            'path' => '/reference/abdomen_inspeksi_ginjal/form_submit',
            'exec' => 'ref_inspeksi_ginjal_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_inspeksi_ginjal_edit'] = array(
            'title' => __t('abdomen_inspeksi_ginjal edit'),
            'description' => __t('Editing inspeksi_ginjal reference form for abdomen'),
            'path' => '/reference/abdomen_inspeksi_ginjal/edit',
            'exec' => 'ref_inspeksi_ginjal_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_inspeksi_ginjal_drop'] = array(
            'title' => __t('abdomen_inspeksi_ginjal drop'),
            'description' => __t('Remove inspeksi_ginjal reference form for abdomen'),
            'path' => '/reference/abdomen_inspeksi_ginjal/drop',
            'exec' => 'ref_inspeksi_ginjal_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        
        $items['ref_abdomen_perkusi'] = array(
            'title' => __t('abdomen_perkusi'),
            'description' => __t('perkusi reference form for abdomen'),
            'path' => '/reference/abdomen_perkusi',
            'exec' => 'ref_abdomen_perkusi_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_perkusi_detail'] = array(
            'title' => __t('detil abdomen_perkusi'),
            'description' => __t('perkusi reference detail for abdomen'),
            'path' => '/reference/abdomen_perkusi/detail',
            'exec' => 'ref_abdomen_perkusi_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_perkusi_form'] = array(
            'title' => __t('abdomen_perkusi form'),
            'description' => __t('perkusi reference form for abdomen'),
            'path' => '/reference/abdomen_perkusi/form',
            'exec' => 'ref_abdomen_perkusi_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_perkusi_form_submit'] = array(
            'title' => __t('abdomen_perkusi form'),
            'description' => __t('Execute perkusi reference form for abdomen'),
            'path' => '/reference/abdomen_perkusi/form_submit',
            'exec' => 'ref_abdomen_perkusi_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_perkusi_edit'] = array(
            'title' => __t('abdomen_perkusi edit'),
            'description' => __t('Editing perkusi reference form for abdomen'),
            'path' => '/reference/abdomen_perkusi/edit',
            'exec' => 'ref_abdomen_perkusi_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_perkusi_drop'] = array(
            'title' => __t('abdomen_perkusi drop'),
            'description' => __t('Remove perkusi reference form for abdomen'),
            'path' => '/reference/abdomen_perkusi/drop',
            'exec' => 'ref_abdomen_perkusi_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_auscultation'] = array(
            'title' => __t('abdomen_auscultation'),
            'description' => __t('auscultation reference form for abdomen'),
            'path' => '/reference/abdomen_auscultation',
            'exec' => 'ref_auscultation_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_auscultation_detail'] = array(
            'title' => __t('detil abdomen_auscultation'),
            'description' => __t('auscultation reference detail for abdomen'),
            'path' => '/reference/abdomen_auscultation/detail',
            'exec' => 'ref_auscultation_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_auscultation_form'] = array(
            'title' => __t('abdomen_auscultation form'),
            'description' => __t('auscultation reference form for abdomen'),
            'path' => '/reference/abdomen_auscultation/form',
            'exec' => 'ref_auscultation_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_auscultation_form_submit'] = array(
            'title' => __t('abdomen_auscultation form'),
            'description' => __t('Execute auscultation reference form for abdomen'),
            'path' => '/reference/abdomen_auscultation/form_submit',
            'exec' => 'ref_auscultation_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_auscultation_edit'] = array(
            'title' => __t('abdomen_auscultation edit'),
            'description' => __t('Editing auscultation reference form for abdomen'),
            'path' => '/reference/abdomen_auscultation/edit',
            'exec' => 'ref_auscultation_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_auscultation_drop'] = array(
            'title' => __t('abdomen_auscultation drop'),
            'description' => __t('Remove auscultation reference form for abdomen'),
            'path' => '/reference/abdomen_auscultation/drop',
            'exec' => 'ref_auscultation_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_peristaltik_usus'] = array(
            'title' => __t('abdomen_peristaltik_usus'),
            'description' => __t('peristaltik_usus reference form for abdomen'),
            'path' => '/reference/abdomen_peristaltik_usus',
            'exec' => 'ref_peristaltik_usus_view',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_peristaltik_usus_detail'] = array(
            'title' => __t('detil abdomen_peristaltik_usus'),
            'description' => __t('peristaltik_usus reference detail for abdomen'),
            'path' => '/reference/abdomen_peristaltik_usus/detail',
            'exec' => 'ref_peristaltik_usus_detail',
            'weight' => '0',
            'user_required' => NULL
        );
        $items['ref_abdomen_peristaltik_usus_form'] = array(
            'title' => __t('abdomen_peristaltik_usus form'),
            'description' => __t('peristaltik_usus reference form for abdomen'),
            'path' => '/reference/abdomen_peristaltik_usus/form',
            'exec' => 'ref_peristaltik_usus_form',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_peristaltik_usus_form_submit'] = array(
            'title' => __t('abdomen_peristaltik_usus form'),
            'description' => __t('Execute peristaltik_usus reference form for abdomen'),
            'path' => '/reference/abdomen_peristaltik_usus/form_submit',
            'exec' => 'ref_peristaltik_usus_form_submit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_peristaltik_usus_edit'] = array(
            'title' => __t('abdomen_peristaltik_usus edit'),
            'description' => __t('Editing peristaltik_usus reference form for abdomen'),
            'path' => '/reference/abdomen_peristaltik_usus/edit',
            'exec' => 'ref_peristaltik_usus_edit',
            'weight' => '0',
            'user_required' => 'reference'
        );
        $items['ref_abdomen_peristaltik_usus_drop'] = array(
            'title' => __t('abdomen_peristaltik_usus drop'),
            'description' => __t('Remove peristaltik_usus reference form for abdomen'),
            'path' => '/reference/abdomen_peristaltik_usus/drop',
            'exec' => 'ref_peristaltik_usus_drop',
            'weight' => '0',
            'user_required' => 'reference'
        );
        return $items;
    }

    function ref_relief_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi bentuk abdomen');
        $result['description'] = __t('Referensi pilihan bentuk abdomen pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/abdomen_relief/form',
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
                'field' => 'relief',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_abdomen_relief'),
            NULL,
            'relief'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['relief'] = ucwords($query->fields['relief']);
                $result['data'][$i]['goto'] = '/reference/abdomen_relief/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_relief_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add abdomen_relief'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'relief',
            '#weight' => -3,
            '#action' => '/reference/abdomen_relief/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_abdomen_relief');
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

    function ref_relief_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/abdomen_relief/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_abdomen_relief', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_abdomen_relief',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/abdomen_relief');
//        } else {
//            redirect_to('/reference/abdomen_relief/form');
//        }
    }

    function ref_relief_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'relief', 'abdomen', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi relief');
        $result['description'] = __t('informasi detil referensi relief yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/abdomen_relief/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'relief'),
            array('ref_abdomen_relief'),
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
                'link' => '/reference/abdomen_relief/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/abdomen_relief/edit/',
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

    function ref_relief_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_abdomen_relief', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_abdomen_relief',
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
        redirect_to('/reference/abdomen_relief/detail/' . $_POST['id']);
    }

    function ref_relief_drop(){
        if($this->__is_dropable($_POST['id'], 'relief', 'abdomen', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_abdomen_relief',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/abdomen_relief');
    }

    // ------------ abdomen_perkusi [Herman]----------------------
    function ref_abdomen_perkusi_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi bentuk abdomen');
        $result['description'] = __t('Referensi pilihan bentuk abdomen pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/abdomen_perkusi/form',
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
                'field' => 'abdomen_perkusi',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_abdomen_perkusi'),
            NULL,
            'abdomen_perkusi'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['abdomen_perkusi'] = ucwords($query->fields['abdomen_perkusi']);
                $result['data'][$i]['goto'] = '/reference/abdomen_perkusi/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_abdomen_perkusi_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add abdomen_perkusi'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'abdomen_perkusi',
            '#weight' => -3,
            '#action' => '/reference/abdomen_perkusi/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_abdomen_perkusi');
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

    function ref_abdomen_perkusi_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/abdomen_perkusi/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_abdomen_perkusi', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_abdomen_perkusi',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/abdomen_perkusi');
//        } else {
//            redirect_to('/reference/abdomen_perkusi/form');
//        }
    }

    function ref_abdomen_perkusi_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'abdomen_perkusi', 'abdomen', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi abdomen_perkusi');
        $result['description'] = __t('informasi detil referensi abdomen_perkusi yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/abdomen_perkusi/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'abdomen_perkusi'),
            array('ref_abdomen_perkusi'),
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
                'link' => '/reference/abdomen_perkusi/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/abdomen_perkusi/edit/',
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

    function ref_abdomen_perkusi_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_abdomen_perkusi', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_abdomen_perkusi',
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
        redirect_to('/reference/abdomen_perkusi/detail/' . $_POST['id']);
    }

    function ref_abdomen_perkusi_drop(){
        if($this->__is_dropable($_POST['id'], 'abdomen_perkusi', 'abdomen', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_abdomen_perkusi',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/abdomen_perkusi');
    }

    function ref_center_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi pusat abdomen');
        $result['description'] = __t('Referensi pilihan pusat abdomen pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/abdomen_center/form',
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
                'field' => 'center',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_abdomen_center'),
            NULL,
            'center'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['center'] = ucwords($query->fields['center']);
                $result['data'][$i]['goto'] = '/reference/abdomen_center/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_center_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add abdomen_center'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'center',
            '#weight' => -3,
            '#action' => '/reference/abdomen_center/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_abdomen_center');
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

    function ref_center_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/abdomen_center/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_abdomen_center', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_abdomen_center',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/abdomen_center');
//        } else {
//            redirect_to('/reference/abdomen_center/form');
//        }
    }

    function ref_center_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'center', 'abdomen', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi center');
        $result['description'] = __t('informasi detil referensi center yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/abdomen_center/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'center'),
            array('ref_abdomen_center'),
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
                'link' => '/reference/abdomen_center/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/abdomen_center/edit/',
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

    function ref_center_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_abdomen_center', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_abdomen_center',
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
        redirect_to('/reference/abdomen_center/detail/' . $_POST['id']);
    }

    function ref_center_drop(){
        if($this->__is_dropable($_POST['id'], 'center', 'abdomen', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_abdomen_center',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/abdomen_center');
    }

    function ref_skin_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi kulit abdomen');
        $result['description'] = __t('Referensi pilihan kulit abdomen pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/abdomen_skin/form',
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
                'field' => 'skin',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_abdomen_skin'),
            NULL,
            'skin'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['skin'] = ucwords($query->fields['skin']);
                $result['data'][$i]['goto'] = '/reference/abdomen_skin/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_skin_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add abdomen_skin'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'skin',
            '#weight' => -3,
            '#action' => '/reference/abdomen_skin/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_abdomen_skin');
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

    function ref_skin_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/abdomen_skin/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_abdomen_skin', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_abdomen_skin',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/abdomen_skin');
//        } else {
//            redirect_to('/reference/abdomen_skin/form');
//        }
    }

    function ref_skin_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'skin', 'abdomen', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi skin');
        $result['description'] = __t('informasi detil referensi skin yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/abdomen_skin/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'skin'),
            array('ref_abdomen_skin'),
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
                'link' => '/reference/abdomen_skin/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/abdomen_skin/edit/',
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

    function ref_skin_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_abdomen_skin', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_abdomen_skin',
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
        redirect_to('/reference/abdomen_skin/detail/' . $_POST['id']);
    }

    function ref_skin_drop(){
        if($this->__is_dropable($_POST['id'], 'skin', 'abdomen', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_abdomen_skin',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/abdomen_skin');
    }

    function ref_gerakan_dinding_perut_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi gerakan dinding perut');
        $result['description'] = __t('Referensi pilihan gerakan dinding perut pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/abdomen_gerakan_dinding_perut/form',
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
                'field' => 'gerakan_dinding_perut',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_abdomen_gerakan_dinding_perut'),
            NULL,
            'gerakan_dinding_perut'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['gerakan_dinding_perut'] = ucwords($query->fields['gerakan_dinding_perut']);
                $result['data'][$i]['goto'] = '/reference/abdomen_gerakan_dinding_perut/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_gerakan_dinding_perut_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add abdomen_gerakan_dinding_perut'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'gerakan_dinding_perut',
            '#weight' => -3,
            '#action' => '/reference/abdomen_gerakan_dinding_perut/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_abdomen_gerakan_dinding_perut');
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

    function ref_gerakan_dinding_perut_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/abdomen_gerakan_dinding_perut/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_abdomen_gerakan_dinding_perut', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_abdomen_gerakan_dinding_perut',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/abdomen_gerakan_dinding_perut');
//        } else {
//            redirect_to('/reference/abdomen_gerakan_dinding_perut/form');
//        }
    }

    function ref_gerakan_dinding_perut_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'gerakan_dinding_perut', 'abdomen', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi gerakan_dinding_perut');
        $result['description'] = __t('informasi detil referensi gerakan_dinding_perut yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/abdomen_gerakan_dinding_perut/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'gerakan_dinding_perut'),
            array('ref_abdomen_gerakan_dinding_perut'),
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
                'link' => '/reference/abdomen_gerakan_dinding_perut/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/abdomen_gerakan_dinding_perut/edit/',
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

    function ref_gerakan_dinding_perut_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_abdomen_gerakan_dinding_perut', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_abdomen_gerakan_dinding_perut',
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
        redirect_to('/reference/abdomen_gerakan_dinding_perut/detail/' . $_POST['id']);
    }

    function ref_gerakan_dinding_perut_drop(){
        if($this->__is_dropable($_POST['id'], 'gerakan_dinding_perut', 'abdomen', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_abdomen_gerakan_dinding_perut',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/abdomen_gerakan_dinding_perut');
    }

    function ref_hepar_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi palpasi hati abdomen');
        $result['description'] = __t('Referensi pilihan palpasi hati abdomen pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/abdomen_hepar/form',
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
                'field' => 'hepar',
                'caption' => __t('keterangan'),
                'align' => 'left'
            ),
            array(
                'field' => 'type',
                'caption' => __t('tipe'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_abdomen_hepar'),
            NULL,
            'hepar'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['hepar'] = ucwords($query->fields['hepar']);
                $result['data'][$i]['goto'] = '/reference/abdomen_hepar/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_hepar_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add abdomen_hepar'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'hepar',
            '#weight' => -3,
            '#action' => '/reference/abdomen_hepar/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_abdomen_hepar');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => $this->config->heparfield_types[$query->fields['Field']],
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
                if($query->fields['Field'] == 'type'){
                    $form['group'][$query->fields['Field']]['#option'] = $this->config->formtypelists;
                }
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

    function ref_hepar_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/abdomen_hepar/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_abdomen_hepar', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_abdomen_hepar',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/abdomen_hepar');
//        } else {
//            redirect_to('/reference/abdomen_hepar/form');
//        }
    }

    function ref_hepar_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'hepar', 'abdomen', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi hepar');
        $result['description'] = __t('informasi detil referensi hepar yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/abdomen_hepar/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_abdomen_hepar'),
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
                'link' => '/reference/abdomen_hepar/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/abdomen_hepar/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => $this->config->heparfield_types[$key],
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->config->heparfield_types[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->config->heparfield_types[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        )
                    )
                );
                if($result['data'][$key]['form']['detail'][$key]['#type'] == 'select'){
                    $result['data'][$key]['form']['detail'][$key]['#option'] = $this->config->formtypelists;
                }
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

    function ref_hepar_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_abdomen_hepar', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_abdomen_hepar',
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
        redirect_to('/reference/abdomen_hepar/detail/' . $_POST['id']);
    }

    function ref_hepar_drop(){
        if($this->__is_dropable($_POST['id'], 'hepar', 'abdomen', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_abdomen_hepar',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/abdomen_hepar');
    }

    function ref_liver_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi palpasi limpa abdomen');
        $result['description'] = __t('Referensi pilihan palpasi limpa abdomen pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/abdomen_liver/form',
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
                'field' => 'liver',
                'caption' => __t('keterangan'),
                'align' => 'left'
            ),
            array(
                'field' => 'type',
                'caption' => __t('tipe'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_abdomen_liver'),
            NULL,
            'liver'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['liver'] = ucwords($query->fields['liver']);
                $result['data'][$i]['goto'] = '/reference/abdomen_liver/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_liver_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add abdomen_liver'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'liver',
            '#weight' => -3,
            '#action' => '/reference/abdomen_liver/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_abdomen_liver');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => $this->config->liverfield_types[$query->fields['Field']],
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
                if($query->fields['Field'] == 'type'){
                    $form['group'][$query->fields['Field']]['#option'] = $this->config->formtypelists;
                }
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

    function ref_liver_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/abdomen_liver/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_abdomen_liver', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_abdomen_liver',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/abdomen_liver');
//        } else {
//            redirect_to('/reference/abdomen_liver/form');
//        }
    }

    function ref_liver_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'liver', 'abdomen', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi liver');
        $result['description'] = __t('informasi detil referensi liver yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/abdomen_liver/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_abdomen_liver'),
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
                'link' => '/reference/abdomen_liver/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/abdomen_liver/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => $this->config->liverfield_types[$key],
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->config->liverfield_type[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->config->liverfield_type[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        )
                    )
                );
                if($result['data'][$key]['form']['detail'][$key]['#type'] == 'select'){
                    $result['data'][$key]['form']['detail'][$key]['#option'] = $this->config->formtypelists;
                }
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

    function ref_liver_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_abdomen_liver', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_abdomen_liver',
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
        redirect_to('/reference/abdomen_liver/detail/' . $_POST['id']);
    }

    function ref_liver_drop(){
        if($this->__is_dropable($_POST['id'], 'liver', 'abdomen', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_abdomen_liver',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/abdomen_liver');
    }

    function ref_ginjal_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi palpasi limpa abdomen');
        $result['description'] = __t('Referensi pilihan palpasi limpa abdomen pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/abdomen_ginjal/form',
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
                'field' => 'ginjal',
                'caption' => __t('keterangan'),
                'align' => 'left'
            ),
            array(
                'field' => 'type',
                'caption' => __t('tipe'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_abdomen_ginjal'),
            NULL,
            'ginjal'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['ginjal'] = ucwords($query->fields['ginjal']);
                $result['data'][$i]['goto'] = '/reference/abdomen_ginjal/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_ginjal_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add abdomen_ginjal'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'ginjal',
            '#weight' => -3,
            '#action' => '/reference/abdomen_ginjal/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_abdomen_ginjal');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => $this->config->ginjalfield_types[$query->fields['Field']],
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
                if($query->fields['Field'] == 'type'){
                    $form['group'][$query->fields['Field']]['#option'] = $this->config->formtypelists;
                }
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

    function ref_ginjal_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/abdomen_ginjal/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_abdomen_ginjal', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_abdomen_ginjal',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/abdomen_ginjal');
//        } else {
//            redirect_to('/reference/abdomen_ginjal/form');
//        }
    }

    function ref_ginjal_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'ginjal', 'abdomen', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi ginjal');
        $result['description'] = __t('informasi detil referensi ginjal yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/abdomen_ginjal/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_abdomen_ginjal'),
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
                'link' => '/reference/abdomen_ginjal/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/abdomen_ginjal/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => $this->config->ginjalfield_types[$key],
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->config->ginjalfield_type[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->config->ginjalfield_type[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        )
                    )
                );
                if($result['data'][$key]['form']['detail'][$key]['#type'] == 'select'){
                    $result['data'][$key]['form']['detail'][$key]['#option'] = $this->config->formtypelists;
                }
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

    function ref_ginjal_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_abdomen_ginjal', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_abdomen_ginjal',
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
        redirect_to('/reference/abdomen_ginjal/detail/' . $_POST['id']);
    }

    function ref_ginjal_drop(){
        if($this->__is_dropable($_POST['id'], 'ginjal', 'abdomen', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_abdomen_ginjal',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/abdomen_ginjal');
    }
    // -------------- Function inspeksi_ginjal -------------
    function ref_inspeksi_ginjal_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi palpasi ginjal abdomen');
        $result['description'] = __t('Referensi pilihan palpasi ginjal abdomen pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/abdomen_inspeksi_ginjal/form',
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
                'field' => 'inspeksi_ginjal',
                'caption' => __t('keterangan'),
                'align' => 'left'
            ),
            array(
                'field' => 'type',
                'caption' => __t('tipe'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_abdomen_inspeksi_ginjal'),
            NULL,
            'inspeksi_ginjal'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['inspeksi_ginjal'] = ucwords($query->fields['inspeksi_ginjal']);
                $result['data'][$i]['goto'] = '/reference/abdomen_inspeksi_ginjal/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_inspeksi_ginjal_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add abdomen_inspeksi_ginjal'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'inspeksi_ginjal',
            '#weight' => -3,
            '#action' => '/reference/abdomen_inspeksi_ginjal/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_abdomen_inspeksi_ginjal');
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        for($i=0; $i<$query->_numOfRows; $i++){
            if(!in_array($query->fields['Field'], array('id'))){
                $form['group'][$query->fields['Field']] = array(
                    '#type' => $this->config->inspeksi_ginjalfield_types[$query->fields['Field']],
                    '#title' => __t($query->fields['Field']),
                    '#value' => isset($vcache[$query->fields['Field']]) ? $vcache[$query->fields['Field']] : ($query->fields['Field'] == 'id' ? $_POST['id'] : ''),
                    '#error' => isset($vcache['blank']) && in_array($query->fields['Field'], $vcache['blank']) ? 1 : 0
                );
                if($query->fields['Field'] == 'type'){
                    $form['group'][$query->fields['Field']]['#option'] = $this->config->formtypelists;
                }
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

    function ref_inspeksi_ginjal_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/abdomen_inspeksi_ginjal/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_abdomen_inspeksi_ginjal', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_abdomen_inspeksi_ginjal',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/abdomen_inspeksi_ginjal');
//        } else {
//            redirect_to('/reference/abdomen_inspeksi_ginjal/form');
//        }
    }

    function ref_inspeksi_ginjal_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'inspeksi_ginjal', 'abdomen', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi inspeksi_ginjal');
        $result['description'] = __t('informasi detil referensi inspeksi_ginjal yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/abdomen_inspeksi_ginjal/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_abdomen_inspeksi_ginjal'),
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
                'link' => '/reference/abdomen_inspeksi_ginjal/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/abdomen_inspeksi_ginjal/edit/',
                        'id' => array(
                            '#type' => 'hidden',
                            '#value' => $keyid
                        ),
                        $key => array(
                            '#type' => $this->config->inspeksi_ginjalfield_types[$key],
                            '#value' => $value,
                            '#title' => 'hidden',
                            '#size' => $this->config->inspeksi_ginjalfield_type[$key] == 'select' ? 1 : 20,
                            '#extra' => $this->config->inspeksi_ginjalfield_type[$key] == 'select' ? 'onchange="Javascript:this.form.submit()"' : ''
                        )
                    )
                );
                if($result['data'][$key]['form']['detail'][$key]['#type'] == 'select'){
                    $result['data'][$key]['form']['detail'][$key]['#option'] = $this->config->formtypelists;
                }
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

    function ref_inspeksi_ginjal_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_abdomen_inspeksi_ginjal', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_abdomen_inspeksi_ginjal',
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
        redirect_to('/reference/abdomen_inspeksi_ginjal/detail/' . $_POST['id']);
    }

    function ref_inspeksi_ginjal_drop(){
        if($this->__is_dropable($_POST['id'], 'inspeksi_ginjal', 'abdomen', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_abdomen_inspeksi_ginjal',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/abdomen_inspeksi_ginjal');
    }

    
    function ref_auscultation_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi auscultation abdomen');
        $result['description'] = __t('Referensi pilihan auscultation abdomen pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/abdomen_auscultation/form',
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
                'field' => 'auscultation',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_abdomen_auscultation'),
            NULL,
            'auscultation'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['auscultation'] = ucwords($query->fields['auscultation']);
                $result['data'][$i]['goto'] = '/reference/abdomen_auscultation/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_auscultation_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add abdomen_auscultation'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'auscultation',
            '#weight' => -3,
            '#action' => '/reference/abdomen_auscultation/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_abdomen_auscultation');
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

    function ref_auscultation_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/abdomen_auscultation/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_abdomen_auscultation', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_abdomen_auscultation',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/abdomen_auscultation');
//        } else {
//            redirect_to('/reference/abdomen_auscultation/form');
//        }
    }

    function ref_auscultation_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'auscultation', 'abdomen', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi auscultation');
        $result['description'] = __t('informasi detil referensi auscultation yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/abdomen_auscultation/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'auscultation'),
            array('ref_abdomen_auscultation'),
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
                'link' => '/reference/abdomen_auscultation/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/abdomen_auscultation/edit/',
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

    function ref_auscultation_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_abdomen_auscultation', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_abdomen_auscultation',
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
        redirect_to('/reference/abdomen_auscultation/detail/' . $_POST['id']);
    }

    function ref_auscultation_drop(){
        if($this->__is_dropable($_POST['id'], 'auscultation', 'auscultation', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_abdomen_auscultation',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/abdomen_auscultation');
    }

    function ref_peristaltik_usus_view(){
        $result = array();
        $result['type'] = 'table';
        $result['title'] = __t('Referensi peristaltik_usus abdomen');
        $result['description'] = __t('Referensi pilihan peristaltik_usus abdomen pasien');
        $result['addmenu'] = array(
            'title' => __t('add reference'),
            'action' => '/reference/abdomen_peristaltik_usus/form',
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
                'field' => 'peristaltik_usus',
                'caption' => __t('keterangan'),
                'align' => 'left'
            )
        );
        $this->query->connect();
        $sql = $this->query->getSelect(
            array(),
            array('ref_abdomen_peristaltik_usus'),
            NULL,
            'peristaltik_usus'
        );
        $query = $this->query->conn->Execute($sql); unset($sql);
        $this->query->close();
        if($query->_numOfRows > 0){
            for($i=0; $i<$query->_numOfRows; $i++){
                $result['data'][$i] = $query->fields;
                $result['data'][$i]['peristaltik_usus'] = ucwords($query->fields['peristaltik_usus']);
                $result['data'][$i]['goto'] = '/reference/abdomen_peristaltik_usus/detail/' . $query->fields['id'];
                $query->MoveNext();
            }
        }
        return $result;
    }

    function ref_peristaltik_usus_form(){
        if(is_file($this->config->fcache)){
            $vcache = $this->__read_form_cache();
            unlink($this->config->fcache);
        }
//        echo '<pre>'; print_r($vcache); echo '</pre>';
        $form['group'] = array(
            '#type' => 'fieldset',
            '#id' => 'group',
            '#title' => __t('add abdomen_peristaltik_usus'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#focused_item' => 'peristaltik_usus',
            '#weight' => -3,
            '#action' => '/reference/abdomen_peristaltik_usus/form_submit',
            '#error' => isset($vcache['error']) ? $vcache['error'] : FALSE
        );
        $this->query->connect();
        $sql = $this->query->getDescribe('ref_abdomen_peristaltik_usus');
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

    function ref_peristaltik_usus_form_submit(){
//        if($_POST['id'] != ''){
            $dump = $this->__write_form_cache();
            foreach($dump as $key => $value){
                if($value == ''){
                    $this->__write_custom_cache(
                        array('error=>' . __t('Data kurang lengkap di kolom <strong>"') . __t($key) . '"</strong>', 1)
                    );
                    redirect_to('/reference/abdomen_peristaltik_usus/form');
                    exit();
                }
                if($key != 'blank' && $key != 'submit'){
                    $thevalue[$key] = $value;
                }
            } unset($dump);
            $thevalue['id'] = $this->__get_id_insert_value('ref_abdomen_peristaltik_usus', 'id', $this->query);
//        echo '<pre>'; print_r($thevalue); echo '</pre>'; exit();
            $this->query->connect();
            $sql = $this->query->saveData(
                'ref_abdomen_peristaltik_usus',
                $thevalue
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
            unset($thevalue);
            unlink($this->config->fcache);
            redirect_to('/reference/abdomen_peristaltik_usus');
//        } else {
//            redirect_to('/reference/abdomen_peristaltik_usus/form');
//        }
    }

    function ref_peristaltik_usus_detail(){
        $dump = explode('/', trim(preg_replace('/^\//','',$_GET['q'])));
        if(count($dump) > 4){
            $update = $dump[4];
        }
        $keyid = $dump[3]; unset($dump);
        $dropable = $this->__is_dropable($keyid, 'peristaltik_usus', 'abdomen', $this->query);
        $result = array();
        $result['type'] = 'items_detail';
        $result['title'] = __t('detil referensi peristaltik_usus');
        $result['description'] = __t('informasi detil referensi peristaltik_usus yang terpilih');
        $result['id'] = $keyid;
        $result['update_access'] = 'reference';
        $result['dropable'] = $dropable !== FALSE ? '/reference/abdomen_peristaltik_usus/drop' : '0';
        unset($dropable);
        $this->query->connect();
        $sql = $this->query->getSelect(
            array('id', 'peristaltik_usus'),
            array('ref_abdomen_peristaltik_usus'),
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
                'link' => '/reference/abdomen_peristaltik_usus/detail/' . $keyid . '/' . $key,
                'hide' => in_array($key, $this->config->hiddenfields) ? 1 : 0
            );
            if(isset($update) && $key == $update){
                $result['data'][$key]['form'] = array(
                    'detail' => array(
                        '#type' => 'fieldset',
                        '#title' => 'hidden',
                        '#action' => '/reference/abdomen_peristaltik_usus/edit/',
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

    function ref_peristaltik_usus_edit(){
        foreach($_POST as $key => $value){
            if($key != 'id'){
                if(in_array($key, $this->__get_data_fields('ref_abdomen_peristaltik_usus', $this->query))){
                    $this->query->connect();
                    $sql = $this->query->updateData(
                        'ref_abdomen_peristaltik_usus',
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
        redirect_to('/reference/abdomen_peristaltik_usus/detail/' . $_POST['id']);
    }

    function ref_peristaltik_usus_drop(){
        if($this->__is_dropable($_POST['id'], 'peristaltik_usus', 'abdomen', $this->query) !== FALSE){
            $this->query->connect();
            $sql = $this->query->setDelete(
                'ref_abdomen_peristaltik_usus',
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
            $this->query->conn->Execute($sql); unset($sql);
            $this->query->close();
        }
        redirect_to('/reference/abdomen_peristaltik_usus');
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
        $result['#title'] = __t('Abdomen');
        $result['#tpl'] = MODULES_DIR . DS . 'abdomen' . DS . 'abdomen.tpl';
        $datafields = $this->__get_data_fields('abdomen', $this->query);
        foreach($datafields as $key => $value){
            $result['datafields'][$value] = array(
                'title' => __t($value),
                'type' => $this->config->typeoffields[$value]
            );
            if(in_array($value, $this->config->fieldsisarray)){
                $result['datafields'][$value]['theref'] = $this->__get_refs($value);
            } elseif($this->config->typeoffields[$value] == 'datetime'){
                $result['datafields'][$value]['theref'] = $this->nama_bulan;
                $result['datafields'][$value]['timenow'] = $this->config->time;
            } else {
                $result['datafields'][$value]['size'] = 6;
            }
        }
        return $result;
    }

    function cardio_submit(){
        $thefields = $this->__get_data_fields('abdomen', $this->query);
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
            $sql = $this->query->updateData(
                'abdomen',
                $thevalue,
                array(
                    array('&&', "id=" . $_POST['id'])
                )
            );
        } else {
            $sql = $this->query->saveData(
                'abdomen',
                $thevalue
            );
        }
//        echo '<pre>'; print_r($thevalue); echo '</pre>';
        unset($thevalue);
//        $this->query->connect();
//        $this->conn->execute($sql); unset($sql);
//        $this->query->close();
    }


}