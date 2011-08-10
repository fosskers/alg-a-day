-- Binary Search in Haskell.

binSearch :: Integral a => a -> [a] -> Bool
binSearch n [] = False
binSearch n ns | n < midval = binSearch n $ take midpos ns
               | n > midval = binSearch n $ drop (midpos + 1) ns       
               | otherwise  = True
               where
                 midval = ns !! midpos
                 midpos = length ns `div` 2
                    