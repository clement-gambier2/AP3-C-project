#ifndef OBJECTS_H
#define OBJECTS_H


#include "../character/character.h"
#include "../inventory/inventory.h"

enum powerUp {
    DAMAGE,
    DEFENSE,
    HP_MAX
};

typedef struct PowerUp_ {
    enum powerUp powerUp;
    int powerValue;
} PowerUp;

// Définition des valeurs de powerValue pour chaque type de power-up
#define DAMAGE_POWER_VALUE 1
#define DEFENSE_POWER_VALUE 1
#define HP_MAX_POWER_VALUE 3

void apply_power_up(PowerUp * powerUp, struct Character * character);
void use_potion(struct Character * character);

#endif //OBJECTS_H
