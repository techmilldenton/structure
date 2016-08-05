<?php $user = user_load($node->uid); ?>
<div class="blog">
  <div class="blog-thumb">
    <?php print render($content['field_news_multimedia']); ?>

    <div class="dates">
      <span class="month"><?php print format_date($node->created, 'custom', 'F'); ?></span>
      <span class="date"><?php print format_date($node->created, 'custom', 'd'); ?></span>
      <span class="year"><?php print format_date($node->created, 'custom', 'Y'); ?></span>
      <span class="comments-counts"><span><?php print $node->comment_count ?></span><?php print t('comment'); ?></span>
    </div> <!-- End .dates -->
  </div> <!-- End .blog-heading -->

  <div class="blog-body">
    <a href="<?php print drupal_get_path_alias('node/' . $node->nid); ?>">
      <h2 class="entry-title"><?php print $node->title ?></h2>
    </a>

    <div class="blog-info">
      <span class="author"><i class="fa fa-user"></i><?php print t('Posted by'); ?> <?php print $node->name ?></span>
      <span class="link-add">
      	<i class="fa fa-folder"></i>
		<?php print t('In'); ?> 
        <?php for($i=0; $i < count($content['field_news_tags']['#items']); $i++) : ?>
			<?php if($i == count($content['field_news_tags']['#items']) - 1): ?>
                <a href="<?php print drupal_lookup_path('alias', $content['field_news_tags'][$i]['#href']) ?>"><?php print $content['field_news_tags'][$i]['#title'] ?></a>
            <?php else : ?>
                <a href="<?php print drupal_lookup_path('alias', $content['field_news_tags'][$i]['#href']) ?>"><?php print $content['field_news_tags'][$i]['#title'] ?></a>, 
            <?php endif; ?>
        <?php endfor; ?>
      </span>
    </div>

    <div class="blog-description">
      <?php print render($content['body']) ?>
    </div> <!-- End .blog-description -->

    <div class="media">

      <div class="pull-right share">
        <span><i class="fa fa-share-alt"></i> <?php print t('Share'); ?>: </span>
        <ul class="social">
          <li>
          	<a href="#" onclick="window.open('http://www.facebook.com/sharer.php?u=<?php print drupal_get_path_alias('node/' . $node->nid); ?>&amp;t=<?php print $node->title; ?>','popupFacebook','width=650,height=270,resizable=0, toolbar=0, menubar=0, status=0, location=0, scrollbars=0'); return false;"><i class="fa fa-facebook"></i></a>
          </li>
          <li>
          	<a href="#" onclick="window.open('https://twitter.com/intent/tweet?text=<?php print $node->title; ?>&amp;url=<?php print drupal_get_path_alias('node/' . $node->nid); ?>','popupTwitter','width=500,height=370,resizable=0, toolbar=0, menubar=0, status=0, location=0, scrollbars=0'); return false;"><i class="fa fa-twitter"></i></a>
          </li>
          <li>
          	<a class="post_share_googleplus" href="#" onclick="window.open('https://plus.google.com/share?url=<?php print drupal_get_path_alias('node/' . $node->nid); ?>','popupGooglePlus','width=650,height=226,resizable=0, toolbar=0, menubar=0, status=0, location=0, scrollbars=0'); return false;"><i class="fa fa-google-plus"></i></a>
          </li>
        </ul>
      </div>
    </div>
  </div> <!-- Emd .blog-body -->
</div> <!-- End .blog -->

<div class="blog-footer">
  <div class="author-info">
    <div class="media">
      <a class="pull-left" href="#">
        <img class="media-object" src="<?php print image_style_url('author', $user->picture->uri) ?>" alt="Image">
      </a>
      <div class="media-body box-icon">
        <h4 class="box-name pt-0"><?php print $user->name; ?></h4>
        <p class="mb-0">
        	<?php
				if(isset($user->field_account_about['und'])) :
					print $user->field_account_about['und'][0]['value'];
				endif;
			?>
        </p>
      </div>
    </div>
  </div> <!-- End .author-info -->
</div> <!-- End .blog-footer -->

<div class="comments">
  <?php print render($content['comments']); ?>
</div>