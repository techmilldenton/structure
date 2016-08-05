<?php
/**
 * @file
 * techmill_meetup.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function techmill_meetup_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'meetup_calendar';
  $view->description = '';
  $view->tag = 'Calendar';
  $view->base_table = 'node';
  $view->human_name = 'Meetup Calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_meetup_date']['id'] = 'field_meetup_date';
  $handler->display->display_options['fields']['field_meetup_date']['table'] = 'field_data_field_meetup_date';
  $handler->display->display_options['fields']['field_meetup_date']['field'] = 'field_meetup_date';
  $handler->display->display_options['fields']['field_meetup_date']['label'] = '';
  $handler->display->display_options['fields']['field_meetup_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_meetup_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_meetup_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_meetup_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_meetup_date']['delta_offset'] = '0';
  /* Sort criterion: Content: Date (field_meetup_date) */
  $handler->display->display_options['sorts']['field_meetup_date_value']['id'] = 'field_meetup_date_value';
  $handler->display->display_options['sorts']['field_meetup_date_value']['table'] = 'field_data_field_meetup_date';
  $handler->display->display_options['sorts']['field_meetup_date_value']['field'] = 'field_meetup_date_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Month */
  $handler = $view->new_display('page', 'Month', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['colors']['legend'] = 'type';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_meetup_date.field_meetup_date_value' => 'field_data_field_meetup_date.field_meetup_date_value',
  );
  $handler->display->display_options['metatags'] = array(
    'und' => array(
      'title' => array(
        'value' => 'Meetups | [site:name]',
        'default' => '[view:title] | [site:name]',
      ),
      'description' => array(
        'value' => 'A calendar of meetups for the Denton Tech scene, curated by TechMill and the StartupDentonTech meetup group.',
        'default' => '[view:description]',
      ),
      'abstract' => array(
        'value' => '',
      ),
      'keywords' => array(
        'value' => '',
      ),
      'robots' => array(
        'value' => array(
          'index' => 0,
          'follow' => 0,
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
      'news_keywords' => array(
        'value' => '',
      ),
      'standout' => array(
        'value' => '',
      ),
      'rights' => array(
        'value' => '',
      ),
      'image_src' => array(
        'value' => '',
      ),
      'canonical' => array(
        'value' => '[view:url]',
        'default' => '[view:url]',
      ),
      'shortlink' => array(
        'value' => '[current-page:url:unaliased]',
        'default' => '[current-page:url:unaliased]',
      ),
      'publisher' => array(
        'value' => '',
      ),
      'author' => array(
        'value' => '',
      ),
      'original-source' => array(
        'value' => '',
      ),
      'revisit-after' => array(
        'value' => '',
        'period' => '',
      ),
      'content-language' => array(
        'value' => '',
      ),
      'dcterms.title' => array(
        'value' => '[current-page:title]',
        'default' => '[current-page:title]',
      ),
      'dcterms.creator' => array(
        'value' => '',
      ),
      'dcterms.subject' => array(
        'value' => '',
      ),
      'dcterms.description' => array(
        'value' => '',
      ),
      'dcterms.publisher' => array(
        'value' => '',
      ),
      'dcterms.contributor' => array(
        'value' => '',
      ),
      'dcterms.date' => array(
        'value' => '',
      ),
      'dcterms.modified' => array(
        'value' => '',
      ),
      'dcterms.type' => array(
        'value' => 'Text',
        'default' => 'Text',
      ),
      'dcterms.format' => array(
        'value' => 'text/html',
        'default' => 'text/html',
      ),
      'dcterms.identifier' => array(
        'value' => '[current-page:url:absolute]',
        'default' => '[current-page:url:absolute]',
      ),
      'dcterms.source' => array(
        'value' => '',
      ),
      'dcterms.language' => array(
        'value' => '',
      ),
      'dcterms.relation' => array(
        'value' => '',
      ),
      'dcterms.coverage' => array(
        'value' => '',
      ),
      'dcterms.rights' => array(
        'value' => '',
      ),
      'og:type' => array(
        'value' => 'article',
        'default' => 'article',
      ),
      'og:url' => array(
        'value' => '[current-page:url:absolute]',
        'default' => '[current-page:url:absolute]',
      ),
      'og:title' => array(
        'value' => '[current-page:title]',
        'default' => '[current-page:title]',
      ),
      'og:determiner' => array(
        'value' => '',
      ),
      'og:description' => array(
        'value' => '',
      ),
      'og:updated_time' => array(
        'value' => '',
      ),
      'og:see_also' => array(
        'value' => '',
      ),
      'og:image' => array(
        'value' => '',
      ),
      'og:image:secure_url' => array(
        'value' => '',
      ),
      'og:image:type' => array(
        'value' => '',
      ),
      'og:image:width' => array(
        'value' => '',
      ),
      'og:image:height' => array(
        'value' => '',
      ),
      'og:latitude' => array(
        'value' => '',
      ),
      'og:longitude' => array(
        'value' => '',
      ),
      'og:street-address' => array(
        'value' => '',
      ),
      'og:locality' => array(
        'value' => '',
      ),
      'og:region' => array(
        'value' => '',
      ),
      'og:postal-code' => array(
        'value' => '',
      ),
      'og:country-name' => array(
        'value' => '',
      ),
      'og:email' => array(
        'value' => '',
      ),
      'og:phone_number' => array(
        'value' => '',
      ),
      'og:fax_number' => array(
        'value' => '',
      ),
      'og:locale' => array(
        'value' => '',
      ),
      'og:locale:alternate' => array(
        'value' => '',
      ),
      'article:author' => array(
        'value' => '',
      ),
      'article:publisher' => array(
        'value' => '',
      ),
      'article:section' => array(
        'value' => '',
      ),
      'article:tag' => array(
        'value' => '',
      ),
      'article:published_time' => array(
        'value' => '',
      ),
      'article:modified_time' => array(
        'value' => '',
      ),
      'article:expiration_time' => array(
        'value' => '',
      ),
      'profile:first_name' => array(
        'value' => '',
      ),
      'profile:last_name' => array(
        'value' => '',
      ),
      'profile:username' => array(
        'value' => '',
      ),
      'profile:gender' => array(
        'value' => '',
      ),
      'og:audio' => array(
        'value' => '',
      ),
      'og:audio:secure_url' => array(
        'value' => '',
      ),
      'og:audio:type' => array(
        'value' => '',
      ),
      'book:author' => array(
        'value' => '',
      ),
      'book:isbn' => array(
        'value' => '',
      ),
      'book:release_date' => array(
        'value' => '',
      ),
      'book:tag' => array(
        'value' => '',
      ),
      'og:video' => array(
        'value' => '',
      ),
      'og:video:secure_url' => array(
        'value' => '',
      ),
      'og:video:width' => array(
        'value' => '',
      ),
      'og:video:height' => array(
        'value' => '',
      ),
      'og:video:type' => array(
        'value' => '',
      ),
      'video:actor' => array(
        'value' => '',
      ),
      'video:actor:role' => array(
        'value' => '',
      ),
      'video:director' => array(
        'value' => '',
      ),
      'video:writer' => array(
        'value' => '',
      ),
      'video:duration' => array(
        'value' => '',
      ),
      'video:release_date' => array(
        'value' => '',
      ),
      'video:tag' => array(
        'value' => '',
      ),
      'video:series' => array(
        'value' => '',
      ),
    ),
  );
  $handler->display->display_options['path'] = 'meetup';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Month';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Calendar';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Week */
  $handler = $view->new_display('page', 'Week', 'page_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'week';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'week';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'week';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_meetup_date.field_meetup_date_value' => 'field_data_field_meetup_date.field_meetup_date_value',
  );
  $handler->display->display_options['path'] = 'meetups/week';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Week';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Upcoming */
  $handler = $view->new_display('block', 'Upcoming', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Meetups';
  $handler->display->display_options['display_description'] = 'Upcoming events block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_meetup_date.field_meetup_date_value' => 'field_data_field_meetup_date.field_meetup_date_value',
  );
  $export['meetup_calendar'] = $view;

  return $export;
}
