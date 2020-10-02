Here's my solution for getting the GCD of several numbers.

<?php

/*
* function gcd()
*
* returns greatest common divisor
* between two numbers
* tested against gmp_gcd()
*/
function gcd($a, $b)
{
    if ($a == 0 || $b == 0)
        return abs( max(abs($a), abs($b)) );
       
    $r = $a % $b;
    return ($r != 0) ?
        gcd($b, $r) :
        abs($b);
}

/*
* function gcd_array()
*
* gets greatest common divisor among
* an array of numbers
*/
function gcd_array($array, $a = 0)
{
    $b = array_pop($array);
    return ($b === null) ?
        (int)$a :
        gcd_array($array, gcd($a, $b));
}

?>
