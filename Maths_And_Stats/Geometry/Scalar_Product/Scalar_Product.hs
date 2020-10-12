module Scalar_Product (scalar) where

[] `scalar` [] = 0
(x:xs) `scalar` (y:ys) = x * y + xs `scalar` ys
