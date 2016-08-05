<?php
/**
 * @file
 * techmill_image.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function techmill_image_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|image_block|default';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'image_block';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_image_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'image-title',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'h2',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => TRUE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_image_body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_image_img' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['bean|image_block|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|image_block|image_wide';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'image_block';
  $ds_fieldsetting->view_mode = 'image_wide';
  $ds_fieldsetting->settings = array(
    'field_image_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'image-title',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'h2',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_image_body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_image_img' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['bean|image_block|image_wide'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function techmill_image_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|image_block|default';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'image_block';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image_img',
        1 => 'field_image_title',
        2 => 'field_image_body',
      ),
    ),
    'fields' => array(
      'field_image_img' => 'ds_content',
      'field_image_title' => 'ds_content',
      'field_image_body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['bean|image_block|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|image_block|form';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'image_block';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'label',
        1 => 'title',
        2 => 'view_mode',
        3 => 'field_image_title',
        4 => 'field_image_body',
        5 => 'field_image_img',
      ),
      'hidden' => array(
        6 => 'revision',
        7 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'label' => 'ds_content',
      'title' => 'ds_content',
      'view_mode' => 'ds_content',
      'field_image_title' => 'ds_content',
      'field_image_body' => 'ds_content',
      'field_image_img' => 'ds_content',
      'revision' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['bean|image_block|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|image_block|image_wide';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'image_block';
  $ds_layout->view_mode = 'image_wide';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image_img',
        1 => 'group_image_caption',
        2 => 'field_image_title',
        3 => 'field_image_body',
      ),
    ),
    'fields' => array(
      'field_image_img' => 'ds_content',
      'group_image_caption' => 'ds_content',
      'field_image_title' => 'ds_content',
      'field_image_body' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['bean|image_block|image_wide'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function techmill_image_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'image_3_2_ratio';
  $ds_view_mode->label = 'Image: 3/2 Ratio';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['image_3_2_ratio'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'image_wide';
  $ds_view_mode->label = 'Image Wide';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
  );
  $export['image_wide'] = $ds_view_mode;

  return $export;
}
