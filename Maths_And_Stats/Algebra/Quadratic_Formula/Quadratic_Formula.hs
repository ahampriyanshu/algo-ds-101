module Quadratic_Formula (csqrt, quadratic) where

import Data.Complex

csqrt z@(a :+ b) = let (mag, ph) = polar z in mkPolar (sqrt mag) (ph/2)

quadratic a b c = (
    quad (conjugate a) (conjugate b) (conjugate c) (+),
    quad (conjugate a) (conjugate b) (conjugate c) (-)
    ) where quad a b c op = (-b `op` csqrt ( b^2 - 4 * a * c))/(2 * a)
