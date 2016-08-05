<?php
  $list = theme('item_list', array(
    'items' => $variables['items'],
    'attributes' => array('class' => array('field-items')),
  ));
?>
<div>
  <?php print $list; ?>
</div>
