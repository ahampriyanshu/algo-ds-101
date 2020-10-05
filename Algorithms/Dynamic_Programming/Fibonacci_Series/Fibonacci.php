<?php
/**
 * Iterative solution for Fibonacci Numbers
 * Execute this file whith: php -f Fibonacci.php
 * @author juanmagutierrez89
 */

/**
 * This function returns the nth fibonacci number
 * @param int $n 
 * @return int the nth fibonacci number
 */
function fibonacci(int $n) : int {
    if ($n <= 1) {
        return $n;
    }
    
    $a = 0;
    $b = 1;
    
    for ($i = 0; $i < $n; $i++) {
        $a = $b - $a;
        $b = $a + $b;
    }
    
    return $a;
}


echo "First ten Fibonacci numbers: \n";
for ($i=0; $i < 10; $i++) {
    echo "fibonacci($i): ".fibonacci($i)."\n";
}

echo "\n";

?>