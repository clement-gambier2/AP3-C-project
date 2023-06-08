//
// Created by mrplume on 17/05/23.
//


#include "inventory.h"


/**
 * Used to render some text with a value.
 * @param renderer
 * @param text
 * @param value
 * @param dstrect
 * @param font
 * @param color
 * @example "Healthpoints : 14"
 */
void render_text(SDL_Renderer* renderer, const char *text, int value, SDL_Rect dstrect, TTF_Font * font, SDL_Color color) {
    /*if (TTF_Init() == -1) {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }*/

    //TTF_Font *font = TTF_OpenFont("src/assets/fonts/roboto.ttf", ptSize);
    if (!font) {
        fprintf(stderr, "Erreur à l'ouverture de la police : %s\n", TTF_GetError());
    }

    char text_buffer[32];
    sprintf(text_buffer, "%s %d", text, value);

    SDL_Surface *text_surface = TTF_RenderText_Solid(font, text_buffer, color);
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
    //TTF_CloseFont(font);

    // render the text texture
    SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);
    SDL_DestroyTexture(text_texture);

    //TTF_Quit();
}

/**
 * Used to render some text in a rectangle.
 * @param renderer
 * @param text
 * @param dstrect
 * @param font
 * @param colorRect
 * @param colorText
 */
void renderTextRect(SDL_Renderer* renderer, const char *text, SDL_Rect dstrect, TTF_Font * font, SDL_Color colorRect, SDL_Color colorText) {
    SDL_Surface* textSurface = TTF_RenderText_Blended(font, text, colorText);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);


    SDL_Rect textRect = { dstrect.x + 5,
                          dstrect.y,
                          textSurface->w,
                          textSurface->h};


    // Draw black rectangle
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Noir (RGBA)
    SDL_Rect rect = { dstrect.x + 2, dstrect.y, dstrect.w + 30, dstrect.h + 2};
    SDL_RenderFillRect(renderer, &rect);

    // render the text texture
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);


    SDL_DestroyTexture(textTexture);
}

/**
 * Used to display the character's HP in the HUD
 * @param renderer
 * @param tilemap
 * @param num_hearts
 */
void render_hearts(SDL_Renderer* renderer, SDL_Texture* tilemap, int num_hearts, struct Character* character) {
    int yellow_hearts = character->hp / 10;
    int red_hearts = character->hp % 10;
    int max_hearts = character->hp_max;

    // Affichage des coeurs jaunes
    for (int i = 0; i < yellow_hearts; i++) {
        SDL_Rect heart_rect = {(i * 40) + 5, 0, 40, 40};
        SDL_RenderCopy(renderer, tilemap, &S_RECT_HEART_GOLD, &heart_rect);
    }

    // Affichage des coeurs rouges
    for (int i = 0; i < red_hearts; i++) {
        SDL_Rect heart_rect = {((i + yellow_hearts) * 40) + 5, 0, 40, 40};
        SDL_RenderCopy(renderer, tilemap, &S_RECT_HEART, &heart_rect);
    }

    // Affichage des coeurs noirs (HPMAX - HP actuels)
    for (int i = 0; i < max_hearts - character->hp; i++) {
        SDL_Rect heart_rect = {((i + yellow_hearts + red_hearts) * 40) + 5, 0, 40, 40};
        SDL_RenderCopy(renderer, tilemap, &S_RECT_HEART_BLACK, &heart_rect);
    }
}

/**
 * Used to display the character's Attack in the HUD
 * @param renderer
 * @param tilemap
 * @param num_dmg
 */
void render_attack(SDL_Renderer* renderer, SDL_Texture * tilemap, int num_dmg) {
    for (int i = 0; i < num_dmg; i++) {
        SDL_Rect attack_rect = {(i * 40) + 5, 80, 40, 40}; // adjust the position as per your requirement
        SDL_RenderCopy(renderer, tilemap, &S_RECT_SWORD_1, &attack_rect);
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
void inventory(SDL_Renderer* renderer, SDL_Texture * tilemap, struct Character * character, TTF_Font * font) {

    int num_hearts = get_hearts(character);
    render_hearts(renderer, tilemap, num_hearts, character);

    int num_def = get_def(character);
    render_def(renderer, tilemap, num_def);
    
    render_attack(renderer, tilemap, character->dmg);

    SDL_Rect key_dstrect = {0, SCREEN_WINDOW - 100, 60, 60};
    SDL_Rect text_key_dstrect = {0, SCREEN_WINDOW - 85, 60, 60};
    SDL_RenderCopy(renderer, tilemap, &S_RECT_KEY, &key_dstrect);

    render_text(renderer, "", character->key, text_key_dstrect, font, WHITE_COLOR);

    SDL_RenderPresent(renderer);
}


