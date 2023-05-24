#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../const/const.h"
#include "../inventory/inventory.h"

#include "../inventory/inventory.h"

#include "../const/const.h"


void launchGame(SDL_Renderer* renderer);
int displayMenu(SDL_Renderer* renderer);
int credits(SDL_Renderer* renderer);

#endif // GAME_H