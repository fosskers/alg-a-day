from heap import *

def test(heap, items):
    print(heap)
    for item in items:
        print('Adding {}'.format(item))
        heap.insert(item)
        print(heap)

def delete_text(heap):
    print('Testing delete_max()...')
    print(heap)
    while(len(heap) > 0):
        print('Deleting max...')
        heap.delete_max()
        print(heap)

if __name__ == '__main__':
    x = Heap([1,8,5,0,3,2,6])
    print('First Heap:')
    print(x)
    y = Heap([11,4,15,7,99])
    print('Second Heap:')
    print(y)
    print('Merge!')
    x.merge(y)
    print(x)
    x = Heap(range(5))
    delete_text(x)
    
        
    
