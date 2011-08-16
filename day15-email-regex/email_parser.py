import re

def parse_email(filename):
    '''Given a file, parses all email addresses contained within it.'''
    emails  = []
    regex   = r"\b([a-zA-Z0-9-_.]+)@(\w+[.][a-zA-Z.]+)"
    pattern = re.compile(regex)
    with open(filename) as input_file:
        for line in input_file:
            matches = pattern.finditer(line)  # Gives an iterator of matches.
            for match in matches:
                group = match.groups()
                email = group[0] + "@" + group[1].strip("\n.")  # Repair.
                emails.append(email)
    return emails


    
