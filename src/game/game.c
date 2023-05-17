//
// Created by clement on 13/05/23.
//
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "game.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

/**
 * launchGame is the function that launches the game
 * @param renderer
 */
void launchGame(SDL_Renderer* renderer){
    // Create a black background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw a red square in the center of the screen
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect rect = { (640 - 30) / 2, (480 - 30) / 2, 30, 30 };
    SDL_RenderFillRect(renderer, &rect);

    // We print the render to the window
    SDL_RenderPresent(renderer);

    // Here we are waiting for events
    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_q:
                            running = 0;
                            break;
                        case SDLK_UP:
                            rect.y -= 10;
                            break;
                        case SDLK_DOWN:
                            rect.y += 10;
                            break;
                        case SDLK_LEFT:
                            rect.x -= 10;
                            break;
                        case SDLK_RIGHT:
                            rect.x += 10;
                            break;
                    }
                    break;
            }
        }


        // We create a grid
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        // Draw vertical lines
        for (int x = 0; x <= 640; x += 30) {
            SDL_RenderDrawLine(renderer, x, 0, x, 480);
        }
        // Draw horizontal lines
        for (int y = 0; y <= 480; y += 30) {
            SDL_RenderDrawLine(renderer, 0, y, 640, y);
        }

        // Draw a red square
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);

        // Present the renderer to the screen
        SDL_RenderPresent(renderer);

        SDL_Delay(10);
    }

}


SDL_Surface* createText(const char* text, TTF_Font* font, SDL_Color color) {
    return TTF_RenderText_Solid(font, text, color);
}


/**
 * displayMenu is the function that displays the menu
 * @param renderer
 */

int displayMenu(SDL_Renderer* renderer) {
    SDL_Color whiteColor = { 255, 255, 255, 255 };
    SDL_Color greenColor = { 0, 255, 0, 255 };
    TTF_Font* font = TTF_OpenFont("src/assets/fonts/antique.ttf", 25);

    struct TextData {
        const char* text;
        SDL_Surface* surface;
        SDL_Texture* texture;
        SDL_Rect rect;
    };

    struct TextData texts[] = {
            {"Labyrinthe", NULL, NULL, {0, 0, 0, 0}},
            {"Nouvelle Partie", NULL, NULL, {0, 100, 0, 0}},
            {"Credit", NULL, NULL, {0, 200, 0, 0}},
            {"Quitter", NULL, NULL, {0, 300, 0, 0}}
    };

    int numTexts = sizeof(texts) / sizeof(texts[0]);

    int isSelected = 1;

    for (int i = 0; i < numTexts; i++) {
        texts[i].surface = createText(texts[i].text, font, whiteColor);
        texts[i].texture = SDL_CreateTextureFromSurface(renderer, texts[i].surface);

        texts[i].rect.w = texts[i].surface->w;
        texts[i].rect.h = texts[i].surface->h;
    }

    int textHeight = texts[0].rect.h;
    int totalTextHeight = numTexts * textHeight;
    int startY = (SCREEN_HEIGHT - totalTextHeight) / 2;

    for (int i = 0; i < numTexts; i++) {
        texts[i].rect.x = (SCREEN_WIDTH - texts[i].rect.w) / 2;
        texts[i].rect.y = startY + i * textHeight;
    }

    SDL_Event event;

    while (1) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return 3;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        if (isSelected == 1){
                            isSelected = 3;
                        }
                        else{
                            isSelected = (isSelected - 1 + numTexts) % numTexts;
                        }
                        break;
                    case SDLK_DOWN:
                        if (isSelected == 3){
                            isSelected = 1;
                        }
                        else{
                            isSelected = (isSelected + 1) % numTexts;
                        }
                        break;
                    case SDLK_RETURN:
                        return isSelected;
                    default:
                        break;
                }
            }
        }

        SDL_RenderClear(renderer);

        for (int i = 0; i < numTexts; i++) {
            if (i == isSelected) {
                SDL_FreeSurface(texts[i].surface);
                texts[i].surface = createText(texts[i].text, font, greenColor);
                SDL_DestroyTexture(texts[i].texture);
                texts[i].texture = SDL_CreateTextureFromSurface(renderer, texts[i].surface);
            } else {
                SDL_FreeSurface(texts[i].surface);
                texts[i].surface = createText(texts[i].text, font, whiteColor);
                SDL_DestroyTexture(texts[i].texture);
                texts[i].texture = SDL_CreateTextureFromSurface(renderer, texts[i].surface);
            }

            SDL_RenderCopy(renderer, texts[i].texture, NULL, &(texts[i].rect));
        }

        SDL_RenderPresent(renderer);
    }

    for (int i = 0; i < numTexts; i++) {
        SDL_DestroyTexture(texts[i].texture);
        SDL_FreeSurface(texts[i].surface);
    }

    TTF_CloseFont(font);
    return isSelected;
}


