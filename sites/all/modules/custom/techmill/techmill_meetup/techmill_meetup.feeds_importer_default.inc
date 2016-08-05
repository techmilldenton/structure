<?php
/**
 * @file
 * techmill_meetup.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function techmill_meetup_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'meetup';
  $feeds_importer->config = array(
    'name' => 'Meetup',
    'description' => 'Import events via Meetup',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsMeetupEventParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '2592000',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'event_url',
            'target' => 'field_event_url:url',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'lat',
            'target' => 'field_meetup_geofield:lat',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'lon',
            'target' => 'field_meetup_geofield:lon',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'id',
            'target' => 'guid',
            'unique' => 1,
          ),
          6 => array(
            'source' => 'event_datetime',
            'target' => 'field_meetup_date:start',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'venue_name',
            'target' => 'field_meetup_venue_name',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'address_1',
            'target' => 'field_meetup_address_street',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'address_2',
            'target' => 'field_meetup_address_street',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'city',
            'target' => 'field_meetup_address_city_state',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'state',
            'target' => 'field_meetup_address_city_state',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'zip',
            'target' => 'field_meetup_address_city_state',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'advanced_html',
        'skip_hash_check' => 0,
        'bundle' => 'meetup',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '604800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 1,
  );
  $export['meetup'] = $feeds_importer;

  return $export;
}
