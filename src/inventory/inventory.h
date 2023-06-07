//
// Created by mrplume on 17/05/23.
//

#ifndef INVENTORY_H
#define INVENTORY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../const/const.h"
#include "../character/character.h"


void render_text(SDL_Renderer* renderer, const char *text, int value, SDL_Rect dstrect, TTF_Font * font);
void inventory(SDL_Renderer* renderer, SDL_Texture * tilemap, struct Character * character, TTF_Font * font);


#endif //INVENTORY_H
