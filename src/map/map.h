#ifndef MAP_H
#define MAP_H
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../const/const.h"
#include "../character/character.h"

struct Map {
    char * name;
    char ** matrix;
    char * directions[4]; //E,S,O,N : array of directions
};

struct Node {
    struct Map * data;
    struct Node *next;
};


struct Map * buildMapFromFile(char * map);
struct Map * initMap(void);
void displayMap(char ** map);
char* concatenateLevelName(char* a, char* b);
void drawWall(SDL_Renderer * renderer, int x, int y, SDL_Texture * tilemap, SDL_Rect rect, char ** map);
void drawDoor(SDL_Renderer * renderer, int x, int y, SDL_Texture * tilemap, SDL_Rect rect, char ** map, int isOpen);
void drawFloor(SDL_Renderer * renderer, int x, int y, SDL_Texture * tilemap, SDL_Rect rect, char ** map);
void drawRoomExit(SDL_Renderer * renderer, int x, int y, SDL_Texture * tilemap, SDL_Rect rect);
void drawMap(SDL_Renderer * renderer, char ** map, struct Character * c, SDL_Texture * tilemap);

void append(struct Node** head, struct Map  * map);
struct Map *findMapByName(struct Node* head, const char *name);

struct Node * buildMapList(void);

#endif //MAP_H
