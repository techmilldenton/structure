<?php
/**
 * @file
 * techmill_initiatives.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function techmill_initiatives_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|initiative|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'initiative';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h2',
        'class' => '',
        'exclude node title settings' => '1',
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
        'linked_field' => array(
          'linked' => 0,
          'destination' => '',
          'advanced' => array(
            'title' => '',
            'target' => '',
            'class' => '',
            'rel' => '',
            'text' => '',
          ),
        ),
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_initiative_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_initiative_date' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['node|initiative|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|initiative|initiative_tile';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'initiative';
  $ds_fieldsetting->view_mode = 'initiative_tile';
  $ds_fieldsetting->settings = array(
    'overlay_title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-cl' => 'overlay-title',
          'fi' => TRUE,
          'fi-el' => 'h4',
          'fi-cl' => 'overlay-title',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
        'linked_field' => array(
          'linked' => 0,
          'destination' => '',
          'advanced' => array(
            'title' => '',
            'target' => '',
            'class' => '',
            'rel' => '',
            'text' => '',
          ),
        ),
      ),
    ),
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => '',
        'exclude node title settings' => '0',
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
        'linked_field' => array(
          'linked' => 0,
          'destination' => '',
          'advanced' => array(
            'title' => '',
            'target' => '',
            'class' => '',
            'rel' => '',
            'text' => '',
          ),
        ),
      ),
    ),
    'node_link' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Read more',
        'wrapper' => '',
        'class' => 'btn btn-primary',
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
        'linked_field' => array(
          'linked' => 0,
          'destination' => '',
          'advanced' => array(
            'title' => '',
            'target' => '',
            'class' => '',
            'rel' => '',
            'text' => '',
          ),
        ),
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_initiative_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_initiative_date' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['node|initiative|initiative_tile'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function techmill_initiatives_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'overlay_title';
  $ds_field->label = 'Overlay Title';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'initiative|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[node:title]',
      'format' => 'plain_text',
    ),
    'use_token' => 1,
  );
  $export['overlay_title'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function techmill_initiatives_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|initiative|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'initiative';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_initiative_image',
        1 => 'title',
        2 => 'field_initiative_date',
        3 => 'body',
        4 => 'field_initiative_link',
      ),
    ),
    'fields' => array(
      'field_initiative_image' => 'ds_content',
      'title' => 'ds_content',
      'field_initiative_date' => 'ds_content',
      'body' => 'ds_content',
      'field_initiative_link' => 'ds_content',
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
  $export['node|initiative|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|initiative|initiative_tile';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'initiative';
  $ds_layout->view_mode = 'initiative_tile';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'overlay_title',
        1 => 'field_initiative_image',
        2 => 'field_initiative_date',
        3 => 'body',
        4 => 'title',
        5 => 'node_link',
        6 => 'group_overlay',
      ),
    ),
    'fields' => array(
      'overlay_title' => 'ds_content',
      'field_initiative_image' => 'ds_content',
      'field_initiative_date' => 'ds_content',
      'body' => 'ds_content',
      'title' => 'ds_content',
      'node_link' => 'ds_content',
      'group_overlay' => 'ds_content',
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
  $export['node|initiative|initiative_tile'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function techmill_initiatives_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'initiative_tile';
  $ds_view_mode->label = 'Initiative Tile';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['initiative_tile'] = $ds_view_mode;

  return $export;
}
