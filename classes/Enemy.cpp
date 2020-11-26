//
// Created by georgiana on 23.11.2020.
//

#include "../headers/Enemy.h"

//todo niste enum-uri sau ceva pentru diferite clase de inamici ca sa fie mai usor de creat?

Enemy::Enemy(int h, int s) {
    this->health=h;
    this->speed=s;
}

///level 1 -> general type of enemy
///will require alterations on values along the way
Enemy::Enemy() {
    health=2;
    speed=1;
}

///lower the health of the enemy
void Enemy::TakeDamage(int damage) {
    health-=damage;
    if(health<=0)
        die();
}

///getter for the health attribute
int Enemy::getHealth() {
    return health;
}

//todo
///ar trebui sa arate ca nu mai trebuie randat pe harta? idk
///sets alive flag on false. enemy ready to be destroyed
void Enemy::die() {
    //alive=false
}

/*
 * // vine waveul
 * int nrinamici = wave[0].length;
 *
 * if(enemy.health == 0)
 * enemy.die();
 * nrinamici--;
 * 
 */



