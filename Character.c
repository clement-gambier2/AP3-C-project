//
// Created by alexa on 10/05/2023.
// santé = hp ; défense = def ;  attaque = dmg  Sante max = p_max


#include "Character.h"

void init_character(Character *perso, int hp_max, int hp, int def, int dmg, int key) {
    perso->hp_max = hp_max;
    perso->hp = hp;
    perso->def = def;
    perso->dmg = dmg;
    perso->key = key;
}
void modify_hp(Character *perso, int delta) {
    // vérifier si les HP actuels sont inférieurs ou égaux à la limite maximale de HP
    if (perso->hp >= perso->hp_max) {
        // si les HP actuels sont déjà à leur maximum, ne pas effectuer de modifications
        return;
    }

    // ajouter la valeur delta aux HP actuels
    perso->hp += delta;

    // vérifier si les HP actuels sont supérieurs à la limite maximale de HP
    if (perso->hp > perso->hp_max) {
        // si les HP actuels sont supérieurs à la limite maximale de HP, les ramener à la limite maximale
        perso->hp = perso->hp_max;
    }
}

int main (){

    Character perso1;

    init_character(&perso1, 10, 10, 1, 2, 0);

    perso1.hp_max += 1;
    modify_hp(&perso1, 3);

    // affichage des stats du personnage
    printf("Stats du personnage :\n");
    printf("Pv MAX : %d\n", perso1.hp_max);
    printf("Santé : %d\n", perso1.hp);
    printf("Défense : %d\n", perso1.def);
    printf("Attaque : %d\n", perso1.dmg);
    printf("Clé : %d\n", perso1.key);

    return 0;

};
