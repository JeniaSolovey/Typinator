#include "player.h"
#include "bullet.h"
#include <QPixmap>
#include <QGraphicsScene>

Player::Player(): QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/res/img/playerShip.png").scaled(120,100));
}

void Player::Shot(QPoint target)
{
    Bullet *bullet = new Bullet(target);
    bullet->setPos(pos().x()+pixmap().width()/2 - bullet->pixmap().width()/2, pos().y());
    bullet->Throw();
    scene()->addItem(bullet);
}

void Player::keyPressEvent(QKeyEvent *event)
{

    Shot(QPoint(0,0));
}
