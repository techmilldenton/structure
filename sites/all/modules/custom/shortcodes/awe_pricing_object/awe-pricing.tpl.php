<div <?php print $attributes; ?> class="ts-pricing-table <?php print $classes; ?>">
   <div class="box-col">
      <div class="box-col-heading">
        <h3><?php print $settings['type'] ?></h3>
        <strong class="fz-48 price"><?php print $settings['price'] ?></strong>
        <p class="mb-0 unit"><i class="bold"><?php print $settings['unit'] ?></i></p>
      </div>
      <div class="box-col-content text-center feature-list">
        <?php print $settings['featureText'] ?>
      </div>
      <div class="box-col-action text-center">
          <a href="<?php print $settings['buttonUrl'] ?>" target="<?php print $settings['buttonTarget'] ?>" class="btn-base <?php print $settings['buttonStyle'] ?> text-uppercase mt-10">
            <span data-hover="<?php print $settings['textButton'] ?>"><?php print $settings['textButton'] ?></span>
          </a>
      </div>
   </div>
</div>