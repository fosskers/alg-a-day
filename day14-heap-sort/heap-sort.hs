-- Heap sort in Haskell!
import Heap
import Data.Maybe (fromJust)

heapSort :: Ord a => Heap a -> [a]
heapSort heap = reverse $ heapSort' heap

heapSort' :: Ord a => Heap a -> [a]
heapSort' EmptyHeap = []
heapSort' heap      = fromJust (heapMax heap) : heapSort' (heapRemove heap)