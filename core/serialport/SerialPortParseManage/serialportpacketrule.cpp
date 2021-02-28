#include "serialportpacketrule.h"

#include <QDebug>

namespace Core {

SerialPortPacketRule::SerialPortPacketRule()
{

}

SerialPortPacketRule::~SerialPortPacketRule()
{

}

/**
 * @brief 接收数据信息
 * @param networkdId
 * @param clientId
 * @param data
 * @param length
 * @return
 */
bool SerialPortPacketRule::unwrap(QString serialPortId,const char *data, const int length)
{
    return dealSerialPortData(serialPortId, data, length);;
}

/**
 * @brief 处理串口数据
 * @param networkdId
 * @param data
 * @param lenth
 * @return
 */
bool SerialPortPacketRule::dealSerialPortData(QString SerialPortId, const char *data, int lenth)
{
    SystemDatastruct::SerialPortProtocolArray array;
    array.SerialPortId = SerialPortId;
    array.data->resize(lenth);
    array.data->clear();
    array.data->append(data, lenth);
    appendSerialPortDataToQueue(array);
    return true;
}

/**
 * @brief 将串口数据信息添加至队列中
 * @param array
 */
void SerialPortPacketRule::appendSerialPortDataToQueue(SystemDatastruct::SerialPortProtocolArray &array)
{
//    g_mutex_recvSerialPortQueueMutex.lock();
//    g_recvSerialPortQueue.push_back(array);
//    g_mutex_recvSerialPortQueueMutex.unlock();
//    g_cv_recvSerialPortQuqueCondition.notify_one();
}

} //namespace Core
