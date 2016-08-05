<?php
/**
 * @file
 * Theme setting callbacks for the md_structure theme.
 */
global $base_url;
define('THEME_PATH', drupal_get_path('theme', 'md_structure'));
define('CURRENT_THEME', variable_get('theme_default'));
define('BASE_THEME', 'md_structure');

require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_structure') . '/inc/admin/utilities.inc';
require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_structure') . '/inc/admin/form.inc';
require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_structure') . '/inc/admin/theme-settings-general.inc';
require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_structure') . '/inc/admin/theme-settings-design.inc';
require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_structure') . '/inc/admin/theme-settings-text.inc';
require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_structure') . '/inc/admin/theme-settings-pages.inc';
require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_structure') . '/inc/admin/theme-settings-code.inc';
require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_structure') . '/inc/admin/theme-settings-config.inc';

/**
 * Implements hook_form_FORM_ID_alter().
 * @param $form
 * @param $form_state
 * @param null $form_id
 * @param bool $no_js_use
 */

function md_structure_form_system_theme_settings_alter(&$form, &$form_state, $form_id = NULL, $no_js_use = FALSE) {
  global $base_url;
  $path = drupal_get_path('theme', 'md_structure');

  // Attach library, js , and css to form.

  //Add libraries
  $form['#attached']['library'] = array(
    array('system', 'jquery.cookie'),
    array('system', 'ui.widget'),
    array('system', 'ui.mouse'),
    array('system', 'ui.slider'),
    array('system', 'ui.tabs'),
    array('system', 'ui.dialog'),
    array('system', 'ui.draggable'),
    array('system', 'ui.sortable'),
    array('system', 'ui.slider'),
    array('system', 'ui.accordion'),
    array('system', 'ui.datepicker'),
  );

  //Add js
  $form['#attached']['js'] = array(
    $path . '/js/admin/modernizr.custom.js',
    $path . '/js/admin/jquery-migrate.min.js',
    $path . '/js/admin/spectrum.js',
    $path . '/js/admin/bootstrap-dialog.js',
    $path . '/js/admin/jquery.choosefont.js',
    $path . '/js/admin/jquery.mCustomScrollbar.js',
    $path . '/js/admin/jquery.mousewheel.js',
    $path . '/js/admin/addmore.js',
    $path . '/js/admin/script.js',
  );

  // Add js settings
  $media_settings = array(
    'wysiwyg_allowed_attributes' => variable_get('media__wysiwyg_allowed_attributes', array(
      'height',
      'width',
      'hspace',
      'vspace',
      'border',
      'align',
      'style',
      'class',
      'id',
      'usemap',
      'data-picture-group',
      'data-picture-align'
    ))
  );
  $fonts = load_font_configure();
  $js_settings = array(
    'themeDir' => $base_url . '/' . THEME_PATH,
    'baseUrl' => $base_url,
    'media' => $media_settings,
    'font_array' => $fonts[0],
    'font_vars' => $fonts[1]
  );
  $form['#attached']['js'][] = array(
    'data' => $js_settings,
    'type' => 'setting',
  );

  //Add css
  $form['#attached']['css'] = array(
    $path . '/css/admin/font-awesome.css',
    $path . '/css/admin/style-frame.css',
    $path . '/css/admin/style-drupal.css',
    $path . '/css/admin/spectrum.css',
    $path . '/css/admin/bootstrap-dialog.css',
    $path . '/css/admin/jquery.mCustomScrollbar.css',
    $path . '/css/admin/jquery.mCustomScrollbar.css',
    $path . '/css/admin/jquery-ui-1.10.4.css',
    $path . '/css/admin/jquery-ui-timepicker-addon.css',
  );
  if (isset($form_id)) {
    return;
  }
  // Need to hide default theme settings in system, we create it after
  unset($form['theme_settings']);
  hide($form['logo']);
  hide($form['favicon']);
  // Make default dialog markup for icon

  $form['md_structure_settings']['html_header'] = array(
    '#markup' => '<div id="md-framewp" class="md-framewp">
    <div id="md-framewp-header">
        <!-- /////////////////// ALERT BOX ///////////////// -->
        <div class="md-alert-boxs">
        </div>
      </div><!-- /#md-framewp-header -->
    <div id="md-framewp-body">
    <div id="md-tabs-framewp" class="md-tabs-framewp">
        <ul class="clearfix">
            <li><a href="#md-general">General</a></li>
            <li><a href="#md-design">Design</a></li>
            <li><a href="#md-text-typography">Text & Typography</a></li>
            <li><a href="#md-code">Custom Code</a></li>
            <li><a href="#md-config">Backup & Restore</a></li>
        </ul>
    </div><!-- /.md-tabs-framewp -->
    <div class="logo-right">
        <a href="http://megadrupal.com/forum">
            <img title="Visit our support forum" src="' . $base_url . '/' . THEME_PATH . '/img/theme-settings/logo.png' . '" alt="Mega Drupal">
        </a>
    </div>
    <div class="md-content-framewp">',
    '#weight' => -99,
  );
  md_structure_theme_settings_general($form, $form_state);
  md_structure_theme_settings_design($form, $form_state);
  md_structure_theme_settings_text($form, $form_state);
  md_structure_theme_settings_code($form, $form_state);
  md_structure_theme_settings_config($form, $form_state);


  $form['actions']['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset Settings'),
    '#submit' => array('md_structure_reset_settings_submit'),
    '#weight' => 98,
    '#attributes' => array(
      'class' => array('btn btn-reset'),
      'onClick' => 'return confirm("Are you sure want to reset all settings to default ?")'
    )
  );
  $form['actions']['submit']['#weight'] = 97;
  $form['actions']['submit']['#attributes'] = array(
    'class' => array('btn btn-save'),
  );
  $form['actions']['#prefix'] = '</div><!-- /.md-content-framewp -->
                                    </div><!-- /#md-framewp-body -->
                                    <div id="md-framewp-footer" class="md-framewp-footer">
                                    <div class="footer-left">
                                    <div class="md-button-group">';
  $form['actions']['#suffix'] = '</div>
                                    </div>
                                    <div class="footer-right">
                                    <p class="md-copyright">Designed and Developed by <a href="http://megadrupal.com">Megadrupal</a></p>
                                    </div>
                                    </div>
                                    </div><!-- /.md-framewp -->';
  // Get all themes.
  $themes = list_themes();
  $active_theme = $GLOBALS['theme_key'];
  $form_state['build_info']['files'][$active_theme] = str_replace("/$active_theme.info", '', $themes[$active_theme]->filename) . '/theme-settings.php';
}


