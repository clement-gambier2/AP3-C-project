//
// Created by clement on 13/05/23.
//
#include "game.h"
#include "../map/map.h"


/**
 * launchGame is the function that launches the game
 * @param renderer
 */
int launchGame(SDL_Renderer* renderer) {
    struct Node * head = buildMapList();
    struct Map * map = findMapByName(head,"src/map/levels/niveau1.level");
    struct Character * c = createCharacter(10,8,4,2,0,0);
    SDL_Surface  * tilemapImage = SDL_LoadBMP("src/assets/img/bmp/tilemap_packed.bmp");
    SDL_Texture * tilemapTexture = SDL_CreateTextureFromSurface(renderer, tilemapImage);
    drawMap(renderer,map->matrix,c,tilemapTexture);
    SDL_RenderPresent(renderer);
    char * returnMove;
    int isGameOverResult;



    // Here we are waiting for events
    SDL_Event event;
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    return 0;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_UP:
                            isGameOverResult = isGameOver(c,map);
                            if(isGameOverResult == 1){
                                return 1;
                            }
                            else if(isGameOverResult == 2){
                                return 2;
                            }
                            returnMove = moveTop(c,map);
                            if(strcmp(returnMove,"noSwitch") != 0){
                                printf("changement de niveau vers : %s\n",returnMove);
                                map = findMapByName(head,concatenateLevelName("src/map/levels/",returnMove));
                                fflush(stdout); // Vide le tampon de la sortie standard
                            }
                            break;
                        case SDLK_LEFT:
                            returnMove = moveLeft(c,map);
                            if(strcmp(returnMove,"noSwitch") != 0){
                                printf("changement de niveau vers : %s\n",returnMove);
                                map = findMapByName(head,concatenateLevelName("src/map/levels/",returnMove));
                                fflush(stdout); // Vide le tampon de la sortie standard
                            }
                            break;
                        case SDLK_DOWN:
                            returnMove = moveBottom(c,map);
                            if(strcmp(returnMove,"noSwitch") != 0){
                                printf("changement de niveau vers : %s\n",returnMove);
                                map = findMapByName(head,concatenateLevelName("src/map/levels/",returnMove));
                                fflush(stdout); // Vide le tampon de la sortie standard
                            }
                            break;
                        case SDLK_RIGHT:
                            returnMove = moveRight(c,map);
                            if(strcmp(returnMove,"noSwitch") != 0){
                                printf("changement de niveau vers : %s\n",returnMove);
                                map = findMapByName(head,concatenateLevelName("src/map/levels/",returnMove));
                                fflush(stdout); // Vide le tampon de la sortie standard
                            }
                            break;
                    }
                    break;
            }

        }

        drawMap(renderer,map->matrix,c,tilemapTexture);
        // Present the renderer to the screen
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }
}

/**
 * isGameOver is the function that checks if the game is over
 * @param c
 * @param map
 * @return 1 if the player is dead, 2 if the player is on the finale cell, 0 otherwise
 */
int isGameOver(struct Character * c, struct Map * map){
    if(c->hp <= 0){
        return 1;
    }
    if(map->matrix[c->pos_y][c->pos_x] == 'w'){
        return 2;
    }

    return 0;
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

int finalScreen(SDL_Renderer* renderer, int gameStatus){
    TTF_Font* font = TTF_OpenFont("src/assets/fonts/pixelart.ttf", 40);
    char * finalText;
    if(gameStatus == 1){
        finalText = "GAME OVER";
    } else if(gameStatus == 2){
        finalText = "YOU WIN";
    }

    struct TextData texts[] = {
            {finalText,       NULL, NULL, {0, 0,   0, 0}},
            {"Nouvelle Partie", NULL, NULL, {0, 100, 0, 0}},
            {"Credit",          NULL, NULL, {0, 200, 0, 0}},
            {"Quitter",         NULL, NULL, {0, 300, 0, 0}}
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
}

/**
 * displayMenu is the function that displays the menu
 * @param renderer
 * @return int
 */
int displayMenu(SDL_Renderer* renderer) {
    TTF_Font* font = TTF_OpenFont("src/assets/fonts/pixelart.ttf", 40);
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
            {"le 7 juin 2023", NULL, NULL, {0, 600, 0, 0}},
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

}
