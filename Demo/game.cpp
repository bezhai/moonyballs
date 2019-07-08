#include "game.h"
#include "ui_game.h"
#include "mainlogic/object_shift.h"
int money=0;
static vector<PlayerBall*> playerballs;
static vector<Barrier *> barriers;
static vector<Prop *> props;
static QTimer *timer=new QTimer;
static QTimer *propgene=new QTimer;
static QTimer *bargene=new QTimer;
static QTimer *upleveltimer=new QTimer;
static qreal coin_P = 0.46;
static qreal bigger_P=0.25;
static qreal smaller_P=0.25;
static int small_ball_num=0;

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
    setAttribute(Qt::WA_DeleteOnClose,true);
    setDifficulty(difficulty);
    m_PointStart=QPoint(305,115);
    m_PointEnd=m_PointStart;
    timer->setInterval(30);
    timer->start();
    bargene->start();
    propgene->start();
    upleveltimer->start();
    generateNewBall();
    geneBars();
    geneBars();
    connect(bargene,SIGNAL(timeout()),this,SLOT(geneBars()));
    connect(propgene,SIGNAL(timeout()),this,SLOT(geneProps()));
    connect(upleveltimer,SIGNAL(timeout()),this,SLOT(uplevel()));
    connect(timer,SIGNAL(timeout()),this,SLOT(gamePlay()));
}

Game::~Game()
{
    delete ui;
}

void Game::getDifficulty(char diff)
{
    switch (diff) {
    case EASY:
        difficulty=EASY;break;
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
        bargene->setInterval(10000);
        propgene->setInterval(10000);
        upleveltimer->setInterval(15000);
        break;
    case NORMAL:
        bargene->setInterval(5000);
        propgene->setInterval(50000);
        upleveltimer->setInterval(10000);
        break;
    case HARD:
        bargene->setInterval(3000);
        propgene->setInterval(100000);
        upleveltimer->setInterval(5000);
        break;
    default:
        break;
    }
}



void Game::mouseMoveEvent(QMouseEvent *event)
{

    int x = event->pos().x();
    int y = event->pos().y();

    m_PointEnd=event->pos();
    QMatrix leftmatrix;
    rot=atan2((y-115),(x-305))/PI*180-90;
    leftmatrix.rotate(rot);
    QPixmap pixmap(":/pic/shtr");
    pixmap.size()=ui->pushButton->rect().size();
    QPixmap fitpixmap=pixmap.transformed(leftmatrix,Qt::SmoothTransformation);

    ui->pushButton->setIcon(QIcon(fitpixmap));
    ui->pushButton->setIconSize(fitpixmap.size());
    ui->pushButton->setFlat(true);
    ui->pushButton->setStyleSheet("border: 0px");

    qreal dis = sqrt(pow((y-115),2.0)+pow((x-305),2.0));
    if (rot>=-45&&rot<=45&&x<=560&&x>=40&&dis<670)
    {
        update();
    }
    else
    {
        m_PointEnd=QPoint(305,115);
        update();
    }
}

