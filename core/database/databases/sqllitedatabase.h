/*!
 *  @brief    创建SqlLite数据库
 *  @details
 *  @author  yzg
 *  @version 1.0
 *  @date    20190803
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef SQLLITEDATABASE_H
#define SQLLITEDATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include "global.h"
#include "protocol/systemdatastruct.h"
#include "protocol/protocoldatastruct.h"
#include "messdispath.h"

namespace Core {

class SqlLiteDataBase : public QObject
{
    Q_OBJECT
public:
    explicit SqlLiteDataBase(QObject *parent = 0);
    ~SqlLiteDataBase();

    bool linkDataBase(SystemDatastruct::DatabaseConfigInfo info);
    void createDataBase();
    bool openDataBase();
    //关闭数据库
    bool closeDataBase();
    //创建数据表（student）
    void createDataBaseTable();
    //在表格中增加新的字段
    void addDataBaseData(QString tableName);
    //修改
    void updateDataBaseData(QString tableName);

    //查询和显示结果
    void queryTable(QString& str);
    //    //判断数据表是否存在
    //    bool IsTaBexists(QString& Tabname);
    //插入数据
    //    void singleinsertdata(w2dba &singledb);//插入单条数据
    //    void Moreinsertdata(QList<w2dba> &moredb);//插入多条数据
    //删除数据
    void deleteDataBaseData();
    //修改数据
    void updatedata();


signals:

public slots:

private:       
    QSqlDatabase m_sqlDb;       /*! <连接数据库类> */
    QString m_dataBaseName;
};

} //namespace Core

#endif // SQLLITEDATABASE_H
