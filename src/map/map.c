#include <stdio.h>
#include <stdlib.h>
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
}

/**
* Test for displaying an image in the window
* @param renderer
*/
void drawMap(SDL_Renderer * renderer, char ** map) {
    SDL_Event event;
    int running = 1;
    while (running) {
        // TODO : Charger toutes les images et les convertir en textures pour les utiliser plus tard dans l'algo
        // Floor
        SDL_Surface * floor_image = SDL_LoadBMP("src/assets/img/floor_tile.bmp");
        SDL_Texture * floor_texture = SDL_CreateTextureFromSurface(renderer, floor_image);
        // Wall
        SDL_Surface * wall_image = SDL_LoadBMP("src/assets/img/wall_tile.bmp");
        SDL_Texture * wall_texture = SDL_CreateTextureFromSurface(renderer, wall_image);
        // Power Up Attack
        SDL_Surface * pu_attack_image = SDL_LoadBMP("src/assets/img/power_up_attack_layout.bmp");
        SDL_Texture * pu_attack_texture = SDL_CreateTextureFromSurface(renderer, pu_attack_image);
        // Power Up Defense
        SDL_Surface * pu_defense_image = SDL_LoadBMP("src/assets/img/power_up_defense_layout.bmp");
        SDL_Texture * pu_defense_texture = SDL_CreateTextureFromSurface(renderer, pu_defense_image);
        // Power Up HP Max
        SDL_Surface * pu_hp_image = SDL_LoadBMP("src/assets/img/power_up_hp_max_layout.bmp");
        SDL_Texture * pu_hp_texture = SDL_CreateTextureFromSurface(renderer, pu_hp_image);
        // Potion
        //SDL_Surface * potion_image = SDL_LoadBMP("src/assets/img/");
        //SDL_Texture * potion_texture = SDL_CreateTextureFromSurface(renderer, pu_attack_image);
        // Key

        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                SDL_Rect rect = { (i * 30), (j * 30), 30, 30 };
                // Print floor to avoid black screens
                SDL_RenderCopy(renderer, floor_texture, NULL, &rect);


                // TODO : Faire un switch pour attribuer la bonne texture à chaque case + importer des assets

                // For test : print only floor tiles
                if (i%2 == 0) {
                    SDL_RenderCopy(renderer, pu_defense_texture, NULL, &rect);
                } else {
                    SDL_RenderCopy(renderer, wall_texture, NULL, &rect);
                }
            }
        }


        SDL_RenderPresent(renderer);

        // TODO : Supprimer toutes les images et textures chargées dans l'algo
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
}

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
    return buildMapFromFile("niveau1Prof.level");
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

int main(){
    char ** map= buildMapFromFile("niveau 1.level");
    displayMap(map);
}