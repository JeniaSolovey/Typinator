#include "enemy.h"

Enemy::Enemy()
{
    setPixmap(QPixmap(":/img/ships/res/img/simpleEnemyShip.png").scaled(60,100));
}
