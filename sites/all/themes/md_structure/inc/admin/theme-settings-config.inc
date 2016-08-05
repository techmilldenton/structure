<?php

/**
 * @file
 * Theme settings .
 */

function md_structure_theme_settings_config(&$form, &$form_state) {
  $form['md_structure_settings']['config'] = array(
    '#type' => 'fieldset',
    '#weight' => 0,
    '#prefix' => '<div id="md-config" class="md-tabcontent clearfix">',
    '#suffix' => '</div><!-- / #md-config -->',
  );

  $form['md_structure_settings']['config']['config_htmllist'] = array(
    '#markup' => '<div id="md-content-sidebar" class="md-content-sidebar">
                                        <ul class="clearfix">
                                            <li><a href="#config-backup"><i class="fa fa-rotate-left"></i>Backup</a></li>
                                            <li><a href="#config-restore"><i class="fa fa-cog"></i>Restore</a></li>
                                        </ul>
                                    </div><!-- /.md-content-sidebar -->
                              <div class="md-content-main">',
    '#weight' => -15,
  );

  $form['md_structure_settings']['config']['config_htmllistclose'] = array(
    '#markup' => '</div><!-- /.md-listleft -->',
    '#weight' => 15,
  );

  $form['md_structure_settings']['config']['backup'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<div id="config-backup"><h3 class="md-tabcontent-title">' . t('Backup Options') . '</h3>',
    '#suffix' => '</div><!-- / #backup -->',
  );
  $form['md_structure_settings']['config']['backup']['backup_html'] = array(
    '#markup' => '<div class="last-backup"></div>',
    '#prefix' => '<p><strong>You can use button below to backup your current theme settings</strong></p>
                          <p>Remember save your current settings before backup, files stored in <strong>public://' . variable_get('theme_default') . '_backup</strong> and make sure you set readable/writable permission for this folders.',
  );
  $form['md_structure_settings']['config']['backup']['backup_theme_settings'] = array(
    '#type' => 'submit',
    '#value' => t('Backup All Settings'),
    '#submit' => array('md_structure_backup_theme_settings_submit'),
  );

  $form['md_structure_settings']['config']['restore'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<div id="config-restore"><h3 class="md-tabcontent-title">' . t('Restore Options') . '</h3>',
    '#suffix' => '</div><!-- / #restore -->',
  );

  $form['md_structure_settings']['config']['restore']['restore_type'] = array(
    '#type' => 'select',
    '#title' => 'Choose type of restore theme settings',
    '#options' => array(
      'upload' => t('Upload file'),
      'select' => t('Select list files')
    ),
    '#attributes' => array(
      'class' => array('select'),
    ),
    '#prefix' => '<div class="form-group">',
    '#suffix' => '</div>',
    '#field_prefix' => '<div class="md-selection big">',
    '#field_suffix' => '</div>',
  );
  if (module_exists('media')) {
    $form['md_structure_settings']['config']['restore']['restore_file_media_wrapper'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('md-media-wrapper')
      )
    );
    $restore_file = new stdClass();
    $restore_file->url = '';
    $restore_file->fid = '';

    $restore_file_hidden_value = theme_get_setting('restore_file_media_upload', 'md_structure');

    if (!empty($restore_file_hidden_value)) {
      if (is_array($restore_file_hidden_value) == FALSE) {
        $restore_file = json_decode($restore_file_hidden_value);
      }
    }


    $form['md_structure_settings']['config']['restore']['restore_file_media_wrapper']['restore_file_upload_media'] = array(
      '#markup' => '
                <div class="form-wrapper  mb-20">
                    <h4 class="md-row-title">' . t('Upload Your Theme Settings Backup File') . '</h4>
                        <div class="form-elements">
                            <div class="preview">
                            </div>
                        </div>
                        <a href="#" class="media-select-button button element-hidden md-button">' . t('Select') . '</a>
                </div>'
    );
    $form['md_structure_settings']['config']['restore']['restore_file_media_wrapper']['restore_file_media_upload'] = array(
      '#type' => 'hidden',
      '#default_value' => theme_get_setting('restore_file_media_upload'),
      '#attributes' => array(
        'class' => array('media-hidden-value')
      )
    );


  }
  else {
    $form['md_structure_settings']['config']['restore']['restore_file_simple_upload'] = array(
      '#type' => 'file',
      '#title' => 'Upload your backup file to restore theme settings'
    );
  }
  $bu_folder = 'public://' . variable_get('theme_default') . '_backup';
  if (file_prepare_directory($bu_folder) === FALSE) {
    drupal_mkdir($bu_folder);
  }
  $backup_dir = getDirectoryList('public://' . variable_get('theme_default') . '_backup');
  $list_files = array();
  if (!$backup_dir) {
    $backup_dir = array();
  }
  foreach ($backup_dir as $key => $value) {
    if (strpos((string) ($value), '' . str_replace('_', '-', variable_get('theme_default')) . '-backup') !== FALSE) {
      $list_files[$value] = $value;
    }
  }
  $form['md_structure_settings']['config']['restore']['restore_from_file'] = array(
    '#type' => 'select',
    '#options' => $list_files,
    '#title' => 'Choose your file you want to backup (Select list files are stored in "public://' . variable_get('theme_default') . '_backup" folder)',
    '#attributes' => array(
      'class' => array('select'),
    ),
    '#prefix' => '<div class="form-group">',
    '#suffix' => '</div>',
    '#field_prefix' => '<div class="md-selection big">',
    '#field_suffix' => '</div>',
    '#states' => array(
      'visible' => array(
        ':input[name="restore_type"]' => array(
          'value' => 'select'
        )
      )
    ),
  );
//  $form['md_structure_settings']['config']['restore']['restore_theme_settings'] = array(
//    '#type' => 'submit',
//    '#value' => t('Restore Settings'),
//    '#submit' => array('md_structure_backup_theme_settings'),
//  );

}

/**
 * Backup Theme Settings
 */
function md_structure_backup_theme_settings_submit() {
  $theme_settings = variable_get('theme_' . variable_get('theme_default') . '_settings');
  $current_time = time();
  $cv_datetime = date("Y-m-d", $current_time);
  $backup_file = serialize(base64_encode(drupal_json_encode($theme_settings)));
  $bu_folder = 'public://' . variable_get('theme_default') . '_backup';
  if (file_prepare_directory($bu_folder) === FALSE) {
    drupal_mkdir($bu_folder);
  }
  if (file_unmanaged_save_data($backup_file, $bu_folder . '/' . str_replace('_', '-', variable_get('theme_default')) . '-backup-' . $cv_datetime . '-' . $current_time . '.txt', FILE_EXISTS_REPLACE) === FALSE) {
    drupal_set_message(t("Could not create backup file."));
    return;
  }
  else {
    drupal_set_message(t("Backup Theme Settings Successful!"));
    drupal_set_message(t("Your backup settings is stored in " . file_create_url('' . $bu_folder . '/' . str_replace('_', '-', variable_get('theme_default')) . '-backup-' . $cv_datetime . '-' . $current_time . '.txt') . ""));
  }
}

