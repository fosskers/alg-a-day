-- Binary Search Tree

import qualified Data.Foldable as F
import Data.Monoid

data Tree a = EmptyTree | Leaf a (Tree a) (Tree a) deriving (Read, Eq)

-- Makes our tree map(p)able.
instance Functor Tree where
    fmap f EmptyTree = EmptyTree
    fmap f (Leaf x left right) = Leaf (f x) (fmap f left) (fmap f right)
    
-- Makes our tree foldable.
instance F.Foldable Tree where
  foldMap f EmptyTree = mempty
  foldMap f (Leaf x left right) = F.foldMap f left `mappend`
                                  f x              `mappend`
                                  F.foldMap f right
                           
instance Show a => Show (Tree a) where
  show EmptyTree = "Leafless Tree"
  show leaf = showTree leaf 0
  
showTree :: Show a => Tree a -> Int -> String  
showTree EmptyTree _ = ""
showTree (Leaf x left right) ind = showTree right ind' ++ 
                                   replicate ind ' '   ++ 
                                   show x              ++ 
                                   "\n"                ++
                                   showTree left ind' 
                                     where ind' = ind + 2
                                    
newTree :: a -> Tree a
newTree x = Leaf x EmptyTree EmptyTree

treeInsert :: Ord a => a -> Tree a -> Tree a
treeInsert x EmptyTree = newTree x
treeInsert x orig@(Leaf a left right)
           | x == a = orig  --Leaf x left right
           | x < a  = Leaf a (treeInsert x left) right
           | x > a  = Leaf a left (treeInsert x right)

treeElem :: Ord a => a -> Tree a -> Bool
treeElem _ EmptyTree = False
treeElem x (Leaf a left right)
         | x == a = True
         | x < a  = treeElem x left
         | x > a  = treeElem x right
                    
fromList :: Ord a => [a] -> Tree a
-- Creates a tree from a given list.
fromList [] = EmptyTree
fromList xs = foldl (\acc x -> treeInsert x acc) EmptyTree xs