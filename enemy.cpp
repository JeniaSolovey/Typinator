#include "enemy.h"

Enemy::Enemy()
{
    setPixmap(QPixmap(":/res/img/simpleEnemyShip.png").scaled(60,100));
}
