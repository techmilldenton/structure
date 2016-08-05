<?php
/**
 * Implement hook_preprocess_html()
 */
function md_structure_preprocess_html(&$vars) {
  global $base_url;
  $css = "";
  $scripts = "";
  $path_theme = drupal_get_path('theme', 'md_structure');

  drupal_add_js("{$path_theme}/js/front/vendor/modernizr-2.8.3.min.js");
  drupal_add_js("{$path_theme}/js/front/plugins/bootstrap.min.js");
  drupal_add_js("{$path_theme}/js/front/plugins/slick.min.js");
  drupal_add_js("{$path_theme}/js/front/plugins/isotope.pkgd.min.js");
  drupal_add_js("{$path_theme}/js/front/plugins/imagesloaded.pkgd.js");
  drupal_add_js("{$path_theme}/js/front/plugins/jquery.hoverdir.js");
  drupal_add_js("{$path_theme}/js/front/main.js");

  //  drupal_add_css();
  drupal_add_css("{$path_theme}/css/front/style.css");
  drupal_add_css("{$path_theme}/css/front/normalize.css");
  drupal_add_css("{$path_theme}/css/front/slick.css");
  drupal_add_css("{$path_theme}/css/front/main.css");

  // FAVICON SETTING

  // Add favicon.
  if (theme_get_setting('toggle_fvicon') == 1) {
    $favicon_path = base_url().'/'.$path_theme.'/favicon.ico';
    if(theme_get_setting('default_favicon') == 0) {
      if(module_exists('media')) {
        $favicon = theme_get_setting('favicon_file_uploaded');
        if(!empty($favicon)) {
          $file = file_load($favicon['fid']);
          $favicon_path = file_create_url($file->uri);
        }
      } else {
        if ($favicon_file = theme_get_setting('favicon_form_file')) {
          $favicon_path =  file_create_url(file_build_uri($favicon_file));
        }
      }
    }
    $type = theme_get_setting('favicon_mimetype');
    drupal_add_html_head_link(array('rel' => 'shortcut icon', 'href' => drupal_strip_dangerous_protocols($favicon_path), 'type' => $type));
  }
  // iOs webclip
  $vars['ios_57'] = '';
  if(module_exists('media')) {
    if(theme_get_setting('ios_57x57_file_uploaded')) {
      $file_upload = theme_get_setting('ios_57x57_file_uploaded');
      if(!empty($file_upload)) {
        $file = file_load($file_upload['fid']);
        if(isset($file->uri)) {
          $vars['ios_57']  = file_create_url($file->uri);
        }
      }
    }
  } else {
    if (theme_get_setting('ios_57x57_form_file')) {
      $vars['ios_57'] =  file_create_url(file_build_uri(theme_get_setting('ios_57x57_form_file')));
    }
  }

  $vars['ios_72'] = '';
  if(module_exists('media')) {
    if(theme_get_setting('ios_72x72_file_uploaded')) {
      $file_upload = theme_get_setting('ios_72x72_file_uploaded');
      if(!empty($file_upload)) {
        $file = file_load($file_upload['fid']);
        if(isset($file->uri)) {
          $vars['ios_72'] = file_create_url($file->uri);
        }
      }
    }
  } else {
    if (theme_get_setting('ios_72x72_form_file')) {
      $vars['ios_72'] =  file_create_url(file_build_uri(theme_get_setting('ios_72x72_form_file')));
    }
  }

  $vars['ios_114'] = '';
  if(module_exists('media')) {
    if(theme_get_setting('ios_114x114_file_uploaded')) {
      $file_upload = theme_get_setting('ios_114x114_file_uploaded');
      if(!empty($file_upload)) {
        $file = file_load($file_upload['fid']);
        if(isset($file->uri)) {
          $vars['ios_144'] = file_create_url($file->uri);
        }
      }
    }
  } else {
    if (theme_get_setting('ios_114x114_form_file')) {
      $vars['ios_114'] =  file_create_url(file_build_uri(theme_get_setting('ios_114x114_form_file')));
    }
  }

  $vars['ios_144'] = '';
  if(module_exists('media')) {
    if(theme_get_setting('ios_144x144_file_uploaded')) {
      if(theme_get_setting('ios_144x144_file_uploaded')) {
        $file_upload = theme_get_setting('ios_144x144_file_uploaded');
        if(!empty($file_upload)) {
          if(isset($file->uri)) {
            $file = file_load($file_upload['fid']);
            $vars['ios_144']  = file_create_url($file->uri);
          }
        }
      }
    }
  } else {
    if (theme_get_setting('ios_144x144_form_file')) {
      $vars['ios_144'] =  file_create_url(file_build_uri(theme_get_setting('ios_144x144_form_file')));
    }
  }

  // FONT - TEXT & TYPO SETTINGS

  //Google Fonts
  if (theme_get_setting('googlewebfonts')) {
    drupal_add_css(str_replace('|', '%7c', theme_get_setting('googlewebfonts')), array('type' => 'external'));
  }
  // Typekit Fonts
  if (theme_get_setting('typekit_id')) {
    drupal_add_js('http://use.typekit.net/' . theme_get_setting('typekit_id') . '.js', 'external');
    drupal_add_js('try{Typekit.load();}catch(e){}', 'inline');
  }

  // Text & Typo
  $typography = '';
  // common text
  if (theme_get_setting('text_font') || theme_get_setting('ts_font_color')) {
    $typography = "body {";
    $typography .= md_ambrosia_font_to_css(theme_get_setting('text_font'));
    if (theme_get_setting('ts_font_color')) {
      $typography .= 'color: #' . theme_get_setting('ts_font_color') . ';';
    }
    $typography .= "}\n";
  }

  $text_font_arr = explode("|", theme_get_setting('text_font'));
  if (count($text_font_arr) == 5 && $text_font_arr[0] != '0') {
    $typography .= '#forum, ul.quicktabs-tabs, #nav ul.sf-menu li li,.ui-widget {font-family: ' . $text_font_arr[4] . ';}';
  }
  /////
  // Text selection
  if (theme_get_setting('tss_bgcolor') || theme_get_setting('tss_tcolor')) {
    $tss_bgcolor = '';
    $tss_tcolor = '';
    if (theme_get_setting('tss_bgcolor')) {
      $tss_bgcolor = 'background: #' . theme_get_setting('tss_bgcolor') . ';';
    }
    if (theme_get_setting('tss_tcolor')) {
      $tss_tcolor = 'color: #' . theme_get_setting('tss_tcolor') . ';';
    }
    $typography .= "::-moz-selection {" . $tss_bgcolor . $tss_tcolor . "text-shadow: none;}\n";
    $typography .= "::selection {" . $tss_bgcolor . $tss_tcolor . "text-shadow: none;}\n";
  }
  // link regular
  if (theme_get_setting('l_regular_color') || theme_get_setting('l_regular_st') || theme_get_setting('l_regular__hl') || theme_get_setting('l_regular_ts')) {
    $typography .= "a:link, #node-title a {";
    if (theme_get_setting('l_regular_color')) {
      $typography .= 'color: #' . theme_get_setting('l_regular_color') . ';';
    }
    if (theme_get_setting('l_regular__hl')) {
      $typography .= 'background-color: #' . theme_get_setting('l_regular__hlc') . ';';
    }
    if (theme_get_setting('l_regular_st') == 1) {
      $typography .= 'text-decoration: line-through';
    }
    $l_text_style = theme_get_setting('l_regular_ts');
    if ($l_text_style['bold']) {
      $typography .= 'font-weight: ' . $l_text_style['bold'] . ';';
    }
    if ($l_text_style['italic']) {
      $typography .= 'font-style: ' . $l_text_style['italic'] . ';';
    }
    if ($l_text_style['underline']) {
      $typography .= 'text-decoration: ' . $l_text_style['underline'] . ';';
    }
    $typography .= "}\n";
  }
  // link rollover
  if (theme_get_setting('l_rollover_color') || theme_get_setting('l_rollover_st') || theme_get_setting('l_rollover__hl') || theme_get_setting('l_rollover_ts')) {
    $typography .= "a:hover, #node-title a:hover {";
    if (theme_get_setting('l_rollover_color')) {
      $typography .= 'color: #' . theme_get_setting('l_rollover_color') . ';';
    }
    if (theme_get_setting('l_rollover__hl')) {
      $typography .= 'background-color: #' . theme_get_setting('l_rollover__hlc') . ';';
    }
    if (theme_get_setting('l_rollover_st') == 1) {
      $typography .= 'text-decoration: line-through';
    }
    $l_text_style = theme_get_setting('l_rollover_ts');
    if ($l_text_style['bold']) {
      $typography .= 'font-weight: ' . $l_text_style['bold'] . ';';
    }
    if ($l_text_style['italic']) {
      $typography .= 'font-style: ' . $l_text_style['italic'] . ';';
    }
    if ($l_text_style['underline']) {
      $typography .= 'text-decoration: ' . $l_text_style['underline'] . ';';
    }
    $typography .= "}\n";
  }

  // link visited
  if (theme_get_setting('l_visited_color') || theme_get_setting('l_visited_st') || theme_get_setting('l_visited__hl') || theme_get_setting('l_visited_ts')) {
    $typography .= "a:visited, #node-title a:visited {";
    if (theme_get_setting('l_visited_color')) {
      $typography .= 'color: #' . theme_get_setting('l_visited_color') . ';';
    }
    if (theme_get_setting('l_visited__hl')) {
      $typography .= 'background-color: #' . theme_get_setting('l_visited__hlc') . ';';
    }
    if (theme_get_setting('l_visited_st') == 1) {
      $typography .= 'text-decoration: line-through';
    }
    $l_text_style = theme_get_setting('l_visited_ts');
    if ($l_text_style['bold']) {
      $typography .= 'font-weight: ' . $l_text_style['bold'] . ';';
    }
    if ($l_text_style['italic']) {
      $typography .= 'font-style: ' . $l_text_style['italic'] . ';';
    }
    if ($l_text_style['underline']) {
      $typography .= 'text-decoration: ' . $l_text_style['underline'] . ';';
    }
    $typography .= "}\n";
  }

  // link on
  if (theme_get_setting('l_on_color') || theme_get_setting('l_on_st') || theme_get_setting('l_on_hl') || theme_get_setting('l_on_ts')) {
    $typography .= "a:focus, a:active, #node-title a:focus, #node-title a:active {";
    if (theme_get_setting('l_on_color')) {
      $typography .= 'color: #' . theme_get_setting('l_on_color') . ';';
    }
    if (theme_get_setting('l_on_hl')) {
      $typography .= 'background-color: #' . theme_get_setting('l_on_hlc') . ';';
    }
    if (theme_get_setting('l_on_st') == 1) {
      $typography .= 'text-decoration: line-through';
    }
    $l_text_style = theme_get_setting('l_on_ts');
    if ($l_text_style['bold']) {
      $typography .= 'font-weight: ' . $l_text_style['bold'] . ';';
    }
    if ($l_text_style['italic']) {
      $typography .= 'font-style: ' . $l_text_style['italic'] . ';';
    }
    if ($l_text_style['underline']) {
      $typography .= 'text-decoration: ' . $l_text_style['underline'] . ';';
    }
    $typography .= "}\n";
  }

// HEADING
  if (theme_get_setting('typo_heading_style_enable') == 1) {
    for ($i = 1; $i <= 6; $i++) {
      $typography .= 'h' . $i . ' {';
      if (theme_get_setting('typo_heading_h' . $i . '_style') || theme_get_setting('typo_heading_h' . $i . '_color')) {
        if (theme_get_setting('typo_heading_h' . $i . '_style')) {
          $typography .= md_ambrosia_font_to_css(theme_get_setting('typo_heading_h' . $i . '_style'));
        }
        if (theme_get_setting('typo_heading_h' . $i . '_color')) {
          $typography .= ' color: #' . theme_get_setting('typo_heading_h' . $i . '_color') . ';';
        }
      }
      $typography .= "}\n";
    }
  }

  $vars['typography'] = $typography;
  $vars['theme_setting_css'] = $css;

  //Custom Code settings
  $vars['footer_text'] = theme_get_setting('footer_text');
  $vars['header_code'] = theme_get_setting('header_code');
  $vars['footer_code'] = theme_get_setting('footer_code');
  if (theme_get_setting('custom_css')) {
    $vars['custom_css'] = theme_get_setting('custom_css');
  }
  drupal_add_css(path_to_theme() . '/css/ie7.css', array(
    'group' => CSS_THEME,
    'browsers' => array('IE' => 'lte IE 7', '!IE' => FALSE),
    'preprocess' => FALSE
  ));

  // PREPARE SCRIPT INLINE FOR PRINT OUTSIDE html.tpl.php
  $vars['theme_setting_scripts'] = $scripts;

}
function md_ambrosia_font_to_css($font) {
  $font_arr = explode("|", $font);
  $css = "";
  if (count($font_arr) == 6) {
    if ($font_arr[0] != '0') {
      $css = '' . $font_arr[5] . ';';
    }
  }
  return $css;
}

