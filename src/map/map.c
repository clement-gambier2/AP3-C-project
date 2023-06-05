
#include "map.h"

/**
 * Draw a wall tile
 * @param renderer
 * @param x
 * @param y
 * @param tilemap
 * @param rect
 * @param map
 */
void drawWall(SDL_Renderer * renderer, int x, int y, SDL_Texture * tilemap, SDL_Rect rect, char ** map) {
    SDL_RenderCopy(renderer, tilemap, &S_RECT_WALL_1, &rect);
    // TODO: Vérifier tout les alentours pour choisir le bon mur
    // TODO: Ajouter du random pour varier les textures de murs
}

/**
 * Draw a well oriented an textured door tile
 * @param renderer
 * @param x
 * @param y
 * @param tilemap
 * @param rect
 * @param map
 * @param isOpen
 */
void drawDoor(SDL_Renderer * renderer, int x, int y, SDL_Texture * tilemap, SDL_Rect rect, char ** map, int isOpen) {
    // Angle determination
    double angle = 0.0;
    if (map[y][x-1] == ' ' && map[y][x+1] == ' ') {
        angle = 90.0;
    }
    // Texture determination
    SDL_Rect doorTexture = S_RECT_SINGLE_CLOSED_DOOR;
    if (isOpen) {
        doorTexture = S_RECT_SINGLE_OPEN_DOOR;
    }
    SDL_RenderCopyEx(renderer, tilemap, &doorTexture, &rect, angle, NULL, RENDERER_FLIP);
}

/**
 * Draw a floor tile
 * @param renderer
 * @param x
 * @param y
 * @param tilemap
 * @param rect
 * @param map
 */
void drawFloor(SDL_Renderer * renderer, int x, int y, SDL_Texture * tilemap, SDL_Rect rect, char ** map) {
    SDL_RenderCopy(renderer, tilemap, &S_RECT_FLOOR_1, &rect);

    // TODO: Vérifier tout les alentours pour choisir la bonne texture et la bonne orientation
    // TODO: Ajouter du random pour varier les textures de sol (en gardant l'orientation etc...)
}

/**
 * Draw a well oriented room exit tile.
 * @param renderer - SDL_Renderer
 * @param x - x coord for the map
 * @param y - y coord for the map
 * @param tilemap - tilemap Texture
 * @param rect - SDL_Rect destination format
 */
void drawRoomExit(SDL_Renderer * renderer, int x, int y, SDL_Texture * tilemap, SDL_Rect rect) {
    if (x == 14) {
        if (y == 29) {
            SDL_RenderCopyEx(renderer, tilemap, &S_RECT_RIGHT_ARCH, &rect, 180.0, NULL, RENDERER_FLIP);
        }
        if (y == 0) {
            SDL_RenderCopyEx(renderer, tilemap, &S_RECT_LEFT_ARCH, &rect, 0.0, NULL, RENDERER_FLIP);
        }
    }
    if (x == 15) {
        if (y == 0) {
            SDL_RenderCopyEx(renderer, tilemap, &S_RECT_RIGHT_ARCH, &rect, 0.0, NULL, RENDERER_FLIP);
        }
        if (y == 29) {
            SDL_RenderCopyEx(renderer, tilemap, &S_RECT_LEFT_ARCH, &rect, 180.0, NULL, RENDERER_FLIP);
        }
    }
    if (y == 14) {
        if (x == 29) {
            SDL_RenderCopyEx(renderer, tilemap, &S_RECT_LEFT_ARCH, &rect, 90.0, NULL, RENDERER_FLIP);
        }
        if (x == 0) {
            SDL_RenderCopyEx(renderer, tilemap, &S_RECT_RIGHT_ARCH, &rect, 270.0, NULL, RENDERER_FLIP);
        }
    }
    if (y == 15) {
        if (x == 29) {
            SDL_RenderCopyEx(renderer, tilemap, &S_RECT_RIGHT_ARCH, &rect, 90.0, NULL, RENDERER_FLIP);
        }
        if (x == 0) {
            SDL_RenderCopyEx(renderer, tilemap, &S_RECT_LEFT_ARCH, &rect, 270.0, NULL, RENDERER_FLIP);
        }
    }
}

