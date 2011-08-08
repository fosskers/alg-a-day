{- Solving primes in Haskell!
   The 'primes' infinite data structure and the function 'isPrime'
   feed off each other, where numbers being tested are only divided 
   by prime numbers less than them, but those prime numbers exist in 
   the list 'primes' which gains values from checking integers with
   isPrime... see the circle?
   It turns out giving 2 and 3 as starting values is enough to produce
   all primes in this circular mannar.
-}


-- A list of all prime numbers.
primes :: Integral a => [a]
primes = 2 : 3 : filter isPrime [5,7..]

isPrime :: Integral a => a -> Bool
isPrime n | n < 2 = False
          | n == 2 = True
          | n `mod` 2 == 0 = False
          | otherwise      = isPrime' n divs
          where
            divs = takeWhile (<= root) primes
            root = floor $ sqrt $ fromIntegral n

isPrime' :: Integral a => a -> [a] -> Bool
-- Should in theory allow for faster prime detection.
-- Only tests for division by other primes.
isPrime' n [] = True
isPrime' n (p:ps) | n `mod` p == 0 = False
                  | otherwise      = isPrime' n ps