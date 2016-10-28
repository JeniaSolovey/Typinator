#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
class Game: public QGraphicsView
{
public:
    Game(QWidget *parent = 0);
    QGraphicsScene * scene;
};

#endif // GAME_H
