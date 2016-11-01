#include "controller.h"
#include "enemy.h"
#include "time.h"

QString Controller::getRandomWord()
{
    qsrand(time(NULL));
    return words.at(qrand()%words.size()-1);
}

void Controller::UpdateLivesLabel()
{
    livesLabel->setPlainText(QString::number(player->lives));
}

Controller::Controller(QGraphicsScene *scene, Player *player)
{
    this->scene = scene;
    this->player = player;
    this->moveTimer = new QTimer();
    moveTimer->start(40);
    LoadWords();

    player->lives = 3;
    livesLabel = new QGraphicsTextItem();
    livesLabel->setPos(0,0);
    livesLabel->setDefaultTextColor(Qt::white);
    scene->addItem(livesLabel);
    UpdateLivesLabel();
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

void Controller::GameOver()
{
    moveTimer->stop();

    QGraphicsTextItem *gameOverLabel = new QGraphicsTextItem("GAME OVER");
    gameOverLabel->setDefaultTextColor(Qt::red);
    gameOverLabel->setPos(scene->width()/2, scene->height()/2);
    scene->addItem(gameOverLabel);
    scene->removeItem(player);
}

void Controller::SpawnEnemy()
{
        Enemy *enemy = new Enemy(getRandomWord());
        scene->addItem(enemy);

        connect(moveTimer, SIGNAL(timeout()),enemy, SLOT(move()));

        connect(player, SIGNAL(Throw(char)), enemy, SLOT(checkHit(char)));
        connect(enemy, SIGNAL(hurt(QPointF)), player, SLOT(Hit(QPointF)));

        connect(player, SIGNAL(AimShot(char)), enemy, SLOT(checkAimHit(char)));
        connect(enemy, SIGNAL(destroyed(QObject*)), player, SLOT(Kill()));

        connect(enemy, SIGNAL(kick()), this, SLOT(PlayerFail()));
        enemy->setRandomPosition();
}

void Controller::PlayerFail()
{
    player->lives--;
    UpdateLivesLabel();
    if(player->lives == 0){ GameOver();}
}
