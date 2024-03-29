#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_ttf.h"
#include "game/game.h"
#include "combat/combat.h"
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
    int game;
    int characterChoosen;
    int shouldExit = 0;
    do {

        if (choice == 2) {
            printf("hello");
            choice = credits(renderer);
            if (choice != 3) {
                choice = displayMenu(renderer);
            }
        } else if (choice == 1) {
            characterChoosen = chooseCharacter(renderer);
            game = launchGame(renderer, characterChoosen);
            if (game == 0) {
                shouldExit = 1;
            } else if (game == 1) {
                choice = finalScreen(renderer, 1);
            } else if (game == 2) {
                choice = finalScreen(renderer, 2);
            }
        }
        if (choice != 1 && choice != 3) {
            choice = displayMenu(renderer);
        }
    } while (!shouldExit && (choice == 1 || choice == 2));

    if(choice == 3){
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
