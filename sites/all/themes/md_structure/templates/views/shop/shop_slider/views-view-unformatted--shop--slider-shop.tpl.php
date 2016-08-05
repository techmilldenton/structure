<div class="arrows">
  <button type="button" class="slick-prev arrows-prev special-offers-prev">Previous</button>
  <button type="button" class="slick-next arrows-next special-offers-next">Next</button>
</div>
<div class="row special-offers-slide">
	<?php foreach ($rows as $id => $row): ?>
        <?php print $row; ?>
    <?php endforeach; ?>
</div>