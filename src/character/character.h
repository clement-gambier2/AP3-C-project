#ifndef AP3_C_PROJECT_CHARACTER_H
#define AP3_C_PROJECT_CHARACTER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


typedef struct Character_ {
    int hp_max;
    int hp;
    int def;
    int dmg;
    int key;
    int potion;
} Character;

typedef struct Enemy_{
    int hp;
    int def;
    int dmg;
    int isDead;
} Enemy;

int get_hearts(Character *character);
int get_def(Character *character);

Character * createCharacter(int hp_max, int hp, int def, int dmg, int key, int potion);
void char_decrement_hp(Character * player, int delta);
void char_increment_hp(Character * player, int delta);

Enemy * createEnemy(int hp, int def, int dmg, int isDead);
void enemy_decrement_hp(Enemy * enemy, int delta);
void enemy_increment_hp(Enemy * enemy, int delta);

#endif //AP3_C_PROJECT_CHARACTER_H