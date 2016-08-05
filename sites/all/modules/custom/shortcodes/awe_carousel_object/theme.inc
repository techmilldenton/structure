<?php

/**
 * Implement hook_preprocess_awe_carousel()
 * @param $vars
 */
function awe_carousel_object_preprocess_awe_carousel(&$vars) {
  drupal_add_js(drupal_get_path('module', 'awe_carousel_object') . '/carousel.js');
  $style = '';
  $settings = $vars['settings'];
  $data_carousel['data-items'] = $settings['items'];
  $data_carousel['data-responsive'] = $settings['itemsResponsive'];
  if ($data_carousel['data-responsive']) {
    $data_carousel['data-items-desktop-small'] = $settings['itemsDesktopSmall'];
    $data_carousel['data-items-tablet'] = $settings['itemsTablet'];
    $data_carousel['data-items-mobile'] = $settings['itemsMobile'];
    $data_carousel['data-items-mobile'] = $settings['itemsMobile'];
  }
  $data_carousel['data-auto'] = $settings['autoPlay'];
  if ($data_carousel['data-auto']) {
    $data_carousel['data-time-auto'] = $settings['timeAutoPlay'];
    $data_carousel['data-stop-on-hover'] = $settings['stopOnHover'] ? 'true' : 'false';
  }
  $data_carousel['data-navigation'] = $settings['navigation']  ? 'true' : 'false';
  $data_carousel['data-pagination'] = $settings['pagination'] ? 'true' : 'false';
  !$settings['mouseDrag'] ? $data_carousel['data-mousedrag'] = 'false' : '';
  !$settings['touchDrag'] ? $data_carousel['data-touchdrag'] = 'false' : '';
  $data_carousel['data-items'] == 1 ? $data_carousel['data-effect'] = $settings['effect'] : '';

  $slides = $settings['slides'];
  unset($slides[count($slides) -1]);
  foreach ($slides as $key_slide => $slide) {
    $slides['content'][] = _awecontent_preprocess_columns($slide['content'], $vars['class_random'], $vars['node']);
  }
  $vars['slides'] = $slides;
  $vars['classes_array'] = array('awe-item', 'awe-carousel');
  $navigation_style = $settings['navigation'] ? " ".$settings['navigationStyle'] : '';
  $pagination_style = $settings['pagination'] ? " ".$settings['paginationStyle'] : '';

  $slides_id = $settings['customID'] != '' ? drupal_html_id($settings['customID']) : FALSE;
  $vars['id'] = $slides_id;
  $slides_class = $settings['customClass'];
  $attributes = array(
    'enable' => $settings['customEnableAttributes'],
    'attributes' => $settings['customDataAttributes']
  );

  $animations = array(
    'enable' => $settings['customEnableAnimations'],
    'animations' => $settings['customDataAnimations']
  );
  $responsive = array(
    'lgResponsive' => $settings['lgResponsive'],
    'xsResponsive' => $settings['xsResponsive'],
    'mediumResponsive' => $settings['mediumResponsive'],
    'smResponsive' => $settings['smResponsive']
  );
  $box_model = $settings['boxModelSettings'];
  $node_style = _ac_render_item_id_tag($slides_id, $slides_class, $vars['class_random']);

  $node_style = $node_style['result'];
  $attributes = _ac_render_item_attributes_settings($attributes);
  $animations = _ac_render_item_animations_settings($animations);
  $responsive = _ac_render_item_responsive_settings($responsive);
  $boxModel = _ac_render_item_box_model_settings($box_model);
  $responsive != '' ? " ".$responsive : '';
  $class = $slides_class .$navigation_style .$pagination_style . $responsive;

  $vars['classes_array'][] = $class;
  $vars['attributes_array'] = array_merge($vars['attributes_array'], $data_carousel, $attributes);
  $animations !== '' ? $vars['attributes_array']['data-animation'] = $animations : '';

  $style .= render_css($node_style, array($boxModel));

  drupal_add_css( $style, array('type' => 'inline', 'group' => CSS_THEME));
}