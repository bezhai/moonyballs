#include "guidepage.h"
#include "ui_guidepage.h"

guidepage::guidepage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::guidepage)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowMaximizeButtonHint|Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
    setAttribute(Qt::WA_StyledBackground);
}

guidepage::~guidepage()
{
    delete ui;
}

void guidepage::on_Back_clicked()
{
    this->close();
    QThread::msleep(100);
    emit sendsignal();
}

void guidepage::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Backspace)
        on_Back_clicked();
}
