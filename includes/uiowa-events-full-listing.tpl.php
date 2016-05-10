<?php
/**
 * @file uiowa-events-full-listing.tpl.php
 * Default theme implementation for the full listing of events.
 *
 * @see uiowa_events_full_listing()
 *
 * Available variables:
 *
 * $title
 *   Sets the page title.
 * $nav
 *   Date based navigation.
 * $list
 *   Pre-formatted list of events.
 */
?>
<?php print render($nav); ?>
<?php print $list; ?>
