<?php 

function isPerfectNumber($N) 
{
	$sum = 0; 
	for ($i = 1; $i < $N; $i++) 
	{ 
		if ($N % $i == 0) 
		{ 
			$sum = $sum + $i; 
		}	 
	} 
	

	return $sum == $N; 
} 

// Driver's code 
$N = 6; 

if (isPerfectNumber($N)) 
	echo " Perfect Number"; 
else
	echo "Not Perfect Number"; 
?> 
