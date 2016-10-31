#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QPointF target;
public:
    Bullet(QPointF target);
    void Throw();
private slots:
    void move();
};

#endif // BULLET_H
