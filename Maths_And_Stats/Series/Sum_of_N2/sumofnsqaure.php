<?php 

function sum($n) 
{ 
	$sum = 0; 
	for ($i = 1; $i <= $n; $i++) 
		$sum += ($i * $i); 

	return $sum; 
} 

	// Driver code 
	$n = 2; 
	echo sum($n); 
	
 
?> 
