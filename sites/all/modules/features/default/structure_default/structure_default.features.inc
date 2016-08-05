<?php
/**
 * @file
 * structure_default.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function structure_default_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "taxonomy_display" && $api == "taxonomy_display") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function structure_default_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function structure_default_image_default_styles() {
  $styles = array();

  // Exported image style: author.
  $styles['author'] = array(
    'label' => 'Author(120x120)',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 120,
          'height' => 120,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: gallery_thumb.
  $styles['gallery_thumb'] = array(
    'label' => 'Gallery Thumb',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 163,
          'height' => 86,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: info_1.
  $styles['info_1'] = array(
    'label' => 'Info(360x220)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 360,
          'height' => 220,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: md_slider_2_thumb.
  $styles['md_slider_2_thumb'] = array(
    'label' => 'md_slider_2_thumb',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 75,
          'scaleup' => FALSE,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: md_slider_3_thumb.
  $styles['md_slider_3_thumb'] = array(
    'label' => 'md_slider_3_thumb',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 75,
          'scaleup' => FALSE,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: portfolio_1.
  $styles['portfolio_1'] = array(
    'label' => 'Portfolio(480x410)',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 410,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: portfolio_2.
  $styles['portfolio_2'] = array(
    'label' => 'Portfolio(270x231)',
    'effects' => array(
      9 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 270,
          'height' => 231,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: recent_post.
  $styles['recent_post'] = array(
    'label' => 'Recent Post(80x60)',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 80,
          'height' => 60,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: slide_thumb.
  $styles['slide_thumb'] = array(
    'label' => 'Slide Thumb',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 163,
          'height' => 86,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_install().
 */
function structure_default_install() {
$sliders = array(
  1 => array(
    'slid' => 1,
    'title' => 'Home Slider 1',
    'description' => '',
    'machine_name' => 'home-slider-1',
    'settings' => 'a:32:{s:10:"full_width";i:1;s:5:"width";s:4:"1940";s:6:"height";s:3:"600";s:11:"touch_swipe";i:1;s:10:"responsive";i:1;s:8:"videobox";i:0;s:4:"loop";i:1;s:10:"loadingbar";s:4:"none";s:12:"bar_position";s:6:"bottom";s:21:"show_next_prev_button";i:1;s:9:"auto_play";i:1;s:11:"pause_hover";i:0;s:11:"show_bullet";i:0;s:15:"bullet_position";s:1:"5";s:14:"show_thumbnail";i:0;s:18:"thumbnail_position";s:1:"1";s:12:"border_style";s:1:"0";s:16:"dropshadow_style";s:1:"0";s:9:"animation";s:4:"fade";s:5:"delay";s:4:"8000";s:9:"transtime";s:3:"800";s:11:"thumb_width";s:3:"100";s:12:"thumb_height";s:2:"75";s:18:"create_bg_imgstyle";i:0;s:10:"dmf_google";s:57:"http://fonts.googleapis.com/css?family=Montserrat:400,700";s:15:"enable_font_css";i:0;s:17:"generate_css_file";i:0;s:8:"on_start";s:0:"";s:6:"on_end";s:0:"";s:11:"color_saved";s:13:"ff9900,CC0000";s:13:"device_enable";i:0;s:12:"device_width";s:3:"460";}',
  ),
  3 => array(
    'slid' => 3,
    'title' => 'Home Slider 2',
    'description' => '',
    'machine_name' => 'md-slider-565fe6da8ed24',
    'settings' => 'a:32:{s:10:"full_width";i:1;s:5:"width";s:4:"1940";s:6:"height";s:3:"600";s:11:"touch_swipe";i:1;s:10:"responsive";i:1;s:8:"videobox";i:0;s:4:"loop";i:1;s:10:"loadingbar";s:4:"none";s:12:"bar_position";s:6:"bottom";s:21:"show_next_prev_button";i:1;s:9:"auto_play";i:1;s:11:"pause_hover";i:0;s:11:"show_bullet";i:0;s:15:"bullet_position";s:1:"5";s:14:"show_thumbnail";i:0;s:18:"thumbnail_position";s:1:"1";s:12:"border_style";s:1:"0";s:16:"dropshadow_style";s:1:"0";s:9:"animation";s:4:"fade";s:5:"delay";s:4:"8000";s:9:"transtime";s:3:"800";s:11:"thumb_width";s:3:"100";s:12:"thumb_height";s:2:"75";s:18:"create_bg_imgstyle";i:0;s:10:"dmf_google";s:57:"http://fonts.googleapis.com/css?family=Montserrat:400,700";s:15:"enable_font_css";i:0;s:17:"generate_css_file";i:0;s:8:"on_start";s:0:"";s:6:"on_end";s:0:"";s:11:"color_saved";s:13:"ff9900,CC0000";s:13:"device_enable";i:0;s:12:"device_width";s:3:"460";}',
  ),
);
foreach ($sliders as $slider) {
	$slider = (object)$slider;
	$slider = _md_slider_recast('MDSlider',$slider);
	$slider->slid = NULL;

	if (!MDSlider::get_by_machine_name($slider->machine_name))
		$slider->save();
}
}

/**
 * Implements hook_node_info().
 */
function structure_default_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'portfolio' => array(
      'name' => t('Portfolio'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'simplenews' => array(
      'name' => t('Simplenews newsletter'),
      'base' => 'node_content',
      'description' => t('A newsletter issue to be sent to subscribed email addresses.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
