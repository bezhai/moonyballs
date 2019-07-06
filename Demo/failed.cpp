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
}

failed::~failed()
{
    delete ui;
}
