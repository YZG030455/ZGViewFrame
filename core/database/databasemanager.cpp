#include "databasemanager.h"

#include <QDebug>

namespace Core {

DatabaseManager::DatabaseManager()
{

}

DatabaseManager::~DatabaseManager()
{

}



/**
 * @brief 创建数据库
 * @param connectionName
 */

//    Database * tmpDb = new Database(m_dbConfigInfo.dbType, connectionName);
//    do
//    {
//        if (!tmpDb->init())
//            break;

//        tmpDb->setHostName(m_dbConfigInfo.hostName);
//        tmpDb->setDatabaseName(m_dbConfigInfo.dbName);
//        tmpDb->setUserName(m_dbConfigInfo.dbUser);
//        tmpDb->setPassword(m_dbConfigInfo.dbPass);

//        if (m_dbConfigInfo.port > 0)
//            tmpDb->setPort(m_dbConfigInfo.port);

//        if (!tmpDb->open())
//            break;

//        return tmpDb;

//    } while (0);

//    delete tmpDb;
//    return nullptr;
//}


//[] 创建数据库
//    SystemDatastruct::DataBaseConfigInfo info;
//    info. dbType = SystemDatastruct::DB_Mysql;            /*! <数据库类型> */
//    info. hostName = QString("localhost");
//    info. dbName = QString("localhost");
//    info. dbUser = QString("root");
//    info. dbPass = QString("030455");
//    info. port = 3306;



//    if(m_listDataBaseConfigInfos.size() > 0){
//        for(int i = 0; i< m_listDataBaseConfigInfos.size(); i++){
//            SystemDatastruct::DataBaseConfigInfo t_configInfo =  m_listDataBaseConfigInfos.at(i);
//            if(t_configInfo.dbType == SystemDatastruct::DB_SqlLite){
//                createSqlLite(t_configInfo);
//            }
//            else if (t_configInfo.dbType == SystemDatastruct::DB_Mysql) {
//                createMysql(t_configInfo);
//            }
//            else if (t_configInfo.dbType == SystemDatastruct::DB_ORACLE) {

//            }
//        }
//    }

}//namespace Core
