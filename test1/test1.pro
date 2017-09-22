#-------------------------------------------------
#
# Project created by QtCreator 2017-08-29T11:01:02
#
#-------------------------------------------------

QT       += core gui widgets testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Scroll.cpp \
    Label.cpp \
    Imagetools.cpp \
    rtspcamera.cpp \
    mylistwidget.cpp \
    Pointinfo.cpp

HEADERS  += mainwindow.h \
    Scroll.h \
    Label.h \
    Imagetools.h \
    rtspcamera.h \
    mylistwidget.h \
    Pointinfo.h

FORMS    += mainwindow.ui \
    Pointifo.ui

INCLUDEPATH += hikvision
LIBS += -L. -lhcnetsdk -lPlayCtrl -lAudioRender -lSuperRender -lhpr -lHCCore
LIBS += -L /usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_calib3d
