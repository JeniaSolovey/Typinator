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
    QTimer *spawnTimer;
    QString getRandomWord();
    int difficultLevel;

    QGraphicsTextItem *livesLabel;
    QGraphicsTextItem *scoreLabel;
    void UpdateLabels();
public:
    Controller(QGraphicsScene *scene, Player* player);
    QStringList words;
    void LoadWords();
    void GameOver();
public slots:
    void SpawnEnemy();
    void PlayerFail();
    void EnemyIsKilled();
};

#endif // CONTROLLER_H
