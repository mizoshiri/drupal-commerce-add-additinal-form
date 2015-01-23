<?php

/**
 * Implements base_settings_form()
 */
function drupal_commerce_add_additinal_form_pane_settings_form($checkout_pane) {
  $form['drupal_commerce_add_additinal_form_pane_field'] = array(
    '#type' => 'textfield',
    '#title' => t('My Module Pane Field'),
    '#default_value' => variable_get('drupal_commerce_add_additinal_form_pane_field', ''),
  );
  return $form;
}

/**
 * Implements base_checkout_form()
 */
function drupal_commerce_add_additinal_form_pane_checkout_form($form, $form_state, $checkout_pane, $order) {

  $checkout_form['drupal_commerce_add_additinal_form_pane_field_display'] = array(
    '#markup' => variable_get('drupal_commerce_add_additinal_form_pane_field', ''),
  );
  $checkout_form['drupal_commerce_add_additinal_form_first_name'] = array(
    '#type' => 'textfield',
    '#title' => t('First Name'),
    '#required' => TRUE,
  );
  $checkout_form['drupal_commerce_add_additinal_form_last_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Last Name'),
    '#required' => TRUE,
  );
  $checkout_form['drupal_commerce_add_additinal_form_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#required' => TRUE,
  );
  $checkout_form['drupal_commerce_add_additinal_form_mobile'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile Phone'),
  );
  return $checkout_form;
}

/**
 * Implements checkout_form_validate()
 */
function drupal_commerce_add_additinal_form_pane_checkout_form_validate($form, &$form_state, $checkout_pane, $order) {
  /**
  * Validate email is valid
  */
  $email = $form_state["values"]["drupal_commerce_add_additinal_form_email"];
  if (!valid_email_address($email)) {
    form_set_error($checkout_pane['pane_id'] . '][another_email', t('Please provide a valid email address.'));
    return FALSE;
  }

  return TRUE;
}


/**
 * Implements base_checkout_form_submit()
 */
function drupal_commerce_add_additinal_form_pane_checkout_form_submit($form, &$form_state, $checkout_pane, $order) {
  // do something here with
  // $form_state['values']['drupal_commerce_add_additinal_form_email']
}
