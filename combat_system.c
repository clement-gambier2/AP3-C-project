//
// Created by Tristan on 10/05/2023.
//

#include "combat_system.h"
#include "Character.h"
#include <stdio.h>

/*
typedef struct {
    int hp_max;
    int hp;
    int def;
    int dmg;
    int key; // uniquement pour les personnages
} Character;

typedef struct {
    int hp;
    int def;
    int dmg;
} Enemy;*/

/**
 * Fight system that modify player and enemy statistics.
 * This function is called every time that the player run into an enemy.
 * This is only one turn of the fight.
 * @param character - struct character
 * @param enemy - struct enemy
 * @return 1-0 - isCombatWin
 *//*
int fight(Character *character, Enemy *enemy) {
    // Player turn
    int enemyHurtPoints = character->dmg - enemy->def;
    if (enemyHurtPoints < 1) {
        enemy->hp -= 1;
    } else {
        enemy->hp -= enemyHurtPoints;
    }

    // Check if the enemy is dead
    if (enemy->hp <= 0) {
        printf("%s", "Combat Win");
        character->dmg += 1;
        character->hp_max += 1;
        return 1;
    }

    // Enemy turn
    int characterHurtPoints = enemy->dmg - character->def;
    if (characterHurtPoints < 1) {
        character->hp -= 1;
    } else {
        character->hp -= characterHurtPoints;
    }

    return 0;
}*/


int main() {
    printf("%s", "HelloWorld!");
    Character *perso1;

    init_character(perso1, 10, 10, 1, 2, 0);
    printf("%s", "On a fini l'initialisation");

    perso1->hp_max += 1;

    // affichage des stats du personnage
    printf("Stats du personnage :\n");
    printf("Pv MAX : %d\n", perso1->hp_max);
    printf("Santé : %d\n", perso1->hp);
    printf("Défense : %d\n", perso1->def);
    printf("Attaque : %d\n", perso1->dmg);
    printf("Clé : %d\n", perso1->key);

    return 0;
}