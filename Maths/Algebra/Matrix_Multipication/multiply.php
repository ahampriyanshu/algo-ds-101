<?php 
function multiply(&$mat1, &$mat2, &$res) 
{ 
	$N = 4; 
	for ($i = 0; $i < $N; $i++) 
	{ 
		for ($j = 0; $j < $N; $j++) 
		{ 
			$res[$i][$j] = 0; 
			for ($k = 0; $k < $N; $k++) 
				$res[$i][$j] += $mat1[$i][$k] * 
								$mat2[$k][$j]; 
		} 
	} 
} 

// Driver Code 
$mat1 = array(array(1, 6, 5, 1), 
			array(2, 8, 2, 2), 
			array(3, 4, 3, 2), 
			array(8, 7, 9, 4)); 

$mat2 = array(array(1, 1, 1, 1), 
			array(2, 2, 2, 2), 
			array(3, 3, 3, 3), 
			array(4, 4, 4, 4)); 

multiply($mat1, $mat2, $res); 
$N = 4; 
echo ("Result matrix is \n"); 
for ($i = 0; $i < $N; $i++) 
{ 
	for ($j = 0; $j < $N; $j++) 
	{ 
		echo ($res[$i][$j]); 
		echo(" "); 
	} 
	
} 
?> 
