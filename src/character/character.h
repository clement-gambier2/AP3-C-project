#ifndef AP3_C_PROJECT_CHARACTER_H
#define AP3_C_PROJECT_CHARACTER_H

#endif //AP3_C_PROJECT_CHARACTER_H

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

Character * createCharacter(int hp_max, int hp, int def, int dmg, int key, int potion);
void char_decrement_hp(Character * player, int delta);
void char_increment_hp(Character * player, int delta);

Enemy * createEnemy(int hp, int def, int dmg, int isDead);
void enemy_decrement_hp(Enemy * enemy, int delta);
void enemy_increment_hp(Enemy * enemy, int delta);