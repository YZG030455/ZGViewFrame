/*!
 *  @brief      网络管理
 *  @details    用于Tcp客户端, tcp服务器，upd单播，udp组播
 *  @author     yzg
 *  @version    1.0
 *  @date       20191129
 *  @warning
 *  @copyright  NanJing RenGu.
 *  @note
 */
#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QMap>

#include "global.h"
#include "protocol/systemdatastruct.h"
#include "protocol/protocoldatastruct.h"
#include "messdispath.h"
//[] 网络
#include "networkchannel/tcpservertask.h"
#include "networkchannel/tcpclienttask.h"
#include "networkchannel/udpunicasttask.h"
#include "networkchannel/udpmulticasttask.h"

namespace Core {

class NetworkManager : public QObject
{
    Q_OBJECT
public:
    explicit NetworkManager(QObject *parent = 0);
    ~NetworkManager();

    void createTcpServer(SystemDatastruct::NetworkInfo info);
    void createTcpClient(SystemDatastruct::NetworkInfo info);
    void createUdpUnicast(SystemDatastruct::NetworkInfo info);
    void createUdpMulticast(SystemDatastruct::NetworkInfo info);

    void sendToServerNetworkInfo(SystemDatastruct::NetworkTaskType type, QString ip, int port, QByteArray array);
    void sendToClientNetworkInfo(SystemDatastruct::NetworkTaskType type, QByteArray array);
    void sendToUnicastNetworkInfo(SystemDatastruct::NetworkTaskType type, QByteArray array);
    void sendToMulticastNetworkInfo(SystemDatastruct::NetworkTaskType type, QByteArray array);

    QString getLocalIp();
    QString getHostIpAddrs();

signals:

private slots:
    void slotParseConfigFileResult(bool result);

private:
    QString m_localIp;                                      /*! <本地Ip> */
    QMap<int, TcpServerTask *> m_pMapServers;               /*! <客户端容器> */
    QMap<int, TcpClientTask *> m_pMapClients;               /*! <客户端容器> */
    QMap<int, UdpUnicastTask *> m_pMapUnicasts;             /*! <单播容器> */
    QMap<int, UdpMulticastTask *> m_pMapMulticasts;         /*! <组播容器> */

};

} //namespace Core

#endif // NETWORKMANAGE_H
