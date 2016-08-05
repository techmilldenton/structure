<ul class="menu">
    <?php if (isset($social)): ?>
	  <?php foreach ($social as $key => $data): ?>
        <?php
          $icon = $data[1];
          $icon = explode('|', $icon);
        ?>
        <li>
            <a href="<?php print $data[0]; ?>">
                <i class="fa <?php print $icon[1]; ?>"></i>
            </a>
        </li>
      <?php endforeach; ?>
    <?php endif; ?>
</ul><!-- social-list -->