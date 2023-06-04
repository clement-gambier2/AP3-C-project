#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "const.h"

#include "character.h"
#include "inventory.h"
#include "combat.h"
#include "inventory.h"
#include "map.h"
#include "const.h"


int launchGame(SDL_Renderer* renderer);
int displayMenu(SDL_Renderer* renderer);
int credits(SDL_Renderer* renderer);

#endif // GAME_H