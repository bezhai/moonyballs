#-------------------------------------------------
#
# Project created by QtCreator 2019-07-03T08:44:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = moonyballs
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        difficulty_choose.cpp \
        failed.cpp \
        game.cpp \
        guidepage.cpp \
        login.cpp \
        main.cpp \
        mainlogic/barrier_generate.cpp \
        mainlogic/barriers.cpp \
        mainlogic/basic_shape.cpp \
        mainlogic/crash_control.cpp \
        mainlogic/math_setting.cpp \
        mainlogic/object_shift.cpp \
        mainlogic/prop.cpp \
        mainwindow.cpp \
        pausemenu.cpp \
        ranking_list.cpp \
        saves.cpp

HEADERS += \
        difficulty_choose.h \
        failed.h \
        game.h \
        guidepage.h \
        login.h \
        mainlogic/barrier_generate.h \
        mainlogic/barriers.h \
        mainlogic/basic_shape.h \
        mainlogic/crash_control.h \
        mainlogic/math_setting.h \
        mainlogic/object_shift.h \
        mainlogic/prop.h \
        mainwindow.h \
        pausemenu.h \
        ranking_list.h \
        saves.h

FORMS += \
        difficulty_choose.ui \
        failed.ui \
        game.ui \
        guidepage.ui \
        login.ui \
        mainwindow.ui \
        pausemenu.ui \
        ranking_list.ui \
        saves.ui
INCLUDEPATH += "D:/Windows Kits/10/Include/10.0.17763.0/ucrt"

LIBS += -L"D:/Windows Kits/10/Lib/10.0.17763.0/ucrt/x64"

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc
