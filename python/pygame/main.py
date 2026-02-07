import pygame as PG
from pygame.locals import *
import Utility as ut

# --- SET UP --- #
resolution = (800, 600)
clock = PG.time.clock()
screen = PG.display.set_mode(resolution)

# --- GAME LOOP --- #
PG.init()
programEnd = False

while not programEnd:

    # -- Event Handler -- #
    for event in PG.event.get():
        # - Default quit event - #
        if event.type == PG.QUIT():
            programEnd = True

    PG.display.flip()

PG.quit()
