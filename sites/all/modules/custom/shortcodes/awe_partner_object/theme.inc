<?php

/**
 * Implement hook_preprocess_awe_partner()
 */
function awe_partner_object_preprocess_awe_partner(&$vars) {
  $module_path = drupal_get_path('module', 'awe_partner_object');
  drupal_add_css($module_path . '/awecontent-partner-item.css');
  $settings = $vars['settings'];

  $partner['title']['css']="";
  if(isset($settings['fontFamilyTitle']))
    $partner['title']['css'] .="font-family:$settings[fontFamilyTitle];";
  if(isset($settings['fontSizeTitle']))
    $partner['title']['css'] .="font-size:$settings[fontSizeTitle]px;";
  if(isset($settings['lineHeightTitle']))
    $partner['title']['css'] .="line-height:$settings[lineHeightTitle]px;";
  if(isset($settings['letterSpacingTitle']))
    $partner['title']['css'] .="letter-spacing:$settings[letterSpacingTitle]px;";
  if(isset($settings['fontStyleTitle'])&& !empty($settings['fontStyleTitle'])){
      $fontStyleTitle = json_decode($settings['fontStyleTitle']);
      foreach($fontStyleTitle as $key=>$value){
          $partner['title']['css'] .="$key:$value;";
      }
  }

  $partner['desc']['css']="";
  if(isset($settings['fontFamilyDesc']))
    $partner['desc']['css'] .="font-family:$settings[fontFamilyDesc];";
  if(isset($settings['fontSizeDesc']))
    $partner['desc']['css'] .="font-size:$settings[fontSizeDesc]px;";
  if(isset($settings['lineHeightDesc']))
    $partner['desc']['css'] .="line-height:$settings[lineHeightDesc]px;";
  if(isset($settings['letterSpacingDesc']))
    $partner['desc']['css'] .="letter-spacing:$settings[letterSpacingDesc]px;";
  if(isset($settings['fontStyleDesc'])&& !empty($settings['fontStyleDesc'])){
      $fontStyleDesc= json_decode($settings['fontStyleDesc']);
      foreach($fontStyleDesc as $key=>$value){
          $partner['desc']['css'] .="$key:$value;";
      }
  }

  
  $partner_id = $settings['customID'] != '' ? drupal_html_id($settings['customID']) : FALSE;
  $vars['id'] = $partner_id;
  $partner_class = empty($settings['customClass']) ? $vars['class_random'] : $settings['customClass'];
  $node_style = _ac_render_item_id_tag($partner_id, $partner_class, $vars['class_random']);
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

  $vars['classes_array'] = array('awe-partner', $vars['class_random']);
  if ($partner_class != ''){
    $vars['classes_array'][] = $partner_class;
  }
  if ($responsive != '') {
    $vars['classes_array'][] = $responsive;
  }
  $vars['attributes_array'] = array_merge($vars['attributes_array'], $attributes);
  $animations !== '' ? $vars['attributes_array']['data-animation'] = $animations : '';

  $id_class = empty($service_id)?".$partner_class":"#$partner_id";

  $style = render_css($node_style, array($boxModel));

  $style .="$id_class h3 {{$partner['title']['css']}}";
  $style .="$id_class .info-desc{{$partner['desc']['css']}}";
  if(isset($settings['title_color'])) {
    $style .="$id_class h3 {color:$settings[title_color];}";
  }
  if(isset($settings['color'])) {
    $style .="$id_class .info-desc {color:$settings[color];}";
  }
  if(isset($settings['iconColor'])) {
    $style .="$id_class .box-icon3 .box-image {color:$settings[iconColor];}";
  }
  if(isset($settings['iconHoverColor'])) {
    $style .="$id_class .box-icon3:hover .box-image {color:$settings[iconHoverColor] !important; border-color:$settings[iconHoverColor];}";
  }

  drupal_add_css( $style, array('type' => 'inline', 'group' => CSS_THEME));
}