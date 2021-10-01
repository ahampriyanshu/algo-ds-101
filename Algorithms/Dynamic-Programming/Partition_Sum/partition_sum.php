<?php
declare(strict_types=1);

function partitionSum(array $input): array
{
    $total = array_sum($input);
    if ($total % 2 !== 0) {
        // There's no way we can split this equally
        return [];
    }

    $target = $total / 2;

    $temp = $input;
    sort($temp);
    $numElements = count($input);
    $usedElements = array_fill(0, $numElements, false);

    $usedElements[$numElements - 1] = true;
    $sum = $temp[$numElements - 1];

    if ($sum > $target) {
        // The largest number is already larger than the target value, no point in trying to partition with equal sums.
        return [];
    }

    for ($i = $numElements - 2; $i >= 0; $i--) {
        for ($j = $i; $j >= 0; $j--) {
            $n = $temp[$j];
            if ($sum + $n <= $target) {
                $usedElements[$j] = true;
                $sum += $n;
            }
            if ($sum === $target) {
                break 2;
            }
        }

        // Remove everything we tried so far
        for ($j = $i; $j >= 0; $j--) {
            if ($usedElements[$j]) {
                $usedElements[$j] = false;
                $sum -= $temp[$j];
            }
        }
    }

    if ($sum !== $target) {
        return [];
    }

    $firstPartition = [];
    $secondPartition = [];

    for ($i = 0; $i < count($usedElements); $i++) {
        if ($usedElements[$i]) {
            $firstPartition[] = $temp[$i];
        } else {
            $secondPartition[] = $temp[$i];
        }
    }

    return [$firstPartition, $secondPartition];
}

$array = [2, 4, 5, 6, 7, 8, 10];

$result = partitionSum($array);
if (count($result) > 0) {
    printf("[%s]\n[%s]", implode(', ', $result[0]), implode(', ', $result[1]));
} else {
    print 'Could not split array in two partitions with equals sums.';
}
