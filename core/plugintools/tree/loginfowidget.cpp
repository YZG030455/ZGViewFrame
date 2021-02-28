#include "loginfowidget.h"

#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QDateTime>
#include <QTime>

/**
 * @brief 为LogInfoWidget的私有类
 */
class LogInfoWidgetPrivate
{
    Q_DECLARE_PUBLIC(LogInfoWidget)
public:
    LogInfoWidgetPrivate(LogInfoWidget * q) :q_ptr(q) {

        initWidget();
    }

    void initWidget();
    void updateDataTimeLogInfo();
    void updateTimeInfo();

    LogInfoWidget *q_ptr;
    QTextEdit *textEditLogInfo;

};

/**
 * @brief 初始化窗口
 */
void LogInfoWidgetPrivate::initWidget()
{
    textEditLogInfo = new  QTextEdit();
    /*! <布局> */
    QVBoxLayout *t_mainLayout = new QVBoxLayout();
    t_mainLayout->addWidget(textEditLogInfo);
    q_ptr->setLayout(t_mainLayout);
}

/**
 * @brief 显示带有日期的日志
 */
void LogInfoWidgetPrivate::updateDataTimeLogInfo()
{
    QDateTime t_dateTime =QDateTime::currentDateTime();
    //yyyy表示年；MM表示月；dd表示日； hh表示小时；mm表示分；ss表示秒；zzz表示毫秒；ddd表示周几
    //    QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz ddd");
    QString t_currentDate = t_dateTime.toString("yyyy.MM.dd hh:mm:ss.zzz");
}

/**
 * @brief 只显示带有时间的日志信息
 */
void LogInfoWidgetPrivate::updateTimeInfo()
{
    QTime t_time = QTime::currentTime();
    QString t_strTime = t_time.toString("HH:mm:ss");


}

LogInfoWidget::LogInfoWidget(QWidget *parent)
    : QWidget(parent),
      d_ptr(new LogInfoWidgetPrivate(this))
{

}

LogInfoWidget::~LogInfoWidget()
{

}

/**
 * @brief 设置输出的日志信息
 * @param str
 */
void LogInfoWidget::setLogInfo(QString str)
{

}



