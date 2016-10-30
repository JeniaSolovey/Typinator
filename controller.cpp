#include "controller.h"
#include "enemy.h"
QString Controller::getRandomWord()
{
    return words.at(qrand()%words.size()-1);
}

Controller::Controller(QGraphicsScene *scene)
{
    this->scene = scene;
    LoadWords();
}

void Controller::LoadWords()
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

void Controller::SpawnEnemy()
{
        Enemy *enemy = new Enemy(getRandomWord());
        scene->addItem(enemy);
        enemy->setRandomPosition();
}
