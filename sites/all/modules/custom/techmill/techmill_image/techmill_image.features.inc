<?php
/**
 * @file
 * techmill_image.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function techmill_image_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  if ($module == "breakpoints" && $api == "default_breakpoints") {
    return array("version" => "1");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "flexslider_picture" && $api == "flexslider_picture_optionset") {
    return array("version" => "1");
  }
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function techmill_image_image_default_styles() {
  $styles = array();

  // Exported image style: 1000x250.
  $styles['1000x250'] = array(
    'label' => '1000x250',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1000,
          'height' => 250,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 1000x250_retina.
  $styles['1000x250_retina'] = array(
    'label' => '1000x250 Retina',
    'effects' => array(
      44 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1000,
          'height' => '',
          'upscale' => 1,
          'retinafy' => 1,
        ),
        'weight' => -10,
      ),
      45 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 1000,
          'height' => 250,
          'anchor' => 'center-center',
          'retinafy' => 1,
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: 1000x500.
  $styles['1000x500'] = array(
    'label' => '1000x500',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1000,
          'height' => 500,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 1000x500_retina.
  $styles['1000x500_retina'] = array(
    'label' => '1000x500 Retina',
    'effects' => array(
      21 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1000,
          'height' => '',
          'upscale' => 1,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
      22 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 1000,
          'height' => 500,
          'anchor' => 'center-center',
          'retinafy' => 1,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 1000x600.
  $styles['1000x600'] = array(
    'label' => '1000x600',
    'effects' => array(
      40 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1000,
          'height' => 600,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 1000x600_retina.
  $styles['1000x600_retina'] = array(
    'label' => '1000x600 Retina',
    'effects' => array(
      42 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1000,
          'height' => 600,
          'upscale' => 1,
          'retinafy' => 1,
        ),
        'weight' => -10,
      ),
      41 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1000,
          'height' => 600,
          'retinafy' => 1,
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: 1000xh.
  $styles['1000xh'] = array(
    'label' => '1000xH',
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1000,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 1000xh_retina.
  $styles['1000xh_retina'] = array(
    'label' => '1000xH Retina',
    'effects' => array(
      23 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1000,
          'height' => '',
          'upscale' => 1,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 1200x400.
  $styles['1200x400'] = array(
    'label' => '1200x400',
    'effects' => array(
      9 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 1200x400_retina.
  $styles['1200x400_retina'] = array(
    'label' => '1200x400 Retina',
    'effects' => array(
      42 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 400,
          'retinafy' => 1,
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: 1200x600.
  $styles['1200x600'] = array(
    'label' => '1200x600',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 600,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 1200x600_retina.
  $styles['1200x600_retina'] = array(
    'label' => '1200x600 Retina',
    'effects' => array(
      16 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1200,
          'height' => '',
          'upscale' => 1,
          'retinafy' => 0,
        ),
        'weight' => -10,
      ),
      20 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 1200,
          'height' => 600,
          'anchor' => 'center-center',
          'retinafy' => 1,
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: 1200xh.
  $styles['1200xh'] = array(
    'label' => '1200xH',
    'effects' => array(
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1200,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 1200xh_retina.
  $styles['1200xh_retina'] = array(
    'label' => '1200xH Retina',
    'effects' => array(
      26 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1200,
          'height' => '',
          'upscale' => 1,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 375x250.
  $styles['375x250'] = array(
    'label' => '375x250',
    'effects' => array(
      38 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 375,
          'height' => 250,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 525x350.
  $styles['525x350'] = array(
    'label' => '525x350',
    'effects' => array(
      14 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 525,
          'height' => 350,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 600x150.
  $styles['600x150'] = array(
    'label' => '600x150',
    'effects' => array(
      12 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 600,
          'height' => 150,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 600x150_retina.
  $styles['600x150_retina'] = array(
    'label' => '600x150 Retina',
    'effects' => array(
      27 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 600,
          'height' => '',
          'upscale' => 1,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
      28 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 600,
          'height' => 150,
          'anchor' => 'center-center',
          'retinafy' => 1,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 600x300.
  $styles['600x300'] = array(
    'label' => '600x300',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 600,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 600x300_retina.
  $styles['600x300_retina'] = array(
    'label' => '600x300 Retina',
    'effects' => array(
      29 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 600,
          'height' => '',
          'upscale' => 1,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
      30 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 600,
          'height' => 300,
          'anchor' => 'center-center',
          'retinafy' => 1,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 600x360.
  $styles['600x360'] = array(
    'label' => '600x360',
    'effects' => array(
      47 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 600,
          'height' => 360,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 600x360_retina.
  $styles['600x360_retina'] = array(
    'label' => '600x360 Retina',
    'effects' => array(
      49 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 600,
          'height' => 360,
          'upscale' => 1,
          'retinafy' => 1,
        ),
        'weight' => -10,
      ),
      48 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 600,
          'height' => 360,
          'retinafy' => 1,
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: 600xh.
  $styles['600xh'] = array(
    'label' => '600xH',
    'effects' => array(
      8 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 600,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 600xh_retina.
  $styles['600xh_retina'] = array(
    'label' => '600xH Retina',
    'effects' => array(
      31 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 600,
          'height' => '',
          'upscale' => 1,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 720x480.
  $styles['720x480'] = array(
    'label' => '720x480',
    'effects' => array(
      13 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 720,
          'height' => 480,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 800x200.
  $styles['800x200'] = array(
    'label' => '800x200',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 800x200_retina.
  $styles['800x200_retina'] = array(
    'label' => '800x200 Retina',
    'effects' => array(
      34 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 800,
          'height' => '',
          'upscale' => 1,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
      36 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 800,
          'height' => 200,
          'anchor' => 'center-center',
          'retinafy' => 1,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 800x400.
  $styles['800x400'] = array(
    'label' => '800x400',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 800x400_retina.
  $styles['800x400_retina'] = array(
    'label' => '800x400 Retina',
    'effects' => array(
      33 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 800,
          'height' => '',
          'upscale' => 1,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
      35 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 800,
          'height' => 400,
          'anchor' => 'center-center',
          'retinafy' => 1,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 800x480.
  $styles['800x480'] = array(
    'label' => '800x480',
    'effects' => array(
      44 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 480,
          'retinafy' => 0,
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: 800x480_retina.
  $styles['800x480_retina'] = array(
    'label' => '800x480 Retina',
    'effects' => array(
      45 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 800,
          'height' => 480,
          'upscale' => 1,
          'retinafy' => 1,
        ),
        'weight' => -10,
      ),
      46 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 480,
          'retinafy' => 1,
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: 800xh.
  $styles['800xh'] = array(
    'label' => '800xH',
    'effects' => array(
      7 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 800,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 800xh_retina.
  $styles['800xh_retina'] = array(
    'label' => '800xH Retina',
    'effects' => array(
      32 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 800,
          'height' => '',
          'upscale' => 1,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 975x650.
  $styles['975x650'] = array(
    'label' => '975x650',
    'effects' => array(
      37 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 975,
          'height' => 650,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: facebook_card.
  $styles['facebook_card'] = array(
    'label' => 'Facebook Card',
    'effects' => array(
      44 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 560,
          'height' => 292,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: large_square.
  $styles['large_square'] = array(
    'label' => 'Large Square (600x600)',
    'effects' => array(
      46 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 600,
          'height' => 600,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: medium_square_220x220.
  $styles['medium_square_220x220'] = array(
    'label' => 'Medium Square (220x220)',
    'effects' => array(
      39 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 220,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: twitter_card.
  $styles['twitter_card'] = array(
    'label' => 'Twitter Card',
    'effects' => array(
      45 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 560,
          'height' => 315,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: user_square.
  $styles['user_square'] = array(
    'label' => 'User Square',
    'effects' => array(
      43 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 250,
          'height' => 250,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
