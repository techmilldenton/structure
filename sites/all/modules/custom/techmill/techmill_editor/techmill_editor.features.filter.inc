<?php
/**
 * @file
 * techmill_editor.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function techmill_editor_filter_default_formats() {
  $formats = array();

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'video_filter' => array(
        'weight' => -1,
        'status' => 1,
        'settings' => array(
          'video_filter_width' => 720,
          'video_filter_height' => 480,
          'video_filter_autoplay' => 1,
          'video_filter_related' => 1,
          'video_filter_html5' => 1,
          'video_filter_codecs' => array(
            'whatchado' => 'whatchado',
            'archive' => 0,
            'bliptv' => 0,
            'candidcareer' => 0,
            'capped' => 0,
            'collegehumor' => 0,
            'coub' => 0,
            'dailymotion' => 0,
            'democracynow_fullshow' => 0,
            'democracynow_story' => 0,
            'flickr_slideshows' => 0,
            'flickr_video' => 0,
            'foxnews' => 0,
            'gametrailers' => 0,
            'gamevideos' => 0,
            'giphy' => 0,
            'godtube' => 0,
            'google' => 0,
            'instagram' => 0,
            'metacafe' => 0,
            'mailru' => 0,
            'myspace' => 0,
            'myvideo' => 0,
            'picasa_slideshows' => 0,
            'rutube' => 0,
            'slideshare' => 0,
            'streamhoster' => 0,
            'teachertube' => 0,
            'ted' => 0,
            'twitch' => 0,
            'ustream' => 0,
            'vbox' => 0,
            'vimeo' => 0,
            'vine' => 0,
            'wistia' => 0,
            'youku' => 0,
            'youtube' => 0,
            'youtube_playlist' => 0,
          ),
          'video_filter_multiple_sources' => 1,
        ),
      ),
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'picture' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_autop' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Markdown.
  $formats['markdown'] = array(
    'format' => 'markdown',
    'name' => 'Markdown',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'geshifilter' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_markdown' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
