<div <?php if($id) print 'id="'.$id.'"'; ?> class="<?php print $classes; ?>" <?php print $attributes; ?>>
  <div class="box-count">
    <div class="box-image">
      <i class="<?php print $settings['icon']; ?>"></i>
    </div>
    <div class="box-count-number" data-stop="<?php print $funfact['number']['value']; ?>">
      <span><?php print $funfact['number']['value']; ?></span>
    </div>
    <p class="bold"><?php print $funfact['title']['value']; ?></p>
   </div>
</div>