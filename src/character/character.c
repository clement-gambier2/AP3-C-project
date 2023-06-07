
#include "character.h"

/**
 * Used to create a new playable character
 * @param hp_max - Maximum health points for the player
 * @param hp - Health points of the player
 * @param def - Defense points of the player
 * @param dmg - Damage points of the player
 * @param key - Number of keys detained by the player
 * @param potion - Number of potions detained by the player
 * @param pos_x - Position on x of the character
 * @param pos_y - Position on y of the character
 * @return Character *
 */
struct Character * createCharacter(int hp_max, int hp, int def, int dmg, int key,int name){
    struct Character *newCharacter = (struct Character *) malloc(sizeof(struct Character));
    newCharacter->hp_max = hp_max;
    newCharacter->hp = hp;
    newCharacter->def = def;
    newCharacter->dmg = dmg;
    newCharacter->key = key;
    newCharacter->pos_x = 15;
    newCharacter->pos_y = 15;
    newCharacter->name = name;
    return newCharacter;
}

 /**
  * Used to create a new enemy
  * @param hp - Health points for the enemy
  * @param def - Defense points of the enemy
  * @param dmg - Damage points of the enemy
  * @param isDead - Indicator if the enemy is alive
  * @param pos_x - Position x of the enemy
  * @param pos_y - Position y of the enemy
  * @return struct Enemy_ *
  */
struct Enemy_ *createEnemy(int hp, int def, int dmg, int isDead, int pos_x, int pos_y) {
    struct Enemy_ *newEnemy = (struct Enemy_ *) malloc(sizeof(struct Enemy_));
    newEnemy->hp = hp;
    newEnemy->def = def;
    newEnemy->dmg = dmg;
    newEnemy->isDead = isDead;
    newEnemy->pos_x = pos_x;
    newEnemy->pos_y = pos_y;
    newEnemy->next = NULL;
    newEnemy->previous = NULL;
    return newEnemy;
}

/**
 * Used to add an enemy in the list of enemy
 * @param enemyAdd - Enemy to add in the list
 * @param myEnemy - Enemy already in the list
 */
void addEnemy(struct Enemy_ *enemyAdd, struct Enemy_ *myEnemy) {
    if (myEnemy == NULL) {
        printf("error");
        return;
    }
    while (myEnemy->next != NULL) {
        myEnemy = myEnemy->next;
    }

    myEnemy->next = enemyAdd;
    enemyAdd->previous = myEnemy;
}

/**
 * Used to create a list of all enemies in the matrix
 * @param map - Map to get the value of enemies and the matrix
 * @return struct Enemy_ *
 */
struct Enemy_ *saveEnemyFromMap(struct Map *map) {
    int cpt = 0;
    char **matrix = map->matrix;
    struct Enemy_ *enemy;
    struct Enemy_ *enemyTmp;
    for (int i = 0; i < 30; i++)//for each line of the file
    {
        for (int y = 0; y < 30; y++)//for each column of the file
        {
            if (matrix[i][y] == 'A') {
                if (cpt == 0) {
                    enemy = createEnemy(map->A_Pv, map->A_Armure, map->A_Force, 0, i, y);
                    cpt += 1;
                }
                else{
                    enemyTmp = createEnemy(map->A_Pv, map->A_Armure, map->A_Force, 0, i, y);
                    addEnemy(enemyTmp, enemy);
                    cpt += 1;
                }
            }
            if (matrix[i][y] == 'B') {
                if (cpt == 0) {
                    enemy = createEnemy(map->B_Pv, map->B_Armure, map->B_Force, 0, i, y);
                    cpt += 1;
                }
                else{
                    enemyTmp = createEnemy(map->B_Pv, map->B_Armure, map->B_Force, 0, i, y);
                    addEnemy(enemyTmp, enemy);
                    cpt += 1;
                }
            }
            if (matrix[i][y] == 'C') {
                if (cpt == 0) {
                    enemy = createEnemy(map->C_Pv, map->C_Armure, map->C_Force, 0, i, y);
                    cpt += 1;
                }
                else{
                    enemyTmp = createEnemy(map->C_Pv, map->C_Armure, map->C_Force, 0, i, y);
                    addEnemy(enemyTmp, enemy);
                    cpt += 1;
                }
            }
        }
    }
    return enemy;
}

