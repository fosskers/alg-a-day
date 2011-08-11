from circ_bs import circ_bs
from time    import time

def print_list(items, name):
    '''Print a given list in an easy-to-read fashion.'''
    print(name)
    print(items[0:10])
    print('... stuff in between ...')
    print(items[-10:])

def manage_search(items):
    '''Runs and times circulary bin search on a given list.'''
    start = time()
    print("Beginning search for all values in the list...")
    for each in items:
        pos = circ_bs(items, each)
        if pos == -1:
            print("{} NOT FOUND!".format(each))
            break
    end = time()
    print("Done!")
    print("Found all {} values in {} secs.".format(len(items), end - start))
    print()

if __name__ == '__main__':
    # Set up and search the normal list.
    items = list(range(1000))
    print_list(items, "Normal list:")
    manage_search(items)

    # Split the list and re-search.
    items = items[-200:] + items[0:800]
    print_list(items, "Circular list:")
    manage_search(items)

    print('Searching for 1 in [1]...')
    print(circ_bs([1], 1))

    print('Search for 1 in []...')
    print(circ_bs([], 1))

    print('Test for values that aren\'t in the list...')
    nots = [x for x in range(-1, -10, -1)]
    for each in nots:
        print('{} -> {}'.format(each, circ_bs(items, each)))
