#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "bullet.h"
#include <QTimer>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    int lives;
    int score;
    bool Aim;
    QTimer *bulletTimer;

    Bullet *bullet;

    Player();
    void Shot(Enemy *target);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void Hit(Enemy* enemyPos);
    void Kill();
signals:
    void Throw(char key);
    void AimShot(char key);
};

#endif // PLAYER_H
