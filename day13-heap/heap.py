# A heap of leaves. In summer!

class Heap():
    '''A Maximum Binary Heap.'''
    def __init__(self, items=None):
        self.leaves = []
        self.indicies = {}
        self.lim = 0  # Used in Heap Sort.
        if items:
            self.merge(items)

    def __iter__(self):
        for leaf in self.leaves:
            yield leaf
            
    def __len__(self):
        return len(self.leaves)
 
    def __str__(self):
        '''Similar to the algorithm found in the Binary Search Tree lib.'''
        if not self.leaves:
            return ''
        tree = []
        self._str(tree, 0, 0)
        return ''.join(tree).rstrip()

    def _str(self, tree, index, ind):
        '''Uses recursion to construct a string of the Heap.'''
        if self.in_heap(index):
            self._str(tree, self.second_born_pos(index), ind + 2)
            tree.append(''.join((' ' * ind, str(self.leaves[index]), '\n')))
            self._str(tree, self.first_born_pos(index), ind + 2)

    def merge(self, iterator):
        '''Merges this Heap with a fellow iterator.'''
        for item in iterator:
            self.insert(item)

    def in_heap(self, index):
        '''Given an index, determines if there is a leaf there.'''
        return True if index < self.lim else False

    def first_born_pos(self, index):
        '''Given a parent's index, return the index of its first child.'''
        return (2 * index) + 1

    def second_born_pos(self, index):
        '''Given a parent's index, return the index of its second child.'''
        return (2 * index) + 2

    def parent_pos(self, index):
        '''Given a child's index, return the index of its parent.'''
        return (index - 1) // 2

    def insert(self, item):
        '''Inserts a new child into the Heap.'''
        self.leaves.append(item)
        self.lim += 1
        self.cascade_up(self.lim - 1)

    def cascade_up(self, index):
        '''Given an index of a child, raises that child through the heap
        as far as it needs to go to restore the Heap Property.
        '''
        if index:  # 0 evaluates to False.
            parent = self.parent_pos(index)
            if self.leaves[parent] < self.leaves[index]:
                self.swap(parent, index)
                self.cascade_up(parent)

    def swap(self, n, m):
        '''Swaps two elements.'''
        self.leaves[n], self.leaves[m] = self.leaves[m], self.leaves[n]
    
    def find_max(self):
        '''Returns the max.'''
        return self.leaves[0] if self.leaves else None

    def delete_max(self):
        '''Deletes the root (maximum value).'''
        self.swap(0, -1)  
        del self.leaves[-1]
        self.lim -= 1
        self.cascade_down(0)

    def cascade_down(self, index):
        '''Given an index of a parent, lowers it through the Heap
        as far as it needs to go to restore the Heap Property.
        '''
        older_pos = self.find_older_pos(index)
        if older_pos:
            if self.leaves[older_pos] > self.leaves[index]:
                self.swap(older_pos, index)
                self.cascade_down(older_pos)

    def find_older_pos(self, index):
        '''Given an index, determines which of its children are greater.'''
        fst_pos = self.first_born_pos(index)
        snd_pos = self.second_born_pos(index)
        older_pos = None
        if self.in_heap(fst_pos):
            if (self.in_heap(snd_pos) and \
                self.leaves[snd_pos] > self.leaves[fst_pos]):
                older_pos = snd_pos
            else:
                older_pos = fst_pos
        return older_pos
