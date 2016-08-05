<div class="widget custom-link <?php print $classes; ?>" <?php print $attributes; ?> id="<?php print $block_html_id; ?>">
    <?php print render($title_prefix); ?>
	<?php if ($block->subject): ?>
        <div class="heading-title">
            <h4><?php print $block->subject; ?></h4>
        </div>
    <?php endif;?>
    <?php print render($title_suffix); ?>
    <?php print render($content); ?>
</div>