/**
 * Used to get enemy in the list, at the position given
 * @param enemy
 * @param pos_x
 * @param pos_y
 * @return struct Enemy_ *
 */
struct Enemy_ *getEnemyByPosition(struct Enemy_ *enemy, int pos_x, int pos_y) {
    if (enemy == NULL) {
        printf("error");
    }
    while (enemy->previous != NULL) {
        enemy = enemy->previous;
    }
    while (enemy != NULL) {
        if (enemy->pos_x == pos_x && enemy->pos_y == pos_y) {
            return enemy;
        }
        enemy = enemy->next;
    }
    return NULL;
}

/**
 * Used to reduce Health Points for a character
 * @param player - The player
 * @param delta - The amount of Health Points to remove
 */
void char_decrement_hp(struct Character* player, int delta) {
    player->hp -= delta;
}


/**
 * Used to reduce Health Points for an enemy
 * @param enemy - The enemy
 * @param delta - The amount of Health Points to remove
 */
void enemy_decrement_hp(struct Enemy_ *enemy, int delta) {
    enemy->hp -= delta;
    if (enemy->hp <= 0) {
        enemy->isDead = 1;
    }
}


int get_hearts(struct Character *character) {
    int num_hearts = character->hp / 1;
    return num_hearts;
}

int get_def(struct Character *character) {
    int num_def = character->def / 1;
    return num_def;
}

int get_dmg(struct Character *character) {
    int num_dmg = character->dmg / 1;
    return num_dmg;
}

/**
 * isMovePossible check if the move is possible
 * @param x - Position x you want to go
 * @param y - Position y you want to go
 * @param map - The matrix in wich you want to move
 * @param enemy - An enemy from the list, to access all enemies
 * @param character - The player
 * @return 0 if the move is possible, 1 otherwise
 */
int isMovePossible(int x, int y, char **map, struct Enemy_ *enemy, struct Character *character) {
    if (x < 0 || x > 29 || y < 0 || y > 29) {
        return 1;
    }
    if (map[y][x] == '#') {
        return 1;
    }
    if(map[y][x] == 'o'){
        if (character->key > 0){
            character->key -= 1;
            map[y][x] = 'i';
            return 0;
        }
        return 1;
    }
    if (map[y][x] == 'A' || map[y][x] == 'B' || map[y][x] == 'C') {
        struct Enemy_ *enemyToFight = getEnemyByPosition(enemy, y, x);//voir si faut pas inverser
        if(enemyToFight!=NULL) {
            if (enemyToFight->isDead == 1) {
                return 0;
            } else {
                int tmp = fight(character, enemyToFight);
                if (tmp == 0) {
                    return 1;
                }
                else {
                    enemyToFight->isDead = 1;
                    return 1;
                }
            }
        }
        else{
            return 1;
        }
    }
    return 0;
}


void isThereAKey(struct Character * character, struct Map * map){
    if(map->matrix[character->pos_y][character->pos_x] == '!'){
        character->key += 1;
        map->matrix[character->pos_y][character->pos_x] = ' ';
    }
}

void isThereAPotionDamage(struct Character * character, struct Map * map){
    if(map->matrix[character->pos_y][character->pos_x] == '1'){
        PowerUp powerUp;
        powerUp.powerUp = DAMAGE;
        powerUp.powerValue = DAMAGE_POWER_VALUE;
        apply_power_up(&powerUp, character);
        map->matrix[character->pos_y][character->pos_x] = ' ';
    }
}

void isThereAPotionDefense(struct Character * character, struct Map * map){
    if(map->matrix[character->pos_y][character->pos_x] == '2'){
        PowerUp powerUp;
        powerUp.powerUp = DEFENSE;
        powerUp.powerValue = DEFENSE_POWER_VALUE;
        apply_power_up(&powerUp, character);
        map->matrix[character->pos_y][character->pos_x] = ' ';
    }
}

