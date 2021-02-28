/*!
 *  @brief      网络协议解析
 *  @details
 *  @author     yzg
 *  @version    1.0
 *  @date       20200219
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef PROTOCOLPARSE_H
#define PROTOCOLPARSE_H

#include <QThread>

#include "protocol/systemdatastruct.h"
#include "protocol/protocoldatastruct.h"

namespace Core {

class ProtocolParse : public QThread
{
    Q_OBJECT
public:
    explicit ProtocolParse(QObject *parent = Q_NULLPTR);
    ~ProtocolParse();

    void startThread();
    void stopThread();

protected:
    void run();

private:
    bool beforeParsing(SystemDatastruct::ProtocolArray & array);

private:
    bool m_isRunFlage;          /*! <线程运行标志> */

};

}

#endif // NETWORKPROTOCOLPARSE_H
