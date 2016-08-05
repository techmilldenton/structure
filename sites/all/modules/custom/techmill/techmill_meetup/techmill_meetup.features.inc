<?php
/**
 * @file
 * techmill_meetup.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function techmill_meetup_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function techmill_meetup_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_date_custom_date_formats().
 */
function techmill_meetup_fe_date_custom_date_formats() {
  $custom_date_formats = array();
  $custom_date_formats['M j, Y - h:i a'] = 'M j, Y - h:i a';
  $custom_date_formats['Y-d-m'] = 'Y-d-m';
  return $custom_date_formats;
}

/**
 * Implements hook_date_format_types().
 */
function techmill_meetup_date_format_types() {
  $format_types = array();
  // Exported date format type: meetup_time
  $format_types['meetup_time'] = 'Meetup Time';
  // Exported date format type: url_date
  $format_types['url_date'] = 'URL Date';
  return $format_types;
}

/**
 * Implements hook_node_info().
 */
function techmill_meetup_node_info() {
  $items = array(
    'meetup' => array(
      'name' => t('Meetup'),
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
