<?php
function maxAchieveable($num)
{
    $row = range(1, $num);
    shuffle($row);
    define("ROW", $row);

    $matrix = array_map(function() use($num){
        return array_pad(array(), $num, 0);
    }, range(1, $num));

    foreach(range(0, $num-1) as $d)
    {
        foreach(range($d, $num) as $j)
        {
            $i = $j - $d;
            list($a, $b, $c) = [0, 0, 0];

            if(($i+2) <= $j) $a = $matrix[$i+2][$j];
            if(($i+1) <= $j) $b = $matrix[$i+1][$j-1];
            if($i <= $j) $c = $matrix[$i][$j-2];

            $matrix[$i][$j] = max(ROW[$i] + min($a, $b) , ROW[$j] + min($b, $c));
        }
    }

    return "Row: ".json_encode(ROW)." , Max Achieveable: ".$matrix[0][$num-1];
}
?>
