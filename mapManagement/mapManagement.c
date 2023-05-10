//
// Created by Gabriel Gressier on 10/05/2023.
//

#include <stdio.h>
#include <stdlib.h>

/**
 *buildMapFromFile build the matrix with the map given in param
 * @param map
 * @return the level you have choice with param map, in a matrix.
 */
char** buildMapFromFile(char * map){
    char** laMap=(char**)malloc(30 * sizeof(char*));
    FILE *fp;
    fp = fopen(map, "r");
    char tmp;
    for (int i = 0; i <= 30; i++)//for each line of the file
    {
        laMap[i]=(char*)malloc(30 * sizeof(char));;
        for (int y = 0; y <= 30; y++)//for each column of the file
        {
            tmp = fgetc(fp);
            if(tmp!=EOF){
                laMap[i][y]=(char)tmp;
            }
        }
    }
    fclose(fp);//close the file
    return laMap;
}

/**
 * initMap set level 1
 */
void initMap(){
    buildMapFromFile("niveau 1.level");
}

/**
 * displayMap dislay each case of the map given in param.
 * @param map
 */
void displayMap(char ** map){
    for (int i = 0; i <= 30; i++)//for each line of the file
    {
        for (int y = 0; y <= 30; y++)//for each column of the file
        {
            printf("%c",map[i][y]);//display the symbol at this position
        }
    }
}