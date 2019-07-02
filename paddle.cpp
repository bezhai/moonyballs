#include "paddle.h"
#include <QColor>
#include <QPoint>

Paddle::Paddle( qreal x, qreal y, qreal width, qreal height, QColor paddleColor )
{
    shape = new QRectF( x, y, width, height );
    color = paddleColor;
    step = 10.0;
}

Paddle::~Paddle()
{
    delete shape;
}

void Paddle::setColor( const QColor &newColor )
{
    color = newColor;
}

QColor Paddle::getColor() const
{
    return color;
}

void Paddle::setShape( const QRectF &newShape )
{
    shape->setRect( newShape.left(), newShape.top(),
            newShape.width(), newShape.height() );
}

QRectF Paddle::getShape() const
{
    return QRectF( shape->left(), shape->top(),
          shape->width(), shape->height() );
}

void Paddle::moveLeft()
{
    shape->setLeft( shape->left() - step );
    shape->setRight( shape->right() - step );
}

void Paddle::moveRight()
{
    shape->setLeft( shape->left() + step );
    shape->setRight( shape->right() + step );
}

void Paddle::setLeft( qreal left )
{
    shape->setLeft( left );
}

void Paddle::setRight( qreal right )
{
    shape->setRight( right );
}

qreal Paddle::getLeft() const
{
    return shape->left();
}

qreal Paddle::getRight() const
{
    return shape->right();
}

void Paddle::setStep( qreal newStep )
{
    step = newStep;
}

qreal Paddle::getStep() const
{
    return step;
}
