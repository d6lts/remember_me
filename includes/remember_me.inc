<?php

/**
 * @file
 * Functions that are not needed at all times can be included when required.
 */

/**
 * Insert 'Remember me' checkbox between in between form elements.
 */
function remember_me_insert_checkbox(&$form) {
  $form1['remember_me'] = array(
    '#title' => t('Remember me'),
    '#type' => variable_get('remember_me_checkbox_visible', 1) ? 'checkbox' : 'hidden',
    '#default_value' => variable_get('remember_me_checkbox', 1),
  );
  _remember_me_array_insert_after_key('pass', $form, $form1);
  $form['name']['#attributes']['tabindex'] = '1';
  $form['pass']['#attributes']['tabindex'] = '2';
  $form['remember_me']['#attributes']['tabindex'] = '3';
  $form['submit']['#attributes']['tabindex'] = '4';
}

/**
 * Insert elements into array after the element with $searck_key key.
 *
 * @param $search_key
 *   Key of array element to insert elements after.
 * @param $array
 *   Given array.
 * @param $elements_to_insert
 *   Array of elements to be inserted.
 */
function _remember_me_array_insert_after_key($search_key, &$array, $elements_to_insert) {
  // Split array into two arrays: prior $search_key element including
  // $search_key element and after $search_key element.
  $array1 = array();
  $array2 = array();
  $curr_array = &$array1;
  foreach ($array as $key => $value) {
    $curr_array[$key] = $value;
    if ($search_key == $key) {
      $curr_array = &$array2;
    }
  }

  // Add $elements_to_insert to the end of the first array.
  $array1 = $array1 + $elements_to_insert;
  $array = $array1 + $array2;
}
