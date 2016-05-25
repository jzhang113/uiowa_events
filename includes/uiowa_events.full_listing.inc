<?php
/**
 * @file
 * Full listing theme functions.
 */

/**
 * Create full listing page.
 *
 * @param array &$variables
 *   Array reference of arguments given to the theme() function.
 */
function template_preprocess_uiowa_events_full_listing(&$variables) {
  drupal_set_title($variables['title']);

  $variables['nav'] = theme('uiowa_events_full_listing_date_nav',
    array(
      'date' => $variables['data'],
      'nav_items' => _uiowa_events_nav_control($variables['length'], $variables['date']),
    )
  );

  $external_link = FALSE;
  if (variable_get('uiowa_events_event_link') == 'event-link-external') {
    $external_link = TRUE;
  }

  $items = array();

  foreach ($variables['data'] as $e) {
    $variables['list'][] = array(
      '#theme' => 'uiowa_events_teaser',
      '#event' => $e,
      '#external_link' => $external_link,
    );
  }
}

/**
 * Theme function for full listing date navigation.
 *
 * @param array $variables
 *    Variables from the event data.
 */
function theme_uiowa_events_full_listing_date_nav($variables) {
  global $base_url;
  $nav = array();
  $page_date = $variables['date'];

  $previous = $variables['nav_items']['previous'];
  $next = $variables['nav_items']['next'];
  $label = $variables['nav_items']['label'];


  $nav['pagination'] = array(
    '#prefix' => '<ul class="pagination">',
    '#markup' => '  <li>
                      <a href="' . $base_url . $previous . '" aria-label="Previous">
                        <span aria-hidden="true">&laquo;</span>
                      </a>
                    </li>
                    <li class="active">
                        <a href="#">' . $label . '</a>
                    </li>
                    <li>
                      <a href="' . $base_url . $next . '" aria-label="Next">
                        <span aria-hidden="true">&raquo;</span>
                      </a>
                    </li>',
    '#suffix' => '</ul>',
  );

  return $nav;
}
