<li>
  <a href="<?php print $fields['path']->content; ?>">
    <img src="<?php print $fields['field_product_thumbnail']->content; ?>" alt="">
    <span class="product-title bold"><?php print $fields['title']->content; ?></span>
  </a>
  <p>
    <?php if($fields['field_commerce_discount']->content) : ?>
        <del><?php print $fields['commerce_price']->content; ?></del>
        <ins><?php print $fields['field_commerce_discount']->content; ?></ins>
    <?php else : ?>
        <span class="amount"><?php print $fields['commerce_price']->content; ?></span>
    <?php endif; ?>
  </p>
</li>