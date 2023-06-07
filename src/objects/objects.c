#include "objects.h"

/**
 * Used to apply a power up on the character
 * @param powerUp - Generic powerup with an enum
 * @param character - The character to powerUp
 */
void apply_power_up(PowerUp * powerUp, struct Character * character) {
    printf("PowerUp: %d\n", powerUp->powerValue);
    switch (powerUp->powerUp) {
        case DAMAGE:
            character->dmg += powerUp->powerValue;
            break;
        case DEFENSE:
            character->def += powerUp->powerValue;
            break;
        case HP_MAX:
            character->hp_max += powerUp->powerValue;
            break;
    }
}

/**
 * Used to heal the player with a potion
 * @param character - The character
 */
void use_potion(struct Character * character) {
        character->hp = character->hp_max;
}