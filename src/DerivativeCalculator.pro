#-------------------------------------------------
#
# Project created by QtCreator 2012-12-03T18:40:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DerivativeCalculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

CONFIG += exceptions

win32 {
    LIBS += 3rdPart/SWI-Prolog-6.3.7/lib/libswipl.dll.a
    LIBS += 3rdPart/SWI-Prolog-6.3.7/lib/libpthreadGC2.dll.a
    LIBS += 3rdPart/SWI-Prolog-6.3.7/lib/plterm.dll.a
    INCLUDEPATH += "3rdPart/SWI-Prolog-6.3.7/include"
}
