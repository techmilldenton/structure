<?php
/**
 * @file
 * techmill_image.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function techmill_image_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Default';
  $picture_mapping->machine_name = 'default';
  $picture_mapping->breakpoint_group = 'default';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '975x650',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '720x480',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '525x350',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '375x250',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
  );
  $export['default'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Default Mini';
  $picture_mapping->machine_name = 'default_mini';
  $picture_mapping->breakpoint_group = 'default';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '720x480',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '525x350',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '375x250',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '375x250',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
  );
  $export['default_mini'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Slideshow Default';
  $picture_mapping->machine_name = 'slideshow_default';
  $picture_mapping->breakpoint_group = 'slideshow';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '1200xh',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '1000xh',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '800xh',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '600xh',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
  );
  $export['slideshow_default'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Slideshow Thin';
  $picture_mapping->machine_name = 'slideshow_thin';
  $picture_mapping->breakpoint_group = 'slideshow';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '1200x400',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '1000x600',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '800x480',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '600x360',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
  );
  $export['slideshow_thin'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Slideshow Wide';
  $picture_mapping->machine_name = 'slideshow_wide';
  $picture_mapping->breakpoint_group = 'slideshow';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '1200x600',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '1000x500',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '800x400',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '600x300',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
  );
  $export['slideshow_wide'] = $picture_mapping;

  return $export;
}
