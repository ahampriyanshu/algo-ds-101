<?php 
function expoSearch($arr, $n, $x) 
{ 
    if ($arr[0] == $x) 
        return 0; 
    $i = 1; 
    while ($i< $n and $arr[$i] <=$x) 
        $i = $i * 2; 
    return binSearch($arr, $i / 2, min($i, $n), $x); 
} 
function binSearch($arr, $l, $r, $x) 
{ 
    if ($r >= $l) 
    { 
        $mid = $l + ($r - $l)/2; 
        if ($arr[$mid] == $x) 
            return $mid; 
        if ($arr[$mid] > $x) 
            return binSearch($arr, $l, $mid - 1, $x); 
        return binSearch($arr, $mid + 1, $r, $x); 
    } 
    return -1; 
} 
$arr = array(2, 3, 4, 10, 40); 
$n = count($arr); 
$x = 10; 
$result = expoSearch($arr, $n, $x); 
if($result == -1) 
    echo "Element is not present in array"; 
else
    echo "Element is present at index ", $result; 
?> 