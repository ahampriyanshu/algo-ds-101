module Polar_Cartesian_Conversion (polar_to_cartesian) where

polar_to_cartesian [mod, arg] = [mod * cos(arg), mod * sin(arg)]
