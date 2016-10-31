#include "enemy.h"
#include "player.h"
#include <QLineF>
#include <QPointF>
#include <QGraphicsScene>
#include <qmath.h>
#include <QTimer>

Enemy::Enemy(QString word)
{
    setPixmap(QPixmap(":/res/img/simpleEnemyShip.png").scaled(60,100));

    inFocus = false;
    this->word = new Word(word, this);
}

void Enemy::setRandomPosition()
{
    int maxPosibleXPosition = scene()->width()- pixmap().width();
    int randomPositionX = qrand()% maxPosibleXPosition;
    setPos(randomPositionX, 0);
    setTransformOriginPoint(pixmap().width()/2, pixmap().height()/2);

    QLineF ln(mapToScene(transformOriginPoint()), QPointF(scene()->width()/2, scene()->height()));
    int angle = -1 * ln.angle()+270;

    setRotation(angle);

    scene()->addItem(this->word);
}

void Enemy::move()
{

    if (y() > scene()->height()- (pixmap().height()*2))
    {
    scene()->removeItem(this);
    delete this;
    return;
    }

    double STEP_SIZE = 2;
    double angle = rotation()+90;

    double dy = STEP_SIZE * qSin(qDegreesToRadians(angle));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(angle));

    setPos(x()+dx, y()+dy);
}

void Enemy::checkHit(char key)
{
    if (key == word->word.at(0).toUpper())
    {
    inFocus = true;
    word->RemoveFirstCharacter();
    word->setDefaultTextColor(Qt::red);
    emit hurt(mapToScene(transformOriginPoint()));
    }
}

void Enemy::checkAimHit(char key)
{
    if (inFocus == true)
    {
        if (key == word->word.at(0).toUpper())
        {
        inFocus = true;
        word->RemoveFirstCharacter();
        emit hurt(mapToScene(transformOriginPoint()));
        }
    }
}
