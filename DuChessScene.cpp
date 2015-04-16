#include "DuChessBoard.h"
#include "DuChessScene.h"
#include "DuDefines.h"
#include <QGraphicsSceneMouseEvent>

DuChessScene::DuChessScene(QObject *parent)
    : QGraphicsScene(0.0, 0.0, BOARDWIDTH, BOARDHEIGHT, parent)
{
    createObjects();
    configureChessBoard();
}

void DuChessScene::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    mUnderMouse = getUnderMouse();
    mMoveEnabled = mUnderMouse;
    e->accept();
}

void DuChessScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    mMoveEnabled = false;
    mUnderMouse = nullptr;
    e->accept();
}

void DuChessScene::configureChessBoard()
{
    // chess board
    addItem(mBoard);

    // black pieces
    addBlackPiece(0, DuChessPiece::Type::ROOK);
    addBlackPiece(1, DuChessPiece::Type::KNIGHT);
    addBlackPiece(2, DuChessPiece::Type::BISHOP);
    addBlackPiece(3, DuChessPiece::Type::QUEEN);
    addBlackPiece(4, DuChessPiece::Type::KING);
    addBlackPiece(5, DuChessPiece::Type::BISHOP);
    addBlackPiece(6, DuChessPiece::Type::KNIGHT);
    addBlackPiece(7, DuChessPiece::Type::ROOK);
    for (int i = 0; i < 8; ++i) {
        addBlackPiece(i, DuChessPiece::Type::PAWN);
    }

    // white pieces
    addWhitePiece(0, DuChessPiece::Type::ROOK);
    addWhitePiece(1, DuChessPiece::Type::KNIGHT);
    addWhitePiece(2, DuChessPiece::Type::BISHOP);
    addWhitePiece(3, DuChessPiece::Type::QUEEN);
    addWhitePiece(4, DuChessPiece::Type::KING);
    addWhitePiece(5, DuChessPiece::Type::BISHOP);
    addWhitePiece(6, DuChessPiece::Type::KNIGHT);
    addWhitePiece(7, DuChessPiece::Type::ROOK);
    for (int i = 0; i < 8; ++i) {
        addWhitePiece(i, DuChessPiece::Type::PAWN);
    }
}

void DuChessScene::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
    if (!mMoveEnabled) {
        e->accept();
        return;
    }
    auto p = e->scenePos().toPoint();
    p.setX(p.x()-35);
    p.setY(p.y()+30);
    mUnderMouse->setPos(p);
    update();
    e->accept();
}

DuChessPiece *DuChessScene::getUnderMouse() const
{
    auto allItems = items();
    for (const auto &i : allItems) {
        if (i->isUnderMouse() && i != mBoard) {
            return dynamic_cast<DuChessPiece *>(i);
        }
    }
    return nullptr;
}

void DuChessScene::addBlackPiece(int n, DuChessPiece::Type type)
{
    if (type == DuChessPiece::Type::PAWN) {
        addItem(new DuChessPiece(QPoint(n * BOARDWIDTH / 8 + 5, 150), type,
                                 DuChessPiece::Color::BLACK,
                                 QFont("courier", 55)));
        return;
    }
    addItem(new DuChessPiece(QPoint(n * BOARDWIDTH / 8 + 5, 65), type,
                             DuChessPiece::Color::BLACK, QFont("courier", 55)));
}

void DuChessScene::addWhitePiece(int n, DuChessPiece::Type type)
{
    if (type == DuChessPiece::Type::PAWN) {
        addItem(new DuChessPiece(QPoint(n * BOARDWIDTH / 8 + 5, 570), type,
                                 DuChessPiece::Color::WHITE,
                                 QFont("courier", 55)));
        return;
    }
    addItem(new DuChessPiece(QPoint(n * BOARDWIDTH / 8 + 5,
                                    7 * BOARDHEIGHT / 8 + 65), type,
                             DuChessPiece::Color::WHITE, QFont("courier", 55)));
}

void DuChessScene::createObjects()
{
    mMoveEnabled = false;
    mUnderMouse = nullptr;
    mBoard = new DuChessBoard;
}
