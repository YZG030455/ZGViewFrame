/*!
 *  @brief     软件入口
 *  @details
 *  @author    yzg
 *  @version   1.0
 *  @date
 *  @warning   2021.02.18
 *  @copyright 个人
 *  @note
 */
#include <QApplication>
#include <QTextCodec>
#include <QSharedMemory>
#include <QMessageBox>
#include <QSplashScreen>

#include "coredump.h"

#include "mainobject.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    //[1] 注冊异常捕获函数
    App::EnableRecordDump();
    QApplication a(argc, argv);
    //[2] 解决汉字乱码问题
    QTextCodec *t_code = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(t_code);
    //[3] 检测软件重复启动
    QSharedMemory t_sharedMemory(a.applicationName());
    if(!t_sharedMemory.create(1)){
        QMessageBox::warning(NULL, QObject::tr("警告"), QObject::tr("该软件已启动!"));
        return -1;
    }
    //[4]加载并显示启动画面, 显示字体位置
    QSplashScreen splash(QPixmap(":/splashScreen/resource/splashscreen/splashScreen1.jpg"));
    splash.setDisabled(true);
    splash.show();
    QFont font;
    font.setFamily("微软雅黑");
    font.setPixelSize(50);
    font.setBold(true);
    font.setPointSize(20);
    font.setWeight(QFont::Light);
    splash.setFont(QFont(font));
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignVertical_Mask;
    splash.showMessage(QObject::tr("Wait......"), topRight, Qt::white);
    //[5] 初始化主类
    Core::MainObject object;
    object.initAll();
    //[6] 初始化主窗口
    Core::MainWindow widget;
    widget.initAll();
    widget.show();
    splash.finish(&widget);
    return a.exec();
}
