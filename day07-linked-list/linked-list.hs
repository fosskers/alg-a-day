-- A linked list implementation in Haskell.
-- Again, this is somewhat silly to have in Haskell too,
-- but here it is.

data LinkedList a = EmptyList | Node a (LinkedList a)

instance Functor LinkedList where
  fmap f EmptyList = EmptyList
  fmap f (Node x next) = Node (f x) (fmap f next)
  
instance Show a => Show (LinkedList a) where
  show EmptyList = "EmptyList"
  show (Node x next) = show x ++ " ~> " ++ show next
  
newList :: a -> LinkedList a
newList x = Node x EmptyList

listPush :: a -> LinkedList a -> LinkedList a
-- End of the list.
listPush x EmptyList = newList x
listPush x (Node y next) = Node y (listPush x next)

listInsert :: a -> LinkedList a -> LinkedList a
-- Front of the list.
listInsert x list = Node x list

listRemove :: Eq a => a -> LinkedList a -> LinkedList a
listRemove _ EmptyList = EmptyList
listRemove x (Node y next) | x == y    = next
                           | otherwise = Node y (listRemove x next)

listElem :: Ord a => a -> LinkedList a -> Bool
-- Is there a more functional solution?
listElem _ EmptyList = False
listElem x (Node y next) | x == y    = True
                         | otherwise = listElem x next
                                       
listLength :: LinkedList a -> Int
listLength EmptyList     = 0
listLength (Node x next) = 1 + listLength next