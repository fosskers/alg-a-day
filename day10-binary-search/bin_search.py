def binary_search(items, target):
    '''Quickly search for an item in a list.'''
    result = -1  # Assume failure.
    lower = 0
    upper = len(items) - 1
    while lower <= upper:
        mid = (lower + upper) // 2  # Calc new mid.
        if items[mid] < target:
            lower = mid + 1
        elif items[mid] > target:
            upper = mid - 1
        else:  # items[mid] == target
            result = mid
            break
    return result
