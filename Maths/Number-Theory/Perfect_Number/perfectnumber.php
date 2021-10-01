function isPerfect($n) { 
    $sum = 1; 
    for ($i = 2; $i * $i <= $n; $i++) { 
        if ($n % $i == 0) { 
            if($i * $i != $n) {
                $sum = $sum + $i + (int)($n / $i); 
            } else {
                $sum = $sum + $i;
            } 
        }
    }  
    if ($sum == $n && $n != 1) {
        echo "$n is a perfect number"; 
    } else {
        echo "$n is not a perfect number"; 
    }
}
isPerfect(6);