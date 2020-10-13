module Stack where

class Stack s where
  push :: a -> s a -> s a
  pop :: s a -> (Maybe a, s a)
  top :: s a -> Maybe a
  size :: s a -> Int
  isEmpty :: s a -> Bool
  empty :: s a

newtype ListStack a = ListStack [a] deriving (Show)

instance Stack ListStack where
  push x (ListStack st) = ListStack (x : st)

  pop (ListStack []) = (Nothing, empty)
  pop (ListStack (x:xs)) = (Just x, ListStack xs)

  top (ListStack []) = Nothing
  top (ListStack st) = Just (head st)

  size (ListStack st) = length st

  isEmpty (ListStack []) = True
  isEmpty _ = False

  empty = ListStack []
