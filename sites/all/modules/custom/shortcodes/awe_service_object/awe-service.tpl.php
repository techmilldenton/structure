<div <?php if($id) print 'id="'.$id.'"'; ?> class="service-item <?php print $classes; ?>" <?php print $attributes; ?>>
 	<div class="box-icon text-center mb-30 <?php if($settings['style'] != "style-1") print "hidden"; ?>">
      <div class="box-image">
        <span><i class="<?php print $settings['icon']; ?>"></i></span>
      </div>
      <div class="box-name">
        <a href="<?php print $settings['buttonUrl'] ?>" target="<?php print $settings['buttonTarget'] ?>" class="ts-button">
        	<h3 class="<?php print $settings['textTransform'] ?> title"><?php print $service['title']['value']; ?></h3>
        </a>
      </div>
      <p><?php print $service['description']['value']; ?></p>
    </div>
    <div class="box box3 text-center <?php if($settings['style'] != "style-2") print "hidden"; ?>">
        <div class="box-image">
          <span><i class="<?php print $settings['icon']; ?>"></i></span>
        </div>
        <div class="box-content">
          <div class="box-name">
          	<a href="<?php print $settings['buttonUrl'] ?>" target="<?php print $settings['buttonTarget'] ?>" class="ts-button">
            	<h4 class="<?php print $settings['textTransform'] ?> title"><?php print $service['title']['value']; ?></h4>
            </a>
          </div>
          <p><?php print $service['description']['value']; ?></p>
          <a href="<?php print $settings['buttonUrl'] ?>" target="<?php print $settings['buttonTarget'] ?>" class="ts-button btn-base btn-effect text-uppercase mt-10"><?php print $settings['buttonText'] ?></a>
        </div>
    </div>
    <div class="box-icon box3 box-icon5 text-center <?php if($settings['style'] != "style-3") print "hidden"; ?>">
        <div class="box-image">
          <span><i class="<?php print $settings['icon']; ?>"></i></span>
        </div>
        <br />
        <div class="box-name">
          <a href="<?php print $settings['buttonUrl'] ?>" target="<?php print $settings['buttonTarget'] ?>" class="ts-button">
          	<h3 class="bold mt-0 mb-0 <?php print $settings['textTransform'] ?> title"><?php print $service['title']['value']; ?></h3>
          </a>
        </div>
        <p><?php print $service['description']['value']; ?></p>
    </div>
    <div class="style-4 media box box-media box-icon box-icon2 <?php if($settings['style'] != "style-4") print "hidden"; ?>">
      <div class="pull-left box-image">
        <span><i class="<?php print $settings['icon']; ?>"></i></span>
      </div>
      <div class="media-body">
        <div class="box-name pt-0">
          <a href="<?php print $settings['buttonUrl'] ?>" target="<?php print $settings['buttonTarget'] ?>"><h4 class="<?php print $settings['textTransform'] ?> title"><?php print $service['title']['value']; ?></h4></a>
        </div>
        <p><?php print $service['description']['value']; ?></p>
      </div>
    </div>
</div>