#ifndef OBJECTS_H
#define OBJECTS_H



#include "character.h"
#include "inventory.h"

enum powerUp {
    DAMAGE, DEFENSE, HP_MAX
};

typedef struct PowerUp_ {
    enum powerUp powerUp;
    int powerValue;
} PowerUp;

void apply_power_up(PowerUp * powerUp, Character * character);
void decrement_potion(Character * character);
void increment_potion(Character * character);
void use_potion(Character * character);
void decrement_key(Character * character, SDL_Renderer* renderer);
void increment_key(Character * character, SDL_Renderer* renderer);
int can_open_door(Character * character);

#endif //OBJECTS_H