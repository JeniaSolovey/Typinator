#include "spawner.h"
#include "enemy.h"
Spawner::Spawner(QGraphicsScene *scene)
{
    this->scene = scene;
}

void Spawner::SpawnEnemy()
{
        Enemy *enemy = new Enemy();
        int maxPosibleXPosition = scene->width()-(enemy->pixmap().width());
        int randomPositionX = qrand()% maxPosibleXPosition;
        enemy->setPos(randomPositionX, 0);
        scene->addItem(enemy);
}
