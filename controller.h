#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <player.h>
#include <QObject>
#include <QGraphicsScene>
#include <QFile>
#include <QStringList>
#include <QTimer>

class Controller: public QObject
{
    Q_OBJECT
private:
    Player *player;
    QGraphicsScene *scene;
    QTimer *timer;
    QString getRandomWord();
public:
    Controller(QGraphicsScene *scene, Player* player);
    QStringList words;
    void LoadWords();
public slots:
    void SpawnEnemy();
};

#endif // CONTROLLER_H
