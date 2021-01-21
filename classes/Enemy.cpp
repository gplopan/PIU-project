//
// Created by georgiana on 23.11.2020.
//

#include "../headers/Enemy.h"

///constructor of enemy class with specific atributes
Enemy::Enemy(int h, int s, std::string sprite) {
    this->health = h;
    this->speed = s;
    sprintName = sprite;
    std::string path = "images/";
    QPixmap pix(QString::fromStdString(path.append(sprintName).append("_p_0.png")));
    this->setPixmap(pix.scaled(70, 70, Qt::KeepAspectRatio));
    sprintCount = 0;
}

///level 1 -> general type of enemy
///will require alterations on values along the way
Enemy::Enemy() {
    health = 2;
    speed = 1;
    sprintName = "enemy_1";
    QPixmap pix("images/enemy_1_p_0.png");
    this->setPixmap(pix.scaled(70, 70, Qt::KeepAspectRatio));
    sprintCount = 0;
}

///lower the health of the enemy
void Enemy::TakeDamage(int damage) {
    health -= damage;
    if (health <= 0)
        die();
}

///getter for the health attribute
int Enemy::getHealth() {
    return health;
}

//todo the logic behind it
///ar trebui sa arate ca nu mai trebuie randat pe harta? idk
///sets alive flag on false. enemy ready to be destroyed
void Enemy::die() {
    //alive=false
}

///x coordinate of the enemy
int Enemy::getX() {
    return x;
}

/// y coordinate of the enemy
int Enemy::getY() {
    return y;
}


/// set the (x, y). not recommended except for the init stage of the level
void Enemy::setCoordinates(int x, int y) {
    this->x = x;
    this->y = y;
}


///returns the name of the sprite. does not include the path to the root directory
std::string Enemy::getFilename() {
    return sprintName;
}


///constructor using the base class parameters
Enemy::Enemy(const QPixmap& pixmap, QGraphicsItem* parent) : QGraphicsPixmapItem(pixmap.scaled(70, 70, Qt::KeepAspectRatio), parent)
{
    health = 2;
    speed = 1;
    sprintName = "images/enemy.png";
}

void Enemy::getNextMovement(int* tile, int x, int y) {
}
void Enemy::sendLocationToTower(int x, int y){
}


///slot override - called by the graphicscene at every timeout by the signal advance()
void Enemy::advance(int phase) {

    int currentTile = 0;
    getNextMovement(&currentTile, x, y);
    sendLocationToTower(x, y);
    switch (currentTile)
    {
    case 3:
        posx = 70 * x;
        posy = 70 * y;
        setPos(QPointF(posx + 70, posy));
        x++;
        break;
    case 1:
        //            setPos(QPointF(x*70,y*70));
        posx += 15;
        setPos(QPointF(posx, posy));
        if (posx >= (x + 1) * 70) {
            x++;
            posx = x * 70;
        }

        break;
    case 6:
        //            y++;
        //            setPos(QPointF(x*70,y*70-20));
        posy += 20;
        setPos(QPointF(posx, posy));
        if (posy >= (y + 1) * 70) {
            y++;
            posy = y * 70;
        }
        break;
    case 7:
        //            y--;
        //            setPos(QPointF(x*70,y*70+20));
        posy -= 15;
        setPos(QPointF(posx, posy));
        if (posy <= (y - 1) * 70) {
            y--;
            posy = y * 70;
        }
        break;
    case 8:
        //            x--;
        //            setPos(QPointF(x*70,y*70));
        posx -= 15;
        setPos(QPointF(posx, posy));
        if (posx <= (x - 1) * 70) {
            x--;
            posx = x * 70;
        }
        break;
    case 4:
        //            std::cout<<"I WON";
        won();
    
    default:
        break;
    }
    sprintCount = (sprintCount + 1) % 7;
    std::string path = "images/";
    path.append(sprintName + "_p_" + std::to_string(sprintCount) + ".png");
    QPixmap pix(QString::fromStdString(path));
    setPixmap(pix.scaled(70, 70, Qt::KeepAspectRatio));

}

///signal
void Enemy::won() {

}

void Enemy::enemyDamaged(int x, int y)
{
	if(x == this->getX() && y == this->getY())
		TakeDamage(1);
}




