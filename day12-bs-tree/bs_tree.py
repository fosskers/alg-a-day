# A binary search tree in Python.

class BSTree():
    '''A binary search tree.'''
    def __init__(self, items=None):
        self.root = None
        if items:  # Can be initialized with a list.
            for item in items:
                self.insert(item)

    def __str__(self):
        '''A pretty picture of a tree.
        May this be the definitive way to print trees, ever. EVER.
        Don't need a special case for empty trees, either :)
        '''
        leaves = []
        self._str(leaves, self.root, 0)
        return ''.join(leaves).rstrip()

    def _str(self, leaves, leaf, indent):
        '''Never have I high-fived myself so hard.
        This generates a tree string expanding out to the right via recursion.
        The indent of each leaf on its line its carried through the recursive
        process, increasing for each layer.'''
        if leaf:
            self._str(leaves, leaf.right, indent + 2)  # Arbitrary pad of 2.
            leaves.append(''.join((' ' * indent, str(leaf), '\n')))
            self._str(leaves, leaf.left, indent + 2)

    def __contains__(self, item):
        '''Determines if a value is in the tree.'''
        return self._contains(self.root, item)

    def _contains(self, leaf, item):
        '''Uses recursion to test for containment.'''
        if not leaf:
            return False
        if item == leaf.data:
            result = True
        elif item < leaf.data:
            result = self._contains(leaf.left, item)
        else:
            result = self._contains(leaf.right, item)
        return result

    def insert(self, item):
        '''Insert a value into the tree.'''
        self.root = self._insert(self.root, item)

    def _insert(self, leaf, item):
        '''Inserts a new Leaf via recursion.'''
        if not leaf:
            return Leaf(item)
        if item < leaf.data:
            leaf.left = self._insert(leaf.left, item)
        else:
            leaf.right = self._insert(leaf.right, item)
        return leaf

class Leaf():
    '''Or 'Node', if you wish.'''
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def __str__(self):
        return str(self.data)
        
