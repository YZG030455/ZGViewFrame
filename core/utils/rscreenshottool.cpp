#include "rscreenshottool.h"

#include <QDebug>
#include <QApplication>

namespace Core {

RScreenshotTool::RScreenshotTool()
{

}

RScreenshotTool::~RScreenshotTool()
{

}

/**
 * @brief 设置截图创建大小
 * @param x
 * @param y
 * @param widget
 * @param higth
 */
void RScreenshotTool::setScreenshotSize(int x, int y, int width, int height)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    m_pixmap  = screen->grabWindow(0, x, y, width,  height);
    qDebug() << "QDebugQDebugQDebugQDebug"  << QCoreApplication::applicationDirPath() ;
    m_pixmap.save(QCoreApplication::applicationDirPath() + "/1.jpg");
}

}//namespace Core
