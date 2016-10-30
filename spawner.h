#ifndef SPAWNER_H
#define SPAWNER_H

#include <QObject>
#include <QGraphicsScene>
#include <QFile>
#include <QStringList>

class Spawner: public QObject
{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    QString getRandomWord();
public:
    Spawner(QGraphicsScene *scene);
    QStringList words;
    void LoadWords();
public slots:
    void SpawnEnemy();
};

#endif // SPAWNER_H
