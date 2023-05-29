#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../const/const.h"

#include "../character/character.h"
#include "../inventory/inventory.h"
#include "../combat/combat.h"
#include "../inventory/inventory.h"

#include "../const/const.h"


int launchGame(SDL_Renderer* renderer);
int displayMenu(SDL_Renderer* renderer);
int credits(SDL_Renderer* renderer);

#endif // GAME_H