#ifndef _GAME_H_
#define _GAME_H_

#include "ball.h"
#include "paddle.h"
#include "brick.h"
#include <QWidget>

class QTimer;

class Game : public QWidget
{
    Q_OBJECT
public:
    Game( QWidget * = 0 );
    ~Game();


    void setBallSpeed( qreal );
    void setBricksNumbers( int , int );
    void setPaddleStep( qreal );

signals:
    void finished();
    void scoreChanged( int );

public slots:
    void moveBall();
    void changeColor();
    void movePaddleLeft();
    void movePaddleRight();
    void startGame();
    void stopGame();

protected:
    void paintEvent( QPaintEvent * );
    void resizeEvent( QResizeEvent * );

private:
    void createBricks();
    void createPaddle();
    void createBall();

    QRectF adjustShape( QRectF, qreal, qreal );
    QColor randomColor();
    int randomInt( int );

    Ball *ball;
    Paddle *paddle;
    QList< Brick * > bricks;
    QTimer *timer;

    int rows;
    int columns;
    int score;
    bool isWin;
    bool isFailure;

    double frameWidth;
    double frameHeight;
};

#endif
