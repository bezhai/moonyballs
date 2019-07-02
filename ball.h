#ifndef _BALL_H_
#define _BALL_H_

#include <QRect>
#include <QColor>

class Ball
{
public:
    Ball(qreal, qreal, qreal, QColor = Qt::green );
    ~Ball();
    
    void move();
    QRect rect() const;
    
    void setShape( const QRectF & );
    void setColor( const QColor & );
    void setDirX( qreal );
    void setDirY( qreal );
    void setSpeed( qreal );
    
    QRectF getShape() const;
    QColor getColor() const;
    qreal getDirX() const;
    qreal getDirY() const;
    qreal getSpeed() const;
    
private:
    QRectF *shape;
    QColor color;
 
    qreal dirX;
    qreal dirY;
    qreal speed;

};

#endif
