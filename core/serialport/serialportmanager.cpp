#include "serialportmanager.h"

#include <QDebug>

namespace Core {

SerialPortManager::SerialPortManager(QObject *parent)
    : QObject(parent),
      m_serialPort(NULL)
{
    m_serialPortList.clear();

}

SerialPortManager::~SerialPortManager()
{

}

/**
 * @brief 获取串口列表信息
 * @return
 */
QStringList SerialPortManager::getSerialPortListInfos()
{
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        m_serialPortList << info.portName();
    }
    return m_serialPortList;
}

/**
 * @brief 设置串口配置信息
 * @param info
 */
void SerialPortManager::setSerialPortBaseInfo(SerialPortConfigInfo info)
{
    m_configInfo = info;

    SerialPort::SerialPortBaseInfo baseInfo;
    baseInfo.name = info.name;
    /*! <波特率> */
    switch (info.baudRate) {
    case 1200:{
    baseInfo.baudRate = QSerialPort::Baud1200;
    }
        break;
    case 2400:{

    }
        break;
    case 4800:{

    }
        break;
    case 9600:{

    }
        break;
    case 19200:{

    }
        break;
    }


    //    t_SerialPortInfo.dataBits = QSerialPort::Data8;                 /*! <数据位> */
    //    t_SerialPortInfo.parity = QSerialPort::NoParity;                /*! <校验位> */
    //    t_SerialPortInfo.stopBits = QSerialPort::OneStop;               /*! <停止位> */
    //    t_SerialPortInfo.flowControl = QSerialPort::NoFlowControl;      /*! <流控> */

    if(m_serialPort == nullptr){
        m_serialPort = new SerialPort();
        m_serialPort->init(baseInfo);
    }
}

/**
 * @brief 开启串口
 */
void SerialPortManager::openSerialPort()
{
    m_serialPort->open();
}

/**
 * @brief 关闭串口
 */
void SerialPortManager::closeSerialPort()
{
    m_serialPort->close();
}

}//namespace Core
