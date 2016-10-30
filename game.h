#ifndef GAME_H
#define GAME_H

#include "controller.h"
#include <QGraphicsView>

class Game: public QGraphicsView
{
private:
    Controller *controller;
public:
    Game(QWidget *parent = 0);
    QGraphicsScene * scene;
};

#endif // GAME_H
