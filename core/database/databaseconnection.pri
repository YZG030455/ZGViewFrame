#数据库
INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD


HEADERS += \
    $$PWD/database.h \
    $$PWD/databaseprotocol.h \
    $$PWD/databasetables/databasetable.h \
    $$PWD/databasemanager.h

SOURCES += \
    $$PWD/database.cpp \
    $$PWD/databaseprotocol.cpp \
    $$PWD/databasetables/databasetable.cpp \
    $$PWD/databasemanager.cpp


