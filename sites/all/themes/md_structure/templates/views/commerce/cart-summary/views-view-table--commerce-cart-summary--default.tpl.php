<table class="table table-cart">
  <thead>
      <tr>
          <th class="product-thumbnail">&nbsp;</th>
		  <?php foreach ($header as $field => $label): ?>
			<?php if ($field != 'product_id' && $field != 'field_product_size' && $field != 'field_product_colors') : ?>
                <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?>>
				  <?php print $label; ?>
                </th>
            <?php endif; ?>
          <?php endforeach; ?>
      </tr>
  </thead>
  <tbody>
      <?php $i = 0; ?>
	  <?php foreach ($rows as $row_count => $row): ?>
        <tr <?php if ($row_classes[$row_count]) { print 'class="' . implode(' ', $row_classes[$row_count]) .'"';  } ?>>
          <?php foreach ($row as $field => $content): ?>
            <?php if ($field != 'product_id') : ?>
                <?php
                      $product = commerce_product_load((int)$row['product_id']);
                      $query = new EntityFieldQuery;
                      $result = $query->entityCondition('entity_type', 'node', '=')
                        ->propertyCondition('type', 'product')
                        ->fieldCondition('field_product_ref', 'product_id', (int)$row['product_id'], '=')
                        ->range(0, 1)->execute();
                       
                        
                      $nids = array();
                      foreach ($result['node'] as $node) {
                        $nids[] = $node->nid;
                      }
                      $node = node_load((int)$nids[0]);
                ?>
				<?php if ($field == 'line_item_title') : ?>
                  <td class="product-thumbnail">
                      <a href="<?php print drupal_get_path_alias('node/'.$node->nid.''); ?>">
                          <img src="<?php print image_style_url('product_mini_cart', $node->field_product_thumbnail['und'][0]['uri']); ?>" alt="">
                      </a>
                  </td>
                  <td <?php if ($field_classes[$field][$row_count]) { print 'class="td-item '. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
                    <div class="info">
                        <?php if($field == 'line_item_title') : ?><?php print $content; ?><?php endif; ?>
                    </div>
                  </td>
                <?php endif; ?>
                <?php if ($field == 'quantity') : ?>
                  <td <?php if ($field_classes[$field][$row_count]) { print 'class="td-qty '. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
                    <?php print $content; ?>
                  </td>
                <?php endif; ?>
                <?php if ($field == 'commerce_unit_price') : ?>
                  <td <?php if ($field_classes[$field][$row_count]) { print 'class="td-sub '. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
                    <?php print $content; ?>
                  </td>
                <?php endif; ?>
                <?php if ($field == 'commerce_total') : ?>
                  <td <?php if ($field_classes[$field][$row_count]) { print 'class="td-sub '. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
                    <?php print $content; ?>
                  </td>
                <?php endif; ?>
            <?php endif; ?>
          <?php endforeach; ?>
        </tr>
        <?php $i++; ?>
      <?php endforeach; ?>
  </tbody>
</table>