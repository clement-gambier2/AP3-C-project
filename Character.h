#ifndef AP3_C_PROJECT_CHARACTER_H
#define AP3_C_PROJECT_CHARACTER_H

#endif //AP3_C_PROJECT_CHARACTER_H

typedef struct Character_ {
    int hp_max;
    int hp;
    int def;
    int dmg;
    int key;
} Character;

typedef struct Enemy_{
    int hp;
    int def;
    int dmg;
} Enemy;

Character * createCharacter(int hp_max, int hp, int def, int dmg, int key);
void char_reduce_hp(Character * player, int delta);
void char_add_hp(Character * player, int delta);

Enemy * createEnemy(int hp, int def, int dmg);
void enemy_reduce_hp(Enemy * enemy, int delta);
void enemy_add_hp(Enemy * enemy, int delta);