#include "failed.h"
#include "ui_failed.h"

failed::failed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::failed)
{
    ui->setupUi(this);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint|Qt::FramelessWindowHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
    setAttribute(Qt::WA_StyledBackground);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_QuitOnClose,true);
}

failed::~failed()
{
    delete ui;
}

void failed::on_Exit_clicked()
{
    emit closegame();
    this->close();
}

void failed::on_Back_clicked()
{
    emit again();
    this->close();
}

void failed::displayScore(int score)
{
    ui->Score->setText(tr("Your Score: %1").arg(score));
}
