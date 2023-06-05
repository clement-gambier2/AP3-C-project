

#include <stdlib.h>
#include "../../include/character.h"

/**
 * Used to create a new playable character
 * @param hp_max - Maximum health points for the player
 * @param hp - Health points of the player
 * @param def - Defense points of the player
 * @param dmg - Damage points of the player
 * @param key - Number of keys detained by the player
 * @param potion - Number of potions detained by the player
 * @param pos_x - Position on x of the character
 * @param pos_y - Position on y of the character
 * @return Character *
 */
struct Character *createCharacter(int hp_max, int hp, int def, int dmg, int key, int potion) {
    struct Character *newCharacter = (Character *) malloc(sizeof(struct Character_));
    newCharacter->hp_max = hp_max;
    newCharacter->hp = hp;
    newCharacter->def = def;
    newCharacter->dmg = dmg;
    newCharacter->key = key;
    newCharacter->potion = potion;
    newCharacter->pos_x = 15;
    newCharacter->pos_y = 15;
    return newCharacter;
}

/**
 * Used to create a new enemy
 * @param hp - Health points for the enemy
 * @param def - Defense points of the enemy
 * @param dmg - Damage points of the enemy
 * @return Enemy *
 */
struct Enemy_ *createEnemy(int hp, int def, int dmg, int isDead, int pos_x, int pos_y) {
    struct Enemy_ *newEnemy = (struct Enemy_ *) malloc(sizeof(struct Enemy_));
    newEnemy->hp = hp;
    newEnemy->def = def;
    newEnemy->dmg = dmg;
    newEnemy->isDead = isDead;
    newEnemy->pos_x = pos_x;
    newEnemy->pos_y = pos_y;
    newEnemy->next = NULL;
    newEnemy->previous = NULL;
    return newEnemy;
}

void addEnemy(struct Enemy_ *enemyAdd, struct Enemy_ *myEnemy) {
    if (myEnemy == NULL) {
        printf("error");
        return;
    }
    while (myEnemy->next != NULL) {
        myEnemy = myEnemy->next;
    }

    myEnemy->next = enemyAdd;
    enemyAdd->previous = myEnemy;
}

struct Enemy_ * saveEnemyFromMap(struct Map *map) {
    int cpt = 0;
    char **matrix = map->matrix;
    struct Enemy_ *enemy;
    struct Enemy_ *enemyTmp;
    for (int i = 0; i < 30; i++)//for each line of the file
    {
        for (int y = 0; y < 30; y++)//for each column of the file
        {
            printf("%c", matrix[i][y]);
            if (matrix[i][y] == 'A') {
                if (cpt == 0) {
                    enemy = createEnemy(map->A_Pv, map->A_Armure, map->A_Force, 0, i, y);
                    cpt += 1;
                }
                enemyTmp = createEnemy(map->A_Pv, map->A_Armure, map->A_Force, 0, i, y);
                addEnemy(enemyTmp, enemy);
                cpt += 1;
            }
            if (matrix[i][y] == 'B') {
                if (cpt == 0) {
                    enemy = createEnemy(map->B_Pv, map->B_Armure, map->B_Force, 0, i, y);
                    cpt += 1;
                }
                enemyTmp = createEnemy(map->B_Pv, map->B_Armure, map->B_Force, 0, i, y);
                addEnemy(enemyTmp, enemy);
                cpt += 1;
            }
            if (matrix[i][y] == 'C') {
                if (cpt == 0) {
                    enemy = createEnemy(map->C_Pv, map->C_Armure, map->C_Force, 0, i, y);
                    cpt += 1;
                }
                enemyTmp = createEnemy(map->C_Pv, map->C_Armure, map->C_Force, 0, i, y);
                addEnemy(enemyTmp, enemy);
                cpt += 1;
            }
        }
    }
    return enemy
}

struct Enemy_ * getEnemyByPosition(struct Enemy_ * enemy,int pos_x, int pos_y){
    if(enemy == NULL){
        printf("error");
    }
    while (enemy->previous != NULL) {
        myEnemy = myEnemy->previous;
    }
    while(enemy->next != NULL){
        if(enemy->pos_x==pos_x && enemy->pos_y==pos_y){
            return enemy;
        }
        enemy=enemy->next;
    }
}

