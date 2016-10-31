#include "controller.h"
#include "enemy.h"
#include "time.h"

QString Controller::getRandomWord()
{
    qsrand(time(NULL));
    return words.at(qrand()%words.size()-1);
}

Controller::Controller(QGraphicsScene *scene, Player *player)
{
    this->scene = scene;
    this->player = player;
    this->timer = new QTimer();
    timer->start(40); //move timer
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

        connect(timer, SIGNAL(timeout()),enemy, SLOT(move()));

        connect(player, SIGNAL(Throw(char)), enemy, SLOT(checkHit(char)));
        connect(enemy, SIGNAL(hurt(QPointF)), player, SLOT(Hit(QPointF)));

        connect(player, SIGNAL(AimShot(char)), enemy, SLOT(checkAimHit(char)));
        connect(enemy, SIGNAL(destroyed(QObject*)), player, SLOT(Kill()));
        enemy->setRandomPosition();
}
