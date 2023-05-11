#include <malloc.h>
#include "Character.h"

/**
 * Used to create a new playable character
 * @param hp_max - Maximum health points for the player
 * @param hp - Health points of the player
 * @param def - Defense points of the player
 * @param dmg - Damage points of the player
 * @param key - Number of keys detained by the player
 * @return Character *
 */
Character * createCharacter(int hp_max, int hp, int def, int dmg, int key) {
    Character * newCharacter = (Character *) malloc(sizeof (struct Character_));
    newCharacter->hp_max = hp_max;
    newCharacter->hp = hp;
    newCharacter->def = def;
    newCharacter->dmg = dmg;
    newCharacter->key = key;

    return newCharacter;
}

/**
 * Used to create a new enemy
 * @param hp - Health points for the enemy
 * @param def - Defense points of the enemy
 * @param dmg - Damage points of the enemy
 * @return Enemy *
 */
Enemy * createEnemy(int hp, int def, int dmg) {
    Enemy * newEnemy = (Enemy *) malloc(sizeof (struct Enemy_));
    newEnemy->hp = hp;
    newEnemy->def = def;
    newEnemy->dmg = dmg;

    return newEnemy;
}

/**
 * Used to reduce Health Points for a character
 * @param player - The player
 * @param delta - The amount of Health Points to remove
 */
void char_reduce_hp(Character * player, int delta) {
    player->hp -= delta;
}

/**
 * Used to increase Health Points for a character
 * @param player - The player
 * @param delta - The amount of Health Points to add
 */
void char_add_hp(Character * player, int delta) {
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
void enemy_reduce_hp(Enemy * enemy, int delta) {
    enemy->hp -= delta;
}

/**
 * Used to add Health Points for an enemy
 * @param enemy - The enemy
 * @param delta - The amount of Health Points to add
 */
void enemy_add_hp(Enemy * enemy, int delta) {
    enemy->hp += delta;
}