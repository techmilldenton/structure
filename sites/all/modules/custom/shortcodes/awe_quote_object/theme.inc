<?php

/**
 * Implement hook_preprocess_awe_quote()
 */
function awe_quote_object_preprocess_awe_quote(&$vars) {
  $module_path = drupal_get_path('module', 'awe_quote_object');
  drupal_add_css($module_path . '/awecontent-quote-item.css');
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

  $quote['title']['css']="";
  if(isset($settings['fontFamilyTitle']))
    $quote['title']['css'] .="font-family:$settings[fontFamilyTitle];";
  if(isset($settings['fontSizeTitle']))
    $quote['title']['css'] .="font-size:$settings[fontSizeTitle]px;";
  if(isset($settings['lineHeightTitle']))
    $quote['title']['css'] .="line-height:$settings[lineHeightTitle]px;";
  if(isset($settings['letterSpacingTitle']))
    $quote['title']['css'] .="letter-spacing:$settings[letterSpacingTitle]px;";
  if(isset($settings['fontStyleTitle'])&& !empty($settings['fontStyleTitle'])){
      $fontStyleTitle = json_decode($settings['fontStyleTitle']);
      foreach($fontStyleTitle as $key=>$value){
          $quote['title']['css'] .="$key:$value;";
      }
  }

  $quote['desc']['css']="";
  if(isset($settings['fontFamilyDesc']))
    $quote['desc']['css'] .="font-family:$settings[fontFamilyDesc];";
  if(isset($settings['fontSizeDesc']))
    $quote['desc']['css'] .="font-size:$settings[fontSizeDesc]px;";
  if(isset($settings['lineHeightDesc']))
    $quote['desc']['css'] .="line-height:$settings[lineHeightDesc]px;";
  if(isset($settings['letterSpacingDesc']))
    $quote['desc']['css'] .="letter-spacing:$settings[letterSpacingDesc]px;";
  if(isset($settings['fontStyleDesc'])&& !empty($settings['fontStyleDesc'])){
      $fontStyleDesc= json_decode($settings['fontStyleDesc']);
      foreach($fontStyleDesc as $key=>$value){
          $quote['desc']['css'] .="$key:$value;";
      }
  }

  $quote['pos']['css']="";
  if(isset($settings['fontFamilyPos']))
    $quote['pos']['css'] .="font-family:$settings[fontFamilyPos];";
  if(isset($settings['fontSizePos']))
    $quote['pos']['css'] .="font-size:$settings[fontSizePos]px;";
  if(isset($settings['lineHeightPos']))
    $quote['pos']['css'] .="line-height:$settings[lineHeightPos]px;";
  if(isset($settings['letterSpacingPos']))
    $quote['pos']['css'] .="letter-spacing:$settings[letterSpacingPos]px;";
  if(isset($settings['fontStylePos'])&& !empty($settings['fontStylePos'])){
      $fontStylePos= json_decode($settings['fontStylePos']);
      foreach($fontStylePos as $key=>$value){
          $quote['pos']['css'] .="$key:$value;";
      }
  }

  
  $quote_id = $settings['customID'] != '' ? drupal_html_id($settings['customID']) : FALSE;
  $vars['id'] = $quote_id;
  $quote_class = empty($settings['customClass']) ? $vars['class_random'] : $settings['customClass'];
  $node_style = _ac_render_item_id_tag($quote_id, $quote_class, $vars['class_random']);
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

  $vars['classes_array'] = array('awe-quote', $vars['class_random']);
  if ($quote_class != ''){
    $vars['classes_array'][] = $quote_class;
  }
  if ($responsive != '') {
    $vars['classes_array'][] = $responsive;
  }
  $vars['attributes_array'] = array_merge($vars['attributes_array'], $attributes);
  $animations !== '' ? $vars['attributes_array']['data-animation'] = $animations : '';

  $id_class = empty($quote_id)?".$quote_class":"#$quote_id";

  $style = render_css($node_style, array($boxModel));

  $style .="$id_class h4 {{$quote['title']['css']}}";
  $style .="$id_class .info-desc{{$quote['desc']['css']}}";
  $style .="$id_class .position{{$quote['pos']['css']}}";
  if(isset($settings['title_color'])) {
    $style .="$id_class h4 {color:$settings[title_color];}";
  }
  if(isset($settings['color'])) {
    $style .="$id_class .info-desc {color:$settings[color];}";
  }
  if(isset($settings['pos_color'])) {
    $style .="$id_class .position {color:$settings[pos_color];}";
  }

  drupal_add_css( $style, array('type' => 'inline', 'group' => CSS_THEME));
}