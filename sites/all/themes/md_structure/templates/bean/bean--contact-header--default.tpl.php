<?php $count = 0; ?>
<?php for($i=0;$i < count($content['field_contact_header_items']['#items']); $i++) : ?>
	<?php if(($count%2) == 0) : ?>
    	<div class="col-md-2"></div>
        <div class="col-md-5 mb-1">
            <i class="fa <?php print $content['field_contact_header_items'][$i]['entity']['field_collection_item'][$content['field_contact_header_items']['#items'][$i]['value']]['field_contact_header_icon']['#items'][0]['value']; ?>"></i><?php print $content['field_contact_header_items'][$i]['entity']['field_collection_item'][$content['field_contact_header_items']['#items'][$i]['value']]['field_contact_header_text']['#items'][0]['value']; ?> <br> <span><?php print $content['field_contact_header_items'][$i]['entity']['field_collection_item'][$content['field_contact_header_items']['#items'][$i]['value']]['field_contact_header_subtext']['#items'][0]['value']; ?></span>
        </div>
        <?php $count++; ?>
    <?php else : ?>
    	<div class="col-md-5 mb-1">
            <i class="fa <?php print $content['field_contact_header_items'][$i]['entity']['field_collection_item'][$content['field_contact_header_items']['#items'][$i]['value']]['field_contact_header_icon']['#items'][0]['value']; ?>"></i><?php print $content['field_contact_header_items'][$i]['entity']['field_collection_item'][$content['field_contact_header_items']['#items'][$i]['value']]['field_contact_header_text']['#items'][0]['value']; ?> <br> <span><?php print $content['field_contact_header_items'][$i]['entity']['field_collection_item'][$content['field_contact_header_items']['#items'][$i]['value']]['field_contact_header_subtext']['#items'][0]['value']; ?></span>
        </div>
        <?php $count++; ?>
    <?php endif; ?>
<?php endfor; ?>