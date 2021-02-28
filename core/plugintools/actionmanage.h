/*!
 *  @brief    样式表管理
 *  @details
 *  @author   yzg
 *  @version  1.0
 *  @date     20191129
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef ACTIONMANAGE_H
#define ACTIONMANAGE_H

#include <QObject>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QProcess>

class ActionManage : public QObject
{
    Q_OBJECT
public:
    explicit ActionManage(QObject *parent = 0);
    ~ActionManage();



signals:

public slots:


private:
   void initManage();
   void initAction();
   void initMenu();

private:


};

#endif // ACTIONMANAGE_H
