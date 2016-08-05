<div class="col-md-4 col-sm-6">
  <div class="box box2">
    <div class="box-image box-image1">
      <img src="<?php print $fields['field_news_thumbnail']->content; ?>" alt="">

      <div class="box-overlay">
        <a class="box-overlay-content box-overlay-link fz-18" href="<?php print $fields['path']->content; ?>"><i class="fa fa-link"></i></a>
      </div> <!-- End .box-overlay -->
    </div> <!-- End .box-image box-image1 -->

    <div class="box-content">
      <a href="<?php print $fields['path']->content; ?>"><div class="box-name"><h3><?php print $fields['title']->content; ?></h3></div></a>

      <ul class="box-info mb-20">
        <li>
          <i class="fa fa-clock-o"></i><time datetime=""><?php print $fields['created']->content; ?></time>
        </li>
        <li>
          <i class="fa fa-comments"></i><span class="count"><?php print $fields['comment_count']->content; ?></span><?php print t('comment(s)'); ?>
        </li>
      </ul>
    </div> <!-- End .box-content -->
  </div>
</div>