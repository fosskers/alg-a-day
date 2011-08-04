-- Demonstrating getting command-line args in Haskell.

import System.Environment

main = do
  args <- getArgs  -- That's it.
  putStrLn "You passed: "
  mapM putStrLn args  -- map an IO action across a list.