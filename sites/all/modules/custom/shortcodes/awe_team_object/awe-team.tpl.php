<div <?php if($id) print 'id="'.$id.'"'; ?> class="our-team-wrapper <?php print $classes ?>" <?php print $attributes; ?>>
  <div class="box box-icon text-center">
      <a href="#" tabindex="0"><img src="<?php print $src_img ?>" alt=""></a>
      <div class="box-name">
        <h3><?php print $settings['name'] ?></h3>
      </div>
      <p>
        <i><?php print $settings['position'] ?></i>
      </p>
      <p class="desc"><?php print $settings['description'] ?></p>
      <?php if (isset($socials)): ?>
          <ul class="social social-list">
            <?php if (isset($socials)): ?>
              <?php foreach($socials as $key => $social): ?>
                  <li>
                      <a href="<?php print $social['link']; ?>">
                          <i class="<?php print $social['icon']; ?>"></i>
                      </a>
                  </li>
              <?php endforeach; ?>
            <?php endif; ?>
          </ul>
      <?php endif; ?>
  </div>
</div>
