/*!
 *  @brief     创建UdpSocket线程（创建线程的一）- 组播
 *  @details
 *  @author    YZG
 *  @version   1.0
 *  @date      2019-05-22
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef MULTICASTUDPSOCKETTASK_H
#define MULTICASTUDPSOCKETTASK_H

#include <QObject>
#include <QAbstractSocket>
#include <QUdpSocket>
#include <QHostAddress>

#include "global.h"
#include "protocol/systemdatastruct.h"
#include "protocol/protocoldatastruct.h"
#include "messdispath.h"

namespace Core {

class UdpMulticastTask : public QObject
{
    Q_OBJECT
public:
    UdpMulticastTask(QObject *parent = Q_NULLPTR);
    ~UdpMulticastTask();

    bool init(SystemDatastruct::NetworkInfo info);
    qint64 setSendToMulticastNetworkInfo(QByteArray buff);

signals:

public slots:
    void slotSendToMulticastSocket(QByteArray buff);
    void slotMulticastSocketReadyRead();
    void slotUdpSocketStateChange(QAbstractSocket::SocketState state);

private:
    void processTheDatagram(QByteArray buff, int length);
    void setStopUdpSocket();

private:
    SystemDatastruct::NetworkInfo m_networkInfo;              /*! <网络信息> */
    QUdpSocket *m_pMulticastSocket;                          /*! <组播模式> */

    QString m_localIp ;                     /*! <本地ip> */
    quint16 m_localPort;                    /*! <本地端口> */
    QString m_targetIp;                     /*! <目标Ip> */
    quint16 m_targetPort;                   /*! <目标端口> */

    QHostAddress m_GroupIp;                 /*! <组播Ip> */
    quint16 m_groupPort;                    /*! <组播端口> */

};

} //}

#endif // MULTICASTUDPSOCKETTHREAD_H
