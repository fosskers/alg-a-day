def qsort(items, lower=0, upper=None):
    '''Quick-sorts a list.'''
    if upper == None:  # 'if not upper' doesn't work. Trust me.
        upper = len(items) - 1
    if upper - lower + 1 > 1:  # Size calculation.
        pivot_pos = qsort_partition(items, lower, upper)
        qsort(items, lower, pivot_pos - 1)
        qsort(items, pivot_pos + 1, upper)
    return items
    
def qsort_partition(items, lower, upper):
    '''Divides the list by the pivot.'''
    pivot_pos  = get_pivot_pos(items, lower, upper)
    swap_index = lower
    # Move pivot to the end.
    items[upper], items[pivot_pos] = items[pivot_pos], items[upper]
    # Partitioning action.
    for x in range(lower, upper):
        if items[x] < items[upper]:
            items[x], items[swap_index] = items[swap_index], items[x]
            swap_index += 1
    # Move pivot back to its proper spot.
    items[upper], items[swap_index] = items[swap_index], items[upper]
    return swap_index

def get_pivot_pos(items, lower, upper):  
    '''Chooses the average of three major points in the list
    as the pivot. This is different from the C version.
    '''  
    points = [lower, upper, (lower + upper) // 2]
    values = [items[points[0]], items[points[1]], items[points[2]]]
    pairs  = dict(zip(values, points))
    sorted_vals = sorted(pairs)  # Gets a list of sorted values.
    if len(sorted_vals) > 1:  # Sometimes the values can overlap in the dict.
        pivot = sorted_vals[1]
    else:
        pivot = sorted_vals[0]
    return pairs[pivot]  # The index in 'items' of the pivot.
