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
 * $add_link
 *   An "Add Your Event" link.
 * $list
 *   Pre-formatted list of events.
 */
?>
<div class="uiowa-events-page">
  <?php if (!empty($add_link)): ?>
       <?php print render($add_link); ?>
  <?php endif; ?>
  <?php print render($nav); ?>
  <div class="uiowa-events">
    <?php print render($list); ?>
  </div>
</div>
