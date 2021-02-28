#include "serverpacketrule.h"

#include <QDebug>

namespace Core {

ServerPacketRule::ServerPacketRule()
{

}

ServerPacketRule::~ServerPacketRule()
{

}

bool ServerPacketRule::unwrap(QString networkdId, int port, const char *data, const int length)
{

    return true;
}


}//namespace Core
