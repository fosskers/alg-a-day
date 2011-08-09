-- quick-sort in Haskell. Not the standard crappy version.
-- Pivot comes from the middle, not the front.

import Data.List (delete)

quickSort :: Ord a => [a] -> [a]
quickSort [] = []
quickSort xs = quickSort smalls ++ [k] ++ quickSort bigs
               where
                 k      = xs !! (length xs `div` 2)
                 smalls = filter (<= k) xs'
                 bigs   = filter (> k) xs'
                 xs'    = delete k xs
  
                     
