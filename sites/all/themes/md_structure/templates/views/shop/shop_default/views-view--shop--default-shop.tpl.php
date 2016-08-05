<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>
  
  <div class="col-md-6 col-sm-6 pl-0 pt-20">
	   <?php
        global $pager_page_array, $pager_total, $pager_limits;
        $from = ($view->query->pager->current_page * $view->query->pager->options['items_per_page']) + 1;
        $to = $from + count($view->result) - 1;
        $total = $view->total_rows;
        if($total > 0){
            if ($total <= $to) {
              print t('Showing').': '.$from.' - '.$total.' of '.$view->total_rows;
            }
            else
            {
              print t('Showing').': '.$from.' - '.$to.' of '.$view->total_rows;
            }
        }
       ?>
  </div>

  <?php if ($exposed): ?>
    <div class="col-md-6 col-sm-6 pr-0 view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>

  <?php if ($rows): ?>
    <div class="view-content">
      <?php print $rows; ?>
    </div>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div>