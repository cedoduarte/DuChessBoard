#ifndef DUCHESSSCENE_H
#define DUCHESSSCENE_H

#include <QGraphicsScene>
#include "DuChessPiece.h"

class DuChessBoard;

class DuChessScene : public QGraphicsScene
{
public:
    DuChessScene(QObject *parent = nullptr);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *e) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e) override;
private:
    void createObjects();
    void configureChessBoard();
    DuChessPiece *getUnderMouse() const;
    void addBlackPiece(int n, DuChessPiece::Type type);
    void addWhitePiece(int n, DuChessPiece::Type type);

    bool mMoveEnabled;
    DuChessBoard *mBoard;
    DuChessPiece *mUnderMouse;
};

#endif // DUCHESSSCENE_H
