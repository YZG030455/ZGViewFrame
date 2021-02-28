/*!
 *  @brief     串口通信线程
 *  @details
 *  @author    YZG
 *  @version   1.0
 *  @date      20190728
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef SERIALPORTPACKETRULE_H
#define SERIALPORTPACKETRULE_H

#include <QObject>

#include "global.h"
#include "protocol/systemdatastruct.h"
#include "protocol/protocoldatastruct.h"
#include "messdispath.h"

namespace Core {

class SerialPortPacketRule
{
public:
    explicit SerialPortPacketRule();
    ~SerialPortPacketRule();

    bool unwrap(QString serialPortId, const char * data, const int length);

private:
    bool dealSerialPortData(QString SerialPortId,const char *data, int lenth);
    void appendSerialPortDataToQueue(SystemDatastruct::SerialPortProtocolArray &array);

};

} // namespace Core

#endif // SERIALPORTPACKETRULE_H