int credits(SDL_Renderer* renderer) {
    SDL_Color whiteColor = { 255, 255, 255, 255 };
    SDL_Color greenColor = { 0, 255, 0, 255 };
    TTF_Font* font = TTF_OpenFont("src/assets/fonts/roboto.ttf", 25);

    struct TextData {
        const char* text;
        SDL_Surface* surface;
        SDL_Texture* texture;
        SDL_Rect rect;
    };

    struct TextData texts[] = {
            {"Membres du groupe : ", NULL, NULL, {0, 0, 0, 0}},
            {"Fumiere Tristan", NULL, NULL, {0, 100, 0, 0}},
            {"Gambier Clement", NULL, NULL, {0, 200, 0, 0}},
            {"Gine Alexandre", NULL, NULL, {0, 300, 0, 0}},
            {"Gressier Gabriel", NULL, NULL, {SCREEN_WIDTH/2, 400, 0, 0}},
            {"Date de derniere modification : ", NULL, NULL, {0, 500, 0, 0}},
            {"le 17 mai 2023", NULL, NULL, {0, 600, 0, 0}},
            {"Retour", NULL, NULL, {0, 700, 0, 0}}
    };

    int numTexts = sizeof(texts) / sizeof(texts[0]);

    int isSelected = 7;

    for (int i = 0; i < numTexts; i++) {
        texts[i].surface = createText(texts[i].text, font, whiteColor);
        texts[i].texture = SDL_CreateTextureFromSurface(renderer, texts[i].surface);

        texts[i].rect.w = texts[i].surface->w;
        texts[i].rect.h = texts[i].surface->h;
    }

    int textHeight = texts[0].rect.h;
    int totalTextHeight = numTexts * textHeight;
    int startY = (SCREEN_HEIGHT - totalTextHeight) / 2;

    for (int i = 0; i < numTexts; i++) {
        texts[i].rect.x = (SCREEN_WIDTH - texts[i].rect.w) / 2;
        texts[i].rect.y = startY + i * textHeight;
    }

    SDL_Event event;

    while (1) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return 3;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_RETURN:
                        return 0;
                    default:
                        break;
                }
            }
        }

        SDL_RenderClear(renderer);

        for (int i = 0; i < numTexts; i++) {
            if (i == isSelected) {
                SDL_FreeSurface(texts[i].surface);
                texts[i].surface = createText(texts[i].text, font, greenColor);
                SDL_DestroyTexture(texts[i].texture);
                texts[i].texture = SDL_CreateTextureFromSurface(renderer, texts[i].surface);
            } else {
                SDL_FreeSurface(texts[i].surface);
                texts[i].surface = createText(texts[i].text, font, whiteColor);
                SDL_DestroyTexture(texts[i].texture);
                texts[i].texture = SDL_CreateTextureFromSurface(renderer, texts[i].surface);
            }

            SDL_RenderCopy(renderer, texts[i].texture, NULL, &(texts[i].rect));
        }

        SDL_RenderPresent(renderer);
    }

    for (int i = 0; i < numTexts; i++) {
        SDL_DestroyTexture(texts[i].texture);
        SDL_FreeSurface(texts[i].surface);
    }

    TTF_CloseFont(font);
    return isSelected;
}