<?php
include_once './' . drupal_get_path('theme', 'md_structure') . '/inc/front/html.preprocess.inc';
include_once './' . drupal_get_path('theme', 'md_structure') . '/inc/front/page.preprocess.inc';
include_once './' . drupal_get_path('theme', 'md_structure') . '/inc/front/function.theme.inc';

/**
 * Implements theme_menu_tree().
 */
function md_structure_menu_tree__main_menu($variables) {
	return '<ul class="menu">' . $variables['tree'] . '</ul>';
}

function md_structure_menu_tree__footer_menu($variables) {
	return '<ul class="menu">' . $variables['tree'] . '</ul>';
}


/**
 * Implements theme_menu_link__[MENU NAME].
 */
function md_structure_menu_link__main_menu($variables) {

  $element = $variables['element'];
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  $sub_menu = drupal_render($element['#below']);
  $sub_menu = str_replace('class="menu"','class="sub-menu"',$sub_menu);
  
  if($element['#below']) {
	$title = $element['#title'] . ' <span class="fa fa-angle-down"></span>';
	$output = l($title, $element['#href'], array('html' => TRUE));
	return '<li ' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
  }
  else {
	return '<li>' . $output . "</li>\n";
  }
}

function md_structure_css_alter(&$css) {
  unset($css[drupal_get_path('module', 'system') . '/system.menus.css']);
}

function md_structure_form_search_block_form_alter(&$form, &$form_state) {
  $form['#attributes']['class'][] = 'search-form';
  $form['search_block_form']['#attributes']['class'][] = 'search-field';
  $form['search_block_form']['#attributes']['placeholder'] = t('Search...');
  $form['actions']['submit']['#attributes']['class'][] = 'search-submit';
}

function md_structure_form_search_form_alter(&$form, &$form_state) {
  $form['basic']['submit']['#attributes']['class'][] = 'btn btn-primary mt-30 mb-30';
  $form['advanced']['#attributes']['class'][] = 'mb-70';
  $form['advanced']['submit']['#attributes']['class'][] = 'btn btn-primary';
}

function md_structure_form_alter(&$form, &$form_state, $form_id) {
  if (strpos((string) ($form_id), "webform_client_form") === false) {
    switch ($form_id) {
	  case 'simplenews_block_form_9':
		$form['mail']['#title_display'] = 'invisible';
		$form['mail']['#attributes']['class'][] = 'form-control';
		$form['mail']['#attributes']['placeholder'] = t('Your Email Address');
		
		$form['submit']['#attributes']['class'][] = 'btn btn-primary';
		$form['submit']['#value'] = 'Sign up';
		break;
    }
  }
}

function md_structure_form_comment_form_alter(&$form, &$form_state) {
	unset($form['actions']['preview']);
	unset($form['subject']);
	
	$form['author']['name']['#attributes'] = array('placeholder' => t('Name*'));
	$form['author']['_author']['#title_display'] = 'invisible';
	
	if(user_is_logged_in()) {
		$form['author']['_author']['#prefix'] = '<div class="row"><div class="col-md-4">';
		$form['author']['_author']['#suffix'] = '</div>';		
	} else {
		$form['author']['name']['#prefix'] = '<div class="row"><div class="col-md-4">';
		$form['author']['name']['#suffix'] = '</div>';
	}
	$form['author']['name']['#title_display'] = 'invisible';
	
	$form['field_comment_email']['und'][0]['email']['#attributes'] = array('placeholder' => t('Email*'));
	$form['field_comment_email']['und'][0]['email']['#title_display'] = 'invisible';
	$form['field_comment_email']['und'][0]['email']['#prefix'] = '<div class="col-md-4">';
	$form['field_comment_email']['und'][0]['email']['#suffix'] = '</div>';
	
	$form['field_comment_website']['und'][0]['value']['#attributes'] = array('placeholder' => t('Website*'));
	$form['field_comment_website']['und'][0]['value']['#title_display'] = 'invisible';
	$form['field_comment_website']['und'][0]['value']['#prefix'] = '<div class="col-md-4">';
	$form['field_comment_website']['und'][0]['value']['#suffix'] = '</div>';
	
	$form['comment_body']['und'][0]['value']['#attributes'] = array('placeholder' => t('Your comment'));
	$form['comment_body']['und'][0]['value']['#title_display'] = 'invisible';
	$form['comment_body']['und'][0]['value']['#prefix'] = '<div class="col-md-12">';
	$form['comment_body']['und'][0]['value']['#suffix'] = '</div>';
	
	$form['actions']['submit']['#value'] = 'Submit';
	$form['actions']['submit']['#prefix'] = '<div class="col-md-12">';
	$form['actions']['submit']['#suffix'] = '</div></div>';
	$form['actions']['submit']['#attributes']['class'][] = 'btn btn-primary';
}

