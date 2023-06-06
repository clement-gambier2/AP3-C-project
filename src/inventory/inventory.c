//
// Created by mrplume on 17/05/23.
//


#include "inventory.h"
#include "../const/const.h"



void render_text(SDL_Renderer* renderer, const char *text, int value, SDL_Rect dstrect) {
    if (TTF_Init() == -1) {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    TTF_Font *font = TTF_OpenFont("src/assets/fonts/roboto.ttf", 24);
    if (!font) {
        fprintf(stderr, "Erreur à l'ouverture de la police : %s\n", TTF_GetError());
    }

    char text_buffer[32];
    sprintf(text_buffer, "%s: %d", text, value);

    SDL_Surface *text_surface = TTF_RenderText_Solid(font, text_buffer, WHITE_COLOR);
    if (!text_surface) {
        fprintf(stderr, "Erreur à la création du texte : %s\n", TTF_GetError());
    }

    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    if (!text_texture) {
        fprintf(stderr, "Erreur à la création de la texture : %s\n", SDL_GetError());
    }

    SDL_Rect text_rect;
    text_rect.x = dstrect.x + dstrect.w + 5; // position the text just after the key image
    text_rect.y = dstrect.y; // align the text vertically with the key image
    text_rect.w = text_surface->w;
    text_rect.h = text_surface->h;

    SDL_FreeSurface(text_surface);
    TTF_CloseFont(font);

    // render the text texture
    SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);
    SDL_DestroyTexture(text_texture);

    TTF_Quit();
}

/**
 * Used to display the character's HP in the HUD
 * @param renderer
 * @param tilemap
 * @param num_hearts
 */
void render_hearts(SDL_Renderer* renderer, SDL_Texture * tilemap, int num_hearts) {
    for (int i = 0; i < num_hearts; i++) {
        SDL_Rect heart_rect = {(i*40)+5, 0, 40, 40};
        SDL_RenderCopy(renderer, tilemap, &S_RECT_HEART, &heart_rect);
    }
}

/**
 * Used to display the character's Defense in the HUD
 * @param renderer
 * @param tilemap
 * @param num_def
 */
void render_def(SDL_Renderer* renderer, SDL_Texture * tilemap, int num_def) {
    for (int i = 0; i < num_def; i++) {
        SDL_Rect def_rect = {(i*40)+5, 40, 40, 40};
        SDL_RenderCopy(renderer, tilemap, &S_RECT_SHIELD, &def_rect);
    }
}

/**
 * Used to display the entire HUD
 * @param renderer
 * @param tilemap
 * @param character
 */
void inventory(SDL_Renderer* renderer, SDL_Texture * tilemap, struct Character * character) {

    int num_hearts = get_hearts(character);
    render_hearts(renderer, tilemap, num_hearts);

    int num_def = get_def(character);
    render_def(renderer, tilemap, num_def);

    SDL_Rect key_dstrect = {0, SCREEN_WINDOW - 100, 60, 60};
    SDL_Rect text_key_dstrect = {0, SCREEN_WINDOW - 85, 60, 60};
    SDL_RenderCopy(renderer, tilemap, &S_RECT_KEY, &key_dstrect);

    render_text(renderer, "", character->key, text_key_dstrect);

    SDL_RenderPresent(renderer);
}


