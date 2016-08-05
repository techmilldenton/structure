<?php
/**
 * @file
 * techmill_partners.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function techmill_partners_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|partner|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'partner';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h3',
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
    'field_partner_website' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_partner_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['node|partner|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function techmill_partners_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|partner|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'partner';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_partner_image',
        1 => 'title',
        2 => 'field_partner_website',
        3 => 'body',
      ),
    ),
    'fields' => array(
      'field_partner_image' => 'ds_content',
      'title' => 'ds_content',
      'field_partner_website' => 'ds_content',
      'body' => 'ds_content',
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
  $export['node|partner|teaser'] = $ds_layout;

  return $export;
}
