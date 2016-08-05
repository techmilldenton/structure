<div <?php if($id) print 'id="'.$id.'"'; ?> class="history-item <?php print $classes ?>" <?php print $attributes; ?>>
  	<div class="media box">
        <div class="col-md-3 col-sm-4 col-xs-12 col-xs-12 pull-left pl-0">
            <img src="<?php print $src_img ?>" alt="">
        </div>
        <div class="col-md-9 col-sm-8 pull-right">
          <div class="heading-title">
            <h5 class="<?php print $settings['textTransform'] ?>"><span class="year"><?php print $settings['year'] ?> </span><span class="title"><?php print $settings['title'] ?></span></h5>
          </div>
          <p class="info-desc"><?php print $settings['description'] ?></p>
        </div>
     </div>
</div>
