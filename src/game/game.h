#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../const/const.h"
#include "../character/character.h"
#include "../inventory/inventory.h"
#include "../combat/combat.h"
#include "../objects/objects.h"
#include "../map/map.h"

struct TextData {
    const char* text;
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Rect rect;
};


int launchGame(SDL_Renderer* renderer);
int isGameOver(struct Character * c, struct Map * map);
int displayMenu(SDL_Renderer* renderer);
int credits(SDL_Renderer* renderer);
int finalScreen(SDL_Renderer* renderer, int gameStatus);

#endif // GAME_H
