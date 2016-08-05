<section class="bg bg-6 bg-breadcrumb bg-overlay-wrapper text-center" style="background-image:url(<?php print file_create_url($content['field_banner_background_image']['#items'][0]['uri']); ?>);">
  <div class="bg-overlay"></div>

  <div class="container">
    <div class="overlay-content">
      <h1 class="entry-title">
        <?php print drupal_get_title(); ?>
      </h1> <!-- End .entry-title -->

      <?php print variable_get('breadcrumb', ''); ?>
    </div>
  </div>
</section>