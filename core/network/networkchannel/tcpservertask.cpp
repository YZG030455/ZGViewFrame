#include "tcpservertask.h"

namespace Core {

TcpServerTask::TcpServerTask(QObject *parent)
    : QObject(parent)
{

}

TcpServerTask::~TcpServerTask()
{

}

/**
 * @brief 初始化信息
 * @param info 网络配置信息
 * @note 创建网络
 * @return
 */
bool TcpServerTask::init(SystemDatastruct::NetworkInfo info)
{
    if(info.baseInfo.localPort <= 0 || info.baseInfo.localPort > USHRT_MAX)
    {
        QString t_sysLogInfo = QString("Create Tcp Server localPort fail!!");
        RLOG_ERROR(t_sysLogInfo.toLocal8Bit().data());
        return false;
    }
    m_networkInfo  = info;
    //[] 创建服务器
    if(m_tcpServer == NULL)
    {
        m_tcpServer = new QTcpServer();
        QHostAddress t_localHostAddress(info.baseInfo.localIp);
        bool t_listen = false;
        t_listen = m_tcpServer->listen(t_localHostAddress, info.baseInfo.localPort);
        if(!t_listen )  {
            QString t_sysLogInfo = QString("Create Tcp Server fail!, Tcp Server listen Port is false!");

            return false;
        }
        connect(m_tcpServer, SIGNAL(newConnection()), this, SLOT(slotTcpServerConnection()));
    }
    return true;
}

/**
 * @brief TcpServerTask::slotTcpServerConnection
 */
void TcpServerTask::slotTcpServerConnection()
{

}

void TcpServerTask::slotReceiveNetworkInfo()
{

}

void TcpServerTask::slotSocketDisconnected()
{

}

void TcpServerTask::slotSocketStateChange(QAbstractSocket::SocketState state)
{

}

}//namespace Core {
