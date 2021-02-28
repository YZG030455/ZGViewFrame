#ifndef UNICASTPACKETRULE_H
#define UNICASTPACKETRULE_H

#include <QObject>

#include "global.h"
#include "protocol/systemdatastruct.h"
#include "protocol/protocoldatastruct.h"
#include "messdispath.h"

#include "utils/rringbuffer.h"

namespace Core {

class UnicastPacketRule
{
public:
    UnicastPacketRule();
    ~UnicastPacketRule();

    bool unwrap(QString networkdId, int port, const char * data, const int length);

};

}//namespace Core

#endif // UNICASTPACKETRULE_H
