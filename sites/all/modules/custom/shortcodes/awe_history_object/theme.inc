<?php

/**
 * Implement hook_preprocess_awe_history()
 */
function awe_history_object_preprocess_awe_history(&$vars) {
  $module_path = drupal_get_path('module', 'awe_history_object');
  drupal_add_css($module_path . '/awecontent-history-item.css');
  $settings = $vars['settings'];
  $vars['src_img'] = 'http://placehold.it/55x34';
  if ($settings['fid'] != -1){
    $file = file_load($settings['fid']);
    if (isset($file->uri)){
      $src_img = $settings['styleImage'] != 'none'
        ? image_style_url($settings['styleImage'], $file->uri)
        : file_create_url($file->uri);
      $vars['src_img'] = $src_img;
    }
  }

  $history['title']['css']="";
  if(isset($settings['fontFamilyTitle']))
    $history['title']['css'] .="font-family:$settings[fontFamilyTitle];";
  if(isset($settings['fontSizeTitle']))
    $history['title']['css'] .="font-size:$settings[fontSizeTitle]px;";
  if(isset($settings['lineHeightTitle']))
    $history['title']['css'] .="line-height:$settings[lineHeightTitle]px;";
  if(isset($settings['letterSpacingTitle']))
    $history['title']['css'] .="letter-spacing:$settings[letterSpacingTitle]px;";
  if(isset($settings['fontStyleTitle'])&& !empty($settings['fontStyleTitle'])){
      $fontStyleTitle = json_decode($settings['fontStyleTitle']);
      foreach($fontStyleTitle as $key=>$value){
          $history['title']['css'] .="$key:$value;";
      }
  }

  $history['desc']['css']="";
  if(isset($settings['fontFamilyDesc']))
    $history['desc']['css'] .="font-family:$settings[fontFamilyDesc];";
  if(isset($settings['fontSizeDesc']))
    $history['desc']['css'] .="font-size:$settings[fontSizeDesc]px;";
  if(isset($settings['lineHeightDesc']))
    $history['desc']['css'] .="line-height:$settings[lineHeightDesc]px;";
  if(isset($settings['letterSpacingDesc']))
    $history['desc']['css'] .="letter-spacing:$settings[letterSpacingDesc]px;";
  if(isset($settings['fontStyleDesc'])&& !empty($settings['fontStyleDesc'])){
      $fontStyleDesc= json_decode($settings['fontStyleDesc']);
      foreach($fontStyleDesc as $key=>$value){
          $history['desc']['css'] .="$key:$value;";
      }
  }

  
  $history_id = $settings['customID'] != '' ? drupal_html_id($settings['customID']) : FALSE;
  $vars['id'] = $history_id;
  $history_class = $settings['customClass'];
  $node_style = _ac_render_item_id_tag($history_id, $history_class, $vars['class_random']);
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

  $vars['classes_array'] = array('awe-history', $vars['class_random']);
  if ($history_class != ''){
    $vars['classes_array'][] = $history_class;
  }
  if ($responsive != '') {
    $vars['classes_array'][] = $responsive;
  }
  $vars['attributes_array'] = array_merge($vars['attributes_array'], $attributes);
  $animations !== '' ? $vars['attributes_array']['data-animation'] = $animations : '';

  $style = render_css($node_style, array($boxModel));

  $style .=".history-item h5 {{$history['title']['css']}}";
  $style .=".history-item .info-desc{{$history['desc']['css']}}";
  if(isset($settings['title_color'])) {
    $style .=".history-item h5 span.title {color:$settings[title_color];}";
  }
  if(isset($settings['year_color'])) {
    $style .=".history-item h5 span.year {color:$settings[year_color];}";
  }
  if(isset($settings['color'])) {
    $style .=".history-item .info-desc {color:$settings[color];}";
  }

  drupal_add_css( $style, array('type' => 'inline', 'group' => CSS_THEME));
}