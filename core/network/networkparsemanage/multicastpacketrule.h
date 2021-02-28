#ifndef MULTICASTPACKETRULE_H
#define MULTICASTPACKETRULE_H

#include <QObject>

#include "global.h"
#include "protocol/systemdatastruct.h"
#include "protocol/protocoldatastruct.h"
#include "messdispath.h"

#include "utils/rringbuffer.h"

namespace Core {

class MulticastPacketRule
{
public:
    MulticastPacketRule();
    ~MulticastPacketRule();

    bool unwrap(QString networkdId, int port, const char * data, const int length);

};

}//namespace Core

#endif // MULTICASTPACKETRULE_H
