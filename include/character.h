#ifndef AP3_C_PROJECT_CHARACTER_H
#define AP3_C_PROJECT_CHARACTER_H
#include "map.h"
#include "character.h"
#include "inventory.h"
#include "combat.h"

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

struct Enemy_ {
    int hp;
    int def;
    int dmg;
    int isDead;
    int pos_x;
    int pos_y;
    struct Enemy_ *next;
    struct Enemy_ *previous;
};

int get_hearts(struct Character *character);
int get_def(struct Character *character);

struct Character * createCharacter(int hp_max, int hp, int def, int dmg, int key, int potion);
void char_decrement_hp(struct Character * player, int delta);
void char_increment_hp(struct Character * player, int delta);

int isMovePossible(int x, int y, char **map, struct Enemy_ * enemy, struct Character * character);
void moveLeft(struct Character * character, char ** map, struct Enemy_ * enemy);
void moveRight(struct Character * character,char ** map, struct Enemy_ * enemy);
void moveTop(struct Character * character,char ** map, struct Enemy_ * enemy);
void moveBottom(struct Character * character,char ** map, struct Enemy_ * enemy);

struct Enemy_ * createEnemy(int hp, int def, int dmg, int isDead, int pos_x, int pos_y);
void enemy_decrement_hp(struct Enemy_ * enemy, int delta);
void enemy_increment_hp(struct Enemy_ * enemy, int delta);

void addEnemy(struct Enemy_ *enemyAdd, struct Enemy_ *myEnemy);
struct Enemy_ * saveEnemyFromMap(struct Map *map);
struct Enemy_ * getEnemyByPosition(struct Enemy_ * enemy,int pos_x, int pos_y);


#endif //AP3_C_PROJECT_CHARACTER_H

