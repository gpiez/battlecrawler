#-------------------------------------------------
#
# Project created by QtCreator 2015-11-04T16:37:02
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = battlecrawler
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wowinterface.cpp \
    censusdatabase.cpp

HEADERS  += mainwindow.h \
    wowinterface.h \
    censusdatabase.h

FORMS    += mainwindow.ui
