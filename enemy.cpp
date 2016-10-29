#include "enemy.h"
#include <QLineF>
#include <QPointF>
#include <QGraphicsScene>
#include <qmath.h>
#include <QTimer>
Enemy::Enemy()
{
    setPixmap(QPixmap(":/res/img/simpleEnemyShip.png").scaled(60,100));

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(move()));
    timer->start(30);
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

void Enemy::move()
{
    double STEP_SIZE = 1;
    double angle = rotation()+90;

    double dy = STEP_SIZE * qSin(qDegreesToRadians(angle));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(angle));

    setPos(x()+dx, y()+dy);
}
