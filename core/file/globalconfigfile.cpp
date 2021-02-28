#include "globalconfigfile.h"
#include "constants/constants.h"

#include <QDebug>

namespace Core {

/**
 * @brief GlobalConfigFile::GlobalConfigFile
 */
GlobalConfigFile::GlobalConfigFile()
    :m_settings(nullptr)
{

}

/**
 * @brief 解析.ini 配置文件
 */
bool GlobalConfigFile::parseFile()
{
    if(m_settings == nullptr)
        return false;

    // 数据库配置
//    int dbType = RUtil::getGlobalValue(Constant::DB_SETTING,Constant::DB_TYPE,databaseConfig.dbType).toInt();
//    //databaseConfig.dbType =
//    databaseConfig.dbName   = RUtil::getGlobalValue(Constant::DB_SETTING, Constant::DB_TYPE, databaseConfig.dbName).toString();
//    databaseConfig.hostName = RUtil::getGlobalValue(Constant::DB_SETTING, Constant::DB_HOST, databaseConfig.hostName).toString();
//    databaseConfig.dbName   = RUtil::getGlobalValue(Constant::DB_SETTING, Constant::DB_DATABASE_NAME, databaseConfig.dbName).toString();
//    databaseConfig.dbUser   = RUtil::getGlobalValue(Constant::DB_SETTING, Constant::DB_USERNAME, databaseConfig.dbUser).toString();
//    databaseConfig.dbPass   = RUtil::getGlobalValue(Constant::DB_SETTING, Constant::DB_PASSWORD, databaseConfig.dbPass).toString();
//    databaseConfig.port     = RUtil::getGlobalValue(Constant::DB_SETTING, Constant::DB_PORT, databaseConfig.port).toInt();

    // 日志模块
    return true;
}

/**
 * @brief 用于保存 .ini 配置文件
 */
void GlobalConfigFile:: saveFile()
{
    if(m_settings == nullptr) {
        return;
    }
    /* 配置文件 */
    //    m_settings->beginGroup(Constant::SYSTEM_SETTING);
    //    m_settings->setValue(Constant::SYSTEM_DEFAULT_SCHEMES,systemConfigInfo.defaultKeySchemes);
    //    m_settings->setValue(Constant::SYSTEM_USER_SCHEMES_NAME,systemConfigInfo.userKeySchemesName);
    //    m_settings->setValue(Constant::SYSTEM_LOCALE,systemConfigInfo.locale);
    //    m_settings->setValue(Constant::SYSTEM_STYLE,systemConfigInfo.style);
    //    m_settings->setValue(Constant::SYSTEM_FULLSCREEN,systemConfigInfo.fullscreen);
    //    m_settings->setValue(Constant::SYSTEM_TOPHINT,systemConfigInfo.topHint);
    //    m_settings->setValue(Constant::SYSTEM_MENUBAR,systemConfigInfo.menubarVisible);
    //    m_settings->endGroup();
}

} //namespace Core
