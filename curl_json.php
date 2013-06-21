<?php

function curl_json($data)  {
	$jsonData = json_encode($data);
	
	// create a new cURL resource
	$ch = curl_init();

	// set options, url, etc.
	curl_setopt($ch, CURLOPT_HTTPHEADER, array("Content-Type: application/json"));
	curl_setopt($ch, CURLOPT_URL, "https://api.rescuegroups.org/http/json");

	curl_setopt($ch, CURLOPT_POSTFIELDS, $jsonData);
	curl_setopt($ch, CURLOPT_POST, 1);

	//curl_setopt($ch, CURLOPT_VERBOSE, true);
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
	curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false); 

	$result = curl_exec($ch);

	if (curl_errno($ch)) {

	  $results = curl_error($ch);
	  curl_close($ch);
	  return false;

	} else {

	  // close cURL resource, and free up system resources
	  curl_close($ch);



	 //returns whole json array
	 //$results = utf8_encode($result);
	 //return json_decode($results, true); 
		
	//returns only data array
	 $results = json_decode(utf8_encode($result), true);
	 return $results['data'];

	}	
}


