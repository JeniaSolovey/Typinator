#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QString>
#include "word.h"

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Word* word;

    Enemy(QString word);
    void setRandomPosition();
public slots:
    void move();
};

#endif // ENEMY_H
