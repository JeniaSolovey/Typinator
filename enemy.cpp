#include "enemy.h"
#include <QLineF>
#include <QPointF>
#include <QGraphicsScene>

Enemy::Enemy()
{
    setPixmap(QPixmap(":/res/img/simpleEnemyShip.png").scaled(60,100));
}

void Enemy::setRandomPosition()
{
    int maxPosibleXPosition = scene()->width()- pixmap().width();
    int randomPositionX = qrand()% maxPosibleXPosition;
    setPos(randomPositionX, 0);
    setTransformOriginPoint(pixmap().width()/2, pixmap().height()/2);

    QLineF ln(mapToScene(transformOriginPoint()), QPointF(scene()->width()/2, scene()->height()));
    int angle = -1 * ln.angle()+270;

    setRotation(angle);
}
