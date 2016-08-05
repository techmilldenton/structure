<?php
/**
 * Implements hook_preprocess_page().
 */
function md_structure_preprocess_page(&$vars, $hook) {
  $path_theme = drupal_get_path('theme', 'md_structure');
  
  if ($vars['main_menu']) {
    $vars['primary_nav'] = menu_tree(variable_get('menu_main_links_source', 'main-menu'));
    $vars['primary_nav']['#theme_wrappers'] = array('menu_tree__primary');
  }

  //Hook suggestion

  if (isset($vars['node'])) {
    $vars['theme_hook_suggestions'][] = 'page__node__' . str_replace('_', '--', $vars['node']->type);
  }
  if (arg(0) == 'taxonomy') {
    $vars['theme_hook_suggestions'][] = 'page__taxonomy';
  }
  if (arg(0) == 'search' && arg(1) && arg(2)) {
    $vars['theme_hook_suggestions'][] = 'page__search__results';
  }

  //Settings Menu
  $vars['skin_menu'] = '';
  $vars['position'] = 'menu-vertical-left';
  $vars['stick_fixed'] = 'js-stick';
  $vars['menu_wrapper'] = 'full-wrapper';
  $vars['menu_type'] = theme_get_setting('menu_type');
  if (theme_get_setting('menu_type') == 'vertical') {
    if (theme_get_setting('menu_location') == 'menu-vertical-right') {
      $vars['position'] = 'menu-vertical-right';
    }
  }
  else {
    $vars['skin_menu'] = theme_get_setting('menu_skin');
    if (theme_get_setting('menu_position') == 'fixed') {
      $vars['stick_fixed'] = 'stick-fixed';
    }
    if (theme_get_setting('menu_wrapper') == 'container') {
      $vars['menu_wrapper'] = 'container';
    }
  }
}

/**
 * @param $vars
 * Implement hook_process_page().
 */
function md_structure_process_page(&$vars) {
  global $base_url;
  $themepath = drupal_get_path("theme","md_structure");

  $status = drupal_get_http_header("status");
  if($status == "404 Not Found") {
    $vars['theme_hook_suggestions'][] = 'page__404';
  }

  // LOGO SETTINGS
  $vars['logo'] = $base_url.'/'.$themepath.'/logo.png';
  if(theme_get_setting('default_logo') == 0) {
    if(module_exists('media')) {
      if($file_upload = theme_get_setting('logo_normal_file_uploaded')) {
        if(!empty($file_upload)) {
          $file = file_load($file_upload['fid']);
          $vars['logo'] = file_create_url($file->uri);
        }
      }
    } else {
      if ($logo_file = theme_get_setting('logo_normal_form_file')) {
        $vars['logo'] =  file_create_url(file_build_uri($logo_file));
      }
    }
  }
}
