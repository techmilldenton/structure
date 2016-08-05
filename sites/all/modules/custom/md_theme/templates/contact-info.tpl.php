<?php
	$info = theme_get_setting('address_info');
	$info = explode('||', $info);
	array_pop($info);
	foreach ($info as $key => $value) {
		$info[$key] = $key != 0 ? substr($value, 1, -1) : substr($value, 0, -1);
	}
	$info = array_chunk($info, 4);
?>
<div class="contact-info">
	<?php foreach ($info as $key => $value): ?>
        <p><i class="<?php print $value[0] ?>"></i><span><?php print $value[3] ?></span></p>
    <?php endforeach; ?>
</div>