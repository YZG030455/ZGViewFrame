#include "global.h"

namespace Core {

namespace Global {
/*! <软件全局配置文件> */
GlobalConfigFile *g_GlobalConfigFile;
RLog * g_RLog;

/************************ 网络协议发送与接收队列 *******************************************/
/*! <Tcp-数据接收 */
std::mutex g_mutex_recvTcpClientQueueMutex;
std::condition_variable g_cv_recvTcpClientQuqueCondition;
//SystemDatastruct::RecvProtocolQueue g_recvTcpClientQueue;



}//namespace Global

} //namespace Core
