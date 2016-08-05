<li class="mini_cart_item">
	<a href="#" class="remove">&times;</a>
    <?php print $fields['edit_delete']->content ?>
    <a href="<?php print $fields['path']->content ?>">
		<img width="180" height="180" src="<?php print $fields['field_product_thumbnail']->content ?>" alt="">
        <?php print $fields['title']->content ?>
    </a>
   	<span class="quantity"><?php print $fields['quantity']->content ?> <span class="amount"><strong><?php print $fields['commerce_price']->content ?></strong></span></span>
</li>