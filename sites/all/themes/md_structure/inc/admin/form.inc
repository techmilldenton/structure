<?php
/**
 * Author: Megadrupal
 * Contain functions generate some specify form for theme-settings
 */
/**
 * Build form upload file via media or form
 * $machine_name: unique name you choose for this form
 */
function _build_form_upload_file(&$form, $machine_name, $title) {
  $default_value = theme_get_setting($machine_name . '_file_uploaded');
  if (module_exists('media')) {
    $media_file = array('fid' => isset($default_value['fid']) ? intval($default_value['fid']) : 0);
    if ($media_file['fid'] && ($media_file = file_load($media_file['fid']))) {
      $media_file = get_object_vars($media_file);
    }

    $form[$machine_name . '_file_uploaded'] = array(
      '#type' => 'media',
      '#title' => t('Upload %title', array('%title' => $title)),
      '#default_value' => $media_file,
      '#input' => TRUE,
      '#extended' => TRUE
    );
  }
  else {
    $fid = array('fid' => 0);
    if ($default_value["{$machine_name}_file_uploaded"]) {
      if (isset($default_value["{$machine_name}_file_uploaded"]['fid'])) {
        $fid = $default_value["{$machine_name}_file_uploaded"];
      }
      else {
        $fid = array('fid' => $default_value["{$machine_name}_file_uploaded"]);
      }
    }

    $validators = array();
    $max_filesize = parse_size(file_upload_max_size());
    $validators['file_validate_size'] = array($max_filesize);
    $validators['file_validate_extensions'] = array('jpg jpeg png gif');

    $form["{$machine_name}_file_uploaded"] = array(
      '#type' => 'managed_file',
      '#title' => t('Upload %title', array('%title' => $title)),
      '#default_value' => $fid,
      '#upload_location' => 'public://',
      '#upload_validators' => $validators,
      '#extended' => TRUE,
      '#description' => theme('file_upload_help', array('upload_validators' => $validators))
    );
  }
}

/**
 * $machine_name: your unique name to create form
 * Contain background image, color, parallax setings, extra css settings, overlay (color, opacity).
 */
