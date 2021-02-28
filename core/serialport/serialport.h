/*!
 *  @brief     串口通信线程
 *  @details
 *  @author    YZG
 *  @version   1.0
 *  @date      20190728
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef SERIALPORTTHREAD_H
#define SERIALPORTTHREAD_H

#include <QObject>
#include <QSerialPort>

//[] 数据包缓存区
#include "SerialPortParseManage/serialportpacketrule.h"

namespace Core {

class SerialPort : public QObject
{
    Q_OBJECT
public:
    explicit SerialPort(QObject *parent = Q_NULLPTR);
    ~SerialPort();

    /**
     * @brief 串口配置信息
     */
    struct SerialPortBaseInfo{
        QString name;                           /*! <串口名> */
        QSerialPort::BaudRate baudRate;         /*! <波特率> */
        QSerialPort::DataBits dataBits;         /*! <数据位> */
        QSerialPort::Parity parity;             /*! <校验位> */
        QSerialPort::StopBits stopBits;         /*! <停止位> */
        QSerialPort::FlowControl flowControl;   /*! <流控> */
    };


    void init(SerialPortBaseInfo info);
    bool open();
    void close();

    qint64 sendToSerialPortInfo(QByteArray buff);

private slots:
    void slotReceiveSerialPortInfo();

private:
    void createRecvBuff();

private:
    SerialPortBaseInfo m_serialPortBaseInfo;            /*!< 串口基本信息 */
    QSerialPort * m_serialPort;                         /*!< 串口操作类 */
    SerialPortPacketRule * m_serialPortPacketRule;      /*!< 协议包管理器 */
};

} //namespace Core

#endif // SERIALPORTTHREAD_H
