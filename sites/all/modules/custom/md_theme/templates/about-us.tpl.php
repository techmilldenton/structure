<?php
	$default_value = theme_get_setting('ft_image_file_uploaded');
	$media_file = array('fid' => isset($default_value['fid']) ? intval($default_value['fid']) : 0);
	if ($media_file['fid'] && ($media_file = file_load($media_file['fid']))) {
	  $media_file = get_object_vars($media_file);
	}
?>

<div class="widget-content">
  <?php if (!empty($media_file['uri'])): ?>
    <p>
      <a href="<?php print base_path(); ?>"><img src="<?php print file_create_url($media_file['uri']); ?>" alt=""></a>
    </p>
  <?php endif; ?>
  <p><?php print theme_get_setting('footer_info') ?></p>
</div> <!-- End widget-content -->

<?php
  $block = module_invoke('md_theme', 'block_view', 'footer');
  print str_replace("menu","social",render($block['content']));
?>