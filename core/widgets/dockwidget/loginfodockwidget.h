/*!
 *  @brief    显示操作日志窗口
 *  @details
 *  @author
 *  @version
 *  @date     20190420
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef LOGINFODOCKWIDGET_H
#define LOGINFODOCKWIDGET_H

#include <QDockWidget>
#include <QSharedPointer>


class LogInfoDockWidget : public QDockWidget
{
    Q_OBJECT
public:
    LogInfoDockWidget(QWidget *parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
    ~LogInfoDockWidget();

    void initDockWidget();

signals:


private slots:
    void slotLogInfo(QString strInfO);

private:

};

#endif // LOGINFODOCKWIDGET_H
