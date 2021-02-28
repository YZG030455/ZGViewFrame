/*!
 *  @brief     多媒体展示窗口
 *  @details
 *  @author    yzg
 *  @version   1.0
 *  @date
 *  @warning   2021.02.19
 *  @copyright 个人
 *  @note
 */
#ifndef MULTIMEDIAWIDGET_H
#define MULTIMEDIAWIDGET_H

#include <QWidget>

#include "multimedia_global.h"

namespace Multimedia {

class MULTIMEDIA_EXPORT MultimediaWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MultimediaWidget(QWidget *parent = nullptr);
    ~MultimediaWidget();

signals:



};

}// namespace Multimedia

#endif // MULTIMEDIAWIDGET_H