/**
* Test for displaying an image in the window
* @param renderer
*/
void drawMap(SDL_Renderer * renderer, char ** map, struct Character * player, SDL_Texture * tilemap) {
    // TODO: drawMap V2 : Load Tilemap Packed + const every tile for drawing
    for (int y_coord = 0; y_coord < 30; y_coord++) {
        for (int x_coord = 0; x_coord < 30; x_coord++) {
            SDL_Rect rect = { (x_coord * 30), (y_coord * 30), 30, 30 };
            // Print floor to avoid black screens
            SDL_RenderCopy(renderer, tilemap, &S_RECT_FLOOR_1, &rect);

            switch (map[y_coord][x_coord]) {
                case ' ': // Floor
                    drawFloor(renderer, x_coord, y_coord, tilemap, rect, map);
                    break;
                case '#': // Wall
                    //SDL_RenderCopy(renderer, tilemap, &S_RECT_WALL_1, &rect);
                    drawWall(renderer, x_coord, y_coord, tilemap, rect, map);
                    break;
                case 'p': // Potion
                    SDL_RenderCopy(renderer, tilemap, &S_RECT_RED_POTION, &rect);
                    break;
                case 'A': // Enemy 1
                    SDL_RenderCopy(renderer, tilemap, &S_RECT_SLIME, &rect);
                    break;
                case 'B': // Enemy 2
                    SDL_RenderCopy(renderer, tilemap, &S_RECT_VIKING, &rect);
                    break;
                case 'C': // Enemy 3
                    SDL_RenderCopy(renderer, tilemap, &S_RECT_BLACK_WIZARD, &rect);
                    break;
                case '?': // Room exit
                    drawRoomExit(renderer, x_coord, y_coord, tilemap, rect);
                    break;
                case '!': // key
                    SDL_RenderCopy(renderer, tilemap, &S_RECT_KEY, &rect);
                    break;
                case 'o': // closed door
                    drawDoor(renderer, x_coord, y_coord, tilemap, rect, map, 0);
                    break;
                case 'i': // open door
                    drawDoor(renderer, x_coord, y_coord, tilemap, rect, map, 1);
                    break;
                case '1': // Power Up Attack
                    SDL_RenderCopy(renderer, tilemap, &S_RECT_GRAY_POTION, &rect);
                    break;
                case '2': // Power Up Defense
                    SDL_RenderCopy(renderer, tilemap, &S_RECT_GREEN_POTION, &rect);
                    break;
                case '3': // Power Up HP Max
                    SDL_RenderCopy(renderer, tilemap, &S_RECT_BLUE_POTION, &rect);
                        break;
                default:
                    SDL_RenderCopy(renderer, tilemap, &S_RECT_LOBSTER, &rect);
                    break;
                }
            }
        }

        // Drawing player
        SDL_Rect playerRect = { (player->pos_x * 30), (player->pos_y * 30), 30, 30 };
        SDL_RenderCopy(renderer, tilemap, &S_RECT_CIV_1, &playerRect);

        SDL_RenderPresent(renderer);
}

/**
 *buildMapFromFile build the matrix with the map given in param
 * @param map
 * @return the level you have choice with param map, in a matrix.
 */
struct Map* buildMapFromFile(char * map){
    struct Map* finalMap = malloc(sizeof(struct Map));
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

    for (int i = 0; i < 15; i++) {
        if (fgets(line, sizeof(line), fp) != NULL) {
            line[strcspn(line, "\r\n")] = '\0';  // delete the \n
            if (strlen(line) > 0) {
                printf("%s\n", line);
                char *separator = strchr(line, ':');
                if (separator != NULL) {
                    separator++;  // we want the string after the :
                    if (*separator == ' ') {
                        separator++;  // we want the string after the space
                    }
                    switch (i) {
                        case 2:
                            finalMap->A_Pv = atoi(separator);
                            break;
                        case 3:
                            finalMap->A_Force = atoi(separator);
                            break;
                        case 4:
                            finalMap->A_Armure = atoi(separator);
                            break;
                        case 7:
                            finalMap->B_Pv = atoi(separator);
                            break;
                        case 8:
                            finalMap->B_Force = atoi(separator);
                            break;
                        case 9:
                            finalMap->B_Armure = atoi(separator);
                            break;
                        case 12:
                            finalMap->C_Pv = atoi(separator);
                            break;
                        case 13:
                            finalMap->C_Force = atoi(separator);
                            break;
                        case 14:
                            finalMap->C_Armure = atoi(separator);
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }

    finalMap->enemy= malloc(sizeof(struct Enemy_));
    finalMap->enemy= saveEnemyFromMap(finalMap);

    fclose(fp);//close the file
    return finalMap;
}

/**
 * initMap set level 1
 */
struct Map* initMap(){
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
