//
// Created by Tristan on 10/05/2023.
//

#include "combat_system.h"
#include <stdio.h>

/**
 * Fight system that modify player and enemy statistics.
 * This function is called every time that the player run into an enemy.
 * This is only one turn of the fight.
 * @param character - struct character
 * @param enemy - struct enemy
 * @return 1-0 - isCombatWin
 */
int fight(struct character character, struct enemy enemy) {
    // Player turn
    int enemyHurtPoints = character.dmg - enemy.def;
    if (enemyHurtPoints < 1) {
        enemy.hp -= 1;
    } else {
        enemy.hp -= enemyHurtPoints;
    }

    // Check if the enemy is dead
    if (enemy.hp <= 0) {
        printf("%s", "Combat Win");
        character.dmg += 1;
        character.hp_max += 1;
        return 1;
    }

    // Enemy turn
    int characterHurtPoints = enemy.dmg - character.def;
    if (characterHurtPoints < 1) {
        character.hp -= 1;
    } else {
        character.hp -= characterHurtPoints;
    }

    return 0;
}


int main() {
    printf("%s", "Hello World !");
}