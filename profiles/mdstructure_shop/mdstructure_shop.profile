<?php
// 

/**
 * Implements hook_install_tasks()
 */
function mdstructure_shop_install_tasks(&$install_state) {

  $tasks = array();

  // Add our custom CSS file for the installation process
  drupal_add_css(drupal_get_path('profile', 'mdstructure_shop') . '/mdtheme.css');

  return $tasks;
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function mdstructure_shop_form_install_configure_form_alter(&$form, $form_state) {
  $form['site_information']['site_name']['#default_value'] = 'MD Structure Shop';
  $form['#submit'][] = 'mdstructure_shop_install_configure_form_submit';
}

/**
 * Forms API submit for the site configuration form.
 */
function mdstructure_shop_install_configure_form_submit($form, &$form_state) {
  global $user;
  $sql_file = dirname(__FILE__) . '/mdstructure_shop.sql';
  $count = mdstructure_shop_import_sql($sql_file);
  //drupal_set_message("MD Boom Multi Purpose Installation was a Success! Imported $count queries.");
  drupal_set_message("For security purposes, it's recommended that you delete $sql_file, or it out of your webroot.");
  //drupal_set_message(st('Congratulations, you installed MD A-Page.<br /><a href="@url">Visit your new site</a>.', array('@url' => url(''))));
  //drupal_set_message("Please ".l(t('clear your cache'), 'admin/config/development/performance')." before use MD Vastudio profile");

  variable_set('site_name', $form_state['values']['site_name']);
  variable_set('site_mail', $form_state['values']['site_mail']);
  variable_set('date_default_timezone', $form_state['values']['date_default_timezone']);
  variable_set('site_default_country', $form_state['values']['site_default_country']);

  // Enable update.module if this option was selected.
  if ($form_state['values']['update_status_module'][1]) {
    module_enable(array('update'), FALSE);

    // Add the site maintenance account's email address to the list of
    // addresses to be notified when updates are available, if selected.
    if ($form_state['values']['update_status_module'][2]) {
      variable_set('update_notify_emails', array($form_state['values']['account']['mail']));
    }
  }

  // We precreated user 1 with placeholder values. Let's save the real values.
  $account = user_load(1);
  $merge_data = array('init' => $form_state['values']['account']['mail'], 'roles' => !empty($account->roles) ? $account->roles : array(), 'status' => 1);
  user_save($account, array_merge($form_state['values']['account'], $merge_data));
  // Load global $user and perform final login tasks.
  $user = user_load(1);
  user_login_finalize();

  if (isset($form_state['values']['clean_url'])) {
    variable_set('clean_url', $form_state['values']['clean_url']);
  }

  // Record when this install ran.
  variable_set('install_time', $_SERVER['REQUEST_TIME']);
  //drupal_flush_all_caches();
  //cache_clear_all();
  //drupal_get_schema(NULL, TRUE);
  //drupal_cron_run();

}

function mdstructure_shop_import_sql($filename) {
  global $databases;
  $databasesName = array(
    "pgsql" => "PostgreSQL",
    "sqlite" => "SQLite"
  );

  // Backup current settings site
  $cron_key = db_select("variable", "v")
    ->fields("v")
    ->condition("name", "cron_key")
    ->range(0, 1)
    ->execute()
    ->fetchAssoc();

  $private_key = db_select("variable", "v")
    ->fields("v")
    ->condition("name", "drupal_private_key")
    ->range(0, 1)
    ->execute()
    ->fetchAssoc();

  // Import database from sql file
  $count = 0;
  $file = @fopen($filename, "r");
  if ($file) {
    $sql_command = "";

    // Open connect to database
    switch ($databases["default"]["default"]["driver"]) {
      case "mysql":
        $connect = new PDO(sprintf("mysql:host=%s;port=%s;dbname=%s", $databases["default"]["default"]["host"], $databases["default"]["default"]["port"], $databases["default"]["default"]["database"]), $databases["default"]["default"]["username"], $databases["default"]["default"]["password"]);
        break;

      case "pgsql":
        $connect = NULL;
        break;

      case "sqlite":
        $connect = NULL;
    }

    if ($connect) {
      while (!feof($file)) {
        $line = fgets($file);
        $sql_command .= $line;

        if (preg_match('|;$|', $line)) {
          try {
            $connect->exec(mdstructure_shop_prefixTables($sql_command));
          } catch (PDOException $ex) {
            pass;
          }
          $sql_command = "";
          $count++;
        }
      }

      // Restore site settings
      db_update("system")
        ->fields(array("status" => 1))
        ->condition("filename", "profiles/standard/standard.profile")
        ->execute();

      db_update("variable")
        ->fields(array("value" => $cron_key["value"]))
        ->condition("name", "cron_key")
        ->execute();
      db_update("variable")
        ->fields(array("value" => $private_key["value"]))
        ->condition("name", "drupal_private_key")
        ->execute();

      drupal_set_message(t("Import demo data successful."));

      // Close database connection
      $connect = NULL;
    }
    else {
      drupal_set_message(t(sprintf("Import demo data unsuccessful. We are only support demo data for MySQL database. You are using %s database.", $databasesName[$databases["default"]["default"]["driver"]])), "warning");
    }

    fclose($file);
  }

  return $count;
}

function mdstructure_shop_prefixTables($sql) {
  global $databases;
  $prefix = isset($databases["default"]["default"]["prefix"]) ? $databases["default"]["default"]["prefix"] : '';
  return str_replace("md7_", $prefix, $sql);
}