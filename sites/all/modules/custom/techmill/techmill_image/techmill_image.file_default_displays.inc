<?php
/**
 * @file
 * techmill_image.file_default_displays.inc
 */

/**
 * Implements hook_file_default_displays().
 */
function techmill_image_file_default_displays() {
  $export = array();

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__image_3_2_ratio__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__image_3_2_ratio__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__image_3_2_ratio__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['image__image_3_2_ratio__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__image_3_2_ratio__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__image_3_2_ratio__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__image_3_2_ratio__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__image_3_2_ratio__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__image_3_2_ratio__file_field_flexslider';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'optionset' => 'default',
    'image_style' => '',
    'caption' => 0,
  );
  $export['image__image_3_2_ratio__file_field_flexslider'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__image_3_2_ratio__file_field_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => '525x350',
    'image_link' => '',
  );
  $export['image__image_3_2_ratio__file_field_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__image_3_2_ratio__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__image_3_2_ratio__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__image_3_2_ratio__file_field_picture';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'picture_mapping' => 'slideshow_wide',
    'fallback_image_style' => '',
    'image_link' => '',
  );
  $export['image__image_3_2_ratio__file_field_picture'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__image_3_2_ratio__file_picture';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'picture_group' => 'slideshow_wide',
    'fallback_image_style' => '',
    'alt' => '',
    'title' => '',
  );
  $export['image__image_3_2_ratio__file_picture'] = $file_display;

  return $export;
}
