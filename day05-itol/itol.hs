-- Haskell version of itol. Straight forward.

itol :: Integral a => a -> [a]
itol n | n == 0    = [0]
       | n < 0     = error "Negative numbers not accepted."
       | otherwise = reverse $ itol' n

itol' :: Integral a => a -> [a]
itol' 0 = []
itol' n = n `mod` 10 : itol' (n `div` 10)
