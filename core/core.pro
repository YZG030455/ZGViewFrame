QT += core gui
QT += xml
QT += serialport
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(../app.pri)

include($$PWD/database/database.pri)

#include($$PWD/serialport/serialport.pri)
#include($$PWD/network/network.pri)
include($$PWD/plugintools/plugintools.pri)
include($$PWD/widgets/widgets.pri)


TEMPLATE = lib
DEFINES += CORE_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    file/globalconfigfile.cpp \
    file/programfilepath.cpp \
    global.cpp \
    mainobject.cpp \
    mainwindow.cpp \
    messdispath.cpp \
    utils/regexp.cpp \
    utils/rlog.cpp \
    utils/rringbuffer.cpp \
    utils/rscreenshottool.cpp \
    utils/rsingleton.cpp \
    utils/rutil.cpp

HEADERS += \
    constants/constants.h \
    core_global.h \
    file/globalconfigfile.h \
    file/programfilepath.h \
    global.h \
    mainobject.h \
    mainwindow.h \
    messdispath.h \
    utils/regexp.h \
    utils/rlog.h \
    utils/rringbuffer.h \
    utils/rscreenshottool.h \
    utils/rsingleton.h \
    utils/rutil.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    resource.qrc

RC_FILE = myicon.rc




