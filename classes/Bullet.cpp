//
// Created by georgiana on 26.11.2020.
//

#include "../headers/Bullet.h"

Bullet::Bullet() {
    damagePower = 1;
    spriteName = "cash.png";
    speed = 1;
}

Bullet::Bullet(int d, string sprite, int s) {
    damagePower = d;
    spriteName = sprite;
    speed = s;
}

int Bullet::getDamagePower() {
    return damagePower;
}

int Bullet::getSpeed() {
    return speed;
}

string Bullet::getFilename() {
    return spriteName;
}
