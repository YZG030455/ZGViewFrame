/*!
 *  @brief    数据包管理类
 *  @details  接收网络的原始数据包
 *  @author   yzg
 *  @version  v1.0
 *  @date     2020.01.17
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef PACKETRULE_H
#define PACKETRULE_H

#include <QObject>

#include "global.h"
#include "protocol/systemdatastruct.h"
#include "protocol/protocoldatastruct.h"
#include "messdispath.h"

#include "utils/rringbuffer.h"

namespace Core {

class PacketRule
{
public:
    PacketRule();
    ~PacketRule();

    bool unwrap(QString networkdId, int port, const char * data, const int length);

private:
    bool dealData(QString networkdId, int port, const char *data, int lenth);
    void appendDataToQueue(SystemDatastruct::ProtocolArray &array);

private:
    QString networkId;
    ushort m_us_port;

};

} //namespace Core

#endif // PACKETRULE_H
