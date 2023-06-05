
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "character.h"
#include "../objects/objects.h"
#include "../map/map.h"


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
struct Character * createCharacter(int hp_max, int hp, int def, int dmg, int key, int potion) {
    struct Character * newCharacter = (struct Character *) malloc(sizeof (struct  Character));
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
void char_decrement_hp(struct Character* player, int delta) {
    player->hp -= delta;
}


/**
 * Used to increase Health Points for a character
 * @param player - The player
 * @param delta - The amount of Health Points to add
 */
void char_increment_hp(struct Character * player, int delta) {
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
int isMovePossible(int x, int y, char ** map, struct Character * character){
    if (x < 0 || x > 29 || y < 0 || y > 29){
        return 1;
    }
    if(map[y][x] == '#'){
        return 1;
    }

    if(map[y][x] == 'o'){
        if (character->key > 0){
            character->key -= 1;
            map[y][x] = 'i';
            return 0;
        }
        return 1;
    }


    return 0;
}

void isThereAKey(struct Character * character, struct Map * map){
    if(map->matrix[character->pos_y][character->pos_x] == '!'){
        printf("You found a key !\n");
        character->key += 1;
        map->matrix[character->pos_y][character->pos_x] = ' ';
    }
}

void isThereAPotionDamage(struct Character * character, struct Map * map){
    if(map->matrix[character->pos_y][character->pos_x] == '1'){
        printf("You found a Potion Damage !\n");
        PowerUp powerUp;
        powerUp.powerUp = DAMAGE;
        powerUp.powerValue = DAMAGE_POWER_VALUE;
        apply_power_up(&powerUp, character);
        map->matrix[character->pos_y][character->pos_x] = ' ';
    }
}

void isThereAPotionDefense(struct Character * character, struct Map * map){
    if(map->matrix[character->pos_y][character->pos_x] == '2'){
        printf("You found a Potion Defense !\n");
        PowerUp powerUp;
        powerUp.powerUp = DEFENSE;
        powerUp.powerValue = DEFENSE_POWER_VALUE;
        apply_power_up(&powerUp, character);
        map->matrix[character->pos_y][character->pos_x] = ' ';
    }
}

void isThereAPotionHPMax(struct Character * character, struct Map * map){
    if(map->matrix[character->pos_y][character->pos_x] == '3'){
        printf("You found a Potion HP Max !\n");
        PowerUp powerUp;
        powerUp.powerUp = HP_MAX;
        powerUp.powerValue = HP_MAX_POWER_VALUE;
        apply_power_up(&powerUp, character);
        map->matrix[character->pos_y][character->pos_x] = ' ';
    }
}

void isThereAPotionHeal(struct Character * character, struct Map * map){
    if(map->matrix[character->pos_y][character->pos_x] == '*'){
        printf("You found a Potion Heal !\n");
        use_potion(character);
        map->matrix[character->pos_y][character->pos_x] = ' ';
    }
}

// Mettez à jour les autres fonctions de déplacement de manière similaire (moveRight, moveTop, moveBottom)



/**
 * moveRight
 * @param character
 * @param map
 * @return
 */
char * moveRight(struct Character * character,struct Map * map){
    //switch map : we are in moveRight so if there is a level it's the EAST one so first cell of the direction array
    if(map->matrix[character->pos_y][character->pos_x] == '?'){
        if(character->pos_x == 29){
            character->pos_x = 0;
            character->pos_y = 14;
            return map->directions[0];
        }

    }
    if (isMovePossible(character->pos_x+1, character->pos_y,map->matrix,character) == 0) {
        character->pos_x += 1;
        isThereAKey(character, map);
        isThereAPotionDamage(character, map);
        isThereAPotionDefense(character, map);
        isThereAPotionHPMax(character, map);
        isThereAPotionHeal(character, map);
    }

    return "noSwitch";
}

/**
 * moveBottom
 * @param character
 * @param map
 * @return
 */
char * moveBottom(struct Character * character, struct Map * map){
    //switch map : we are in moveBottom so if there is a level it's the SOUTH one so second cell of the direction array
    if(map->matrix[character->pos_y][character->pos_x] == '?'){
        if(character->pos_y == 29){
            character->pos_x = 15;
            character->pos_y = 0;;
            return map->directions[1];
        }
    }
    if (isMovePossible(character->pos_x, character->pos_y+1,map->matrix,character) == 0) {
        character->pos_y += 1;
        isThereAKey(character, map);
        isThereAPotionDamage(character, map);
        isThereAPotionDefense(character, map);
        isThereAPotionHPMax(character, map);
        isThereAPotionHeal(character, map);
    }

    return "noSwitch";
}

/**
 * moveLeft
 * @param character
 * @param map
 * @return
 */
char * moveLeft(struct Character * character,struct Map * map){
    //switch map : we are in moveLeft so if there is a level it's the WEST one so third cell of the direction array
    if(map->matrix[character->pos_y][character->pos_x] == '?'){
        if(character->pos_y == 14 && character->pos_x == 0){
            character->pos_x = 29;
            character->pos_y = 14;
            return map->directions[2];
        }
    }
    if (isMovePossible(character->pos_x-1, character->pos_y,map->matrix,character) == 0){
        character->pos_x-=1;
        isThereAKey(character, map);
        isThereAPotionDamage(character, map);
        isThereAPotionDefense(character, map);
        isThereAPotionHPMax(character, map);
        isThereAPotionHeal(character, map);
    }
    return "noSwitch";

}

/**
 * moveTop
 * @param character
 * @param map
 * @return
 */
char * moveTop(struct Character * character,struct Map * map){
    //switch map : we are in moveTop so if there is a level it's the NORTH one so fourth cell of the direction array
    if(map->matrix[character->pos_y][character->pos_x] == '?'){
        if(character->pos_y == 0){
            character->pos_x = 15;
            character->pos_y = 29;;
            return map->directions[3];
        }
    }
    if (isMovePossible(character->pos_x, character->pos_y-1,map->matrix,character) == 0) {
        character->pos_y -= 1;
        isThereAKey(character, map);
        isThereAPotionDamage(character, map);
        isThereAPotionDefense(character, map);
        isThereAPotionHPMax(character, map);
        isThereAPotionHeal(character, map);
    }
    return "noSwitch";
}


