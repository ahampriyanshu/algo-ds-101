main = do {
    putStrLn "Enter sides of the triangle";
    sides <- getLine;
    putStrLn (
        let {
            [x,y,z] = map (\x -> read x :: Int) (words sides);
            hyp = maxx x y z;
            legs = filter (< hyp) [x,y,z];
        } in (
            if isRectTriangle [x,y,z]
            then "Hypotenuse: " ++ show hyp ++ ", legs: " ++ show legs
            else "The sides don't follow Pythagoras' theorem."
        )
    )
}

isRectTriangle [a,b,c] = or [
    a^2 + b^2 == c^2,
    b^2 + c^2 == a^2,
    c^2 + a^2 == b^2]

maxx a b c = max a (max b c)
