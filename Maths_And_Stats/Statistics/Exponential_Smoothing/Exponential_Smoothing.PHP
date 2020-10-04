<?php

/* Triple exponential holt winters smoothing */

/**
 * Smooth supplied timeline data 3 ways - overall, by trend and by season. 
 *
 * @param array $data - 1d array of data
 * @param int $season_length  - the number of entries that represent a 'season'
 * @param float $alpha - data smoothing factor
 * @param float $beta - trend smoothing factor
 * @param float $gamma - seasonality smoothing factor
 * @param float $dev_gamma - smoothing factor for deviations
 * @return array - the smoothed data
 */
function holt_winters($data, $season_length = 7, $alpha = 0.2, $beta = 0.01, $gamma = 0.01, $dev_gamma = 0.1) {
    
    // Calculate an initial trend level
    $trend1 = 0;
    for($i = 0; $i < $season_length; $i++) {
        $trend1 += $data[$i];
    }
    $trend1 /= $season_length;
    
    $trend2 = 0;
    for($i = $season_length; $i < 2*$season_length; $i++) {
        $trend2 += $data[$i];
    }
    $trend2 /= $season_length;
    
    $initial_trend = ($trend2 - $trend1) / $season_length;
    
    // Take the first value as the initial level
    $initial_level = $data[0];
        
    // Build index
    $index = array();
    foreach($data as $key => $val) {
        $index[$key] = $val / ($initial_level + ($key + 1) * $initial_trend);
    }
    
    // Build season buffer
    $season = array_fill(0, count($data), 0);
    for($i = 0; $i < $season_length; $i++) {
        $season[$i] = ($index[$i] + $index[$i+$season_length]) / 2;
    }
    
    // Normalise season
    $season_factor = $season_length / array_sum($season);
    foreach($season as $key => $val) {
        $season[$key] *= $season_factor;
    }
    
    
    $holt_winters = array();
    $deviations = array();
    $alpha_level = $initial_level;
    $beta_trend = $initial_trend;
    foreach($data as $key => $value) {
        $temp_level = $alpha_level;
        $temp_trend = $beta_trend;
        
        $alpha_level = $alpha * $value / $season[$key] + (1.0 - $alpha) * ($temp_level + $temp_trend);
        $beta_trend = $beta * ($alpha_level - $temp_level) + ( 1.0 - $beta ) * $temp_trend;
        
        $season[$key + $season_length] = $gamma * $value / $alpha_level + (1.0 - $gamma) * $season[$key];
        
        $holt_winters[$key] = ($alpha_level + $beta_trend * ($key + 1)) * $season[$key];
        $deviations[$key] = $dev_gamma * abs($value - $holt_winters[$key]) + (1-$dev_gamma) 
                                * (isset($deviations[$key - $season_length]) ? $deviations[$key - $season_length] : 0);
    }
    
    /* Could forecast a bit!
    for($i = 1; $i <= $season_length; $i++) {
        $holt_winters[$key + $i] = $alpha_level + $beta_trend * $season[$key + $i];
    }
    */
    
    return array($holt_winters, $deviations);
}

/*************************/
/*** Use the function ***/
/*************************/

// Load in some web stats data
$fh = fopen("data/webstats.csv", 'r');
$data = array();
while($csv = fgetcsv($fh)) {
    $data[] = $csv[1];
}

list($newdata, $deviations) = holt_winters($data, 30);

// Echo it out in a format to paste into to the charts JS
foreach($newdata as $key => $d) {
    echo "data.addRow([" . 
            $key . ", " . 
            (isset($data[$key]) ? $data[$key] : 0) . ", " . 
            $d . ", " . 
            ($d + 3*$deviations[$key]) .", " . 
            ($d - 3*$deviations[$key]) .", " . 
            "]);\n";
}
