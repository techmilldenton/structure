<?php
/**
 * @file
 * structure_shop.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function structure_shop_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'banner';
  $bean_type->label = 'Banner';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['banner'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'contact_header';
  $bean_type->label = 'Contact Header';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['contact_header'] = $bean_type;

  return $export;
}
