/*!
 *  @brief    软件启动配置文件
 *  @details  启动时解析/config/config.ini文件
 *  @author   yzg
 *  @version
 *  @date      2021.02.24
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef GLOBALCONFIGFILE_H
#define GLOBALCONFIGFILE_H

#include <QObject>
#include <QSettings>

#include "utils/rlog.h"
#include "utils/rutil.h"

namespace Core {

class GlobalConfigFile
{
public:
    GlobalConfigFile();
    void setSettings(QSettings * setting){this->m_settings = setting;}

    bool parseFile();
    void saveFile();

public:
    RLog::LogConfig logConfig;                                  /*!< 日志配置信息 */


private:
    QSettings *m_settings;      /*! < 读写ini文件
                                      Qsettings就是提供了一种方便的方法来存储和恢复应用程序的settings。
                                      用户对应用程序经常有这样的要求：要求它能记住它的settings，
                                      比如窗口大小，位置，一些别的设置，还有一个经常用的，就是recent files，
                                      等等这些都可以通过Qsettings来实现。> */
};

} //namespace Core

#endif // GLOBALCONFIGFILE_H
