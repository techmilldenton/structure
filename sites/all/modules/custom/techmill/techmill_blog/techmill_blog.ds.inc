<?php
/**
 * @file
 * techmill_blog.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function techmill_blog_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|blog_post|blog_featured';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'blog_post';
  $ds_fieldsetting->view_mode = 'blog_featured';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'exclude node title settings' => '0',
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
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
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_blog_featured_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_blog_categories' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['node|blog_post|blog_featured'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|blog_post|blog_micro';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'blog_post';
  $ds_fieldsetting->view_mode = 'blog_micro';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => '',
        'exclude node title settings' => '1',
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
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
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['node|blog_post|blog_micro'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|blog_post|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'blog_post';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'disqus_comments' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
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
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_blog_featured_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_blog_tags' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_blog_categories' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['node|blog_post|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|blog_post|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'blog_post';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'stacked_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
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
      ),
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'exclude node title settings' => '0',
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
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
      ),
    ),
    'author' => array(
      'weight' => '3',
      'label' => 'inline',
      'format' => 'author_linked',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
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
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_blog_featured_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['node|blog_post|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function techmill_blog_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'disqus_comments';
  $ds_field->label = 'Disqus: Comments';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'disqus|disqus_comments',
    'block_render' => '1',
  );
  $export['disqus_comments'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'stacked_date';
  $ds_field->label = 'Stacked Date';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<div class="style-date-stacked">
  <span class="day">[node:created:custom:d]</span>
  <span class="month">[node:created:custom:M]</span>
</div>',
      'format' => 'advanced_html',
    ),
    'use_token' => 1,
  );
  $export['stacked_date'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function techmill_blog_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blog_post|blog_featured';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blog_post';
  $ds_layout->view_mode = 'blog_featured';
  $ds_layout->layout = 'bootstrap_5_7';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_blog_featured_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'body',
        3 => 'field_blog_categories',
      ),
    ),
    'fields' => array(
      'field_blog_featured_image' => 'left',
      'title' => 'right',
      'body' => 'right',
      'field_blog_categories' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'left' => array(
        'pull-right' => 'pull-right',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|blog_post|blog_featured'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blog_post|blog_micro';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blog_post';
  $ds_layout->view_mode = 'blog_micro';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|blog_post|blog_micro'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blog_post|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blog_post';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_blog_featured_image',
        1 => 'body',
        2 => 'field_blog_categories',
        3 => 'field_blog_tags',
        4 => 'techmill_board_entity_view_1',
        5 => 'disqus_comments',
      ),
    ),
    'fields' => array(
      'field_blog_featured_image' => 'ds_content',
      'body' => 'ds_content',
      'field_blog_categories' => 'ds_content',
      'field_blog_tags' => 'ds_content',
      'techmill_board_entity_view_1' => 'ds_content',
      'disqus_comments' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|blog_post|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blog_post|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blog_post';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_blog_featured_image',
        1 => 'title',
      ),
      'left' => array(
        2 => 'stacked_date',
      ),
      'right' => array(
        3 => 'author',
        4 => 'body',
      ),
    ),
    'fields' => array(
      'field_blog_featured_image' => 'header',
      'title' => 'header',
      'stacked_date' => 'left',
      'author' => 'right',
      'body' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        'well' => 'well',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|blog_post|teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function techmill_blog_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'blog_featured';
  $ds_view_mode->label = 'Blog Featured';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['blog_featured'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'blog_micro';
  $ds_view_mode->label = 'Blog Micro';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['blog_micro'] = $ds_view_mode;

  return $export;
}