/**
 * @param $form
 * @param $form_state
 * Reset all theme settings
 */
function md_structure_reset_settings_submit($form, &$form_state) {
  $theme_settings = variable_get('theme_' . variable_get('theme_default') . '_settings');
  $default_settings = _md_structure_theme_default_settings($theme_settings);
  variable_set('theme_' . variable_get('theme_default') . '_settings', NULL);
  variable_set('theme_' . variable_get('theme_default') . '_settings', $default_settings);
  drupal_set_message('All settings reset to default');
  cache_clear_all();
}



/**
 * Restore Theme settings
 */
function md_structure_restore_theme_settings($form, &$form_state) {
  $values = $form_state['values'];
  $theme = variable_get('theme_default');
  if ($values['restore_type'] != NULL) {
    if ($values['restore_type'] == 'upload') {
      if ($form_state['values']['restore_file_media_upload'] != NULL) {
        $data_decode = drupal_json_decode($form_state['values']['restore_file_media_upload']);
        $file = file_load($data_decode['fid']);
        if (!$file) {
          drupal_set_message(t("Your file upload isn't correct, please upload again"), 'error');
          return;
        }
        $file_content = file_get_contents($file->uri);
        $restore_settings = drupal_json_decode(base64_decode(unserialize($file_content)));
        if (is_array($restore_settings)) {
          variable_set('theme_' . $theme . '_settings', array());
          variable_set('theme_' . $theme . '_settings', $restore_settings);
          file_delete($file, $force = TRUE);
          cache_clear_all();
          drupal_set_message(t('All your theme settings have been restored'));
        }
        else {
          drupal_set_message(t("Your file upload isn't correct, please upload again"), 'warning');
          return;
        }


      }
      else {
        drupal_set_message(t('Please choose your file upload'), 'error');
        return;
      }
    }
    else {
      if ($values['restore_from_file'] == NULL) {
        drupal_set_message('Choose your backup file in list or move back up to backup folder', 'warning');
        return;
      }
      else {
        $file_content = file_get_contents("public://" . variable_get('theme_default') . "_backup/{$values['restore_from_file']}");
        $restore_settings = drupal_json_decode(base64_decode(unserialize($file_content)));
        if (is_array($restore_settings)) {
          variable_set('theme_' . $theme . '_settings', array());
          variable_set('theme_' . $theme . '_settings', $restore_settings);
          cache_clear_all();
          drupal_set_message(t('All your theme settings have been restored'));
        }
        else {
          drupal_set_message(t("Your choosen backup file isn't correct, please choose again"), 'warning');
          return;
        }
      }
    }
  }


  if ($restore_file = file_save_upload('restore_file_simple_upload')) {
    $file_content = file_get_contents($restore_file->uri);
    $restore_settings = drupal_json_decode(base64_decode(unserialize($file_content)));
    variable_set('theme_' . $theme . '_settings', $restore_settings);
    cache_clear_all();
    drupal_set_message(t('All your theme settings have been restored'));
  }
  if (isset($form_state['values']['restore_file_media_upload'])) {

  }

}

/**
 * Default theme settings
 */
function _md_structure_theme_default_settings($theme_settings) {
  $default_settings = array();
  foreach ($theme_settings as $key => $setting) {
    $default_settings[$key] = NULL;
  }
  $default_settings['toggle_logo'] = 1;
  $default_settings['toggle_name'] = 1;
  $default_settings['toggle_slogan'] = 1;
  $default_settings['toggle_node_user_picture'] = 1;
  $default_settings['toggle_comment_user_picture'] = 1;
  $default_settings['toggle_comment_user_verification'] = 1;
  $default_settings['toggle_favicon'] = 1;
  $default_settings['toggle_fvicon'] = 1;
  $default_settings['toggle_main_menu'] = 1;
  $default_settings['toggle_secondary_menu'] = 1;
  $default_settings['default_logo'] = 1;
  $default_settings['default_favicon'] = 1;
  $default_settings['css3_textarea'] = 0;
  $default_settings['webclip_precomp'] = 1;
  $default_settings['skins'] = 'red';
  $default_settings['typo_heading_style_enable'] = 0;
  $default_settings['header_background_type'] = 'static';
  $default_settings['header_video_play'] = 0;
  return $default_settings;
}



