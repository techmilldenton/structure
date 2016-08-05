<div <?php if($id) print 'id="'.$id.'"'; ?> class="<?php print $classes; ?>" <?php print $attributes; ?>>
    <?php if(isset($slides)) : ?>
		<?php foreach ($slides['content'] as $key => $content): ?>
          <div class="awe-carousel-slide">
            <div class="row">
              <?php foreach ($content as $key_column => $column): ?>
                <?php print render($column); ?>
              <?php endforeach; ?>
            </div>
          </div>
        <?php endforeach; ?>
    <?php endif; ?>
</div>
