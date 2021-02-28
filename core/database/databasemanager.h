/*!
 *  @brief     数据库管理器
 *  @details   用于创建各种类型的数据库
 *  @author    YZG
 *  @version   1.0
 *  @date      20190731
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>

#include "databaseprotocol.h"
#include "database.h"

namespace Core {

class DatabaseManager : public QObject
{

public:
     DatabaseManager();
    ~DatabaseManager();

    /*!
     * @brief 设置数据库基本配置信息
     * @param configInfo 包括类型、连接地址、用户名等配置信息
     */


    Database * createDatabase(QString connectionName = "");

private:


private:
    Database * m_database;                          /*!< 数据库 */
};

} //namespace Core

#endif // SQLDATAMANAGE_H