function md_ambrosia_expand_font_weight($fw) {
  switch ($fw) {
    case 'n1':
      $fontExpand = "font-style: normal; font-weight: 100;";
      break;
    case 'i1':
      $fontExpand = "font-style: italic; font-weight: 100;";
      break;
    case 'n2':
      $fontExpand = "font-style: normal; font-weight: 200;";
      break;
    case 'i2':
      $fontExpand = "font-style: italic; font-weight: 200;";
      break;
    case 'n3':
      $fontExpand = "font-style: normal; font-weight: 300;";
      break;
    case 'i3':
      $fontExpand = "font-style: italic; font-weight: 300;";
      break;
    case 'n4':
      $fontExpand = "font-style: normal; font-weight: normal;";
      break;
    case 'i4':
      $fontExpand = "font-style: italic; font-weight: normal";
      break;
    case 'n5':
      $fontExpand = "font-style: normal; font-weight: 500;";
      break;
    case 'i5':
      $fontExpand = "font-style: italic; font-weight: 500;";
      break;
    case 'n6':
      $fontExpand = "font-style: normal; font-weight: 600;";
      break;
    case 'i6':
      $fontExpand = "font-style: italic; font-weight: 600;";
      break;
    case 'n7':
      $fontExpand = "font-style: normal; font-weight: bold;";
      break;
    case 'i7':
      $fontExpand = "font-style: italic; font-weight: bold;";
      break;
    case 'n8':
      $fontExpand = "font-style: normal; font-weight: 800;";
      break;
    case 'i8':
      $fontExpand = "font-style: italic; font-weight: 800;";
      break;
    case 'n9':
      $fontExpand = "font-style: normal; font-weight: 800;";
      break;
    case 'i9':
      $fontExpand = "font-style: italic; font-weight: 800;";
      break;
    default:
      $fontExpand = "";
  }

  return $fontExpand;
}

function base_url() {
  global $base_url;
  return $base_url;
}