# Quick demonstration.

from bs_tree import *

def test_contains(tree, item):
    '''Sees if 'tree' contains 'item'.'''
    print('Does the tree contain {}?'.format(item))
    print(item in tree)

if __name__ == '__main__':
    items = [5,3,7,2,4,6,8,1,2,3,4,5,6,7,9]
    print('Creating tree out of ->', items)
    x = BSTree(items)
    print(x)
    test_contains(x, 1)
    test_contains(x, 5)
    test_contains(x, 10)

    print('Inserting 10...')
    x.insert(10)
    print(x)
    test_contains(x, 10)

    # Names.
    names = ['Molly', 'Jim', 'Bob', 'Sam', 'Frank', 'Anne', 'May', 'George',
             'Terry', 'Zander', 'James', 'Oliver']
    print('Tree of names from ->', names)
    x = BSTree(names)
    print(x)
