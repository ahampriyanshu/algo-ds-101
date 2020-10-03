<?php

// This will return their greatest common divisor (gcd)
function gcd($int1, $int2) {
    if ($int1 == 0 || $int2 == 0) return 0;
    if ($int1 == $int2) return $int1;
    if ($int1 > $int2) return gcd($int1 - $int2, $int2);
    return gcd($int1, $int2 - $int1);
}

// check if they are both relatively prime or not
function isRelativelyPrime($int1, $int2) {
    $result = gcd($int1, $int2) == 1 ? "is relatively prime \n": "is not relatively prime \n";
    return $result;
}

echo isRelativelyPrime(4, 9);
echo isRelativelyPrime(6, 8);
