-- A different implementation of FizzBuzz in Haskell.
-- Every value essentially starts as 'FizzBuzz' and gets shaved down
-- if it turns out it wasn't a multiple of 3 or 5.

import Data.List ((\\))

type FizzBuzzPair = (Int,String)

main = do
  let nums   = zip [1..100] $ replicate 100 "FizzBuzz"
      noFizz = map (shaver 3 "Fizz") nums
      noBuzz = map (shaver 5 "Buzz") noFizz
  mapM (\(n,cs) -> if null cs then putStrLn $ show n else putStrLn cs) noBuzz

shaver :: Int -> String -> FizzBuzzPair -> FizzBuzzPair
shaver m shave (n,cs) = if not $ divBy m n then (n, cs \\ shave) else (n,cs)

divBy :: Int -> Int -> Bool
divBy m n = if n `mod` m == 0 then True else False
      