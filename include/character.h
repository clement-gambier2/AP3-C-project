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

typedef struct Enemy_{
    int hp;
    int def;
    int dmg;
    int isDead;
    int pos_x;
    int pos_y;
    struct Enemy_* next;
    struct Enemy_* previous;
} Enemy;

int get_hearts(struct Character *character);
int get_def(struct Character *character);

struct Character * createCharacter(int hp_max, int hp, int def, int dmg, int key, int potion);
void char_decrement_hp(struct Character * player, int delta);
void char_increment_hp(struct Character * player, int delta);

int isMovePossible(int x, int y, char **map, Enemy * enemy, struct Character * character);
void moveLeft(struct Character * character, char ** map, Enemy * enemy);
void moveRight(struct Character * character,char ** map, Enemy * enemy);
void moveTop(struct Character * character,char ** map, Enemy * enemy);
void moveBottom(struct Character * character,char ** map, Enemy * enemy);

Enemy * createEnemy(int hp, int def, int dmg, int isDead, int pos_x, int pos_y);
void enemy_decrement_hp(Enemy * enemy, int delta);
void enemy_increment_hp(Enemy * enemy, int delta);

void addEnemy(Enemy *enemyAdd, Enemy *myEnemy);
Enemy * saveEnemyFromMap(Map *map);
Enemy * getEnemyByPosition(Enemy * enemy,int pos_x, int pos_y);


#endif //AP3_C_PROJECT_CHARACTER_H

