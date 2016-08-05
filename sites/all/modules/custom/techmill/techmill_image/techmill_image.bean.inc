<?php
/**
 * @file
 * techmill_image.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function techmill_image_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'image_block';
  $bean_type->label = 'Image Block';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['image_block'] = $bean_type;

  return $export;
}
