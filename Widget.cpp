#include "Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mScene = new DuChessScene(this);
    ui->graphicsView->setScene(mScene);
}

Widget::~Widget()
{
    delete ui;
}
