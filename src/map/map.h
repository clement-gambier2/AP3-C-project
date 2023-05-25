#ifndef AP3_C_PROJECT_MAP_H
#define AP3_C_PROJECT_MAP_H

#endif //AP3_C_PROJECT_MAP_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "../const/const.h"
#include "../character/character.h"

char** buildMapFromFile(char * map);
char** initMap();
void displayMap(char ** map);
void drawWall(SDL_Renderer * renderer, int x, int y, SDL_Texture * tilemap, SDL_Rect rect, char ** map);
void drawDoor(SDL_Renderer * renderer, int x, int y, SDL_Texture * tilemap, SDL_Rect rect, char ** map, int isOpen);
void drawFloor(SDL_Renderer * renderer, int x, int y, SDL_Texture * tilemap, SDL_Rect rect, char ** map);
void drawRoomExit(SDL_Renderer * renderer, int x, int y, SDL_Texture * tilemap, SDL_Rect rect);
void drawMap(SDL_Renderer * renderer, char ** map, Character * player, SDL_Texture * tilemap);