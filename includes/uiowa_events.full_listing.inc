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
  dpm($data);
  drupal_set_title($variables['title']);

  $variables['list'] = theme('uiowa_events_teaser',
    array(
      'data' => $data,
    )
  );
}

function theme_uiowa_events_teaser($variables){
  $data = $variables['data'];
  dpm($data);
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
      '#markup' => '<img src="'.$e['photo'].'" alt="'.$e['title'].'" title="'.$e['title'].'" />',
    );
    $event['container']['title'] = array(
      '#markup' => '<h3>'.$e['title'].'</h3>',
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
