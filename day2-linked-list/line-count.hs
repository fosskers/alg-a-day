-- Counts number of lines in a file.

import System.Environment
import System.Directory

main = do
  (filename:_) <- getArgs
  fileExists   <- doesFileExist filename
  if fileExists
     then do contents <- readFile filename
             putStrLn $ show $ length $ lines contents
     else do putStrLn "No such file."
  