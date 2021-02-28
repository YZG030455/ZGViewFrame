#include "udpmulticasttask.h"

#include <QDebug>

namespace Core {

UdpMulticastTask::UdpMulticastTask(QObject *parent)
    :QObject(parent),
      m_pMulticastSocket(NULL)
{

}

UdpMulticastTask::~UdpMulticastTask()
{
    if(m_pMulticastSocket != NULL){
        m_pMulticastSocket->close();
        delete m_pMulticastSocket;
        m_pMulticastSocket = NULL;
    }
}

/**
 * @brief 初始化网络
 * @param info ：网络信息
 */
bool UdpMulticastTask::init(SystemDatastruct::NetworkInfo info)
{
    if(info.baseInfo.localPort <= 0 || info.baseInfo.targetPort > USHRT_MAX){
        return false;
    }
    m_networkInfo = info;

    m_pMulticastSocket = new QUdpSocket(this);
    /*!< 设置缓冲区 >*/
    m_pMulticastSocket->setSocketOption(QAbstractSocket::MulticastTtlOption, 1024*1024*8);
    /*! <绑定本机端口> */
    bool bind = m_pMulticastSocket->bind(QHostAddress::AnyIPv4, m_groupPort, QUdpSocket::ShareAddress);
    if(bind) {
        m_pMulticastSocket->joinMulticastGroup(m_GroupIp);
    }

    /*! <信号与槽> */
    //    connect(NetWorkMessDispath::instance(), SIGNAL(signalSendToNetWork(QByteArray)), this, SLOT(slotSendToMulticastSocket(QByteArray)));
    connect(m_pMulticastSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(slotUdpSocketStateChange(QAbstractSocket::SocketState)));
    slotUdpSocketStateChange(m_pMulticastSocket->state());
    connect(m_pMulticastSocket, SIGNAL(readyRead()), this, SLOT(slotUnicastSocketReadyRead()));

}

qint64 UdpMulticastTask::setSendToMulticastNetworkInfo(QByteArray buff)
{
    return 1;
}

/**
 * @brief 发送信息到组播UdpSocket
 * @param buff
 */
void UdpMulticastTask::slotSendToMulticastSocket(QByteArray buff)
{
    m_pMulticastSocket->writeDatagram(buff, m_GroupIp, m_groupPort);
}

/**
 * @brief 读取组播Socket信息
 */
void UdpMulticastTask::slotMulticastSocketReadyRead()
{
    while (m_pMulticastSocket->hasPendingDatagrams())              //是否有待读取的传入数据
    {
        QByteArray buff;
        buff.resize(m_pMulticastSocket->pendingDatagramSize());    // 返回待读取数据报的字节数
        QHostAddress peerAddr;    // 数据来源Ip
        quint16 peerPort;         // 数据来源端口
        m_pMulticastSocket->readDatagram(buff.data(), buff.size(), &peerAddr, &peerPort);

        this->processTheDatagram(buff, buff.size());
    }
}

/**
 * @brief 查看网络连接状态
 * @param state
 */
void UdpMulticastTask::slotUdpSocketStateChange(QAbstractSocket::SocketState state)
{
    switch (state) {
    case QAbstractSocket::UnconnectedState:
    {

        break;
    }
    case QAbstractSocket::HostLookupState:
    {

        break;
    }
    case QAbstractSocket::ConnectingState:
    {

        break;
    }
    case QAbstractSocket::ConnectedState:
    {

        break;
    }
    case QAbstractSocket::BoundState:
    {

        break;
    }
    case QAbstractSocket::ClosingState:
    {

        break;
    }
    case QAbstractSocket::ListeningState:
    {

        break;
    }
    default:
        break;
    }
}

/**
 * @brief 处理网络数据
 * @param buff
 * @param length
 */
void UdpMulticastTask::processTheDatagram(QByteArray buff, int length)
{
    qDebug() <<"__FILE__<<__LINE__"<<"\n" << "Recv Net" << buff.toHex();

    if(length <= 0)
    {
        return;
    }
}

/**
 * @brief 退出网络
 */
void UdpMulticastTask::setStopUdpSocket()
{
    if (m_pMulticastSocket != NULL)
    {
        m_pMulticastSocket->leaveMulticastGroup(m_GroupIp);  // 退出组播
        m_pMulticastSocket->abort();     //解除绑定
    }
}

} //namespace Core
