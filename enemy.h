#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();
};

#endif // ENEMY_H
