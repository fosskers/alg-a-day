from heap import *
from heap_sort import *
from time import time

def test_heap(sort, heap):
    print('Testing heap of size {}'.format(len(heap)))
    start = time()
    sort(heap)
    end = time()
    print('Done in {} sec'.format(end - start))

def visual_test(heap):    
    print(heap)
    print('Sorted:')
    print(heap_sort(heap))
    print()

if __name__ == '__main__':
    sorts = (heap_sort,)  # Add a different sort here for more tests!
    tests = (100, 1000, 5000, 10000, 100000)
    for sort in sorts:
        print('Testing {}'.format(sort.__name__))
        for test in tests:
            heap = Heap(range(test))
            test_heap(sort, heap)
        print()
    print('Visual test:')
    x = Heap(range(10))
    visual_test(x)
    x = Heap(['bob', 'jim', 'sally', 'anne', 'frank', 'billy', 'james'])
    visual_test(x)
    
    
