#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

// Size of the windows
#define SCREEN_WINDOW 900

// Text color
extern const SDL_Color GREEN_COLOR;
extern const SDL_Color WHITE_COLOR;
extern const SDL_Color YELLOW_COLOR;
extern const SDL_Color BLACK_COLOR;

extern const SDL_RendererFlip RENDERER_FLIP;

// Default Floor
extern const SDL_Rect S_RECT_DEFAULT_FLOOR;

// Special Floors
extern const SDL_Rect S_RECT_DOUBLE_BORDED_FLOOR;
extern const SDL_Rect S_RECT_DOUBLE_BORDED_CORNER_FLOOR;
extern const SDL_Rect S_RECT_SINGLE_SIDE_FLOOR;
extern const SDL_Rect S_RECT_SINGLE_SIDE_CORNER;
extern const SDL_Rect S_RECT_MINI_CORNER;
extern const SDL_Rect S_RECT_CUL_DE_SAC;

// Floors
extern const SDL_Rect S_RECT_FLOOR_1;
extern const SDL_Rect S_RECT_FLOOR_2;
extern const SDL_Rect S_RECT_FLOOR_3;

// Walls
extern const SDL_Rect S_RECT_WALL_1;
extern const SDL_Rect S_RECT_WALL_2;
extern const SDL_Rect S_RECT_DOUBLE_BORDED_WALL_1;
extern const SDL_Rect S_RECT_DOUBLE_BORDED_WALL_2;
extern const SDL_Rect S_RECT_DOUBLE_BORDERED_END_WALL_1;
extern const SDL_Rect S_RECT_DOUBLE_BORDERED_END_WALL_2;
extern const SDL_Rect S_RECT_DOUBLE_BORDERED_END_WALL_3;
extern const SDL_Rect S_RECT_DOUBLE_BORDERED_END_WALL_4;
extern const SDL_Rect S_RECT_SINGLE_WALL;


// Roofs
extern const SDL_Rect S_RECT_ROOF_1;
extern const SDL_Rect S_RECT_CRENEL_1;
extern const SDL_Rect S_RECT_CRENEL_2;
extern const SDL_Rect S_RECT_CRENEL_3;
extern const SDL_Rect S_RECT_CORNER_CRENEL_1;
extern const SDL_Rect S_RECT_CORNER_CRENEL_2;
extern const SDL_Rect S_RECT_CORNER_CRENEL_3;
extern const SDL_Rect S_RECT_CORNER_CRENEL_4;
extern const SDL_Rect S_RECT_CORNER_CRENEL_5;
extern const SDL_Rect S_RECT_CORNER_CRENEL_6;
extern const SDL_Rect S_RECT_CORNER_CRENEL_7;
extern const SDL_Rect S_RECT_CORNER_CRENEL_8;




// Doors
extern const SDL_Rect S_RECT_SINGLE_CLOSED_DOOR;
extern const SDL_Rect S_RECT_LEFT_CLOSED_DOOR;
extern const SDL_Rect S_RECT_RIGHT_CLOSED_DOOR;
extern const SDL_Rect S_RECT_SINGLE_PARTIALLY_OPEN_DOOR;
extern const SDL_Rect S_RECT_LEFT_PARTIALLY_OPEN_DOOR;
extern const SDL_Rect S_RECT_RIGHT_PARTIALLY_OPEN_DOOR;
extern const SDL_Rect S_RECT_SINGLE_OPEN_DOOR;
extern const SDL_Rect S_RECT_LEFT_OPEN_DOOR;
extern const SDL_Rect S_RECT_RIGHT_OPEN_DOOR;
extern const SDL_Rect S_RECT_SINGLE_ARCH;
extern const SDL_Rect S_RECT_LEFT_ARCH;
extern const SDL_Rect S_RECT_RIGHT_ARCH;

// Characters
extern const SDL_Rect S_RECT_CIV_1;
extern const SDL_Rect S_RECT_CIV_2;
extern const SDL_Rect S_RECT_CIV_3;
extern const SDL_Rect S_RECT_CIV_4;
extern const SDL_Rect S_RECT_CIV_5;
extern const SDL_Rect S_RECT_PRINCESS;
extern const SDL_Rect S_RECT_WIZARD;
extern const SDL_Rect S_RECT_KNIGHT_1;
extern const SDL_Rect S_RECT_KNIGHT_2;
extern const SDL_Rect S_RECT_KNIGHT_3;

// Enemies
extern const SDL_Rect S_RECT_VIKING;
extern const SDL_Rect S_RECT_SLIME;
extern const SDL_Rect S_RECT_CYCLOP;
extern const SDL_Rect S_RECT_LOBSTER;
extern const SDL_Rect S_RECT_BLACK_WIZARD;
extern const SDL_Rect S_RECT_BAT;
extern const SDL_Rect S_RECT_GHOST;
extern const SDL_Rect S_RECT_SPIDER;
extern const SDL_Rect S_RECT_BROWN_RAT;
extern const SDL_Rect S_RECT_GRAY_RAT;
extern const SDL_Rect S_RECT_GRAVE_1;

// Potions + misc
extern const SDL_Rect S_RECT_GRAY_POTION;
extern const SDL_Rect S_RECT_GREEN_POTION;
extern const SDL_Rect S_RECT_RED_POTION;
extern const SDL_Rect S_RECT_BLUE_POTION;
extern const SDL_Rect S_RECT_KEY;
extern const SDL_Rect S_RECT_HEART;
extern const SDL_Rect S_RECT_HEART_BLACK;
extern const SDL_Rect S_RECT_HEART_GOLD;
extern const SDL_Rect S_RECT_SHIELD;
extern const SDL_Rect S_RECT_SWORD_1;

// Final room items
extern const SDL_Rect S_RECT_CHEST;
extern const SDL_Rect S_RECT_CHEST_CONNECTED;

#endif
