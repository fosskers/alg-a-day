-- Circular Binary Search in Haskell.
{- Test with this in the interpretter:
-- Testing a normal list:
let ns = [1..1000]
map (\n -> binSearch n ns) ns
filter (== Nothing) $ map (\n -> binSearch n ns) ns
.
.
and then
.
.
-- Testing a split list:
let ns = [1100..1500] ++ [1..1000]
map (\n -> binSearch n ns) ns
filter (== Nothing) $ map (\n -> binSearch n ns) ns
-}

import Data.List (elemIndex)

binSearch :: Ord a => a -> [a] -> Maybe Int
binSearch _ [] = Nothing            
binSearch n ns = binSearch' n 0 upper ns
                 where upper = length ns - 1

binSearch' :: Ord a => a -> Int -> Int -> [a] -> Maybe Int
binSearch' n low upp ns 
  | low > upp                 = Nothing
  | n == midval               = Just midpos
  | lowval <= n && n < midval = binSearch' n low (midpos - 1) ns
  | midval < n && n <= uppval = binSearch' n (midpos + 1) upp ns
  | lowval > midval           = binSearch' n low (midpos - 1) ns
  | otherwise                 = binSearch' n (midpos + 1) upp ns
    where
      midval = ns !! midpos
      midpos = (upp + low) `div` 2                    
      lowval = ns !! low
      uppval = ns !! upp
                            
                            