<?php
/**
 * @file
 * Administrative form functions for the University of Iowa branding bar.
 */
/**
 * Page callback: University of Iowa branding bar configuration form.
 *
 * @see uiowa_bar_menu()
 */
function uiowa_events_config_form($form, &$form_state) {
  $form['markup'] = array(
    '#type' => 'markup',
    '#markup' => t('<p>These settings let you configure the University of Iowa Events module.</p>'),
  );
  $form['uiowa_events_filter_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Events Filter ID'),
    '#default_value' => variable_get('uiowa_events_filter_id'),
    '#description' => t('Enter the filter ID for the events to display.'),
    '#size' => 60,
    '#required' => FALSE,
  );
  return system_settings_form($form);
}
