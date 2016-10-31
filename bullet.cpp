#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <qmath.h>
#include <QGraphicsScene>

Bullet::Bullet(QPointF target)
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
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){

            Enemy *enemy = static_cast<Enemy*> (colliding_items[i]);
            if(enemy->word->toPlainText().size() > 2)
            {
                enemy->word->VisualRemoveFirstCharacter();
                scene()->removeItem(this);
                delete this;
                return;
            }

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;
            return;
        }
    }


    double STEP_SIZE = 20;
    double angleToTarget = rotation();

    double dy = STEP_SIZE * qSin(qDegreesToRadians(angleToTarget));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(angleToTarget));

    setPos(x()+dx, y()+dy);
}
