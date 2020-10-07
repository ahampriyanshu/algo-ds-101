module Vector_Product (vector) where

[x1,x2,x3] `vector` [y1,y2,y3] = 
    [x2 * y3 - x3 * y2,
     x3 * y1 - x1 * y3,
     x1 * y2 - x2 * y1]
