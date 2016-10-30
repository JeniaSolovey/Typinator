#include "bullet.h"
#include <QTimer>
#include <qmath.h>

Bullet::Bullet(QPoint target)
{
    this->target = target;
    setPixmap(QPixmap(":/res/img/redBullet.png"));
}

void Bullet::Throw()
{
    setTransformOriginPoint(pixmap().width()/2, pixmap().height()/2);

    QLineF ln(mapToScene(transformOriginPoint()), target);
    int angle =-1* ln.angle();
    setRotation(angle);

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(10);
}

void Bullet::move()
{
    double STEP_SIZE = 10;
    double angleToTarget = rotation();

    double dy = STEP_SIZE * qSin(qDegreesToRadians(angleToTarget));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(angleToTarget));

    setPos(x()+dx, y()+dy);
}
