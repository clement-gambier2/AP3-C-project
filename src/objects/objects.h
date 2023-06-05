#ifndef OBJECTS_H
#define OBJECTS_H



#include "../character/character.h"
#include "../inventory/inventory.h"

enum powerUp {
    DAMAGE, DEFENSE, HP_MAX
};

typedef struct PowerUp_ {
    enum powerUp powerUp;
    int powerValue;
} PowerUp;

void apply_power_up(PowerUp * powerUp, struct Character * character);
void decrement_potion(struct Character * character);
void increment_potion(struct Character * character);
void use_potion(struct Character * character);
void decrement_key(struct Character * character);
void increment_key(struct Character * character);
int can_open_door(struct Character * character);

#endif //OBJECTS_H