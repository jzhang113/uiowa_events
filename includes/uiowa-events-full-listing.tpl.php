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
<?php print render($nav); ?>
<?php if (!empty($add_link)): ?>
  <div class="uiowa-events-add-link-wrapper">
    <?php print render($add_link); ?>
  </div>
<?php endif; ?>
<div class="uiowa-events">
  <?php print render($list); ?>
</div>
