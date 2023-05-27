#include "map.h"
#include <stdbool.h>
#include <string.h>
/**
* Test for displaying an image in the window
* @param renderer
*/
void drawMap(SDL_Renderer * renderer, char ** map, int x, int y) {
    // TODO: drawMap V2 : Load Tilemap Packed + const every tile for drawing

        // Floor
        SDL_Surface * floor_image = SDL_LoadBMP("src/assets/img/bmp/floor_2.bmp");
        SDL_Texture * floor_texture = SDL_CreateTextureFromSurface(renderer, floor_image);
        // Wall
        SDL_Surface * wall_image = SDL_LoadBMP("src/assets/img/bmp/wall.bmp");
        SDL_Texture * wall_texture = SDL_CreateTextureFromSurface(renderer, wall_image);
        // Power Up Attack
        SDL_Surface * pu_attack_image = SDL_LoadBMP("src/assets/img/bmp/pu_attack.bmp");
        SDL_Texture * pu_attack_texture = SDL_CreateTextureFromSurface(renderer, pu_attack_image);
        // Power Up Defense
        SDL_Surface * pu_defense_image = SDL_LoadBMP("src/assets/img/bmp/pu_defense.bmp");
        SDL_Texture * pu_defense_texture = SDL_CreateTextureFromSurface(renderer, pu_defense_image);
        // Power Up HP Max
        SDL_Surface * pu_hp_image = SDL_LoadBMP("src/assets/img/bmp/pu_hp.bmp");
        SDL_Texture * pu_hp_texture = SDL_CreateTextureFromSurface(renderer, pu_hp_image);
        // Potion
        SDL_Surface * potion_image = SDL_LoadBMP("src/assets/img/bmp/potion.bmp");
        SDL_Texture * potion_texture = SDL_CreateTextureFromSurface(renderer, potion_image);
        // Enemy A
        SDL_Surface * enemy_A_image = SDL_LoadBMP("src/assets/img/bmp/enemy_A.bmp");
        SDL_Texture * enemy_A_texture = SDL_CreateTextureFromSurface(renderer, enemy_A_image);
        // Enemy B
        SDL_Surface * enemy_B_image = SDL_LoadBMP("src/assets/img/bmp/enemy_B.bmp");
        SDL_Texture * enemy_B_texture = SDL_CreateTextureFromSurface(renderer, enemy_B_image);
        // Enemy C
        SDL_Surface * enemy_C_image = SDL_LoadBMP("src/assets/img/bmp/enemy_C.bmp");
        SDL_Texture * enemy_C_texture = SDL_CreateTextureFromSurface(renderer, enemy_C_image);
        // Single Door North
        SDL_Surface * closed_door_N_image = SDL_LoadBMP("src/assets/img/bmp/closed_single_door_N.bmp");
        SDL_Texture * closed_door_N_texture = SDL_CreateTextureFromSurface(renderer, closed_door_N_image);
        SDL_Surface * open_door_N_image = SDL_LoadBMP("src/assets/img/bmp/open_single_door_N.bmp");
        SDL_Texture * open_door_N_texture = SDL_CreateTextureFromSurface(renderer, open_door_N_image);
        // Single Door West
        SDL_Surface * closed_door_W_image = SDL_LoadBMP("src/assets/img/bmp/closed_single_door_E.bmp");
        SDL_Texture * closed_door_W_texture = SDL_CreateTextureFromSurface(renderer, closed_door_W_image);
        SDL_Surface * open_door_W_image = SDL_LoadBMP("src/assets/img/bmp/open_single_door_E.bmp");
        SDL_Texture * open_door_W_texture = SDL_CreateTextureFromSurface(renderer, open_door_W_image);
        // Player
        SDL_Surface * player_image = SDL_LoadBMP("src/assets/img/bmp/character_civilian_1.bmp");
        SDL_Texture * player_texture = SDL_CreateTextureFromSurface(renderer, player_image);
        // Key
        SDL_Surface * key_image = SDL_LoadBMP("src/assets/img/bmp/key.bmp");
        SDL_Texture * key_texture = SDL_CreateTextureFromSurface(renderer, key_image);

        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                SDL_Rect rect = { (i * 30), (j * 30), 30, 30 };
                // Print floor to avoid black screens
                SDL_RenderCopy(renderer, floor_texture, NULL, &rect);

                switch (map[j][i])
                {
                case '#': // Wall
                    SDL_RenderCopy(renderer, wall_texture, NULL, &rect);
                    break;
                case 'p': // Potion
                    SDL_RenderCopy(renderer, potion_texture, NULL, &rect);
                    break;
                case 'A': // Enemy 1
                    SDL_RenderCopy(renderer, enemy_A_texture, NULL, &rect);
                    break;
                case 'B': // Enemy 2
                    SDL_RenderCopy(renderer, enemy_B_texture, NULL, &rect);
                    break;
                case 'C': // Enemy 3
                    SDL_RenderCopy(renderer, enemy_C_texture, NULL, &rect);
                    break;
                case '?': // Room exit

                    break;
                case '!': // key
                    SDL_RenderCopy(renderer, key_texture, NULL, &rect);
                    break;
                case 'o': // door
                    if (map[j][i-1] == ' ' && map[j][i+1] == ' ') {
                        SDL_RenderCopy(renderer, closed_door_W_texture, NULL, &rect);
                    } else {
                        SDL_RenderCopy(renderer, closed_door_N_texture, NULL, &rect);
                    }
                    break;
                case '1': // Power Up Attack
                    SDL_RenderCopy(renderer, pu_attack_texture, NULL, &rect);
                    break;
                case '2': // Power Up Defense
                    SDL_RenderCopy(renderer, pu_defense_texture, NULL, &rect);
                    break;
                case '3': // Power Up HP Max
                    SDL_RenderCopy(renderer, pu_hp_texture, NULL, &rect);
                        break;
                default:
                    break;
                }
            }
        }

        // Drawing player
        SDL_Rect playerRect = { (x * 30), (y * 30), 30, 30 };
        SDL_RenderCopy(renderer, player_texture, NULL, &playerRect);

        //inventory(renderer, player);


        SDL_RenderPresent(renderer);

        // Delete all texture and images
        // Floor
        SDL_DestroyTexture(floor_texture);
        SDL_FreeSurface(floor_image);
        // Wall
        SDL_DestroyTexture(wall_texture);
        SDL_FreeSurface(wall_image);
        // Power Up Attack
        SDL_DestroyTexture(pu_attack_texture);
        SDL_FreeSurface(pu_attack_image);
        // Power Up Defense
        SDL_DestroyTexture(pu_defense_texture);
        SDL_FreeSurface(pu_defense_image);
        // Power Up HP Max
        SDL_DestroyTexture(pu_hp_texture);
        SDL_FreeSurface(pu_hp_image);
        // Enemy A
        SDL_DestroyTexture(enemy_A_texture);
        SDL_FreeSurface(enemy_A_image);
        // Enemy B
        SDL_DestroyTexture(enemy_B_texture);
        SDL_FreeSurface(enemy_B_image);
        // Enemy C
        SDL_DestroyTexture(enemy_C_texture);
        SDL_FreeSurface(enemy_C_image);
        // Closed Door North Left
        SDL_DestroyTexture(closed_door_N_texture);
        SDL_FreeSurface(closed_door_N_image);
        // Closed Door North Right
        SDL_DestroyTexture(closed_door_W_texture);
        SDL_FreeSurface(closed_door_W_image);
        // Player
        SDL_DestroyTexture(player_texture);
        SDL_FreeSurface(player_image);
        // Key
        SDL_DestroyTexture(key_texture);
        SDL_FreeSurface(key_image);

}

