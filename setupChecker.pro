#-------------------------------------------------
#
# Project created by QtCreator 2017-11-23T23:02:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = setupChecker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pingthread.cpp

HEADERS  += mainwindow.h \
    pingthread.h

FORMS    += mainwindow.ui
