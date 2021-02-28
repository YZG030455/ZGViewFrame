#include "networkmanager.h"

#include <QDebug>

namespace Core {

NetworkManager::NetworkManager(QObject *parent)
    : QObject(parent)
{
    m_pMapServers.clear();
    m_pMapClients.clear();
    m_pMapUnicasts.clear();
    m_pMapMulticasts.clear();
}

NetworkManager::~NetworkManager()
{
    if(m_pMapClients.size() > 0){

    }

    if(m_pMapUnicasts.size() > 0){

    }

    if(m_pMapMulticasts.size() > 0){

    }
}

/**
 * @brief 创建Tcp服务器
 * @param info
 */
void NetworkManager::createTcpServer(SystemDatastruct::NetworkInfo info)
{
    TcpServerTask *t_pTcpServer = new TcpServerTask();
    t_pTcpServer->init();
    m_pMapServers.insert(info.taskType, t_pTcpServer);
}

/**
 * @brief 创建Tcp客户端
 * @param info
 */
void NetworkManager::createTcpClient(SystemDatastruct::NetworkInfo info)
{
    TcpClientTask *t_pTcpClient = new TcpClientTask();
    t_pTcpClient->init(info);
    m_pMapClients.insert(info.taskType, t_pTcpClient);
}

/**
 * @brief 创建Udp单播
 * @param info
 */
void NetworkManager::createUdpUnicast(SystemDatastruct::NetworkInfo info)
{
    UdpUnicastTask *t_pUnicast = new UdpUnicastTask();
    t_pUnicast->init(info);
    m_pMapUnicasts.insert(info.taskType, t_pUnicast);
}

/**
 * @brief 创建Udp组播
 * @param info
 */
void NetworkManager::createUdpMulticast(SystemDatastruct::NetworkInfo info)
{
    UdpMulticastTask *t_pMulticast = new UdpMulticastTask();
    t_pMulticast->init(info);
    m_pMapMulticasts.insert(info.taskType, t_pMulticast);
}

/**
 * @brief 发送Tcpf服务器信息
 * @param ip
 * @param port
 * @param array
 */
void NetworkManager::sendToServerNetworkInfo(SystemDatastruct::NetworkTaskType type, QString ip, int port, QByteArray array)
{

}

void NetworkManager::sendToClientNetworkInfo(SystemDatastruct::NetworkTaskType type, QByteArray array)
{
    if(m_pMapClients.size() > 0){

    }
}

void NetworkManager::sendToUnicastNetworkInfo(SystemDatastruct::NetworkTaskType type, QByteArray array)
{
    if(m_pMapUnicasts.size() > 0){
        if(m_pMapUnicasts.contains(type)){

        }
    }
}

void NetworkManager::sendToMulticastNetworkInfo(SystemDatastruct::NetworkTaskType type, QByteArray array)
{
    if(m_pMapMulticasts.size() > 0){

    }
}


/**
 * @brief 获取本地Ip
 * @return 返回：本地Ip
 */
QString NetworkManager::getLocalIp()
{
    QString localIp;
    // 获取本机IPV4地址
    QString hostName = QHostInfo::localHostName();  // 本地主机名
    QHostInfo hostinfo = QHostInfo::fromName(hostName);
    QList<QHostAddress >  listAddresss =  hostinfo.addresses();
    if( !listAddresss.isEmpty() ) {
        for(int i = 0; i < listAddresss.size(); i++ ) {
            QHostAddress hostAddress = listAddresss.at(i);
            if(QAbstractSocket::IPv4Protocol == hostAddress.protocol()) {
                localIp = hostAddress.toString();
                break;
            }
        }
    }
    return localIp;
}

QString NetworkManager::getHostIpAddrs()
{
    QString ip;
    QList<QHostAddress> ipAddrs = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipAddrs.size(); ++i) {
        if (ipAddrs.at(i) != QHostAddress::LocalHost && ipAddrs.at(i).toIPv4Address()) {
            // 如果这个地址不是127.0.0.1，并且是IPv4的地址，就将其赋值给ip，并结束for循环
            ip = ipAddrs.at(i).toString();
            break;
        }
    }
    // 如果ip为空，则将其赋值为127.0.0.1
    if (ip.isEmpty())
        ip = QHostAddress(QHostAddress::LocalHost).toString();
    return ip;
}

/**
 * @brief 解析配置文件结果
 * @param result
 */
void NetworkManager::slotParseConfigFileResult(bool result)
{

}

}//namespace Core
