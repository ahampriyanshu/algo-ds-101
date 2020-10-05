<?php 
 
function sumOfSeries( $n) 
{ 
    $sum = 0; 
    for ($x = 1; $x <= $n; $x++) 
        $sum += $x * $x * $x; 
    return $sum; 
} 
  
$n = 5; //enter the number here
echo sumOfSeries($n); 
  

?>