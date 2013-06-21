<?php
// $Id;

/**
 * @file
 *   Hooks for Views API integration
 */

/**
 * Implementation of hook_views_data().
 */
function rescuegroups_views_data() {
	$data = array();
 	$data['rescuegroups_api']['table']['group'] = t('rescuegroups.api');
 	$data['rescuegroups_api']['table']['base'] =  array(
		// The label shown when selecting this table in Views.
	    'title' => t('Rescuegroups API'),
	    'help' => t('Queries the Rescuegroups API'),
	    // use a diferent data source ,in this case a query to external rescuegroups API
	    'query class' => 'rescuegroups_views_backend'
	);

  	return $data;
}

/**
 * Implements hook_views_plugins().
 */
function rescuegroups_views_plugins() {
  $plugins = array
    'query' => array(
      'rescuegroups_views_backend' => array(
        'title' => t('DrupalConsAPIRequest'),
        'help' => t('Uses HTTP API for querying information from Rescuegroups.'),
        'handler' => 'rescuegroups_views_plugin_query',
        'path' => drupal_get_path('module', 'rescuegroups') .'/plugins',
      ),
    ),
  );

  return $plugins;
}

