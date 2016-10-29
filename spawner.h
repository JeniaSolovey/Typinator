#ifndef SPAWNER_H
#define SPAWNER_H

#include <QObject>
#include <QGraphicsScene>

class Spawner: public QObject
{
    Q_OBJECT
private:
    QGraphicsScene *scene;
public:
    Spawner(QGraphicsScene *scene);
public slots:
    void SpawnEnemy();
};

#endif // SPAWNER_H
