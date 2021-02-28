/*!
 *  @brief     系统文件配置信息
 *  @details   定义了系统中各个文件夹路径、文件名全路径等信息
 *  @author    yzg
 *  @version   v1.0
 *  @date      2019.05.06
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef PROGRAMFILEPATH_H
#define PROGRAMFILEPATH_H

#include <QObject>

namespace Core {

class ProgramFilePath
{
public:
    ProgramFilePath();

    /*! <文件夹路径> */
    QString m_programPath;                  /*! <文件路径> */
    QString m_configPath;                   /*! <config 配置文件路径> */
    QString m_configFile;                   /*! <config 配置文件> */

    QString m_dataBaseConfigFile;           /*! <数据库配置文件路径> */

    QString m_styleSheetsPath;              /*! <样式表文件路径> */
    QString m_styleSheetsCofigFile;         /*! <样式表配置文件> */

};

}// namespace Core

#endif // PROGRAMFILEPATH_H
