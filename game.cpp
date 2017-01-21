#include "game.h"
#include "player.h"
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaPlaylist>

Game::Game(QWidget * parent)
{
    //view settings
    setFixedSize(800, 600);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //scene settings
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,this->width(), this->height());
    scene->setBackgroundBrush(QBrush(QPixmap(":/res/img/space.png").scaled(width(),height())));
    setScene(scene);

    Player *player = new Player();
    player->setPos(width()/2-player->pixmap().width()/2, height()-player->pixmap().height());
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);


    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/res/sound/background.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *mediaPlayer = new QMediaPlayer();
    mediaPlayer->setPlaylist(playlist);
    mediaPlayer->setVolume(50);
    mediaPlayer->play();

    setRenderHint(QPainter::SmoothPixmapTransform);

    setOptimizationFlags(QGraphicsView::DontClipPainter);
    setOptimizationFlags(QGraphicsView::DontSavePainterState);
    setOptimizationFlags(QGraphicsView::DontAdjustForAntialiasing);
    setCacheMode(QGraphicsView::CacheBackground);

    controller = new Controller(scene, player);
}
