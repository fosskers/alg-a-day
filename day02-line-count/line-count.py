# Counts the number of lines in a file.

import sys

def line_count(filename):
    '''Counts the number of lines from a given file.'''
    with open(filename) as lines:
        return sum(1 for line in lines)
            
if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('No file given.')
    else:
        print(line_count(sys.argv[1]))