function md_structure_form_webform_client_form_54_alter(&$form, &$form_state) {
  	$form['submitted']['name']['#title_display'] = 'invisible';
	$form['submitted']['name']['#attributes'] = array('placeholder' => t('Name*'));
	$form['submitted']['name']['#prefix'] = '<div class="row"><div class="col-md-4">';
	$form['submitted']['name']['#suffix'] = '</div>';
  
	$form['submitted']['email']['#title_display'] = 'invisible';
	$form['submitted']['email']['#attributes'] = array('placeholder' => t('Email*'));
	$form['submitted']['email']['#attributes']['class'][] = 'form-control';
	$form['submitted']['email']['#prefix'] = '<div class="col-md-4">';
	$form['submitted']['email']['#suffix'] = '</div>';
	
	$form['submitted']['website']['#title_display'] = 'invisible';
	$form['submitted']['website']['#attributes'] = array('placeholder' => t('Website'));
	$form['submitted']['website']['#prefix'] = '<div class="col-md-4">';
	$form['submitted']['website']['#suffix'] = '</div>';
	
	$form['submitted']['comment']['#title_display'] = 'invisible';
	$form['submitted']['comment']['#default_value'] = 'Comment';
	$form['submitted']['comment']['#prefix'] = '<div class="col-md-12">';
	$form['submitted']['comment']['#suffix'] = '</div>';
  
	$form['actions']['submit']['#value'] = 'Send Message';
	$form['actions']['submit']['#attributes']['class'][] = 'btn btn-primary';
	$form['actions']['submit']['#prefix'] = '<div class="col-md-12">';
	$form['actions']['submit']['#suffix'] = '</div></div>';
}

/**
 * Override theme_breadcrumb().
 */
function md_structure_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  $output = '';
  if (!empty($breadcrumb)) {
    $output = '<ol class="breadcrumb">' . t('You are here:');
    $is_first = TRUE;
    foreach($breadcrumb as $value) {
      if ($is_first) {
        $output .= '<li>' . $value . '</li>';
        $is_first = FALSE;
      } else {
        $output .= '<li>' . $value . '</li>';
      }
    }
    $output .= '<li class="active">' . drupal_get_title() . '</li>';
    $output .= '</ol>';
  }
  
  variable_set('breadcrumb', $output);
  return $output;
}

function md_structure_form_user_login_alter(&$form, &$form_state) {
	$form['name']['#attributes']['class'][] = 'form-control';	
	$form['pass']['#attributes']['class'][] = 'form-control';
	$form['actions']['submit']['#attributes']['class'][] = 'btn btn-primary form-submit';
}

function md_structure_form_user_register_form_alter(&$form, &$form_state) {
	$form['account']['name']['#attributes']['class'][] = 'form-control';
	$form['account']['mail']['#attributes']['class'][] = 'form-control';
	$form['actions']['submit']['#attributes']['class'][] = 'btn btn-primary form-submit';
}

