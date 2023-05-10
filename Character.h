//
// Created by alexa on 10/05/2023.
//

#ifndef AP3_C_PROJECT_CHARACTER_H
#define AP3_C_PROJECT_CHARACTER_H

#endif //AP3_C_PROJECT_CHARACTER_H

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
} Enemy;
