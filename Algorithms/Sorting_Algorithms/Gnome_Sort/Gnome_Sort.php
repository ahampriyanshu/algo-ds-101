<?php 
// PHP Program to implement 
// Gnome Sort 
  
// A function to sort the  
// algorithm using gnome sort 
function gnomeSort($arr, $n) 
{ 
    $index = 0; 
  
    while ($index < $n)  
    { 
        if ($index == 0) 
            $index++; 
        if ($arr[$index] >= $arr[$index - 1]) 
            $index++; 
        else 
        { 
            $temp = 0; 
            $temp = $arr[$index]; 
            $arr[$index] = $arr[$index - 1]; 
            $arr[$index - 1] = $temp; 
            $index--; 
        } 
    } 
    echo "Sorted sequence ",  
         "after Gnome sort: "; 
    for ($i = 0; $i < $n; $i++) 
        echo $arr[$i] . " "; 
    echo "\n";  
} 
  
// Driver Code 
$arr = array(34, 2, 10, -9); 
$n = count($arr); 
  
gnomeSort($arr, $n); 
  
// This code is contributed 
// by Sam007 
?> 
