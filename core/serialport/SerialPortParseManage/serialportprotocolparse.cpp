#include "serialportprotocolparse.h"

#include <QDebug>

namespace Core {

SerialPortProtocolParse::SerialPortProtocolParse(QObject *parent)
    : QThread(parent),
      m_b_runningFlage(false)
{

}

SerialPortProtocolParse::~SerialPortProtocolParse()
{
    m_b_runningFlage = false;
//    g_cv_recvSerialPortQuqueCondition.notify_one();
    wait();
}

/**
 * @brief 开启线程
 */
void SerialPortProtocolParse::startThread()
{
    if(!m_b_runningFlage){
        m_b_runningFlage = true;
        this->start();
    }
}

/**
 * @brief 关闭线程
 */
void SerialPortProtocolParse::stopThread()
{
    m_b_runningFlage = false;
//    g_cv_recvSerialPortQuqueCondition.notify_all();
}

/**
 * @brief 线程运行
 */
void SerialPortProtocolParse::run()
{
//    while (m_b_runningFlage) {
//        while (m_b_runningFlage && g_recvSerialPortQueue.size() == 0 ) {
//            std::unique_lock<std::mutex> lg(g_mutex_recvSerialPortQueueMutex);
//            g_cv_recvSerialPortQuqueCondition.wait(lg);
//        }
//        while(m_b_runningFlage && g_recvSerialPortQueue.size() > 0){
//            g_mutex_recvSerialPortQueueMutex.lock();
//            SerialPortProtocolArray orginData = g_recvSerialPortQueue.dequeue();
//            g_mutex_recvSerialPortQueueMutex.unlock();
//            beforeParsing(orginData);
//        }
//    }
}

/*!
 * @brief 按照协议解析原始数据
 * @param[in] array 原始数据
 * @return 是否解析成功
 */
bool SerialPortProtocolParse::beforeParsing(SystemDatastruct::SerialPortProtocolArray &array)
{


    return true;
}

}
