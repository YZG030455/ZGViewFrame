/*!
 *  @brief        协议解析线程 ——》tcp客户端数据包
 *  @details    1.处理网络线程打包好的原始协议数据；
 *                  2.将解析后的数据分发给不同的插件；
 *  @author     yzg
 *  @version    1.0
 *  @date       20200217
 *  @warning
 *  @copyright  NanJing RenGu.
 *  @note
 */
#ifndef CLIENTPROTOCOLPARSE_H
#define CLIENTPROTOCOLPARSE_H

#include <QThread>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include "global.h"
#include "utils/rutil.h"
#include "protocol/systemdatastruct.h"
#include "protocol/protocoldatastruct.h"
#include "messdispath.h"

namespace Core {

class CmdClientProtocolParse : public QThread
{
    Q_OBJECT
public:
    CmdClientProtocolParse(QObject *parent = Q_NULLPTR);
    ~CmdClientProtocolParse();

    void startThread();
    void stopThread();

signals:

protected:
    void run();

private:
    bool beforeParsing(SystemDatastruct::ProtocolArray *array);

private:
    bool m_runningFlag;                              /*! <线程运行标志> */
};

}//namespace Core

#endif // CLIENTPROTOCOLPARSE_H
