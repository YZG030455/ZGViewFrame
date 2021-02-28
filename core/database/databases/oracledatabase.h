/*!
 *  @brief    创建Oracle数据库
 *  @details
 *  @author   yzg
 *  @version  1.0
 *  @date
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef ORACLEDATABASE_H
#define ORACLEDATABASE_H

#include <QObject>

class OracleDataBase : public QObject
{
    Q_OBJECT
public:
    explicit OracleDataBase(QObject *parent = 0);

signals:

public slots:
};

#endif // ORACLEDATABASE_H
