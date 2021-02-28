#include "loginfodockwidget.h"
#include "messdispath.h"

#include <QDebug>

LogInfoDockWidget::LogInfoDockWidget(QWidget *parent, Qt::WindowFlags flags)
    : QDockWidget(parent, flags)
{

}

LogInfoDockWidget::~LogInfoDockWidget()
{

}

/**
 * @brief 初始化日志窗口
 */
void LogInfoDockWidget::initDockWidget()
{

    /*! <信号与槽> */
    connect(Core::MessDispath::instance(), SIGNAL(signalLogInfo(QString)), this, SLOT(slotLogInfo(QString)));
}

/**
 * @brief 显示并打印日志信息
 * @param strInfO
 */
void LogInfoDockWidget::slotLogInfo(QString strInfO)
{

}
