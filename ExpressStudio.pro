#-------------------------------------------------
#
# Project created by QtCreator 2015-11-30T11:57:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExpressStudio
TEMPLATE = app


SOURCES += main.cpp\
        main_window.cpp \
    instrument.cpp

HEADERS  += main_window.h \
    instrument.h

FORMS    += mainwindow.ui
