<?php
/**
 * @file
 * techmill_partners.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function techmill_partners_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'community_partners';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Community Partners';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'responsive_grid';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_partner_sponsor_level',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['style_options']['column_classes'] = 'views-column col-sm-6 col-md-3';
  $handler->display->display_options['style_options']['row_classes'] = 'views-row row';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relationship: Content: Sponsor Level (field_partner_sponsor_level) */
  $handler->display->display_options['relationships']['field_partner_sponsor_level_tid']['id'] = 'field_partner_sponsor_level_tid';
  $handler->display->display_options['relationships']['field_partner_sponsor_level_tid']['table'] = 'field_data_field_partner_sponsor_level';
  $handler->display->display_options['relationships']['field_partner_sponsor_level_tid']['field'] = 'field_partner_sponsor_level_tid';
  $handler->display->display_options['relationships']['field_partner_sponsor_level_tid']['label'] = 'Sponsor Level';
  $handler->display->display_options['relationships']['field_partner_sponsor_level_tid']['required'] = TRUE;
  /* Field: Content: Sponsor Level */
  $handler->display->display_options['fields']['field_partner_sponsor_level']['id'] = 'field_partner_sponsor_level';
  $handler->display->display_options['fields']['field_partner_sponsor_level']['table'] = 'field_data_field_partner_sponsor_level';
  $handler->display->display_options['fields']['field_partner_sponsor_level']['field'] = 'field_partner_sponsor_level';
  $handler->display->display_options['fields']['field_partner_sponsor_level']['label'] = '';
  $handler->display->display_options['fields']['field_partner_sponsor_level']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_sponsor_level']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_partner_sponsor_level']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_partner_sponsor_level_tid';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'partner' => 'partner',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['community_partners'] = $view;

  return $export;
}
