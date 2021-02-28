/*!
 *  @brief    文件树结构图窗口
 *  @details
 *  @author
 *  @version   1.0
 *  @date      20190319
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef FILETREEDOCKWIDGET_H
#define FILETREEDOCKWIDGET_H

#include <QDockWidget>


class FileTreeDockWidget : public QDockWidget
{
public:
    FileTreeDockWidget(QWidget *parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
    ~FileTreeDockWidget();

};

#endif // FILETREEDOCKWIDGET_H
