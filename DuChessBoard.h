#ifndef DUCHESSBOARD_H
#define DUCHESSBOARD_H

#include <QGraphicsItem>

class DuChessBoard : public QGraphicsItem
{
public:
    DuChessBoard(QGraphicsItem *parent = nullptr);
protected:
    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *,
               QWidget *) override;
};

#endif // DUCHESSBOARD_H
