<ul class="media-list comments-list">
    <li>
        <div class="media">
          <div class="media-left">
            <a href="#">
              <?php if (isset($comment->picture->uri)) : ?>
                  <img src="<?php print file_create_url($comment->picture->uri); ?>" alt="<?php print $content['comment_body']['#object']->name; ?>">
              <?php else : ?>
                  <img src="http://placehold.it/100x100" alt="<?php print $content['comment_body']['#object']->name; ?>">
              <?php endif; ?>
            </a>
          </div>
          <div class="media-body">
            <a href="#" class="media-heading"><?php print $content['comment_body']['#object']->name; ?> </a>
  
            <time datetime=""><?php print format_date($comment->created, 'custom', 'F d, Y'); ?></time>
  
            <?php
				hide($content['links']);
				hide($content['field_comment_email']);
				print '<p>' . $content['comment_body']['#object']->comment_body['und'][0]['value'] . '</p>';
			?>
  
            <a class="btn-reply" href="<?php print url($content['links']['comment']['#links']['comment-reply']['href']); ?>"><?php print t('Reply'); ?></a>
          </div>
        </div>
    </li><!-- /comment -->
</ol><!-- /comment-list -->