#ifndef AP3_C_PROJECT_MAP_H
#define AP3_C_PROJECT_MAP_H

#endif //AP3_C_PROJECT_MAP_H

#include <SDL2/SDL.h>

char** buildMapFromFile(char * map);
char** initMap();
void displayMap(char ** map);
void drawMap(SDL_Renderer * renderer, char ** map);