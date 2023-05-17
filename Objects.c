#include "Objects.h"

/**
 * Used to apply a power up on the character
 * @param powerUp - Generic powerup with an enum
 * @param character - The character to powerUp
 */
void apply_power_up(PowerUp * powerUp, Character * character) {
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
 * Used to decrement the number of player's potions by one
 * @param character - The character
 */
void decrement_potion(Character * character) {
    character->potion -= 1;
}

/**
 * Used to increment the number of player's potions by one
 * @param character - The character
 */
void increment_potion(Character * character) {
    character->potion += 1;
}

/**
 * Used to heal the player with a potion
 * @param character - The character
 */
void use_potion(Character * character) {
    if (character->potion > 0) {
        character->hp = character->hp_max;
        decrement_potion(character);
    }
}

/**
 * Used to decrement the number of player's key
 * @param character - The character
 */
void decrement_key(Character * character) {
    character->key -= 1;
}

/**
 * Used to increment the number of player's key
 * @param character - The character
 */
void increment_key(Character * character) {
    character->key += 1;
}

/**
 * Check if the player has at least on key to open a door
 * @param character - The character
 * @return 1 - 0
 */
int can_open_door(Character * character) {
   return character->key > 0;
}