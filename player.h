#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    int lives;
    bool Aim;
    Player();
    void Shot(QPointF target);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void Hit(QPointF pos);
    void Kill();
signals:
    void Throw(char key);
    void AimShot(char key);
};

#endif // PLAYER_H
