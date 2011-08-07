-- FizzBuzz in Haskell. Not so fancy solution.

main = do
  let nums = map (\n -> if divBy 3 n && divBy 5 n then "FizzBuzz" else if divBy 3 n then "Fizz" else if divBy 5 n then "Buzz" else show n) [1..100]
  mapM putStrLn nums
  
divBy :: Int -> Int -> Bool
divBy m n = if n `mod` m == 0 then True else False