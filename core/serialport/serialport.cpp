#include "serialport.h"

#include <QDebug>

namespace Core {

SerialPort::SerialPort(QObject *parent)
    : QObject(parent),
      m_serialPort(nullptr),
      m_serialPortPacketRule(nullptr)
{

}

SerialPort::~SerialPort()
{
    if (m_serialPort->isOpen()){
        m_serialPort->close();
        delete  m_serialPort;
        m_serialPort = nullptr;
    }

    if(m_serialPortPacketRule != nullptr){
        delete m_serialPortPacketRule;
        m_serialPortPacketRule = nullptr;
    }
}

/**
 * @brief 初始化串口
 * @note 用于创建串口
 */
void SerialPort::init(SerialPortBaseInfo info)
{
    if(m_serialPort == NULL){
        m_serialPort = new QSerialPort();
        m_serialPort->setPortName(info.name);
        m_serialPort->setBaudRate(info.baudRate, QSerialPort::AllDirections);
        m_serialPort->setDataBits(info.dataBits);
        m_serialPort->setParity(info.parity);
        m_serialPort->setStopBits(info.stopBits);
        m_serialPort->setFlowControl(info.flowControl);
        /*! <信号与槽> */
        connect(m_serialPort, SIGNAL(readyRead()), this, SLOT(slotReceiveSerialPortInfo()));
    }
    //创建缓存区
    createRecvBuff();
}

/**
 * @brief 开启端口
 * @return
 */
bool SerialPort::open()
{
    bool t_open = false;
    /*! <如果串口已经打开了 先给他关闭了> */
    if(m_serialPort->isOpen()) {
        m_serialPort->clear();
        m_serialPort->close();
        return t_open;
    }
    /*! <打开串口> */
    t_open = m_serialPort->open(QIODevice::ReadWrite);
    return t_open;
}

/**
 * @brief 关闭串口
 * @return
 */
void SerialPort::close()
{
    if(m_serialPort->isOpen()) {
        m_serialPort->close();
    }
}

/**
 * @brief 发送信息到网络Scoket
 * @param buff
 * @return 发送的有效长度
 */
qint64 SerialPort::sendToSerialPortInfo(QByteArray buff)
{
    int t_ret = 0;      //有效长度
    t_ret =  m_serialPort->write(buff);
    return t_ret;
}

/**
 * @brief 接收串口信息
 */
void SerialPort::slotReceiveSerialPortInfo()
{
    QByteArray buff;
    buff = m_serialPort->readAll();

    if(m_serialPortPacketRule != NULL){
        m_serialPortPacketRule->unwrap("", buff.data(), buff.size());
    }
}


/**
 * @brief 创建接收的缓存区
 */
void SerialPort::createRecvBuff()
{
    if(m_serialPortPacketRule == NULL) {
        m_serialPortPacketRule = new SerialPortPacketRule();
    }
}

} //namespace Core
