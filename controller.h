#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QFile>
#include <QStringList>

class Controller: public QObject
{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    QString getRandomWord();
public:
    Controller(QGraphicsScene *scene);
    QStringList words;
    void LoadWords();
public slots:
    void SpawnEnemy();
};

#endif // CONTROLLER_H
