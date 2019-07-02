#include "game.h"
#include <QPainter>
#include <QTimer>
#include <QDebug>
#include <cstdlib>
#include <ctime>

Game::Game( QWidget *parent )
    :QWidget( parent )
{
    isWin = false;
    isFailure = false;

    frameWidth = 800;
    frameHeight = 500;

    score = 0;
    rows = 5;
    columns = 10;

    createBricks();
    createPaddle();
    createBall();

    timer = new QTimer( this );
    timer->setInterval( 10 );
    connect( timer, SIGNAL( timeout() ), this, SLOT( moveBall() ) );

    changeColor();
}

void Game::changeColor()
{
    srand( (int) time( NULL ) );

    foreach( Brick *brick, bricks )
    brick->setColor( randomColor() );

    ball->setColor( randomColor() );
    paddle->setColor( randomColor() );
}

QColor Game::randomColor()
{
    return QColor( randomInt( 255 ), randomInt( 255 ), randomInt( 255 ) );
}

int Game::randomInt( int high )
{
    double d = (double)rand() / ( (double)RAND_MAX + 1 );
    int k = (int) (d * ( high  + 1 ));

    return k;
}
void Game::createBricks()
{
    qreal gap = 5.0;
    qreal brickWidth = frameWidth / ( columns + 1 ) - gap;
    qreal brickHeight = frameHeight / 4 / ( rows + 1 ) - gap;

    for( int r = 0; r < rows; ++r )
    for( int c = 0; c < columns; ++c )
    {
        Brick *brick = new Brick(  brickWidth / 2 + c * ( brickWidth + gap ),
                       brickHeight / 2 + r * ( brickHeight + gap ),
                       brickWidth, brickHeight );
        bricks.append( brick );
    }
}

void Game::createPaddle()
{
    qreal paddleWidth = frameWidth / 10;
    qreal paddleHeight = paddleWidth / 5;

    paddle = new Paddle( frameWidth / 2 - paddleWidth / 2 ,
             frameHeight - paddleHeight * 2,
             paddleWidth, paddleHeight );
}

void Game::createBall()
{
    qreal ballSide = paddle->getShape().height();

    ball = new Ball( frameWidth / 2 - ballSide / 2, paddle->getShape().top() - ballSide, ballSide );
}

void Game::resizeEvent( QResizeEvent * )
{
    qreal scaleWidth = rect().width() / frameWidth;
    qreal scaleHeight = rect().height() / frameHeight;

    foreach( Brick *brick, bricks )
    {
    QRectF shape = brick->getShape();
    brick->setShape( adjustShape( shape, scaleWidth, scaleHeight ) );
    }

    QRectF ballShape = ball->getShape();
    ball->setShape( adjustShape( ballShape, scaleWidth, scaleHeight ) );
    ball->setSpeed( ball->getSpeed() * scaleWidth );

    QRectF paddleShape = paddle->getShape();
    paddle->setShape( adjustShape( paddleShape, scaleWidth, scaleHeight ) );
    paddle->setStep( paddle->getStep() * scaleWidth );

    frameWidth = rect().width();
    frameHeight = rect().height();
}

QRectF Game::adjustShape( QRectF shape, qreal scaleWidth, qreal scaleHeight )
{
    QRectF newShape( shape.left() * scaleWidth, shape.top() * scaleHeight,
            shape.width() * scaleWidth, shape.height() * scaleHeight );
    return newShape;
}

Game::~Game()
{
    delete ball;
    delete paddle;

    while( !bricks.isEmpty() )
    delete bricks.takeFirst();
}

void Game::paintEvent( QPaintEvent * )
{
    QPainter painter( this );

    if( isWin  || isFailure )
    {
    QFont font( "Courier", 20, QFont::DemiBold );
    QFontMetrics fm( font );

    painter.setFont( font );
    painter.translate( QPoint( width() / 2, height() / 2 ) );

    if( isWin )
    {
        int textWidth = fm.width( "You are winner!" );
        painter.setPen( Qt::blue );
        painter.drawText( -textWidth / 2, 0, tr( "You are the winner!" ) );
    }
    else
    {
        int textWidth = fm.width( "You are loser!" );
        painter.setPen( Qt::red );
        painter.drawText( -textWidth / 2, 0, tr( "You are the loser!" ) );
    }

    timer->stop();
    emit finished();
    return;
    }

    painter.setPen( Qt::NoPen );
    painter.setBrush( ball->getColor() );
    painter.drawEllipse( ball->getShape() );
    painter.fillRect( paddle->getShape(), paddle->getColor() );

    foreach( Brick *brick, bricks )
    painter.fillRect( brick->getShape(), brick->getColor() );
}

void Game::movePaddleLeft()
{
    if( paddle->getLeft() > rect().left() )
    {
    paddle->moveLeft();
    update();
    }
}

void Game::movePaddleRight()
{
    if( paddle->getRight() < rect().right() )
    {
    paddle->moveRight();
    update();
    }
}

void Game::startGame()
{
    timer->start();
}

void Game::stopGame()
{
    timer->stop();
}

void Game::moveBall()
{
    ball->move();

    QRectF ballShape = ball->getShape();
    QRectF paddleShape = paddle->getShape();

    qreal ballLeft = ballShape.left();
    qreal ballRight = ballShape.right();
    qreal ballBottom = ballShape.bottom();
    qreal ballTop = ballShape.top();
    qreal ballCenterX = ( ballShape.left() + ballShape.right() ) / 2;
    qreal paddleCenterX = ( paddleShape.left() + paddleShape.right() ) / 2;

    if( ballLeft < rect().left() || ballRight > rect().right()  )
    ball->setDirX( -ball->getDirX() );


    if( ballBottom >= paddleShape.top() )
    {
     if( paddleShape.intersects( ballShape ) )
     {
         if( ballCenterX < paddleCenterX )
         ball->setDirX( -ball->getDirX() );
         ball->setDirY( -ball->getDirY() );
     }
     else
     {
         isFailure = true;
         update();
         return;
     }
    }

    if( ballTop < rect().top() )
    ball->setDirY( -ball->getDirY() );
    else
    {
    for( int i = 0; i < bricks.size(); ++i )
    {
        Brick *brick = bricks.at( i );
        QRectF brickShape = brick->getShape();
        if( brickShape.intersects( ball->getShape() ) )
        {
        ball->setDirY( -ball->getDirY() );
        Brick *temp = bricks.takeAt( i );
        delete temp;
        score += 100;
        emit scoreChanged( score );
        }
    }

    if( bricks.size() == 0 )
    isWin = true;
    }

    update();
}

void Game::setBallSpeed( qreal speed )
{
    ball->setSpeed( speed );
}

void Game::setPaddleStep( qreal step )
{
    paddle->setStep( step );
}

bool intersects ( const QRectF & rectangle )
{

}
