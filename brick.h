#ifndef BRICK_H
#define BRICK_H

#include <QRect>
#include <QColor>

class Brick
{
public:
  Brick( qreal, qreal, qreal, qreal, QColor = Qt::red);
  ~Brick();

  void setShape(const QRectF &);
  void setColor(const QColor &);

  QRectF getShape() const;
  QColor getColor() const;

private:
  QRectF *shape;
  QColor color;
};

#endif // BRICK_H
