#include "protocolparse.h"

#include <QDebug>

namespace Core {

ProtocolParse::ProtocolParse(QObject *parent)
    : QThread(parent),
      m_isRunFlage(false)
{

}

ProtocolParse::~ProtocolParse()
{
    m_isRunFlage = false;
//    g_cv_recvQuqueCondition.notify_one();
    wait();
}

/**
 * @brief 开启线程
 */
void ProtocolParse::startThread()
{
    if(!m_isRunFlage){
        m_isRunFlage = true;
        this->start();
    }
}

/**
 * @brief 关闭线程
 */
void ProtocolParse::stopThread()
{
    m_isRunFlage = false;
//    g_cv_recvQuqueCondition.notify_all();
}

/**
 * @brief 线程运行
 */
void ProtocolParse::run()
{
//    while (m_isRunFlage)
//    {
//        while (m_isRunFlage && g_recvQueue.size() == 0 ) {
//            std::unique_lock<std::mutex> lg(g_mutex_recvQueueMutex);
//            g_cv_recvQuqueCondition.wait(lg);
//        }
//        while(m_isRunFlage && g_recvQueue.size() > 0){
//            g_mutex_recvQueueMutex.lock();
//            ProtocolArray orginData = g_recvQueue.dequeue();
//            g_mutex_recvQueueMutex.unlock();
//            beforeParsing(orginData);
//        }
//    }
}

/*!
 * @brief 按照协议解析原始数据
 * @param[in] array 原始数据
 * @return 是否解析成功
 */
bool ProtocolParse::beforeParsing(SystemDatastruct::ProtocolArray &array)
{
//    int t_dataOffset = 0;
//    //[1] 解析报头
//    ProtocolDataStruct::PacketHeadInfo t_packHead;
//    memset((char *)&t_packHead, 0, sizeof(ProtocolDataStruct::PacketHeadInfo));
//    memcpy((char *)&t_packHead, array.data->data(),sizeof(ProtocolDataStruct::PacketHeadInfo));
//    t_dataOffset += sizeof(ProtocolDataStruct::PacketHeadInfo);

//    int t_messageType = t_packHead.msgType;
//    //[2] 根据消息类型解析数据
//    switch(static_cast<ProtocolDataStruct::MessageType>(t_messageType))
//    {
//    case ProtocolDataStruct::Message_heartBeat:{

//    }
//        break;
//    case ProtocolDataStruct::Message_ModelFlowControl:{

//    }
//        break;
//    default:
//        break;
//    }
    return true;
}

}
