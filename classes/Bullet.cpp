//
// Created by georgiana on 26.11.2020.
//

#include "../headers/Bullet.h"
#include "../headers/Includes.h"


Bullet::~Bullet() {
   
}
Bullet::Bullet() {
    damagePower=1;
    spriteName="images/Bullet_Cannon1.png";
    speed=1;
    currentX = -1, currentY = -1;
    
    bullettime = 0;
    stoppingPoint = 0;
}

Bullet::Bullet(int d, string sprite, int s) {
    damagePower=d;
    spriteName=sprite;
    speed=s;
    currentX = -1, currentY = -1;
    stoppingPoint = 0;
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

void Bullet::towerPos(int x, int y)
{
    this->towerX = x;
    this->towerY = y;
}


void Bullet::getTargetLocation(int x, int y)
{
    this->enemyX = x;
    this->enemyY = y;
    bulletTime = new QTimer();
    connect(bulletTime, &QTimer::timeout, this, &Bullet::advance);
    bulletTime->start(25);
}

void Bullet::enemyDamaged(int x, int y)
{
}


void Bullet::advance()
{
    
    if (bullettime == 0) {
        setPos(QPointF(towerX * 70 + 35, towerY * 70 + 35));
        bulletX = towerX * 70 + 35;
        bulletY = towerY * 70 + 35;
    }else if(bulletX/70 != enemyX || bulletY/70 != enemyY)
    {
        int ex = bulletX / 70 ;
        int ey = bulletY / 70 ;
    	
		if (abs(currentX / 70 - ex) <= 1 && abs(currentY / 70 - ey)<=1)
		{
            stoppingPoint++;
            if (stoppingPoint >= 6) {
                bulletTime->stop();
                bullettime = -1;
                enemyDamaged(currentX/70, currentY/70);
                currentX = -1, currentY = -1;
                stoppingPoint = 10;
                
            }
		}
    	if (enemyX > ex && stoppingPoint!=10)
        {
            if (enemyY < ey) // sus-dreapta
            {
                setPos(QPointF(towerX * 70 + bullettime * 10 + 25, towerY * 70 - bullettime * 10 + 25));
                QPixmap pix("images/Bullet_Cannon2.png");
                currentX = towerX * 70 + bullettime * 10 + 25;
                currentY = towerY * 70 - bullettime * 10 + 25;
                this->setPixmap(pix.scaled(20, 30, Qt::KeepAspectRatio));
            }
            else if (enemyY == ey) // dreapta
            {
                setPos(QPointF(towerX * 70 + bullettime * 10 + 45, towerY * 70 + 25));
                QPixmap pix("images/Bullet_Cannon3.png");
                currentX = towerX * 70 + bullettime * 10 + 45;
                currentY = towerY * 70+25;
                this->setPixmap(pix.scaled(20, 30, Qt::KeepAspectRatio));
            }
            else { //jos-dreapta
                setPos(QPointF(towerX * 70 + bullettime * 10 + 35, towerY * 70 + bullettime * 10 + 35));
                QPixmap pix("images/Bullet_Cannon4.png");
                currentX = towerX * 70 + bullettime * 10 + 35;
                currentY = towerY * 70 + bullettime * 10 + 35;
                this->setPixmap(pix.scaled(20, 30, Qt::KeepAspectRatio));
            }
        }
        else if (enemyX == ex && stoppingPoint!=10) //centru
        {
            if (enemyY < ey) //sus
            {
                setPos(QPointF(towerX * 70 + 25, towerY * 70 - bullettime * 10 + 25));
                QPixmap pix("images/Bullet_Cannon1.png");
                currentX = towerX * 70 + 25;
                currentY = towerY * 70 - bullettime * 10 + 25;
                this->setPixmap(pix.scaled(20, 30, Qt::KeepAspectRatio));
            }
            else if (enemyY > ey) { //jos
                setPos(QPointF(towerX * 70 + 25, towerY * 70 + bullettime * 10 + 45));
                QPixmap pix("images/Bullet_Cannon5.png");
                currentX = towerX * 70 + 25;
                currentY = towerY * 70 + bullettime * 10 + 45;
                this->setPixmap(pix.scaled(20, 30, Qt::KeepAspectRatio));
            }
        }
        else if (enemyX < ex && stoppingPoint!=10) //stanga
        {
            if (enemyY < ey) // sus-stanga
            {
                setPos(QPointF(towerX * 70 - bullettime * 10 + 35, towerY * 70 - bullettime * 10 + 35));
                QPixmap pix("images/Bullet_Cannon8.png");
                currentX = towerX * 70 - bullettime * 10 + 35;
                currentY = towerY * 70 - bullettime * 10 + 35;
                this->setPixmap(pix.scaled(20, 30, Qt::KeepAspectRatio));
            }
            else if (enemyY == ey) // stanga
            {
                setPos(QPointF(towerX * 70 - bullettime * 10 + 25, towerY * 70 + 25));
                QPixmap pix("images/Bullet_Cannon7.png");
                currentX = towerX * 70 - bullettime * 10 + 25;
                currentY = towerY * 70 + 25;
                this->setPixmap(pix.scaled(20, 30, Qt::KeepAspectRatio));
            }
            else {//jos-stanga
                setPos(QPointF(towerX * 70 - bullettime * 10 + 25, towerY * 70 + bullettime * 10 + 30));
                QPixmap pix("images/Bullet_Cannon6.png");
                currentX = towerX * 70 - bullettime * 10 + 25;
                currentY = towerY * 70 + bullettime * 10 + 30;
                this->setPixmap(pix.scaled(20, 30, Qt::KeepAspectRatio));
            }

        }
        
    }
	bullettime++;
}



