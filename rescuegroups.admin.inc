<?php
/**
 * @file
 *   A Views backend to query the Last.fm API.
 */

 /**
 * Display Rescuegroups global settings form.
 *
 * @param $form_state
 *   FAPI form state
 * @return
 *   FAPI form definition
 * @ingroup forms
 * @see deploy_server_form_validate()
 * @see deploy_server_form_submit()
 */
function rescuegroups_settings_form() {
  $form = array();

  $form['rescuegroups_api_key'] = array(
    '#title' => t('API Key'),
    '#type' => 'textfield',
    '#size' => 32,
    '#maxlength' => 32,
    '#required' => TRUE,
    '#default_value' => variable_get('rescuegroups_api_key', ''),
    '#description' => t('The rescuegroups API key.'),
  );

  return system_settings_form($form);
}

