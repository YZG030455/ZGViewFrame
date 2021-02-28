/*!
 *  @brief     用户登录界面
 *  @details
 *  @author    yzg
 *  @version   1.0
 *  @date
 *  @warning   2021.02.19
 *  @copyright 个人
 *  @note
 */
#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>


#include "core_global.h"

namespace Core {

class CORE_EXPORT LoginWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

signals:

private:
    void init();

};

}//namespace Core

#endif // LOGINWIDGET_H
