/*!
 *  @brief     串口管理器
 *  @details   该类用于获取串口的信息，并创建串口通信
 *  @author    yzg
 *  @version   1.0
 *  @date      20200214
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef SERIALPORTMANAGER_H
#define SERIALPORTMANAGER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

//[] 串口
#include "serialport.h"

namespace Core {

/**
 * @brief 串口配置信息
 */
struct SerialPortConfigInfo{
    SerialPortConfigInfo():baudRate(9600),dataBits(8),parity(2),stopBits(1),
        flowControl(0) {

    }
    QString name;           /*!< 串口号 */
    int baudRate;           /*!< 波特率 */
    int dataBits;           /*!< 数据位 */
    int parity;             /*!< 校验位 */
    int stopBits;           /*!< 停止位 */
    int flowControl;        /*!< 流控 */
};

class SerialPortManager : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortManager(QObject *parent = 0);
    ~SerialPortManager();

    QStringList getSerialPortListInfos();

    void setSerialPortBaseInfo(SerialPortConfigInfo info);

    void openSerialPort();
    void closeSerialPort();

private:
    QStringList m_serialPortList;                           /*! <本机串口列表> */
    SerialPortConfigInfo m_configInfo;                      /*! <串口配置信息> */
    SerialPort *m_serialPort;                               /*! <串口线程> */
};

} //namespace Core

#endif // SERIALPORTMANAGE_H
