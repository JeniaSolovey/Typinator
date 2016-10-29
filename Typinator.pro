#-------------------------------------------------
#
# Project created by QtCreator 2016-10-27T22:55:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Typinator
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    player.cpp \
    enemy.cpp \
    spawner.cpp

HEADERS  += \
    game.h \
    player.h \
    enemy.h \
    spawner.h

RESOURCES += \
    res.qrc
