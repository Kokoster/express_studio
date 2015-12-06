#-------------------------------------------------
#
# Project created by QtCreator 2015-11-30T11:57:31
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExpressStudio
TEMPLATE = app
CONFIG += c++11


SOURCES += src/instrument.cpp \
    src/main.cpp \
    src/main_window.cpp \
    src/component.cpp

HEADERS  += src/instrument.h \
    src/main_window.h \
    src/point.h \
    src/component.h

FORMS    += mainwindow.ui

DISTFILES += \
    res/background/18qpu6wwtukumjpg.jpg \
    res/background/derevyannaya-komnata-[2560x1600]-[6050074].jpg \
    res/background/grey_room.jpg \
    res/background/grey_room_trial.jpg \
    res/background/grey_room_trial2.jpg \
    res/background/light_empty_room.jpg \
    res/background/white_room.jpg \
    res/instruments/Drums/pearl-e-pro-live.jpg \
    res/instruments/Drums/brooklyn_kit.png \
    res/instruments/Drums/disabled_drums.png \
    res/instruments/Drums/drums copy.png \
    res/instruments/Drums/drums.png \
    res/instruments/Guitars/AmpwithGuitar1011a.png \
    res/instruments/Guitars/disabled_guitar.png \
    res/instruments/Guitars/guitarwithamp_small_.png \
    res/instruments/Drums/drums copy.png \
    res/instruments/Guitars/guitar.png \
    res/menu/55c0d2a54f5f4_340.png \
    res/menu/city.png \
    res/menu/flowers.png \
    res/menu/street.png \
    res/menu/tea_time.png
