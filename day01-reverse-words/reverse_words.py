def reverse_words(line):
    '''Reverses the order of words in a string.'''
    words = line.split()
    words.reverse()
    return ' '.join(words)
