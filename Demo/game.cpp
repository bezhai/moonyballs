#include "game.h"
#include "ui_game.h"
#include <QDebug>
enum DIFFICULTYS {EASY,NORMAL,HARD};
const qreal PI=atan(1.0)*4;
static char difficulty;
static qreal rot;
Game::Game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowMaximizeButtonHint|Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
    setAttribute(Qt::WA_StyledBackground);
    setDifficulty(difficulty);
}

Game::~Game()
{
    delete ui;
}

void Game::getDifficulty(char diff)
{
    switch (diff) {
    case EASY:
        difficulty=EASY;
        break;
    case NORMAL:
        difficulty=NORMAL;break;
    case HARD:
        difficulty=HARD;break;
    default:
        difficulty=NORMAL;break;
    }
}

void Game::setDifficulty(char diff)
{
    switch (diff) {
    case EASY:
        // TODO
        break;
    case NORMAL:
        // TODO
        break;
    case HARD:
        // TODO
        break;
    default:
        // TODO
        break;
    }
}



void Game::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "(" <<event->pos().x()<<", "<<event->pos().y()<<")";
    int x = event->pos().x();
    int y = event->pos().y();
    if (x!=305)
        rot=atan((115-y)/(x-305))/PI*180;
    else if (x==305&&y>115)
        rot=0;
    else if(x==305&&y<115)
        rot=PI;
    qDebug()<<"Rotation is "<<rot;
    QMatrix leftmatrix;
    leftmatrix.rotate(rot);
    QPixmap pixmap(":/pic/shtr");
    QPixmap fitpixmap=pixmap.transformed(leftmatrix);

    ui->pushButton->setIcon(QIcon(fitpixmap));
    // ui->pushButton->setFlat(true);
    // ui->pushButton->setStyleSheet("border: 0px");

    ui->pushButton->setMask(fitpixmap.mask());
}
