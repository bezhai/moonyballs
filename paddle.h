#ifndef _PADDLE_H_
#define _PADDLE_H_

#include <QRect>
#include <QColor>

class Paddle
{
public:
    Paddle( qreal, qreal, qreal, qreal, QColor = Qt::blue );
    ~Paddle();

    QRectF getShape() const;
    QColor getColor() const;
    qreal getLeft() const;
    qreal getRight() const;
    qreal getStep() const;

    void setShape( const QRectF & );
    void setColor( const QColor & );
    void setLeft( qreal );
    void setRight( qreal );
    void setStep( qreal );

    void moveLeft();
    void moveRight();

private:
    QRectF *shape;
    QColor color;
    qreal step;
};


#endif
