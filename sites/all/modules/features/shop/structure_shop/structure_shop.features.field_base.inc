<?php
/**
 * @file
 * structure_shop.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function structure_shop_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'body'.
  $field_bases['body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'node',
    ),
    'field_name' => 'body',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'comment_body'.
  $field_bases['comment_body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'comment',
    ),
    'field_name' => 'comment_body',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'commerce_customer_address'.
  $field_bases['commerce_customer_address'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_customer_profile',
    ),
    'field_name' => 'commerce_customer_address',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'addressfield',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'addressfield',
  );

  // Exported field_base: 'commerce_customer_billing'.
  $field_bases['commerce_customer_billing'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_order',
    ),
    'field_name' => 'commerce_customer_billing',
    'indexes' => array(
      'profile_id' => array(
        0 => 'profile_id',
      ),
    ),
    'locked' => 0,
    'module' => 'commerce_customer',
    'settings' => array(
      'options_list_limit' => 50,
      'profile_type' => 'billing',
    ),
    'translatable' => 0,
    'type' => 'commerce_customer_profile_reference',
  );

  // Exported field_base: 'commerce_display_path'.
  $field_bases['commerce_display_path'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_line_item',
    ),
    'field_name' => 'commerce_display_path',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'commerce_line_items'.
  $field_bases['commerce_line_items'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_order',
    ),
    'field_name' => 'commerce_line_items',
    'indexes' => array(
      'line_item_id' => array(
        0 => 'line_item_id',
      ),
    ),
    'locked' => 1,
    'module' => 'commerce_line_item',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'commerce_line_item_reference',
  );

  // Exported field_base: 'commerce_order_total'.
  $field_bases['commerce_order_total'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_order',
    ),
    'field_name' => 'commerce_order_total',
    'indexes' => array(
      'currency_price' => array(
        0 => 'amount',
        1 => 'currency_code',
      ),
    ),
    'locked' => 1,
    'module' => 'commerce_price',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'commerce_price',
  );

  // Exported field_base: 'commerce_price'.
  $field_bases['commerce_price'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_product',
    ),
    'field_name' => 'commerce_price',
    'indexes' => array(
      'currency_price' => array(
        0 => 'amount',
        1 => 'currency_code',
      ),
    ),
    'locked' => 1,
    'module' => 'commerce_price',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'commerce_price',
  );

  // Exported field_base: 'commerce_product'.
  $field_bases['commerce_product'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_line_item',
    ),
    'field_name' => 'commerce_product',
    'indexes' => array(
      'product_id' => array(
        0 => 'product_id',
      ),
    ),
    'locked' => 1,
    'module' => 'commerce_product_reference',
    'settings' => array(
      'options_list_limit' => NULL,
    ),
    'translatable' => 0,
    'type' => 'commerce_product_reference',
  );

  // Exported field_base: 'commerce_total'.
  $field_bases['commerce_total'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_line_item',
    ),
    'field_name' => 'commerce_total',
    'indexes' => array(
      'currency_price' => array(
        0 => 'amount',
        1 => 'currency_code',
      ),
    ),
    'locked' => 1,
    'module' => 'commerce_price',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'commerce_price',
  );

  // Exported field_base: 'commerce_unit_price'.
  $field_bases['commerce_unit_price'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_line_item',
    ),
    'field_name' => 'commerce_unit_price',
    'indexes' => array(
      'currency_price' => array(
        0 => 'amount',
        1 => 'currency_code',
      ),
    ),
    'locked' => 1,
    'module' => 'commerce_price',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'commerce_price',
  );

  // Exported field_base: 'field_account_about'.
  $field_bases['field_account_about'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_account_about',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_banner_background_image'.
  $field_bases['field_banner_background_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_banner_background_image',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_comment_email'.
  $field_bases['field_comment_email'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_comment_email',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'email',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'email',
  );

  // Exported field_base: 'field_comment_website'.
  $field_bases['field_comment_website'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_comment_website',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_commerce_discount'.
  $field_bases['field_commerce_discount'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_commerce_discount',
    'indexes' => array(
      'currency_price' => array(
        0 => 'amount',
        1 => 'currency_code',
      ),
    ),
    'locked' => 0,
    'module' => 'commerce_price',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'commerce_price',
  );

  // Exported field_base: 'field_contact_header_icon'.
  $field_bases['field_contact_header_icon'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_contact_header_icon',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'fa-glass' => 'fa-glass',
        'fa-music' => 'fa-music',
        'fa-search' => 'fa-search',
        'fa-envelope-o' => 'fa-envelope-o',
        'fa-heart' => 'fa-heart',
        'fa-star' => 'fa-star',
        'fa-star-o' => 'fa-star-o',
        'fa-user' => 'fa-user',
        'fa-film' => 'fa-film',
        'fa-th-large' => 'fa-th-large',
        'fa-th' => 'fa-th',
        'fa-th-list' => 'fa-th-list',
        'fa-check' => 'fa-check',
        'fa-times' => 'fa-times',
        'fa-search-plus' => 'fa-search-plus',
        'fa-search-minus' => 'fa-search-minus',
        'fa-power-off' => 'fa-power-off',
        'fa-signal' => 'fa-signal',
        'fa-gear' => 'fa-gear',
        'fa-cog' => 'fa-cog',
        'fa-trash-o' => 'fa-trash-o',
        'fa-home' => 'fa-home',
        'fa-file-o' => 'fa-file-o',
        'fa-clock-o' => 'fa-clock-o',
        'fa-road' => 'fa-road',
        'fa-download' => 'fa-download',
        'fa-arrow-circle-o-down' => 'fa-arrow-circle-o-down',
        'fa-arrow-circle-o-up' => 'fa-arrow-circle-o-up',
        'fa-inbox' => 'fa-inbox',
        'fa-play-circle-o' => 'fa-play-circle-o',
        'fa-rotate-right' => 'fa-rotate-right',
        'fa-repeat' => 'fa-repeat',
        'fa-refresh' => 'fa-refresh',
        'fa-list-alt' => 'fa-list-alt',
        'fa-lock' => 'fa-lock',
        'fa-flag' => 'fa-flag',
        'fa-headphones' => 'fa-headphones',
        'fa-volume-off' => 'fa-volume-off',
        'fa-volume-down' => 'fa-volume-down',
        'fa-volume-up' => 'fa-volume-up',
        'fa-qrcode' => 'fa-qrcode',
        'fa-barcode' => 'fa-barcode',
        'fa-tag' => 'fa-tag',
        'fa-tags' => 'fa-tags',
        'fa-book' => 'fa-book',
        'fa-bookmark' => 'fa-bookmark',
        'fa-print' => 'fa-print',
        'fa-camera' => 'fa-camera',
        'fa-font' => 'fa-font',
        'fa-bold' => 'fa-bold',
        'fa-italic' => 'fa-italic',
        'fa-text-height' => 'fa-text-height',
        'fa-text-width' => 'fa-text-width',
        'fa-align-left' => 'fa-align-left',
        'fa-align-center' => 'fa-align-center',
        'fa-align-right' => 'fa-align-right',
        'fa-align-justify' => 'fa-align-justify',
        'fa-list' => 'fa-list',
        'fa-dedent' => 'fa-dedent',
        'fa-outdent' => 'fa-outdent',
        'fa-indent' => 'fa-indent',
        'fa-video-camera' => 'fa-video-camera',
        'fa-picture-o' => 'fa-picture-o',
        'fa-pencil' => 'fa-pencil',
        'fa-map-marker' => 'fa-map-marker',
        'fa-adjust' => 'fa-adjust',
        'fa-tint' => 'fa-tint',
        'fa-edit' => 'fa-edit',
        'fa-pencil-square-o' => 'fa-pencil-square-o',
        'fa-share-square-o' => 'fa-share-square-o',
        'fa-check-square-o' => 'fa-check-square-o',
        'fa-arrows' => 'fa-arrows',
        'fa-step-backward' => 'fa-step-backward',
        'fa-fast-backward' => 'fa-fast-backward',
        'fa-backward' => 'fa-backward',
        'fa-play' => 'fa-play',
        'fa-pause' => 'fa-pause',
        'fa-stop' => 'fa-stop',
        'fa-forward' => 'fa-forward',
        'fa-fast-forward' => 'fa-fast-forward',
        'fa-step-forward' => 'fa-step-forward',
        'fa-eject' => 'fa-eject',
        'fa-chevron-left' => 'fa-chevron-left',
        'fa-chevron-right' => 'fa-chevron-right',
        'fa-plus-circle' => 'fa-plus-circle',
        'fa-minus-circle' => 'fa-minus-circle',
        'fa-times-circle' => 'fa-times-circle',
        'fa-check-circle' => 'fa-check-circle',
        'fa-question-circle' => 'fa-question-circle',
        'fa-info-circle' => 'fa-info-circle',
        'fa-crosshairs' => 'fa-crosshairs',
        'fa-times-circle-o' => 'fa-times-circle-o',
        'fa-check-circle-o' => 'fa-check-circle-o',
        'fa-ban' => 'fa-ban',
        'fa-arrow-left' => 'fa-arrow-left',
        'fa-arrow-right' => 'fa-arrow-right',
        'fa-arrow-up' => 'fa-arrow-up',
        'fa-arrow-down' => 'fa-arrow-down',
        'fa-mail-forward' => 'fa-mail-forward',
        'fa-share' => 'fa-share',
        'fa-expand' => 'fa-expand',
        'fa-compress' => 'fa-compress',
        'fa-plus' => 'fa-plus',
        'fa-minus' => 'fa-minus',
        'fa-asterisk' => 'fa-asterisk',
        'fa-exclamation-circle' => 'fa-exclamation-circle',
        'fa-gift' => 'fa-gift',
        'fa-leaf' => 'fa-leaf',
        'fa-fire' => 'fa-fire',
        'fa-eye' => 'fa-eye',
        'fa-eye-slash' => 'fa-eye-slash',
        'fa-warning' => 'fa-warning',
        'fa-exclamation-triangle' => 'fa-exclamation-triangle',
        'fa-plane' => 'fa-plane',
        'fa-calendar' => 'fa-calendar',
        'fa-random' => 'fa-random',
        'fa-comment' => 'fa-comment',
        'fa-magnet' => 'fa-magnet',
        'fa-chevron-up' => 'fa-chevron-up',
        'fa-chevron-down' => 'fa-chevron-down',
        'fa-retweet' => 'fa-retweet',
        'fa-shopping-cart' => 'fa-shopping-cart',
        'fa-folder' => 'fa-folder',
        'fa-folder-open' => 'fa-folder-open',
        'fa-arrows-v' => 'fa-arrows-v',
        'fa-arrows-h' => 'fa-arrows-h',
        'fa-bar-chart-o' => 'fa-bar-chart-o',
        'fa-twitter-square' => 'fa-twitter-square',
        'fa-facebook-square' => 'fa-facebook-square',
        'fa-camera-retro' => 'fa-camera-retro',
        'fa-key' => 'fa-key',
        'fa-gears' => 'fa-gears',
        'fa-cogs' => 'fa-cogs',
        'fa-comments' => 'fa-comments',
        'fa-thumbs-o-up' => 'fa-thumbs-o-up',
        'fa-thumbs-o-down' => 'fa-thumbs-o-down',
        'fa-star-half' => 'fa-star-half',
        'fa-heart-o' => 'fa-heart-o',
        'fa-sign-out' => 'fa-sign-out',
        'fa-linkedin-square' => 'fa-linkedin-square',
        'fa-thumb-tack' => 'fa-thumb-tack',
        'fa-external-link' => 'fa-external-link',
        'fa-sign-in' => 'fa-sign-in',
        'fa-trophy' => 'fa-trophy',
        'fa-github-square' => 'fa-github-square',
        'fa-upload' => 'fa-upload',
        'fa-lemon-o' => 'fa-lemon-o',
        'fa-phone' => 'fa-phone',
        'fa-square-o' => 'fa-square-o',
        'fa-bookmark-o' => 'fa-bookmark-o',
        'fa-phone-square' => 'fa-phone-square',
        'fa-twitter' => 'fa-twitter',
        'fa-facebook' => 'fa-facebook',
        'fa-github' => 'fa-github',
        'fa-unlock' => 'fa-unlock',
        'fa-credit-card' => 'fa-credit-card',
        'fa-rss' => 'fa-rss',
        'fa-hdd-o' => 'fa-hdd-o',
        'fa-bullhorn' => 'fa-bullhorn',
        'fa-bell' => 'fa-bell',
        'fa-certificate' => 'fa-certificate',
        'fa-hand-o-right' => 'fa-hand-o-right',
        'fa-hand-o-left' => 'fa-hand-o-left',
        'fa-hand-o-up' => 'fa-hand-o-up',
        'fa-hand-o-down' => 'fa-hand-o-down',
        'fa-arrow-circle-left' => 'fa-arrow-circle-left',
        'fa-arrow-circle-right' => 'fa-arrow-circle-right',
        'fa-arrow-circle-up' => 'fa-arrow-circle-up',
        'fa-arrow-circle-down' => 'fa-arrow-circle-down',
        'fa-globe' => 'fa-globe',
        'fa-wrench' => 'fa-wrench',
        'fa-tasks' => 'fa-tasks',
        'fa-filter' => 'fa-filter',
        'fa-briefcase' => 'fa-briefcase',
        'fa-arrows-alt' => 'fa-arrows-alt',
        'fa-group' => 'fa-group',
        'fa-users' => 'fa-users',
        'fa-chain' => 'fa-chain',
        'fa-link' => 'fa-link',
        'fa-cloud' => 'fa-cloud',
        'fa-flask' => 'fa-flask',
        'fa-cut' => 'fa-cut',
        'fa-scissors' => 'fa-scissors',
        'fa-copy' => 'fa-copy',
        'fa-files-o' => 'fa-files-o',
        'fa-paperclip' => 'fa-paperclip',
        'fa-save' => 'fa-save',
        'fa-floppy-o' => 'fa-floppy-o',
        'fa-square' => 'fa-square',
        'fa-bars' => 'fa-bars',
        'fa-list-ul' => 'fa-list-ul',
        'fa-list-ol' => 'fa-list-ol',
        'fa-strikethrough' => 'fa-strikethrough',
        'fa-underline' => 'fa-underline',
        'fa-table' => 'fa-table',
        'fa-magic' => 'fa-magic',
        'fa-truck' => 'fa-truck',
        'fa-pinterest' => 'fa-pinterest',
        'fa-pinterest-square' => 'fa-pinterest-square',
        'fa-google-plus-square' => 'fa-google-plus-square',
        'fa-google-plus' => 'fa-google-plus',
        'fa-money' => 'fa-money',
        'fa-caret-down' => 'fa-caret-down',
        'fa-caret-up' => 'fa-caret-up',
        'fa-caret-left' => 'fa-caret-left',
        'fa-caret-right' => 'fa-caret-right',
        'fa-columns' => 'fa-columns',
        'fa-unsorted' => 'fa-unsorted',
        'fa-sort' => 'fa-sort',
        'fa-sort-down' => 'fa-sort-down',
        'fa-sort-asc' => 'fa-sort-asc',
        'fa-sort-up' => 'fa-sort-up',
        'fa-sort-desc' => 'fa-sort-desc',
        'fa-envelope' => 'fa-envelope',
        'fa-linkedin' => 'fa-linkedin',
        'fa-rotate-left' => 'fa-rotate-left',
        'fa-undo' => 'fa-undo',
        'fa-legal' => 'fa-legal',
        'fa-gavel' => 'fa-gavel',
        'fa-dashboard' => 'fa-dashboard',
        'fa-tachometer' => 'fa-tachometer',
        'fa-comment-o' => 'fa-comment-o',
        'fa-comments-o' => 'fa-comments-o',
        'fa-flash' => 'fa-flash',
        'fa-bolt' => 'fa-bolt',
        'fa-sitemap' => 'fa-sitemap',
        'fa-umbrella' => 'fa-umbrella',
        'fa-paste' => 'fa-paste',
        'fa-clipboard' => 'fa-clipboard',
        'fa-lightbulb-o' => 'fa-lightbulb-o',
        'fa-exchange' => 'fa-exchange',
        'fa-cloud-download' => 'fa-cloud-download',
        'fa-cloud-upload' => 'fa-cloud-upload',
        'fa-user-md' => 'fa-user-md',
        'fa-stethoscope' => 'fa-stethoscope',
        'fa-suitcase' => 'fa-suitcase',
        'fa-bell-o' => 'fa-bell-o',
        'fa-coffee' => 'fa-coffee',
        'fa-cutlery' => 'fa-cutlery',
        'fa-file-text-o' => 'fa-file-text-o',
        'fa-building-o' => 'fa-building-o',
        'fa-hospital-o' => 'fa-hospital-o',
        'fa-ambulance' => 'fa-ambulance',
        'fa-medkit' => 'fa-medkit',
        'fa-fighter-jet' => 'fa-fighter-jet',
        'fa-beer' => 'fa-beer',
        'fa-h-square' => 'fa-h-square',
        'fa-plus-square' => 'fa-plus-square',
        'fa-angle-double-left' => 'fa-angle-double-left',
        'fa-angle-double-right' => 'fa-angle-double-right',
        'fa-angle-double-up' => 'fa-angle-double-up',
        'fa-angle-double-down' => 'fa-angle-double-down',
        'fa-angle-left' => 'fa-angle-left',
        'fa-angle-right' => 'fa-angle-right',
        'fa-angle-up' => 'fa-angle-up',
        'fa-angle-down' => 'fa-angle-down',
        'fa-desktop' => 'fa-desktop',
        'fa-laptop' => 'fa-laptop',
        'fa-tablet' => 'fa-tablet',
        'fa-mobile-phone' => 'fa-mobile-phone',
        'fa-mobile' => 'fa-mobile',
        'fa-circle-o' => 'fa-circle-o',
        'fa-quote-left' => 'fa-quote-left',
        'fa-quote-right' => 'fa-quote-right',
        'fa-spinner' => 'fa-spinner',
        'fa-circle' => 'fa-circle',
        'fa-mail-reply' => 'fa-mail-reply',
        'fa-reply' => 'fa-reply',
        'fa-github-alt' => 'fa-github-alt',
        'fa-folder-o' => 'fa-folder-o',
        'fa-folder-open-o' => 'fa-folder-open-o',
        'fa-smile-o' => 'fa-smile-o',
        'fa-frown-o' => 'fa-frown-o',
        'fa-meh-o' => 'fa-meh-o',
        'fa-gamepad' => 'fa-gamepad',
        'fa-keyboard-o' => 'fa-keyboard-o',
        'fa-flag-o' => 'fa-flag-o',
        'fa-flag-checkered' => 'fa-flag-checkered',
        'fa-terminal' => 'fa-terminal',
        'fa-code' => 'fa-code',
        'fa-reply-all' => 'fa-reply-all',
        'fa-mail-reply-all' => 'fa-mail-reply-all',
        'fa-star-half-empty' => 'fa-star-half-empty',
        'fa-star-half-full' => 'fa-star-half-full',
        'fa-star-half-o' => 'fa-star-half-o',
        'fa-location-arrow' => 'fa-location-arrow',
        'fa-crop' => 'fa-crop',
        'fa-code-fork' => 'fa-code-fork',
        'fa-unlink' => 'fa-unlink',
        'fa-chain-broken' => 'fa-chain-broken',
        'fa-question' => 'fa-question',
        'fa-info' => 'fa-info',
        'fa-exclamation' => 'fa-exclamation',
        'fa-superscript' => 'fa-superscript',
        'fa-subscript' => 'fa-subscript',
        'fa-eraser' => 'fa-eraser',
        'fa-puzzle-piece' => 'fa-puzzle-piece',
        'fa-microphone' => 'fa-microphone',
        'fa-microphone-slash' => 'fa-microphone-slash',
        'fa-shield' => 'fa-shield',
        'fa-calendar-o' => 'fa-calendar-o',
        'fa-fire-extinguisher' => 'fa-fire-extinguisher',
        'fa-rocket' => 'fa-rocket',
        'fa-maxcdn' => 'fa-maxcdn',
        'fa-chevron-circle-left' => 'fa-chevron-circle-left',
        'fa-chevron-circle-right' => 'fa-chevron-circle-right',
        'fa-chevron-circle-up' => 'fa-chevron-circle-up',
        'fa-chevron-circle-down' => 'fa-chevron-circle-down',
        'fa-html5' => 'fa-html5',
        'fa-css3' => 'fa-css3',
        'fa-anchor' => 'fa-anchor',
        'fa-unlock-alt' => 'fa-unlock-alt',
        'fa-bullseye' => 'fa-bullseye',
        'fa-ellipsis-h' => 'fa-ellipsis-h',
        'fa-ellipsis-v' => 'fa-ellipsis-v',
        'fa-rss-square' => 'fa-rss-square',
        'fa-play-circle' => 'fa-play-circle',
        'fa-ticket' => 'fa-ticket',
        'fa-minus-square' => 'fa-minus-square',
        'fa-minus-square-o' => 'fa-minus-square-o',
        'fa-level-up' => 'fa-level-up',
        'fa-level-down' => 'fa-level-down',
        'fa-check-square' => 'fa-check-square',
        'fa-pencil-square' => 'fa-pencil-square',
        'fa-external-link-square' => 'fa-external-link-square',
        'fa-share-square' => 'fa-share-square',
        'fa-compass' => 'fa-compass',
        'fa-toggle-down' => 'fa-toggle-down',
        'fa-caret-square-o-down' => 'fa-caret-square-o-down',
        'fa-toggle-up' => 'fa-toggle-up',
        'fa-caret-square-o-up' => 'fa-caret-square-o-up',
        'fa-toggle-right' => 'fa-toggle-right',
        'fa-caret-square-o-right' => 'fa-caret-square-o-right',
        'fa-euro' => 'fa-euro',
        'fa-eur' => 'fa-eur',
        'fa-gbp' => 'fa-gbp',
        'fa-dollar' => 'fa-dollar',
        'fa-usd' => 'fa-usd',
        'fa-rupee' => 'fa-rupee',
        'fa-inr' => 'fa-inr',
        'fa-cny' => 'fa-cny',
        'fa-rmb' => 'fa-rmb',
        'fa-yen' => 'fa-yen',
        'fa-jpy' => 'fa-jpy',
        'fa-ruble' => 'fa-ruble',
        'fa-rouble' => 'fa-rouble',
        'fa-rub' => 'fa-rub',
        'fa-won' => 'fa-won',
        'fa-krw' => 'fa-krw',
        'fa-bitcoin' => 'fa-bitcoin',
        'fa-btc' => 'fa-btc',
        'fa-file' => 'fa-file',
        'fa-file-text' => 'fa-file-text',
        'fa-sort-alpha-asc' => 'fa-sort-alpha-asc',
        'fa-sort-alpha-desc' => 'fa-sort-alpha-desc',
        'fa-sort-amount-asc' => 'fa-sort-amount-asc',
        'fa-sort-amount-desc' => 'fa-sort-amount-desc',
        'fa-sort-numeric-asc' => 'fa-sort-numeric-asc',
        'fa-sort-numeric-desc' => 'fa-sort-numeric-desc',
        'fa-thumbs-up' => 'fa-thumbs-up',
        'fa-thumbs-down' => 'fa-thumbs-down',
        'fa-youtube-square' => 'fa-youtube-square',
        'fa-youtube' => 'fa-youtube',
        'fa-xing' => 'fa-xing',
        'fa-xing-square' => 'fa-xing-square',
        'fa-youtube-play' => 'fa-youtube-play',
        'fa-dropbox' => 'fa-dropbox',
        'fa-stack-overflow' => 'fa-stack-overflow',
        'fa-instagram' => 'fa-instagram',
        'fa-flickr' => 'fa-flickr',
        'fa-adn' => 'fa-adn',
        'fa-bitbucket' => 'fa-bitbucket',
        'fa-bitbucket-square' => 'fa-bitbucket-square',
        'fa-tumblr' => 'fa-tumblr',
        'fa-tumblr-square' => 'fa-tumblr-square',
        'fa-long-arrow-down' => 'fa-long-arrow-down',
        'fa-long-arrow-up' => 'fa-long-arrow-up',
        'fa-long-arrow-left' => 'fa-long-arrow-left',
        'fa-long-arrow-right' => 'fa-long-arrow-right',
        'fa-apple' => 'fa-apple',
        'fa-windows' => 'fa-windows',
        'fa-android' => 'fa-android',
        'fa-linux' => 'fa-linux',
        'fa-dribbble' => 'fa-dribbble',
        'fa-skype' => 'fa-skype',
        'fa-foursquare' => 'fa-foursquare',
        'fa-trello' => 'fa-trello',
        'fa-female' => 'fa-female',
        'fa-male' => 'fa-male',
        'fa-gittip' => 'fa-gittip',
        'fa-sun-o' => 'fa-sun-o',
        'fa-moon-o' => 'fa-moon-o',
        'fa-archive' => 'fa-archive',
        'fa-bug' => 'fa-bug',
        'fa-vk' => 'fa-vk',
        'fa-weibo' => 'fa-weibo',
        'fa-renren' => 'fa-renren',
        'fa-pagelines' => 'fa-pagelines',
        'fa-stack-exchange' => 'fa-stack-exchange',
        'fa-arrow-circle-o-right' => 'fa-arrow-circle-o-right',
        'fa-arrow-circle-o-left' => 'fa-arrow-circle-o-left',
        'fa-toggle-left' => 'fa-toggle-left',
        'fa-caret-square-o-left' => 'fa-caret-square-o-left',
        'fa-dot-circle-o' => 'fa-dot-circle-o',
        'fa-wheelchair' => 'fa-wheelchair',
        'fa-vimeo-square' => 'fa-vimeo-square',
        'fa-turkish-lira' => 'fa-turkish-lira',
        'fa-try' => 'fa-try',
        'fa-plus-square-o' => 'fa-plus-square-o',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_contact_header_items'.
  $field_bases['field_contact_header_items'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_contact_header_items',
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
    ),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'translatable' => 0,
    'type' => 'field_collection',
  );

  // Exported field_base: 'field_contact_header_subtext'.
  $field_bases['field_contact_header_subtext'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_contact_header_subtext',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_contact_header_text'.
  $field_bases['field_contact_header_text'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_contact_header_text',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_file_image_alt_text'.
  $field_bases['field_file_image_alt_text'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_file_image_alt_text',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_file_image_title_text'.
  $field_bases['field_file_image_title_text'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_file_image_title_text',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_image'.
  $field_bases['field_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_image',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => FALSE,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_news_multimedia'.
  $field_bases['field_news_multimedia'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_news_multimedia',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'mediafield',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'media',
  );

  // Exported field_base: 'field_news_tags'.
  $field_bases['field_news_tags'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_news_tags',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'tags',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_news_thumbnail'.
  $field_bases['field_news_thumbnail'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_news_thumbnail',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_portfolio_categories'.
  $field_bases['field_portfolio_categories'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_portfolio_categories',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'portfolio_categories',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_portfolio_detail'.
  $field_bases['field_portfolio_detail'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_portfolio_detail',
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
    ),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'translatable' => 0,
    'type' => 'field_collection',
  );

  // Exported field_base: 'field_portfolio_detail_label'.
  $field_bases['field_portfolio_detail_label'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_portfolio_detail_label',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_portfolio_detail_text'.
  $field_bases['field_portfolio_detail_text'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_portfolio_detail_text',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_portfolio_gallery'.
  $field_bases['field_portfolio_gallery'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_portfolio_gallery',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_portfolio_thumbnail'.
  $field_bases['field_portfolio_thumbnail'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_portfolio_thumbnail',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_product_categories'.
  $field_bases['field_product_categories'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_product_categories',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'product_categories',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_product_gallery'.
  $field_bases['field_product_gallery'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_product_gallery',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_product_ref'.
  $field_bases['field_product_ref'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_product_ref',
    'indexes' => array(
      'product_id' => array(
        0 => 'product_id',
      ),
    ),
    'locked' => 0,
    'module' => 'commerce_product_reference',
    'settings' => array(
      'options_list_limit' => '',
    ),
    'translatable' => 0,
    'type' => 'commerce_product_reference',
  );

  // Exported field_base: 'field_product_thumbnail'.
  $field_bases['field_product_thumbnail'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_product_thumbnail',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_simplenews_term'.
  $field_bases['field_simplenews_term'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_simplenews_term',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'parent' => 0,
          'vocabulary' => 'newsletter',
        ),
      ),
    ),
    'translatable' => 1,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_tags'.
  $field_bases['field_tags'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_tags',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'tags',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}