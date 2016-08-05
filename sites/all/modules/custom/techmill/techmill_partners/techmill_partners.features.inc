<?php
/**
 * @file
 * techmill_partners.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function techmill_partners_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function techmill_partners_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function techmill_partners_node_info() {
  $items = array(
    'partner' => array(
      'name' => t('Partner'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
