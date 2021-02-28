/*!
 *  @brief   窗口截图功能
 *  @details
 *  @author  yzg
 *  @version 1.0
 *  @date    20190908
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef SCREENSHOTSWIDGET_H
#define SCREENSHOTSWIDGET_H

#include <QWidget>

class ScreenShotsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ScreenShotsWidget(QWidget *parent = 0);
    ~ScreenShotsWidget();

    void initWidget();

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:


private:

};

#endif // SCREENSHOTSWIDGET_H
