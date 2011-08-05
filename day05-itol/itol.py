# This is also available in my python-libs repo.

def itol(num):
    '''Converts a given int to a list, with each digit 
    as a single element in the list.
    '''
    digits = []
    d_a = digits.append  # Minor performance tweak.
    if num == 0:
        d_a(0)
    while num > 0:
        d_a(num % 10)
        num //= 10
    digits.reverse()
    return digits
