#include "controller.h"
#include "enemy.h"
#include "time.h"

QString Controller::getRandomWord()
{
    qsrand(time(NULL));
    return words.at(qrand()%words.size()-1);
}

void Controller::UpdateLabels()
{
    livesLabel->setPlainText(QString::number(player->lives));
    scoreLabel->setPlainText(QString::number(player->score));
}

Controller::Controller(QGraphicsScene *scene, Player *player)
{
    this->scene = scene;
    this->player = player;
    this->moveTimer = new QTimer();
    this->spawnTimer = new QTimer();
    moveTimer->start(40);
    spawnTimer->start(4000);
    connect(spawnTimer, SIGNAL(timeout()), this, SLOT(SpawnEnemy()));

    LoadWords();

    player->lives = 3;
    livesLabel = new QGraphicsTextItem();
    livesLabel->setPos(10,0);
    livesLabel->setDefaultTextColor(Qt::red);
    scene->addItem(livesLabel);

    player->score = 0;
    scoreLabel = new QGraphicsTextItem();
    scoreLabel->setPos(10,10);
    scoreLabel->setDefaultTextColor(Qt::yellow);
    scene->addItem(scoreLabel);

    UpdateLabels();
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
    spawnTimer->stop();

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
        connect(enemy, SIGNAL(destroyed(QObject*)), this, SLOT(EnemyIsKilled()));
        enemy->setRandomPosition();
}

void Controller::PlayerFail()
{
    player->lives--;
    UpdateLabels();
    if(player->lives == 0){ GameOver();}
}

void Controller::EnemyIsKilled()
{
    UpdateLabels();
}
