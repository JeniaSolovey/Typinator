#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QString>
#include <QPointF>
#include "word.h"

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bool inFocus;
    Word* word;

    Enemy(QString word);
    void setRandomPosition();
public slots:
    void move();
    void checkHit(char key);
    void checkAimHit(char key);
signals:
    void hurt(QPointF pos);
    void kick();
};

#endif // ENEMY_H
