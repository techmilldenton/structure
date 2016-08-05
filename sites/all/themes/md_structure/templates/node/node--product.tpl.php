<div class="product-detail">
  <div class="image js-images">
    <div class="slide-for-images">
      <?php for($i=0; $i < count($content['field_product_gallery']['#items']); $i++) : ?>
      	<div class="slide-for-images-item">
          <img src="<?php print image_style_url('product_4', $content['field_product_gallery']['#items'][$i]['uri']); ?>"alt="">
        </div>
	  <?php endfor; ?>
    </div> <!-- End .slide-for -->

    <div class="slide-nav-images">
      <?php for($i=0; $i < count($content['field_product_gallery']['#items']); $i++) : ?>
      	<div class="slide-nav-images-item">
          <img src="<?php print image_style_url('product_3', $content['field_product_gallery']['#items'][$i]['uri']); ?>"alt="">
        </div>
	  <?php endfor; ?>
    </div> <!-- End .slide-nav -->
  </div>

  <div class="summary">
    <h1 class="product-title"><?php print $node->title; ?></h1>
    <span class="product-price">
    	<?php if(render($content['product:field_commerce_discount'])) : ?>
        	<del><span class="amount"><?php print $content['product:commerce_price'][0]['#markup'] ?></span></del> 
            <ins><span class="amount"><?php print $content['product:field_commerce_discount'][0]['#markup']  ?></span></ins>
        <?php else : ?>
        	<?php print render($content['product:commerce_price']) ?>
        <?php endif; ?>
    </span>

    <?php print render($content['field_product_ref']); ?>

    <div class="box-name"><h4><?php print t('Description'); ?>: </h4></div>

    <?php print $content['body'][0]['#markup']; ?>
  </div>
</div> <!-- End .product-detail -->

<section class="section">
  <?php print render($content['comments']); ?>
</section>
