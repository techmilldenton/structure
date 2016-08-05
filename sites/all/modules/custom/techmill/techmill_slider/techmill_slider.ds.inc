<?php
/**
 * @file
 * techmill_slider.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function techmill_slider_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|slideshow|default';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'slideshow';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_slideshow_slides' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['bean|slideshow|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|slideshow|slideshow_normal';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'slideshow';
  $ds_fieldsetting->view_mode = 'slideshow_normal';
  $ds_fieldsetting->settings = array(
    'field_slideshow_slides' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['bean|slideshow|slideshow_normal'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|slideshow|slideshow_thin';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'slideshow';
  $ds_fieldsetting->view_mode = 'slideshow_thin';
  $ds_fieldsetting->settings = array(
    'field_slideshow_slides' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['bean|slideshow|slideshow_thin'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|slideshow|slideshow_wide';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'slideshow';
  $ds_fieldsetting->view_mode = 'slideshow_wide';
  $ds_fieldsetting->settings = array(
    'field_slideshow_slides' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['bean|slideshow|slideshow_wide'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_slideshow_slides|default';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_slideshow_slides';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_slide_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'h2',
          'ow-cl' => '',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_slide_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_slide_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_slide_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['field_collection_item|field_slideshow_slides|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_slideshow_slides|slideshow_normal';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_slideshow_slides';
  $ds_fieldsetting->view_mode = 'slideshow_normal';
  $ds_fieldsetting->settings = array(
    'field_slide_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'h2',
          'ow-cl' => 'slide-title',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_slide_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'slide-desc',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_slide_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_slide_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['field_collection_item|field_slideshow_slides|slideshow_normal'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_slideshow_slides|slideshow_thin';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_slideshow_slides';
  $ds_fieldsetting->view_mode = 'slideshow_thin';
  $ds_fieldsetting->settings = array(
    'field_slide_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'h2',
          'ow-cl' => 'slide-title',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_slide_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'slide-desc',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_slide_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_slide_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['field_collection_item|field_slideshow_slides|slideshow_thin'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_slideshow_slides|slideshow_wide';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_slideshow_slides';
  $ds_fieldsetting->view_mode = 'slideshow_wide';
  $ds_fieldsetting->settings = array(
    'field_slide_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'h2',
          'ow-cl' => 'slide-title',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_slide_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'slide-desc',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_slide_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_slide_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['field_collection_item|field_slideshow_slides|slideshow_wide'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function techmill_slider_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|slideshow|default';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'slideshow';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_slideshow_slides',
      ),
    ),
    'fields' => array(
      'field_slideshow_slides' => 'ds_content',
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
  $export['bean|slideshow|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|slideshow|form';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'slideshow';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'label',
        1 => 'title',
        2 => 'view_mode',
        3 => 'field_slideshow_slides',
      ),
      'hidden' => array(
        4 => 'revision',
        5 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'label' => 'ds_content',
      'title' => 'ds_content',
      'view_mode' => 'ds_content',
      'field_slideshow_slides' => 'ds_content',
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
  $export['bean|slideshow|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|slideshow|slideshow_normal';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'slideshow';
  $ds_layout->view_mode = 'slideshow_normal';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_slideshow_slides',
      ),
    ),
    'fields' => array(
      'field_slideshow_slides' => 'ds_content',
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
  $export['bean|slideshow|slideshow_normal'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|slideshow|slideshow_thin';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'slideshow';
  $ds_layout->view_mode = 'slideshow_thin';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_slideshow_slides',
      ),
    ),
    'fields' => array(
      'field_slideshow_slides' => 'ds_content',
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
  $export['bean|slideshow|slideshow_thin'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|slideshow|slideshow_wide';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'slideshow';
  $ds_layout->view_mode = 'slideshow_wide';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_slideshow_slides',
      ),
    ),
    'fields' => array(
      'field_slideshow_slides' => 'ds_content',
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
  $export['bean|slideshow|slideshow_wide'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_slideshow_slides|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_slideshow_slides';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_slide_image',
        1 => 'group_slide_caption',
        2 => 'field_slide_title',
        3 => 'field_slide_description',
        4 => 'field_slide_link',
      ),
    ),
    'fields' => array(
      'field_slide_image' => 'ds_content',
      'group_slide_caption' => 'ds_content',
      'field_slide_title' => 'ds_content',
      'field_slide_description' => 'ds_content',
      'field_slide_link' => 'ds_content',
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
  $export['field_collection_item|field_slideshow_slides|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_slideshow_slides|slideshow_normal';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_slideshow_slides';
  $ds_layout->view_mode = 'slideshow_normal';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_slide_image',
        1 => 'group_overlay',
        2 => 'group_slide_caption',
        3 => 'field_slide_title',
        4 => 'field_slide_description',
        5 => 'field_slide_link',
      ),
    ),
    'fields' => array(
      'field_slide_image' => 'ds_content',
      'group_overlay' => 'ds_content',
      'group_slide_caption' => 'ds_content',
      'field_slide_title' => 'ds_content',
      'field_slide_description' => 'ds_content',
      'field_slide_link' => 'ds_content',
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
  $export['field_collection_item|field_slideshow_slides|slideshow_normal'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_slideshow_slides|slideshow_thin';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_slideshow_slides';
  $ds_layout->view_mode = 'slideshow_thin';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_slide_image',
        1 => 'group_overlay',
        2 => 'group_slide_caption',
        3 => 'field_slide_title',
        4 => 'field_slide_description',
        5 => 'field_slide_link',
      ),
    ),
    'fields' => array(
      'field_slide_image' => 'ds_content',
      'group_overlay' => 'ds_content',
      'group_slide_caption' => 'ds_content',
      'field_slide_title' => 'ds_content',
      'field_slide_description' => 'ds_content',
      'field_slide_link' => 'ds_content',
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
  $export['field_collection_item|field_slideshow_slides|slideshow_thin'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_slideshow_slides|slideshow_wide';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_slideshow_slides';
  $ds_layout->view_mode = 'slideshow_wide';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_slide_image',
        1 => 'group_overlay',
        2 => 'group_slide_caption',
        3 => 'field_slide_title',
        4 => 'field_slide_description',
        5 => 'field_slide_link',
      ),
    ),
    'fields' => array(
      'field_slide_image' => 'ds_content',
      'group_overlay' => 'ds_content',
      'group_slide_caption' => 'ds_content',
      'field_slide_title' => 'ds_content',
      'field_slide_description' => 'ds_content',
      'field_slide_link' => 'ds_content',
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
  $export['field_collection_item|field_slideshow_slides|slideshow_wide'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function techmill_slider_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'slideshow_normal';
  $ds_view_mode->label = 'Slideshow Normal';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
    'field_collection_item' => 'field_collection_item',
  );
  $export['slideshow_normal'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'slideshow_thin';
  $ds_view_mode->label = 'Slideshow Thin';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
    'field_collection_item' => 'field_collection_item',
  );
  $export['slideshow_thin'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'slideshow_wide';
  $ds_view_mode->label = 'Slideshow Wide';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
    'field_collection_item' => 'field_collection_item',
  );
  $export['slideshow_wide'] = $ds_view_mode;

  return $export;
}
