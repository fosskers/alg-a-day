# A linked list in Python. 
# Pretty pointless due to the existence of built-in non-homogenious lists,
# but whatever.

class LinkedList():
    '''A linked list. Hurray.'''
    def __init__(self, initial_data):
        self.root = Node(initial_data)
        self.end  = self.root

    def __str__(self):
        nodes = []
        curr  = self.root
        while curr:
            nodes.append(str(curr))
            curr = curr.next
        return ''.join(nodes)

    def __contains__(self, data):
        curr = self.root
        while curr:
            if curr.data == data:
                return True
            curr = curr.next
        return False

    def __len__(self):
        curr = self.root
        result = 0
        while curr:
            result += 1
            curr = curr.next
        return result
        
    def push(self, data):
        '''Push some data on to the back of the list.'''
        if not self.root:  # Not even a root is present.
            self.__init__(data)
        else:
            self.end.next = Node(data)
            self.end = self.end.next

    def insert(self, data):
        '''Insert some data at the front of the list.'''
        if not self.root:
            self.__init__(data)
        else:
            new = Node(data)
            new.next  = self.root.next
            self.root = new

    def remove(self, other):
        '''Removes a Node that contains 'data', if it's there.'''
        curr = self.root
        prev = curr
        while curr:
            if curr.data == other:
                if prev == curr:  # Removing root.
                    self.root = self.root.next
                elif not curr.next:  # Removing end.
                    prev.next = None
                    self.end  = prev
                else:
                    prev.next = curr.next
                break
            prev = curr
            curr = curr.next

class Node():
    '''A node in a linked list.'''
    def __init__(self, data):
        self.data = data
        self.next = None

    def __str__(self):
        if self.next:
            end = ''
        else:
            end = 'None'
        return '{} ~> {}'.format(self.data, end)
