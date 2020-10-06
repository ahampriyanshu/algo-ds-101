<?php 
$d = 256; 

function search($pat, $txt, $q) 
{ 
	$M = strlen($pat); 
	$N = strlen($txt); 
	$i; $j; 
    $p = 0; //hash value for pattern
    
	$t = 0; // hash value for text
	
	$h = 1; 
	$d =1; 


	for ($i = 0; $i < $M - 1; $i++) 
		$h = ($h * $d) % $q; 


	for ($i = 0; $i < $M; $i++) 
	{ 
		$p = ($d * $p + $pat[$i]) % $q; 
		$t = ($d * $t + $txt[$i]) % $q; 
	} 

	
	for ($i = 0; $i <= $N - $M; $i++) 
	{ 

		
		if ($p == $t) 
		{ 
			for ($j = 0; $j < $M; $j++) 
			{ 
				if ($txt[$i + $j] != $pat[$j]) 
					break; 
			} 

			if ($j == $M) 
				echo "Pattern found at index ", $i, "\n"; 
		} 

		if ($i < $N - $M) 
		{ 
			$t = ($d * ($t - $txt[$i] * $h) + $txt[$i + $M]) % $q; 

		
			if ($t < 0) 
			$t = ($t + $q); 
		} 
	} 
} 

$txt = "GEEKS FOR GEEKS"; 
$pat = "GEEK"; 
$q = 101;  
search($pat, $txt, $q); 

?> 