/**
 * Used to reduce Health Points for a character
 * @param player - The player
 * @param delta - The amount of Health Points to remove
 */
void char_decrement_hp(struct Character *player, int delta) {
    player->hp -= delta;
}


/**
 * Used to increase Health Points for a character
 * @param player - The player
 * @param delta - The amount of Health Points to add
 */
void char_increment_hp(struct Character *player, int delta) {
    if (player->hp + delta > player->hp_max) {
        player->hp = player->hp_max;
    } else {
        player->hp += delta;
    }
}

/**
 * Used to reduce Health Points for an enemy
 * @param enemy - The enemy
 * @param delta - The amount of Health Points to remove
 */
void enemy_decrement_hp(struct Enemy_ *enemy, int delta) {
    enemy->hp -= delta;
    if (enemy->hp <= 0) {
        enemy->isDead = 1;
    }
}

/**
 * Used to add Health Points for an enemy
 * @param enemy - The enemy
 * @param delta - The amount of Health Points to add
 */
void enemy_increment_hp(struct Enemy_ *enemy, int delta) {
    enemy->hp += delta;
}


int get_hearts(struct Character *character) {
    int num_hearts = character->hp / 1;
    return num_hearts;
}

int get_def(struct Character *character) {
    int num_def = character->def / 1;
    return num_def;
}

/**
 * isMovePossible check if the move is possible
 * @param x
 * @param y
 * @param map
 * @return 0 if the move is possible, 1 otherwise
 */
int isMovePossible(int x, int y, char **map, struct Enemy_ * enemy, struct Character * character) {
    if (x < 0 || x > 29 || y < 0 || y > 29) {
        return 1;
    }
    if (map[y][x] == '#') {
        return 1;
    }
    if (map[y][x] == 'A' || map[y][x] == 'B' || map[y][x] == 'C') {
        struct Enemy_ * enemyToFight=getEnemyByPosition(enemy,x,y);//voir si faut pas inverser
        if(enemyToFight->isDead==1){
            return 0;
        }
        else{
            if(fight(character, enemyToFight)==0){
                return 1;
            }
            else{
                enemyToFight->isDead=1;
                return 1;
            }
        }
    }
    printf("y : %d, x : %d\n", x, y);
    printf("%c\n", map[y][x]);
    return 0;
}
/*
int ennemyOnTheWay(char **map, int x, int y, char direction) {
    switch (direction) {
        case 't':
            if (map[x][y + 1] == 'A' || map[x][y + 1] == 'B' || map[x][y + 1] == 'C') {
                return 1;
            }
            return 0;
        case 'b':
            if (map[x][y - 1] == 'A' || map[x][y - 1] == 'B' || map[x][y - 1] == 'C') {
                return 1;
            }
            return 0;
        case 'l':
            if (map[x - 1][y] == 'A' || map[x - 1][y] == 'B' || map[x - 1][y] == 'C') {
                return 1;
            }
            return 0;
        case 'r':
            if (map[x + 1][y] == 'A' || map[x + 1][y] == 'B' || map[x + 1][y] == 'C') {
                return 1;
            }
            return 0;
        default:
            break;
    }
    return 0;
}*/

/**
 * Used to moveLeft the character
 * @param character - The character
 */
void moveLeft(struct Character *character, char **map, struct Enemy_ * enemy) {
    if (isMovePossible(character->pos_x - 1, character->pos_y, map, enemy, character) == 0) {
        character->pos_x -= 1;
    }
}

/**
 * Used to moveRight the character
 * @param character - The character
 */
void moveRight(struct Character *character, char **map, struct Enemy_ * enemy) {
    if (isMovePossible(character->pos_x + 1, character->pos_y, map, enemy, character) == 0) {
        character->pos_x += 1;
    }
}

/**
 * Used to moveTop the character
 * @param character - The character
 */
void moveTop(struct Character *character, char **map, struct Enemy_ * enemy) {
    if (isMovePossible(character->pos_x, character->pos_y - 1, map, enemy, character) == 0) {
        character->pos_y -= 1;
    }
}

/**
 * Used to moveBottom the character
 * @param character - The character
 */
void moveBottom(struct Character *character, char **map, struct Enemy_ * enemy) {
    if (isMovePossible(character->pos_x, character->pos_y + 1, map, enemy, character) == 0) {
        character->pos_y += 1;
    }
}
