/*!
 *  @brief   显示操作日志信息窗口
 *  @details 用于显示操作的日志信息
 *  @author  YZG
 *  @version 1.0
 *  @date    20190624
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef LOGINFOWIDGET_H
#define LOGINFOWIDGET_H

#include <QWidget>
#include <QSharedPointer>

class LogInfoWidgetPrivate;

class LogInfoWidget : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(LogInfoWidget)
public:
    explicit LogInfoWidget(QWidget *parent = 0);
    ~LogInfoWidget();

    void setLogInfo(QString str);

signals:

public slots:



private:
    QSharedPointer<LogInfoWidgetPrivate> d_ptr;
};

#endif // LOGINFOWIDGET_H
