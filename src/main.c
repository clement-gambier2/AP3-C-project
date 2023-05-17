#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "game/game.h"
#include "combat/combat.h"
#include "map/map.h"

int main() {
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Failed to initialize SDL2: %s\n", SDL_GetError());
        return 1;
    }

    //We start by creating a window
    SDL_Window* window = SDL_CreateWindow("AP3-C-Project",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          640, 480,
                                          SDL_WINDOW_SHOWN);

    //Then we need to render
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    //TTF_Font* font = TTF_OpenFont("../assets/fonts/antique.ttf", 24); // Load font from file
    //displayMenu(renderer, font); // Call displayMenu with loaded font
    //TTF_CloseFont(font); // Free font when you're done using it

    

    char ** map = initMap();
    drawMap(renderer, map);
    // displayMap(map);


    // Cleanup SDL2
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
