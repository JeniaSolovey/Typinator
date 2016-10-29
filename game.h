#ifndef GAME_H
#define GAME_H

#include "spawner.h"
#include <QGraphicsView>

class Game: public QGraphicsView
{
private:
    Spawner *spawner;
public:
    Game(QWidget *parent = 0);
    QGraphicsScene * scene;
};

#endif // GAME_H
