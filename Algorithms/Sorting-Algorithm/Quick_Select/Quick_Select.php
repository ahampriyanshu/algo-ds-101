<?php

/**
 * Select kth smallest element
 * 
 * @param array $list Elements
 * @param int $kthPosition Kth position
 * @return mixed
 */
function kthSmallest(array $list, int $kthPosition) {
    $high = count($list) - 1;
    $kthIndex = $kthPosition -1;
    
    if($high < $kthIndex) {
        throw "Index out of bound";
    }

    return quickSelect($list, 0, $high, $kthIndex);  
}

/**
 * Quick selection of element
 * 
 * @param array $list Elements
 * @param int $low Lowest index
 * @param int $high Higest index
 * @param int $kthPosition Kth index
 * @return mixed
 */
function quickSelect(array $list, int $low, int $high, int $kthIndex) {
    $partition = partition($list, $low, $high);

    if($partition == $kthIndex) {

        return $list[$partition];

    } elseif($partition < $kthIndex) {

        return quickSelect($list, $partition + 1, $high, $kthIndex);

    } else {

        return quickSelect($list, $low, $partition - 1, $kthIndex); 
    }
}

/**
 * Partition of the elements
 * 
 * @param array $list elements
 * @param int $low Lowest index
 * @param int $high Highest index
 * @return int $pivotLoc Pivot location
 */
function partition(array &$list, int $low, int $high) { 
    $pivot = $list[$high];
    $pivotLoc = $low;

    for ($i = $low; $i <= $high; $i++) {

        if($list[$i] < $pivot) {

            $temp = $list[$i]; 
            $list[$i] = $list[$pivotLoc]; 
            $list[$pivotLoc] = $temp; 
            $pivotLoc++; 
        }
    }
    
    $temp = $list[$high]; 
    $list[$high] = $list[$pivotLoc]; 
    $list[$pivotLoc] = $temp;
    return $pivotLoc; 
}


//Test
$elements = [7, 4, 5, 8 , 9, 0, 10, 16];
$kthPosition = 5;

echo "The kth smallest element for {$kthPosition} is: " . kthSmallest($elements, $kthPosition);

//Output: The kth smallest element for 5 is: 8