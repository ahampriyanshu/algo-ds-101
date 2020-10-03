<?php

function mode($arr) {
    $arrCnt = array_count_values($arr);
    $mode = array_keys($arrCnt, max($arrCnt));
    return "The Mode is " . implode( ", ", $mode) . "\n";
}

echo mode([6, 3, 9, 5, 9, 3]);
echo mode([6, 3, 9, 6, 6, 5, 9, 3]);
