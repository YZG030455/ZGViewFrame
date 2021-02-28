#include "packetrule.h"

#include <QDebug>

namespace Core {

PacketRule::PacketRule()
{

}

PacketRule::~PacketRule()
{

}

/**
 * @brief 接收数据信息
 * @param ip
 * @param port
 * @param data
 * @param length
 * @return
 */
bool PacketRule::unwrap(QString ip, int port, const char *data, const int length)
{

    return dealData(ip, port, data, length);
}

/**
 * @brief 处理数据
 * @param networkdId
 * @param port
 * @param data
 * @param lenth
 * @return
 */
bool PacketRule::dealData(QString networkdId, int port, const char *data, int lenth)
{
//    NetworkGlobal::ProtocolArray array;
//    array.m_sz_senderIp = networkdId;
//    array.m_us_senderPort = port;
//    array.data->resize(lenth);
//    array.data->clear();
//    array.data->append(data, lenth);
//    appendDataToQueue(array);
    return true;
}

/**
 * @brief 将按原始数据添加至数据协议队列中
 * @param array
 */
void PacketRule::appendDataToQueue(SystemDatastruct::ProtocolArray &array)
{
//    g_mutex_recvQueueMutex.lock();
//    g_recvQueue.push_back(array);
//    g_mutex_recvQueueMutex.unlock();
//    g_cv_recvQuqueCondition.notify_one();
}

} //namespace Core
