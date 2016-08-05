<div class="col-md-4 col-sm-6">
  <div class="box grid-1">
    <div class="box-image">
      <img src="<?php print $fields['field_news_thumbnail']->content; ?>" alt="">

      <div class="box-overlay">
        <a class="box-overlay-content box-overlay-link fz-18" href="<?php print $fields['path']->content; ?>"><i class="fa fa-link"></i></a>
      </div> <!-- End .box-overlay -->
    </div> <!-- End .box-image -->

    <div class="box-content">
      <div class="box-name"><h4 class="fz-16"><?php print $fields['title']->content; ?></h4></div>
      <ul class="box-info mb-20">
        <li>
          <i class="fa fa-clock-o"></i><time datetime=""><?php print $fields['created']->content; ?></time>
        </li>
        <li>
          <i class="fa fa-comments"></i><span class="count"><?php print $fields['comment_count']->content; ?></span><?php print t('comment(s)'); ?>
        </li>
      </ul>

      <p><?php print $fields['body']->content; ?></p>
      <a href="<?php print $fields['path']->content; ?>" class="btn-base btn-effect-2 text-uppercase mt-10"><?php print t('Read more'); ?></a>
    </div> <!-- End .box-content -->
  </div>
</div>