<?php

/**
 * Implement hook_preprocess_awe_service()
 * @param $vars
 */
function awe_service_object_preprocess_awe_service(&$vars) {
  $style = '';
  $settings = $vars['settings'];
  $service = array();
  $service['title']['value'] = $settings['title'];
  $service['description']['value'] = $settings['description'];

  $service['title']['css'] = "color:$settings[titleColor];";
  if (isset($settings['fontFamilyTitle']))
    $service['title']['css'] .= "font-family: $settings[fontFamilyTitle];";
  if (isset($settings['fontSizeTitle']))
    $service['title']['css'] .= "font-size: $settings[fontSizeTitle]px;";
  if (isset($settings['lineHeightTitle']))
    $service['title']['css'] .= "line-height: $settings[lineHeightTitle]px;";
  if(isset($settings['letterSpacingTitle']))
    $service['title']['css'] .= "letter-spacing: $settings[letterSpacingTitle]px;";
  if (isset($settings['fontStyleTitle'])&& !empty($settings['fontStyleTitle'])) {
      $fontStyleTitle = json_decode($settings['fontStyleTitle']);
      foreach ($fontStyleTitle as $key => $value) {
          $service['title']['css'] .= "$key:$value;";
      }
  }

  $service['description']['css'] = "color: $settings[sdescriptionColor];";
  if (isset($settings['fontFamilyDescription']))
    $service['description']['css'] .= "font-family:$settings[fontFamilyDescription];";
  if (isset($settings['fontSizeDescription']))
    $service['description']['css'] .= "font-size:$settings[fontSizeDescription]px;";
  if (isset($settings['lineHeightDescription']))
    $service['description']['css'] .= "line-height: $settings[lineHeightDescription]px;";
  if (isset($settings['letterSpacingDescription']))
    $service['description']['css'] .= "letter-spacing: $settings[letterSpacingDescription]px;";
  if(isset($settings['fontStyleDescription']) && !empty($settings['fontStyleDescription'])){
      $fontStyleDescription = json_decode($settings['fontStyleDescription']);
      foreach ($fontStyleDescription as $key=>$value){
          $service['description']['css'] .= "$key:$value;";
      }
  }


  $vars['service'] = $service;
  $service_id = $settings['customID'] != '' ? drupal_html_id($settings['customID']) : FALSE;
  $vars['id'] = $service_id;
  $service_class = empty($settings['customClass']) ? $vars['class_random'] : $settings['customClass'];
  $attributes = array(
    'enable' => $settings['customEnableAttributes'],
    'attributes' => $settings['customDataAttributes']
  );

  $animations = array(
    'enable' => $settings['customEnableAnimations'],
    'animations' => $settings['customDataAnimations']
  );

  $box_model = $settings['boxModelSettings'];
  $node_style = _ac_render_item_id_tag($service_id, $service_class, $vars['class_random']);

  $node_style = $node_style['result'];
  $attributes = _ac_render_item_attributes_settings($attributes);
  $animations = _ac_render_item_animations_settings($animations);
  $boxModel = _ac_render_item_box_model_settings($box_model);

  $class = $service_class;

  $vars['classes_array'][] = $class;
  $vars['attributes_array'] = array_merge($vars['attributes_array'], $attributes);
  $animations !== '' ? $vars['attributes_array']['data-animation'] = $animations : '';

  $style .= render_css($node_style, array($boxModel));

  $id_class = empty($service_id)?".$service_class":"#$service_id";
  $style .="$id_class {background-color:$settings[background_color];cursor: pointer;}$id_class:hover{background-color:$settings[hover_color] !important;}";

  $style .="$id_class .title {" . $service['title']['css'] . "}";
  $style .="$id_class p {" . $service['description']['css'] . "}";

  $style .="$id_class i {color:$settings[iconColor] !important;}";
  $style .="$id_class .box-image {border-color:$settings[iconColor];}";
  $style .="$id_class .style-4 .box-image {background-color:$settings[iconBgColor];}";
  $style .="$id_class .btn-base {color:$settings[buttonColor];}";
  $style .="$id_class .btn-base:hover {color:$settings[buttonHoverColor];}";
  $style .="$id_class .btn-effect:before {border-color:$settings[buttonColor];}";
  $style .="$id_class .btn-effect:after {border-color:$settings[buttonHoverColor];}";

  drupal_add_css(drupal_get_path('module', 'awe_service_object') . '/awecontent-service-item.css');
  drupal_add_css( $style, array('type' => 'inline', 'group' => CSS_THEME));
}