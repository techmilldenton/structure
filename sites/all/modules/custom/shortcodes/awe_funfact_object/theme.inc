<?php

/**
 * Implement hook_preprocess_awe_funfact()
 * @param $vars
 */
function awe_funfact_object_preprocess_awe_funfact(&$vars) {
  $module_path = drupal_get_path('module', 'awe_funfact_object');
  drupal_add_css($module_path . '/awecontent-funfact-item.css');


  $style = '';
  $settings = $vars['settings'];
  $funfact = array();

  $funfact['number']['value'] = $settings['number'];
  $funfact['title']['value'] = $settings['title'];
  $funfact['number']['css'] = "color:$settings[numberColor];";
  if (isset($settings['fontFamilyNumber']))
    $funfact['number']['css'] .= "font-family: $settings[fontFamilyNumber];";
  if (isset($settings['fontSizeNumber']))
    $funfact['number']['css'] .= "font-size: $settings[fontSizeNumber]px;";
  if (isset($settings['lineHeightNumber']))
    $funfact['number']['css'] .= "line-height: $settings[lineHeightNumber]px;";
  if(isset($settings['letterSpacingNumber']))
    $funfact['number']['css'] .= "letter-spacing: $settings[letterSpacingNumber]px;";
  if (isset($settings['fontStyleNumber'])&& !empty($settings['fontStyleNumber'])) {
      $fontStyleNumber = json_decode($settings['fontStyleNumber']);
      foreach ($fontStyleNumber as $key => $value) {
          $funfact['number']['css'] .= "$key:$value;";
      }
  }

  $funfact['title']['css'] = "color: $settings[titleColor];";
  if (isset($settings['fontFamilyTitle']))
    $funfact['title']['css'] .= "font-family:$settings[fontFamilyTitle];";
  if (isset($settings['fontSizeTitle']))
    $funfact['title']['css'] .= "font-size:$settings[fontSizeTitle]px;";
  if (isset($settings['lineHeightTitle']))
    $funfact['title']['css'] .= "line-height: $settings[lineHeightTitle]px;";
  if (isset($settings['letterSpacingTitle']))
    $funfact['title']['css'] .= "letter-spacing: $settings[letterSpacingTitle]px;";
  if(isset($settings['fontStyleTitle']) && !empty($settings['fontStyleTitle'])){
      $fontStyleTitle = json_decode($settings['fontStyleTitle']);
      foreach ($fontStyleTitle as $key=>$value){
          $funfact['title']['css'] .= "$key:$value;";
      }
  }


  $vars['funfact'] = $funfact;
  $funfact_id = $settings['customID'] != '' ? drupal_html_id($settings['customID']) : FALSE;
  $vars['id'] = $funfact_id;
  $funfact_class = empty($settings['customClass']) ? $vars['class_random'] : $settings['customClass'];
  $attributes = array(
    'enable' => $settings['customEnableAttributes'],
    'attributes' => $settings['customDataAttributes']
  );

  $animations = array(
    'enable' => $settings['customEnableAnimations'],
    'animations' => $settings['customDataAnimations']
  );

  $box_model = $settings['boxModelSettings'];
  $node_style = _ac_render_item_id_tag($funfact_id, $funfact_class, $vars['class_random']);

  $node_style = $node_style['result'];
  $attributes = _ac_render_item_attributes_settings($attributes);
  $animations = _ac_render_item_animations_settings($animations);
  $boxModel = _ac_render_item_box_model_settings($box_model);

  $class = $funfact_class;

  $vars['classes_array'][] = $class;
  $vars['attributes_array'] = array_merge($vars['attributes_array'], $attributes);
  $animations !== '' ? $vars['attributes_array']['data-animation'] = $animations : '';

  $style .= render_css($node_style, array($boxModel));

  $id_class = empty($funfact_id)?".$funfact_class":"#$funfact_id";
  $style .="$id_class{background-color:$settings[background_color];cursor: pointer;}$id_class:hover{background-color:$settings[hover_color] !important;}";

  $style .="$node_style .box-count-number span {" . $funfact['number']['css'] . "}";
  $style .="$node_style p {" . $funfact['title']['css'] . "}";

  if(isset($settings['iconColor'])) {
    $style .="$id_class i {color:$settings[iconColor] !important;}";
  }

  drupal_add_css( $style, array('type' => 'inline', 'group' => CSS_THEME));
}