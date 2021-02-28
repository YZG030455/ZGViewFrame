/*!
 *  @brief      创建UdpSocket线程（创建线程的一）- 单播
 *  @details
 *  @author     YZG
 *  @version
 *  @date       2019-05-22
 *  @warning
 *  @copyright  NanJing RenGu.
 *  @note
 */
#ifndef UNICASTUDPSOCKETTASK_H
#define UNICASTUDPSOCKETTASK_H

#include <QObject>
#include <QAbstractSocket>
#include <QUdpSocket>
#include <QHostAddress>
#include <QHostInfo>

#include "global.h"
#include "protocol/systemdatastruct.h"
#include "protocol/protocoldatastruct.h"
#include "messdispath.h"

#include "networkParseManage/unicastpacketrule.h"

namespace Core {

class UdpUnicastTask : public QObject
{
    Q_OBJECT
public:
    UdpUnicastTask(QObject *parent = Q_NULLPTR);
    ~UdpUnicastTask();

    bool init(SystemDatastruct::NetworkInfo info);
    qint64 setSendToUnicastNetworkInfo(QByteArray buff);

signals:

public slots:
    void slotUnicastSocketReadyRead();
    void slotUdpSocketStateChange(QAbstractSocket::SocketState state);

private:


private:
    SystemDatastruct::NetworkInfo m_networkInfo;              /*! <网络信息> */
    QUdpSocket *m_pUnicastUdpSocket;                          /*! <单播模式> */

};

} //namespace Core

#endif // UNICASTUDPSOCKETTHREAD_H
