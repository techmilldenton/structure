<div class="box">
  <div class="box-image  text-center">
    <img src="<?php print $fields['field_portfolio_thumbnail']->content; ?>" alt="">

    <div class="box-overlay2">
      <div class="box-overlay-wrapper  ">
        <div class="box-overlay-content">
          <span class="fz-15"><?php print $fields['title']->content; ?></span>
          <a href="<?php print $fields['path']->content; ?>" class="btn-base-1 text-uppercase mt-10 fz-12"><?php print t('VIEW PROJECT'); ?></a>
        </div>
      </div>
    </div> <!-- End .box-overlay2 -->

  </div> <!-- End .box-image -->
</div>