#include "difficulty_choose.h"
#include "ui_difficulty_choose.h"

enum DIFFICULTYS {EASY,NORMAL,HARD};
difficulty_choose::difficulty_choose(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::difficulty_choose)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowMaximizeButtonHint|Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
    setAttribute(Qt::WA_StyledBackground);
}

difficulty_choose::~difficulty_choose()
{
    delete ui;
}

void difficulty_choose::on_Back_clicked()
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->close();
    QThread::msleep(100);
    emit sendsignal();
}

void difficulty_choose::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Backspace)
        on_Back_clicked();
}

void difficulty_choose::on_Easy_clicked()
{
    gm=new Game;
    gm->show();
    connect(this,SIGNAL(sendDifficulty(char)),gm,SLOT(getDifficulty(char)));
    emit sendDifficulty(EASY);
    this->close();
}

void difficulty_choose::on_Medium_clicked()
{
    gm=new Game;
    gm->show();
    connect(this,SIGNAL(sendDifficulty(char)),gm,SLOT(getDifficulty(char)));
    emit sendDifficulty(NORMAL);
    this->close();
}

void difficulty_choose::on_Hard_clicked()
{
    gm=new Game;
    gm->show();
    connect(this,SIGNAL(sendDifficulty(char)),gm,SLOT(getDifficulty(char)));
    emit sendDifficulty(HARD);
    this->close();
}
