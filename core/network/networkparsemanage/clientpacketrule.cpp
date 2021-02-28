#include "clientpacketrule.h"

#include <QDebug>

namespace Core{

ClientPacketRule::ClientPacketRule()
{

}

ClientPacketRule::~ClientPacketRule()
{
    m_fixedRingBuffer.clear();
}

/**
 * @brief 接收网络数据
 * @param networkdId ： 发送端Ip
 * @param port :   发送端网络
 * @param data ：数据
 * @param length ：数据长度
 * @return
 */
bool ClientPacketRule::unwrap(QString networkdId, int port,  const char *data, const int length)
{
    this->networkIp = networkdId;
    this->networkPort = port;
    bool unwrapResult = false;
    m_fixedRingBuffer.append(data, length);
    unwrapResult = dealOriginalData();
    return unwrapResult;
}

/*!
 *  @brief 处理原始数据
 * @note 将原始数据根据数据信息进行数据拼接，拼成完整一包
 */
bool ClientPacketRule::dealOriginalData()
{
    ProtocolDataStruct::PacketHeadInfo t_packetHead;

    if(m_fixedRingBuffer.dataSize() > sizeof(ProtocolDataStruct::PacketHeadInfo)){
        do {
            //【】 预读取报头长度
            m_fixedRingBuffer.preRead((char*)&t_packetHead, sizeof(ProtocolDataStruct::PacketHeadInfo));

            if(t_packetHead.flag == m_packetHeadInfo.flag) {
                //【】 判断至少存在完整的一包数据
                int t_complete = t_packetHead.length + sizeof(ProtocolDataStruct::PacketHeadInfo)
                        + sizeof(ProtocolDataStruct::PacketTailInfo);
                if(t_complete <= m_fixedRingBuffer.dataSize()) {
                    //[1]读取完整的一包到缓存中
                    char *t_buff = new char[sizeof(ProtocolDataStruct::PacketHeadInfo) + t_packetHead.length];
                    m_fixedRingBuffer.read(t_buff, sizeof(ProtocolDataStruct::PacketHeadInfo) + t_packetHead.length);
                    //【】 Crc16检验
                    uint check = RUtil::Crc16check(t_buff, sizeof(ProtocolDataStruct::PacketHeadInfo) + t_packetHead.length);
                    //【】 读取包尾
                    ProtocolDataStruct::PacketTailInfo tail;
                    m_fixedRingBuffer.read((char*)&tail, sizeof(ProtocolDataStruct::PacketTailInfo));
                    if(check != tail.tail)
                        return false;
                    //【】 处理数据
                    processData(t_buff, sizeof(ProtocolDataStruct::PacketHeadInfo) + t_packetHead.length);
                    delete [] t_buff;
                    //【】 判断剩余数据
                    if(m_fixedRingBuffer.dataSize() <= 0)
                        break;

                    if(m_fixedRingBuffer.dataSize() >= sizeof(ProtocolDataStruct::PacketHeadInfo))
                        continue;
                } else {
                    break;
                }
            } else {
                break;
            }
        }while (m_fixedRingBuffer.dataSize() > 0) ;
    }
    return true;
}

/**
 * @brief 解析数据信息
 * @param data
 * @param lenth
 * @return
 */
bool ClientPacketRule::processData(const char *data, int lenth)
{
    SystemDatastruct::ProtocolArray *array = new SystemDatastruct::ProtocolArray();
    array->networkId = this->networkIp;
    array->socketId = this->networkPort;

    array->m_sz_senderIp = this->networkIp;
    array->m_us_senderPort = this->networkPort;;
    array->data->resize(lenth);
    array->data->clear();
    array->data->append(data, lenth);

    appendDataToQueue(array);
    return true;
}

/*!
 * @brief 添加原始数据至缓冲队列，唤醒解析线程处理
 * @param[in] array 封装后的数据体
 */
void ClientPacketRule::appendDataToQueue(SystemDatastruct::ProtocolArray *array)
{
//    NetworkGlobal::g_mutex_recvCmdClientQueueMutex.lock();
//    NetworkGlobal::g_recvCmdClientQueue.push_back(array);
//    NetworkGlobal::g_mutex_recvCmdClientQueueMutex.unlock();
//    NetworkGlobal::g_cv_recvCmdClientQuqueCondition.notify_one();
}

} //namespace Core
