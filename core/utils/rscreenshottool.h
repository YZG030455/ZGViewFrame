/*!
 *  @brief     屏幕截图工具类
 *  @details
 *  @author    yzg
 *  @version   1.0
 *  @date
 *  @warning   2021.02.19
 *  @copyright 个人
 *  @note
 */
#ifndef RSCREENSHOTTOOL_H
#define RSCREENSHOTTOOL_H

#include <QObject>
#include <QScreen>
#include <QPixmap>

namespace Core {

class RScreenshotTool
{
public:
    RScreenshotTool();
    ~RScreenshotTool();

    enum ScreenshotType{
        Screenshot_None,           /*!< 不做任何操作 */
        Screenshot_ALL,            /*!< 全屏截图 */
    };

    void setScreenshotSize(int x, int y, int widget, int height);

private:
    QPixmap m_pixmap;
};

}//namespace Core

#endif // RSCREENSHOTTOOL_H
