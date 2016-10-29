#include "game.h"
#include "player.h"

Game::Game(QWidget * parent)
{
    //view settings
    setFixedSize(800, 600);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //scene settings
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,this->width(), this->height());
    setScene(scene);

    Player *player = new Player();
    player->setPos(width()/2-player->pixmap().width()/2, height()-player->pixmap().height());
    scene->addItem(player);

}
