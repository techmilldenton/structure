<?php
/**
 * @file
 * techmill_slider.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function techmill_slider_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overlay|field_collection_item|field_slideshow_slides|slideshow_normal';
  $field_group->group_name = 'group_overlay';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_slideshow_slides';
  $field_group->mode = 'slideshow_normal';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Overlay',
    'weight' => '1',
    'children' => array(
      0 => 'group_slide_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Overlay',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'overlay field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_overlay|field_collection_item|field_slideshow_slides|slideshow_normal'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overlay|field_collection_item|field_slideshow_slides|slideshow_thin';
  $field_group->group_name = 'group_overlay';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_slideshow_slides';
  $field_group->mode = 'slideshow_thin';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Overlay',
    'weight' => '1',
    'children' => array(
      0 => 'group_slide_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Overlay',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'overlay field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_overlay|field_collection_item|field_slideshow_slides|slideshow_thin'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overlay|field_collection_item|field_slideshow_slides|slideshow_wide';
  $field_group->group_name = 'group_overlay';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_slideshow_slides';
  $field_group->mode = 'slideshow_wide';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Overlay',
    'weight' => '1',
    'children' => array(
      0 => 'group_slide_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Overlay',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'overlay field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_overlay|field_collection_item|field_slideshow_slides|slideshow_wide'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_slide_caption|field_collection_item|field_slideshow_slides|default';
  $field_group->group_name = 'group_slide_caption';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_slideshow_slides';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption',
    'weight' => '1',
    'children' => array(
      0 => 'field_slide_title',
      1 => 'field_slide_description',
      2 => 'field_slide_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-slide-caption field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_slide_caption|field_collection_item|field_slideshow_slides|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_slide_caption|field_collection_item|field_slideshow_slides|slideshow_normal';
  $field_group->group_name = 'group_slide_caption';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_slideshow_slides';
  $field_group->mode = 'slideshow_normal';
  $field_group->parent_name = 'group_overlay';
  $field_group->data = array(
    'label' => 'Caption',
    'weight' => '2',
    'children' => array(
      0 => 'field_slide_title',
      1 => 'field_slide_description',
      2 => 'field_slide_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-slide-caption field-group-div container',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_slide_caption|field_collection_item|field_slideshow_slides|slideshow_normal'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_slide_caption|field_collection_item|field_slideshow_slides|slideshow_thin';
  $field_group->group_name = 'group_slide_caption';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_slideshow_slides';
  $field_group->mode = 'slideshow_thin';
  $field_group->parent_name = 'group_overlay';
  $field_group->data = array(
    'label' => 'Caption',
    'weight' => '2',
    'children' => array(
      0 => 'field_slide_title',
      1 => 'field_slide_description',
      2 => 'field_slide_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-slide-caption field-group-div container',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_slide_caption|field_collection_item|field_slideshow_slides|slideshow_thin'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_slide_caption|field_collection_item|field_slideshow_slides|slideshow_wide';
  $field_group->group_name = 'group_slide_caption';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_slideshow_slides';
  $field_group->mode = 'slideshow_wide';
  $field_group->parent_name = 'group_overlay';
  $field_group->data = array(
    'label' => 'Caption',
    'weight' => '2',
    'children' => array(
      0 => 'field_slide_title',
      1 => 'field_slide_description',
      2 => 'field_slide_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-slide-caption field-group-div container',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_slide_caption|field_collection_item|field_slideshow_slides|slideshow_wide'] = $field_group;

  return $export;
}
