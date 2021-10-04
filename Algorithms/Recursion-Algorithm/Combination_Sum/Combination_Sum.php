<?php

/**
 * Calculate combinational sum
 * 
 * @param array $elements
 * @param int $target Target number
 */
function combinationalSum(array $elements, int $target)
{
    if(count($elements) !== count(array_unique($elements))) {
        throw "Element array is not distict.";
    }

    if($target < 0) {
        throw "Target should be a posivite number.";
    }

    $combinations = [];

    for($i = 0; $i < count($elements); $i++) {
        $combination = findCombination(array_slice($elements, $i), $target, []);
        
        if(count($combination) > 0) {
            $combinations[] = $combination;
        }
    }

    printCombinations($combinations);
}

/**
 * Find the combination for a specific target
 * 
 * @param array $elements
 * @param int $target
 * @param array $combination possible combinations from previous iteration
 */
function findCombination(array $elements, int $target, array $combination): array
{
    for($i = 0; $i < count($elements); $i++) {
        $newTarget = $target - $elements[$i];

        if($newTarget == 0) {
            $combination[] = $elements[$i];
            return $combination;
        }

        if($newTarget < 0) {
            continue;
        }

        $combination[] = $elements[$i];
        return findCombination(array_slice($elements, $i + 1), $newTarget, $combination);
    }
    return [];
}

/**
 * Print the combinations
 * 
 * @param array $combinations
 */
function printCombinations(array $combinations) 
{
    for($i = 0; $i < count($combinations); $i++) {
        for($j = 0; $j < count($combinations[$i]); $j++) {
            echo $combinations[$i][$j] . " ";
        }
        echo "\n";
    }
}

//Test
$elements = [1, 5, 2, 8, 6, 4, 3, 10];
$target = 10;
combinationalSum($elements, $target);

//Result: 5 2 3
//        2 8
//        6 4
//        10