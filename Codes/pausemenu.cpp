#include "pausemenu.h"
#include "ui_pausemenu.h"

PauseMenu::PauseMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PauseMenu)
{
    ui->setupUi(this);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint|Qt::FramelessWindowHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
    setAttribute(Qt::WA_StyledBackground);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_QuitOnClose,true);
}

PauseMenu::~PauseMenu()
{
    delete ui;
}

void PauseMenu::on_Exit_clicked()
{
    emit closegame();
    this->close();
}

void PauseMenu::on_Back_clicked()
{
    emit resume();
    this->close();
}
