<?php

/**
 * Implement hook_preprocess_awe_client()
 * @param $vars
 */

function awe_client_object_preprocess_awe_client(&$vars) {
  $vars['classes_array'] = array('awe-item', 'awe-icon');
  $settings = $vars['settings'];
  //$name_client = $settings['styleClient'];
  $font_settings = array(
    'fontSize' => $settings['fontSize'],
    'lineHeight' => $settings['lineHeight'],
    'unit' => 'px'
  );
  //$style_client = $settings['styleClient'];
  $color_settings = array(
    'color' => $settings['color'],
    'hoverColor' => $settings['hoverColor']
  );
  $client_class = $settings['customClass'];
  $client_id = $settings['customID'] != '' ? drupal_html_id($settings['customID']) : FALSE;
  $vars['id'] = $client_id;
  $client_class = empty($settings['customClass']) ? $vars['class_random'] : $settings['customClass'];
  $box_model = $settings['boxModelSettings'];
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

  // process data for item client
  $node_style = _ac_render_item_id_tag($client_id, $client_class, $vars['class_random']);
  if ($node_style['isChange']) {
    $client_class = $node_style['isChange'];
  }
  $node_style = $node_style['result'] . '.awe-icon .awe-icon-container';
  $class = $client_class;
  $font_settings = _ac_render_item_font_settings($font_settings);
  $color_settings = _ac_render_item_hover_settings($color_settings);
  $box_model = _ac_render_item_box_model_settings($box_model);
  $attributes = _ac_render_item_attributes_settings($attributes);
  $animations = _ac_render_item_animations_settings($animations);
  $responsive = _ac_render_item_responsive_settings($responsive);
  $class .= $responsive;

  // set value for variable
  $vars['classes_array'][] = $class;
  $vars['attributes_array'] = array_merge($vars['attributes_array'], $attributes);
  $animations !== '' ? $vars['attributes_array']['data-animation'] = $animations : '';
  //$vars['name_client'] = $name_client;

  $id_class = empty($client_id)?".$client_class":"#$client_id";

  $style = render_css($node_style, array($font_settings, $color_settings['normal'], $box_model));
  $style .= render_css($node_style . ':hover', array($color_settings['hover']));

  $style .="$id_class .box-image {color:$settings[color]; } $id_class .box-image:hover { color:$settings[hoverColor]; border-color:$settings[hoverColor]; }";

  drupal_add_css(drupal_get_path('module', 'awe_client_object') . '/awecontent-client-item.css');
  drupal_add_css( $style, array('type' => 'inline', 'group' => CSS_THEME));
}