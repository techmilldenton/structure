<div class="media box box-media latest-news">
    <div class="pull-left box-image">
      <?php print $fields['field_news_multimedia']->content; ?>

      <?php if($row->field_field_news_multimedia[0]['rendered']['#file']->filemime == "image/jpeg") : ?>
          <div class="box-overlay2">
            <div class="box-overlay-wrapper  ">
              <div class="box-overlay-content">
                <a href="<?php print $fields['path']->content; ?>">
                  <div class="icon-plus">
                    <span>+</span>
                  </div> <!-- End .icon-plus -->
                </a>
              </div>
            </div>
          </div>
      <?php endif; ?>
    </div>

    <div class="media-body">
      <div class="box-name">
        <a href="<?php print $fields['path']->content; ?>"><h5 class="bold"><?php print $fields['title']->content; ?></h5></a>
      </div>

      <ul class="box-info mb-20">
        <li>
          <i class="fa fa-user"></i><?php print $fields['name']->content; ?>
        </li>
        <li>
          <i class="fa fa-clock-o"></i><time datetime=""><?php print $fields['created']->content; ?></time>
        </li>
        <li>
          <i class="fa fa-comments"></i><span class="count"><?php print $fields['comment_count']->content; ?></span><?php print t('comment(s)'); ?>
        </li>
      </ul>
    </div>
</div>