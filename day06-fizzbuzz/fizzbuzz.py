# FizzBuzz, Python style.

def fizzbuzz():
    '''Prints Fizz on multiples of 3, Buzz on multiples of 5, and FizzBuzz
    on multiples of both.
    '''
    for x in range(1, 101):
        line = ''
        if x % 3 == 0:
            line = ''.join('Fizz')
        if x % 5 == 0:
            line = ''.join((line, 'Buzz'))
        if line:
            print(line)
        else:
            print(x)

if __name__ == '__main__':
    fizzbuzz()
