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
    Aim =false;
    setPixmap(QPixmap(":/res/img/playerShip.png").scaled(120,100));
}

void Player::Shot(QPointF target)
{
    Bullet *bullet = new Bullet(target);
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
}

void Player::Kill()
{
    Aim = false;
}
