<?php
  $field_instances = field_info_instance('node', $settings['fieldName'], $settings['nodeType']);
  $display = 'full';
  if ($field_instances && field_get_display($field_instances, 'full', $node)) {
    $display = field_get_display($field_instances, 'full', $node);
  }
  $field_render = field_view_field('node', $node, $settings['fieldName'], $display);
?>
<?php if (count($field_render) > 0): ?>
  <?php print render($field_render); ?>
<?php else: ?>
  <div></div>
<?php endif; ?>
