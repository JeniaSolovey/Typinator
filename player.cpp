#include "player.h"
#include <QPixmap>

Player::Player(): QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/res/img/playerShip.png").scaled(120,100));
}
