/*!
 *  @brief     主窗口
 *  @details
 *  @author    yzg
 *  @version   1.0
 *  @date
 *  @warning   2021.02.19
 *  @copyright 个人
 *  @note
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>


#include "utils/rscreenshottool.h"


#include "core_global.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace Core {

class CORE_EXPORT MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initAll();


private slots:
    void slotScreenshotTriggered();
private:
    void initMenu();
    void initWidget();

private:
    Ui::MainWindow *ui;

    QMenu * m_fileMenu;                 /*!< 文件菜单栏 */

    QMenu * m_toolMenu;                 /*!< 工具菜单栏 */
    QAction * m_screenshotAct;          /*!< 截图 */

    QMenu * m_helpMenu;                 /*!< 帮助 */
};

}//namespace Core

#endif // MAINWINDOW_H
