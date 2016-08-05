<?php
function saveImage($path, $upload) {
  $validators = array('file_validate_extensions' => array('ico png gif jpg jpeg apng svg'));
  $save_path = $path;
  if ($file = file_save_upload($upload, $validators)) {
    if (isset($file)) {
      // File upload was attempted.
      if ($file) {
        $parts = pathinfo($file->filename);
        $destination = 'public://' . $parts['basename'];
        $file->status = FILE_STATUS_PERMANENT;
        if (file_copy($file, $destination, FILE_EXISTS_REPLACE)) {
          $save_path = $parts['basename'];
        }
      }
      else {
        // File upload failed.
        form_set_error(key($path), t('File could not be uploaded.'));
      }
    }
    else {
      $save_path = $path;
    }
  }
  else {
    $save_path = $path;
  }
  return $save_path;
}

function icon_default_markup() {
  $icon_bundles = icon_bundles();
}

/**
 * Analys goole link to get font information
 */
function _md_structure_process_google_web_font($fonts) {
  if (strpos($fonts, '@import url(') !== FALSE) {
    preg_match("/http:\/\/\s?[\'|\"]?(.+)[\'|\"]?\s?(\)|\')/Uix", $fonts, $ggwflink);
  }

  preg_match('/([^\?]+)(\?family=)?([^&\']+)/i', $fonts, $matches);
  $gfonts = explode("|", $matches[3]);

  for ($i = 0; $i < count($gfonts); $i++) {
    $gfontsdetail = explode(":", $gfonts[$i]);
    $gfontname = str_replace("+", " ", $gfontsdetail['0']);
    $fontarray[] = $gfontname;
    if (array_key_exists('1', $gfontsdetail)) {
      $tmpft = explode(",", $gfontsdetail['1']);
      $gfontweigth[$i] = "";
      for ($j = 0; $j < count($tmpft); $j++) {
        if (preg_match("/italic/i", $tmpft[$j])) {
          $gfontstyle = "i";
        }
        else {
          $gfontstyle = "n";
        }
        $tmpw = str_replace("italic", "", $tmpft[$j]);
        $seperator = ",";

        if ($j == (count($tmpft) - 1)) {
          $seperator = "";
        }

        if ($tmpw) {
          $gfontweigth[$i] .= $gfontstyle . str_replace("00", "", $tmpw) . $seperator;
        }
        else {
          $gfontweigth[$i] .= "n4" . $seperator;
        }
      }
    }
    else {
      $gfontweigth[$i] = "n4";
    }
    $fontvars[] = array(
      'CSS' => '"' . $gfontname . '"',
      'Weight' => $gfontweigth[$i],
    );
  }

  return array($fontarray, $fontvars);
}

/**
 * Get fonts information from type-kit id
 */
function _md_structure_process_typekit_font($typekit_id) {
  $tk_url = 'http://typekit.com/api/v1/json/kits/' . $typekit_id . '/published';
  $typekit = json_decode(file_get_contents($tk_url), TRUE);
  for ($i = 0; $i < count($typekit['kit']['families']); $i++) {
    $fontarray[] = $typekit['kit']['families'][$i]['name'];
    $fontweight = "";
    for ($j = 0; $j < count($typekit['kit']['families'][$i]['variations']); $j++) {
      if (($j + 1) == count($typekit['kit']['families'][$i]['variations'])) {
        $fontweight .= $typekit['kit']['families'][$i]['variations'][$j];
      }
      else {
        $fontweight .= $typekit['kit']['families'][$i]['variations'][$j] . ',';
      }
    }
    $fontvars[] = array(
      'CSS' => $typekit['kit']['families'][$i]['css_stack'],
      'Weight' => $fontweight,
    );
  }

  return array($fontarray, $fontvars);
}

/**
 * Load font configure
 */
function load_font_configure() {
  $fontarray = array(
    t('Default'),
    t('Arial'),
    t('Verdana'),
    t('Trebuchet MS'),
    t('Georgia'),
    t('Times New Roman'),
    t('Tahoma'),
  );

  $fontvars = array(
    array('CSS' => '', 'Weight' => 'n4'),
    array('CSS' => 'Arial, sans-serif', 'Weight' => 'n4, n7, i4, i7'),
    array('CSS' => 'Verdana, Geneva, sans-serif', 'Weight' => 'n4, n7, i4, i7'),
    array(
      'CSS' => 'Trebuchet MS, Tahoma, sans-serif',
      'Weight' => 'n4, n7, i4, i7'
    ),
    array('CSS' => 'Georgia, serif', 'Weight' => 'n4, n7, i4, i7'),
    array('CSS' => 'Times New Roman, serif', 'Weight' => 'n4, n7, i4, i7'),
    array(
      'CSS' => 'Tahoma, Geneva, Verdana, sans-serif',
      'Weight' => 'n4, n7, i4, i7'
    ),
  );
  $google_font = theme_get_setting('googlewebfonts', 'md_structure');
  if ($google_font != '') {
    $result = _md_structure_process_google_web_font($google_font);
    add_font_style($result, $fontarray, $fontvars);
  }
  $typekit = theme_get_setting('typekit_id', 'md_structure');;

  if ($typekit != '') {
    $result = _md_structure_process_typekit_font($typekit);
    add_font_style($result, $fontarray, $fontvars);
  }

  return array($fontarray, $fontvars);
}

function add_font_style($results, &$font_array, &$font_vars) {
  if (is_array($results)) {
    foreach ($results[0] as $id => $font_name) {
      $key = array_search($font_name, $font_array);
      if ($key === FALSE) {
        $font_array[] = $font_name;
        $font_vars[] = $results[1][$id];
      }
      else {
        $font_vars[$key] = $results[1][$id];
      }
    }
  }
}

/**
 * @param $directory
 * @return array
 * Get Directory List
 */
function getDirectoryList($directory) {
  $results = array();
  $handler = opendir($directory);
  while ($file = readdir($handler)) {
    if ($file != "." && $file != "..") {
      $results[] = $file;
    }
  }
  closedir($handler);
  return $results;
}

/**
 * @param $haystack
 * @param $needle
 * @param int $offset
 * @return bool
 * Check string in string
 */
function strposa($haystack, $needle, $offset = 0) {
  if (!is_array($needle)) {
    $needle = array($needle);
  }
  foreach ($needle as $query) {
    if (strpos($haystack, $query, $offset) !== FALSE) {
      return TRUE;
    }
  }
  return FALSE;
}

function theme_path() {
  $theme_path = drupal_get_path('theme', 'md_structure');
  return $theme_path;
}

function get_option_icon() {
  return array();
}

function get_list_menus() {
  $menus = menu_get_menus();
  return $menus;
}