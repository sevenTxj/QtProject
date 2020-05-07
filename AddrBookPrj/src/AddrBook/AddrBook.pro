#-------------------------------------------------
#
# Project created by QtCreator 2020-04-26T22:01:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AddrBook
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addrbook.cpp \
    findDialog.cpp

HEADERS  += mainwindow.h \
    addrbook.h \
    findDialog.h

FORMS    += mainwindow.ui
