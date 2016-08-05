<?php
/**
 * Implements theme_pager().
 */
function md_structure_pager($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.
  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('« first')), 'element' => $element, 'parameters' => $parameters));
  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('‹ previous')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('next ›')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('last »')), 'element' => $element, 'parameters' => $parameters));

  if ($pager_total[$element] > 1) {
    if ($li_first) {
      $items[] = array(
        'class' => array('first'),
        'data' => $li_first,
      );
    }
    if ($li_previous) {
      $items[] = array(
        'class' => array(''),
        'data' => $li_previous,
      );
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => 'â€¦',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array(''),
            'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('current-page'),
            'data' => $i,
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array(''),
            'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => 'â€¦',
        );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array(''),
        'data' => $li_next,
      );
    }
    if ($li_last) {
      $items[] = array(
        'class' => array('last'),
        'data' => $li_last,
      );
    }
    $output = '<nav class="pager mt-3"><ul class="pagination">';
    foreach ($items as $item) {
      if(isset($item['class'])) {
        $output .= '<li class="' . $item['class'][0] . '">' . $item['data'] . "</li>\n";
      } else {
        $output .= '<li>' . $item['data'] . "</li>\n";
      }
    }
    $output .= '</ul></nav>';

    return $output;
  }
}

/**
 * Implements theme_textarea().
 */
function md_structure_textarea($variables) {
  $element = $variables['element'];
  $element['#attributes']['placeholder'] = $element['#title'];
  element_set_attributes($element, array('id', 'name', 'cols', 'rows'));
  _form_set_class($element, array('form-control'));

  // Add resizable behavior.
  if (!empty($element['#resizable'])) {
    drupal_add_library('system', 'drupal.textarea');
    $wrapper_attributes['class'][] = 'resizable';
    $output = '<div' . drupal_attributes($wrapper_attributes) . '>';
    $output .= '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
    $output .= '</div>';
    return $output;
  }
  else {
    $output = '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
    return $output;
  }
}

/**
 * Implements theme_textfield().
 */
function md_structure_textfield($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'text';
  $element['#attributes']['placeholder'] = isset($element['#title']) ? $element['#title'] : '';
  element_set_attributes($element, array('id', 'name', 'value', 'size', 'maxlength'));
  _form_set_class($element, array('form-control'));

  $extra = '';
  if ($element['#autocomplete_path'] && drupal_valid_path($element['#autocomplete_path'])) {
    drupal_add_library('system', 'drupal.autocomplete');
    $element['#attributes']['class'][] = 'form-autocomplete';

    $attributes = array();
    $attributes['type'] = 'hidden';
    $attributes['id'] = $element['#attributes']['id'] . '-autocomplete';
    $attributes['value'] = url($element['#autocomplete_path'], array('absolute' => TRUE));
    $attributes['disabled'] = 'disabled';
    $attributes['class'][] = 'autocomplete';
    $extra = '<input' . drupal_attributes($attributes) . ' />';
  }
  $output = '<input' . drupal_attributes($element['#attributes']) . ' />';
  return $output . $extra;
}



function md_structure_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables ['primary'])) {
    $variables ['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables ['primary']['#prefix'] .= '<ul class="tabs primary">';
    $variables ['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables ['primary']);
  }
  if (!empty($variables ['secondary'])) {
    $variables ['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables ['secondary']['#prefix'] .= '<ul class="tabs secondary nav nav-tabs tpl-tabs animate">';
    $variables ['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables ['secondary']);
  }

  return $output;
}


/**************************************
*  Messenger 
***************************************/
function md_structure_status_messages($variables) {
  $display = $variables ['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
  );
  foreach (drupal_get_messages($display) as $type => $messages) {
    //dsm($type);
    $output .= '<div class="mtop_bottom">';
    if($type=='status'){
          $output .= "<div class=\"alert success messages $type\">\n";
          if (!empty($status_heading [$type])) {
            $output .= '<h2 class="element-invisible">' . $status_heading [$type] . "</h2>\n";
          }
            if (count($messages) > 1) {
              $output .= " <ul class=\"list-unstyled\">\n";
              foreach ($messages as $message) {
                $output .= '  <li> ' . $message . "</li>\n";
              }
              $output .= " </ul>\n";
            }
            else {
              $output .= ' '.reset($messages);
            }
          $output .= "</div>\n";  
    }
    elseif($type=="error"){
          $output .= "<div class=\"alert messages $type\">\n";
          if (!empty($status_heading [$type])) {
            $output .= '<h2 class="element-invisible">' . $status_heading [$type] . "</h2>\n";
          }
            if (count($messages) > 1) {
              $output .= " <ul class=\"list-unstyled\">\n";
              foreach ($messages as $message) {
                $output .= '  <li> ' . $message . "</li>\n";
              }
              $output .= " </ul>\n";
            }
            else {
              $output .= ' '.reset($messages);
            }
          $output .= "</div>\n";  
    }
    elseif($type=="warning"){
          $output .= "<div class=\"alert notice messages $type\">\n";
          if (!empty($status_heading [$type])) {
            $output .= '<h2 class="element-invisible">' . $status_heading [$type] . "</h2>\n";
          }
            if (count($messages) > 1) {
              $output .= " <ul class=\"list-unstyled\">\n";
              foreach ($messages as $message) {
                $output .= '  <li> ' . $message . "</li>\n";
              }
              $output .= " </ul>\n";
            }
            else {
              $output .= ' '.reset($messages);
            }
          $output .= "</div>\n";  
    }
    $output .= "</div>\n";
  }
  return $output;
}