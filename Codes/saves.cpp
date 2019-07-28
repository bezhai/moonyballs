#include "saves.h"
#include "ui_saves.h"
static QString saveinfo;
saves::saves(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::saves)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowMaximizeButtonHint|Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
    setAttribute(Qt::WA_StyledBackground);
    getSaves();
}

saves::~saves()
{
    delete ui;
}

void saves::on_Back_clicked()
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->close();
    QThread::msleep(100);
    emit sendsignal();
}

void saves::getSaves()
{
    // TODO
    if(getSlot(1))
    {
        QString slot = getInfo(1);
        ui->Slot_1->setEnabled(true);
        ui->Slot_1->setText(slot);
        ui->Slot_1->setStyleSheet("QPushButton{border-image: url(:/pic/btn);background: transparent}");
    }
    if(getSlot(2))
    {
        QString slot = getInfo(2);
        ui->Slot_2->setEnabled(true);
        ui->Slot_2->setText(slot);
        ui->Slot_2->setStyleSheet("QPushButton{border-image: url(:/pic/btn);background: transparent}");
    }
    if(getSlot(3))
    {
        QString slot = getInfo(3);
        ui->Slot_3->setEnabled(true);
        ui->Slot_3->setText(slot);
        ui->Slot_3->setStyleSheet("QPushButton{border-image: url(:/pic/btn);background: transparent}");
    }
    if(getSlot(4))
    {
        QString slot = getInfo(4);
        ui->Slot_4->setEnabled(true);
        ui->Slot_4->setText(slot);
        ui->Slot_4->setStyleSheet("QPushButton{border-image: url(:/pic/btn);background: transparent}");
    }
}

bool saves::getSlot(int index)
{
    // TODO
    if (index==1||index==2)
        return true;
    else
        return false;
}

QString saves::getInfo(int index)
{
    // TODO
    // slotname = getSlotName();
    // slottime = getSlotTime();
    saveinfo=tr("Slot%1 info").arg(index);
    return saveinfo;
}

void saves::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Backspace)
        on_Back_clicked();
}
