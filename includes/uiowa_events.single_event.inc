<?php

/**
 * Create FAQ page if set to show the answer in a new page.
 *
 * @param array &$variables
 *   Array reference of arguments given to the theme() function.
 */
function template_preprocess_uiowa_events_single_event(&$variables) {
  $data = $variables['data'];
  drupal_set_title($variables['title']);
}
