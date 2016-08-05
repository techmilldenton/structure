<?php
/**
 * @file
 * techmill_initiatives.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function techmill_initiatives_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overlay|node|initiative|initiative_tile';
  $field_group->group_name = 'group_overlay';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'initiative';
  $field_group->mode = 'initiative_tile';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Overlay',
    'weight' => '3',
    'children' => array(
      0 => 'body',
      1 => 'field_initiative_date',
      2 => 'overlay_title',
      3 => 'node_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Overlay',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-overlay overlay field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_overlay|node|initiative|initiative_tile'] = $field_group;

  return $export;
}