function _build_form_background_settings(&$form, $machine_name, $title) {
  $form['enable_' . $machine_name] = array(
    '#type' => 'checkbox',
    '#field_suffix' => '<label class="label-checkbox" for="edit-' . str_replace("_", "-", 'enable_' . $machine_name) . '' . '">' . t('Enable ' . $title . ' Background') . '</label>',
    '#attributes' => array(
      'class' => array('input-checkbox')
    ),
    '#prefix' => '<div class="form-elements">',
    '#suffix' => '</div>',
    '#default_value' => theme_get_setting('enable_' . $machine_name),
    '#tree' => FALSE,
  );
  $form[$machine_name . '_wrapper'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="enable_' . $machine_name . '"]' => array('checked' => TRUE)
      )
    )
  );
  $form[$machine_name . '_wrapper'][$machine_name . '_source'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<h4 class="md-tabcontent-title">' . t('' . $title . ' Background Source') . '</h4>
                                            <div class="form-group">',
    '#suffix' => '</div>',
  );
  // BACKGROUND COLORPICKER
  $form[$machine_name . '_wrapper'][$machine_name . '_source'][$machine_name . '_color'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="' . $machine_name . '_type"]' => array('value' => 'color')
      )
    )
  );
  $form[$machine_name . '_wrapper'][$machine_name . '_source'][$machine_name . '_color'][$machine_name . '_colorpicker'] = array(
    '#type' => 'textfield',
    '#prefix' => '<h5 class="md-row-title">' . t('Background Color') . '</h5><div class="form-group">',
    '#suffix' => '</div>',
    '#default_value' => theme_get_setting($machine_name . '_colorpicker'),
    '#attributes' => array(
      'class' => array('form-colorpicker')
    ),
  );

  // BACKGROUND SELECT IMAGE
  $form[$machine_name . '_wrapper'][$machine_name . '_source'][$machine_name . '_image'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="' . $machine_name . '_type"]' => array('value' => 'image')
      )
    )
  );
  $form[$machine_name . '_wrapper'][$machine_name . '_source'][$machine_name . '_image'][$machine_name . '_image_enable_parallax'] = array(
    '#type' => 'checkbox',
    '#field_suffix' => '<label class="label-checkbox" for="edit-' . str_replace("_", "-", $machine_name) . '-image-enable-parallax' . '">' . t('Enable Parallax Effect') . '</label>',
    '#attributes' => array(
      'class' => array('input-checkbox')
    ),
    '#prefix' => '<div class="form-group">',
    '#suffix' => '</div>',
    '#default_value' => theme_get_setting($machine_name . '_image_enable_parallax'),
  );
  $form[$machine_name . '_wrapper'][$machine_name . '_source'][$machine_name . '_image'][$machine_name . '_image_parallax'] = array(
    '#type' => 'fieldset',
    '#field_prefix' => '<h5 class="md-tabcontent-title">' . t('Parallax Settings') . '</h5><div class="form-group">',
    '#field_suffix' => '</div>',
    '#states' => array(
      'visible' => array(
        ':input[name="' . $machine_name . '_image_enable_parallax"]' => array('checked' => TRUE)
      )
    )
  );
  $form[$machine_name . '_wrapper'][$machine_name . '_source'][$machine_name . '_image'][$machine_name . '_image_parallax'][$machine_name . '_img_pr_xpos'] = array(
    '#type' => 'textfield',
    '#default_value' => theme_get_setting($machine_name . '_img_pr_xpos'),
    '#prefix' => '<div class="form-inline"><h5 class="md-row-title">' . t('X-Position') . '</h5>
                                                        <div class="form-group">',
    '#suffix' => '</div></div>',
    '#attributes' => array(
      'class' => array('input-border small')
    ),
  );
  $form[$machine_name . '_wrapper'][$machine_name . '_source'][$machine_name . '_image'][$machine_name . '_image_parallax'][$machine_name . '_img_pr_speed'] = array(
    '#type' => 'select',
    '#default_value' => theme_get_setting($machine_name . '_img_pr_speed'),
    '#options' => array(
      '0.1' => '0.1',
      '0.2' => '0.2',
      '0.3' => '0.3',
      '0.4' => '0.4',
      '0.5' => '0.5',
      '0.6' => '0.6',
      '0.7' => '0.7',
      '0.8' => '0.8',
      '0.9' => '0.9',
    ),
    '#attributes' => array(
      'class' => array('select')
    ),
    '#prefix' => '<div class="form-inline"><h5 class="md-row-title">' . t('SpeedFactor') . '</h5>
                                                        <div class="form-group">',
    '#suffix' => '</div></div>',
    '#field_prefix' => '<div class="md-selection small">',
    '#field_suffix' => '</div>'
  );
  $form[$machine_name . '_wrapper'][$machine_name . '_source'][$machine_name . '_image'][$machine_name . '_image_parallax'][$machine_name . '_img_pr_outerheight'] = array(
    '#type' => 'select',
    '#default_value' => theme_get_setting($machine_name . '_img_pr_outerheight'),
    '#options' => array(
      1 => 'true',
      0 => 'false',
    ),
    '#attributes' => array(
      'class' => array('select')
    ),
    '#prefix' => '<div class="form-inline"><h5 class="md-row-title">' . t('OuterHeight') . '</h5>
                                                        <div class="form-group">',
    '#suffix' => '</div></div>',
    '#field_prefix' => '<div class="md-selection small">',
    '#field_suffix' => '</div>'
  );

  _build_form_upload_file($form[$machine_name . '_wrapper'][$machine_name . '_source'][$machine_name . '_image'], $machine_name, $title);

  $form[$machine_name . '_wrapper'][$machine_name . '_extra_settings'] = array(
    '#type' => 'container',
    '#states' => array(
      'invisible' => array(
        ':input[name="' . $machine_name . '_image_enable_parallax"]' => array("checked" => TRUE)
      )
    )
  );
  $form[$machine_name . '_wrapper'][$machine_name . '_extra_settings'][$machine_name . '_extra_settings_wrapper'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<h4 class="md-tabcontent-title">' . t('' . $title . ' Background Extra Settings') . '</h4>
                                            <div class="form-group">',
    '#suffix' => '</div>',

  );

  // background repeat
  $form[$machine_name . '_wrapper'][$machine_name . '_extra_settings'][$machine_name . '_extra_settings_wrapper'][$machine_name . '_image_repeat'] = array(
    '#type' => 'select',
    '#options' => array(
      'no-repeat' => t('No repeat'),
      'repeat' => t('Repeat'),
      'repeat-x' => t('Repeat X'),
      'repeat-y' => t('Repeat Y'),
    ),
    '#default_value' => theme_get_setting($machine_name . '_image_repeat'),
    '#attributes' => array(
      'class' => array('select')
    ),
    '#prefix' => '<div class="form-inline"><h5 class="md-row-title">' . t('Repeat') . '</h5>
                                            <div class="form-group">',
    '#suffix' => '</div></div>',
    '#field_prefix' => '<div class="md-selection medium">',
    '#field_suffix' => '</div>'

  );

  // background position
  $form[$machine_name . '_wrapper'][$machine_name . '_extra_settings'][$machine_name . '_extra_settings_wrapper'][$machine_name . '_image_position'] = array(
    '#type' => 'select',
    '#options' => array(
      'center center' => t('Center Center'),
      'left top' => t('Left Top'),
      'left center' => t('Left Center'),
      'left bottom' => t('Left Bottom'),
      'center top' => t('Center Top'),
      'center bottom' => t('Center Bottom'),
      'right top' => t('Right Top'),
      'right center' => t('Right Center'),
      'right bottom' => t('Right Bottom'),
    ),
    '#default_value' => theme_get_setting($machine_name . '_image_position'),
    '#attributes' => array(
      'class' => array('select')
    ),
    '#prefix' => '<div class="form-inline"><h5 class="md-row-title">' . t('Position') . '</h5>
                                            <div class="form-group">',
    '#suffix' => '</div></div>',
    '#field_prefix' => '<div class="md-selection medium">',
    '#field_suffix' => '</div>'
  );

  // background attachment
  $form[$machine_name . '_wrapper'][$machine_name . '_extra_settings'][$machine_name . '_extra_settings_wrapper'][$machine_name . '_image_attachment'] = array(
    '#type' => 'select',
    '#options' => array(
      'fixed' => t('Fixed'),
      'scroll' => t('Scroll'),
    ),
    '#default_value' => theme_get_setting($machine_name . '_image_attachment'),
    '#attributes' => array(
      'class' => array('select')
    ),
    '#prefix' => '<div class="form-inline"><h5 class="md-row-title">' . t('Attachment') . '</h5>
                                            <div class="form-group">',
    '#suffix' => '</div></div>',
    '#field_prefix' => '<div class="md-selection medium">',
    '#field_suffix' => '</div>',

  );
  // OVERLAY SETTINGS
  $form[$machine_name . '_wrapper'][$machine_name . '_overlay'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<h4 class="md-tabcontent-title">' . t('' . $title . ' Background Overlay Settings') . '</h4>
                                            <div class="form-group">',
    '#suffix' => '</div>',
  );
  $form[$machine_name . '_wrapper'][$machine_name . '_overlay'][$machine_name . '_enable_overlay'] = array(
    '#type' => 'checkbox',
    '#field_suffix' => '<label class="label-checkbox" for="edit-' . str_replace("_", "-", $machine_name) . '-enable-overlay' . '">' . t('Enable Overlay') . '</label>',
    '#attributes' => array(
      'class' => array('input-checkbox')
    ),
    '#prefix' => '<div class="form-group">',
    '#suffix' => '</div>',
    '#default_value' => theme_get_setting($machine_name . '_enable_overlay'),
  );
  $form[$machine_name . '_wrapper'][$machine_name . '_overlay'][$machine_name . '_overlay_settings'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="' . $machine_name . '_enable_overlay"]' => array('checked' => TRUE)
      )
    )
  );
  $form[$machine_name . '_wrapper'][$machine_name . '_overlay'][$machine_name . '_overlay_settings'][$machine_name . '_overlay_colorpicker'] = array(
    '#type' => 'textfield',
    '#prefix' => '<div class="form-inline"><h5 class="md-row-title">' . t('Overlay Color') . '</h5><div class="form-group">',
    '#suffix' => '</div></div>',
    '#default_value' => theme_get_setting($machine_name . '_overlay_colorpicker'),
    '#attributes' => array(
      'class' => array('form-colorpicker')
    ),

  );
  $form[$machine_name . '_wrapper'][$machine_name . '_overlay'][$machine_name . '_overlay_settings'][$machine_name . '_overlay_opacity'] = array(
    '#type' => 'textfield',
    '#prefix' => '<div class="form-inline"><h5 class="md-row-title">' . t('Overlay Opacity') . '</h5>
                                                <div class="form-group">',
    '#suffix' => '</div></div>',
    '#attributes' => array(
      'class' => array('input-border small slider-range'),
      'data-max' => 100,
      'data-min' => 0,
      'data-divine' => 100,
      'data-value' => theme_get_setting($machine_name . '_overlay_opacity')
    ),
    '#default_value' => theme_get_setting($machine_name . '_overlay_opacity'),
  );

}

