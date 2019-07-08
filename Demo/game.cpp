#include "game.h"
#include "ui_game.h"
#include "mainlogic/object_shift.h"

static vector<PlayerBall*> playerballs;
static vector<Barrier *> barriers;
static vector<Prop *> props;
static QTimer *timer=new QTimer;

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
    m_PointStart=QPoint(305,115);
    m_PointEnd=m_PointStart;
    timer->setInterval(30);
    timer->start();
    generateNewBall();
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
    static QPixmap cirbr(":/pic/cirbr");

    QPen pen;
    pen.setBrush(QBrush(Qt::white));
    QVector<qreal> dashes;
    qreal space = 3;
    dashes<<5<<space<<5<<space;
    pen.setDashPattern(dashes);
    pen.setWidth(5);
    QPainter painter(this);
    QPixmap pix(":/pic/gmbgrcmr");
    pix=pix.scaled(QSize(600,780),Qt::IgnoreAspectRatio);
    painter.drawPixmap(0,0,pix);
    painter.setPen(pen);
    painter.drawLine(m_PointEnd,m_PointStart);
    for(int i = 0;i < playerballs.size();i++)
    {
        int x = playerballs.at(i)->GetcoordX();
        int y = 700 - playerballs.at(i)->GetcoordY();
        qreal radius = playerballs.at(i)->GetRadius();
        int size = static_cast<int>(radius*2);
        qreal rotation=playerballs.at(i)->GetAngle();
        rotation=rotation*180/PAI;
        QPixmap ballpic(":/pic/ball");
        ballpic=ballpic.scaled(QSize(size,size),Qt::IgnoreAspectRatio);
        painter.drawPixmap(x,y,ballpic);
        QString pos;
        pos = tr("X: %1 Y: %2 Radius: %3 Rotation: %4").arg(x).arg(y).arg(size).arg(rotation);
        ui->label_2->setText(pos);
    }
    for (int j = 0;j<barriers.size();j++)
    {
        int x = barriers.at(j)->GetX();
        int y = 700 - barriers.at(j)->GetY();
        qreal radius = barriers.at(j)->GetCalculateRadius();
        int size = static_cast<int>(radius);
        int red=0,green=0,blue=0;
        int hp = barriers.at(j)->GetHp();
        red=MainControl::GetColor(barriers.at(j),RED);
        green=MainControl::GetColor(barriers.at(j),GREEN);
        blue=MainControl::GetColor(barriers.at(j),BLUE);
        QMatrix matrix;
        matrix.rotate(barriers.at(j)->GetRot()*180/PAI);
        x-=size;
        y-=size;
        switch (barriers.at(j)->GetMode()) {
        case CIRCLE:
            cirbr=cirbr.scaled(size,size);
            painter.drawPixmap(x,y,cirbr);
            break;
        /*case SQUARE:
            rectbr=rectbr.transformed(matrix,Qt::SmoothTransformation);
            rectbr.fill(QColor(red,green,blue));
            rectbr.scaled(QSize(size,size));
            painter.drawImage(x,y,rectbr);
            break;
        case TRIANGLE:
            tribr=tribr.transformed(matrix,Qt::SmoothTransformation);
            tribr.fill(QColor(red,green,blue));
            tribr.scaled(QSize(size,size));
            painter.drawImage(x,y,tribr);
            break;
        case HEXAGON:
            hexbr=hexbr.transformed(matrix,Qt::SmoothTransformation);
            hexbr.fill(QColor(red,green,blue));
            hexbr.scaled(QSize(size,size));
            painter.drawImage(x,y,hexbr);
            break;
        case PENTAGON:
            penbr=penbr.transformed(matrix,Qt::SmoothTransformation);
            penbr.fill(QColor(red,green,blue));
            penbr.scaled(QSize(size,size));
            painter.drawImage(x,y,penbr);*/
            break;
        }
        QString posr;
        posr = tr("X: %1 Y: %2 Radius: %3 Hp: %4").arg(x).arg(y).arg(size).arg(hp);
        ui->label_3->setText(posr);
    }
    QString pos;
    pos=tr("X: %1, Y: %2 Rot: %3").arg(m_PointEnd.x()).arg(m_PointEnd.y()).arg(rot);
    ui->label->setText(pos);
}

void Game::mouseReleaseEvent(QMouseEvent *)
{
    m_PointEnd=QPoint(305,115);
    MainControl::SetBeginAngle(playerballs,(rot+90)/180*PAI);
    for(int i =0 ;i < playerballs.size(); i++)
    {
        playerballs.at(i)->SetActive();
        MainControl::BallCalc(playerballs,barriers,props);
        update();
        QThread::msleep(30);
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
    update();
}

void Game::on_TestFailure_clicked()
{
    fail=new failed;
    fail->show();
    this->setEnabled(false);
    timer->stop();
    connect(fail,SIGNAL(closegame()),this,SLOT(closeself()));
    connect(fail,SIGNAL(again()),this,SLOT(chooseagain()));
}

void Game::closeself()
{
    this->close();
}

void Game::chooseagain()
{
    emit tryagain();
    this->close();
}

void Game::generateNewBall()
{
    int nownum=playerballs.size();
    MainControl::PlayerGenerate(playerballs);
    playerballs.at(nownum)->SetInactive();
}

void Game::on_pushButton_2_clicked()
{
    generateNewBall();
}

void Game::on_pushButton_4_clicked()
{
    MainControl::PropGenerate(props,1,0,0);
}

void Game::on_pushButton_3_clicked()
{
    MainControl::BarrierGenerate(barriers,1);
}
