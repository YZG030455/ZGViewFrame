#ifndef SERVERPACKETRULE_H
#define SERVERPACKETRULE_H

#include <QObject>

#include "global.h"
#include "protocol/systemdatastruct.h"
#include "protocol/protocoldatastruct.h"
#include "messdispath.h"

#include "utils/rringbuffer.h"

namespace Core {

class ServerPacketRule
{
public:
    ServerPacketRule();
    ~ServerPacketRule();

    bool unwrap(QString networkdId, int port, const char * data, const int length);


};

} //namespace Core

#endif // SERVERPACKETRULE_H
