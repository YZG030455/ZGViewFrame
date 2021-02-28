/*!
 *  @brief    创建MySql数据库
 *  @details
 *  @author
 *  @version
 *  @date
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef MYSQLDATABASE_H
#define MYSQLDATABASE_H

#include <QObject>
#include <QSqlDatabase>

class MySqlDataBase : public QObject
{
    Q_OBJECT
public:
    explicit MySqlDataBase(QObject *parent = 0);
    ~MySqlDataBase();

    void createDataBase();
    void openDataBase();

signals:

public slots:


private:
    QSqlDatabase m_mySqlDatabase;       /*! <数据库> */

};

#endif // MYSQLDATABASE_H
