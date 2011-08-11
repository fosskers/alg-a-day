# Circular Binary Search

def circ_bs(items, target):
    '''Finds a value in a given list using a circular binary search.
    Returns -1 if the value was not found.
    '''
    size = len(items)
    lower = 0
    upper = size - 1
    result = -1  # Assume failure.
    while lower <= upper:
        mid = (upper + lower) // 2
        if items[mid] == target:
            result = mid
            break
        elif items[lower] <= target < items[mid]:
            upper = mid - 1
        elif items[mid] < target <= items[upper]: 
            lower = mid + 1 
        else:  # Standard binary search logic has failed.
            if items[lower] > items[mid]:  # Link is on the left.
                upper = mid - 1
            else:  # Link is on the right.
                lower = mid + 1
    return result
