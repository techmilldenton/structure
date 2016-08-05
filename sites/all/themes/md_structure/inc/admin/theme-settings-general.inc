<?php

/**
 * @file
 * Theme settings general.
 */

function md_structure_theme_settings_general(&$form, &$form_state) {
  $form['md_structure_settings']['general'] = array(
    '#type' => 'fieldset',
    '#weight' => -5,
    '#prefix' => '<div id="md-general" class="md-tabcontent clearfix">',
    '#suffix' => '</div><!-- / #md-general -->',
  );

  $form['md_structure_settings']['general']['general_htmllist'] = array(
    '#markup' => '<div id="md-content-sidebar" class="md-content-sidebar">
                            <ul class="clearfix">
                                <li><a href="#general-settings"><i class="fa fa-home"></i>Sites Settings</a></li>
                                <li><a href="#logo-favicon-webclip"><i class="fa fa-picture-o"></i>Logo, Favicon &amp; Webclip</a></li>
                                <li><a href="#custom-font"><i class="fa fa-font"></i>Custom Font</a></li>
                            </ul>
                        </div><!-- /.md-content-sidebar -->
                  <div class="md-content-main">',
    '#weight' => -15,
  );
  $form['md_structure_settings']['general']['general_htmllistclose'] = array(
    '#markup' => '</div><!-- /.md-content-main -->',
    '#weight' => 15,
  );

  /* 1.General Settings
  --------------------------------------------------------------------------*/
  $form['md_structure_settings']['general']['general_settings'] = array(
    '#type' => 'fieldset',
    '#weight' => -14,
    '#prefix' => '<div id="general-settings" class="">',
    '#suffix' => '</div><!-- / #general-settings -->',
  );
  $form['md_structure_settings']['general']['general_settings']['general_setting_content'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<div class="md-tabcontent-row">',
    '#suffix' => '</div><!-- /.md-tabcontent-row -->'
  );
  $themes = list_themes();
  $features = $themes['md_structure']->info['features'];
  // Toggle settings
  $toggles = array(
    'logo' => t('Logo'),
    'name' => t('Site name'),
    'slogan' => t('Site slogan'),
    'node_user_picture' => t('User pictures in posts'),
    'comment_user_picture' => t('User pictures in comments'),
    'comment_user_verification' => t('User verification status in comments'),
    'main_menu' => t('Main menu'),
    'secondary_menu' => t('Secondary menu'),
  );

  // Some features are not always available
  $disabled = array();
  if (!variable_get('user_pictures', 0)) {
    $disabled['toggle_node_user_picture'] = TRUE;
    $disabled['toggle_comment_user_picture'] = TRUE;
  }
  if (!module_exists('comment')) {
    $disabled['toggle_comment_user_picture'] = TRUE;
    $disabled['toggle_comment_user_verification'] = TRUE;
  }

  $form['md_structure_settings']['general']['general_settings']['general_setting_content']['theme_settings'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<h3 class="md-tabcontent-title">Toggle Display</h3>',
    '#description' => t('Enable or disable the display of certain page elements.'),
  );
  foreach ($toggles as $name => $title) {
    if (in_array($name, $features)) {
      $form['md_structure_settings']['general']['general_settings']['general_setting_content']['theme_settings']['toggle_' . $name] = array(
        '#type' => 'checkbox',
        '#default_value' => theme_get_setting('toggle_' . $name),
        '#field_suffix' => '<label class="label-checkbox" for="edit-toggle-' . str_replace('_', '-', $name) . '">' . $title . '</label>',
        '#attributes' => array(
          'class' => array('input-checkbox')
        ),
        '#prefix' => '<div class="form-elements">',
        '#suffix' => '</div>',
      );
      // Disable checkboxes for features not supported in the current configuration.
      if (isset($disabled['toggle_' . $name])) {
        $form['md_structure_settings']['general']['general_settings']['general_setting_content']['theme_settings']['toggle_' . $name]['#disabled'] = TRUE;
      }
    }

  }
  if (in_array('favicon', $features)) {
    $form['md_structure_settings']['general']['general_settings']['general_setting_content']['theme_settings']['toggle_fvicon'] = array(
      '#type' => 'checkbox',
      '#default_value' => theme_get_setting('toggle_fvicon'),
      '#field_suffix' => '<label class="label-checkbox" for="edit-toggle-fvicon">Shortcut Icon</label>',
      '#attributes' => array(
        'class' => array('input-checkbox')
      ),
      '#prefix' => '<div class="form-elements">',
      '#suffix' => '</div>',
    );
  }

  if (!element_children($form['md_structure_settings']['general']['general_settings']['general_setting_content']['theme_settings'])) {
    // If there is no element in the theme settings fieldset then do not show
    // it -- but keep it in the form if another module wants to alter.
    $form['md_structure_settings']['general']['general_settings']['general_setting_content']['theme_settings']['#access'] = FALSE;
  }

  /* 2.	Logo, Favicon & Webclip
  --------------------------------------------------------------------------*/
  $form['md_structure_settings']['general']['logo_fav_webclip'] = array(
    '#type' => 'fieldset',
    '#weight' => -13,
    '#prefix' => '<div id="logo-favicon-webclip">',
    '#suffix' => '</div><!-- / #general-settings -->',
  );
  $form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<div class="md-tabcontent-row">',
    '#suffix' => '</div><!-- /.md-tabcontent-row -->'
  );


  // Logo settings

  $form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['logo'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<h3 class="md-tabcontent-title">Logo image settings</h3>',
    '#description' => t('If toggled on, the following logo will be displayed.'),
    '#attributes' => array('class' => array('theme-settings-bottom')),
    '#weight' => 1
  );
  $form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['logo']['default_logo'] = array(
    '#type' => 'checkbox',
    '#field_suffix' => '<label class="label-checkbox" for="edit-default-logo--2' . '">Use the default logo</label>',
    '#attributes' => array(
      'class' => array('input-checkbox')
    ),
    '#prefix' => '<div class="form-elements">',
    '#suffix' => '</div>',
    '#default_value' => theme_get_setting('default_logo'),
    '#tree' => FALSE,
    '#description' => t('Check here if you want the theme to use the logo supplied with it.')
  );
  $form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['logo']['settings'] = array(
    '#type' => 'container',
    '#states' => array(
      // Hide the logo settings when using the default logo.
      'invisible' => array(
        'input[name="default_logo"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['logo']['settings']['logo_normal'] = array(
    '#type' => 'container',
  );
  _build_form_upload_file($form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['logo']['settings']['logo_normal'], 'logo_normal', t('Logo Normal'));
  $form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['logo']['settings']['logo_retina'] = array(
    '#type' => 'container',
  );

  //$form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['logo']['settings']['logo_retina'] = _build_form_upload_file($form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['logo']['settings']['logo_retina'], 'logo_retina', t('Logo Retina'));

////////////////////////////////////////// FAVICON ///////////////////////////////////////////////////////////
  if (in_array('favicon', $features)) {
    $form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['favicon'] = array(
      '#type' => 'fieldset',
      '#prefix' => '<h3 class="md-tabcontent-title">Shortcut icon settings</h3>',
      '#description' => t("Your shortcut icon, or 'favicon', is displayed in the address bar and bookmarks of most browsers."),
      '#weight' => 2
    );
    $form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['favicon']['default_favicon'] = array(
      '#type' => 'checkbox',
      '#field_suffix' => '<label class="label-checkbox" for="edit-default-favicon--2' . '">Use the default shortcut icon.</label>',
      '#attributes' => array(
        'class' => array('input-checkbox')
      ),
      '#prefix' => '<div class="form-elements">',
      '#suffix' => '</div>',
      '#default_value' => theme_get_setting('default_favicon'),
      '#description' => t('Check here if you want the theme to use the default shortcut icon.')
    );
    $form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['favicon']['settings'] = array(
      '#type' => 'container',
      '#states' => array(
        // Hide the favicon settings when using the default favicon.
        'invisible' => array(
          'input[name="default_favicon"]' => array('checked' => TRUE),
        ),
      ),
    );

    _build_form_upload_file($form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['favicon']['settings'], 'favicon', t('Favicon'));

    // Inject human-friendly values for logo and favicon.
    foreach (array(
               'logo' => 'logo.png',
               'favicon' => 'favicon.ico'
             ) as $type => $default) {
      if (isset($form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content'][$type]['settings'][$type . '_path'])) {
        $element = &$form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content'][$type]['settings'][$type . '_path'];
        // If path is a public:// URI, display the path relative to the files
        // directory; stream wrappers are not end-user friendly.
        $original_path = $element['#default_value'];
        $friendly_path = NULL;
        if (file_uri_scheme($original_path) == 'public') {
          $friendly_path = file_uri_target($original_path);
          $element['#default_value'] = $friendly_path;
        }
      }
    }


    $form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['favicon_webclip'] = array(
      '#type' => 'fieldset',
      '#weight' => 3,
      '#prefix' => '<h3 class="md-tabcontent-title">Webclip settings</h3>',
      '#collapsible' => TRUE
    );

    $form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['favicon_webclip']['ios_57x57'] = array(
      '#type' => 'container'
    );
    _build_form_upload_file($form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['favicon_webclip']['ios_57x57'], 'ios_57x57', t('IOS 57x57'));

    $form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['favicon_webclip']['ios_72x72'] = array(
      '#type' => 'container'
    );
    _build_form_upload_file($form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['favicon_webclip']['ios_72x72'], 'ios_72x72', t('IOS 72x72'));

    $form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['favicon_webclip']['ios_114x114'] = array(
      '#type' => 'container'
    );
    _build_form_upload_file($form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['favicon_webclip']['ios_114x114'], 'ios_114x114', t('IOS 114x114'));

    $form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['favicon_webclip']['ios_144x144'] = array(
      '#type' => 'container'
    );
    _build_form_upload_file($form['md_structure_settings']['general']['logo_fav_webclip']['logo_fav_webclip_content']['favicon_webclip']['ios_144x144'], 'ios_144x144', t('IOS 144x144'));
  }


  /* 3.	Custom font
  --------------------------------------------------------------------------*/
  $form['md_structure_settings']['general']['custom_font'] = array(
    '#type' => 'fieldset',
    '#weight' => -12,
    '#prefix' => '<div id="custom-font">',
    '#suffix' => '</div><!-- / #general-settings -->',
  );
  $form['md_structure_settings']['general']['custom_font']['custom_font_content'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<div class="md-tabcontent-row">',
    '#suffix' => '</div><!-- /.md-tabcontent-row -->'
  );
  $form['md_structure_settings']['general']['custom_font']['custom_font_content']['googlewebfonts'] = array(
    '#type' => 'textarea',
    '#title' => t('@import'),
    '#resizable' => FALSE,
    '#rows' => 1,
    '#description' => t("For example: http://fonts.googleapis.com/css?family=Kavoon|Hanalei+Fill"),
    '#default_value' => theme_get_setting('googlewebfonts'),
    '#prefix' => '<h3 class="md-tabcontent-title">Google Web Fonts</h3>
        <ul class="steps">
            <li>Go to <a href="http://www.google.com/webfonts" target="_blank">www.google.com/webfonts</a>, choose your fonts and add to collection</li>
        <li>Click &quot;Use&quot; in the bottom bar after choose fonts</li>
        <li>Find &quot;Integrate the fonts into your CSS&quot;, copy all code from that field and paste it below to activate.</li>
        </ul>',
    '#attributes' => array(
      'class' => array('input-border')
    )
  );

  $form['md_structure_settings']['general']['custom_font']['custom_font_content']['custom_font']['typekit_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Typekit'),
    '#description' => t('<strong>* Note:</strong> Your kit must contain fonts and be published before entering your Typekit ID below. Check out <a href="http://help.typekit.com/customer/portal/articles/6780-adding-fonts-to-your-site" target="_blank">this article at Typekit\'s Help Center</a> for detailed information on how to add fonts to your kit. (Make sure you skip the part about adding CSS selectors, and remember to republish your kit after making any changes.)'),
    '#default_value' => theme_get_setting('typekit_id'),
    '#prefix' => '<h3 class="md-tabcontent-title">Enter Your Typekit ID</h3>
        <ul class="steps">
            <li>Go to <a href="http://typekit.com/" target="_blank">www.typekit.com</a> and Log in to your account</li>
            <li>In the top bar of the Typekit website, click the green &quot;Launch Kit Editor&quot; button.</li>
            <li>In the top bar of the popup that appears, click the &quot;Kit Settings&quot; link and paste your domain. Once you\'ve done this, click &quot;Save Settings.&quot;</li>
            <li>In the same top bar of the popup, click the &quot;embed code&quot; link.</li>
            <li>In the overlay that appears, there is a line at the   bottom that says, &quot;If you are using a plugin or service that asks for a   Typekit ID, use this: ____.&quot; This is your Typekit ID. Paste it below to activate.</li>
        </ul><div class="form-group">',
    '#suffix' => '</div>',
    '#attributes' => array(
      'class' => array('input-border big')
    )
  );


  /* Hidden input
  --------------------------------------------------------------------------*/
  $form['md_structure_settings']['general']['general_settings']['general_setting_content']['savedcolor1'] = array(
    '#type' => 'hidden',
    '#default_value' => theme_get_setting('savedcolor1'),
    '#attributes' => array(
      'id' => 'savedcolor1',
    ),
  );
}
