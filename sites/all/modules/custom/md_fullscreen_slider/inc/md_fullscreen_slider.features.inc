<?php
/**
 * @file: md_fullscreen_slider.features.inc
 * @author: MegaDrupal
 */

/**
 * implements hook_features_export_option()
 */
function md_fullscreen_slider_features_export_options() {
  $options = array();
  foreach(MDFullScreenSlider::get_all() as $slider)
    $options[$slider->machine_name] = $slider->title;

  return $options;
}

/**
 * implements hook_features_export()
 */
function md_fullscreen_slider_features_export($data, &$export, $module_name) {
  $export["dependencies"]["media"] = "media";
  $export["dependencies"]["md_fullscreen_slider"] = "md_fullscreen_slider";

  foreach ($data as $slider) {
    $export["features"]["md_fullscreen_slider"][$slider] = $slider;
  }
}

/**
 * implements hook_feature_export_render()
 */
function md_fullscreen_slider_features_export_render($module_name, $data, $export = NULL) {
  $code = array();

  $sliders = db_select("md_fullscreen_sliders", "mfs")
    ->fields("mfs")
    ->condition("machine_name", array_keys($data), "IN")
    ->execute()
    ->fetchAllAssoc("machine_name");
  $sliders_export = features_var_export($sliders);


  $code[] = "\$sliders = {$sliders_export};";
  $code[] = "foreach (\$sliders as \$slider) {";
  $code[] = "\t\$slider = (object)\$slider;";
  $code[] = "\t\$slider = _md_slider_recast('MDFullScreenSlider',\$slider);";
  $code[] = "\t\$slider->id = NULL;\n";
  $code[] = "\t\$slider->save();";
  $code[] = "}";
  return array("install" => implode("\n", $code));
}