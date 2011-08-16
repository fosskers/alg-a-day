from email_parser import *
from syshelp      import get_args

def get_addresses(filename):
    '''Given a filename, gets and prints email addresses it finds.'''
    emails = parse_email(filename)
    for email in emails:
        print(email)

if __name__ == '__main__':
    filenames = get_args('AT_LEAST', 1)  # AaD Day 04!
    for filename in filenames:
        get_addresses(filename)
