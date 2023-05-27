#ifndef MAP_H
#define MAP_H
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../character/character.h"

struct Map {
    char ** matrix;
    char * directions[4]; //E,S,O,N : array of directions
};


struct Map * buildMapFromFile(char * map);
struct Map * initMap(void);
void displayMap(char ** map);
void drawMap(SDL_Renderer * renderer, char ** map, int x, int y);
char* concatenateLevelName(char* a, char* b);

#endif //MAP_H
