#include "programfilepath.h"

#include <QApplication>

namespace Core {

ProgramFilePath::ProgramFilePath()
{
    /*! <文件路径> */
    m_programPath = qApp->applicationDirPath();
    m_configPath = m_programPath  + QString("/../configs");
    m_configFile = m_configPath  + QString("/config.ini");

    m_dataBaseConfigFile = m_configPath + QString("/databaseConfig.xml");

    m_styleSheetsPath = m_programPath  + QString("/../styleSheets");
    m_styleSheetsCofigFile = m_configPath + QString("/stylesheetsconfig.xml");
}

}//namespace Core
