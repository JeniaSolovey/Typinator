#include "controller.h"
#include "enemy.h"
#include "time.h"
#include <QGraphicsPixmapItem>

QString Controller::getRandomWord()
{
    qsrand(time(NULL));
    return words.at(qrand()%(words.size()-1));
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

    //player lives part
    QGraphicsPixmapItem *livesIcon = new QGraphicsPixmapItem();
    livesIcon->setPixmap(QPixmap(":/res/img/lives.png").scaled(20,20));
    livesIcon->setPos(0,0);
    scene->addItem(livesIcon);

    player->lives = 3;
    livesLabel = new QGraphicsTextItem();
    livesLabel->setPos(livesIcon->pixmap().width(),0);
    livesLabel->setFont(QFont(QString("Courier New")));
    livesLabel->setDefaultTextColor(Qt::red);
    scene->addItem(livesLabel);

    //player score part
    QGraphicsPixmapItem *scoreIcon = new QGraphicsPixmapItem();
    scoreIcon->setPixmap(QPixmap(":/res/img/score.png").scaled(20,20));
    scoreIcon->setPos(0,20);
    scene->addItem(scoreIcon);

    player->score = 0;
    scoreLabel = new QGraphicsTextItem();
    scoreLabel->setPos(scoreIcon->pixmap().width(), livesIcon->pixmap().height());
    scoreLabel->setFont(QFont(QString("Courier New")));
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

    /*QGraphicsTextItem *gameOverLabel = new QGraphicsTextItem();
    gameOverLabel->setTextWidth(200);
    gameOverLabel->setHtml("<center>GAME OVER</center>");
    gameOverLabel->setDefaultTextColor(Qt::red);
    gameOverLabel->setPos(scene->width()/2 - (gameOverLabel->textWidth()/2), scene->height()/3);
    gameOverLabel->setFont(QFont(QString("Courier New"),30));
    scene->addItem(gameOverLabel);*/

    QGraphicsPixmapItem *gemeOverPixmap = new QGraphicsPixmapItem();
    gemeOverPixmap->setPixmap(QPixmap(":/res/img/gameOver.png"));
    gemeOverPixmap->setPos(scene->width()/2 - (gemeOverPixmap->pixmap().width()/2), scene->height()/3);
    scene->addItem(gemeOverPixmap);
    scene->removeItem(player);
}

void Controller::SpawnEnemy()
{
        Enemy *enemy = new Enemy(getRandomWord());
        scene->addItem(enemy);
        enemy->setRandomPosition();

        connect(moveTimer, SIGNAL(timeout()),enemy, SLOT(move()));

        connect(player, SIGNAL(Throw(char)), enemy, SLOT(checkHit(char)));
        connect(enemy, SIGNAL(hurt(QPointF)), player, SLOT(Hit(QPointF)));

        connect(player, SIGNAL(AimShot(char)), enemy, SLOT(checkAimHit(char)));
        connect(enemy, SIGNAL(destroyed(QObject*)), player, SLOT(Kill()));

        connect(enemy, SIGNAL(kick()), this, SLOT(PlayerFail()));
        connect(enemy, SIGNAL(destroyed(QObject*)), this, SLOT(EnemyIsKilled()));
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
