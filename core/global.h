/*!
 *  @brief
 *  @details
 *  @author
 *  @version  v1.0
 *  @date
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef GLOBAL_H
#define GLOBAL_H

#include <QObject>
#include <QMap>
#include <QQueue>
#include <mutex>
#include <condition_variable>

#include "utils/rlog.h"


#include "file/globalconfigfile.h"
#include "file/globalconfigfile.h"

namespace  Core {

namespace  Global {
/*! <软件全局配置文件> */
extern GlobalConfigFile *g_GlobalConfigFile;
extern RLog * g_RLog;

/************************ 网络协议发送与接收队列 *******************************************/
/*! <Tcp-数据接收 */
extern std::mutex g_mutex_recvTcpClientQueueMutex;
extern std::condition_variable g_cv_recvTcpClientQuqueCondition;
//extern SystemDatastruct::RecvProtocolQueue g_recvTcpClientQueue;


}//namespace Global

} //namespace Core

#endif // GLOBAL_H