/**
 * Path/pages Options for some settings
 */
function _build_form_page_options(&$form, $machine_name, $title) {
  $form[$machine_name . '_page_options'] = array(
    '#type' => 'container',
    '#prefix' => '<div class="form-group">',
    '#suffix' => '</div>',
  );
  $form[$machine_name . '_page_options']['enable_' . $machine_name . '_page_options'] = array(
    '#type' => 'checkbox',
    '#field_suffix' => '<label class="label-checkbox" for="' . str_replace("_", "-", 'edit_enable_' . $machine_name . '_page_options') . '">' . t('Enable ' . $title . ' options for specific pages') . '</label>',
    '#attributes' => array(
      'class' => array('input-checkbox')
    ),
    '#prefix' => '<div class="form-elements">',
    '#suffix' => '</div>',
    '#default_value' => theme_get_setting('enable_' . $machine_name . '_page_options'),
    '#tree' => FALSE,
    '#description' => t('If you using "Delta & Context" modules to apply theme settings for specific paths or other condition, please uncheck this option')
  );
  $form[$machine_name . '_page_options'][$machine_name . '_options'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name=enable_' . $machine_name . '_page_options]' => array('checked' => TRUE)
      )
    )
  );
  $form[$machine_name . '_page_options'][$machine_name . '_options'][$machine_name . '_path_options'] = array(
    '#type' => 'radios',
    '#options' => array(
      'all_except' => t('All pages except those listed'),
      'only_listed' => t('Only the listed pages')
    ),
    '#default_value' => theme_get_setting($machine_name . '_path_options') ? theme_get_setting($machine_name . '_path_options') : 'all_except',
    '#prefix' => '<h3 class="md-tabcontent-title">' . t('' . $title . ' Settings') . '</h3><h5 class="md-tabcontent-title">Apply ' . $title . ' options on specific pages</h5>'
  );
  $form[$machine_name . '_page_options'][$machine_name . '_options'][$machine_name . '_path_list'] = array(
    '#type' => 'textarea',
    '#default_value' => theme_get_setting($machine_name . '_path_list'),
    '#prefix' => '',
    '#suffix' => '',
    '#attributes' => array(
      'class' => array('input-border')
    ),
    '#description' => t('Specify pages by using their paths. Enter one path per line. The "*" character is a wildcard. Example paths are blog for the blog page and blog/* for every personal blog. <front> is the front page.')
  );
}
