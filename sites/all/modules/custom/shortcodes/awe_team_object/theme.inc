<?php

/**
 * Implement hook_preprocess_awe_team()
 */
function awe_team_object_preprocess_awe_team(&$vars) {
  $module_path = drupal_get_path('module', 'awe_team_object');
  drupal_add_css($module_path . '/awecontent-team-item.css');
  $settings = $vars['settings'];
  $vars['src_img'] = 'http://placehold.it/363x462';
  if ($settings['fid'] != -1){
    $file = file_load($settings['fid']);
    if (isset($file->uri)){
      $src_img = $settings['styleImage'] != 'none'
        ? image_style_url($settings['styleImage'], $file->uri)
        : file_create_url($file->uri);
      $vars['src_img'] = $src_img;
    }
  }
  if ($settings['social'] != '') {
    $vars['socials'] = drupal_json_decode($settings['social']);
  }
  $team_id = $settings['customID'] != '' ? drupal_html_id($settings['customID']) : FALSE;
  $vars['id'] = $team_id;
  $team_class = $settings['customClass'];
  $node_style = _ac_render_item_id_tag($team_id, $team_class, $vars['class_random']);
  $node_style = $node_style['result'];

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

  $attributes = _ac_render_item_attributes_settings($attributes);
  $animations = _ac_render_item_animations_settings($animations);
  $responsive = _ac_render_item_responsive_settings($responsive);
  $boxModel = _ac_render_item_box_model_settings($box_model);

  /*$color_settings = array(
    'color' => $settings['color'],
    'background' => $settings['background_color'],
  );*/

  //$color = _ac_render_item_hover_settings($color_settings);
  $responsive != '' ? " ".$responsive : '';
  $class = $responsive;

  $vars['classes_array'] = array('awe-item', 'awe-team', $vars['class_random']);
  if ($team_class != ''){
    $vars['classes_array'][] = $team_class;
  }
  if ($responsive != '') {
    $vars['classes_array'][] = $responsive;
  }
  $vars['attributes_array'] = array_merge($vars['attributes_array'], $attributes);
  $animations !== '' ? $vars['attributes_array']['data-animation'] = $animations : '';

  $style = render_css($node_style, array($boxModel));
  drupal_add_css( $style, array('type' => 'inline', 'group' => CSS_THEME));
}