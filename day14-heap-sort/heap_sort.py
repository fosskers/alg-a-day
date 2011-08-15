from heap import *

def heap_sort(heap):
    h_swap = heap.swap
    h_cd = heap.cascade_down
    heap.lim = len(heap)
    while(heap.lim > 1):
        h_swap(0, heap.lim-1)
        heap.lim -= 1
        h_cd(0)
    return heap.leaves
