module SinglyLinkedList where

import Prelude hiding (tail, last)

data List a = Cons a (List a) | Nil deriving (Show)

size :: List a -> Int
size Nil = 0
size (Cons _ tail) = 1 + size tail

isEmpty :: List a -> Bool
isEmpty Nil = True
isEmpty _ = False

first :: List a -> Maybe a
first Nil = Nothing
first (Cons x _) = Just x

last :: List a -> Maybe a
last Nil = Nothing
last (Cons x Nil) = Just x
last (Cons _ rest) = last rest

addFirst :: a -> List a -> List a
addFirst = Cons

addLast :: a -> List a -> List a
addLast x Nil = Cons x Nil
addLast x (Cons el tail) = Cons el (addLast x tail)

-- Convenience method.
fromList :: [a] -> List a
fromList = foldr Cons Nil
