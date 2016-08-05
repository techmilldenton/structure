<?php

/**
 * @file
 * Theme settings .
 */

function md_structure_theme_settings_design(&$form, &$form_state) {
  global $base_url;
  $theme_default = variable_get('theme_default');

  $form['md_structure_settings']['design'] = array(
    '#type' => 'fieldset',
    '#weight' => -4,
    '#prefix' => '<div id="md-design" class="md-tabcontent clearfix">',
    '#suffix' => '</div><!-- / #md-design -->',
  );

  $form['md_structure_settings']['design']['design_htmllist'] = array(
    '#markup' => '<div id="md-content-sidebar" class="md-content-sidebar">
                        <ul class="clearfix">
                            <li><a href="#ds-header"><i class="fa-magic icon fa"></i>Header</a></li>
                            <li><a href="#ds-sidebar"><i class="fa-list-ul icon fa"></i>Sidebar</a></li>
                            <li><a href="#ds-contact-info"><i class="fa-envelope icon fa"></i>Contact</a></li>
                            <li><a href="#ds-contact"><i class="fa-info-circle icon fa"></i>Footer</a></li>
                        </ul>
                    </div><!-- /.md-content-sidebar -->
                    <div class="md-content-main">',
    '#weight' => -15,
  );
  $form['md_structure_settings']['design']['design_htmllistclose'] = array(
    '#markup' => '</div><!-- /.md-listleft -->',
    '#weight' => 15,
  );
  //////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////// Header //////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  $form['md_structure_settings']['design']['ds_header'] = array(
    '#type' => 'fieldset',
    '#weight' => 1,
    '#prefix' => '<div id="ds-header"><div class="md-tabcontent-row">',
    '#suffix' => '    </div></div><!-- / #ds-general -->',
  );
  $form['md_structure_settings']['design']['ds_header']['header_fix'] = array(
    '#type' => 'checkbox',
    '#default_value' => theme_get_setting('header_fix') ? theme_get_setting('header_fix') : 0,
    '#field_suffix' => '<label class="label-checkbox" for="edit-header-fix">Enable Fixed Header</label>',
    '#attributes' => array(
      'class' => array('input-checkbox')
    ),
  );
  $form['md_structure_settings']['design']['ds_header']['header_info'] = array(
    '#type' => 'textarea',
    '#format' => 'full_html',
    '#title' => t('Top header information'),
    '#default_value' => theme_get_setting('header_info'),
    '#prefix' => '<br />',
    '#attributes' => array(
      'class' => array('input-border')
    ),
  );

  //////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////// Sidebar /////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  $form['md_structure_settings']['design']['ds_sidebar'] = array(
    '#type' => 'fieldset',
    '#weight' => 1,
    '#prefix' => '<div id="ds-sidebar"><div class="md-tabcontent-row">',
    '#suffix' => '    </div></div><!-- / #ds-sidebar -->',
  );
  $form['md_structure_settings']['design']['ds_sidebar']['sidebar_position'] = array(
    '#type' => 'select',
    '#title' => t('Choose Sidebar Position'),
    '#default_value' => theme_get_setting('sidebar_position'),
    '#options' => array(
      'right' => t('Right'),
      'left' => t('Left'),
      'no' => t('No Sidebar'),

    ),
    '#attributes' => array(
      'class' => array('select')
    ),
    '#prefix' => '<h3 class="md-tabcontent-title">Sidebar Settings</h3><div class="form-group" style="margin-bottom: 0">',
    '#suffix' => '</div>',
    '#field_prefix' => '<div class="md-selection medium">',
    '#field_suffix' => '</div>'
  );

  /////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////// Custom Address ////////////////////////
  /////////////////////////////////////////////////////////////////////////////
  $form['md_structure_settings']['design']['info_contact'] = array(
    '#type' => 'fieldset',
    '#weight' => 1,
    '#prefix' => '<div id="ds-contact-info"><div class="md-tabcontent-row">',
    '#suffix' => '    </div></div><!-- / #ds-general -->',
  );
  if (module_exists('icon')) {
    $icon_bundles = icon_bundles();
    $icons = array();
    foreach ($icon_bundles as $bundles) {
      $icons[] = md_icon_bundle_list($bundles);
    }
    $address_defaul = theme_get_setting('address_info')
      ? theme_get_setting('address_info')
      : 'icon fontello icon-phone,||,font_icon|icon-phone,||,Call Us,||,0307-567-890,||';

    $markup = '<ul id="sortable">
                    <li class="icon-sort draggable-item" id="li-0">
                      <div class="toolbar">
                          <a class="delete-icon" href="#">Delete</a>
                          <a class="clone-icon" href="#">Clone</a>
                      </div>
                      <div class="wrap-icon">
                      </div>
                    </li>
                  </ul>';
    $form_popup = '<div class="form-popup">
                    <ul >
                      <li><div class="choose-icon" data-value="font_icon|icon-glyph">Choose Icon<a href="#"><i class="icon fontello icon-glyph"></i></a></div></li>
                      <li class="hidden"><label>Enter Title</label><input class="form-text icon-title" type="text" name="title-icon" value="" /></li>
                      <li><label>Enter Text</label><input class="form-text icon-text" type="text" name="text-icon" value="" /></li>
                    </ul>
                  </div>';
    $form['md_structure_settings']['design']['info_contact'] = array(
      '#type' => 'fieldset',
      '#weight' => 1,
      '#prefix' => '<div id="ds-contact-info"><div class="md-tabcontent-row">',
      '#suffix' => '    </div></div><!-- / #ds-general -->',
    );
    $form['md_structure_settings']['design']['info_contact']['markup'] = array(
      '#type' => 'markup',
      '#markup' => '<div></div>',
    );
    $form['md_structure_settings']['design']['info_contact']['address_info'] = array(
      '#type' => 'hidden',
      '#default_value' => $address_defaul,
      '#attributes' => array(
        'class' => array('icon-footer')
      )
    );
    $form['md_structure_settings']['design']['info_contact']['popup_icon'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="icon-popup">' . drupal_render($icons) . '</div>',
      '#prefix' => '<div class="form-group" style="margin-top: 0">',
      '#suffix' => '</div>',
    );
    $form['md_structure_settings']['design']['info_contact']['popup_form'] = array(
      '#type' => 'markup',
      '#prefix' => '<div class="form-group" style="margin-top: 0">',
      '#suffix' => '</div>',
      '#markup' => $form_popup
    );
    $form['md_structure_settings']['design']['info_contact']['markup'] = array(
      '#type' => 'markup',
      '#markup' => $markup,
    );
  }
  else{
    $form['md_structure_settings']['design']['info_contact']['markup'] = array(
      '#type' => 'markup',
      '#markup' => '<div>You need enable module Icon</div>',
    );
  }


  /////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////// Footer & Copyright ////////////////////
  /////////////////////////////////////////////////////////////////////////////
  $form['md_structure_settings']['design']['contact'] = array(
    '#type' => 'fieldset',
    '#weight' => 1,
    '#prefix' => '<div id="ds-contact"><div class="md-tabcontent-row">',
    '#suffix' => '    </div></div><!-- / #ds-general -->',
  );
  $form['md_structure_settings']['design']['contact']['footer_columns'] = array(
      '#type'          => 'select',
      '#default_value' => theme_get_setting('footer_columns') ? theme_get_setting('footer_columns') : '4',
      '#options'       => array(
          '12'         => t('1 column'),
          '6'          => t('2 columns'),
          '4'          => t('3 columns'),
          '3'          => t('4 columns'),
      ),
      '#attributes'           => array(
          'class'             => array('select')
      ),
      '#prefix'                     => '<h3 class="md-tabcontent-title">Footer columns</h3><div class="form-group">',
      '#suffix'                     => '</div>',
      '#field_prefix'               => '<div class="md-selection medium">',
      '#field_suffix'               => '</div>'
  );
  $form['md_structure_settings']['design']['contact']['footer_info'] = array(
    '#type' => 'textarea',
    '#title' => t('Footer information'),
    '#default_value' => theme_get_setting('footer_info'),
    '#attributes' => array(
      'class' => array('input-border')
    ),
  );
  $form['md_structure_settings']['design']['contact']['info_text'] = array(
    '#type' => 'textfield',
    '#format' => 'full_html',
    '#title' => t('Copyright'),
    '#default_value' => theme_get_setting('info_text'),
    '#attributes' => array(
      'class' => array('input-border big')
    ),
  );
  //FOOTER IMAGE SETTINGS
  $form['md_structure_settings']['design']['contact']['footer_image'] = array(
    '#type' => 'container',
  );
  _build_form_upload_file($form['md_structure_settings']['design']['contact']['footer_image'],'ft_image','Footer Image');

}