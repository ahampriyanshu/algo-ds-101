module NthTribonacci(tribonacci) where

-- [0, 0, 1, 1, 2, 4, 7, 13, ...]
tribonacci :: [Integer]
tribonacci = extend [0, 0, 1] where
             extend (x1:x2:x3:_) = x1 : (extend (x2:x3:[x1+x2+x3]))

main = do 
         putStr "Number of elements: "
         n <- readLn
         putStrLn $ show $ take n tribonacci