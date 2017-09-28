#-------------------------------------------------
#
# Project created by QtCreator 2017-08-29T11:01:02
#
#-------------------------------------------------

QT       += core gui widgets testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test1
TEMPLATE = app

LIBS += -L /usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_calib3d

SOURCES += main.cpp\
    imagetools.cpp \
    mainwindow.cpp \
    rtspcamera.cpp \
    imagelabel.cpp \
    labelscroll.cpp \
    pointInfolistwidget.cpp \
    pointinfowidget.cpp

HEADERS  += \
    imagetools.h \
    mainwindow.h \
    rtspcamera.h \
    imagelabel.h \
    labelscroll.h \
    pointInfolistwidget.h \
    pointinfowidget.h

FORMS    += mainwindow.ui \
    pointinfowidget.ui


RESOURCES += \
    qrc/resources.qrc

DISTFILES +=
