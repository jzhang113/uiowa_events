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
 * $data
 *   Pre-formatted list.
 */


dpm($data);
?>
<div id="uiowa-event">
  <div id="main-column">
    <div class="event-time">
      <?php print $data['today'] ?>
    </div>
    <?php if (!empty($data['location_name'])): ?>
      <div class="event-location"><?php print $data['location_name'] ?><?php if (!empty($data['room_number'])): ?><?php print ', '.$data['room_number'] ?>
        <?php endif; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($data['description'])): ?>
      <div class="event-description">
        <?php print $data['description'] ?>
      </div>
    <?php endif; ?>
  </div>
  <div id="secondary-column">
    <?php
      print theme('imagecache_external', array(
        'path' => $data['photo_url'],
        'style_name'=> 'medium',
        'alt' => 'Druplicon',
      ));
    ?>
  </div>
</div>
