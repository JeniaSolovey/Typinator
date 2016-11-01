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
    QTimer *moveTimer;
    QString getRandomWord();

    QGraphicsTextItem *livesLabel;
    void UpdateLivesLabel();
public:
    Controller(QGraphicsScene *scene, Player* player);
    QStringList words;
    void LoadWords();
    void GameOver();
public slots:
    void SpawnEnemy();
    void PlayerFail();
};

#endif // CONTROLLER_H
