<?php

	$arr=[];//define array
	$n = (int)readline('Enter number of elements : ');//take number of elements in array
	for ($i=0;$i<$n ;$i++ ) 
	{
	  array_push($arr,$i); //adding the $i variable to the array using array_push() function
	}
	print_r($arr);//print array
?>