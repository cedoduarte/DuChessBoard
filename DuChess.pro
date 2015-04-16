#-------------------------------------------------
#
# Project created by QtCreator 2015-01-23T16:11:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DuChess
TEMPLATE = app

SOURCES += main.cpp\
    DuChessPiece.cpp \
    DuChessScene.cpp \
    DuChessBoard.cpp \
    Widget.cpp

HEADERS  += \
    DuChessPiece.h \
    DuChessBoard.h \
    DuChessScene.h \
    DuDefines.h \
    Widget.h

FORMS    += \
    Widget.ui

RESOURCES += \
    res.qrc

QMAKE_CXXFLAGS += -std=gnu++14