void Game::paintEvent(QPaintEvent *)
{
    static QImage cirbr;
    static QImage rectbr;
    static QImage tribr;
    static QImage hexbr;
    static QImage penbr;

    static QPixmap coin(":/pic/coin");
    coin=coin.scaled(coin_radius*2,coin_radius*2,Qt::IgnoreAspectRatio);
    static QPixmap turntable(":/pic/turntable");
    turntable=turntable.scaled(turntable_radius*2,turntable_radius*2,Qt::IgnoreAspectRatio);
    static QPixmap plus(":/pic/plus");
    plus=plus.scaled(plus_radius*2,plus_radius*2,Qt::IgnoreAspectRatio);
    // 载入资源

    QPen pen;
    pen.setBrush(QBrush(Qt::white));
    QVector<qreal> dashes;
    qreal space = 3;
    dashes<<5<<space<<5<<space;
    pen.setDashPattern(dashes);
    pen.setWidth(5);
    // 设定画笔(用于绘制虚线)

    QPainter painter(this);
    QPixmap pix(":/pic/gmbgrcmr");
    pix=pix.scaled(QSize(600,780),Qt::IgnoreAspectRatio);
    painter.drawPixmap(0,0,pix);
    painter.setPen(pen);
    painter.drawLine(m_PointEnd,m_PointStart);
    // 绘制虚线与背景

    for(int i = 0;i < playerballs.size();i++)
    {
        int x = playerballs.at(i)->GetcoordX();
        int y = 700 - playerballs.at(i)->GetcoordY();
        qreal radius = playerballs.at(i)->GetRadius();
        int size = static_cast<int>(radius*2);
        x-=size/2;
        y-=size/2;
        qreal rotation=playerballs.at(i)->GetAngle();
        rotation=rotation*180/PAI;
        QPixmap ballpic(":/pic/ball");
        ballpic=ballpic.scaled(QSize(size,size),Qt::IgnoreAspectRatio);
        painter.drawPixmap(x,y,ballpic);
        QString pos;
        pos = tr("X: %1 Y: %2 Radius: %3 Rotation: %4").arg(x).arg(y).arg(size).arg(rotation);
        ui->label_2->setText(pos);
    }
    // 绘制小球

    for (int j = 0;j<barriers.size();j++)
    {
        int x = barriers.at(j)->GetX();
        int y = 700 - barriers.at(j)->GetY();
        qreal radius = barriers.at(j)->GetCalculateRadius();
        int size = static_cast<int>(radius*2);
        int color=barriers.at(j)->GetColor();

        int hp = barriers.at(j)->GetHp();
        x-=size/2;
        y-=size/2;
        QFont font=painter.font();
        font.setBold(true);
        font.setPixelSize(20);
        pen.setColor(Qt::white);
        painter.setPen(pen);
        painter.setFont(font);
        QString strhp=tr("%1").arg(hp);
        switch (barriers.at(j)->GetMode()) {
        case CIRCLE:
            switch (color) {
                case 0:
                cirbr.load(":/pic/cirbl");break;
            case 1:
                cirbr.load(":/pic/cirrd");break;
            case 2:case 3:
                cirbr.load(":/pic/cirgr");break;
            }
            cirbr=cirbr.scaled(size,size);
            painter.drawImage(x,y,cirbr);
            painter.drawText(barriers.at(j)->GetX(),700-barriers.at(j)->GetY(),strhp);
            break;
        case SQUARE:
            switch (color) {
            case 0:
                rectbr.load(":/pic/rectbl");break;
            case 1:
                rectbr.load(":/pic/rectrd");break;
            case 2:
                rectbr.load(":/pic/rectbr");break;
            case 3:
                rectbr.load(":/pic/rectgr");break;
            }
            painter.rotate(-barriers.at(j)->GetRot());
            rectbr=rectbr.scaled(QSize(size,size));
            painter.drawImage(x,y,rectbr);
            painter.drawText(barriers.at(j)->GetX(),700-barriers.at(j)->GetY(),strhp);
            break;
        case TRIANGLE:
            switch (color) {
            case 0:
                tribr.load(":/pic/tribl");break;
            case 1:
                tribr.load(":/pic/trird");break;
            case 2:
                tribr.load(":/pic/trigr");break;
            case 3:
                tribr.load(":/pic/tricy");break;
            }
            painter.rotate(-barriers.at(j)->GetRot());
            tribr=tribr.scaled(QSize(size,size));
            painter.drawImage(x,y,tribr);
            painter.drawText(barriers.at(j)->GetX(),700-barriers.at(j)->GetY(),strhp);
            break;
        case HEXAGON:
            switch (color) {
            case 0:
                hexbr.load(":/pic/hexbl");break;
            case 1:
                hexbr.load(":/pic/hexrd");break;
            case 2:
                hexbr.load(":/pic/hexgr");break;
            case 3:
                hexbr.load(":/pic/hexpl");break;
            }
            painter.rotate(-barriers.at(j)->GetRot());
            hexbr=hexbr.scaled(QSize(size,size));
            painter.drawImage(x,y,hexbr);
            painter.drawText(barriers.at(j)->GetX(),700-barriers.at(j)->GetY(),strhp);
            break;
        case PENTAGON:
            switch (color) {
            case 0:
                penbr.load(":/pic/penbl");break;
            case 1:
                penbr.load(":/pic/penrd");break;
            case 2:
                penbr.load(":/pic/pengr");break;
            case 3:
                penbr.load(":/pic/penpl");break;
            }
            painter.rotate(-barriers.at(j)->GetRot());
            penbr=penbr.scaled(QSize(size,size));
            painter.drawImage(x,y,penbr);
            painter.drawText(barriers.at(j)->GetX(),700-barriers.at(j)->GetY(),strhp);
            break;
        }
        int floor=barriers.at(j)->GetFloor();
        QString posr;
        posr = tr("X: %1 Y: %2 Radius: %3 Hp: %4 Bars: %5 Floor: %6").arg(x).arg(y).arg(size).arg(hp).arg(barriers.size()).arg(floor);
        ui->label_3->setText(posr);
        painter.rotate(0);

    }
    // 绘制障碍物

    for(int k=0;k<props.size();k++)
    {
        int x = props.at(k)->GetcoordX();
        int y =700- props.at(k)->GetcoordY();
        switch (props.at(k)->GetMode()) {
        case COIN:
            painter.drawPixmap(x,y,coin);
            break;
        case TURNTABLE:
            painter.drawPixmap(x,y,turntable);
            break;
        case PLUSSYMBOL:
            painter.drawPixmap(x,y,plus);
            break;
        }

    }

    QString pos;
    pos=tr("X: %1, Y: %2 Rot: %3").arg(m_PointEnd.x()).arg(m_PointEnd.y()).arg(rot);
    ui->label->setText(pos);
}

