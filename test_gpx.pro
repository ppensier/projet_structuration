#-------------------------------------------------
#
# Project created by QtCreator 2015-10-09T09:24:50
#
#-------------------------------------------------

QT       += core gui
QT +=opengl
QT += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_gpx
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    Point.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    Point.h

FORMS    += mainwindow.ui
