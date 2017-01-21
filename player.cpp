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

    shotSound = new QMediaPlayer();
    shotSound->setMedia(QUrl("qrc:/res/sound/shot_sound.wav"));
}

void Player::Shot(Enemy* target)
{
    bullet = new Bullet(target);
    connect(bulletTimer, SIGNAL(timeout()), bullet, SLOT(move()));
    bullet->setPos(pos().x()+pixmap().width()/2 - bullet->pixmap().width()/2, pos().y());
    bullet->Throw();
    scene()->addItem(bullet);

    shotSound->play();
    if (shotSound->PlayingState == QMediaPlayer::PlayingState)
    { shotSound->setPosition(0);  }

}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (Aim) emit AimShot(event->key());
    if (!Aim) emit Throw(event->key());
}

void Player::Hit(Enemy *enemyPos)
{
    Aim=true;
    Shot(enemyPos);
    score ++;
}

void Player::Kill()
{
    Aim = false;
}
