#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// Size of the windows
#define SCREEN_WINDOW 900

// Text color
extern const SDL_Color GREEN_COLOR;
extern const SDL_Color WHITE_COLOR;

extern const SDL_RendererFlip RENDERER_FLIP;

// Default Floor
extern const SDL_Rect S_RECT_DEFAULT_FLOOR;

// Special Floors
extern const SDL_Rect S_RECT_DOUBLE_BORDED_FLOOR;

// Floors
extern const SDL_Rect S_RECT_FLOOR_1;
extern const SDL_Rect S_RECT_FLOOR_2;
extern const SDL_Rect S_RECT_FLOOR_3;

// Walls
extern const SDL_Rect S_RECT_WALL_1;
extern const SDL_Rect S_RECT_WALL_2;

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

// Potions + misc
extern const SDL_Rect S_RECT_GRAY_POTION;
extern const SDL_Rect S_RECT_GREEN_POTION;
extern const SDL_Rect S_RECT_RED_POTION;
extern const SDL_Rect S_RECT_BLUE_POTION;
extern const SDL_Rect S_RECT_KEY;

#endif
