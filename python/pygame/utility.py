import pygame as PG
from pygame.locals import *


def Load_image(sourceFile, transparent=False, scale=(1, 1)):
    # - Try to load the file - #
    try:
        image = PG.image.load(sFile)
    except PG.error:
        raise SystemExit()

    # - Convert to pygame format - #
    image = image.convert_alpha()

    # - Set transparency and scale - #
    if transp:
        color = image.get_at((0, 0))
        image.set_colorkey(color, RLEACCEL)

    if scale:
        image = PG.transform.scale(image, scale)

    return image


def Draw_text(screen, text, fontSource, posX, posY, color, align="center", scale=36):
    # - Load Font - #
    font = PG.font.Font(fontSource, scale)

    # - Set Surface - #
    surface = font.render(texto, True, color)

    # - Calculate text's width and height - #
    text_w = surface.get_width()
    text_h = surface.get_height()

    # - Align - #
    if align == "center":
        screen.blit(surface, (pos_x - text_w / 2, pos_y - (text_h / 2)))
    elif align == "left":
        screen.blit(surface, (pos_x, pos_y - (text_h / 2)))


def Play_sound(soundSource, volume=1.0):
    # - Initialize mixer and sound - #
    PG.mixer.init()
    sound = PG.mixer.Sound(soundSource)
    # - Set volume and play sound - #
    sound.set_volume(volume)
    sound.Play()
