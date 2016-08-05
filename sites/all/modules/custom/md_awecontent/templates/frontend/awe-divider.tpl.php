<div <?php if($id) print 'id="'.$id.'"'; ?> class="<?php print $classes; ?>" <?php print $attributes; ?>>
  <div class="divider-field">
    <?php if($settings['with'] != 'none'):?>
      <span class="divider-left">
        <span class="line-divider">
        </span>
      </span>
      <span class="<?php print $contentClass;?>">
        <?php print ($settings['with'] == 'text') ? $settings['textContent'] : ''; ?>
        <?php print ($settings['with'] == 'icon') ? "<i class='{$settings['nameIcon']}'></i>" : ''; ?>
      </span>
      <span class="divider-right">
        <span class="line-divider">
        </span>
      </span>
    <?php else: ?>
      <div class="divider-left"><span class="line-divider"></span></div>
    <?php endif; ?>
  </div>
</div>
