<div class="section-project-detail scheme-project-detail">
	<?php if(count($content['field_portfolio_gallery']['#items']) > 0) : ?>
        <div class="slide-for mb-40">
          <?php for($i=0; $i < count($content['field_portfolio_gallery']['#items']); $i++) : ?>
          	<div class="slide-for-item">
              <img src="<?php print file_create_url($content['field_portfolio_gallery']['#items'][$i]['uri']) ?>" alt="">
            </div>
		  <?php endfor; ?>
        </div>
        <div class="slide-nav mb-70">
		  <?php for($j=0; $j < count($content['field_portfolio_gallery']['#items']); $j++) : ?>
          	<div class="slide-nav-item">
              <img src="<?php print image_style_url('gallery_thumb', $content['field_portfolio_gallery']['#items'][$j]['uri']) ?>" alt="">
            </div>
		  <?php endfor; ?>
        </div>
    <?php endif; ?>
    <div class="mb-50">
      <div class="col-md-6 pl-0">

        <div class="heading-title mb-40">
          <h4><?php print t('PROJECT DESCRIPTION'); ?></h4>
        </div> <!-- End .heading-title -->

        <?php print render($content['body']); ?>

      </div>

      <div class="col-md-6 pr-0">
        <div class="widget">
          <div class="heading-title mb-40">
            <h4><?php print t('PROJECT DETAILS'); ?></h4>
          </div>

          <table class="widget-table pt-40 pb-40">
            <tbody>
              <tr>
                <td class="meta-title"><?php print t('Categories'); ?>:</td>
                <td>
                  <ul>
                    <?php for($i=0; $i < count($content['field_portfolio_categories']['#items']); $i++) : ?>
						<li><a href="<?php print drupal_lookup_path('alias', $content['field_portfolio_categories'][$i]['#href']) ?>"><?php print $content['field_portfolio_categories'][$i]['#title'] ?></a></li>
                    <?php endfor; ?>
                  </ul>
                </td>
              </tr>
              <?php for($i=0; $i < count($content['field_portfolio_detail']['#items']); $i++) : ?>
              	<tr>
                  <td class="meta-title"><?php print $content['field_portfolio_detail'][$i]['entity']['field_collection_item'][$content['field_portfolio_detail']['#items'][$i]['value']]['field_portfolio_detail_label']['#items'][0]['value'] ?>:</td>
                  <td><span><?php print $content['field_portfolio_detail'][$i]['entity']['field_collection_item'][$content['field_portfolio_detail']['#items'][$i]['value']]['field_portfolio_detail_text']['#items'][0]['value'] ?></span></td>
                </tr>
			  <?php endfor; ?>
            </tbody>
          </table>

        </div>
      </div>
    </div>
</div>