#include "mysqldatabase.h"

#include <QDebug>

#include <QSqlQuery>
#include <QSqlError>

MySqlDataBase::MySqlDataBase(QObject *parent)
    : QObject(parent)
{

}

MySqlDataBase::~MySqlDataBase()
{

}

/**
 * @brief 创建数据库
 */
void MySqlDataBase::createDataBase()
{
    /*! <打印Qt支持的数据库驱动> */
    qDebug()<< "MySql" << QSqlDatabase::drivers();
    /*! <建立和 QMYSQL 数据的连接 > */
    m_mySqlDatabase = QSqlDatabase::addDatabase("QMYSQL");
    /*! <数据库信息> */
    m_mySqlDatabase.setHostName("127.0.0.1");       //连接数据库主机名，这里需要注意（若填的为”127.0.0.1“，出现不能连接，则改为localhost)
    m_mySqlDatabase.setPort(3306);                  //连接数据库端口号，与设置一致

    m_mySqlDatabase.setUserName("root");            //数据库用户名，与设置一致
    m_mySqlDatabase.setPassword("rengu123456");     //数据库密码，与设置一致
    m_mySqlDatabase.setDatabaseName("test");        //连接数据库名，与设置一致

}

/**
 * @brief 打开数据库
 */
void MySqlDataBase::openDataBase()
{
//    m_mySqlDatabase.open();
//    if(!m_mySqlDatabase.open())
//    {
//        qDebug()<<"不能连接"<<"connect to mysql error"<<db.lastError().text();
//        return ;
//    }
//    else
//    {
//        qDebug()<<"连接成功"<<"connect to mysql OK";
//    }
//    QSqlQuery query(m_mySqlDatabase);
//    query.exec("select * from student");
//    while(query.next()){
//        qDebug()<<query.value("name").toString();
//    }
}
