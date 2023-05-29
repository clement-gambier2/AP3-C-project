#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "game/game.h"
#include "combat/combat.h"
#include "map/map.h"
#include "const/const.h"

int main() {
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Failed to initialize SDL2: %s\n", SDL_GetError());
        return 1;
    }
    // Initialisation de SDL_ttf
    if (TTF_Init() != 0) {
        printf("Erreur lors de l'initialisation de SDL_ttf : %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }

    //We start by creating a window
    SDL_Window* window = SDL_CreateWindow("AP3-C-Project",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WINDOW, SCREEN_WINDOW,
                                          SDL_WINDOW_SHOWN);

    //Then we need to render
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    int choice = displayMenu(renderer); // Call displayMenu with loaded font

    while(choice == 2){
        choice = credits(renderer);
        if (choice != 3){
            choice = displayMenu(renderer);
        }
    }

    if(choice == 1) {
      int quitGame = launchGame(renderer);
        if (quitGame == 0){
            printf("You quit the game\n");
            choice = 3;
        }
    }
    else if(choice == 3){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
    }

    // Cleanup SDL2
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
