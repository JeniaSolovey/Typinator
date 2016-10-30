#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>

class Player: public QGraphicsPixmapItem
{
public:
    Player();
    void Shot(QPoint target);
    void keyPressEvent(QKeyEvent *event);
};

#endif // PLAYER_H
