<?php
function sumOfDiv( $x) 
{ 

    $sum = 1; 
    for ( $i = 2; $i <= sqrt($x); $i++)  
    { 
        if ($x % $i == 0)  
        { 
            $sum += $i; 
  
           
            if ($x / $i != $i) 
                $sum += $x / $i; 
        } 
    } 
    return $sum; 
} 

function isAmicable( $a, $b) 
{ 
    return (sumOfDiv($a) == $b and 
            sumOfDiv($b) == $a); 
} 
  
$n1=(int)readline('Enter first number to check :');
$n2=(int)readline('Enter second number to check : ');
if (isAmicable($n1, $n2))
{
 echo "Pair is amicable";
}
else
{
 echo "Pair is not amicable";
}

?>
