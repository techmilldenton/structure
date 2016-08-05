<?php if($node->comment_count > 0) : ?>
<!-- COMMENT -->
<div id="comments">
    <h4 class="comments-title"><?php print $node->comment_count; ?> <?php print t('COMMENTS'); ?></h4>
    <?php print render($content['comments']); ?>
</div>
<!-- END / COMMENT -->
<?php endif; ?>

<!-- COMMENT RESPOND -->
<div id="respond" class="comment-respond">
    <h4 class="comments-title"><?php print t('Write a Reply or Comment'); ?></h4>
    <?php print render($content['comment_form']); ?>
</div>
<!-- END COMMENT RESPOND -->