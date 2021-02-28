#网络模块
INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

HEADERS += \
    $$PWD/networkchannel/udpmulticasttask.h \
    $$PWD/networkchannel/udpunicasttask.h \
    $$PWD/networkchannel/tcpclienttask.h \
    $$PWD/networkchannel/tcpservertask.h \
    $$PWD/networkmanager.h \
    $$PWD/networkparsemanage/packetrule.h \
    $$PWD/networkparsemanage/protocolparse.h \
    $$PWD/networkparsemanage/clientpacketrule.h \
    $$PWD/networkparsemanage/clientprotocolparse.h \
    $$PWD/networkparsemanage/serverpacketrule.h \
    $$PWD/networkparsemanage/unicastpacketrule.h \
    $$PWD/networkparsemanage/multicastpacketrule.h \
    $$PWD/networkprotocol.h


SOURCES += \
    $$PWD/networkchannel/udpmulticasttask.cpp \
    $$PWD/networkchannel/udpunicasttask.cpp \
    $$PWD/networkchannel/tcpclienttask.cpp \
    $$PWD/networkchannel/tcpservertask.cpp \
    $$PWD/networkmanager.cpp \
    $$PWD/networkparsemanage/packetrule.cpp \
    $$PWD/networkparsemanage/protocolparse.cpp \
    $$PWD/networkparsemanage/clientpacketrule.cpp \
    $$PWD/networkparsemanage/clientprotocolparse.cpp \
    $$PWD/networkparsemanage/serverpacketrule.cpp \
    $$PWD/networkparsemanage/unicastpacketrule.cpp \
    $$PWD/networkparsemanage/multicastpacketrule.cpp \
    $$PWD/networkprotocol.cpp


FORMS +=
