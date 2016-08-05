<?php
/**
 * @file
 * techmill_coworkers.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function techmill_coworkers_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_coworking_social|node|coworking_member|form';
  $field_group->group_name = 'group_coworking_social';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'coworking_member';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Media',
    'weight' => '7',
    'children' => array(
      0 => 'field_coworking_twitter',
      1 => 'field_coworking_facebook',
      2 => 'field_coworking_linkedin',
      3 => 'field_coworking_github',
      4 => 'field_coworking_youtube',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-coworking-social field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_coworking_social|node|coworking_member|form'] = $field_group;

  return $export;
}
