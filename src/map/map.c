#include <stdio.h>
#include <stdlib.h>
#include "map.h"

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