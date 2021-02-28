#include "tcpclienttask.h"

#include <QDebug>

namespace Core {

TcpClientTask::TcpClientTask(QObject *parent)
    : QObject(parent),
      m_tcpSocket(NULL),
      m_pPacketRule(NULL)
{

}

TcpClientTask::~TcpClientTask()
{
    if(m_tcpSocket != NULL){
        m_tcpSocket->close();
        delete m_tcpSocket;
        m_tcpSocket == NULL;
    }
}

/**
 * @brief 初始化
 * @note 创建网络与数据缓冲区
 */
bool TcpClientTask::init(SystemDatastruct::NetworkInfo info)
{
    //[]检测端口
    if(info.baseInfo.localPort <= 0 && info.baseInfo.localPort  > USHRT_MAX
            &&info.baseInfo.targetPort <= 0 && info.baseInfo.targetPort > USHRT_MAX){
        return false;
    }
    bool t_bind = false;
    m_networkInfo = info;
    /*! <创建TcpSocket> */
    if(m_tcpSocket == NULL) {
        m_tcpSocket = new QTcpSocket();
        QHostAddress t_localHostAddress(m_networkInfo.baseInfo.localIp);

        t_bind = m_tcpSocket->bind(t_localHostAddress, m_networkInfo.baseInfo.localPort, QTcpSocket::ReuseAddressHint);
        if(!t_bind) {
            m_tcpSocket->close();
            t_bind = m_tcpSocket->bind(t_localHostAddress, m_networkInfo.baseInfo.localPort, QTcpSocket::ReuseAddressHint);
        }
        m_tcpSocket->connectToHost(m_networkInfo.baseInfo.targetIp, m_networkInfo.baseInfo.targetPort);
        /*! <信号与槽> */
        connect(m_tcpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(slotTcpSocketStateChange(QAbstractSocket::SocketState)));
        connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(slotReceiveNetwork()));
    }
    //[2] 创建接收缓存区
    createRecvBuff();

    return t_bind;
}

/**
 * @brief 用于向scoket 发送信息
 * @param buff
 */
qint64 TcpClientTask::setSendInfoToNetwork(QByteArray buff)
{
    int t_ret = 0;      //有效长度
    if(m_tcpSocket != NULL){
        if(buff.size() > 0){
            t_ret = m_tcpSocket->write(buff);
        }
        buff.clear();
    }
    return t_ret;
}

/**
 * @brief 读取接收到的网络信息
 */
void TcpClientTask::slotReceiveNetwork()
{
    if(m_tcpSocket != NULL) {
        QByteArray t_buff;
        t_buff.clear();
        t_buff = m_tcpSocket->readAll();
        if(m_pPacketRule != NULL){
            m_pPacketRule->unwrap(m_networkInfo.baseInfo.targetIp, m_networkInfo.baseInfo.targetPort, t_buff.data(), t_buff.size());
            t_buff.clear();
        }
    }
}

/**
 * @brief 查看网络状态
 * @param state
 */
void TcpClientTask::slotTcpSocketStateChange(QAbstractSocket::SocketState state)
{
    switch (state) {
    case QAbstractSocket::UnconnectedState:      {

        break;
    }
    case QAbstractSocket::HostLookupState: {

        break;
    }
    case QAbstractSocket::ConnectingState: {

        break;
    }
    case QAbstractSocket::ConnectedState: {

        break;
    }
    case QAbstractSocket::BoundState: {

        break;
    }
    case QAbstractSocket::ClosingState: {

        break;
    }
    case QAbstractSocket::ListeningState: {

        break;
    }
    default:
        break;
    }
}

/**
 * @brief 创建接收的缓存区
 */
void TcpClientTask::createRecvBuff()
{
    if(m_pPacketRule == NULL){
        m_pPacketRule = new ClientPacketRule();
    }
}

} //namespace Core
