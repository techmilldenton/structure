<?php
/**
 * @file
 * techmill_image.flexslider_picture_optionset.inc
 */

/**
 * Implements hook_default_flexslider_picture_optionset().
 */
function techmill_image_default_flexslider_picture_optionset() {
  $export = array();

  $flexslider_picture_optionset = new stdClass();
  $flexslider_picture_optionset->disabled = FALSE; /* Edit this to true to make a default flexslider_picture_optionset disabled initially */
  $flexslider_picture_optionset->api_version = 1;
  $flexslider_picture_optionset->flexslider_optionset = 'default';
  $flexslider_picture_optionset->imagestyle_type = 'image_style';
  $flexslider_picture_optionset->mapping = '';
  $flexslider_picture_optionset->fallback = '';
  $export['default'] = $flexslider_picture_optionset;

  return $export;
}
