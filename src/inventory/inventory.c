//
// Created by mrplume on 17/05/23.
//
#include "../../include/SDL2/SDL.h"
#include "../../include/SDL2/SDL_ttf.h"
#include "../../include/inventory.h"
#include "../../include/const.h"



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

void render_hearts(SDL_Renderer* renderer, int num_hearts) {
    SDL_Surface* heart_surface = SDL_LoadBMP("src/assets/img/heart.bmp");
    if (!heart_surface) {
        fprintf(stderr, "Erreur lors du chargement de l'image du cœur : %s\n", SDL_GetError());
        return;
    }

    SDL_Texture* heart_texture = SDL_CreateTextureFromSurface(renderer, heart_surface);
    if (!heart_texture) {
        fprintf(stderr, "Erreur lors de la création de la texture du cœur : %s\n", SDL_GetError());
        SDL_FreeSurface(heart_surface);
        return;
    }

    SDL_Rect heart_rect;
    heart_rect.w = 30;
    heart_rect.h = 30;

    for (int i = 0; i < num_hearts; i++) {
        heart_rect.x = i * (heart_rect.w + 5);
        heart_rect.y = 0;  // Décalage vertical pour les cœurs
        SDL_RenderCopy(renderer, heart_texture, NULL, &heart_rect);
    }


    SDL_DestroyTexture(heart_texture);
    SDL_FreeSurface(heart_surface);
}
void render_def(SDL_Renderer* renderer, int num_def) {
    SDL_Surface* def_surface = SDL_LoadBMP("src/assets/img/def.bmp");
    if (!def_surface) {
        fprintf(stderr, "Erreur lors du chargement de l'image de défense : %s\n", SDL_GetError());
        return;
    }

    SDL_Texture* def_texture = SDL_CreateTextureFromSurface(renderer, def_surface);
    if (!def_texture) {
        fprintf(stderr, "Erreur lors de la création de la texture de défense : %s\n", SDL_GetError());
        SDL_FreeSurface(def_surface);
        return;
    }

    SDL_Rect def_rect;
    def_rect.w = 30;
    def_rect.h = 30;

    for (int i = 0; i < num_def; i++) {
        def_rect.x = i * (def_rect.w + 5);
        def_rect.y = 30;  // Décalage vertical pour les défenses
        SDL_RenderCopy(renderer, def_texture, NULL, &def_rect);
    }

    SDL_DestroyTexture(def_texture);
    SDL_FreeSurface(def_surface);
}

void inventory(SDL_Renderer* renderer, struct Character * character) {

    int num_hearts = get_hearts(character);
    render_hearts(renderer, num_hearts);

    int num_def = get_def(character);
    render_def(renderer, num_def);


    SDL_Surface *key_image = SDL_LoadBMP("src/assets/img/key.bmp");
    SDL_Texture *key_texture = SDL_CreateTextureFromSurface(renderer, key_image);

    SDL_Rect key_dstrect = {0, SCREEN_WINDOW - 100, 60, 30};
    SDL_RenderCopy(renderer, key_texture, NULL, &key_dstrect);

    render_text(renderer, "", character->key, key_dstrect);

    SDL_Surface *potion_image = SDL_LoadBMP("src/assets/img/potion.bmp");
    SDL_Texture *potion_texture = SDL_CreateTextureFromSurface(renderer, potion_image);

    SDL_Rect potion_dstrect = {0, SCREEN_WINDOW - 50, 30, 30};
    SDL_RenderCopy(renderer, potion_texture, NULL, &potion_dstrect);

    render_text(renderer, "", character->potion, potion_dstrect);


        SDL_RenderPresent(renderer);

        SDL_DestroyTexture(key_texture);
        SDL_DestroyTexture(potion_texture);
        SDL_FreeSurface(key_image);
        SDL_FreeSurface(potion_image);

    }


