<?php
declare(strict_types=1);

function segmentedSieve(int $maxValue): array
{
    // Prepare a sieve, assume all numbers are prime.
    $primes = array_fill(0, $maxValue + 1, true);

    // 0 and 1 are not primes, skip
    $primes[0] = false;
    $primes[1] = false;

    for ($i = 2; $i <= $maxValue; $i++) {
        if ($primes[$i] === false) {
            // We already know this is not a prime, stop waisting time here
            continue;
        }
        for ($j = $i + $i; $j <= $maxValue; $j += $i) {
            // Mark every multiple of a prime as not prime
            $primes[$j] = false;
        }
    }

    // filter out all non-primes, then return the keys (primes)
    return array_keys(array_filter($primes));
}

$maxValue = isset($argv[1]) && is_numeric($argv[1]) ? (int) $argv[1] : 100;

$primes = segmentedSieve($maxValue);

printf('[%s]' . PHP_EOL, implode(', ', $primes));
