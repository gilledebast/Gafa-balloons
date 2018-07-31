<?php

	$new_stockData = [];

	$last_stockData_content = file_get_contents('data/gafa.json');
	$last_stockData = json_decode($last_stockData_content, true);

	//print_r($last_stockData);
	
	$symbols = 'GOOG,AAPL,FB,AMZN';
	$apiKey = 'QKFXINVDMWRT0P06';

	$current_stockData_content = file_get_contents('https://www.alphavantage.co/query?function=BATCH_STOCK_QUOTES&symbols='.$symbols.'&apikey='.$apiKey);
	$current_stockData = json_decode($current_stockData_content, true);

	//print_r($current_stockData);

	foreach ($current_stockData['Stock Quotes'] as $value) {
		array_push($new_stockData, array($value['1. symbol'] => $value['2. price']));
	}

	//print_r($new_stockData);

	$newData = false;
	if(!empty($new_stockData)){
		$directions = [];
		foreach ($last_stockData as $id => $value) {
			$result = 2;
			if($last_stockData[$id][key($value)] < $new_stockData[$id][key($value)]){
				$result = 1;
				$newData = true;
			} else if($last_stockData[$id][key($value)] > $new_stockData[$id][key($value)]){
				$result = 0;
				$newData = true;
			}
			$directions[$id] = $result;
		}
	} else {
		echo 'null';
	}

	if(isset($directions)){
		echo implode("",$directions);
	}

	if($newData == true){
		$file_url = 'data/gafa.json';
		$file = fopen($file_url, 'w+');
		fwrite($file, json_encode($new_stockData, JSON_NUMERIC_CHECK ));
		fclose($file);
	}
?>