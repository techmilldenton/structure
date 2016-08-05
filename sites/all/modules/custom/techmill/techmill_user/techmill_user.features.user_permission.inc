<?php
/**
 * @file
 * techmill_user.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function techmill_user_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_user_title'.
  $permissions['create field_user_title'] = array(
    'name' => 'create field_user_title',
    'roles' => array(
      'Board Member' => 'Board Member',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_user_title'.
  $permissions['edit field_user_title'] = array(
    'name' => 'edit field_user_title',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_user_title'.
  $permissions['edit own field_user_title'] = array(
    'name' => 'edit own field_user_title',
    'roles' => array(
      'Board Member' => 'Board Member',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_user_title'.
  $permissions['view field_user_title'] = array(
    'name' => 'view field_user_title',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_user_title'.
  $permissions['view own field_user_title'] = array(
    'name' => 'view own field_user_title',
    'roles' => array(
      'Board Member' => 'Board Member',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
