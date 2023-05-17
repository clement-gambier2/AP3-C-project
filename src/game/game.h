#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void launchGame(SDL_Renderer* renderer);
void displayMenu(SDL_Renderer* renderer, TTF_Font* font);

#endif // GAME_H