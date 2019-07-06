#include "mainwindow.h"
#include "ui_mainwindow.h"
static QString Account = "Guest";
static bool logAppear=false;
static bool up=true;
static int move_speed= 20;
static bool logged=false;
static bool sound_on=true;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowMaximizeButtonHint|Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
    QTimer *timer;
    timer = new QTimer(this);
    timer->start();
    timer->setInterval(30);
    connect(timer,SIGNAL(timeout()),this,SLOT(BallBounce()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::BallBounce()       // 主页球跳动
{
    if (!logAppear)
    {
        logindlg = new login;
        logindlg->show();
        logAppear=true;
        setFocus();
        connect(logindlg,SIGNAL(closeGame()),this,SLOT(closeself()));
        connect(logindlg,SIGNAL(logged(QString)),this,SLOT(loginSuccessful(QString)));
    }
    auto ball = ui->Ball;
    if(up)
    {
        ball->setGeometry(ball->x(),ball->y()-move_speed,ball->width(),ball->height());
        move_speed-=1;
        if(move_speed==0)
            up=false;
    }
    else
    {
        ball->setGeometry(ball->x(),ball->y()+move_speed,ball->width(),ball->height());
        move_speed+=1;
        if(move_speed==21)
        {
            up=true;
            move_speed--;
        }
    }
}


void MainWindow::on_StartGame_clicked()
{
    diff = new difficulty_choose;
    diff->show();
    this->hide();
    connect(diff,SIGNAL(sendsignal()),this,SLOT(reshow()));
}

bool MainWindow::getSaves()
{
    // TODO
    return false;
}

void MainWindow::on_About_clicked()
{
    QString title=QString::fromLocal8Bit("关于");
    QString intro=QString::fromLocal8Bit("疯狂弹球\n\n基于Qt 5.12.3 (MSCV 2017, 32 bit)\n\n在 X年X月X日 XX:XX:XX编译通过\n\nSky Group 版权所有 保留所有权利.\n\n.");
    QMessageBox about(QMessageBox::NoIcon,title,intro);
    about.setIconPixmap(QPixmap(":/pic/ball"));
    about.exec();
}

void MainWindow::reshow()
{
    this->show();
}

void MainWindow::closeself()
{
    this->close();
}

void MainWindow::loginSuccessful(QString acct)
{
    logged=true;
    Account=acct;
    this->setEnabled(true);
    if (!getSaves())
    {
        ui->ResumeGame->setEnabled(false);
        ui->ResumeGame->setStyleSheet("QPushButton{border-image: url(:/pic/unrsm);background: transparent}");
    }
    else
    {
        ui->ResumeGame->setEnabled(true);
        ui->ResumeGame->setStyleSheet("QPushButton{border-image: url(:/pic/rsmbtn);background: transparent}");
    }
}

void MainWindow::on_ResumeGame_clicked()
{
    save=new saves;
    save->show();
    this->hide();
    connect(save,SIGNAL(sendsignal()),this,SLOT(reshow()));
}

void MainWindow::on_Exit_clicked()
{
    this->close();
}


void MainWindow::on_Rank_clicked()
{
    rank=new ranking_list;
    rank->show();
    this->hide();
    connect(rank,SIGNAL(sendsignal()),this,SLOT(reshow()));
}

void MainWindow::on_Sound_clicked()
{
    if(sound_on)
    {
        sound_on=false;
        ui->Sound->setStyleSheet("QPushButton{border-image: url(:/pic/sdbtn);background: transparent}");
        // TODO
    }
    else
    {
        sound_on=true;
        ui->Sound->setStyleSheet("QPushButton{border-image: url(:/pic/sdbtndis);background: transparent}");
        // TODO

    }
}

void MainWindow::on_Guide_clicked()
{
    guide=new guidepage;
    guide->show();
    this->hide();
    connect(guide,SIGNAL(sendsignal()),this,SLOT(reshow()));
}
