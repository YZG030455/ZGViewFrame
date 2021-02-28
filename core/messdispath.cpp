#include "messdispath.h"

#include <QDebug>

namespace Core {

static MessDispath *G_MessDispath = NULL;

/**
 * @brief 创建单例对象
 * @return
 */
MessDispath *MessDispath::instance()
{
    if(G_MessDispath == NULL)
    {
        new MessDispath;
    }
    return G_MessDispath;
}

/**
 * @brief 设置操作信息: 发送到日志信息窗口
 * @param str 日志信息
 */
void MessDispath::setLogInfo(QString str)
{
    emit signalLogInfo(str);
}

MessDispath::MessDispath(QObject *parent)
    : QObject(parent)
{
    G_MessDispath = this;
}

}//namespace Core
