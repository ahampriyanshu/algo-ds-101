module Clock_Angle (clock_angle) where

clock_angle hour minute =
    if (hour `elem` [1..12]) && (minute `elem` [0..59])
    then let {
        hour' = if hour == 12 then 0 else hour;
        minute_angle = minute * 6;
        hour_angle = hour' * 30 + minute * 0.5;
    }
    in Just (abs (hour_angle - minute_angle))
    else Nothing
