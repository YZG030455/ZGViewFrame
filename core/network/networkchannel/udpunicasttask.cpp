#include "udpunicasttask.h"

#include <QDebug>

namespace Core {

UdpUnicastTask::UdpUnicastTask(QObject *parent)
    :QObject(parent),
      m_pUnicastUdpSocket(NULL)
{

}

UdpUnicastTask::~UdpUnicastTask()
{
    if(m_pUnicastUdpSocket != NULL){
        m_pUnicastUdpSocket->close();
        delete m_pUnicastUdpSocket;
        m_pUnicastUdpSocket = NULL;
    }
}

/**
 * @brief 初始化网络
 * @param info ：网络信息
 */
bool UdpUnicastTask::init(SystemDatastruct::NetworkInfo info)
{
    if(info.baseInfo.localPort <= 0 && info.baseInfo.localPort >USHRT_MAX
            && info.baseInfo.targetPort <= 0 && info.baseInfo.targetPort > USHRT_MAX){
        return false;
    }
    bool t_bind = false;
    m_networkInfo = info;
    /*! <创建网络> */
    if(m_pUnicastUdpSocket == NULL){
        m_pUnicastUdpSocket = new QUdpSocket(this);
        t_bind = m_pUnicastUdpSocket->bind(m_networkInfo.baseInfo.localPort);
    }
    /*! <绑定本机端口> */
    connect(m_pUnicastUdpSocket, SIGNAL(readyRead()), this, SLOT(slotUnicastSocketReadyRead()));
    connect(m_pUnicastUdpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(slotUdpSocketStateChange(QAbstractSocket::SocketState)));
    slotUdpSocketStateChange(m_pUnicastUdpSocket->state());
    return t_bind;
}

/**
 * @brief 发送信息到单播UdpSocket
 * @param buff 二进制数据
 * @return 发送的有效长度
 */
qint64 UdpUnicastTask::setSendToUnicastNetworkInfo(QByteArray buff)
{
    int t_ret = 0;
    if(m_pUnicastUdpSocket) {
        QHostAddress t_targetIp(m_networkInfo.baseInfo.targetIp);        //目标Ip
        t_ret = m_pUnicastUdpSocket->writeDatagram(buff, t_targetIp, m_networkInfo.baseInfo.targetPort);
    }
    return t_ret;
}

/**
 * @brief 读取数据
 */
void UdpUnicastTask::slotUnicastSocketReadyRead()
{
    while (m_pUnicastUdpSocket->hasPendingDatagrams())  {
        QByteArray buff;
        buff.resize(m_pUnicastUdpSocket->pendingDatagramSize());    // 返回待读取数据报的字节数
        QHostAddress peerAddr;    // 数据来源Ip
        quint16 peerPort;         // 数据来源端口
        m_pUnicastUdpSocket->readDatagram(buff.data(), buff.size(), &peerAddr, &peerPort);
    }
}

/**
 * @brief 网络状态信息改变
 * @param state
 */
void UdpUnicastTask::slotUdpSocketStateChange(QAbstractSocket::SocketState state)
{
    switch (state) {
    case QAbstractSocket::UnconnectedState: {

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

} //namespace Core
