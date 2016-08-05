<?php
	$default_value = theme_get_setting('logo_normal_file_uploaded');
	$path = base_path() . drupal_get_path("theme","md_structure") . "/logo.png";
	$media_file = array('fid' => isset($default_value['fid']) ? intval($default_value['fid']) : 0);
	if ($media_file['fid'] && ($media_file = file_load($media_file['fid']))) :
	  $media_file = get_object_vars($media_file);
	endif;
	
	if(theme_get_setting('default_logo') != 0) :
		$path = base_path() . drupal_get_path("theme","md_structure") . "/logo.png";
	else :	
		if($media_file['fid'] != 0) :
			$path = file_create_url($media_file['uri']);
		endif;
	endif;
?>
<div class="header-wrapper scheme header-preset-06">
	<header class="header">
      <div class="container">
          <div class="row">
              <div class="col-md-3 col-xs-6">
                  <div class="site-branding">
                      <a href="<?php print base_path(); ?>">
                          <img src="<?php print $path; ?>" alt="logo"/> 
                      </a>
                  </div>
              </div>
              <div class="col-md-8 col-sm-5 col-xs-6 header-right">
                  <span class="menu-link"><i class="fa fa-navicon"></i></span> 
                  <nav class="navigation">
                      <div class="primary-menu">
                          <?php
							  $menu_name = variable_get('menu_main_links_source', 'main-menu');
							  $tree = menu_tree($menu_name);
							  print drupal_render($tree); 
						  ?>
                      </div>
                  </nav>
              </div>
              <div class="col-md-1 col-sm-1 hidden-xs search-wrapper">
                  <div class="search-box hidden-xs hidden-sm">
                      <?php
                          $block = module_invoke('search', 'block_view', 'form');
                          print render($block['content']);
                      ?> 
                      <i class="fa fa-search"></i>
                  </div>
              </div>
          </div>
      </div>
  </header>
</div>