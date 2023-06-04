//
// Created by clement on 13/05/23.
//
#include "../../include/game.h"


/**
 * launchGame is the function that launches the game
 * @param renderer
 */
int launchGame(SDL_Renderer* renderer) {

    struct Map* map = buildMapFromFile("./src/map/niveau1Prof.level");
    Enemy * enemy=saveEnemyFromMap(map);
    SDL_Surface  * tilemapImage = SDL_LoadBMP("src/assets/img/bmp/tilemap_packed.bmp");
    SDL_Texture * tilemapTexture = SDL_CreateTextureFromSurface(renderer, tilemapImage);

    struct Character * c = createCharacter(10, 10, 10, 10, 10, 10);
    // Here we are waiting for events
    SDL_Event event;
    while (1) {
        drawMap(renderer, map->matrix, c, tilemapTexture);
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    return 0;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_UP:
                            moveTop(c,map->matrix,enemy);
                            break;
                        case SDLK_LEFT:
                            moveLeft(c,map->matrix,enemy);
                            break;
                        case SDLK_DOWN:
                            moveBottom(c,map->matrix,enemy);
                            break;
                        case SDLK_RIGHT:
                            moveRight(c,map->matrix,enemy);
                            break;
                    }
                    break;
            }
        }
        SDL_Delay(10);
    }
    // Delete all texture and images
    SDL_DestroyTexture(tilemapTexture);
    SDL_FreeSurface(tilemapImage);
    return 1;
}


/**
 * createText is the function that creates the text
 * @param text
 * @param font
 * @param color
 * @return SDL_Surface*
 */
SDL_Surface* createText(const char* text, TTF_Font* font, SDL_Color color) {
    return TTF_RenderText_Solid(font, text, color);
}



/**
 * displayMenu is the function that displays the menu
 * @param renderer
 * @return int
 */
int displayMenu(SDL_Renderer* renderer) {
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
        texts[i].surface = createText(texts[i].text, font, WHITE_COLOR);
        texts[i].texture = SDL_CreateTextureFromSurface(renderer, texts[i].surface);

        texts[i].rect.w = texts[i].surface->w;
        texts[i].rect.h = texts[i].surface->h;
    }

    int textHeight = texts[0].rect.h;
    int totalTextHeight = numTexts * textHeight;
    int startY = (SCREEN_WINDOW - totalTextHeight) / 2;

    for (int i = 0; i < numTexts; i++) {
        texts[i].rect.x = (SCREEN_WINDOW - texts[i].rect.w) / 2;
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
                texts[i].surface = createText(texts[i].text, font, GREEN_COLOR);
                SDL_DestroyTexture(texts[i].texture);
                texts[i].texture = SDL_CreateTextureFromSurface(renderer, texts[i].surface);
            } else {
                SDL_FreeSurface(texts[i].surface);
                texts[i].surface = createText(texts[i].text, font, WHITE_COLOR);
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
            {"Gressier Gabriel", NULL, NULL, {SCREEN_WINDOW/2, 400, 0, 0}},
            {"Date de derniere modification : ", NULL, NULL, {0, 500, 0, 0}},
            {"le 17 mai 2023", NULL, NULL, {0, 600, 0, 0}},
            {"Retour", NULL, NULL, {0, 700, 0, 0}}
    };

    int numTexts = sizeof(texts) / sizeof(texts[0]);

    int isSelected = 7;

    for (int i = 0; i < numTexts; i++) {
        texts[i].surface = createText(texts[i].text, font, WHITE_COLOR);
        texts[i].texture = SDL_CreateTextureFromSurface(renderer, texts[i].surface);
        texts[i].rect.w = texts[i].surface->w;
        texts[i].rect.h = texts[i].surface->h;
    }

    int textHeight = texts[0].rect.h;
    int totalTextHeight = numTexts * textHeight;
    int startY = (SCREEN_WINDOW - totalTextHeight) / 2;

    for (int i = 0; i < numTexts; i++) {
        texts[i].rect.x = (SCREEN_WINDOW - texts[i].rect.w) / 2;
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
                texts[i].surface = createText(texts[i].text, font, GREEN_COLOR);
                SDL_DestroyTexture(texts[i].texture);
                texts[i].texture = SDL_CreateTextureFromSurface(renderer, texts[i].surface);
            } else {
                SDL_FreeSurface(texts[i].surface);
                texts[i].surface = createText(texts[i].text, font, WHITE_COLOR);
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
