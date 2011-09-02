# Conway's Game of Life in Python 2.x
# Uses a set instead of a list or array to cut down on 
# unneccessary checks.

# TODO: Allow mouse-clicks to add cells!

from random  import randrange as _randrange
from syshelp import get_args  # In my python-libs repo.
import pygame

class Ecosystem():
    '''A biological ecosystem of single-celled organisms.'''
    def __init__(self, dim, eco_type=None):
        self.gen = 1
        if eco_type == 'f':
            self.live_cells = self.full_ecosystem(dim)
        elif eco_type == 'e':
            self.live_cells = self.empty_ecosystem(dim)
        else:
            self.live_cells = self.random_ecosystem(dim)

    def __len__(self):
        return len(self.live_cells)

    def __contains__(self, item):
        return item in self.live_cells
        
    def forge_ecosystem(self, dim, func):
        '''Creates an ecosystem via a given function.'''
        cells = set()  # Only live cells appear in this set.
        for x in xrange(0, dim):
            for y in xrange(0, dim):
                if func():
                    cells.add((x, y))
        return cells

    def random_ecosystem(self, dim):
        '''Creates a random configuration of the cells.'''
        func = lambda: True if _randrange(1, 12) == 1 else False
        return self.forge_ecosystem(dim, func)

    def full_ecosystem(self, dim):
        '''Creates a fully populated ecosystem of cells.'''
        func = lambda: True
        return self.forge_ecosystem(dim, func)

    def empty_ecosystem(self, dim):
        '''Creates an ecosystem full of dead cells.'''
        func = lambda: False
        return self.forge_ecosystem(dim, func)

    def next_generation(self):
        '''Scans the current ecosystem and creates the next generation.'''
        future = set()
        deads = {}  # Tracks dead cells next to live ones.
        for cell in self.live_cells:
            neighs = 0  # Number of live neighbours.
            # Note that cells will compare with themselves this way.
            for x in xrange(cell[0] - 1, cell[0] + 2):
                for y in xrange(cell[1] - 1, cell[1] + 2):
                    neighbour = (x, y)
                    if neighbour in self.live_cells:
                        neighs += 1
                    else:
                        if neighbour in deads:
                            deads[neighbour] += 1
                        else:
                            deads[neighbour] = 1
            if 2 < neighs < 5:  # This includes the current cell.
                future.add(cell)  # Still alive! No cake though.
        # Check all the dead cells that had live partners.
        for pos in deads:
            if deads[pos] == 3:
                future.add(pos)  # Birth!
        self.live_cells = future  # The future becomes the present.
        self.gen += 1  # Advance the generation number.

    def add_cell(self, cell):
        '''Adds a cell to the Ecosystem.'''
        self.live_cells.add(cell)

    def remove_cell(self, cell):
        '''Removes a cell from the Ecosystem.'''
        self.live_cells.remove(cell)

    def show_ecosystem(self, screen):
        '''Scan the cells and display the live ones.'''
        for cell in self.live_cells:
            pygame.draw.rect(screen, WHITE, (cell[0] * MAG, cell[1] * MAG,
                                             MAG, MAG))

def cell_from_coord(coords):
    '''Given a coordinate pair from a grid, determines
    which cell contains those coordinates.
    '''
    return (coords[0] / MAG, coords[1] / MAG)

# Fire up pygame.
pygame.init()
# Set the title. 
pygame.display.set_caption("Conway's Game of Life") 

## GLOBALS / CONSTANTS
# Create the screen and set its dimensions.
DIM = 600
MAG = 3  # Increase this to raise the magnification on the ecosystem.
SIZE = [DIM, DIM + 50]
screen = pygame.display.set_mode(SIZE)
# Used to manage how fast the screen updates. 
clock = pygame.time.Clock()
# Set onts, colours, and text positions.
FSIZE = 35
font = pygame.font.Font(None, FSIZE)
XPOS = 10
YPOS = DIM + 20
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

# Create the Ecosystem.
args = get_args('AT_LEAST', 0)
if args:
    eco_type = args[0]
    present = Ecosystem(DIM / MAG, args[0])
else:
    present = Ecosystem(DIM / MAG)

# The work.
done = False
run = True  # Used for pausing.
while not done:
    for event in pygame.event.get(): 
        if event.type == pygame.QUIT:
            done = True 
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_q:
                print 'Quitting...'
                done = True
            elif event.key == pygame.K_p:
                if run:
                    print 'Paused!'
                    run = False
                else:
                    print 'Unpaused!'
                    run = True
        elif event.type == pygame.MOUSEBUTTONDOWN and not run:
            pos = pygame.mouse.get_pos()
            pos = cell_from_coord(pos)
            present.add_cell(pos)            
    # Set the screen background
    screen.fill(BLACK)
    # Print cells.
    present.show_ecosystem(screen)
    if run:
        # Print generation number and amount of live cells.
        text = font.render("Gen {0:4} Cells {1:4}".format(present.gen, 
                                                          len(present)),
                           True, WHITE)
        # Create the next generation.
        present.next_generation()
    # Show currently rendered text.
    screen.blit(text, (XPOS, YPOS))
    # Limit to 20 frames per second
    clock.tick(20)
    # Update the screen.
    pygame.display.flip()
# We're done.    
pygame.quit()
print 'Bye!'
