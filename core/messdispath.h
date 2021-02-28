/*!
 *  @brief     单例模式： 用于管理发送与接受
 *  @details
 *  @author    yzg
 *  @version
 *  @date      2021.02.19
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef MESSDISPATH_H
#define MESSDISPATH_H

#include <QObject>

namespace Core {

class MessDispath : public QObject
{
    Q_OBJECT
public:
    static MessDispath *instance();


    void setLogInfo(QString str);

signals:
    void signalLogInfo(QString strLog);


public slots:

private:
    explicit MessDispath(QObject *parent = 0);
};

} //namespace Core

#endif // MESSDISPATH_H
