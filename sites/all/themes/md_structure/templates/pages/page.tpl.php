<?php if(isset($awecontent)) : ?>
<div id="page-wrapper" class="scheme header-preset-01">	
	
    <?php if($page['header']):?>
		<?php print render($page['header']);?>
    <?php endif; ?>
    
    <?php if($page['banner']):?>
		<?php print render($page['banner']);?>
    <?php endif; ?>
    
	<div id="main" class="main">
		<?php print $messages; ?>
        <?php if ($tabs): ?><div class="config-tool"><?php print render($tabs); ?></div><?php endif; ?>
        <?php print render($page['content']);?>
    </div>
    
    <?php if($page['footer']):?>
    	<footer id="footer" class="footer">
            <div class="container">
              <div class="row">
                <?php print render($page['footer']);?>
              </div>
            </div>
        </footer>
    <?php endif; ?>

	<?php if(theme_get_setting('info_text')) : ?>
        <div class="copy-right">
          <div class="container">
            <?php print theme_get_setting('info_text') ?>
          </div>
        </div> <!-- End .copy-right -->
    <?php endif; ?>
</div>
<?php else : ?>
<div class="scheme">
	<?php if($page['header']):?>
		<?php print render($page['header']);?>
    <?php endif; ?>
    
    <?php if($page['banner']):?>
		<?php print render($page['banner']);?>
    <?php endif; ?>
    
    <div id="main" class="main">
    	<section class="section">
          <div class="container">
            <div class="row">
                <?php if (!empty($page['sidebar'])) : ?>
                    <?php if(theme_get_setting('sidebar_position') == 'left') : ?>
                        <div class="col-md-3">
                          <div class="sidebar">
                            <?php print render($page['sidebar']); ?>
                          </div>
                        </div>
                    <?php endif; ?>
                    <?php if(theme_get_setting('sidebar_position') == 'no') : ?>
                        <div class="col-md-12">
                          <?php print $messages; ?>
                          <?php if ($tabs): ?><div class="tab-tool"><?php print render($tabs); ?></div><?php endif; ?>
                          <?php print render($page['content']); ?>
                        </div>
                    <?php else: ?>
                        <div class="col-md-9">
                          <?php print $messages; ?>
                          <?php if ($tabs): ?><div class="tab-tool"><?php print render($tabs); ?></div><?php endif; ?>
                          <?php print render($page['content']); ?>
                        </div>
                    <?php endif; ?>
                    <?php if(theme_get_setting('sidebar_position') == 'right' || theme_get_setting('sidebar_position') == "") : ?>
                        <div class="col-md-3">
                          <div class="sidebar">
                            <?php print render($page['sidebar']); ?>
                          </div>
                        </div>
                    <?php endif; ?>
                <?php else: ?>
                    <div class="col-md-12">
                        <?php print $messages; ?>
                        <?php if ($tabs): ?><div class="tab-tool"><?php print render($tabs); ?></div><?php endif; ?>
                        <?php print render($page['content']);?>
                    </div>
                <?php endif; ?>
            </div>
          </div>
        </section>
    </div>
    
    <?php if($page['footer']):?>
    	<footer id="footer" class="footer">
            <div class="container">
              <div class="row">
                <?php print render($page['footer']);?>
              </div>
            </div>
        </footer>
    <?php endif; ?>

	<?php if(theme_get_setting('info_text')) : ?>
        <div class="copy-right">
          <div class="container">
            <?php print theme_get_setting('info_text') ?>
          </div>
        </div> <!-- End .copy-right -->
    <?php endif; ?>
</div>
<?php endif; ?>