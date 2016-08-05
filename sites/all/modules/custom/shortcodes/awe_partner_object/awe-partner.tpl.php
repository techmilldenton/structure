<div <?php if($id) print 'id="'.$id.'"'; ?> class="partner-item <?php print $classes ?>" <?php print $attributes; ?>>
  	<div class="media box box-icon box-icon3 box-media">
          <div class="col-md-3 col-sm-4">
            <div class="pull-left box-image">
            	<span><i class="<?php print $settings['icon']; ?>"></i></span>
            </div>
          </div>
          <div class="col-md-9 col-sm-8">
            <div class="media-body">
              <div class="box-name">
                <h3 class="<?php print $settings['textTransform'] ?>"><?php print $settings['title'] ?></h3>
              </div>
              <p class="info-desc"><?php print $settings['description'] ?></p>
            </div>
          </div>
     </div>
</div>
