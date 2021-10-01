module Factorial_of_Large_Number (fact) where

fact x = foldr (*) [1..x]
