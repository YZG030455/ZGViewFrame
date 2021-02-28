/*!
 *  @brief      串口通信的协议解析
 *  @details
 *  @author     yzg
 *  @version    1.0
 *  @date       20200219
 *  @warning
 *  @copyright  NanJing RenGu.
 *  @note
 */
#ifndef SERIALPORTPROTOCOLPARSE_H
#define SERIALPORTPROTOCOLPARSE_H

#include <QThread>

#include "global.h"
#include "protocol/systemdatastruct.h"
#include "protocol/protocoldatastruct.h"
#include "messdispath.h"


namespace Core {

class SerialPortProtocolParse : public QThread
{
    Q_OBJECT
public:
    explicit SerialPortProtocolParse(QObject *parent = Q_NULLPTR);
    ~SerialPortProtocolParse();

    void startThread();
    void stopThread();

protected:
    void run();

private:
    bool beforeParsing(SystemDatastruct::SerialPortProtocolArray & array);

private:
    bool m_b_runningFlage;
};

}

#endif // SERIALPORTPROTOCOLPARSE_H
