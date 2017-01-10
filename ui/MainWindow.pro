#-------------------------------------------------
#
# Project created by QtCreator 2017-01-06T11:28:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainWindow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    configdialog.cpp \
    detectframe.cpp

HEADERS  += mainwindow.h \
    configdialog.h \
    detectframe.h

FORMS    += \
    Main \
    configdialog.ui \
    detectframe.ui
