<?php

$a = (int)readline("Enter the first term: ");
$n = (int)readline("Enter the number of terms: ");
$d = (int)readline("Enter the difference between the terms: ");

echo "AP: ";
for ($i=0; $i < $n; $i++) { 
    echo $a + ($i * $d);
}

?>