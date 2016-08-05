<?php
/**
 * @file
 * techmill_meetup.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function techmill_meetup_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'meetup-address_2-rewrite';
  $feeds_tamper->importer = 'meetup';
  $feeds_tamper->source = 'address_2';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[address_1]
[address_2]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite Address';
  $export['meetup-address_2-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'meetup-zip-rewrite_city_meetup';
  $feeds_tamper->importer = 'meetup';
  $feeds_tamper->source = 'zip';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[city], [state] [zip]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite City Meetup';
  $export['meetup-zip-rewrite_city_meetup'] = $feeds_tamper;

  return $export;
}
