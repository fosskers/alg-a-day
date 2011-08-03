from syshelp import get_args  # This is in my python-libs repo.

def cat(filename):
    '''Print the contents of a given file.'''
    with open(filename) as lines:
        for line in lines:
            print(line)

if __name__ == '__main__':
    args = get_args('EXACTLY', 1)
    if args:
        cat(args[0])
