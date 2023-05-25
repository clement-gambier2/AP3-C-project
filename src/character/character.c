

#include <malloc.h>
#include "character.h"



#include "../inventory/inventory.h"

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
Character * createCharacter(int hp_max, int hp, int def, int dmg, int key, int potion) {
    Character * newCharacter = (Character *) malloc(sizeof (struct Character_));
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
Enemy * createEnemy(int hp, int def, int dmg, int isDead) {
    Enemy * newEnemy = (Enemy *) malloc(sizeof (struct Enemy_));
    newEnemy->hp = hp;
    newEnemy->def = def;
    newEnemy->dmg = dmg;
    newEnemy->isDead = isDead;

    return newEnemy;
}

/**
 * Used to reduce Health Points for a character
 * @param player - The player
 * @param delta - The amount of Health Points to remove
 */
void char_decrement_hp(Character* player, int delta) {
    player->hp -= delta;
}


/**
 * Used to increase Health Points for a character
 * @param player - The player
 * @param delta - The amount of Health Points to add
 */
void char_increment_hp(Character * player, int delta) {
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
void enemy_decrement_hp(Enemy * enemy, int delta) {
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
void enemy_increment_hp(Enemy * enemy, int delta) {
    enemy->hp += delta;
}


int get_hearts(Character *character) {
    int num_hearts = character->hp / 1;
    return num_hearts;
}

int get_def(Character *character) {
    int num_def = character->def / 1;
    return num_def;
}

int ennemyOnTheWay(char** map, int x, int y, char direction){
    switch(direction){
        case 't':
            if(map[x][y-1]=='A' && map[x][y-1]=='B' && map[x][y-1]=='C'){
                return 1;
            }
            return 0;
        case 'b':
            if(map[x][y+1]=='A' && map[x][y+1]=='B' && map[x][y+1]=='C'){
                return 1;
            }
            return 0;
        case 'l':
            if(map[x-1][y]=='A' && map[x-1][y]=='B' && map[x-1][y]=='C'){
                return 1;
            }
            return 0;
        case 'r':
            if(map[x+1][y]=='A' && map[x+1][y]=='B' && map[x+1][y]=='C'){
                return 1;
            }
            return 0;
        default:
            break;
    }
    return 0;   
}

/**
 * isMovePossible check if the move is possible
 * @param x
 * @param y
 * @param map
 * @return 0 if the move is possible, 1 otherwise
 */
int isMovePossible(int x, int y, char ** map){
    if (x < 0 || x > 29 || y < 0 || y > 29){
        return 1;
    }
    if(map[y][x] == '#'){
        return 1;
    }
    printf("y : %d, x : %d\n", x,y);
    printf("%c\n", map[y][x]);
    return 0;
}

int ennemyOnTheWay(char** map, int x, int y, char direction){
    switch(direction){
        case 't':
            if(map[x][y-1]=='A' && map[x][y-1]=='B' && map[x][y-1]=='C'){
                return 1;
            }
            return 0;
        case 'b':
            if(map[x][y+1]=='A' && map[x][y+1]=='B' && map[x][y+1]=='C'){
                return 1;
            }
            return 0;
        case 'l':
            if(map[x-1][y]=='A' && map[x-1][y]=='B' && map[x-1][y]=='C'){
                return 1;
            }
            return 0;
        case 'r':
            if(map[x+1][y]=='A' && map[x+1][y]=='B' && map[x+1][y]=='C'){
                return 1;
            }
            return 0;
        default:
            break;
    }   
}

/**
 * Used to moveLeft the character
 * @param character - The character
 */ 

void moveLeft(Character * character, char ** map){
    if (isMovePossible(character->pos_x-1, character->pos_y,map) == 0) {
        character->pos_x -= 1;
    }
}



/**
 * Used to moveRight the character
 * @param character - The character
 */ 
void moveRight(Character * character, char ** map){
    if (isMovePossible(character->pos_x+1, character->pos_y,map) == 0) {
        character->pos_x += 1;
    }
}

/**
 * Used to moveTop the character
 * @param character - The character
 */ 
void moveTop(Character * character, char ** map){
    if (isMovePossible(character->pos_x, character->pos_y-1,map) == 0) {
        character->pos_y -= 1;
    }
}

/**
 * Used to moveBottom the character
 * @param character - The character
 */ 
void moveBottom(Character * character, char ** map){
    if (isMovePossible(character->pos_x, character->pos_y+1,map) == 0) {
        character->pos_y += 1;
    }
}