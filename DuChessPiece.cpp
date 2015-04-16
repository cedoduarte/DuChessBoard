#include "DuChessPiece.h"
#include "DuDefines.h"
#include <QPainter>

DuChessPiece::DuChessPiece(const QPoint &pos, Type type, Color color,
                           const QFont &font, QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    mPos = pos;
    mType = type;
    mColor = color;
    mFont = font;
}

QRectF DuChessPiece::boundingRect() const
{
    return QRect(mPos.x() - 5, mPos.y() - 65, BOARDWIDTH / 8,
                 BOARDHEIGHT / 8);
}

void DuChessPiece::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                         QWidget *)
{
    QString peace;
    switch (mType) {
    case Type::PAWN:
        peace = mColor == Color::WHITE ? "♙" : "♟";
        break;
    case Type::KING:
        peace = mColor == Color::WHITE ? "♔" : "♚";
        break;
    case Type::QUEEN:
        peace = mColor == Color::WHITE ? "♕" : "♛";
        break;
    case Type::ROOK:
        peace = mColor == Color::WHITE ? "♖" : "♜";
        break;
    case Type::KNIGHT:
        peace = mColor == Color::WHITE ? "♘" : "♞";
        break;
    case Type::BISHOP:
        peace = mColor == Color::WHITE ? "♗" : "♝";
        break;
    }
    painter->setFont(mFont);
    painter->drawText(mPos.x(), mPos.y(), peace);

    // for debugging
    //    painter->setPen(Qt::red);
    //    painter->drawRect(boundingRect());
}
