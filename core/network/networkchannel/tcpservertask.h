/*!
 *  @brief      Qt_TCP服务器端
 *  @details    1、创建Tcp客户端
 *  @author     yzg
 *  @version    1.0
 *  @date       2021-02-05
 *  @warning
 *  @copyright  NanJing RenGu.
 *  @note
 */
#ifndef TCPSERVERTASK_H
#define TCPSERVERTASK_H

#include <QObject>
#include <QAbstractSocket>
#include <QHostAddress>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostInfo>

#include "utils/rlog.h"
#include "utils/rutil.h"

#include "protocol/systemdatastruct.h"

namespace Core {

class TcpServerTask : public QObject
{
    Q_OBJECT
public:
    explicit TcpServerTask(QObject *parent = nullptr);
    ~TcpServerTask();

    /**
     * @brief Tcp客户端信息
     * @note 用于记录与Tcp服务器链接的客户端信息
     */
    struct NetworkClientInfo{
        NetworkClientInfo() : socket(NULL),clienPport(0){
            clientIp = nullptr;
        }
        QString clientIp;                                   /*! <客户端Ip> */
        int clienPport;                                     /*! <客户端端口> */
        QTcpSocket * socket;                                /*! <套接字> */
    };

    bool init(SystemDatastruct::NetworkInfo info);

signals:

private slots:
    void slotTcpServerConnection();
    void slotReceiveNetworkInfo();
    void slotSocketDisconnected();
    void slotSocketStateChange(QAbstractSocket::SocketState state);

private:
    SystemDatastruct::NetworkInfo m_networkInfo;            /*!< 网络配置信息 */
    QTcpServer * m_tcpServer;                               /*!< Tcp服务器 */
    QList<NetworkClientInfo>  m_listClients;                /*! <与服务器链接的客户端列表> */
};

}//namespace Core

#endif // TCPSERVERTASK_H
