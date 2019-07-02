#include "ball.h"

Ball::Ball(qreal x, qreal y, qreal radius, QColor ballColor)
{
    dirX = 1.0;
    dirY = -1.0;
    speed = 1.0;
    
    shape = new QRectF (x, y, radius, radius);
    color = ballColor;
}

Ball::~Ball()
{
    delete shape;
}

void Ball::setShape( const QRectF &newShape )
{
    shape->setRect( newShape.left(), newShape.top(),
		    newShape.width(), newShape.height() );
}
 
void Ball::setColor( const QColor &newColor )
{
    color = newColor;
}
 
void Ball::setDirX( qreal newDirX )
{
    dirX = newDirX;
}
 
void Ball::setDirY( qreal newDirY )
{
    dirY = newDirY;
}
 
QRectF Ball::getShape() const
{
    return QRectF( shape->left(), shape->top(),
		  shape->width(), shape->height() );
}
 
QColor Ball::getColor() const
{
    return color;
}
 
qreal Ball::getDirX() const
{
    return dirX;
}
 
qreal Ball::getDirY() const
{
    return dirY;
}
 
void Ball::move()
{
    shape->setLeft( shape->left() + dirX );
    shape->setRight( shape->right() + dirX );
    shape->setTop( shape->top() + dirY );
    shape->setBottom( shape->bottom() + dirY );
}
 
void Ball::setSpeed( qreal newSpeed )
{
    speed = newSpeed;
    setDirX( speed );
    setDirY( -speed );
}
 
qreal Ball::getSpeed() const
{
    return speed;
}
