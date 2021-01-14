//
// Created by georgiana on 23.11.2020.
//

#include "headers/Enemy.h"

///constructor of enemy class with specific atributes
Enemy::Enemy(int h, int s, std::string sprite) {
    this->health=h;
    this->speed=s;
    sprintName=sprite;
    std::string path="/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/";
    QPixmap pix(QString::fromStdString(path.append(sprintName)));
    this->setPixmap(pix.scaled(70, 70, Qt::KeepAspectRatio));
}

///level 1 -> general type of enemy
///will require alterations on values along the way
Enemy::Enemy() {
    health=2;
    speed=1;
    QPixmap pix("/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/enemy.png");
    this->setPixmap(pix.scaled(70, 70, Qt::KeepAspectRatio));
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
    this->x=x;
    this->y=y;
}


///returns the name of the sprite. does not include the path to the root directory
std::string Enemy::getFilename() {
    return sprintName;
}


///constructor using the base class parameters
Enemy::Enemy(const QPixmap &pixmap, QGraphicsItem *parent) : QGraphicsPixmapItem(pixmap.scaled(70, 70, Qt::KeepAspectRatio), parent)
{
    health=2;
    speed=1;
    sprintName="/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/enemy.png";
}

void Enemy::getNextMovement(int *tile, int x, int y) {
}


///slot override - called by the graphicscene at every timeout by the signal advance()
void Enemy::advance(int phase) {
    int currentTile=0;
    getNextMovement(&currentTile, x, y);
//    std::cout<<currentTile;
    switch(currentTile)
    {
        case 1:
        case 3:

            setPos(QPointF(x*70,y*70));
//            if(x*70+15>(x+1)*70)
            x++;
            break;
        case 6:
            y++;
            setPos(QPointF(x*70,y*70-20));
            break;
        case 7:
            y--;
            setPos(QPointF(x*70,y*70+20));
            break;
        case 8:
            x--;
            setPos(QPointF(x*70,y*70));
            break;
        case 4:
//            std::cout<<"I WON";
            won();
        default:
            break;
    }

}

///signal
void Enemy::won() {

}





