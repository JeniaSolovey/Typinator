#include "spawner.h"
#include "enemy.h"
QString Spawner::getRandomWord()
{
    return words.at(qrand()%words.size()-1);
}

Spawner::Spawner(QGraphicsScene *scene)
{
    this->scene = scene;
    LoadWords();
}

void Spawner::LoadWords()
{
    QFile file(":/res/words.txt");
    QByteArray arr;

    if(file.open(QIODevice::ReadOnly |QIODevice::Text))
        {
            while(!file.atEnd())
            {
                QString str = file.readLine();
                words.push_back(str);
            }
        }
}

void Spawner::SpawnEnemy()
{
        Enemy *enemy = new Enemy(getRandomWord());
        scene->addItem(enemy);
        enemy->setRandomPosition();
}
