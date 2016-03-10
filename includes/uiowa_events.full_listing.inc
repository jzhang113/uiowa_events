<?php

/**
 * Create FAQ page if set to show the answer in a new page.
 *
 * @param array &$variables
 *   Array reference of arguments given to the theme() function.
 */
function template_preprocess_uiowa_events_full_listing(&$variables) {
  $items = array();
  $data = $variables['data'];
  $date = $variables['date'];
  drupal_set_title($variables['title']);

  $variables['nav'] = theme('uiowa_events_full_listing_date_nav',
    array(
      'date' => $date,
    )
  );

  $variables['list'] = theme('uiowa_events_teaser',
    array(
      'data' => $data,
    )
  );
}

function theme_uiowa_events_full_listing_date_nav($variables){
  $nav = Array();
  $page_date = $variables['date'];

  $nav['pagination'] = array(
    '#prefix' => '<ul class="pagination">',
    '#markup' => '  <li>
                      <a href="/events/'.date('Y-m-d', strtotime("-1 days", strtotime($page_date))).'" aria-label="Previous">
                        <span aria-hidden="true">&laquo;</span>
                      </a>
                    </li>
                    <li class="active">
                        <a href="#">'.date('l, F j',strtotime($page_date)).'</a>
                    </li>
                    <li>
                      <a href="/events/'.date('Y-m-d', strtotime("+1 days", strtotime($page_date))).'" aria-label="Next">
                        <span aria-hidden="true">&raquo;</span>
                      </a>
                    </li>',
    '#suffix' => '</ul>'
  );

  $output = drupal_render($nav);
  return $output;
}

function theme_uiowa_events_teaser($variables){
  $data = $variables['data'];
  $external_link = FALSE;
  if(variable_get('uiowa_events_event_link') == 'event-link-external') $external_link = TRUE;

  $items = Array();
  $items['events'] = array(
    '#attributes' => array('class' => array('uiowa-events')),
    '#type' => 'container',
  );

  foreach ($data as $e) {

    $event = Array();
    $event['container'] = array(
      '#attributes' => array('class' => array('uiowa-event')),
      '#type' => 'container',
    );
    $event['container']['image'] = array(
      '#theme' => 'imagecache_external',
      '#path' => $e['photo'],
      '#style_name' => 'medium',
      '#alt' => $e['title'],
    );

    $title_link = '';
    if($external_link) $title_link = '<h3><a href="http://events.uiowa.edu/event/'.$e['id'].'">'.$e['title'].'</a></h3>';
    else $title_link = '<h3><a href="/event/'.$e['id'].'">'.$e['title'].'</a></h3>';
    $event['container']['title'] = array(
      '#markup' => $title_link,
    );

    $date_string = '';
    if($e['all_day']){
      $date_string = date('n/j/Y',strtotime($e['start']));
    }
    else{
      $date_string = date('n/j/Y - g:i a',strtotime($e['start']));
      if(isset($e['end'])){
        $date_string .= ' to '.date('g:i a',strtotime($e['end']));
      }
    }

    $event['container']['time'] = array(
      '#markup' => '<p>'.$date_string.'</p>',
    );
    $items['events'][] = array(
      'data' => $event,
    );
  }

  $output = drupal_render($items);
  return $output;
}
