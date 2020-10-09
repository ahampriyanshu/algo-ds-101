module DoublyLinkedLists where

import Prelude hiding (last, elem)

-- Implementation without a header/trailer sentinel, meaning some operations
-- take O(n) instead of O(1).
data DList a
  = Empty
  | Node { prev :: DList a
         , elem :: a
         , next :: DList a }
  deriving (Eq)

instance Show a => Show (DList a) where
  show (Node Empty x Empty) = "[" ++ show x ++ "]"
  show (Node Empty x next) = "[" ++ show x ++ "," ++ show next
  show (Node _ x Empty) = show x ++ "]"
  show (Node _ x next) = show x ++ "," ++ show next
  show Empty = "[]"

fromList :: [a] -> DList a
fromList = append Empty
  where
    append :: DList a -> [a] -> DList a
    append _ [] = Empty
    append prev (x:xs) = head
      where
        head = Node prev x tail
        tail = append head xs

size :: DList a -> Int
size Empty = 0
size (Node _ _ next) = 1 + size next

isEmpty :: DList a -> Bool
isEmpty Empty = True
isEmpty _ = False

first :: DList a -> Maybe a
first Empty = Nothing
first (Node _ a _) = Just a

last :: Eq a => DList a -> Maybe a
last Empty = Nothing
last (Node _ a next)
  | next == Empty = Just a
  | otherwise = last next

addFirst :: a -> DList a -> DList a
addFirst x Empty = Node Empty x Empty
addFirst x (Node prev y next) =
  let newFirst = Node Empty x newSecond
      newSecond = Node newFirst y next
   in newFirst

-- WIP: doesnt work for lists with length > 1
addLast :: a -> DList a -> DList a
addLast x Empty = Node Empty x Empty
addLast x list = let last' = lastNode list
                     secondToLast = Node (prev last') (elem last') newLast
                     newLast = Node secondToLast x Empty
                 in rewind newLast
  where
    lastNode :: DList a -> DList a
    lastNode Empty = Empty
    lastNode (Node prev x Empty) = Node prev x Empty
    lastNode (Node _ _ next) = lastNode next

    rewind :: DList a -> DList a
    rewind Empty = Empty
    rewind (Node Empty x next) = Node Empty x next
    rewind (Node prev _ _) = rewind prev
