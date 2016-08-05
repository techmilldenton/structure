<?php
/**
 * @file
 * structure_shop.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function structure_shop_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'blog';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Blog';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Blog';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Multimedia */
  $handler->display->display_options['fields']['field_news_multimedia']['id'] = 'field_news_multimedia';
  $handler->display->display_options['fields']['field_news_multimedia']['table'] = 'field_data_field_news_multimedia';
  $handler->display->display_options['fields']['field_news_multimedia']['field'] = 'field_news_multimedia';
  $handler->display->display_options['fields']['field_news_multimedia']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_multimedia']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_news_tags']['id'] = 'field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['table'] = 'field_data_field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['field'] = 'field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'news' => 'news',
  );

  /* Display: Blog Classic */
  $handler = $view->new_display('block', 'Blog Classic', 'classic_blog');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Multimedia */
  $handler->display->display_options['fields']['field_news_multimedia']['id'] = 'field_news_multimedia';
  $handler->display->display_options['fields']['field_news_multimedia']['table'] = 'field_data_field_news_multimedia';
  $handler->display->display_options['fields']['field_news_multimedia']['field'] = 'field_news_multimedia';
  $handler->display->display_options['fields']['field_news_multimedia']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_multimedia']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_news_tags']['id'] = 'field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['table'] = 'field_data_field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['field'] = 'field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['delta_offset'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'node';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created_1']['custom_date_format'] = 'd';
  $handler->display->display_options['fields']['created_1']['second_date_format'] = 'long';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created_2']['id'] = 'created_2';
  $handler->display->display_options['fields']['created_2']['table'] = 'node';
  $handler->display->display_options['fields']['created_2']['field'] = 'created';
  $handler->display->display_options['fields']['created_2']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created_2']['custom_date_format'] = 'Y';
  $handler->display->display_options['fields']['created_2']['second_date_format'] = 'long';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';

  /* Display: Latest News */
  $handler = $view->new_display('block', 'Latest News', 'latest_news');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Multimedia */
  $handler->display->display_options['fields']['field_news_multimedia']['id'] = 'field_news_multimedia';
  $handler->display->display_options['fields']['field_news_multimedia']['table'] = 'field_data_field_news_multimedia';
  $handler->display->display_options['fields']['field_news_multimedia']['field'] = 'field_news_multimedia';
  $handler->display->display_options['fields']['field_news_multimedia']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_multimedia']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_news_tags']['id'] = 'field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['table'] = 'field_data_field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['field'] = 'field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['delta_offset'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F d, Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';

  /* Display: Blog Grid */
  $handler = $view->new_display('block', 'Blog Grid', 'grid_blog');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '40',
  );
  /* Field: Content: Multimedia */
  $handler->display->display_options['fields']['field_news_multimedia']['id'] = 'field_news_multimedia';
  $handler->display->display_options['fields']['field_news_multimedia']['table'] = 'field_data_field_news_multimedia';
  $handler->display->display_options['fields']['field_news_multimedia']['field'] = 'field_news_multimedia';
  $handler->display->display_options['fields']['field_news_multimedia']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_multimedia']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_news_tags']['id'] = 'field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['table'] = 'field_data_field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['field'] = 'field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['delta_offset'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F d, Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_news_thumbnail']['id'] = 'field_news_thumbnail';
  $handler->display->display_options['fields']['field_news_thumbnail']['table'] = 'field_data_field_news_thumbnail';
  $handler->display->display_options['fields']['field_news_thumbnail']['field'] = 'field_news_thumbnail';
  $handler->display->display_options['fields']['field_news_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_thumbnail']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_news_thumbnail']['settings'] = array(
    'url_type' => '0',
    'image_style' => '',
    'image_link' => '',
  );

  /* Display: Blog Grid 2 */
  $handler = $view->new_display('block', 'Blog Grid 2', 'grid_blog_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '40',
  );
  /* Field: Content: Multimedia */
  $handler->display->display_options['fields']['field_news_multimedia']['id'] = 'field_news_multimedia';
  $handler->display->display_options['fields']['field_news_multimedia']['table'] = 'field_data_field_news_multimedia';
  $handler->display->display_options['fields']['field_news_multimedia']['field'] = 'field_news_multimedia';
  $handler->display->display_options['fields']['field_news_multimedia']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_multimedia']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_news_tags']['id'] = 'field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['table'] = 'field_data_field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['field'] = 'field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['delta_offset'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F d, Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_news_thumbnail']['id'] = 'field_news_thumbnail';
  $handler->display->display_options['fields']['field_news_thumbnail']['table'] = 'field_data_field_news_thumbnail';
  $handler->display->display_options['fields']['field_news_thumbnail']['field'] = 'field_news_thumbnail';
  $handler->display->display_options['fields']['field_news_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_thumbnail']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_news_thumbnail']['settings'] = array(
    'url_type' => '0',
    'image_style' => '',
    'image_link' => '',
  );

  /* Display: Recent Posts */
  $handler = $view->new_display('block', 'Recent Posts', 'recent_posts');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_news_thumbnail']['id'] = 'field_news_thumbnail';
  $handler->display->display_options['fields']['field_news_thumbnail']['table'] = 'field_data_field_news_thumbnail';
  $handler->display->display_options['fields']['field_news_thumbnail']['field'] = 'field_news_thumbnail';
  $handler->display->display_options['fields']['field_news_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_thumbnail']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_news_thumbnail']['settings'] = array(
    'url_type' => '0',
    'image_style' => 'recent_post',
    'image_link' => '',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';

  /* Display: Blog by Taxonomy */
  $handler = $view->new_display('block', 'Blog by Taxonomy', 'taxonomy_blog');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Multimedia */
  $handler->display->display_options['fields']['field_news_multimedia']['id'] = 'field_news_multimedia';
  $handler->display->display_options['fields']['field_news_multimedia']['table'] = 'field_data_field_news_multimedia';
  $handler->display->display_options['fields']['field_news_multimedia']['field'] = 'field_news_multimedia';
  $handler->display->display_options['fields']['field_news_multimedia']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_multimedia']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_news_tags']['id'] = 'field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['table'] = 'field_data_field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['field'] = 'field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['delta_offset'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'node';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created_1']['custom_date_format'] = 'd';
  $handler->display->display_options['fields']['created_1']['second_date_format'] = 'long';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created_2']['id'] = 'created_2';
  $handler->display->display_options['fields']['created_2']['table'] = 'node';
  $handler->display->display_options['fields']['created_2']['field'] = 'created';
  $handler->display->display_options['fields']['created_2']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created_2']['custom_date_format'] = 'Y';
  $handler->display->display_options['fields']['created_2']['second_date_format'] = 'long';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = TRUE;
  $export['blog'] = $view;

  $view = new view();
  $view->name = 'blog_tags';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Blog Tags';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Blog Tags';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'tags' => 'tags',
  );

  /* Display: Tags */
  $handler = $view->new_display('block', 'Tags', 'tags_default');
  $export['blog_tags'] = $view;

  $view = new view();
  $view->name = 'portfolio';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Portfolio';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Portfolio';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['id'] = 'field_portfolio_thumbnail';
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['table'] = 'field_data_field_portfolio_thumbnail';
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['field'] = 'field_portfolio_thumbnail';
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['settings'] = array(
    'url_type' => '0',
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'portfolio' => 'portfolio',
  );

  /* Display: Portfolio Slider */
  $handler = $view->new_display('block', 'Portfolio Slider', 'slider_portfolio');

  /* Display: Portfolio Grid */
  $handler = $view->new_display('block', 'Portfolio Grid', 'grid_portfolio');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['id'] = 'field_portfolio_thumbnail';
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['table'] = 'field_data_field_portfolio_thumbnail';
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['field'] = 'field_portfolio_thumbnail';
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['settings'] = array(
    'url_type' => '0',
    'image_style' => 'portfolio_1',
    'image_link' => '',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_portfolio_categories']['id'] = 'field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['table'] = 'field_data_field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['field'] = 'field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_portfolio_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_portfolio_categories']['separator'] = ' // ';

  /* Display: Latest Portfolio */
  $handler = $view->new_display('block', 'Latest Portfolio', 'latest_portfolio');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';

  /* Display: Portfolio Grid 2 */
  $handler = $view->new_display('block', 'Portfolio Grid 2', 'grid_portfolio_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['id'] = 'field_portfolio_thumbnail';
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['table'] = 'field_data_field_portfolio_thumbnail';
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['field'] = 'field_portfolio_thumbnail';
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['settings'] = array(
    'url_type' => '0',
    'image_style' => 'portfolio_2',
    'image_link' => '',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_portfolio_categories']['id'] = 'field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['table'] = 'field_data_field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['field'] = 'field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_portfolio_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_portfolio_categories']['separator'] = ' // ';

  /* Display: Portfolio Grid 3 */
  $handler = $view->new_display('block', 'Portfolio Grid 3', 'grid_portfolio_3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['id'] = 'field_portfolio_thumbnail';
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['table'] = 'field_data_field_portfolio_thumbnail';
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['field'] = 'field_portfolio_thumbnail';
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_portfolio_thumbnail']['settings'] = array(
    'url_type' => '0',
    'image_style' => 'portfolio_2',
    'image_link' => '',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_portfolio_categories']['id'] = 'field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['table'] = 'field_data_field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['field'] = 'field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_portfolio_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_portfolio_categories']['separator'] = ' // ';
  $export['portfolio'] = $view;

  $view = new view();
  $view->name = 'product_categories';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Product Categories';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Product Categories';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Taxonomy term: Content with term */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'taxonomy_index';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: COUNT(Taxonomy term: Name) */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_1']['prefix'] = '(';
  $handler->display->display_options['fields']['name_1']['suffix'] = ')';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'product_categories' => 'product_categories',
  );

  /* Display: Product Categories */
  $handler = $view->new_display('block', 'Product Categories', 'block');
  $export['product_categories'] = $view;

  $view = new view();
  $view->name = 'shop';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Shop';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Shop';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Content: Referenced products */
  $handler->display->display_options['relationships']['field_product_ref_product_id']['id'] = 'field_product_ref_product_id';
  $handler->display->display_options['relationships']['field_product_ref_product_id']['table'] = 'field_data_field_product_ref';
  $handler->display->display_options['relationships']['field_product_ref_product_id']['field'] = 'field_product_ref_product_id';
  $handler->display->display_options['relationships']['field_product_ref_product_id']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_product_thumbnail']['id'] = 'field_product_thumbnail';
  $handler->display->display_options['fields']['field_product_thumbnail']['table'] = 'field_data_field_product_thumbnail';
  $handler->display->display_options['fields']['field_product_thumbnail']['field'] = 'field_product_thumbnail';
  $handler->display->display_options['fields']['field_product_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_product_thumbnail']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_product_thumbnail']['settings'] = array(
    'url_type' => '0',
    'image_style' => 'product_1',
    'image_link' => '',
  );
  /* Field: Commerce Product: Add to Cart form */
  $handler->display->display_options['fields']['add_to_cart_form']['id'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['table'] = 'views_entity_commerce_product';
  $handler->display->display_options['fields']['add_to_cart_form']['field'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['relationship'] = 'field_product_ref_product_id';
  /* Field: Commerce Product: Discount Price */
  $handler->display->display_options['fields']['field_commerce_discount']['id'] = 'field_commerce_discount';
  $handler->display->display_options['fields']['field_commerce_discount']['table'] = 'field_data_field_commerce_discount';
  $handler->display->display_options['fields']['field_commerce_discount']['field'] = 'field_commerce_discount';
  $handler->display->display_options['fields']['field_commerce_discount']['relationship'] = 'field_product_ref_product_id';
  $handler->display->display_options['fields']['field_commerce_discount']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['field_commerce_discount']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'field_product_ref_product_id';
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => '0',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
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
    'product' => 'product',
  );

  /* Display: Shop Default */
  $handler = $view->new_display('block', 'Shop Default', 'default_shop');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Sort by date';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Sort by title';
  /* Sort criterion: Commerce Product: Price (commerce_price:amount) */
  $handler->display->display_options['sorts']['commerce_price_amount']['id'] = 'commerce_price_amount';
  $handler->display->display_options['sorts']['commerce_price_amount']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['sorts']['commerce_price_amount']['field'] = 'commerce_price_amount';
  $handler->display->display_options['sorts']['commerce_price_amount']['relationship'] = 'field_product_ref_product_id';
  $handler->display->display_options['sorts']['commerce_price_amount']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['commerce_price_amount']['expose']['label'] = 'Sort by price';

  /* Display: Shop Fullwidth */
  $handler = $view->new_display('block', 'Shop Fullwidth', 'fullwidth_shop');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_product_thumbnail']['id'] = 'field_product_thumbnail';
  $handler->display->display_options['fields']['field_product_thumbnail']['table'] = 'field_data_field_product_thumbnail';
  $handler->display->display_options['fields']['field_product_thumbnail']['field'] = 'field_product_thumbnail';
  $handler->display->display_options['fields']['field_product_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_product_thumbnail']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_product_thumbnail']['settings'] = array(
    'url_type' => '0',
    'image_style' => 'product_1',
    'image_link' => '',
  );
  /* Field: Commerce Product: Add to Cart form */
  $handler->display->display_options['fields']['add_to_cart_form']['id'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['table'] = 'views_entity_commerce_product';
  $handler->display->display_options['fields']['add_to_cart_form']['field'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['relationship'] = 'field_product_ref_product_id';
  /* Field: Commerce Product: Discount Price */
  $handler->display->display_options['fields']['field_commerce_discount']['id'] = 'field_commerce_discount';
  $handler->display->display_options['fields']['field_commerce_discount']['table'] = 'field_data_field_commerce_discount';
  $handler->display->display_options['fields']['field_commerce_discount']['field'] = 'field_commerce_discount';
  $handler->display->display_options['fields']['field_commerce_discount']['relationship'] = 'field_product_ref_product_id';
  $handler->display->display_options['fields']['field_commerce_discount']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['field_commerce_discount']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'field_product_ref_product_id';
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => '0',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_product_categories']['id'] = 'field_product_categories';
  $handler->display->display_options['fields']['field_product_categories']['table'] = 'field_data_field_product_categories';
  $handler->display->display_options['fields']['field_product_categories']['field'] = 'field_product_categories';
  $handler->display->display_options['fields']['field_product_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_product_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_product_categories']['separator'] = ' // ';

  /* Display: Recent Shop */
  $handler = $view->new_display('block', 'Recent Shop', 'recent_shop');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_product_thumbnail']['id'] = 'field_product_thumbnail';
  $handler->display->display_options['fields']['field_product_thumbnail']['table'] = 'field_data_field_product_thumbnail';
  $handler->display->display_options['fields']['field_product_thumbnail']['field'] = 'field_product_thumbnail';
  $handler->display->display_options['fields']['field_product_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_product_thumbnail']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_product_thumbnail']['settings'] = array(
    'url_type' => '0',
    'image_style' => 'product_5',
    'image_link' => '',
  );
  /* Field: Commerce Product: Add to Cart form */
  $handler->display->display_options['fields']['add_to_cart_form']['id'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['table'] = 'views_entity_commerce_product';
  $handler->display->display_options['fields']['add_to_cart_form']['field'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['relationship'] = 'field_product_ref_product_id';
  /* Field: Commerce Product: Discount Price */
  $handler->display->display_options['fields']['field_commerce_discount']['id'] = 'field_commerce_discount';
  $handler->display->display_options['fields']['field_commerce_discount']['table'] = 'field_data_field_commerce_discount';
  $handler->display->display_options['fields']['field_commerce_discount']['field'] = 'field_commerce_discount';
  $handler->display->display_options['fields']['field_commerce_discount']['relationship'] = 'field_product_ref_product_id';
  $handler->display->display_options['fields']['field_commerce_discount']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['field_commerce_discount']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'field_product_ref_product_id';
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => '0',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Sort by date';

  /* Display: Shop by Taxonomy */
  $handler = $view->new_display('block', 'Shop by Taxonomy', 'taxonomy_shop');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Sort by date';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = TRUE;

  /* Display: Shop Slider */
  $handler = $view->new_display('block', 'Shop Slider', 'slider_shop');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest Products';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_product_thumbnail']['id'] = 'field_product_thumbnail';
  $handler->display->display_options['fields']['field_product_thumbnail']['table'] = 'field_data_field_product_thumbnail';
  $handler->display->display_options['fields']['field_product_thumbnail']['field'] = 'field_product_thumbnail';
  $handler->display->display_options['fields']['field_product_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_product_thumbnail']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_product_thumbnail']['settings'] = array(
    'url_type' => '0',
    'image_style' => 'product_1',
    'image_link' => '',
  );
  /* Field: Commerce Product: Add to Cart form */
  $handler->display->display_options['fields']['add_to_cart_form']['id'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['table'] = 'views_entity_commerce_product';
  $handler->display->display_options['fields']['add_to_cart_form']['field'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['relationship'] = 'field_product_ref_product_id';
  /* Field: Commerce Product: Discount Price */
  $handler->display->display_options['fields']['field_commerce_discount']['id'] = 'field_commerce_discount';
  $handler->display->display_options['fields']['field_commerce_discount']['table'] = 'field_data_field_commerce_discount';
  $handler->display->display_options['fields']['field_commerce_discount']['field'] = 'field_commerce_discount';
  $handler->display->display_options['fields']['field_commerce_discount']['relationship'] = 'field_product_ref_product_id';
  $handler->display->display_options['fields']['field_commerce_discount']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['field_commerce_discount']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'field_product_ref_product_id';
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => '0',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Sort by date';
  $export['shop'] = $view;

  return $export;
}
