/*!
 *  @brief      TCP客户端
 *  @details    1、创建Tcp客户端
 *              2、
 *  @author     yzg
 *  @version    1.0
 *  @date       20190425
 *  @warning
 *  @copyright  NanJing RenGu.
 *  @note
 */
#ifndef TCPCLIENTTASK_H
#define TCPCLIENTTASK_H

#include <QObject>
#include <QAbstractSocket>
#include <QHostAddress>
#include <QTcpSocket>
#include <QHostInfo>

#include "global.h"
#include "protocol/systemdatastruct.h"
#include "protocol/protocoldatastruct.h"
#include "messdispath.h"

#include "utils/rlog.h"

//[]网络数据包管理
#include "networkParseManage/clientpacketrule.h"

namespace Core {

class TcpClientTask : public QObject
{
    Q_OBJECT
public:
    TcpClientTask(QObject *parent = Q_NULLPTR);
    ~TcpClientTask();

    bool init(SystemDatastruct::NetworkInfo info);
    qint64 setSendInfoToNetwork(QByteArray buff);

private slots:

    void slotReceiveNetwork();
    void slotTcpSocketStateChange(QAbstractSocket::SocketState state);

private:
    void createRecvBuff();
private:
    SystemDatastruct::NetworkInfo m_networkInfo;                /*! <网络信息结构体> */
    QTcpSocket *m_tcpSocket;                                    /*! <创建Socket通信> */
    ClientPacketRule *m_pPacketRule;                            /*! <数据包管理器> */
};

}//namespace Core

#endif // TCPCLIENTTHREAD_H
