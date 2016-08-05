<div class="blog">
  <div class="blog-thumb">
    <?php print $fields['field_news_multimedia']->content; ?>

    <div class="dates">
      <span class="month"><?php print $fields['created']->content; ?></span>
      <span class="date"><?php print $fields['created_1']->content; ?></span>
      <span class="year"><?php print $fields['created_2']->content; ?></span>
      <span class="comments-counts"><span><?php print $fields['comment_count']->content; ?></span><?php print t('comment(s)'); ?></span>
    </div> <!-- End .dates -->
  </div> <!-- End .blog-heading -->

  <div class="blog-body">
    <a href="<?php print $fields['path']->content; ?>">
      <h2 class="entry-title"><?php print $fields['title']->content; ?></h2>
    </a>

    <div class="blog-info">
      <span class="author"><i class="fa fa-user"></i><?php print t('Posted by'); ?> <?php print $fields['name']->content; ?></span>
      <span class="link-add"><i class="fa fa-folder"></i><?php print t('In'); ?> <?php print $fields['field_news_tags']->content; ?></span>
    </div>

    <p><?php print $fields['body']->content; ?> [&hellip;]</p>

    <div class="media">
      <div class="pull-left">
        <a href="<?php print $fields['path']->content; ?>" class="btn-base btn-base-2 text-uppercase"><?php print t('Continue Reading'); ?></a>
      </div>

      <div class="pull-right share">
        <span><i class="fa fa-share-alt"></i> <?php print t('Share'); ?>: </span>
        <ul class="social">
          <li><a href="#" onclick="window.open('http://www.facebook.com/sharer.php?u=<?php print drupal_get_path_alias('node/' . $fields['nid']->content); ?>&amp;t=<?php print $fields['title']->content; ?>','popupFacebook','width=650,height=270,resizable=0, toolbar=0, menubar=0, status=0, location=0, scrollbars=0'); return false;"><i class="fa fa-facebook"></i></a></li>
          <li><a href="#" onclick="window.open('https://twitter.com/intent/tweet?text=<?php print $fields['title']->content; ?>&amp;url=<?php print drupal_get_path_alias('node/' . $fields['nid']->content); ?>','popupTwitter','width=500,height=370,resizable=0, toolbar=0, menubar=0, status=0, location=0, scrollbars=0'); return false;"><i class="fa fa-twitter"></i></a></li>
          <li><a href="#" onclick="window.open('https://plus.google.com/share?url=<?php print drupal_get_path_alias('node/' . $fields['nid']->content); ?>','popupGooglePlus','width=650,height=226,resizable=0, toolbar=0, menubar=0, status=0, location=0, scrollbars=0'); return false;"><i class="fa fa-google-plus"></i></a></li>
        </ul>
      </div>
    </div>
  </div> <!-- Emd .blog-body -->
</div>