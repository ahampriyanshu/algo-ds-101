
<?php
//Radix Sort algorithm
// Description: The idea of Radix Sort is to divide the array in digit by digit starting from least significant digit to most significant digit. Radix sort uses counting sort as a subroutine to sort.
// Time Complexity: O((n+b) * logb(k))

// A function to do counting sort of arr[] 
// according to the digit represented by exp. 
function countSort(&$arr, $size, $exp) 
{ 
	$output = array_fill(0, $size, 0);  
	$count = array_fill(0, 10, 0); 

	// Store count of occurrences in count[] 
	for ($i = 0; $i < $size; $i++) 
		$count[ ($arr[$i] / $exp) % 10 ]++; 

	// Change count[i] so that count[i] 
	// now contains actual position of 
	// this digit in output[] 
	for ($i = 1; $i < 10; $i++) 
		$count[$i] += $count[$i - 1]; 

	// Build the output array 
	for ($i = $size - 1; $i >= 0; $i--) 
	{ 
		$output[$count[ ($arr[$i] / 
						$exp) % 10 ] - 1] = $arr[$i]; 
		$count[ ($arr[$i] / $exp) % 10 ]--; 
	} 

	// Copy the output array to arr[], so 
	// that arr[] now contains sorted numbers
	// according to current digit 
	for ($i = 0; $i < $size; $i++) 
		$arr[$i] = $output[$i]; 
} 

// The main function to that sorts arr[] 
// of size n using Radix Sort 
function radixsort(&$arr, $size) 
{ 
	
	// Find the maximum number to know
	// number of digits 
	$m = max($arr); 

	// Do counting sort for every digit. Note 
	// that instead of passing digit number, 
	// exp is passed. exp is 10^i where i is 
	// current digit number 
	for ($exp = 1; $m / $exp > 0; $exp *= 10) 
		countSort($arr, $size, $exp); 
} 

// Function to print an array 
function printArray(&$arr,$size) 
{ 
	for ($i = 0; $i < $size; $i++) 
		echo $arr[$i] . " "; 
} 

// Input is given here 

$arr = array(170, 43, 77, 90, 21, 820, 2, 65); 
$size = count($arr); 

// Function Call
radixsort($arr, $size); 
printArray($arr, $size); 

?>