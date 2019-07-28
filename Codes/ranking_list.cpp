#include "ranking_list.h"
#include "ui_ranking_list.h"

ranking_list::ranking_list(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ranking_list)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowMaximizeButtonHint|Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
    setAttribute(Qt::WA_StyledBackground);

    // 设置表格格式
    auto rnklst=ui->RankingList;
    rnklst->setEditTriggers(QAbstractItemView::NoEditTriggers);
    rnklst->setSelectionMode(QAbstractItemView::NoSelection);
    rnklst->verticalHeader()->setVisible(false);
    rnklst->horizontalHeader()->setVisible(false);
    rnklst->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    rnklst->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    rnklst->setFocusPolicy(Qt::NoFocus);
    rnklst->setFrameShape(QFrame::NoFrame);
    rnklst->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // getRanking();

    int column=rnklst->columnCount();
    int row=rnklst->rowCount();
    bool flag=false;
    for(int i = 0;i<row;i++)
    {
        for(int j = 0;j<column;j++)
        {
            if (rnklst->item(i,j)!=nullptr)
                rnklst->item(i,j)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);     // 防止“下标越界”
            else
            {
                flag=true;
                break;
            }
        }
        if(flag)
            break;
    }

}

ranking_list::~ranking_list()
{
    delete ui;
}

void ranking_list::on_Back_clicked()
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->close();
    QThread::msleep(100);
    emit sendsignal();
}

void ranking_list::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Backspace)
        on_Back_clicked();
}
