<?php
/**
 * @file
 * Administrative form functions for the University of Iowa branding bar.
 */

/**
 * Page callback: University of Iowa events configuration form.
 *
 * @see uiowa_events_menu()
 */
function uiowa_events_config_form($form, &$form_state) {
  $form['markup'] = array(
    '#type' => 'markup',
    '#markup' => t('<p>These settings let you configure the University of Iowa Events module.</p>'),
  );

  $form['global'] = array(
    '#type' => 'fieldset',
    '#title' => t('Site-wide settings'),
    '#description' => t('These settings affect all University of Iowa event lists and single instances.'),
  );

  $form['global']['uiowa_events_event_link'] = array(
    '#type' => 'select',
    '#title' => t('Link Option'),
    '#default_value' => variable_get('uiowa_events_event_link'),
    '#description' => t('Choose to have events link to Localist or an event page on this site.'),
    '#options' => array(
      'event-link-external' => t('Link to Localist'),
      'event-link-internal' => t('Link to page on this site'),
    ),
  );

  $form['global']['uiowa_events_cache_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Events Caching'),
    '#default_value' => variable_get('uiowa_events_cache_time'),
    '#description' => t('Enter the number of minutes event data should be cached. (Minimum of 5 minutes)'),
    '#size' => 60,
    '#required' => TRUE,
  );

  $form['page'] = array(
    '#type' => 'fieldset',
    '#title' => t('Main events page settings'),
    '#description' => t('These settings affect the main University of Iowa event list at /events.'),
  );

  $form['page']['uiowa_events_filter_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Events Filter ID'),
    '#default_value' => variable_get('uiowa_events_filter_id'),
    '#description' => t('Enter the filter ID for the events to display.'),
    '#size' => 60,
    '#required' => FALSE,
  );

  return system_settings_form($form);
}

/**
 * Implements validation from the Form API.
 *
 * @param array $form
 *   A structured array containing the elements and properties of the form.
 * @param array $form_state
 *   An array that stores information about the form's current state
 *   during processing.
 */
function uiowa_events_config_form_validate($form, &$form_state) {
  $minutes = $form_state['values']['uiowa_events_cache_time'];
  if (!is_numeric($minutes)) {
    form_set_error('uiowa_events_cache_time', t('You must enter a number for the minutes to cache data.'));
  }
  elseif ($minutes < 5) {
    form_set_error('uiowa_events_cache_time', t('Minimum cache limit is 5 minutes'));
  }
}
