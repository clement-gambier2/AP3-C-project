#ifndef AP3_C_PROJECT_MAP_H
#define AP3_C_PROJECT_MAP_H

#endif //AP3_C_PROJECT_MAP_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "../const/const.h"
#include "../character/character.h"
#include "../inventory/inventory.h"
typedef struct Map_ {
    char ** matrix;
    char * directions[4]; //E,S,O,N : array of directions
    int A_Pv;
    int A_Force;
    int A_Armure;
    int B_Pv;
    int B_Force;
    int B_Armure;
    int C_Pv;
    int C_Force;
    int C_Armure;

} Map;

Map* buildMapFromFile(char * map);
char** initMap();
void displayMap(char ** map);
void drawWall(SDL_Renderer * renderer, int x, int y, SDL_Texture * tilemap, SDL_Rect rect, char ** map);
void drawDoor(SDL_Renderer * renderer, int x, int y, SDL_Texture * tilemap, SDL_Rect rect, char ** map, int isOpen);
void drawFloor(SDL_Renderer * renderer, int x, int y, SDL_Texture * tilemap, SDL_Rect rect, char ** map);
void drawRoomExit(SDL_Renderer * renderer, int x, int y, SDL_Texture * tilemap, SDL_Rect rect);
void drawMap(SDL_Renderer * renderer, char ** map, Character * player, SDL_Texture * tilemap);