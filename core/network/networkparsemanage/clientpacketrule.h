/*!
 *  @brief       数据包管理 ——》tcp客户端数据包
 *  @details    该类用于将固定长度的数据包进行组装
 *  @author    yzg
 *  @version   v1.0
 *  @date      2018.11.19
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef BL_PACKETRULE_H
#define BL_PACKETRULE_H

#include <QObject>

#include "global.h"
#include "utils/rutil.h"
#include "utils/rringbuffer.h"
#include "protocol/systemdatastruct.h"
#include "protocol/protocoldatastruct.h"
#include "messdispath.h"

namespace Core{

class ClientPacketRule
{
public:
    ClientPacketRule();
    ~ClientPacketRule();

    bool unwrap(QString networkdId, int port, const char * data,const int length);

private:
    bool dealOriginalData();
    bool processData(const char *data, int lenth);
    void appendDataToQueue(SystemDatastruct::ProtocolArray *array);

private:
    QString networkIp;                                                          /*!< 网卡ID */
    int networkPort;                                                                /*!< 当前包所属tcp连接ID */
    RFixedRingBuffer m_fixedRingBuffer;                                //环形数据缓存区
    ProtocolDataStruct::PacketHeadInfo m_packetHeadInfo;                //通用报头
    ProtocolDataStruct::PacketTailInfo m_packetTailInfo;                 //通用包尾
};

} //namespace Core

#endif // BL_PACKETRULE_H
