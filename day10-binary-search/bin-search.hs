-- Binary Search in Haskell.

import Data.List (elemIndex)


binSearch :: Ord a => a -> [a] -> Maybe Int
binSearch _ [] = Nothing            
binSearch n ns = binSearch' n 0 upper ns
                 where upper = length ns - 1

binSearch' :: Ord a => a -> Int -> Int -> [a] -> Maybe Int
binSearch' n low upp ns | low > upp  = Nothing
                        | n < midval = binSearch' n low (midpos - 1) ns
                        | n > midval = binSearch' n (midpos + 1) upp ns
                        | otherwise  = Just midpos
                          where
                            midval = ns !! midpos
                            midpos = (upp + low) `div` 2                    
                            
                            