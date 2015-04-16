#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ui_widget.h"
#include "DuChessScene.h"

namespace Ui
{
class Widget;
}

class Widget : public QWidget
{
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    Ui::Widget *ui;
    DuChessScene *mScene;
};

#endif // WIDGET_H