void isThereAPotionHPMax(struct Character * character, struct Map * map){
    if(map->matrix[character->pos_y][character->pos_x] == '3'){
        PowerUp powerUp;
        powerUp.powerUp = HP_MAX;
        powerUp.powerValue = HP_MAX_POWER_VALUE;
        apply_power_up(&powerUp, character);
        map->matrix[character->pos_y][character->pos_x] = ' ';
    }
}

void isThereAPotionHeal(struct Character * character, struct Map * map){
    if(map->matrix[character->pos_y][character->pos_x] == 'p'){
        use_potion(character);
        map->matrix[character->pos_y][character->pos_x] = ' ';
    }
}

/**
 * Used to moveRight the character
 * @param - The character
 * @param map - The map with the infos you want
 * @return
 */
char * moveRight(struct Character * character,struct Map * map){
    //switch map : we are in moveRight so if there is a level it's the EAST one so first cell of the direction array
    if(map->matrix[character->pos_y][character->pos_x] == '?'){
        if(character->pos_x == 29){
            character->pos_x = 0;
            character->pos_y = 14;
            return map->directions[0];
        }

    }
    if (isMovePossible(character->pos_x+1, character->pos_y, map->matrix, map->enemy, character) == 0) {
        character->pos_x += 1;
        isThereAKey(character, map);
        isThereAPotionDamage(character, map);
        isThereAPotionDefense(character, map);
        isThereAPotionHPMax(character, map);
        isThereAPotionHeal(character, map);
    }
    return "noSwitch";
}

/**
 * Used to moveBottom the character
 * @param - The character
 * @param map - The map with the infos you want
 * @return
 */
char * moveBottom(struct Character * character, struct Map * map){
    //switch map : we are in moveBottom so if there is a level it's the SOUTH one so second cell of the direction array
    if(map->matrix[character->pos_y][character->pos_x] == '?'){
        if(character->pos_y == 29){
            character->pos_x = 15;
            character->pos_y = 0;;
            return map->directions[1];
        }
    }
    if (isMovePossible(character->pos_x, character->pos_y+1,map->matrix, map->enemy, character) == 0) {
        character->pos_y += 1;
        isThereAKey(character, map);
        isThereAPotionDamage(character, map);
        isThereAPotionDefense(character, map);
        isThereAPotionHPMax(character, map);
        isThereAPotionHeal(character, map);
    }

    return "noSwitch";
}

/**
 * moveLeft
 * @param character
 * @param map
 * @return
 */
char * moveLeft(struct Character * character,struct Map * map){
    //switch map : we are in moveLeft so if there is a level it's the WEST one so third cell of the direction array
    if(map->matrix[character->pos_y][character->pos_x] == '?'){
        if(character->pos_y == 14 && character->pos_x == 0){
            character->pos_x = 29;
            character->pos_y = 14;
            return map->directions[2];
        }
    }
    if (isMovePossible(character->pos_x-1, character->pos_y,map->matrix, map->enemy, character) == 0){
        character->pos_x-=1;
        isThereAKey(character, map);
        isThereAPotionDamage(character, map);
        isThereAPotionDefense(character, map);
        isThereAPotionHPMax(character, map);
        isThereAPotionHeal(character, map);
    }
    return "noSwitch";

}

/**
 * moveTop
 * @param character
 * @param map
 * @return
 */
char * moveTop(struct Character * character,struct Map * map){
    //switch map : we are in moveTop so if there is a level it's the NORTH one so fourth cell of the direction array
    if(map->matrix[character->pos_y][character->pos_x] == '?'){
        if(character->pos_y == 0){
            character->pos_x = 15;
            character->pos_y = 29;;
            return map->directions[3];
        }
    }
    if (isMovePossible(character->pos_x, character->pos_y-1,map->matrix, map->enemy, character) == 0) {
        character->pos_y -= 1;
        isThereAKey(character, map);
        isThereAPotionDamage(character, map);
        isThereAPotionDefense(character, map);
        isThereAPotionHPMax(character, map);
        isThereAPotionHeal(character, map);
    }
    return "noSwitch";
}
