

#include <stdio.h>
#include <stdlib.h>
#include "character.h"


#define MOVE_IMPOSSIBLE 1
#define POTION 2
#define KEY 3
#define POWERUP_DAMAGE 4
#define POWERUP_DEFENSE 5
#define POWERUP_HP_MAX 6

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

/**
 * isMovePossible check if the move is possible
 * @param x
 * @param y
 * @param map
 * @return 0 if the move is possible, 1 otherwise
 */
int isMovePossible(int x, int y, char ** map){
    if (x < 0 || x > 29 || y < 0 || y > 29){
        return MOVE_IMPOSSIBLE;
    }
    if(map[y][x] == '#'){
        return MOVE_IMPOSSIBLE;
    }
    if (map[y][x] == 'p') {
        return POTION;
    }
    if (map[y][x] == '!') {
        return KEY;
    }
    if (map[y][x] == '1') {
        return POWERUP_DAMAGE;
    }
    if (map[y][x] == '2') {
        return POWERUP_DEFENSE;
    }
    if (map[y][x] == '3') {
        return POWERUP_HP_MAX;
    }

    return 0;
}

/**
 * Used to moveLeft the character
 * @param character - The character
 */

void moveLeft(Character* character,PowerUp * powerUp, char ** map) {
    int moveResult = isMovePossible(character->pos_x - 1, character->pos_y, map);
    if (moveResult == 0) {

        character->pos_x -= 1;
    }
    if (moveResult == POTION) {
        use_potion(character);
        map[character->pos_y][character->pos_x - 1] = ' ';

    }
    if (moveResult == KEY) {
        map[character->pos_y][character->pos_x - 1] = ' ';
        character->key += 1;
    }
    if (moveResult == POWERUP_DAMAGE) {
        map[character->pos_y][character->pos_x - 1] = ' ';
        apply_power_up(DAMAGE, character);
    }
    if (moveResult == POWERUP_DEFENSE) {
        map[character->pos_y][character->pos_x - 1] = ' ';
        apply_power_up(DEFENSE, character);
    }
    if (moveResult == POWERUP_HP_MAX) {
        map[character->pos_y][character->pos_x - 1] = ' ';
        apply_power_up(HP_MAX, character);
    }

}

// Mettez à jour les autres fonctions de déplacement de manière similaire (moveRight, moveTop, moveBottom)

/**
 * Used to moveRight the character
 * @param character - The character
 */

void moveRight(Character * character,PowerUp * powerUp, char ** map){
    int moveResult = isMovePossible(character->pos_x + 1, character->pos_y, map);
    if (moveResult == 0) {
        character->pos_x += 1;
    }
    if (moveResult == POTION) {
        use_potion(character);
        map[character->pos_y][character->pos_x + 1] = ' ';
    }
    if (moveResult == KEY) {
        map[character->pos_y][character->pos_x + 1] = ' ';
        character->key += 1;
    }
    if (moveResult == POWERUP_DAMAGE) {
        map[character->pos_y][character->pos_x + 1] = ' ';
        apply_power_up(DAMAGE, character);
    }
    if (moveResult == POWERUP_DEFENSE) {
        map[character->pos_y][character->pos_x + 1] = ' ';
        apply_power_up(DEFENSE, character);
    }
    if (moveResult == POWERUP_HP_MAX) {
        map[character->pos_y][character->pos_x + 1] = ' ';
        apply_power_up(HP_MAX, character);
    }
}

/**
 * Used to moveTop the character
 * @param character - The character
 */
void moveTop(Character * character,PowerUp * powerUp, char ** map){
    int moveResult = isMovePossible(character->pos_x, character->pos_y - 1, map);
    if (moveResult == 0) {
        character->pos_y -= 1;
    }
    if (moveResult == POTION) {
        use_potion(character);
        map[character->pos_y - 1][character->pos_x] = ' ';
    }
    if (moveResult == KEY) {
        map[character->pos_y - 1][character->pos_x] = ' ';
        character->key += 1;
    }
    if (moveResult == POWERUP_DAMAGE) {
        map[character->pos_y - 1][character->pos_x] = ' ';
        apply_power_up(DAMAGE, character);
    }
    if (moveResult == POWERUP_DEFENSE) {
        map[character->pos_y - 1][character->pos_x] = ' ';
        apply_power_up(DEFENSE, character);
    }
    if (moveResult == POWERUP_HP_MAX) {
        map[character->pos_y - 1][character->pos_x] = ' ';
        apply_power_up(HP_MAX, character);
    }
}

/**
 * Used to moveBottom the character
 * @param character - The character
 */
void moveBottom(Character * character,PowerUp * powerUp, char ** map) {
    int moveResult = isMovePossible(character->pos_x, character->pos_y + 1, map);
    if (moveResult == 0) {
        character->pos_y += 1;
    }
    if (moveResult == POTION) {
        use_potion(character);
        map[character->pos_y + 1][character->pos_x] = ' ';
    }
    if (moveResult == KEY) {
        map[character->pos_y + 1][character->pos_x] = ' ';
        character->key += 1;
    }
    if (moveResult == POWERUP_DAMAGE) {
        map[character->pos_y + 1][character->pos_x] = ' ';
        apply_power_up(DAMAGE, character);
    }
    if (moveResult == POWERUP_DEFENSE) {
        map[character->pos_y + 1][character->pos_x] = ' ';
        apply_power_up(DEFENSE, character);
    }
    if (moveResult == POWERUP_HP_MAX) {
        map[character->pos_y + 1][character->pos_x] = ' ';
        apply_power_up(HP_MAX, character);
    }
}
