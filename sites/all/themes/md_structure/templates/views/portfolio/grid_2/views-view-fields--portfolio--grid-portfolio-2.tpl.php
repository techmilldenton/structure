<div class="grid-item <?php $string = str_replace(' ', '', strtolower($fields['field_portfolio_categories']->content)); $string = str_replace('//', ' ', $string); $string = str_replace('&amp;', '-', $string); $string = str_replace('/', '-', $string); print $string; ?>">
  <div class="box-image text-center">
      <img src="<?php print $fields['field_portfolio_thumbnail']->content; ?>" alt="">

    <div class="box-overlay">
      <div class="box-overlay-wrapper">
        <div class="box-overlay-content pt-30">
          <span class="fz-15 bold"><?php print $fields['title']->content; ?></span>
          <a href="<?php print $fields['path']->content; ?>" class="btn-base-1 text-uppercase mt-10 fz-12"><?php print t('VIEW PROJECT'); ?></a>
        </div>
      </div>
    </div> <!-- End .box-overlay2 -->

  </div> <!-- End .box-image -->
</div>