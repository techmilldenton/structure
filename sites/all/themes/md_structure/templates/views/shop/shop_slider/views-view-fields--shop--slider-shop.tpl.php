<div class="col-md-3">
  <div class="product-style">
    <div class="product-header">
      <div class="product-thumb">
        <a href="<?php print $fields['path']->content; ?>"><img src="<?php print $fields['field_product_thumbnail']->content; ?>" alt=""></a>
      </div>
    </div> <!-- End .product-header -->

    <div class="product-body">
      <a href="<?php print $fields['path']->content; ?>"><h3 class="product-name fz-16"><?php print $fields['title']->content; ?></h3></a>

      <span class="product-price">
        <?php if($fields['field_commerce_discount']->content) : ?>
            <del><?php print $fields['commerce_price']->content; ?></del>
            <ins><?php print $fields['field_commerce_discount']->content; ?></ins>
        <?php else : ?>
            <span class="amount"><?php print $fields['commerce_price']->content; ?></span>
        <?php endif; ?>
      </span>
      <?php print $fields['add_to_cart_form']->content;?>
    </div>
  </div>
</div>