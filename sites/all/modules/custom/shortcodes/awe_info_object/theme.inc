<?php

/**
 * Implement hook_preprocess_awe_info()
 */
function awe_info_object_preprocess_awe_info(&$vars) {
  $module_path = drupal_get_path('module', 'awe_info_object');
  drupal_add_css($module_path . '/awecontent-info-item.css');
  $settings = $vars['settings'];
  $vars['src_img'] = 'http://placehold.it/100x100';
  if ($settings['fid'] != -1){
    $file = file_load($settings['fid']);
    if (isset($file->uri)){
      $src_img = $settings['styleImage'] != 'none'
        ? image_style_url($settings['styleImage'], $file->uri)
        : file_create_url($file->uri);
      $vars['src_img'] = $src_img;
    }
  }

  $info['title']['css'] = "";
  if (isset($settings['fontFamilyTitle']))
    $info['title']['css'] .= "font-family: $settings[fontFamilyTitle];";
  if (isset($settings['fontSizeTitle']))
    $info['title']['css'] .= "font-size: $settings[fontSizeTitle]px;";
  if (isset($settings['lineHeightTitle']))
    $info['title']['css'] .= "line-height: $settings[lineHeightTitle]px;";
  if(isset($settings['letterSpacingTitle']))
    $info['title']['css'] .= "letter-spacing: $settings[letterSpacingTitle]px;";
  if (isset($settings['fontStyleTitle'])&& !empty($settings['fontStyleTitle'])) {
      $fontStyleTitle = json_decode($settings['fontStyleTitle']);
      foreach ($fontStyleTitle as $key => $value) {
          $info['title']['css'] .= "$key:$value;";
      }
  }

  $info['description']['css'] = "";
  if (isset($settings['fontFamilyDescription']))
    $info['description']['css'] .= "font-family:$settings[fontFamilyDescription];";
  if (isset($settings['fontSizeDescription']))
    $info['description']['css'] .= "font-size:$settings[fontSizeDescription]px;";
  if (isset($settings['lineHeightDescription']))
    $info['description']['css'] .= "line-height: $settings[lineHeightDescription]px;";
  if (isset($settings['letterSpacingDescription']))
    $info['description']['css'] .= "letter-spacing: $settings[letterSpacingDescription]px;";
  if(isset($settings['fontStyleDescription']) && !empty($settings['fontStyleDescription'])){
      $fontStyleDescription = json_decode($settings['fontStyleDescription']);
      foreach ($fontStyleDescription as $key=>$value){
          $info['description']['css'] .= "$key:$value;";
      }
  }

  $info_id = $settings['customID'];
  $vars['id'] = $info_id;
  $info_class = empty($settings['customClass']) ? $vars['class_random'] : $settings['customClass'];
  $node_style = _ac_render_item_id_tag($info_id, $info_class, $vars['class_random']);
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

  $color_settings = array(
    'color' => $settings['color'],
  );
  $color = _ac_render_item_hover_settings($color_settings);

  $responsive != '' ? " ".$responsive : '';
  $class = $responsive;

  $vars['classes_array'] = array('awe-item', 'item-info', $vars['class_random']);
  if ($info_class != ''){
    $vars['classes_array'][] = $info_class;
  }

  if ($responsive != '') {
    $vars['classes_array'][] = $responsive;
  }
  $vars['attributes_array'] = array_merge($vars['attributes_array'], $attributes);
  $animations !== '' ? $vars['attributes_array']['data-animation'] = $animations : '';

  $style = render_css($node_style, array($boxModel, $color['normal']));
  $id_class = empty($info_id)?".$info_class":"#$info_id";

  $style .="$id_class h4 {" . $info['title']['css'] . "}";
  $style .="$id_class .info-desc {" . $info['description']['css'] . "}";

  if(isset($settings['title_color'])) {
    $style .="$id_class h4.info-box-title {color:$settings[title_color];}";
  }
  if(isset($settings['buttonColor'])) {
    $style .="$id_class .btn-base {color:$settings[buttonColor]; border-color:$settings[buttonColor];}";
    $style .="$id_class .btn-effect:before {border-color:$settings[buttonColor];}";
  }
  if(isset($settings['buttonHoverColor'])) {
    $style .="$id_class .btn-base:hover {color:$settings[buttonHoverColor]; border-color:$settings[buttonHoverColor];}";
    $style .="$id_class .btn-effect:after {border-color:$settings[buttonHoverColor];}";
  }
  if(isset($settings['titleHoverColor'])) {
    $style .="$id_class .overlay-title {color:$settings[titleHoverColor];}";
  }
  if(isset($settings['textHoverColor'])) {
    $style .="$id_class .overlay-text {color:$settings[textHoverColor];}";
  }
  if(isset($settings['bgHoverColor'])) {
    $style .="$id_class .box-overlay2, $id_class .box-overlay {background-color:$settings[bgHoverColor];}";
  }

  drupal_add_css( $style, array('type' => 'inline', 'group' => CSS_THEME));
}