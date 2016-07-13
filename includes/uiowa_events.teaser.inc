<?php
/**
 * @file
 * Teaser theme functions.
 */

/**
 * Theme function for an event teaser.
 *
 * @param array $variables
 *    Variables from the theme function.
 */
function template_preprocess_uiowa_events_teaser(&$variables) {
  $variables['event']['image'] = array(
    '#theme' => 'imagecache_external',
    '#path' => $variables['event']['photo'],
    '#style_name' => 'medium',
    '#alt' => $variables['event']['title'],
  );

  if ($variables['external_link']) {
    $variables['event']['url'] = 'https://events.uiowa.edu/event/' . $variables['event']['id'];
  }
  else {
    $variables['event']['url'] = $GLOBALS['base_url'] . '/event/' . $variables['event']['id'];
  }

  if ($variables['event']['all_day']) {
    $variables['event']['date_string'] = date('n/j/Y', strtotime($variables['event']['start']));
  }
  else {
    $variables['event']['date_string'] = date('n/j/Y - g:i a', strtotime($variables['event']['start']));
    if (isset($variables['event']['end'])) {
      $variables['event']['date_string'] .= ' to ' . date('g:i a', strtotime($variables['event']['end']));
    }
  }
}
