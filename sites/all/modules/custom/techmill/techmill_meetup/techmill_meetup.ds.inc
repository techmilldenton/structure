<?php
/**
 * @file
 * techmill_meetup.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function techmill_meetup_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|meetup|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'meetup';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'meetup_event_button' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
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
    'field_meetup_geofield' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_meetup_date' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_meetup_venue_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_meetup_address_street' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_meetup_address_city_state' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['node|meetup|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|meetup|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'meetup';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
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
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_meetup_date' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['node|meetup|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function techmill_meetup_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'meetup_event_button';
  $ds_field->label = 'Meetup Event Button';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'meetup|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a href="[node:field-event-url:url]" title="[node:title]" class="btn btn-primary btn-lg">RSVP for this Meetup</a>',
      'format' => 'advanced_html',
    ),
    'use_token' => 1,
  );
  $export['meetup_event_button'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function techmill_meetup_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|meetup|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'meetup';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_8_4';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'body',
        1 => 'field_meetup_date',
        2 => 'meetup_event_button',
      ),
      'right' => array(
        3 => 'field_meetup_geofield',
        4 => 'group_meetup_venue',
        5 => 'field_meetup_venue_name',
        6 => 'field_meetup_address_street',
        7 => 'field_meetup_address_city_state',
      ),
    ),
    'fields' => array(
      'body' => 'left',
      'field_meetup_date' => 'left',
      'meetup_event_button' => 'left',
      'field_meetup_geofield' => 'right',
      'group_meetup_venue' => 'right',
      'field_meetup_venue_name' => 'right',
      'field_meetup_address_street' => 'right',
      'field_meetup_address_city_state' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|meetup|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|meetup|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'meetup';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_meetup_date',
        2 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_meetup_date' => 'ds_content',
      'body' => 'ds_content',
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
  $export['node|meetup|teaser'] = $ds_layout;

  return $export;
}
