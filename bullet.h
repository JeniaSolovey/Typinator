#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <enemy.h>

class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    Enemy *target;
public:
    Bullet(Enemy* target);
    void Throw();
private slots:
    void move();
};

#endif // BULLET_H
