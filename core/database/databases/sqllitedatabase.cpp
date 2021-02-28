#include "sqllitedatabase.h"

#include <QDebug>
#include <QApplication>

#include <QMessageBox>

#include <QVariantList>

namespace Core {

SqlLiteDataBase::SqlLiteDataBase(QObject *parent)
    : QObject(parent)
{

}

SqlLiteDataBase::~SqlLiteDataBase()
{
    m_sqlDb.close();
}

/**
 * @brief 创建数据库
 * @param dbName : 数据库连接名称
 */
bool SqlLiteDataBase::linkDataBase(SystemDatastruct::DataBaseConfigInfo info)
{
    qDebug()<< QSqlDatabase::drivers();
    //[1]检测数据库连接名称是否被占用
    bool  t_open = false;
    if(QSqlDatabase::contains(info.dbName)){
        m_sqlDb = QSqlDatabase::database(info.dbName);
    }else {
        //[2]建立和sqlite数据的连接
        m_sqlDb = QSqlDatabase::addDatabase("QMYSQL","connect1");
        m_sqlDb.setHostName("localhost");         //主机名
//        m_sqlDb.setPort(3306);
        m_sqlDb.setUserName("root");              //用户名//端口
//        m_sqlDb.setDatabaseName(m_dataBaseName);          //数据库名
        m_sqlDb.setPassword("030455");            //密码
        m_sqlDb.open();

        // 创建数据库，把下面的your_database1替换成你要创建的数据库名字。
        m_sqlDb.exec("create database if not exists your_database1");

        // 连接上刚刚创建好的数据库
        m_sqlDb.setDatabaseName("your_database1");
        // 必须重新调用一遍.open()，这里不加这一句，后面就会报错"QSqlQuery::exec: database not open"
        m_sqlDb.open();
    }
    return t_open;
}

/**
 * @brief 创建数据库
 */
void SqlLiteDataBase::createDataBase()
{
//    m_dataBaseName = QString("mysystemsql");
//    // 创建数据库，把下面的your_database1替换成你要创建的数据库名字。
//    QString t_database = QString("create database if not exists MySystemSql");
//    QSqlQuery query(m_sqlDb);
//    query.exec(t_database);

}

bool SqlLiteDataBase::openDataBase()
{
    bool  t_open = false;
//    m_sqlDb.setHostName("localhost");         //主机名
//    m_sqlDb.setPort(3306);
//    m_sqlDb.setUserName("root");              //用户名//端口
//    m_sqlDb.setDatabaseName(m_dataBaseName);          //数据库名
//    m_sqlDb.setPassword("030455");            //密码
//    m_sqlDb.open();
//    //测试连接
//    t_open = m_sqlDb.open();
//    if(!t_open) {
//        qDebug()<<"不能连接"<<"connect to mysql error"<<m_sqlDb.lastError().text();
        return t_open;
//    }
}

/**
 * @brief 关闭数据库
 * @return
 */
bool SqlLiteDataBase::closeDataBase()
{
    m_sqlDb.close();
    return true;
}

/**
 * @brief 创建数据库表
 * @param tableName : 数据库表名称
 */
void SqlLiteDataBase::createDataBaseTable()
{
    QString table = QString("create table course (id int primary key, "
                            "name varchar(20), teacher varchar(20))");
    QSqlQuery query(m_sqlDb);//绑定要访问的数据库
    query.exec(table);
    //    QString create_sql = "create table student (id int primary key, name varchar(30), age int)";

    //    QString create_sql = QString("create table %1 (id int primary key, name varchar(30), age int)").arg(tableName);

    //    t_sqlQuery.prepare(create_sql);
    //    if(!t_sqlQuery.exec())
    //    {
    //        qDebug() << "Error: Fail to create table." << t_sqlQuery.lastError();
    //    }
    //    else
    //    {
    //        qDebug() << "Table created!";
    //    }
}

/**
 * @brief 向数据库中表天添加数据信息
 */
void SqlLiteDataBase::addDataBaseData(QString tableName)
{
    QSqlQuery t_sqlQuery;
    QString insert_sql = QString("insert into %1 values (?, ?, ?)").arg(tableName);
    t_sqlQuery.prepare(insert_sql);
    t_sqlQuery.addBindValue(1);
    t_sqlQuery.addBindValue("Wang");
    t_sqlQuery.addBindValue(25);
    if(!t_sqlQuery.exec())
    {
        qDebug() << t_sqlQuery.lastError();
    }
    else
    {
        qDebug() << "inserted Wang!";
    }

    //
    bool t_exec = t_sqlQuery.exec(QString("INSERT INTO %1 VALUES(3, \"Li\", 23)").arg(tableName));
    if(!t_exec)
    {
        qDebug() << t_sqlQuery.lastError();
    }
    else
    {
        qDebug() << "inserted Li!";
    }

}

/**
 * @brief 修改数据库表格中信息
 * @param tableName
 */
void SqlLiteDataBase::updateDataBaseData(QString tableName)
{
    QSqlQuery t_sqlQuery;
    QString update_sql = QString("update %1 set name = :name where id = :id").arg(tableName);
    t_sqlQuery.prepare(update_sql);
    t_sqlQuery.bindValue(":name", "Qt");
    t_sqlQuery.bindValue(":id", 32);
    if(!t_sqlQuery.exec())
    {
        qDebug() << t_sqlQuery.lastError();
    }
    else
    {
        qDebug() << "updated!";
    }
}

/**
 * @brief 查询数据库
 * @param str
 */
void SqlLiteDataBase::queryTable(QString &str)
{

}

void SqlLiteDataBase::deleteDataBaseData()
{

}

} //namespace Core
