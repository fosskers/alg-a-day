-- Binary Max Heap in Haskell

import qualified Data.Foldable as F
import Data.Monoid 

data Heap a = EmptyHeap | Leaf a (Heap a) (Heap a) deriving (Eq, Ord)

instance F.Foldable Heap where
  foldMap f EmptyHeap = mempty
  foldMap f (Leaf x left right) = F.foldMap f left `mappend`
                                  f x              `mappend`
                                  F.foldMap f right

instance Show a => Show (Heap a) where
  show EmptyHeap  = "Empty Heap"
  show leaf = showHeap leaf 0
  
showHeap :: Show a => Heap a -> Int -> String  
showHeap EmptyHeap _ = ""
showHeap (Leaf x l r) ind = showHeap r ind'   ++
                            replicate ind ' ' ++
                            show x            ++
                            "\n"              ++
                            showHeap l ind'   
                              where ind' = ind + 2

newHeap :: a -> Heap a
newHeap x = Leaf x EmptyHeap EmptyHeap

heapMax :: Heap a -> Maybe a
heapMax EmptyHeap    = Nothing
heapMax (Leaf x l r) = Just x

-- I really want to fuse heapInsert and cascade together.
heapInsert :: Ord a => a -> Heap a -> Heap a
heapInsert x EmptyHeap = newHeap x
heapInsert x leaf@(Leaf a l r)
  | x > a           = cascade x leaf
  | l == EmptyHeap  = Leaf a (newHeap x) r
  | r == EmptyHeap  = Leaf a l (newHeap x)
  | otherwise       = Leaf a l' r'
    where
      l' = if l <= r then heapInsert x l else l
      r' = if r < l then heapInsert x r else r               
      
cascade :: Ord a => a -> Heap a -> Heap a                
cascade x (Leaf a l r)
  | l == EmptyHeap  = Leaf x (newHeap a) r
  | r == EmptyHeap  = Leaf x l (newHeap a)
  | otherwise       = Leaf x l' r'
    where
      l' = if l <= r then heapInsert a l else l
      r' = if r < l then heapInsert a r else r

heapRemove :: Ord a => Heap a -> Heap a
heapRemove EmptyHeap    = EmptyHeap
heapRemove (Leaf a l r) = heapMerge l r  -- This is severe cheating.

heapMerge :: Ord a => Heap a -> Heap a -> Heap a
heapMerge orig other = F.foldl (\acc n -> heapInsert n acc) orig other

listToHeap :: Ord a => [a] -> Heap a
listToHeap list = F.foldl (\acc n -> heapInsert n acc) EmptyHeap list