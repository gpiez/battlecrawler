#-------------------------------------------------
#
# Project created by QtCreator 2015-11-04T16:37:02
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11
TARGET = battlecrawler
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    censusdatabase.cpp \
    armory.cpp \
    player.cpp \
    guild.cpp \
    armoryguild.cpp \
    character.cpp \
    armorycharacter.cpp \
    bossindex.cpp \
    achievementindex.cpp

HEADERS  += mainwindow.h \
    censusdatabase.h \
    armory.h \
    player.h \
    guild.h \
    armoryguild.h \
    character.h \
    armorycharacter.h \
    bossindex.h \
    achievementindex.h

FORMS    += mainwindow.ui
