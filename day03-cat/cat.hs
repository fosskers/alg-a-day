-- Prints the contents of a given file.

import System.Environment
import System.IO

main = do
  (filename:_) <- getArgs
  contents     <- readFile filename
  putStr contents