function md_structure_form_user_pass_alter(&$form, &$form_state) {
	$form['name']['#attributes']['class'][] = 'form-control';
	$form['actions']['submit']['#attributes']['class'][] = 'btn btn-primary form-submit';
}
function md_structure_form_commerce_cart_add_to_cart_form_alter(&$form, &$form_state, $form_id) {
	$form['submit']['#attributes']['class'][] = 'btn-base btn-base-2 text-uppercase';
}
function md_structure_form_views_exposed_form_alter(&$form, &$form_state, $form_id) {
	$form['sort_by']['#attributes']['class'][] = 'form-control';
	$form['sort_by']['#title_display'] = 'invisible';
	$form['sort_order']['#attributes']['class'][] = 'form-control';
	$form['sort_order']['#title_display'] = 'invisible';
	$form['submit']['#attributes']['class'][] = 'btn btn-primary form-submit mt-0';
}
function md_structure_form_views_form_commerce_cart_form_default_alter(&$form, &$form_state, $form_id) {
	for($i=0; $i < count($form['edit_delete'])-1; $i++) {
		$form['edit_delete'][$i]['#value'] = "X";
		$form['edit_delete'][$i]['#attributes']['class'][] = 'product-remove';
	}
	$form['actions']['submit']['#attributes']['class'][] = "btn btn-primary pull-right ml-10";
	$form['actions']['checkout']['#attributes']['class'][] = "btn btn-primary pull-right";
}
function md_structure_form_commerce_checkout_form_checkout_alter(&$form, &$form_state) {
	$form['#attributes']['class'][] = 'form' ;

	$form['customer_profile_billing']['commerce_customer_address']['und'][0]['name_block']['name_line']['#attributes']['class'][] = 'form-control';
	$form['customer_profile_billing']['commerce_customer_address']['und'][0]['country']['#attributes']['class'][] = 'form-control';
	$form['customer_profile_billing']['commerce_customer_address']['und'][0]['street_block']['thoroughfare']['#attributes']['class'][] = 'form-control';
	$form['customer_profile_billing']['commerce_customer_address']['und'][0]['street_block']['premise']['#attributes']['class'][] = 'form-control';
	$form['customer_profile_billing']['commerce_customer_address']['und'][0]['locality_block']['locality']['#attributes']['class'][] = 'form-control';
	$form['customer_profile_billing']['commerce_customer_address']['und'][0]['locality_block']['dependent_locality']['#attributes']['class'][] = 'form-control';
	$form['customer_profile_billing']['commerce_customer_address']['und'][0]['locality_block']['administrative_area']['#attributes']['class'][] = 'form-control';
	$form['customer_profile_billing']['commerce_customer_address']['und'][0]['locality_block']['postal_code']['#attributes']['class'][] = 'form-control';
	
	$form['buttons']['continue']['#attributes']['class'][] = 'btn btn-primary pull-left';
	$form['buttons']['cancel']['#prefix'] = '&nbsp;';
	$form['buttons']['cancel']['#attributes']['class'][] = 'btn btn-primary pull-left ml-10 mt-10';
}
function md_structure_form_commerce_checkout_form_review_alter(&$form, &$form_state) {
	$form['#attributes']['class'][] = 'form' ;
	
	$form['commerce_payment']['payment_details']['credit_card']['number']['#attributes']['class'][] = 'form-control';
	$form['commerce_payment']['payment_details']['credit_card']['exp_month']['#attributes']['class'][] = 'form-control auto';
	$form['commerce_payment']['payment_details']['credit_card']['exp_year']['#attributes']['class'][] = 'form-control auto';
	
	$form['buttons']['continue']['#attributes']['class'][] = 'btn btn-primary pull-left';
	$form['buttons']['back']['#prefix'] = '&nbsp;';
	$form['buttons']['back']['#attributes']['class'][] = 'btn btn-primary pull-left ml-10 mt-10';
}