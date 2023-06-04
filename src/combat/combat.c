#include "../../include/combat.h"

/**
 * Fight system that modify player and enemy statistics.
 * This function is called every time that the player run into an enemy.
 * This is only one turn of the fight.
 * @param character - struct character
 * @param enemy - struct enemy
 * @return -1 = Player's dead | 0 = Nobody's dead | 1 = Enemy's dead
 */
int fight(struct Character *character, Enemy *enemy){//, SDL_Renderer* renderer) {
    // Player turn
    int enemyHurtPoints = character->dmg - enemy->def;
    if (enemyHurtPoints < 1) {
        enemy_decrement_hp(enemy, 1);
    } else {
        enemy_decrement_hp(enemy, enemyHurtPoints);
    }

    // Check if the enemy is dead
    if (enemy->hp <= 0) {
        character->dmg += 1;
        character->hp_max += 1;
        return 1;
    }

    // Enemy turn
    int characterHurtPoints = enemy->dmg - character->def;
    if (characterHurtPoints < 1) {
        char_decrement_hp(character, 1);
    } else {
        char_decrement_hp(character, characterHurtPoints);
    }

    // Check if the player is dead
    if (character->hp <= 0) {
        return -1;
    }
    //inventory(renderer, character);
    return 0;
}