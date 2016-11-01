#include "player.h"
#include "bullet.h"
#include <QPixmap>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QString>
#include <QPointF>
#include <enemy.h>

Player::Player(): QGraphicsPixmapItem()
{
    bulletTimer = new QTimer();
    bulletTimer->start(10);

    score = 0;
    Aim =false;
    setPixmap(QPixmap(":/res/img/playerShip.png").scaled(120,100));
}

void Player::Shot(QPointF target)
{
    bullet = new Bullet(target);
    connect(bulletTimer, SIGNAL(timeout()), bullet, SLOT(move()));
    bullet->setPos(pos().x()+pixmap().width()/2 - bullet->pixmap().width()/2, pos().y());
    bullet->Throw();
    scene()->addItem(bullet);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (Aim) emit AimShot(event->key());
    if (!Aim) emit Throw(event->key());
}

void Player::Hit(QPointF pos)
{
    Aim=true;
    Shot(pos);
    score ++;
}

void Player::Kill()
{
    Aim = false;
}
