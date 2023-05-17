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