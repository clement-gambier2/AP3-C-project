
#include "map.h"

/*char * switchCharacter(char * map){
    FILE *fichier;
    int caractere_a_remplacer = 167; // Code décimal pour le caractère "§"
    char caractere_de_remplacement = 'p';
    int caractere;

    fichier = fopen(map, "r+");

    while ((caractere = fgetc(fichier)) != EOF) {
        if (caractere == caractere_a_remplacer) {
            fseek(fichier, -1, SEEK_CUR);
            fputc(caractere_de_remplacement, fichier);
        }
    }

    fclose(fichier);

    return map;
}*/

/**
* Test for displaying an image in the window
* @param renderer
*/
void drawMap(SDL_Renderer * renderer, char ** map, Character * player) {
    // TODO: drawMap V2 : Load Tilemap Packed + const every tile for drawing
    SDL_Event event;
    int running = 1;
    while (running) {
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
        //SDL_Rect playerRect = { (player->x * 30), (player->y * 30), 30, 30 };
        //SDL_RenderCopy(renderer, player_texture, NULL, &playerRect);


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


        // TODO : Supprimer cette section, elle ne sert qu'à des tests d'affichage pour éviter que ça crash
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
            }
        }
    }
}

/*
char * putInATab(char * map){
    FILE *fichier;
    int cpt=0;
    char tmp;
    char * tmp;
    tmp=(char*)malloc(900 * sizeof(char));

    fichier = fopen(map, "r+");
    while(cpt<900) {
        tmp= fgetc(fichier);
        if(tmp!=EOF){
            if(tmp=='#'||tmp=='1'||tmp=='2'||tmp=='3'||tmp=='A'||tmp=='B'||tmp=='C'||tmp=='!'||tmp=='p'||tmp=='<'||tmp=='>'||tmp=='^'||tmp=='v'||tmp==' '){
                tmp[cpt]=(char)tmp;
                printf("%c",(char)tmp);
                cpt+=1;
            }
        }
    }
    fclose(fichier);
    return tmp;
}

char * putInAFile(char * tab, char * map){
    FILE *fichier;
    fichier = fopen(map, "r+");
    for (int i = 0; i < 900; ++i) {
        fputc(tab[i], fichier);
    }
    fclose(fichier);
    return map;
}*/

/**
 *buildMapFromFile build the matrix with the map given in param
 * @param map
 * @return the level you have choice with param map, in a matrix.
 */
char** buildMapFromFile(char * map){
    //putInAFile(putInATab(switchCharacter(map)),map);
    char** laMap=(char**)malloc(30 * sizeof(char*));
    FILE *fp;
    fp = fopen(map, "r");
    char tmp;
    for (int i = 0; i < 30; i++)//for each line of the file
    {
        laMap[i]=(char*)malloc(30 * sizeof(char));
        for (int y = 0; y < 32; y++)//for each column of the file
        {
            tmp = fgetc(fp);
            if(tmp!=EOF && y< 30){
                //if(tmp=='#'||tmp=='1'||tmp=='2'||tmp=='3'||tmp=='A'||tmp=='B'||tmp=='C'||tmp=='!'||tmp=='p'||tmp=='<'||tmp=='>'||tmp=='^'||tmp=='v'||tmp==' '||tmp=='?'||tmp=='o'||tmp=='#\n') {
                    laMap[i][y] = (char) tmp;
                //}
            }
        }
    }
    fclose(fp);//close the file
    return laMap;
}

/**
 * initMap set level 1
 */
char** initMap(){
    return buildMapFromFile("src/map/niveau1Prof.level");
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
