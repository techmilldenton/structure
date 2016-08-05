<?php if($block->region == "sidebar") : ?>
	<div class="widget <?php print $classes; ?>" <?php print $attributes; ?> id="<?php print $block_html_id; ?>">
        <?php print render($title_prefix); ?>
        <?php if ($block->subject): ?>
            <div class="heading-title">
                <h4><?php print $block->subject; ?></h4>
            </div>
        <?php endif;?>
        <?php print render($title_suffix); ?>
        <?php print render($content); ?>
    </div>
<?php elseif($block->region == "footer") : ?>
	<div class="col-md-<?php (theme_get_setting('footer_columns') == "") ? print "4" : print theme_get_setting('footer_columns'); ?> <?php print $classes; ?>" <?php print $attributes; ?> id="<?php print $block_html_id; ?>">
        <div class="widget">
            <?php print render($title_prefix); ?>
			<?php if ($block->subject): ?>
                <div class="heading-title">
					<h3><?php print $block->subject; ?></h3>
                </div>
            <?php endif;?>
            <?php print render($title_suffix); ?>
            <?php print render($content); ?>
        </div><!-- /widget_contact -->
    </div><!-- /col-4 -->
<?php else : ?>
    <div class="<?php print $classes; ?>" <?php print $attributes; ?> id="<?php print $block_html_id; ?>">
        <?php print render($title_prefix); ?>
        <?php if ($block->subject): ?>
            <div class="heading-title">
                <h4><?php print $block->subject; ?></h4>
            </div>
        <?php endif;?>
        <?php print render($title_suffix); ?>
        <?php print render($content); ?>
    </div>
<?php endif; ?>