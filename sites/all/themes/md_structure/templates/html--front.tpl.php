<!DOCTYPE html>
<!--[if lt IE 7]>      <html class="no-js lt-ie9 lt-ie8 lt-ie7"> <![endif]-->
<!--[if IE 7]>         <html class="no-js lt-ie9 lt-ie8"> <![endif]-->
<!--[if IE 8]>         <html class="no-js lt-ie9"> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js"> <!--<![endif]-->

<head>
    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
    <?php if(isset($ios_144) && $ios_144 != null) :?><link rel="apple-touch-icon-precomposed" sizes="144x144" href="<?php print $ios_144; ?>"><?php endif;?>
    <?php if(isset($ios_114) && $ios_114 != null) :?><link rel="apple-touch-icon-precomposed" sizes="114x114" href="<?php print $ios_114; ?>"><?php endif;?>
    <?php if(isset($ios_72) && $ios_72 != null)  :?><link rel="apple-touch-icon-precomposed" sizes="72x72" href="<?php print $ios_72; ?>"><?php endif;?>
    <?php if(isset($ios_57) && $ios_57 != null)  :?><link rel="apple-touch-icon-precomposed" sizes="57x57" href="<?php print $ios_57; ?>"><?php endif;?>
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.4.0/css/font-awesome.min.css">
    <?php
        print $styles;
        print $scripts;
    ?>
    <style type="text/css">
        <?php if (isset($googlewebfonts)): print $googlewebfonts; endif; ?>
        <?php if (isset($theme_setting_css)): print $theme_setting_css; endif; ?>
        <?php
        // custom typography
        if (isset($typography)): print $typography; endif;
        ?>

        <?php if (isset($custom_css)): print $custom_css; endif; ?>
    </style>
    <?php if (isset($header_code)): print $header_code; endif;?>
    <!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
    <!--[if lt IE 9]>
        <script src="http://html5shim.googlecode.com/svn/trunk/html5.js"></script>
        <script src="http://css3-mediaqueries-js.googlecode.com/svn/trunk/css3-mediaqueries.js"></script>
    <![endif]-->
</head>
<body class="<?php print $classes; ?> <?php if(theme_get_setting('header_fix')) print "has-fixed-header" ?>" <?php print $attributes;?>>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php 
		print $page_bottom; 
		if (isset($footer_code)) : print $footer_code; endif;
  ?>
</body>
</html>
