#-------------------------------------------------
#
# Project created by QtCreator 2015-11-05T14:45:39
#
#-------------------------------------------------

QT       += core gui multimedia serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = XmasTest
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    track.cpp \
    binarytrack.cpp \
    visualdisplay.cpp \
    channeloptions.cpp \
    channelcolordisplay.cpp \
    module.cpp \
    moduledialog.cpp \
    serialportoptions.cpp \
    playlist.cpp

HEADERS  += mainwindow.h \
    track.h \
    binarytrack.h \
    visualdisplay.h \
    channeloptions.h \
    channelcolordisplay.h \
    module.h \
    moduledialog.h \
    serialportoptions.h \
    playlist.h

FORMS    += mainwindow.ui \
    moduledialog.ui \
    serialportoptions.ui \
    playlist.ui
