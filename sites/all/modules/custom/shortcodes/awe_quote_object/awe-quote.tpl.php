<div <?php if($id) print 'id="'.$id.'"'; ?> class="quote-item <?php print $classes ?>" <?php print $attributes; ?>>
  	<?php if($settings['style'] != "style-3") : ?>
        <div class="quote">
          <div class="quote-wrapper">
            <div class="quote-content">
              <p class="mb-0 info-desc"><?php print $settings['description'] ?></p>
            </div>
          </div>
          <?php if($settings['style'] == "style-1") : ?>
              <img class="quote-image" src="<?php print $src_img ?>" alt="">
              <div class="quote-info">
                <div class="box-name pb-0">
                  <h4 class="<?php print $settings['textTransform'] ?>"><?php print $settings['title'] ?></h4>
                </div>
                <p class="position"><?php print $settings['position'] ?></p>
              </div>
          <?php endif; ?>
        </div>
    <?php endif; ?>
    <?php if($settings['style'] == "style-3") : ?>
        <div class="testi">
             <div class="quote-content">
                <div class="col-md-10 col-md-offset-1 col-sm-10 col-sm-offset-1 col-xs-8 col-xs-offset-2">
                  <p class="mb-0 info-desc"><?php print $settings['description'] ?></p>
                </div>
             </div>
             <div class="box-name pb-0">
                <h4 class="<?php print $settings['textTransform'] ?>"><?php print $settings['title'] ?></h4>
             </div>
        </div>
    <?php endif; ?>
</div>
