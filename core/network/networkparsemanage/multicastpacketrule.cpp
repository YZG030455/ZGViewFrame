#include "multicastpacketrule.h"

#include <QDebug>

namespace Core {

MulticastPacketRule::MulticastPacketRule()
{

}

MulticastPacketRule::~MulticastPacketRule()
{

}

bool MulticastPacketRule::unwrap(QString networkdId, int port, const char *data, const int length)
{

    return true;
}


}//namespace Core
