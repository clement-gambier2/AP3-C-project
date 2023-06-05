#include "const.h"

const SDL_Color WHITE_COLOR = { 255, 255, 255, 255};
const SDL_Color GREEN_COLOR = { 0, 255, 0, 255};

const SDL_RendererFlip RENDERER_FLIP = SDL_FLIP_HORIZONTAL;

// Floors
const SDL_Rect S_RECT_FLOOR_1 = { 0, 64, 16, 16 };
const SDL_Rect S_RECT_FLOOR_2 = {1*16, 4*16, 16, 16};
const SDL_Rect S_RECT_FLOOR_3 = {6*16, 3*16, 16, 16};

// Walls
const SDL_Rect S_RECT_WALL_1 = {64, 48, 16, 16};
const SDL_Rect S_RECT_WALL_2 = {64, 32, 16, 16};

// Doors
const SDL_Rect S_RECT_SINGLE_CLOSED_DOOR = {9*16, 3*16, 16, 16};
const SDL_Rect S_RECT_LEFT_CLOSED_DOOR = {10*16, 3*16, 16, 16};
const SDL_Rect S_RECT_RIGHT_CLOSED_DOOR = {11*16, 3*16, 16, 16};
const SDL_Rect S_RECT_SINGLE_PARTIALLY_OPEN_DOOR = {9*16, 2*16, 16, 16};
const SDL_Rect S_RECT_LEFT_PARTIALLY_OPEN_DOOR = {10*16, 2*16, 16, 16};
const SDL_Rect S_RECT_RIGHT_PARTIALLY_OPEN_DOOR = {11*16, 2*16, 16, 16};
const SDL_Rect S_RECT_SINGLE_OPEN_DOOR = {9*16, 1*16, 16, 16};
const SDL_Rect S_RECT_LEFT_OPEN_DOOR = {10*16, 1*16, 16, 16};
const SDL_Rect S_RECT_RIGHT_OPEN_DOOR = {11*16, 1*16, 16, 16};
const SDL_Rect S_RECT_SINGLE_ARCH = {9*16, 0*16, 16, 16};
const SDL_Rect S_RECT_LEFT_ARCH = {11*16, 0*16, 16, 16};
const SDL_Rect S_RECT_RIGHT_ARCH = {10*16, 0*16, 16, 16};


// Characters
const SDL_Rect S_RECT_CIV_1 = {16, 112, 16, 16};
const SDL_Rect S_RECT_CIV_2 = {32, 112, 16, 16};
const SDL_Rect S_RECT_CIV_3 = {64, 112, 16, 16};
const SDL_Rect S_RECT_CIV_4 = {64, 128, 16, 16};
const SDL_Rect S_RECT_CIV_5 = {64, 144, 16, 16};
const SDL_Rect S_RECT_PRINCESS = {48, 128, 16, 16};
const SDL_Rect S_RECT_WIZARD = {0, 112, 16, 16};
const SDL_Rect S_RECT_KNIGHT_1 = {0, 128, 16, 16};
const SDL_Rect S_RECT_KNIGHT_2 = {16, 128, 16, 16};
const SDL_Rect S_RECT_KNIGHT_3 = {32, 128, 16, 16};

// Enemy
const SDL_Rect S_RECT_VIKING = {48, 112, 16, 16};
const SDL_Rect S_RECT_SLIME = {0, 144, 16, 16};
const SDL_Rect S_RECT_CYCLOP = {16, 144, 16, 16};
const SDL_Rect S_RECT_LOBSTER = {32, 144, 16, 16};
const SDL_Rect S_RECT_BLACK_WIZARD = {48, 144, 16, 16};
const SDL_Rect S_RECT_BAT = {0, 160, 16, 16};
const SDL_Rect S_RECT_GHOST = {16, 160, 16, 16};
const SDL_Rect S_RECT_SPIDER = {32, 160, 16, 16};
const SDL_Rect S_RECT_BROWN_RAT = {48, 160, 16, 16};
const SDL_Rect S_RECT_GRAY_RAT = {64, 160, 16, 16};

// Potions + misc
const SDL_Rect S_RECT_GRAY_POTION = {5*16, 9*16, 16, 16};
const SDL_Rect S_RECT_GREEN_POTION = {6*16, 9*16, 16, 16};
const SDL_Rect S_RECT_RED_POTION = {7*16, 9*16, 16, 16};
const SDL_Rect S_RECT_BLUE_POTION = {8*16, 9*16, 16, 16};
const SDL_Rect S_RECT_KEY = {5*16, 8*16, 16, 16};
const SDL_Rect S_RECT_HEART = {0*16, 11*16, 16, 16};
const SDL_Rect S_RECT_SHIELD = {6*16, 8*16, 16, 16};