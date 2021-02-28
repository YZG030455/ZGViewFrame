#ifndef DATABASEPROTOCOL_H
#define DATABASEPROTOCOL_H

#include <QObject>

namespace Core {

/*!
 *  @brief 数据库类型
 */
enum DatabaseType
{
    DB_NONE = 0,
    DB_MYSQL,
    DB_ORACLE
};

/*!
 *  @brief 数据库特征信息
 *  @note 保存当前使用的数据库中的功能特点
 */
struct DBFeature
{
    bool lastInsertId;
    bool transactions;
};

/*!
 *  @brief 数据库配置信息
 */
struct DatabaseConfigInfo{
    DatabaseType dbType;
    QString hostName;
    QString dbName;
    QString dbUser;
    QString dbPass;
    ushort port;
};

}

#endif // DATABASEPROTOCOL_H
