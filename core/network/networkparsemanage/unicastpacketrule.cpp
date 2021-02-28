#include "unicastpacketrule.h"

#include <QDebug>

namespace Core {

UnicastPacketRule::UnicastPacketRule()
{

}

UnicastPacketRule::~UnicastPacketRule()
{

}

bool UnicastPacketRule::unwrap(QString networkdId, int port, const char *data, const int length)
{

    return true;
}

}//namespace Core
