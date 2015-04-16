#ifndef DUCHESSPEACE_H
#define DUCHESSPEACE_H

#include <QGraphicsItem>
#include <QFont>

class DuChessPiece : public QGraphicsItem
{
public:
    enum class Type
    {
        PAWN,
        KING,
        QUEEN,
        ROOK,
        KNIGHT,
        BISHOP
    };

    enum class Color
    {
        WHITE,
        BLACK
    };

    DuChessPiece(const QPoint &pos, Type type, Color color,
                 const QFont &font, QGraphicsItem *parent = nullptr);

    void setPos(const QPoint &pos)
    {
        mPos = pos;
    }

    QPoint getPos() const
    {
        return mPos;
    }
protected:
    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;
private:
    Type mType;
    Color mColor;
    QFont mFont;
    QPoint mPos;
};

#endif // DUCHESSPEACE_H
