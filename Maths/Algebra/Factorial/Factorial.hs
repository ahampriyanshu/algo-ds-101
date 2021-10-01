module Factorial (fact) where

fact x = foldr (*) [1..x]
