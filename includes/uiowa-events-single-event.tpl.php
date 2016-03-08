<?php

/**
 * @file
 * Template file for the full listing of events.
 */

 /**
 * Available variables:
 *
 * $title
 *   Sets the page title
 * $list
 *   Pre-formatted list.
 */
$breadcrumb = array();
$breadcrumb[] = l('Home', '<front>');
$breadcrumb[] = l('Events', 'events');
drupal_set_breadcrumb($breadcrumb);
?>
