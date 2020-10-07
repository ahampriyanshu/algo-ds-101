{-- Calculates distance between points in any dimension.
 -
 - Syntax:
 - > distance_formula [1,2] [2,3] 
 - 1.4142135623730951
 -}

module N_dimensional_distance (distance_formula) where

distance_formula xs ys = sqrt $ sum $ map (\(x, y) -> (x-y)^2) (zip xs ys)
