<?php
/**
 * @file
 * Provides University of Iowa events fields.
 */

/**
 * Implements hook_field_info().
 *
 * Provides a University of Iowa events field.
 */
function uiowa_events_field_info() {
  return array(
    // We name our field as the associative name of the array.
    'field_uiowa_events' => array(
      'label' => t('University of Iowa Events'),
      'description' => t('List of events from the University of Iowa events website.'),
      'default_widget' => 'field_uiowa_events_configuration',
      'default_formatter' => 'field_uiowa_events_list',
    ),
  );
}

/**
 * Implements hook_field_formatter_info().
 *
 * @see uiowa_events_field_formatter_view()
 */
function uiowa_events_field_formatter_info() {
  return array(
    'field_uiowa_events_list' => array(
      'label' => t('University of Iowa events list'),
      'field types' => array('field_uiowa_events'),
    ),
  );
}

function uiowa_events_field_is_empty($item, $field) {
  //return empty($item['rgb']);
  return FALSE;
}

/**
 * Implements hook_field_formatter_view().
 *
 * @see uiowa_events_field_formatter_info()
 */
function uiowa_events_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  switch ($display['type']) {

  }

  return $element;
}

/**
 * Implements hook_field_widget_info().
 *
 * @see uiowa_events_field_widget_form()
 */
function uiowa_events_field_widget_info() {
  return array(
    'field_uiowa_events_configuration' => array(
      'label' => t('Localist configuration form'),
      'field types' => array('field_uiowa_events'),
    ),
  );
}

/**
 * Implements hook_field_widget_form().
 */
function uiowa_events_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  $default = $instance['default_value'][0];
  $widget = $element;
  $widget['#delta'] = $delta;

  $widget['pp'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of Results'),
    '#description' => t('Number of events to display. Maxinimum of 50.'),
    '#default_value' => isset($items[$delta]['pp']) ? $items[$delta]['pp'] : $default['pp'],
    '#required' => TRUE,
  );

  $widget['days'] = array(
    '#type' => 'textfield',
    '#title' => t('Days Ahead'),
    '#description' => t('Number of days in the future from which to display events. Maximum of 365.'),
    '#default_value' => isset($items[$delta]['days']) ? $items[$delta]['days'] : $default['days'],
    '#required' => TRUE,
  );
  $widget['filter_events'] = array(
    '#type' => 'fieldset',
    '#title' => t('Filter Events'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $widget['filter_events']['match'] = array(
    '#type' => 'select',
    '#title' => t('Match'),
    '#options' => array(
      '' => 'At least one keyword or tag, and one filter item',
      'any' => 'Any keyword, tag, or filter item',
      'all' => 'All keywords, tags, and filter items',
    ),
    '#default_value' => isset($items[$delta]['match']) ? $items[$delta]['match'] : $default['match'],
  );
  $widget['filter_events']['featured'] = array(
    '#type' => 'checkbox',
    '#title' => t('Only Show Featured Events'),
    '#default_value' => isset($items[$delta]['featured']) ? $items[$delta]['featured'] : $default['featured'],
  );
  $widget['filter_events']['sponsored'] = array(
    '#type' => 'checkbox',
    '#title' => t('Only Show Sponsored Events'),
    '#default_value' => isset($items[$delta]['sponsored']) ? $items[$delta]['sponsored'] : $default['sponsored'],
  );
  $widget['filter_events']['keyword'] = array(
    '#type' => 'textfield',
    '#title' => t('Keywords and Tags'),
    '#description' => t('Separate keywords with commas.'),
    '#default_value' => isset($items[$delta]['keyword']) ? $items[$delta]['keyword'] : $default['keyword'],
  );

  // Grab the all the filters.
  $filters = uiowa_events_get_filters();

  $widget['filter_events']['filter_events_filters'] = array(
    '#type' => 'fieldset',
    '#title' => t('Filters'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $widget['filter_events']['filter_events_filters']['event_types'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('Event Types'),
    '#default_value' => isset($items[$delta]['event_types']) ? $items[$delta]['event_types'] : $default['event_types'],
    '#options' => $filters['event_types'],
    '#size'=> 7,
  );
  $widget['filter_events']['filter_events_filters']['departments'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('Department'),
    '#default_value' => $widget_state['conf']['departments'],
    '#options' => $filters['departments'],
    '#size'=> 10,
  );
  $widget['filter_events']['filter_events_filters']['audience'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('Audience'),
    '#default_value' => $widget_state['conf']['audience'],
    '#options' => $filters['event_audience'],
    '#size'=> 6,
  );
  $widget['filter_events']['filter_events_filters']['general_interest'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('General Interest'),
    '#default_value' => $widget_state['conf']['general_interest'],
    '#options' => $filters['event_general_interest'],
    '#size'=> 7,
  );
  $widget['filter_events']['filter_events_filters']['venues'] = array(
    '#type' => 'select',
    '#title' => t('Places'),
    '#multiple' => TRUE,
    '#default_value' => $conf['venues'],
    '#options' => uiowa_events_get_places(),
    '#size'=> 10,
  );
  $widget['excluded_content'] = array(
    '#type' => 'fieldset',
    '#title' => t('Excluded Content'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $widget['excluded_content']['exclude_event_types'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('Event Types'),
    '#default_value' => $conf['exclude_event_types'],
    '#options' => $filters['event_types'],
    '#size'=> 7,
  );
  $widget['excluded_content']['exclude_departments'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('Department'),
    '#default_value' => $conf['exclude_departments'],
    '#options' => $filters['departments'],
    '#size'=> 10,
  );
  $widget['excluded_content']['exclude_audience'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('Audience'),
    '#default_value' => $conf['exclude_audience'],
    '#options' => $filters['event_audience'],
    '#size'=> 6,
  );
  $widget['excluded_content']['exclude_general_interest'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('General Interest'),
    '#default_value' => $conf['exclude_general_interest'],
    '#options' => $filters['event_general_interest'],
    '#size'=> 7,
  );

  $element = $widget;
  return $element;
}

/**
 * Implements hook_field_presave().
 */
function uiowa_events_field_presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
  foreach ($items as $delta => $item) {
    if (isset($item['filter_events']['match'])) {
      $items[$delta]['match'] = $item['filter_events']['match'];
    }
    if (isset($item['filter_events']['featured'])) {
      $items[$delta]['featured'] = $item['filter_events']['featured'];
    }
    if (isset($item['filter_events']['sponsored'])) {
      $items[$delta]['sponsored'] = $item['filter_events']['sponsored'];
    }
    if (isset($item['filter_events']['keyword'])) {
      $items[$delta]['keyword'] = $item['filter_events']['keyword'];
    }
    if (isset($item['filter_events']['filter_events_filters']['event_types'])) {
      $items[$delta]['event_types'] = $item['filter_events']['filter_events_filters']['event_types'];
    }
  }
}
