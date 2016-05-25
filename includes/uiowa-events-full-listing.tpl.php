<?php
/**
 * @file uiowa-events-full-listing.tpl.php
 * Default theme implementation for the full listing of events.
 *
 * @see uiowa_events_full_listing()
 *
 * Available variables:
 *
 * $nav
 *   Date based navigation.
 * $list
 *   Pre-formatted list of events.
 */
?>
<?php print render($nav); ?>
<div class="uiowa-events">
  <?php print render($list); ?>
</div>
