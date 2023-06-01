//
// Created by mrplume on 17/05/23.
//

#ifndef INVENTORY_H
#define INVENTORY_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "Objects.h"
#include "character.h"


void inventory(SDL_Renderer* renderer, Character * character);
void decrement_hp(Character* character);
void decrement_def(Character* character);
int get_hearts(Character *character);



#endif //INVENTORY_H
