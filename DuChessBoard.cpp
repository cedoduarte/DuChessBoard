#include "DuChessBoard.h"
#include "DuDefines.h"
#include <QPainter>

DuChessBoard::DuChessBoard(QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
}

QRectF DuChessBoard::boundingRect() const
{
    return QRectF(0, 0, BOARDWIDTH, BOARDHEIGHT);
}

void DuChessBoard::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                         QWidget *)
{
    painter->drawPixmap(0, 0, BOARDWIDTH, BOARDHEIGHT,
                        QPixmap(":chessboard"));
}
