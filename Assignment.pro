#-------------------------------------------------
#
# Project created by QtCreator 2014-12-29T00:10:30
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Assignment
TEMPLATE = app

SOURCES += \
    glslprogram.cpp \
    glutils.cpp \
    main.cpp \
    mainview.cpp \
    scenebasic.cpp \
    LinePanel.cpp \

HEADERS  += \
    glslprogram.h \
    glutils.h \
    mainview.h \
    scene.h \
    scenebasic.h \
    LinePanel.h \

macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lGLEW

INCLUDEPATH += $$PWD/../../../../../usr/local/lib
DEPENDPATH += $$PWD/../../../../../usr/local/lib
