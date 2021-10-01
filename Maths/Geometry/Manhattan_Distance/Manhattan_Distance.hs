{-- Calculates Manhattan distance between points in any dimension.
 -
 - Syntax:
 - > manhattan_distance [1,2,3] [7,7,8]
 - 16
 -}

module Manhattan_Distance (manhattan_distance) where

manhattan_distance xs ys = sum $ map (\(x, y) -> abs (x-y)) (zip xs ys)
