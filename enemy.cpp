#include "enemy.h"
#include <QLineF>
#include <QPointF>
#include <QGraphicsScene>
#include <qmath.h>
#include <QTimer>

Enemy::Enemy(QString word)
{
    setPixmap(QPixmap(":/res/img/simpleEnemyShip.png").scaled(60,100));

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(move()));
    timer->start(40);

    this->word = new Word(word, this);
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

    scene()->addItem(this->word);
}

void Enemy::move()
{
    double STEP_SIZE = 2;
    double angle = rotation()+90;

    double dy = STEP_SIZE * qSin(qDegreesToRadians(angle));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(angle));

    setPos(x()+dx, y()+dy);
}