void Game::mouseReleaseEvent(QMouseEvent *)
{
    m_PointEnd=QPoint(305,115);
    bool cando=true;
    for(int j = 0 ;j<playerballs.size();j++)
    {
        if (playerballs.at(j)->GetActive()==true)
        {
            cando=false;
            break;
        }
    }
    if (cando)
    {
        MainControl::SetBeginAngle(playerballs,(rot+90)/180*PAI);
        for(int i =0 ;i < playerballs.size(); i++)
        {
            playerballs.at(i)->SetActive();
            MainControl::BallCalc(playerballs,barriers,props);
            update();
            QThread::msleep(50);
        }
    }
    update();
}

void Game::gamePlay()
{
    MainControl::BallCalc(playerballs,barriers,props);
    for(int i = 0 ;i< barriers.size();i++)
    {
        if(barriers.at(i)->GetHp()<=0)
        {
            barriers.erase(barriers.begin()+i);
        }
    }
    for(int j = 0 ;j<props.size();j++)
    {
        if(props.at(j)->GetHp()<=0)
        {
            props.erase(props.begin()+j);
        }
    }
    ui->Coin->setText(tr("%1").arg(money));
    ui->SmallNum->setText(tr("%1").arg(small_ball_num));
    update();
}

void Game::on_TestFailure_clicked()
{
    fail=new failed;
    fail->show();
    this->setEnabled(false);
    timer->stop();
    barriers.clear();
    props.clear();
    playerballs.clear();
    small_ball_num=0;
    connect(fail,SIGNAL(closegame()),this,SLOT(closeself()));
    connect(fail,SIGNAL(again()),this,SLOT(chooseagain()));
}

void Game::closeself()
{
    this->close();
    deleteLater();
}

void Game::chooseagain()
{
    emit tryagain();
    closeself();
}

void Game::generateNewBall()
{
    int nownum=playerballs.size();
    MainControl::PlayerGenerate(playerballs);
    playerballs.at(nownum)->SetInactive();
    small_ball_num++;
}

void Game::on_pushButton_2_clicked()
{
    generateNewBall();
    update();
}

void Game::on_pushButton_4_clicked()
{
    MainControl::PropGenerate(props,coin_P,bigger_P,smaller_P);
    update();
}

void Game::on_pushButton_3_clicked()
{
    int nownum=barriers.size();
    MainControl::BarrierGenerate(barriers,1);
    barriers.at(nownum)->SetColor(rand()%4);
    update();
}

void Game::on_pause_clicked()
{
    timer->stop();
    bargene->stop();
    upleveltimer->stop();
    propgene->stop();
    pause = new PauseMenu;
    pause->show();
    connect(pause,SIGNAL(resume()),this,SLOT(resumeGame()));
    connect(pause,SIGNAL(closegame()),this,SLOT(closeself()));
}

void Game::on_pushButton_5_clicked()
{
    MainControl::ItemsMovement(barriers,props);
    for(int i=0;i<barriers.size();i++)
    {
        if(barriers.at(i)->GetFloor()>=10)
            on_TestFailure_clicked();
    }
}
void Game::uplevel()
{
    MainControl::ItemsMovement(barriers,props);
    generateNewBall();
    update();
    for(int i=0;i<barriers.size();i++)
    {
        if(barriers.at(i)->GetFloor()>=10)
            on_TestFailure_clicked();
    }
}

void Game::geneBars()
{
    int nownum=barriers.size();
    MainControl::BarrierGenerate(barriers,1);
    barriers.at(nownum)->SetColor(rand()%4);
    update();
}

void Game::geneProps()
{
    MainControl::PropGenerate(props,coin_P,bigger_P,smaller_P);
    update();
}

void Game::resumeGame()
{
    timer->start();
    bargene->start();
    upleveltimer->start();
    propgene->start();
}

void Game::on_Buy_clicked()
{
    if(money>0)
    {
        money--;
        generateNewBall();
        update();
    }
    else
    {
       QMessageBox::information(this,"Insufficient funds",QString::fromLocal8Bit("金钱不足！"));
    }
}
