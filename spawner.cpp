#include "spawner.h"
#include "enemy.h"
Spawner::Spawner(QGraphicsScene *scene)
{
    this->scene = scene;
}

void Spawner::SpawnEnemy()
{
        Enemy *enemy = new Enemy();
        scene->addItem(enemy);
        enemy->setRandomPosition();
}
