<?php

function factorial($n) {
    if ($n < 0) return false;
    if ($n == 0 || $n == 1) return 1;
    while($n > 1) return ($n * factorial($n - 1));
}
echo factorial(0);
