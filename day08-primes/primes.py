# Prime number solver, and a nice iterator!

from funchelp import head  # Available in my python-libs repo.

class primes():
    '''An iterator that produces all the prime numbers.'''
    def __iter__(self):
        yield 2
        prime = 3
        while True:
            yield prime
            prime = _next_prime(prime)

def is_prime(num):
    '''Tests if a given number is prime. Written procedurally.'''
    if num == 2:
        return True
    elif num % 2 == 0 or num < 2:
        return False
    count = 3
    root = _sqrt(num)
    while count <= root:
        if num % count == 0:  # If anything divides evenly, it isn't prime.
            return False
        count += 2
    return True

def next_prime(num):
    '''Given any number, determines the first prime number greater than it.'''
    if num < 2:
        return 2
    elif num == 2:
        return 3
    elif num % 2 == 0:  # Even number. Perform magic.
        num -= 1
    return _next_prime(num)

def _next_prime(odd):
    '''Optimized version. Assumes its arg is odd and positive.'''
    return head(filter(is_prime, count(odd + 2, 2)))
