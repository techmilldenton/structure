<div <?php if($id) print 'id="'.$id.'"'; ?> class="info-item <?php print $classes ?>" <?php print $attributes; ?>>
  <?php if($settings['style'] != "style-3" && $settings['style'] != "style-4") : ?>
      <div class="box">
        <div class="box-image box-image1 <?php if($settings['style'] == 'style-2') print "mb-20" ?>">
          <img src="<?php print $src_img ?>" alt="">
          <div class="box-overlay2 <?php if(!$settings['overlay']) print "hidden" ?>">
            <div class="box-overlay-wrapper">
              <div class="box-overlay-content">
                <?php if($settings['style'] != 'style-2') : ?>
                  <a class="box-overlay-link" href="<?php print $settings['buttonUrl'] ?>" target="<?php print $settings['buttonTarget'] ?>">
                    <i class="fa fa-link"></i>
                  </a>
                <?php endif; ?>
                <?php if($settings['style'] == 'style-2') : ?>
                  <span class="fz-18 overlay-title"><?php print $settings['overlay_title'] ?></span>
                  <span class="fz-24 overlay-text"><?php print $settings['overlay_text'] ?></span>
                  <a href="<?php print $settings['buttonUrl'] ?>" target="<?php print $settings['buttonTarget'] ?>" class="btn-base <?php print $settings['buttonStyle'] ?> text-uppercase mt-10"><?php print $settings['buttonText'] ?></a>
                <?php endif; ?>
              </div>
            </div>
          </div>
        </div>
        <?php if($settings['title'] != "") : ?>
            <div class="box-name">
                <a href="<?php print $settings['buttonUrl'] ?>" target="<?php print $settings['buttonTarget'] ?>">
                    <h4 class="info-box-title <?php if(isset($settings['textTransform'])) print $settings['textTransform'] ?>"><?php print $settings['title'] ?></h4>
                </a>
            </div>
        <?php endif; ?>
        <p class="info-desc"><?php print $settings['description'] ?></p>
        <a href="<?php print $settings['buttonUrl'] ?>" class="btn-base <?php print $settings['buttonStyle'] ?> text-uppercase mt-10 ts-button <?php if($settings['style'] == 'style-2') print "hidden" ?>" target="<?php print $settings['buttonTarget'] ?>"><?php print $settings['buttonText'] ?></a>
      </div>
  <?php endif; ?>
  
  <?php if($settings['style'] == "style-3" || $settings['style'] == "style-4") : ?>
  	  <div class="box">
          <div class="box-image">
            <img src="<?php print $src_img ?>" alt="">
            <div class="box-overlay <?php if(!$settings['overlay']) print "hidden" ?>">
              <a class="box-overlay-content box-overlay-link fz-18 ts-button" href="<?php print $settings['buttonUrl'] ?>" target="<?php print $settings['buttonTarget'] ?>"><i class="fa fa-link"></i></a>
            </div>
          </div>
          <div class="box-content <?php if($settings['style'] == "style-3") print "pr-0 mr-0 pb-25" ?>">
            <?php if($settings['title'] != "") : ?>
            	<div class="box-name">
                	<h4 class="info-box-title <?php if(isset($settings['textTransform'])) print $settings['textTransform'] ?>">
						<?php print $settings['title'] ?>
                    </h4>
                </div>
            <?php endif; ?>
            <p class="info-desc"><?php print $settings['description'] ?></p>
            <a href="<?php print $settings['buttonUrl'] ?>" target="<?php print $settings['buttonTarget'] ?>" class="<?php print $settings['buttonStyle'] ?> btn-base text-uppercase mt-10 ts-button"><?php print $settings['buttonText'] ?></a>
          </div>
      </div>
  <?php endif; ?>
</div>
