<?php

/**
 * Implement hook_preprocess_awe_contact()
 * @param $vars
 */
function awe_contact_object_preprocess_awe_contact(&$vars) {
  $module_path = drupal_get_path('module', 'awe_contact_object');
  drupal_add_css($module_path . '/awecontent-contact-item.css');


  $style = '';
  $settings = $vars['settings'];
  $contact = array();

  $contact['title']['css'] = "color: $settings[titleColor];";
  if (isset($settings['fontFamilyTitle']))
    $contact['title']['css'] .= "font-family:$settings[fontFamilyTitle];";
  if (isset($settings['fontSizeTitle']))
    $contact['title']['css'] .= "font-size:$settings[fontSizeTitle]px;";
  if (isset($settings['lineHeightTitle']))
    $contact['title']['css'] .= "line-height: $settings[lineHeightTitle]px;";
  if (isset($settings['letterSpacingTitle']))
    $contact['title']['css'] .= "letter-spacing: $settings[letterSpacingTitle]px;";
  if(isset($settings['fontStyleTitle']) && !empty($settings['fontStyleTitle'])){
      $fontStyleTitle = json_decode($settings['fontStyleTitle']);
      foreach ($fontStyleTitle as $key=>$value){
          $contact['title']['css'] .= "$key:$value;";
      }
  }


  $vars['contact'] = $contact;
  $contact_id = $settings['customID'] != '' ? drupal_html_id($settings['customID']) : FALSE;
  $vars['id'] = $contact_id;
  $contact_class = empty($settings['customClass']) ? $vars['class_random'] : $settings['customClass'];
  $attributes = array(
    'enable' => $settings['customEnableAttributes'],
    'attributes' => $settings['customDataAttributes']
  );

  $animations = array(
    'enable' => $settings['customEnableAnimations'],
    'animations' => $settings['customDataAnimations']
  );

  $box_model = $settings['boxModelSettings'];
  $node_style = _ac_render_item_id_tag($contact_id, $contact_class, $vars['class_random']);

  $node_style = $node_style['result'];
  $attributes = _ac_render_item_attributes_settings($attributes);
  $animations = _ac_render_item_animations_settings($animations);
  $boxModel = _ac_render_item_box_model_settings($box_model);

  $class = $contact_class;

  $vars['classes_array'][] = $class;
  $vars['attributes_array'] = array_merge($vars['attributes_array'], $attributes);
  $animations !== '' ? $vars['attributes_array']['data-animation'] = $animations : '';

  $style .= render_css($node_style, array($boxModel));

  $id_class = empty($contact_id)?".$contact_class":"#$contact_id";
  $style .="$id_class{background-color:$settings[background_color];cursor: pointer;}$id_class:hover{background-color:$settings[hover_color] !important;}";

  $style .="$node_style span {" . $contact['title']['css'] . "}";
  $style .="$node_style i {color:$settings[iconColor];}";

  drupal_add_css( $style, array('type' => 'inline', 'group' => CSS_THEME));
}