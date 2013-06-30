<?php
/**
 * Implements hook_vies_data().
 */
function rescuegroups_views_data() {
  // First, the entry $data['example_table']['table'] describes properties of
  // the actual table – not its content.

  // The 'group' index will be used as a prefix in the UI for any of this
  // table's fields, sort criteria, etc. so it's easy to tell where they came
  // from.
  $data['rescuegroups_animal']['table']['group'] = t('Rescuegroups Dog');
	
	//Define this as a base table
	$data['rescuegroups_animal']['table']['base'] = array(
		'field' => 'animal_id',
		'title' => t('Rescuegroups Dogs'),
		'help' => t("OBG Table contains imported data from rescuegroups site api"),
		'weight' => -10,
	);

	$data['rescuegroups_animal']['animal_id'] = array(
		'title' => t('animal id'),
		'help' => t('unique animal id'),
		'field' => array('handler' => 'views_handler_field'),
		'argument' => array('handler' => 'views_handler_argument_numeric'),
    	'filter' => array('handler' => 'views_handler_filter_numeric'),
    	'sort' => array('handler' => 'views_handler_sort'),
	);
	
	$data['rescuegroups_animal']['animal_name'] = array(
		'title' => t('name'),
    	'help' => t('dog name'), 
    	'field' => array(
    			'handler' => 'views_handler_field',
    			'click sortable' => TRUE,
		),
		'argument' => array('handler' => 'views_handler_argument_string'),
    	'filter' => array('handler' => 'views_handler_filter_string'),
    	'sort' => array('handler' => 'views_handler_sort'),
	);
	
 	$data['rescuegroups_animal']['animal_last_update'] = array(
	    'title' => t('date of last update'),
	    'help' => t('Last update of dog'),
	    'field' => array(
    			'handler' => 'views_handler_field',
    			'click sortable' => TRUE,
		),
	    'argument' => array('handler' => 'views_handler_argument_date'),
	    'filter' => array('handler' => 'views_handler_filter_datetime'),
	    'sort' => array('handler' => 'views_handler_sort_date')
	);

	// ----------------------------------------------------------------------
  	// Animal Image table

  	$data['rescuegroups_animal']['table']['group'] = t('Rescuegroups Dog Image');

  	// Explain how this table joins to others.
	$data['rescuegroups_animal_image']['table']['join'] = array(
	    'rescuegroups_animal' => array(
	      'left_field' => 'animal_id',
	      'field' => 'animal_id',
	    ),
	);

	$data['rescuegroups_animal_image']['image_id'] = array(
		'title' => t('image id'),
		'help' => t('unique image id'),
		'field' => array('handler' => 'views_handler_field'),
		'argument' => array('handler' => 'views_handler_argument_numeric'),
    	'filter' => array('handler' => 'views_handler_filter_numeric'),
    	'sort' => array('handler' => 'views_handler_sort'),
	);

	$data['rescuegroups_animal_image']['animal_url_image_full'] = array(
	    'title' => t('Animal image'),
	    'help' => t('Full animal image.'),
	    'field' => array(
	      'handler' => 'views_handler_field_image',
	    ),
	  );

	return $data;

}
