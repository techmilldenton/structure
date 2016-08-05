<?php
/**
 * @file
 * techmill_image.default_breakpoints.inc
 */

/**
 * Implements hook_default_breakpoints().
 */
function techmill_image_default_breakpoints() {
  $export = array();

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.lg';
  $breakpoint->name = 'lg';
  $breakpoint->breakpoint = '(min-width: 1200px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 3;
  $breakpoint->multipliers = array(
    '2x' => '2x',
    '1x' => '1x',
  );
  $export['custom.user.lg'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.md';
  $breakpoint->name = 'md';
  $breakpoint->breakpoint = '(min-width: 992px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 5;
  $breakpoint->multipliers = array(
    '2x' => '2x',
    '1x' => '1x',
  );
  $export['custom.user.md'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.sm';
  $breakpoint->name = 'sm';
  $breakpoint->breakpoint = '(min-width: 768px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 7;
  $breakpoint->multipliers = array(
    '2x' => '2x',
    '1x' => '1x',
  );
  $export['custom.user.sm'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.xs';
  $breakpoint->name = 'xs';
  $breakpoint->breakpoint = '(max-width: 767px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 9;
  $breakpoint->multipliers = array(
    '2x' => '2x',
    '1x' => '1x',
  );
  $export['custom.user.xs'] = $breakpoint;

  return $export;
}
