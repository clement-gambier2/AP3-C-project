#ifndef AP3_C_PROJECT_OBJECTS_H
#define AP3_C_PROJECT_OBJECTS_H

#endif //AP3_C_PROJECT_OBJECTS_H

#include "Character.h"

enum powerUp {
    DAMAGE, DEFENSE, HP_MAX
};

struct PowerUp_ {
    enum powerUp powerUp;
    int powerValue;
} typedef PowerUp;

void apply_power_up(PowerUp * powerUp, Character * character);
void decrement_potion(Character * character);
void increment_potion(Character * character);
void use_potion(Character * character);
void decrement_key(Character * character);
void increment_key(Character * character);
int can_open_door(Character * character);