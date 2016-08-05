<?php
/**
 * @author: MegaDrupal
 * @file: fullscreen_slider.tpl.php
 */
?>
<div class="mdf-slide-items" id="mdf-fullscreen-<?php print $slider->id; ?>" <?php print $data;?>>
  <?php foreach ($slides as $slide): ?>
    <div class="mdf-slide-item" data-timeout="<?php print $slide["settings"]["timelinewidth"]; ?>"
         data-transition="<?php print $slide["settings"]["transitions"]; ?>"
         data-thumb="<?php print $slide["settings"]["thumb"]; ?>"
      <?php if ($slide["settings"]["customTransitionTime"] && !empty($slide["settings"]["transitionTime"])) print " data-transition_time=\"{$slide["settings"]["transitionTime"]}\"";?>>
      <div class="mdf-mainimg">
        <?php
          $image_alt = t('Background Slide');
          if (isset($slide['settings']['bgFid'])) {
            $file = file_load($slide['settings']['bgFid']);
            $field_file_image_alt_text = field_get_items('file', $file, 'field_file_image_alt_text');

          }
        ?>
        <img src="<?php print $slide["settings"]["bgImage"]; ?>"  alt="<?php print $image_alt;?>"/>
      </div>
      <?php if (isset($slide['settings']['bgOverlay']) && $slide['settings']['bgOverlay'] != ''): ?>
        <div class="md-full-overlay" style="background-color: <?php print $slide['settings']['bgOverlay']; ?>">
        </div>
      <?php endif; ?>
      <div class="mdf-objects">
        <div class="mdf-objects-content">
          <?php foreach ($slide["items"] as $item) {
            print theme("fullscreen_slide_item", array("item" => $item, "generate" => FALSE));
          }
          ?>
        </div>
      </div>
    </div>
  <?php endforeach; ?>
</div>