-- Binary Search in Haskell.

binSearch :: Integral a => a -> [a] -> Int
binSearch n [] = (-1)
binSearch n ns | n < midval = binSearch n $ take midpos ns
               | n > midval = binSearch n $ drop (midpos + 1) ns       
               | otherwise  = midpos
               where
                 midval = ns !! midpos
                 midpos = length ns `div` 2
                    