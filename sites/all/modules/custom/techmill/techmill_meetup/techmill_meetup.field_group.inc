<?php
/**
 * @file
 * techmill_meetup.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function techmill_meetup_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meetup_venue|node|meetup|default';
  $field_group->group_name = 'group_meetup_venue';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'meetup';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Venue',
    'weight' => '4',
    'children' => array(
      0 => 'field_meetup_venue_name',
      1 => 'field_meetup_address_street',
      2 => 'field_meetup_address_city_state',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Venue',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-meetup-venue field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_meetup_venue|node|meetup|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meetup_venue|node|meetup|form';
  $field_group->group_name = 'group_meetup_venue';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'meetup';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Venue',
    'weight' => '48',
    'children' => array(
      0 => 'field_meetup_venue_name',
      1 => 'field_meetup_address_street',
      2 => 'field_meetup_address_city_state',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-meetup-venue field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_meetup_venue|node|meetup|form'] = $field_group;

  return $export;
}
