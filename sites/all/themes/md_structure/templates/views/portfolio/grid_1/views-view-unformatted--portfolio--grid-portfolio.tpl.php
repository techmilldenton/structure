<?php
	$voca = taxonomy_vocabulary_machine_name_load('portfolio_categories');
	$terms = taxonomy_get_tree($voca->vid);
?>
<ul class="portfolioFilter nav-base">
  <li><a href="#" data-filter="*" class="current"><?php print t('ALL PROJECTS'); ?></a></li>
  <?php foreach ($terms as $term): ?>
    <li><a href="#" data-filter=".<?php $string = str_replace(' ', '', strtolower($term->name)); $string = str_replace('&', '-', $string); $string = str_replace('/', '-', $string); print $string; ?>"><?php print strtoupper($term->name); ?></a></li>
  <?php endforeach; ?>
</ul>
<div class="portfolio-row" data-column="4" data-column-md="3" data-column-sm="2" data-column-xs="1" data-column-gap="0">
    <div class="portfolioContainer portfolioContainer-full" id="da-thumbs">
		<?php foreach ($rows as $id => $row): ?>
            <?php print $row; ?>
        <?php endforeach; ?>
    </div>
</div>