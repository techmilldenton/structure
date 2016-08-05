<?php

/**
 * Implement hook_preprocess_awe_pricing()
 * @param $vars
 */
function awe_pricing_object_preprocess_awe_pricing(&$vars) {
  $style = '';
  $settings = $vars['settings']; //dsm($settings);
  $pricing = array();
  $pricing['type']['value'] = $settings['type'];
  $pricing['price']['value'] = $settings['price'];
  $pricing['unit']['value'] = $settings['unit'];
  $pricing['list_feature']= json_decode($settings['customDataListText']);
  $pricing['featureText'] = $settings['featureText'];
  $pricing['button']['text']=$settings['textButton'];
  $pricing['button']['url']=empty($settings['buttonUrl'])?'#':$settings['buttonUrl'];
  $pricing['button']['target']=$settings['buttonTarget'];

  $pricing['button']['css']['normal']="color:$settings[colorButton] !important;background:$settings[backgroundButton] !important;border-color:$settings[backgroundButton];";
  $pricing['button']['css']['hover']="color:$settings[colorButtonHover] !important;background:$settings[backgroundButtonHover] !important;border-color:$settings[backgroundButtonHover] !important;";

  $pricing['type']['css']="color:$settings[typeColor];";
  if(isset($settings['fontFamilyType']))
    $pricing['type']['css'] .="font-family:$settings[fontFamilyType];";
  if(isset($settings['fontSizeType']))
    $pricing['type']['css'] .="font-size:$settings[fontSizeType]px;";
  if(isset($settings['lineHeightType']))
    $pricing['type']['css'] .="line-height:$settings[lineHeightType]px;";
  if(isset($settings['letterSpacingType']))
    $pricing['type']['css'] .="letter-spacing:$settings[letterSpacingType]px;";
  if(isset($settings['fontStyleType'])&& !empty($settings['fontStyleType'])){
      $fontStyleType = json_decode($settings['fontStyleType']);
      foreach($fontStyleType as $key=>$value){
          $pricing['type']['css'] .="$key:$value;";
      }
  }

  $pricing['price']['css']="color:$settings[priceColor];";
  if(isset($settings['fontFamilyPrice']))
    $pricing['price']['css'] .="font-family:$settings[fontFamilyPrice];";
  if(isset($settings['fontSizePrice']))
    $pricing['price']['css'] .="font-size:$settings[fontSizePrice]px;";
  if(isset($settings['lineHeightPrice']))
    $pricing['price']['css'] .="line-height:$settings[lineHeightPrice]px;";
  if(isset($settings['letterSpacingPrice']))
    $pricing['price']['css'] .="letter-spacing:$settings[letterSpacingPrice]px;";
  if(isset($settings['fontStylePrice'])&& !empty($settings['fontStylePrice'])){
      $fontStylePrice= json_decode($settings['fontStylePrice']);
      foreach($fontStylePrice as $key=>$value){
          $pricing['price']['css'] .="$key:$value;";
      }
  }


  $vars['pricing']=$pricing;
  $pricing_id = $settings['customID'];
  $pricing_class = empty($settings['customClass'])?$vars['class_random']:$settings['customClass'];
  $attributes = array(
    'enable' => $settings['customEnableAttributes'],
    'attributes' => $settings['customDataAttributes']
  );

  $animations = array(
    'enable' => $settings['customEnableAnimations'],
    'animations' => $settings['customDataAnimations']
  );

  $box_model = $settings['boxModelSettings'];
  $node_style = _ac_render_item_id_tag($pricing_id, $pricing_class, $vars['class_random']);

  $node_style = $node_style['result'];
  $attributes = _ac_render_item_attributes_settings($attributes);
  $animations = _ac_render_item_animations_settings($animations);
  $boxModel = _ac_render_item_box_model_settings($box_model);

  $class = $pricing_class;

  $pricing_id != '' ? $vars['attributes_array']['id'] = $pricing_id : '';
  $vars['classes_array'][] = $class;
  $vars['attributes_array'] = array_merge($vars['attributes_array'], $attributes);
  $animations !== '' ? $vars['attributes_array']['data-animation'] = $animations : '';

  $style .= render_css($node_style, array($boxModel));

  $id_class = empty($pricing_id)?".$pricing_class":"#$pricing_id";
  $style .="$id_class{cursor: pointer;}";
  //$style .="$id_class:hover span,$id_class:hover h5{color:$settings[text_hover_color] !important;}";
  $style .="$id_class .feature-list {color:$settings[feature_color];}";
  $style .="$id_class .price {{$pricing['type']['css']}} $id_class .price{{$pricing['price']['css']}}";
  $style .="$id_class .ts-button {{$pricing['button']['css']['normal']}} $id_class .ts-button:hover{{$pricing['button']['css']['hover']}}";


  $style .="$node_style h3 {" . $pricing['type']['css'] . " !important;}";
  $style .="$node_style .price {" . $pricing['price']['css'] . " !important}";
  $style .="$node_style .unit {color:$settings[priceColor];}";
  $style .="$node_style .box-col-heading {background-color:$settings[headerColor];}";
  $style .="$node_style .box-col {background-color:$settings[bodyColor];}";
  $style .="$node_style .btn-base span {color:$settings[colorButton]; border-color:$settings[colorButton]; background-color:$settings[backgroundButton]; }";
  $style .="$node_style .btn-base span:before {background-color:$settings[backgroundButtonHover];color:$settings[colorButtonHover];}";
  $style .="$node_style .btn-roll span:after {background-color:$settings[backgroundButtonHover];color:$settings[colorButtonHover];}";

  drupal_add_css(drupal_get_path('module', 'awe_pricing_object') . '/awecontent-pricing-item.css');
  drupal_add_css( $style, array('type' => 'inline', 'group' => CSS_THEME));
}