/**
 *buildMapFromFile build the matrix with the map given in param
 * @param map
 * @return the level you have choice with param map, in a matrix.
 * finalMap is an object with the matrix and the directions in this order (E,S,O,N)
 */
struct Map * buildMapFromFile(char * map){
    struct Map* finalMap = malloc(sizeof(struct Map));
    char** laMap=(char**)malloc(30 * sizeof(char*));
    FILE *fp;
    fp = fopen(map, "r");
    char tmp;
    int cpt=0;

    for (int i = 0; i < 30; i++)//for each line of the file
    {
        laMap[i]=(char*)malloc(30 * sizeof(char));
        for (int y = 0; y < 32+cpt; y++)//for each column of the file
        {
            tmp = fgetc(fp);
            if(tmp!=EOF && y< 30+cpt){
                if(tmp=='#'||tmp=='1'||tmp=='2'||tmp=='3'||tmp=='A'||tmp=='B'||tmp=='C'||tmp=='!'||tmp=='p'||tmp=='<'||tmp=='>'||tmp=='^'||tmp=='v'||tmp==' '||tmp=='?'||tmp=='o'||tmp=='*') {
                    laMap[i][y] = (char) tmp;
                }
                else if((int)tmp==-62){ //first part of special char
                    laMap[i][y] = 'p';
                    fseek(fp, 1, SEEK_CUR);
                }
            }
        }
    }
    finalMap->matrix = laMap;

    char line[100];  // works like a buffer
    for (int i = 0; i < 4; i++) {
        if (fgets(line, sizeof(line), fp) != NULL) {
            line[strcspn(line, "\r\n")] = '\0';  // delete the \n
            if (strlen(line) > 0) {
                char* separator = strchr(line, ':');
                if (separator != NULL) {
                    separator++;  // we want the string after the :
                    if (*separator == ' ') {
                        separator++;  // we want the string after the space
                    }
                    finalMap->directions[i] = malloc(strlen(separator) + 1);
                    strcpy(finalMap->directions[i], separator); // copy the string in the array
                }
            }
        }
    }
    fclose(fp); //close the file
    return finalMap;
}

/**
 * initMap set level 1
 */
struct Map * initMap(void){
    return buildMapFromFile("src/map/niveau1.level");
}

/**
 * displayMap dislay each case of the map given in param.
 * @param map
 */
void displayMap(char ** map){
    for (int i = 0; i < 30; i++)//for each line of the file
    {
        for (int y = 0; y < 30; y++)//for each column of the file
        {
            printf("%c",map[i][y]);//display the symbol at this position
        }
        printf("\n");
    }
}

char* concatenateLevelName(char* a, char* b) {
    // Allouer suffisamment de mémoire pour la chaîne concaténée
    int len_a = strlen(a);
    int len_b = strlen(b);
    int len_concatenated = len_a + len_b + 1; // +1 pour le caractère nul de fin de chaîne
    char* concatenated = (char*)malloc(len_concatenated * sizeof(char));

    // Vérifier si l'allocation de mémoire a réussi
    if (concatenated == NULL) {
        printf("Erreur lors de l'allocation de mémoire.\n");
        exit(1);
    }

    // Copier les chaînes de caractères dans la chaîne concaténée
    strcpy(concatenated, a);
    strcat(concatenated, b);

    return concatenated;
}
