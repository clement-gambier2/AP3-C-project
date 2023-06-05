#ifndef AP3_C_PROJECT_CHARACTER_H
#define AP3_C_PROJECT_CHARACTER_H
#include "../objects/objects.h"
#include "../map/map.h"
#include <malloc.h>

struct Character {
    int hp_max;
    int hp;
    int def;
    int dmg;
    int key;
    int potion;
    int pos_x;
    int pos_y;
};

typedef struct Enemy_{
    int hp;
    int def;
    int dmg;
    int isDead;
} Enemy;

int get_hearts(struct Character *character);
int get_def(struct Character *character);

struct Character * createCharacter(int hp_max, int hp, int def, int dmg, int key, int potion);
void char_decrement_hp(struct Character * player, int delta);
void char_increment_hp(struct Character * player, int delta);

int isMovePossible(int x, int y, char ** map, struct Character * character);
void isThereAKey(struct Character * character, struct Map * map);
char * moveRight(struct Character * character,struct Map * map);
char * moveBottom(struct Character * character,struct Map * map);
char * moveLeft(struct Character * character,struct Map * map);
char * moveTop(struct Character * character,struct Map * map);


Enemy * createEnemy(int hp, int def, int dmg, int isDead);
void enemy_decrement_hp(Enemy * enemy, int delta);
void enemy_increment_hp(Enemy * enemy, int delta);

#endif //AP3_C_PROJECT_CHARACTER_H

