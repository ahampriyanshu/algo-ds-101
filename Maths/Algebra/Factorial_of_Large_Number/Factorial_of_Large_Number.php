<?php

$digitArray = [];

/**
 * Factorial calculation
 *
 * @param int $number
 * @return mixed $factorial
 */
function factorial(int $number) {
    if($number < 2) {
        return 1;
    }

    global $digitArray;
    $digitArray[] = 1;

    for($i = 2; $i <= $number; $i++) {
        calcFactorialInDigit($i);
    }
    return implode('', $digitArray);
}

/**
 * Calculate factorial and stored in array as digit
 * 
 * @param int $number
 * @return void
 */
function calcFactorialInDigit(int $number) {
    global $digitArray;
    $carry = 0;

    for($i = count($digitArray) - 1; $i >= 0; $i--) {
        $currentResult = $digitArray[$i] * $number + $carry;
        $digitArray[$i] = (int) ($currentResult % 10);
        $carry = (int) ($currentResult / 10);
    }

    while($carry > 0) {
        array_unshift($digitArray, (int) ($carry % 10));
        $carry = (int) ($carry / 10);
    }
}

// Test
$number = 70;
echo "Factorial of {$number} is: " . factorial($number);

//Output => Factorial of 70 is: 11978571669969891796072783721689098736458938142546425857555362864628009582789845319680000000000000000
